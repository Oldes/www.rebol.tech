# Anatomy of Rebol values
=========================

Rebol value has 16 bytes on 32bit systems and 32 bytes on 64bit.
Every Rebol value consists from:
1. **flags**  (4 bytes of `Reb_Val_Head` union: REBHED or REBCNT)
	Its order depends on system endianess.

	1. unsigned type:8;	// datatype
	2. unsigned opts:8;	// special options
	3. unsigned exts:8;	// extensions to datatype
	4. unsigned resv:8;	// reserved for future

	Possible type:
	```
	REB_END,                      // 0
	REB_UNSET,                    // 1
	REB_NONE,                     // 2
	REB_LOGIC,                    // 3
	REB_INTEGER,                  // 4
	REB_DECIMAL,                  // 5
	REB_PERCENT,                  // 6
	REB_MONEY,                    // 7
	REB_CHAR,                     // 8
	REB_PAIR,                     // 9
	REB_TUPLE,                    // 10
	REB_TIME,                     // 11
	REB_DATE,                     // 12
	REB_BINARY,                   // 13
	REB_STRING,                   // 14
	REB_FILE,                     // 15
	REB_EMAIL,                    // 16
	REB_REF,                      // 17
	REB_URL,                      // 18
	REB_TAG,                      // 19
	REB_BITSET,                   // 20
	REB_IMAGE,                    // 21
	REB_VECTOR,                   // 22
	REB_BLOCK,                    // 23
	REB_PAREN,                    // 24
	REB_PATH,                     // 25
	REB_SET_PATH,                 // 26
	REB_GET_PATH,                 // 27
	REB_LIT_PATH,                 // 28
	REB_MAP,                      // 29
	REB_DATATYPE,                 // 30
	REB_TYPESET,                  // 31
	REB_WORD,                     // 32
	REB_SET_WORD,                 // 33
	REB_GET_WORD,                 // 34
	REB_LIT_WORD,                 // 35
	REB_REFINEMENT,               // 36
	REB_ISSUE,                    // 37
	REB_NATIVE,                   // 38
	REB_ACTION,                   // 39
	REB_REBCODE,                  // 40
	REB_COMMAND,                  // 41
	REB_OP,                       // 42
	REB_CLOSURE,                  // 43
	REB_FUNCTION,                 // 44
	REB_FRAME,                    // 45
	REB_OBJECT,                   // 46
	REB_MODULE,                   // 47
	REB_ERROR,                    // 48
	REB_TASK,                     // 49
	REB_PORT,                     // 50
	REB_GOB,                      // 51
	REB_EVENT,                    // 52
	REB_HANDLE,                   // 53
	REB_STRUCT,                   // 54
	REB_LIBRARY,                  // 55
	REB_UTYPE,                    // 56
	```

	Possible options:
	```
	OPTS_LINE = 0,  // Line break occurs before this value
	OPTS_LOCK,      // Lock word from modification
	OPTS_REVAL,     // Reevaluate result value
	OPTS_UNWORD,    // Not a normal word
	OPTS_TEMP,      // Temporary flag - variety of uses
	OPTS_HIDE,      // Hide the word
	```

2. **padding** (4 bytes; only on 64bit systems)
3. **data** (`Reb_Val_Data` union) large enough to hold at least 3 pointers = 24 bytes on 64bit or 12 bytes on 32bit


Following binary values are in little-endian. Only used bytes are shown (dot means unused data)

## REB_END - `end!`

An internal marker for end of block.

	32bit: #{00000000 ........ ........ ........}
	64bit: #{00000000 ........ ........ ........ ........ ........ ........ ........}


## REB_UNSET - `unset!`

Value without any value.

	32bit: #{01000000 ........ ........ ........}
	64bit: #{01000000 ........ ........ ........ ........ ........ ........ ........}


## REB_NONE - `none!`

Value with a none value.

	32bit: #{02000000 ........ ........ ........}
	64bit: #{02000000 ........ ........ ........ ........ ........ ........ ........}


## REB_LOGIC - `logic!`

True value:

	32bit: #{03000000 01000000 ........ ........}
	64bit: #{03000000 ........ 01000000 ........ ........ ........ ........ ........}

False value:

	32bit: #{03000000 00000000 ........ ........}
	64bit: #{03000000 ........ 00000000 ........ ........ ........ ........ ........}


## REB_INTEGER - `integer!`

64 bit integer value. For example value 42:

	32bit: #{04000000 0000002A 00000000 ........}
	64bit: #{04000000 ........ 0000002A 00000000 ........ ........ ........ ........}


## REB_DECIMAL - `decimal!`

64bit floating point number (IEEE standard). For example value 42.5:

	32bit: #{05000000 00000000 00404540 ........}
	64bit: #{05000000 ........ 00000000 00404540 ........ ........ ........ ........}


## REB_PERCENT - `percent!`

Same like decimal, but multiplied by 100. For example value 4250% is same like 42.5:

	32bit: #{06000000 00000000 00404540 ........}
	64bit: #{06000000 ........ 00000000 00404540 ........ ........ ........ ........}


## REB_MONEY - `money!`

A high precision decimals with denomination. Stored in the `REBDCI` struct:

	unsigned m0:32; /* significand, lowest part */
	unsigned m1:32; /* significand, continuation */
	unsigned m2:23; /* significand, highest part */
	unsigned s:1;   /* sign, 0 means nonnegative, 1 means nonpositive */
	int e:8;        /* exponent */

The currency type is not implemented yet! It must be stored in the header's `exts` byte.

Value $1:

	32bit: #{07000000 01000000 00000000 00000000}
	64bit: #{07000000 ........ 01000000 00000000 00000000 ........ ........ ........}

Value -$1:

	32bit: #{07000000 01000000 00000000 00008000}
	64bit: #{07000000 ........ 01000000 00000000 00008000 ........ ........ ........}


## REB_CHAR - `char!`

Currently as 8bit and 16bit character. For example value `#"a"`:

	32bit: #{08000000 6100.... ........ ........}
	64bit: #{08000000 ........ 61000.... ........ ........ ........ ........ ........}


## REB_PAIR - `pair!`

Two dimensional point or size. Stored as two 32bit float values. For example value `-1x1`:

	32bit: #{09000000 000080BF 0000803F ........}
	64bit: #{09000000 ........ 000080BF 0000803F ........ ........ ........ ........}


## REB_TUPLE - `tuple!`

Sequence of small (8bit) integers (colors, versions, IP). Maximum size is 12 bytes.
Actual length is stored in the header's `exts` byte. Value `1.2.3.4.5`:

	32bit: #{0A000500 01020304 05000000 00000000}
	64bit: #{0A000500 ........ 01020304 05000000 00000000 ........ ........ ........}


## REB_TIME - `time!`

Time of day or duration. Stored as a time in nanoseconds (`REBI64`).
Value `0:0:0.000000001` (1ns):

	32bit: #{0B000000 01000000 00000000 ........}
	64bit: #{0B000000 ........ 01000000 00000000 ........ ........ ........ ........}

Value `01:02:03.04`:

	32bit: #{0B000000 00087AD6 62030000 ........}
	64bit: #{0B000000 ........ 00087AD6 62030000 ........ ........ ........ ........}


## REB_DATE - `date!`

A day, month, year, time of day, and timezone.
Stored as a time with additional `REBYMD` struct (4 bytes), which is defines for little endian as:

	REBINT zone:7;  // +/-15:00 res: 0:15
	REBCNT day:5;
	REBCNT month:4;
	REBCNT year:16;

Value `9-Nov-2022/0:0:0.000000001`:

	32bit: #{0C000000 01000000 00000000 80B4E607}
	64bit: #{0C000000 ........ 01000000 00000000 80B4E607 ........ ........ ........}

Value `9-Nov-2022/23:31:47+1:00`:

	32bit: #{0C000000 007EEC31 C4490000 84B4E607}
	64bit: #{0C000000 ........ 007EEC31 C4490000 84B4E607 ........ ........ ........}


## SERIES Values

Values of type `binary!`, `string!`, `file!`, `email!`, `ref!`, `url!`, `tag!`, `bitset!`, `image!`, `vector!`, `block!`, `paren!`, `path!`, `set-path!`, `get-path!` and `lit-path!` are stored as a series reference `REBSRI` struct, defined as:

	REBSER	*series;
	REBCNT	index;
	union {
		REBSER	*side;		// lookaside block for lists/hashes/images
		REBINT  back;		// (Used in DO for stack back linking)
	} link;

So for example binary (type `0D`) would be:

	32bit: #{0D000000 AAAAAAAA 00000000 BBBBBBBB}
	64bit: #{0D000000 ........ AAAAAAAA AAAAAAAA 00000000 BBBBBBBB BBBBBBBB ........}

Where `AAAAAAAA` is the series pointer and `BBBBBBBB` is the optional side pointer (in case of binary just NULL).
The series itsef is defined as a `REBSER` struct:

	REBYTE	*data;		// series data head
	REBCNT	tail;		// one past end of useful data
	REBCNT	rest;		// total number of units from bias to end
	REBINT	info;		// holds width and flags
	#if defined(__LP64__) || defined(__LLP64__)
	REBCNT	padding;	// ensure next pointer is naturally aligned
	#endif
	union {
		REBCNT size;	// used for vectors and bitsets
		REBSER *series;	// MAP datatype uses this
		struct {
			REBCNT wide:16;
			REBCNT high:16;
		} area;
		REBUPT all;     // for copying, must have the same size as the union
	};
	#ifdef SERIES_LABELS
	REBYTE  *label;		// identify the series
	#endif

`map!` datatype is actually not a series (because does not support offsets), but is internally also using the series reference.


## REB_DATATYPE - `datatype!`

Defined as a type of datatype. Stored as a `REBTYP` struct.

	REBINT	type;	// base type
	REBSER  *spec;  // pointer to a datatype specification object used by help (may be NULL)

For example value `#[integer!]`:

	32bit: #{1E000000 04000000 00000000 ........}
	64bit: #{1E000000 ........ 04000000 00000000 00000000 ........ ........ ........}


## REB_TYPESET - `typeset!`

Defined as a set of datatypes. Stored as a `REBTYS` struct.

	REBCNT  pad;	// Allows us to overlay this type on WORD spec type
	REBU64  bits;

For example value `#[typeset! [integer!]]`:

	32bit: #{1F000000 ........ 30000000 00000000}
	64bit: #{1F000000 ........ ........ 30000000 00000000 ........ ........ ........}


## REB_WORD and other word variants

Values of type `word!`, `set-word!`, `get-word!`, `lit-word!`, `refinement!` and `issue!` are stored as `REBWRD` struct:

	REBCNT	sym;		// Index of the word's symbol
	REBINT	index;		// Index of the word in the frame
	REBSER	*frame;		// Frame in which the word is defined

For example a word `system`:

	32bit: #{20000000 65000000 10000000 AAAAAAAA}
	64bit: #{20000000 ........ 65000000 10000000 AAAAAAAA AAAAAAAA}

Where `20` is type of `word!` and `AAAAAAAA` is a pointer to its frame (word's context).


## REB_FUNCTION and other function value types

Values of type `native!`, `action!`, `rebcode!` (not used), `command!`, `op!`, `closure!` and `function!` are stored as a `REBFCN` struct:

	REBSER	*spec;	// Spec block for function
	REBSER	*args;	// Block of Wordspecs (with typesets)
	union Reb_Func_Code {
		REBFUN	code;  // for native functions
		REBSER	*body; // for interpreted functions
		REBCNT	act;   // for actions
	} func;

So any native function value (like `print`) will be:

	32bit: #{26000000 AAAAAAAA BBBBBBBB CCCCCCCC}
	64bit: #{26000000 ........ AAAAAAAA AAAAAAAA BBBBBBBB BBBBBBBB CCCCCCCC CCCCCCCC}

Where `A`, `B` and `C` are pointers. In case of native, the `C` would be pointer to `REBFUN`.


## REB_OBJECT and other object value types

Values of type `object!`, `module!`, `task!` (not used yet), and `port!` are stored as `REBOBJ` struct:

	REBSER	*frame;
	REBSER	*body;		// module body

So any object like value looks like:

	32bit: #{26000000 AAAAAAAA BBBBBBBB ........}
	64bit: #{26000000 ........ AAAAAAAA AAAAAAAA BBBBBBBB BBBBBBBB ........ ........}

Where `A`, and `B` are pointers.

`error!` is a special kind of object, which uses `REBERR` struct:

	union Reo {
		REBSER	*object;
		REBVAL	*value;		// RETURN value (also BREAK, THROW)
	} reo;
	REBCNT	num;			// Value from `REBOL_Errors` enumeration.
	REBCNT  sym;			// THROW symbol, zero if `num >= RE_THROW_MAX`


## REB_GOB - `gob!`

Special graphical object, which is actually something between an object and a block. Stored as `REBGBO` struct:

	REBGOB *gob;
	REBCNT index;

`REBGOB` is than defined as:

	REBCNT flags;		// option flags
	REBCNT state;		// state flags

	REBSER *pane;		// List of child GOBs
	REBGOB *parent;		// Parent GOB (or window ptr)

	REBYTE alpha;		// transparency
	REBYTE ctype;		// content data type
	REBYTE dtype;		// pointer data type
	REBYTE resv;		// reserved

	union {
		REBGOB *owner;	// temp field - reused for different things
	};

	REBSER *content;	// content value (block, string, color)
	REBSER *data;		// user defined data

	REBXYF offset;		// location
	REBXYF size;
	REBXYF old_offset;	// prior location
	REBXYF old_size;	// prior size


## REB_EVENT - `event!`

Efficiently sized user interface event. Stored as `REBEVT` struct:

	u8  type;		// event id (mouse-move, mouse-button, etc)
	u8  flags;		// special flags
	u8  win;		// window id
	u8  model;		// port, object, gui, callback
	u32 data;		// an x/y position or keycode (raw/decoded)
	union {
		REBREQ *req;	// request (for device events)
		REBSER *port;   // port
		void *ser;		// object
	};


## REB_HANDLE - `handle!`

An arbitrary internal object or value. Stored as `REBHAN` struct:

	union {
		ANYFUNC	code;
		REBHOB *ctx;
		REBSER *data;
		REBINT  index;
	};
	REBCNT	sym;    // Index of the word's symbol. Used as a handle's type! TODO: remove and use REBHOB
	REBFLG  flags;  // Handle_Flags

It means, that it is a pointer, handle's type name and flags, which are use to decide, what type of the pointer handle holds. Currently there are used these flags:

	enum Handle_Flags {
		HANDLE_FUNCTION       = 0     ,  // handle has pointer to function (or holds an index) so GC don't mark it
		HANDLE_SERIES         = 1 << 0,  // handle has pointer to REB series, GC will mark it, if not set as releasable 
		HANDLE_RELEASABLE     = 1 << 1,  // GC will not try to mark it, if it is SERIES handle type
		HANDLE_CONTEXT        = 1 << 2,
		HANDLE_CONTEXT_MARKED = 1 << 3,  // used in handle's context (HOB)
		HANDLE_CONTEXT_USED   = 1 << 4,  // --//--
		HANDLE_CONTEXT_LOCKED = 1 << 5,  // so Rebol will not GC the handle if C side still depends on it
	};

Optional handle's context is stored as a `REBHOB` struct (using it's own memory pool):

	REBYTE *data;
	REBCNT  sym;      // Index of the word's symbol. Used as a handle's type!
	REBFLG  flags:16; // Handle_Flags (HANDLE_CONTEXT_MARKED and HANDLE_CONTEXT_USED)
	REBCNT  index:16; // Index into Reb_Handle_Spec value


--------------------------------------------------------------


Sizes on 64bit architecture:

	REBVAL =>  32  rebval
	REBSER =>  32  rebser
	REBWRD =>  16  word
	REBSRI =>  20  series
	REBCNT =>   4  logic
	REBI64 =>   8  integer
	REBU64 =>   8  unteger
	REBINT =>   4  int32
	REBDEC =>   8  decimal
	REBUNI =>   2  uchar
	REBERR =>  16  error
	REBTYP =>  12  datatype
	REBFRM =>  16  frame
	REBWRS =>  12  wordspec
	REBTYS =>  12  typeset
	REBSYM =>  12  symbol
	REBTIM =>  12  time
	REBTUP =>  12  tuple
	REBFCN =>  24  func
	REBOBJ =>  16  object
	REBXYF =>   8  pair
	REBEVT =>  16  event
	REBLIB =>  20  library
	REBROT =>  20  routine
	REBSTU =>  24  structure
	REBGOB =>  84  gob
	REBGBO =>  12  gbo
	REBUDT =>  16  utype
	REBDCI =>  12  deci
	REBHAN =>  16  handle
	REBALL =>  12  all

