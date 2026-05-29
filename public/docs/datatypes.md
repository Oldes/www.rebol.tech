;; The content of this file is parsed to extract datatype details and usage examples.
;; The original data in this file were collected from https://www.rebol.com/r3/docs/datatypes.html

## action!


This is a variant of a `native!` function that is standardized across datatypes. (They implement a set of common polymorphic functions.)

For example, the `insert` function is an `action!` function. It performs the same abstract operation over a variety of datatypes:
```rebol
insert "string" 123
insert [a b c] 123
```

The same is true for the `add` action (which implements the `+` operator):
```rebol
add 1 2
add 1:11 2:22
add 1.2.3 4.5.6
add 80% 10%
```

Note that not all actions apply to all datatypes. For example, `insert` is not used for `integer!` types and `add` is not used for `string!` types.

Action functions are optimized, and new actions cannot be added to the system.


### List of Actions
A complete list of action functions can be found in `system/catalog/actions`.

They are listed below.

###### Magnitude (scalar) oriented:
`add`,
`subtract`,
`multiply`,
`divide`,
`remainder`,
`power`,
`and~`,
`or~`,
`xor~`,
`negate`,
`complement`,
`absolute`,
`random`,
`round`,
`odd?`,
`even?`
###### Series oriented:
`head`,
`tail`,
`head?`,
`tail?`,
`past?`,
`next`,
`back`,
`skip`,
`at`,
`index?`,
`length?`,
`pick`,
`find`,
`select`,
`reflect`,
`make`,
`to`,
`copy`,
`take`,
`insert`,
`append`,
`remove`,
`change`,
`poke`,
`clear`,
`trim`,
`swap`,
`reverse`,
`sort`
###### Port oriented:
`create`,
`delete`,
`open`,
`close`,
`read`,
`write`,
`open?`,
`query`,
`modify`,
`update`,
`rename`


------------------------------------------------------------------
## binary!


The `binary!` datatype is a `series` of bytes (8-bits each, octets).

Binary is the **raw storage format** for all files and networking. It holds encoded data such as images, sounds, strings (in formats like UTF-8 and others), movies, compressed data, encrypted data, and others.

The meaning of an specific binary value depends on what it holds. For example, if you read a JPEG image, it's just a sequence of bytes. Once you've decoded those bytes, it becomes an `image!` datatype.

### Format
The source format for binary data can be base-2 (binary), base-16 (hex), and base-64. The default base for binary data in Rebol is base-16.

Binary strings are written as a number sign (#) followed by a string enclosed in braces. The characters within the string are encoded in one of several formats as specified by an optional number prior to the number sign. Base-16 is the default format.
```rebol
#{3A18427F 899AEFD8}                  ;; default base-16
2#{10010110110010101001011011001011}  ;; base-2
64#{LmNvbSA8yw9CB0aGvXmgUkVCu2Uz934b} ;; base-64
```

Whitespace and comments are ignored inside the braces, so long values can be spread across multiple lines:
```rebol
probe #{
    3A ;; comment is ignored
    18
    92
    56
}
#{3A189256}
```

The encoded characters must represent a whole number of bytes (a multiple of 8 bits). Strings with the wrong number of characters are invalid.

### Creation
The `to-binary` function converts data to the `binary!` datatype at the default base set in `system/options/binary-base`:
```rebol
to-binary "123"
;== #{313233}

to-binary "today is the day..."
;== #{746F64617920697320746865206461792E2E2E}
```

To convert an integer into its binary value, pass it in a block:
```rebol
probe to-binary [1] ;== #{01}
to-binary [11]      ;== #{0B}
```

Converting a series of integers into a binary, returns the bit conversion for each integer concatenated into a single binary value:
```rebol
to binary! [1 1 1 1] ;== #{01010101}
```


### Related
Use `binary?` determine whether a value is an `binary!`  datatype.


```rebol
binary? #{616263} ;== #(true)
```

Binary values are a type of series:


```rebol
series? #{616263} ;== #(true)
length? #{616263} ;== 3 (three hex values in this binary)
```

Closely related to working with `binary!` datatypes are the functions `enbase` and `debase`. The `enbase` function converts strings to their base-2, base-16 or base-64 representations as strings. The `debase` function converts enbased strings to a binary value of the base specified in `system/options/binary-base`.



------------------------------------------------------------------
## bitset!


Bitsets are bit-based data sets, `logic!` bitmaps. They map collections of integer and character values to `true` and `false`.

For example, bitsets define character classes used with the `parse` or `find` functions. They are also commonly used for allocation maps and search hash markers.

More information about bitsets, including details of changes from R2 to R3 can be found on the [DocBase Bitsets](http://www.rebol.net/wiki/Bitsets) page.


### Creating bitsets
New bitsets are created with `make`, which accepts several datatypes as arguments, including a bitset specification block as described below. Bitsets can also be created from `copy` and `complement`.

#### Using MAKE
The standard method of creating bitsets is by providing `make` with a datatype and argument:
```rebol
bits: make bitset! arg
```

The argument can be one of several datatypes, providing a range of possible results.

If `arg` is an `integer!`, a bitset of at least that size in bits is allocated:
```rebol
bits: make bitset! 1000
```

If `arg` is a `binary!`, the bitset is initialized according to the bits that are set within its bytes. This is common when `mold` was used to output the bitset or `to-binary` was used to convert it to binary.

```rebol
bits: make bitset! #{0F0016}
```

In addition, the spec can be a `char!`, any `string!`, or a `block!`.

```rebol
bits: make bitset! #"A"
bits: make bitset! "ABC"
bits: make bitset! [...]  ; see below
```

> **Zero based:**
> Unlike other `series` datatypes, bitsets are zero-based. This allows the NULL character to be included in the bitset and tested:
> ```rebol
> if find bits #"^(null)" [...]
> ```

#### Unicode
Bitsets are not limited to just ASCII characters. Unicode characters can also be specified.

You can write them directly within the UTF-8 encoding of Rebol source, or you can write them as:
```rebol
other: make bitset! [#"^(02FF)" - #"^(0FFF)"]
```

or even as integers:
```rebol
other: make bitset! [612 - 990]
```

Bitsets will only allocate as many bits as necessary to reach the upper limit of the specified range. The bitset example above will require 124 bytes of memory storage.

#### The CHARSET helper
Because bitsets are so commonly used for character maps, the `charset` helper function is also provided for creating bitsets.

```rebol
digits: charset "0123456789"
alpha:  charset [#"A" - #"Z" #"a" - #"z"]
```


### Bitset specification block
If a block is provided for `make` (and also several of the other bitset-related functions) it represents bit settings in the following way:

#### Accepted datatypes

| Datatype   | Example | Description |
|------------|---------|-------------|
| `integer!` | 123     | the bit associated with the integer 123 (or part of a range)
| `char!`    | #"a"    | the bit associated with character code "a" (or part of a range)
| `string!`  | "abc"   | multiple bits, each character specifies a bit
| `binary!`  | #{0102} | multiple bits, each byte specifies a single bit to be set

#### Bit ranges
Note that characters and integers can specify inclusive ranges using a dash (-). **Do not forget the spaces around it. Spaces are required to delimit it.**
```rebol
[0 - 99]       ;; bits 0 to 99 inclusive
[#"A" - #"Z"]  ;; bits associated with A to Z, inclusive
```
More examples are shown below.

#### Complement (not) bitsets
Bitsets can be complements, meaning that each bit is inverted (a logical `not`.) In order to specify such bitsets, a specification block can begin with the keyword not`.

Here are examples:
```rebol
no-space:      make bitset! [not #" "]
no-whitespace: make bitset! [not "^-^/ "]
no-ctrl-space: make bitset! [not 0 - #" "]
```

#### Binaries as bits
It should be noted that these two lines are not equivalent:
```rebol
make bitset! #{01FF}
make bitset! [#{01FF}]
```

The first sets bits 7 through 15. The second sets bits 1 and 255.

This difference occurs because the `mold` function outputs bitsets in a binary form that indicates what specific bits are set (the first line.)

However, within a block, this binary form can also be used if the bits` keyword is used. These lines are equivalent:
```rebol
make bitset! #{0060000080}
make bitset! [bits #{0060000080}]
```

And for the complement, these lines are also equivalent:
```rebol
complement make bitset! #{0060000080}
make bitset! [not bits #{0060000080}]
```

> **MOLD output:**
> When `mold` is used on a complemented bitset, in order to preserve the complement, the bitset must be output as a block in the form:
> ```rebol
> make bitset! [not bits #{...}]
> ```
> This is necessary in order to include the complement indication.


#### Examples
Create a bitset with the bit associated with #"a" set:
```rebol
bits: make bitset! #"a"
```

Create a bitset large enough to holds bits up to 1000 and set bit 1000:
```rebol
bits: make bitset! [1000]  ; note that bit 1000 is set
```

Create a bitset large enough to hold the bits for each character of "AxZ3?" and set each of those:
```rebol
bits: make bitset! "AxZ3?"
```

Note that upper and lower case bits are different.

A block allows multiple bits to be specified using one or more combination of the above. For example:
```rebol
bits: make bitset! [#"?" #"A" - #"Z" "!@#$" 201 - 220]
```

If the contents of bitset block needs to be computed, use `reduce` or `compose` first. For example:
```rebol
start: 200
len: 50
bits: make bitset! reduce [start '- start + len]
```

### Supported actions
These datatype [actions](#action!) are defined for the `bitset!` datatype:

| Action | Description
|--------|------------
| `make` | creates and returns a new bitset
| `copy` | returns a copy of a bitset
| `complement` | inverts each bit; returns a new bitset
| `find` | test that value is set
| `append` | add new bits to the set (set them to `true`)
| `poke` | set one or more bits `true` or `false`
| `remove` | remove specific bits from the bitset (requires `/part` refinement)
| `clear` | clear entire bitset
| `length?` | returns the number of bits used
| `and` | bitwise `and` of two bitsets; returns new bitset
| `or` | bitwise `or` of two bitsets; returns new bitset
| `xor` | bitwise `xor` of two bitsets; returns new bitset

In addition, these actions are identical:

| Action   | Same as
|----------|-------------
| `to`     | `make`
| `insert` | `append`
| `pick`   | `find`
| `negate` | `complement`

These comparisons are supported:

|Action    | Description
|----------|-------------
| `equal?` | the bitsets are equal
| `not-equal?` | the bitsets are not equal
| `same?` | the bitsets use the same memory storage
| `tail?` | provided to allow `empty?` to work for bitsets
| `zero?` | always returns `false` (because bitsets are not scalar values)


### Using bitsets
When you use a bitset, you normally want to:
- check if a single bit is set or not
- check for if any one or more of several bits are set or not
- check that all specified bits are set
- find a character in a string specified by a bitset
- parse a string for characters specified in a bitset

#### Checking bits
To check for one or more bits in a bitset most of the time you will use the `find` function.
```rebol
find the-bitset some-bits
```

It's quite common for `find` to be part of a conditional expression, such as:
```rebol
if find the-bitset some-bits [... do something ...]
```

Note that while less common, you can also use `pick` or a path selection in a similar way.

#### Examples of character bitsets
Examples of character-oriented:
```rebol
alpha: make bitset! [#"A" - #"Z" #"a" - #"z"]
if find alpha #"a" [...]
if find alpha "abc" [...]
if find alpha [#"a" - #"g"] [...]
if find alpha [":;?" #"a" - #"g" 3 - 20] [...]
```

#### Examples using integer bitsets

```rebol
bits: make bitset! [1 4 9 - 16 25 - 36]

if find bits 42 [...]
if find bits [20 - 29] [...]
if find bits [#"A" - #"Z" ".,?" 20 - 29] [...]
```

#### Examples using path selection

```rebol
if alpha/#"a" [...]
if alpha/"abc" [...]
if bits/12 [...]
```

#### Bitsets for character classes
Bitsets are often used to create character classes (e.g. digits, alpha, alpha-numeric, punctuation) to search for multiple characters at the same time:

```rebol
invalid-chars: charset [0 - #" " ",.;:?"]
if find name invalid-chars [...]
```

Such character classes are also used in `parse` rules:

```rebol
digits: charset "0123456789"
alpha: charset [#"A" - #"Z" #"a" - #"z"]
if parse name [some alpha any digits] [...]
```

See `parse` section for details.


#### Character casing

Editor note: specification pending


### Modification
You can modify the bits specified by a bitset in a few ways.

#### Appending bits
You can add bits to a bitset with the `append` function:
```rebol
spaces: make bitset! " "
append spaces "^-^/"
```

The `append` function will also accept a bitset specification block:
```rebol
letters: make bitset! [#"A" - #"Z"]
append letters [#"a" - #"z"]
```

The `insert` function is synonymous with `append`.


#### Removing bits
You can remove bits from a bitset with the `remove` function. In order to specify the bits to be removed, the `/part` refinement is necessary.

```rebol
spaces: make bitset! "^-^/ "
remove/part spaces #" "
```

The `remove` function will also accept a bitset specification block:
```rebol
letters: make bitset! [#"A" - #"Z" #"a" - #"z"]
remove/part letters [#"a" - #"z"]
```

If `/part` is not given, an error will result:
```rebol
remove spaces #" "
** Script error: missing a required argument or refinement
```

Also, note that `remove` only "unsets" bits, it does does not modify the size of the bitset.


#### Clearing all bits
The `clear` function will clear all bits for a bitset:
```rebol
bits: make bitset! "abc"
clear bits
append bits "d"
probe bits
make bitset! #{00000000000000000000000008}
```

Note that a complemented bitset remains complemented. The `clear` function does not reset the flag.


#### Complementing bitsets
As mentioned above, bitsets can be complemented. A complement provides the logical not of each bit.

Complemented bitsets are nothing more than a normal bitset with a complement flag used to indicate that the bits are inverted.

To create a complement bitset, use the `complement` function. It returns a new bitset with the complement flag set:
```rebol
no-space: complement make bitset! #" "

if find no-space "a" [print "not a space"]
not a space
```

Other examples:
```rebol
no-whitespace: complement make bitset! "^-^/ "
no-ctrl-space: complement make bitset! [0 - #" "]
```

If you `mold` a complemented bitset, you will see a `not` indicator:


```rebol
print mold no-space
make bitset! [not bits #{0000000080}]
```

For more information, see the notes in the above sections.


#### Logical operations
You can use `and`, `or`, and `xor` to create new bitsets.

For example:
```rebol
b1: make bitset! "abc"
b2: make bitset! "cdef"

probe b1 or b2
make bitset! #{0000000000000000000000007E}

probe b1 and b2
make bitset! #{00000000000000000000000010}
```

Note that the resultant bitset will always be minimized (trimmed):
```rebol
b3: make bitset! [0 30 60]
b4: make bitset! [0 1 2]

probe b3 and b4
make bitset! #{80}
```


#### Using set-path notation
Bitsets can also be modified using path notation.


```rebol
bits: make bitset! "abc"

bits/#"d": true
bits/#"c": false
bits/0: true
```

Variables can also be used:
```rebol
s: "abc"
bits/:s: false
```


### Special notes
#### Virtual length
You have always been able to define bitsets of any reasonable length, but now the length is more automatic:
- Bitsets are only as long as needed.
- Virtual bits outside physical range are valid.
- Bitsets will auto expand if necessary.

For example, in R2 if you created a bitset:
```rebol
bits: make bitset! 160
```
a 160 bit set would be created. However, if you wrote:
```rebol
space: make bitset! " ^-^/"
```
a 256 bitset would be created (because it assumed you wanted an 8-bit character-based bitset).

In R3, this is no longer true. A bitset is only as long as needed to hold its maximum bit value. The line:
```rebol
space: make bitset! " ^-^/"
```
creates a 40 bit set that looks like this:
```rebol
make bitset! #{0060000080}
```

The bitset is only as long as it needs to be.

If you check for a bit outside its range, such a request is valid:
```rebol
if find space "a" [print "found"]
```

In R2, this line would have caused an error, but it is fine in R3. All virtual bits are zero.

In addition, a bitset will auto-extend as needed. For example:
```rebol
append space ".:;"
```

will expand the space bitset to be:
```rebol
make bitset! #{006000008002}
```

Again, it is only as long as needed to hold the largest bit.

The above examples show only string bit values, but these rules apply to bitsets that are accessed with `char!` and `integer!` bit values as well.


#### Binary conversion
The binary representation for bitsets has changed compared to R2.

It is now left-to-right bit continuous (as if bits were written in binary as big-endian values.)

For example, in R3:
```rebol
make bitset! "abcd"
;== make bitset! #{00000000000000000000000078}
```

but, in R2:
```rebol
make bitset! "abcd"
;== make bitset! #{
;0000000000000000000000001E00000000000000000000000000000000000000
;}
```

Also, complemented bitsets do not use complemented bitmasks.

```rebol
to-binary complement make bitset! " "
;== #{0000000080}
```

For such conversions, the complement state is lost (similar to how width and height are lost for a conversion of an `image!` to `binary!`.)

If you want to preserve that information, you must use `mold`.



------------------------------------------------------------------
## block!



Blocks are groups of values and words. Blocks are used everywhere, from a script itself to blocks of data and code provided in a script.

Block values are indicated by opening and closing square brackets `[ ]` with any amount of data contained between them.

```rebol
[123 data "hi"]  ; block with data
[]               ; empty block
```

Blocks can hold records of information:
```rebol
woodsmen: [
    "Paul"    "Bunyan"  paul@bunyan.dom
    "Grizzly" "Adams"   grizzly@adams.dom
    "Davy"    "Crocket" davy@crocket.dom
]
```

Blocks can contain code:
```rebol
[print "this is a segment of code"]
```

Blocks are a type of series and thus anything that can be done with a series can be done with a block value.

Blocks can be searched:
```rebol
probe copy/part (find woodsmen "Grizzly") 3
;== ["Grizzly" "Adams" grizzly@adams.dom]
```

Blocks can be modified:
```rebol
append woodsmen [
    "John" "Muir" john@muir.dom
]
probe woodsmen
[
    "Paul" "Bunyan" paul@bunyan.dom
    "Grizzly" "Adams" grizzly@adams.dom
    "Davy" "Crocket" davy@crocket.dom
    "John" "Muir" john@muir.dom
]
```

Blocks can be evaluated:
```rebol
blk: [print "data in a block"]
do blk
data in a block
```

Blocks can contain blocks:
```rebol
blks: [
    [print "block one"]
    [print "block two"]
    [print "block three"]
]
foreach blk blks [do blk]
block one
block two
block three
```


### Format
Blocks can contain any number of values or no values at all. They can extend over multiple lines and can include any type of value, including other blocks.

An empty block:
```rebol
[ ]
```

A block of integers:
```rebol
[24 37 108]
```

A Rebol header:
```rebol
Rebol [
    Title: "Test Script"
    Date: 31-Dec-1998
    Author: "Ima User"
]
```

The condition and evaluation block of a function:
```rebol
while [time < 10:00] [
    print time
    time: time + 0:10
]
```

Words in a block need not be defined:
```rebol
blk: [undefined words in a block]
probe value? pick blk 1
;== #(false)
```

Blocks allow any number of lines, spaces, or tabs. Lines and spaces can be placed anywhere within the block, so long as they do not divide a single value.


### Creation

The `to-block` function converts data to the `block!` datatype:
```rebol
probe to-block luke@rebol.com
;== [luke@rebol.com]

probe to-block {123 10:30 "string" luke@rebol.com}
;== [123 10:30 "string" luke@rebol.com]
```


### Related

Use `block?` to determine whether a value is an `block!`  datatype.

```rebol
probe block? [123 10:30]
;== #(true)
```

As blocks are a subset of the series!` typeset, use `series?` to check this:
```rebol
probe series? [123 10:30]
;== #(true)
```

Using `form` on a block value creates a string from the contents contained in the block:
```rebol
probe form [123 10:30]
;== "123 10:30"
```

Using `mold` on a block value creates a string from the block value and it's contents, thus allowing it to be reloaded as a Rebol block value:
```rebol
probe mold [123 10:30]
;== "[123 10:30]"
```



------------------------------------------------------------------
## char!

A `char!` value represents a single Unicode code point. Characters are not strings — they are the individual values from which strings are built. A character can be printable, unprintable, or a control symbol. The full Unicode range (U+000000 to U+10FFFF) is supported.


### Format

A `char!` value is written as `#"` followed by the character and a closing `"`:

```rebol
#"R"     ; the letter R
#" "     ; a space
```

This distinguishes a character from a single-character string:

```rebol
#"R"     ; char! -- a single character value
"R"      ; string! -- a string containing one character
```

#### Escape sequences

Characters that cannot be typed directly use a caret `^` escape sequence inside the quotes:

```rebol
#"^/"    ; newline
#"^-"    ; horizontal tab
#"^^"    ; caret character itself
#"^""    ; double quote
```

Control characters `^A` through `^Z` correspond to Ctrl+A through Ctrl+Z (case-insensitive):

```rebol
#"^A"    ; Ctrl+A (same as #"^a")
#"^Z"    ; Ctrl+Z
```

#### Hex and named escape sequences

Parentheses inside the escape sequence specify a code point by hex value or by name. Up to 6 hex digits are supported, covering the full Unicode range:

```rebol
#"^(41)"       ;== #"A"     (U+0041)
#"^(263A)"     ;== #"☺"     (U+263A, smiley face)
#"^(1F600)"    ;== #"😀"    (U+1F600, emoji)
```

Named escapes for common control characters:

| Character               | Equivalent  | Description     |
|-------------------------|-------------|-----------------|
| `#"^(null)"` or `#"^@"` | U+0000      | Null            |
| `#"^(line)"` or `#"^/"` | U+000A      | Newline         |
| `#"^(tab)"`  or `#"^-"` | U+0009      | Horizontal tab  |
| `#"^(page)"`            | U+000C      | Form feed       |
| `#"^(esc)"`             | U+001B      | Escape          |
| `#"^(back)"`            | U+0008      | Backspace       |
| `#"^(del)"`             | U+007F      | Delete          |
| `#"^^"`                 |             | Caret           |
| `#"^""`                 |             | Double quote    |


### Creation

Use `to char!` or `to-char` to convert from other types:

```rebol
to char! "a"      ;== #"a"  (first character of string)
to char! 65       ;== #"A"  (from integer code point)
```

The full Unicode range is available:

```rebol
to char! 9786     ;== #"☺"   U+263A
to char! 128512   ;== #"😀"  U+1F600
to char! 0#1F601  ;== #"😁"  U+1F601
```

Get the first character of a string with `first`:

```rebol
first "ABC"       ;== #"A"
```

Some Unicode characters (such as emoji or CJK ideographs) occupy two columns when displayed in a fixed-width terminal. Use the `width` property to check the display width of a character:

```rebol
s: "a^(26A1)b"    ;; "a⚡b"
s/1/width         ;;== 1   (regular ASCII character)
s/2/width         ;;== 2   (the lightning bolt is a wide character)
```

`++` and `--` increment or decrement a character to the next or previous code point, returning the value before the change:

```rebol
a: #"a"
++ a   ;== #"a"
a      ;== #"b"
-- a   ;== #"b"
a      ;== #"a"
```

Get the integer code point of a character with `to integer!`:

```rebol
to integer! #"A"    ;== 65
to integer! #"☺"    ;== 9786
```

Convert a character to its hex code point as an `issue!` with `to-hex`:

```rebol
to-hex #"^(1F642)"  ;== #01F642
to-hex #"A"         ;== #000041
```


### Comparison

Character comparison with `=` is case-insensitive by default, consistent with string comparison. Use `==` (strict-equal?) for case-sensitive comparison:

```rebol
#"a" = #"A"    ;== true    (case-insensitive)
#"a" == #"A"   ;== false   (case-sensitive)
#"a" < #"b"    ;== true
```

Functions that accept characters also default to case-insensitive matching and require `/case` for exact matching:

```rebol
find "abcde" #"B"           ;== "bcde" (case-insensitive)
find/case "abcde" #"B"      ;== none

select [#"A" 1] #"a"        ;== 1      (case-insensitive)
select/case [#"A" 1] #"a"   ;== none

switch #"A" [#"a" [true]]   ;== true   (case-insensitive)
```


### Display

`form` produces the character without the `#"..."` wrapper:

```rebol
form #"A"    ;== "A"
```

`mold` produces the full literal representation, using escape sequences where needed:

```rebol
mold #"A"    ;== {#"A"}
mold #"^/"   ;== {#"^/"}
```


### Related

Use `char?` to test whether a value is a `char!`:

```rebol
char? #"a"   ;== true
char? "a"    ;== false
```

`char!` is a member of the `scalar!` and `immediate!` typesets.



------------------------------------------------------------------
## closure!



Normally, a function takes a set of arguments, computes with them,
then returns a result. There are several types of functions, depending
on how they are implemented.

The most common function type is `function!`, and they are created with
code such as:

```rebol
add2: func [a b] [a + b]
```

These functions are efficient and work well for most code. But note, the
variables (a and b) of the function are valid only within the body of
the function. If you try to use those variables outside of the function,
an error will occur.

For example, this case returns a block that contains the variables. If
after the function returns, you try to access (in this case DO) the
variables, you get into trouble:


```rebol
>> add2: func [c d] [[c + d]]
>> do add2 1 2
** Script error: c word is not bound to a context
```

This happens because the variables are locally bound (locally scoped) to
the function. They only have values for the period of time during which
the function is evaluating. They have no meaning outside the function.

A `closure!` function solves this problem. With a closure you can write:


```rebol
>> add2: closure [c d] [[c + d]]
>> do add2 1 2
== 3
```

This works because the variables of a closure remain valid, even outside
the closure after it has been called. Such variables have **indefinite
extent**. They are not limited to the lifetime of the function.

Note, however, that the luxury provided by closures is not without its
costs. Closures require more time to evaluate as well as more memory
space.


### More detail
In essence a closure is an object. When you define the closure, it
constructs a prototype object, and each time you call the closure, the
prototype object is instantiated and the body code is evaluated within
that context.

Here is another usage example:


```rebol
>> make-adder: closure[x] [func [y] [x + y]]
== closure!
>> add-10: make-adder 10
== function!
>> add-2: make-adder 2
== function!
>> add-10 5
== 15
>> add-2 3
== 5
```


> **Editor note: Add more on:**
> - closure mezzanine function
> - closure? and any-function?
> - USE implemented as closure
> - actions that work on the closure datatype
> - passing closures as values

[More about function closures](https://en.wikipedia.org/wiki/Closure_(computer_science))



------------------------------------------------------------------
## command!

A `command!` is a special function type used to call into native C extensions. Rather than executing Rebol code, a `command!` value dispatches to an extension's C-level handler when called. From the caller's perspective it behaves like any other function — it has a spec, accepts arguments, and returns a value.

Commands are created by native extensions, not by Rebol code directly. When an extension is loaded, it registers its commands and makes them available as `command!` values in the current context.

### Reflection

Like other function types, `command!` values can be inspected:

```rebol
spec-of :some-command    ;: returns the argument spec block
body-of :some-command    ;: implementation-defined
```

### Related

Use `command?` to test whether a value is a `command!`:

```rebol
command? :some-command   ;== true
```

Use `help command!` to list all available commands in the current session.

`command!` is a member of the `any-function!` typeset.


------------------------------------------------------------------
## datatype!

Datatypes are documented on this page. Note that new datatypes cannot be created at runtime.

To get a full list of available datatypes, run the following command:
```code
help datatype!
```


------------------------------------------------------------------
## date!

A `date!` value represents a calendar date, optionally combined with a time of day and a timezone offset. Dates are normalized automatically — setting an out-of-range time or day causes the date to roll over correctly.


### Format

Dates can be written in several equivalent formats using `-` or `/` as separators. The canonical output format is `day-Mon-year`:

```rebol
1/3/1999      ;== 1-Mar-1999
1-3-1999      ;== 1-Mar-1999
1999-3-1      ;== 1-Mar-1999   (ISO format: year-month-day)
1999/3/1      ;== 1-Mar-1999
```

Month names and abbreviations are also accepted:

```rebol
5/Oct/1999        ;== 5-Oct-1999
5-October-1999    ;== 5-Oct-1999
1999/oct/5        ;== 5-Oct-1999
```

Two-digit years are interpreted relative to the current year, valid within a ±50 year window. Four-digit years are always preferred:

```rebol
28-2-90     ;== 28-Feb-1990
12-Mar-20   ;== 12-Mar-2020
11-Mar-45   ;== 11-Mar-2045
```

Valid years range from 0 to 16383. Year zero is valid:

```rebol
1-Jan-0000
make date! [1 1 0]   ;== 1-Jan-0000
```

Negative years are not supported. Years in the first century should use leading zeros: `9-4-0029`.

There can be no spaces within a date literal — `10 - 5 - 99` is a subtraction expression, not a date.

#### Date with time

A time is appended after a `/`:

```rebol
4-Apr-2000/6:00
1999-10-2/2:00:30.5
```

#### Date with timezone

A timezone offset is appended after the time using `+` or `-`. The offset can be written as hours (integer), `H:MM`, or `HHMM`:

```rebol
4-Apr-2000/6:00+8:00
1999-10-2/2:00-4:00
1-Jan-1990/12:20:25-6       ;== 1-Jan-1990/12:20:25   (integer offset)
8-Nov-2013/17:01+1:00       ;== from "2013-11-08T17:01+0100"
```

Valid timezone offsets range from -13:00 to +14:00 in 15-minute increments. No seconds are allowed in the offset.

#### ISO 8601

ISO 8601 format is accepted for loading. Both `T` separator and `Z` (UTC) suffix are supported:

```rebol
load "2013-11-08T17:01"        ;== 8-Nov-2013/17:01
load "2013-11-08T17:01Z"       ;== 8-Nov-2013/17:01
load "2013-11-08T17:01+01:00"  ;== 8-Nov-2013/17:01+1:00
```

`mold/all` produces valid ISO 8601 / RFC 3339 output:

```rebol
mold/all 1-1-2000/1:2:3            ;== "2000-01-01T01:02:03"
mold/all 1-1-200/1:2:3+2:0         ;== "0200-01-01T01:02:03+02:00"
```

ISO 8601 dates can also be used directly as path selectors:

```rebol
b: [8-Nov-2013/17:01 "foo"]
b/2013-11-08T17:01              ;== "foo"
```


### Construction

```rebol
make date! [day month year]
make date! [day month year time]
make date! [day month year time zone]

make date! [1 2 3]             ;== 1-Feb-0003
make date! [1 2 3 4:0]         ;== 1-Feb-0003/4:00
make date! [1 2 3 4:0 5:0]     ;== 1-Feb-0003/4:00+5:00
```

An existing date can also be used as the first element:

```rebol
make date! [1-1-2000]          ;== 1-Jan-2000
make date! [1-1-2000 10:0]     ;== 1-Jan-2000/10:00
make date! [1-1-2000 10:0 2:0] ;== 1-Jan-2000/10:00+2:00
```

Time overflow carries over into the date:

```rebol
make date! [1-1-2000 100:0]    ;== 5-Jan-2000/4:00
```

Literal syntax:

```rebol
#(date! 1 2 3)                 ;== 1-Feb-0003
#(date! 1 2 3 4:0)             ;== 1-Feb-0003/4:00
#(date! 1 2 3 4:0 5:0)         ;== 1-Feb-0003/4:00+5:00
#(date! 1-1-2000 10:0 2:0)     ;== 1-Jan-2000/10:00+2:00
```

Invalid dates (e.g. 31st February) produce an error.


### Field accessors

All fields are accessible via path. Fields return `none` when the date has no time component:

| Accessor    | Description |
|-------------|-------------|
| `/year`     | Year as integer |
| `/month`    | Month as integer (1–12) |
| `/day`      | Day as integer |
| `/date`     | Date part only (no time or zone) |
| `/time`     | Time of day (`time!` or `none`) |
| `/hour`     | Hour (or `none`) |
| `/minute`   | Minute (or `none`) |
| `/second`   | Second, may be decimal (or `none`) |
| `/zone`     | Timezone offset as `time!` (or `none`) |
| `/timezone` | Timezone in hours — adjusts time when changed |
| `/weekday`  | Day of week: 1=Monday, 7=Sunday |
| `/yearday`  | Day of year (1–366); settable |
| `/utc`      | Date/time converted to UTC (zone removed) |
| `/julian`   | Julian Day Number as `decimal!`; settable |

```rebol
d: 28-Oct-2009/10:09:38-7:00

d/year      ;== 2009
d/month     ;== 10
d/day       ;== 28
d/time      ;== 10:09:38
d/hour      ;== 10
d/minute    ;== 9
d/second    ;== 38
d/zone      ;== -7:00
d/weekday   ;== 3   ; Wednesday
d/utc       ;== 28-Oct-2009/17:09:38
```

Dates without time return `none` for time-related fields:

```rebol
d: 8-Apr-2020
d/time      ;== none
d/hour      ;== none
d/zone      ;== none
```

Fields can be set via path. The date is renormalized automatically:

```rebol
d: 1-Jan-2000
d/time: 50:00         ; overflow — date rolls forward
d                     ;== 3-Jan-2000/2:00

d/hour: 2             ; sets time if not present
d: 1-Jan-2000
d/minute: 10
d/time                ;== 0:10

d/yearday: 60         ; set by day of year
d                     ;== 29-Feb-2000   (leap year)

d/yearday: 0          ; last day of previous year
d                     ;== 31-Dec-1999
```

Setting timezone with `/zone` changes the offset only. Setting `/timezone` also adjusts the time to keep the UTC moment the same:

```rebol
d: 1-Jan-2000
d/zone: 2             ;== 1-Jan-2000/0:00+2:00

d/timezone: 4         ; adjusts time: +2 hours
d                     ;== 1-Jan-2000/2:00+4:00

d/timezone: -7        ; adjusts time again
d                     ;== 31-Dec-1999/15:00-7:00
```

Setting `/utc` adjusts the date to the given UTC moment:

```rebol
n: 27-Nov-2020/18:15:57+1:00
d/utc: n
d                     ;== 27-Nov-2020/17:15:57
```

Julian Day Number can be read and set:

```rebol
d: 10-Jun-2023/20:47:53+2:00
d/julian              ;== 2460106.28325231

d/julian: 2415020.5
d                     ;== 1-Jan-1900/0:00
```

Out-of-range numeric selectors return `none`:

```rebol
d/0    ;== none
d/-1   ;== none
d/100  ;== none
```

Numeric selectors (1–12) can also be used to access fields positionally:

```rebol
d: now
repeat i 12 [try [d/:i: i]]
mold d   ;== "11-Jan-0001/13:08:09+12:00"
```


### UTC and timezone

Remove the timezone by setting it to `none`, or use `/utc` to get the equivalent UTC time with the zone stripped:

```rebol
d: now                           ;== 19-Sep-2009/20:04:26-7:00
d/utc                            ;== 20-Sep-2009/3:04:26
d/zone: none                     ; strip timezone in place
```


### Date math

Adding or subtracting an integer shifts the date by that many days:

```rebol
5-Oct-1999 + 1          ;== 6-Oct-1999
5-Oct-1999 - 10         ;== 25-Sep-1999
now/date + 1            ; tomorrow
```

Adding a time shifts the date-time:

```rebol
5-Oct-1999/23:00 + 5:00  ;== 6-Oct-1999/4:00
```


### Internet dates

Convert to and from RFC 2822 Internet date format:

```rebol
to-idate 28-Mar-2019/20:00:59+1:00
;== "Thu, 28 Mar 2019 20:00:59 +0100"

to-idate/gmt 28-Mar-2019/20:00:59+1:00
;== "Thu, 28 Mar 2019 19:00:59 GMT"

to-idate 28-Mar-2019
;== "Thu, 28 Mar 2019 00:00:00 GMT"

to-date "Thu, 28 Mar 2019 20:00:59 +0100"
;== 28-Mar-2019/20:00:59+1:00

to-date/utc "Thu, 28 Mar 2019 20:00:59 +0100"
;== 28-Mar-2019/19:00:59
```

`to-itime` formats a time value for use in Internet dates:

```rebol
to-itime 9:4:5      ;== "09:04:05"
to-itime 13:24:5.21 ;== "13:24:05"
```


### Query

Use `query` to retrieve multiple fields at once:

```rebol
date: 8-Apr-2020/12:04:32+2:00

query date 'time                    ;== 12:04:32
query date [:year :month]           ;== [2020 4]
query date [month year]             ;== [month: 4 year: 2020]
query date object!                  ; returns an object with all fields
```

All available field names:

```rebol
query date none
;== [year month day time date zone hour minute second weekday yearday timezone utc julian]
```


### Current date and time

`now` returns the current date and time with timezone:

```rebol
now                  ; full date/time/zone
now/date             ; date only
now/time             ; time only
now/utc              ; current UTC time
now/year             ; current year
now/weekday          ; day of week
now/precise          ; high-precision timestamp
now/time/precise     ; high-precision time
```

Combining more than one time-related refinement (other than `/precise`) produces an error:

```rebol
now/time/day    ;** error
now/utc/month   ;** error
```


### Related

Use `date?` to test whether a value is a `date!`:

```rebol
date? 5/1/1999    ;== true
date? "1-1-2000"  ;== false
```


------------------------------------------------------------------
## decimal!


The `decimal!` datatype is based on 64-bit standard IEEE 754 binary floating point
numbers. They are distinguished from integer numbers by a decimal point
(a period or a comma is allowed for international usage, see the notes
below).


### Format
Decimal values are a sequence of numeric digits, followed by a decimal point, which can be a period (.) or a comma (,), followed by more digits. A plus (+) or minus (-) immediately before the first digit indicates sign. Leading zeros before the decimal point are ignored. Extra spaces, commas, and periods are not allowed.

```rebol
1.23
123.
123.0
0.321
0.123
1234.5678
```

A comma can be used in place of a period to represent the decimal point (which is the standard in many countries):

```rebol
1,23
0,321
1234,5678
```

Use a single quote `'` to separate the digits in long decimals. Single quotes can appear anywhere after the first digit in the number, but not before the first digit.


```rebol
100'234'562.3782
100'234'562,3782
```

Do not use commas or periods to separate the digits in a decimal value.

Scientific notation can be used to specify the exponent of a number by
appending the number with the letter **E** or **e** followed by a
sequence of digits. The exponent can be a positive or negative number.


```rebol
1.23E10
1.2e007
123.45e-42
56,72E300
-0,34e-12
0.0001e-001
```

Decimal numbers span from 2.2250738585072e-308 up to
1.7976931348623e+308 and can contain up to 15 digits of precision.


### Creation
Use the `to-decimal` function to convert `string!`,
`integer!`, `block!`, or `decimal!` datatypes to a decimal
number:


```rebol
probe to-decimal "123.45"
123.45

probe to-decimal 123
123

probe to-decimal [-123 45]
-1.23E+47

probe to-decimal [123 -45]
1.23E-43

probe to-decimal -123.8
-123.8

probe to-decimal 12.3
12.3
```

If a decimal and integer are combined in an expression, the integer is converted to a decimal number:

```rebol
probe 1.2 + 2
3.2

probe 2 + 1.2
3.2

probe 1.01 > 1
true

probe 1 > 1.01
false
```

### Related
Use `decimal?` to determine whether a value is an `decimal!` datatype.


```rebol
print decimal? 0.123
true
```

Use the `form`, `print`, and `mold` functions with a decimal argument to print a decimal value in its simplest form:
- integer. If it can be represented as one.
- decimal without exponent. If it's not too big or too small.
- scientific notation. If it's too big or small.

For example:
```rebol
probe mold 123.4
123.4

probe form 2222222222222222
2.22222222222222E+15

print 1.00001E+5
100001
```

Single quotes `'` and a leading plus sign `+` do not appear in decimal output:


```rebol
print +1'100'200.222'112
1100200.222112
```



------------------------------------------------------------------
## email!

An `email!` value represents an email address. It is a member of the `any-string!` and `series!` typesets, so all series operations apply.


### Format

An email address consists of a user part, an `@` sign, and a host part:

```rebol
info@rebol.com
123@number-mail.org
my-name.here@an.example-domain.com
šiška@rebol.tech
```

Case is preserved. There is no strict validation of the address format — any string-like value can be coerced to `email!` using `as`:

```rebol
as email! "foo"          ;== #(email! "foo")
as email! "aaa@bbb@ccc"  ;== #(email! "aaa@bbb@ccc")
```


### Construction

Email literals are written directly. Use `to-email`, `to email!` or `as email!` to convert from other types:

```rebol
to-email  "user@example.com"  ;== user@example.com
as email! "user@example.com"  ;== user@example.com - zero-copy coercion
```

Use `make email!` with a block to construct an address from parts. The first element is the user, subsequent elements form the host joined by dots:
```rebol
make email! [aaa]            ;== #(email! "aaa") - user only, no host
make email! [aaa bbb]        ;== aaa@bbb
make email! [aaa bbb cc]     ;== aaa@bbb.cc
make email! [aaa bbb cc dd]  ;== aaa@bbb.cc.dd
```
An empty block produces an error. The block must have at least one element.


### Accessing user and host

Use `/user` and `/host` to read the parts of an email address. These always operate on the full email value regardless of the current series position:

```rebol
e: someone@rebol.tech
e/user    ;== "someone"
e/host    ;== "rebol.tech"

;; position does not affect the result:
e: find e ".tech"
e/user    ;== "someone"
e/host    ;== "rebol.tech"
```

When there is no `@`, `/host` returns `none`:

```rebol
e: as email! "foo"
e/user    ;== "foo"
e/host    ;== none
```

When there are multiple `@` signs, `/user` is everything before the first one and `/host` is everything after it:

```rebol
e: as email! "aaa@bbb@ccc"
e/user    ;== "aaa"
e/host    ;== "bbb@ccc"
```


### Setting user and host

`/user` and `/host` are also settable:

```rebol
e: someone@rebol.tech
e/host: "gmail.com"
e    ;== someone@gmail.com

e/user: "foo"
e    ;== foo@gmail.com
```

Setting `/host` on an email with no `@` prepends `@host`:

```rebol
e: as email! ""
e/host: %rebol.tech
e    ;== #(email! "@rebol.tech")
```

Setting `/user` on an email with no `@` sets just the user, with no `@`:

```rebol
e: as email! ""
e/user: "bob"
e    ;== #(email! "bob")
```

Unicode is valid in both parts:

```rebol
e/user: "šiška"
e    ;== šiška@rebol.tech
```


### Series operations

Since `email!` is a series, standard operations apply:

```rebol
head change/part jane@doe.dom "john" 4   ;== john@doe.dom
find someone@rebol.tech ".tech"          ;== ".tech"
length? info@rebol.com                   ;== 13
```


### Related

Use `email?` to test whether a value is an `email!`:

```rebol
email?  info@rebol.com   ;== true
email? "info@rebol.com"  ;== false
```

Use `as` to coerce between `any-string!` types without copying:

```rebol
as email! "user@host.com"   ;== user@host.com
as string! user@host.com    ;== "user@host.com"
```



------------------------------------------------------------------
## end!

This is **a special internal datatype that should never appear in user code**.

It is a marker used for end-of-block.



------------------------------------------------------------------
## error!

An `error!` value represents a recoverable error condition. Errors carry structured information: a type, an id, a numeric code, and optional arguments (`arg1`, `arg2`, `arg3`). They are objects internally and can be inspected, converted, and constructed like other values.

Errors are defined in `system/catalog/errors`, which is protected and cannot be modified at runtime.

### Catching errors

Use `try` to evaluate a block and return either its result or an `error!` value if something goes wrong:

```rebol
try [1 + 1]          ;== 2
try [1 / 0]          ;== error!
error? try [1 / 0]   ;== true
```

Use `try/with` to handle an error inline — the handler block is evaluated on failure, and its result becomes the return value:

```rebol
try/with [1 / 0] [
    print "Zero division in the code!"
    print system/state/last-error
    0   ; return 0 as fallback
]
```

Use `attempt` when you only care whether the block succeeded — it returns `none` on failure instead of an error:

```rebol
attempt [1 + 1]   ;== 2
attempt [1 / 0]   ;== none
```

Both `try` and `attempt` also accept a `paren!` as their argument:

```rebol
try first [(1 / 0)]     ;== error!
attempt first [(1 / 0)] ;== none
```

### Inspecting errors

An error has the following fields accessible via path:

```rebol
e: try [1 / 0]

e/type    ;; error category (e.g. 'Math)
e/id      ;; error identifier (e.g. 'zero-divide)
e/code    ;; numeric error code
e/arg1    ;; first argument (if any)
e/arg2    ;; second argument (if any)
e/arg3    ;; third argument (if any)
```

The last error that occurred is always accessible via `system/state/last-error`:

```rebol
try [1 / 0]
system/state/last-error/id   ;== 'zero-divide
```

Use `select` and `find` to access fields by name:

```rebol
e: try [read %nonsense]

select e 'arg1          ;== %nonsense
select e 'arg1111       ;== none
find e 'arg1            ;== true
find e 'arg1111         ;== none
```

### Making errors

Use `make error!` with a block specifying `type` and `id`. Both are required — the `code` field is derived from the catalog and cannot be overridden:

```rebol
e: make error! [type: 'math id: 'zero-divide]
e/type   ;== 'Math
e/id     ;== 'zero-divide
```

Clone and retype an existing error with a message:

```rebol
e2: make e "message"
e2/type   ;== 'User
e2/arg1   ;== "message"
```

Invalid construction raises an `Internal/invalid-error`:

```rebol
make error! []                        ;** Internal/invalid-error — missing type and id
make error! [code: 400]               ;** Internal/invalid-error — missing type and id
make error! [code: 500 type: 'math]   ;** Internal/invalid-error — missing id
```

Invalid type or id raises a `Script/invalid-arg`:

```rebol
make error! [type: 'math id: 'foo]     ;** Script/invalid-arg — unknown id
make error! [type: 'foo id: 'overflow] ;** Script/invalid-arg — unknown type
```

Note: `Throw` type errors cannot be constructed with `make`.

### Converting errors

Convert an error to an object for manipulation:

```rebol
o: to-object try [1 / 0]
o/code: 1
```

Convert an object back to an error:

```rebol
e: to-error o
e/code   ;== 400
```

### Binding error messages

Error message templates are stored in `system/catalog/errors`. Use `bind` to resolve a message template against an error value:

```rebol
e: try [read %nonsense]
reduce bind system/catalog/errors/(e/type)/(e/id) e
;== ["cannot open:" %nonsense "reason:" 3]
```

### Asserting

Use `assert` to raise an error if a condition fails:

```rebol
assert [not none? 1]     ;; passes

assert [not none? none]
;** assert-failed error — arg1 contains the failing block
```

Use `assert/type` to check the type of a word:

```rebol
x: 1
assert/type [x integer!]           ;; passes
assert/type [x [integer! string!]] ;; passes — accepts a typeset block
assert/type [x any-string!]        ;; passes — accepts a typeset word

x: ""
assert/type [x integer!]           ;** wrong-type error
```

Note: `assert/type` requires a word as its first element — passing a literal value is an error:

```rebol
assert/type [1 integer!]   ;** invalid-arg error
```

### Related

Use `error?` to test whether a value is an `error!`:

```rebol
error? try [1 / 0]   ;== true
error? 42            ;== false
```


------------------------------------------------------------------
## event!


user interface event (efficiently sized)

> **Note:**
> Needs documentation!

------------------------------------------------------------------
## file!


The `file!` datatype can be a file name, directory name, or directory path.


```rebol
%file.txt
%directory/
%directory/path/to/some/file.txt
```

File values are a subset of series, and thus can be manipulated as a series:


```rebol
probe find %dir/path1/path2/file.txt "path2"
%path2/file.txt

f: %dir/path/file.txt
probe head remove/part (find f "path/") (length? "path/")
%dir/file.txt
```



### Format
Files are designated with a percent sign `%` followed by a sequence of characters:


```rebol
load %image.jpg
prog: load %examples.r
save %this-file.txt "This file has few words."
files: load %../programs/
```

Unusual characters in file names must be encoded with a `%` hexadecimal number, which is an Internet convention. A file name with a space (hexadecimal `20`) would look like:

```rebol
probe %cool%20movie%20clip.mpg
%cool%20movie%20clip.mpg

print %cool%20movie%20clip.mpg
cool movie clip.mpg
```

Another format is to enclose the file name in quotes:


```rebol
probe %"cool movie clip.mpg"
%cool%20movie%20clip.mpg

print %"cool movie clip.mpg"
cool movie clip.mpg
```

The standard character for separating directories in a path is the forward slash `/`, not the backslash `\`. However, the Rebol language automatically converts backslashes found in file names to forward slashes:

```rebol
probe %\some\path\to\some\where\movieclip.mpg
%/some/path/to/some/where/movieclip.mpg
```



### Creation
The `to-file` function converts data to the `file!` datatype:


```rebol
probe to-file "testfile"
%testfile
```

When passed a block, elements in the block are concatenated into a file path with the final element used as the file name:


```rebol
probe to-file [some path to a file the-file.txt]
%some/path/to/a/file/the-file.txt
```

### Related
Use `file?` to determine whether a value is an `file!` datatype.


```rebol
probe file? %rebol.r
true
```

As files are a subset of the series! pseudotype, use `series?` to check this:


```rebol
probe series? %rebol.r
true
```



------------------------------------------------------------------
## frame!


internal context frame


------------------------------------------------------------------
## function!


The Rebol language contains a few different types of functions, including
`native!`, `action!`, `function!`, and `closure!`. The main thing that
makes them different is how they are evaluated.

The `function!` datatype is a higher level function that is interpreted.
They are also called **user-defined** functions, and system functions
defined this way are called **mezzanine** functions.



### Format
Functions consist of a specification and a body block. The specification part provides the interface specification and any embedded documentation. The body is the code of the function.

The formal definition of `function` is:

```rebol
make function! [[specs] [body]]
```

(However, functions are normally created using helper functions. See below.)


> **Changed from R2:**
> Note that this format changed from Rebol V2. This change was necessary because `make` accepts only two arguments. Therefore, the second argument contains the specs block and the body block.

The function specs block holds:

| arguments   | the arguments passed to the function.
| datatypes   | optional datatype specifications for each argument.
| refinements | optional variations in the behavior and arguments of a function.
| doc strings | embedded documentation for the function and its arguments.

For every argument it is possible to define how the argument is passed to the function using one of the formats:

| Notation | Meaning
|----------|-----------
| `word`   | The argument expression is evaluated before it is passed to the function.
| `'word`  | The argument expression is evaluated only if it starts with a `get-word!` or a `paren!`.
| `:word`  | The argument expression is not evaluated. The very next value is used.
| `word:`  | Reserved. Used to define variations.


### Creation
Normally, you create a `function!` using a helper function.
There are a few choices:

| Helper  | Description
|---------|--------------
| `func`  | Is the most common function defining function.
| `funct` | Is similar to `func`, but by default makes internal variables locals.
| `has`   | Is for creating functions that have no formal arguments, only local variables.
| `does`  | Is for creating functions that have no variables at all.


More about functions is found in [defining functions](https://www.rebol.com/r3/docs/guide/code-functions.html).


------------------------------------------------------------------
## get-path!


A `get-path!` retrieves the value a path points to without triggering any evaluation side effects — in particular, it will return a function value rather than calling it. It is the path equivalent of a `get-word!`.

Prefixing a path with a colon `:` produces a `get-path!`:

```rebol
:root/word
```

Compare the three behaviours:

```rebol
; Plain path — evaluates; calls a function if found
obj/hello
; hello! hello!

; get-path — returns the function value itself, does not call it
:obj/hello
;== func [] [print "hello! hello!"]
```

This is useful when you need to pass a function as a value rather than invoke it, or when you want to retrieve a path's value while suppressing any other evaluation effects:

```rebol
saved: :obj/hello
saved
; hello! hello!
```

For plain data (non-function values), a `get-path!` behaves the same as a plain `path!`:

```rebol
probe USA/CA/Willits/population
;== 9935

probe :USA/CA/Willits/population
;== 9935
```

### Related
Use `get-path?` to test whether a value is a `get-path!`. Use `to-get-path` to convert other values:

```rebol
to-get-path "root sub"   ;== :root/sub
to-get-path [root sub]   ;== :root/sub
```

See `path!` for the full set of path types, series operations on paths, and how paths are evaluated.


------------------------------------------------------------------
## get-word!


A `get-word!` retrieves the value of a word without triggering any evaluation side effects — in particular, it will return a function value rather than calling it. It is written as a word prefixed with a colon:

```rebol
:word
```

Compare the two behaviours:

```rebol
; Plain word — evaluates; calls a function if found
print
;** Error: missing argument

; get-word — returns the function value itself, does not call it
:print
;== func [value /only] [...]
```

This is useful when you need to pass a function as a value rather than invoke it:

```rebol
saved: :print
saved "hello"
; hello
```

For plain data (non-function values), a `get-word!` behaves the same as a plain `word!`:

```rebol
count: 42
probe count    ;== 42
probe :count   ;== 42
```

### Related
Use `get-word?` to test whether a value is a `get-word!`. Use `to-get-word` to convert other values:

```rebol
to-get-word "test"   ;== :test
to-get-word 'test    ;== :test
```

See `word!` for the full set of word types and how words are evaluated.


------------------------------------------------------------------
## gob!


**A GOB is a low-level graphical object.**

GOBs are used for for constructing windows, panels, images, text, and drawings. They support two dimensional compositing with transparency (alpha channel), scalar vector graphics, image effects, and rich-text.

A GOB is a highly optimized native datatype. It has been designed to provide the primary features required for graphics, but substantially reduce the memory footprint and processing overhead required. As a result, complex displays, such as animations, simulations, or video games can be created that are composed of thousands of individual GOB elements.

Full details about GOBs can be found on the [R3 View - Graphical Objects](https://www.rebol.com/r3/docs/view/gobs.html) page.



------------------------------------------------------------------
## handle!


arbitrary internal object or value



------------------------------------------------------------------
## hash!


This Rebol 2 datatype is now implemented in Rebol 3 only as a plain `block!` (placeholder - without hashing)!



------------------------------------------------------------------
## image!

The `image!` datatype is a series that holds RGBA image data. Each pixel is stored as a 4-component tuple (red, green, blue, alpha). Images can be loaded from files, constructed programmatically, and manipulated as a series.

Supported file formats depend on the available codecs. Common ones include PNG, BMP, JPEG, and GIF. Check `system/catalog/codecs` to see what is available in your build.


### Construction

Create an empty image by providing a size as a `pair!`. The default pixel color is white with full opacity (`255.255.255.255`):

```rebol
make image! 2x2
make image! 300x300
```

Create an image with a uniform color by providing a size and an RGB or RGBA tuple:

```rebol
make image! [2x2 255.0.0]        ;; red, fully opaque (alpha defaults to 255)
make image! [2x2 255.0.0.128]    ;; red, semi-transparent
```

Create an image from raw binary data (RGBA, 4 bytes per pixel):

```rebol
make image! [2x1 #{010203FF040506FF}]
```

Using the literal syntax:

```rebol
#(image! 1x1)                    ;; 1x1 white image
#(image! 1x1 #{FFFFFF})          ;; RGB data only
#(image! 1x1 #{FFFFFF} #{FF})    ;; RGB + alpha channel separately
#(image! 1x1 20.20.20.60)        ;; from RGBA tuple
```

An optional trailing integer in the literal sets the initial index:

```rebol
img: #(image! 1x1 #{FFFFFF} 2)
index? img   ;== 2
```

Load an image from a file:

```rebol
img: load %photo.png
img: load %photo.jpg
```

Save an image to a file:

```rebol
save %output.png img
save %output.bmp img
```

The maximum image dimension is 65535 in each axis. Attempting to exceed this produces a `size-limit` error.


### Accessing pixels

Pixels are indexed from 1. Access by integer index (linear) or pair index (x/y coordinates, both 1-based):

```rebol
img: make image! 2x2

img/1        ;== 255.255.255.255   (first pixel)
img/(1x1)    ;== 255.255.255.255   (same pixel by coordinate)
img/(2x1)    ;== 255.255.255.255   (second pixel, first row)
img/0        ;== none              (out of range)
img/5        ;== none              (out of range for 2x2)
```

Use `pick` and `poke` as alternatives:

```rebol
pick img 1           ;== 255.255.255.255
poke img 1 1.2.3     ;; set pixel 1 to RGB 1.2.3 (alpha unchanged)
```

Set pixels using a set-path. Accepts 3- or 4-component tuples (5+ components are silently truncated to 4). Hexadecimal integer notation (`0#RRGGBB` or `0#RRGGBBAA`) may also be used:

```rebol
img/1: 255.0.0       ;; red, alpha unchanged
img/1: 255.0.0.128   ;; red, semi-transparent
img/(2x1): 0.0.255   ;; blue at position 2x1
img/1: 0#8855DD      ;; hex integer notation — same as 136.85.221
img/1: 0#8855DDAA    ;; with alpha
```

Setting alpha only using an integer or char:

```rebol
img/1: 0             ;; fully transparent
img/1: 127           ;; half transparent
img/1: 0#7F          ;; same as 127
img/1: #"^@"         ;; same as 0
```

Values outside 0–255 produce an error.

Access and set individual RGBA components via chained paths (1=R, 2=G, 3=B, 4=A):

```rebol
img/1/1: 10          ;; set red channel of pixel 1
img/1/4: 200         ;; set alpha channel of pixel 1
img/1/1              ;== 10
```

### Size and dimensions

```rebol
img/size             ;== 2x2 (width x height as pair!)
img/width            ;== 2
img/height           ;== 2
```


### Raw data access

Raw pixel data can be read and written as binary or `uint8!` vectors using named accessors:

| Accessor     | Description |
|--------------|-------------|
| `rgb`        | RGB data only (3 bytes per pixel) |
| `alpha`      | Alpha channel only (1 byte per pixel) |
| `rgba`       | RGBA interleaved (4 bytes per pixel) |
| `rgbo`       | RGB + opacity (inverse alpha) |
| `argb`       | Alpha-first RGBA |
| `bgra`       | Blue-green-red-alpha |
| `red`        | Red channel only |
| `green`      | Green channel only |
| `blue`       | Blue channel only |
| `opacity`    | Opacity (inverse of alpha) |
| `gray`       | Grayscale luminosity data |
| `color`      | Average color of the image |
| `luminosity` | Grayscale binary (BT.709) |

```rebol
img/rgb                  ;== #{RRGGBBRRGGGBB...}
img/alpha                ;== #{AA...}
img/rgba                 ;== #{RRGGBBAARR...}

img/rgb: #{010203040506} ;; set RGB from binary
img/alpha: #{6400}       ;; set alpha channel
```

These accessors also accept `uint8!` vectors:

```rebol
img/rgba: make vector! [uint8! #{01020364}]
```

The `color` accessor returns the average pixel color of the image, and when set fills all pixels with the given color (alpha channel is preserved):

```rebol
img/color            ;== 127.127.127.255   ; average color
img/color: 255.0.0   ;; fill with red, alpha unchanged
```


### Color operations

Convert an image (or tuple) to grayscale using `luminosity` (BT.709), `luminosity/luma` (BT.601), or `grayscale` (simple average). These modify the image in place:

```rebol
luminosity img       ;; BT.709 perceptual weighting
luminosity/luma img  ;; BT.601 weighting
grayscale img        ;; simple average of R, G, B
```

For single color tuples:

```rebol
luminosity 255.0.0   ;== 54
grayscale  255.0.0   ;== 85
```

Blend a color into an image or tuple using `tint`. Does not modify the original tuple, but does modify an image in place:

```rebol
tint 100.200.255 128.128.128 50% ;== 114.164.192
tint img 128.128.128 50%         ;; modifies img
```

Convert between RGB and HSV color spaces:

```rebol
rgb-to-hsv 134.116.10            ;== 36.235.134
hsv-to-rgb 36.235.134            ;== 134.116.10
```

Compute the perceptual distance between two colors:

```rebol
color-distance 0.0.0 255.255.255   ;== 764.83...
```


### Premultiplication

Apply alpha premultiplication in place. Has no effect on fully opaque images:

```rebol
premultiply img
```

Operates from the current position — use `head` to ensure the full image is processed.


### Image difference

Compare two images and return the percentage of differing pixels:

```rebol
image-diff img1 img2                   ;; 0% to 100%
image-diff/part img1 img2 offset size  ;; compare a region
```

Images of different sizes are supported — the comparison area is clipped to the smaller image.


### Series operations

Images are series and support the standard series operations. The unit of iteration is one pixel (an RGBA tuple):

```rebol
img: make image! 2x2

length? img                     ;== 4
index? img                      ;== 1
index? next img                 ;== 2
index? tail img                 ;== 5
```

Use `index?/xy` and `indexz?/xy` for coordinate-based indexing (1-based and 0-based respectively):

```rebol
index?/xy img                   ;== 1x1
index?/xy next img              ;== 2x1
index?/xy tail img              ;== 1x3 (one past the last row)

indexz?/xy img                  ;== 0x0
indexz?/xy next img             ;== 1x0
```

Use `at` and `atz` to position by coordinate:

```rebol
at img 2x2                      ;; position at pixel 2x2 (1-based)
atz img 1x1                     ;; position at pixel 1x1 (0-based)
```

Iterate over pixels with `foreach`:

```rebol
foreach p img [
    print p                     ;; each p is an RGBA tuple
]
```

Use `repeat` to iterate with a mutable reference:

```rebol
repeat n img [
    n/1: 255.0.0                ;; set each pixel to red
]
```

Find a pixel by color:

```rebol
find img 66.66.66               ;; returns image at matching position (RGB match, any alpha)
find img 66.66.66.22            ;; exact RGBA match
find/only img 66.66.66          ;; matches ignoring alpha
find img 66                     ;; find by alpha value
```

Append and insert pixels:

```rebol
append img 170.170.170          ;; append one pixel
append img [1.1.1 2.2.2]        ;; append multiple pixels
insert img 170.170.170          ;; insert at current position
```

Note: images have a fixed width. Pixels accumulate in a row buffer and the height only increases once a full row is completed.

Change pixels in place:

```rebol
change img 0.0.0                ;; change pixel at current position
change img another-image        ;; paste image data
change at img 2x2 another-image ;; paste at a specific coordinate
change/dup img 200.200.200 4    ;; fill 4 pixels
```

Blur an image (if the `blur` function is available):

```rebol
blur img 5    ; blur radius 5
```


### Related

Use `image?` to test whether a value is an `image!`:

```rebol
image? img    ;== true
image? 42     ;== false
```

Images are part of the `series!` typeset:

```rebol
series? img   ;== true
```


------------------------------------------------------------------
## integer!

Integers are 64-bit signed values ranging from `-9223372036854775808` to `9223372036854775807`.


### Format

An integer is a sequence of digits with an optional leading `+` or `-` sign. No space is allowed between the sign and the digits. Leading zeros are ignored:

```rebol
0   1234   +1234   -1234   00012   -0123
```

Do not use commas or periods within integers — a period makes it a `decimal!`, and a comma is a delimiter. Use a single quote `'` as a thousands separator for readability. It can appear anywhere after the first digit:

```rebol
2'147'483'647
9'223'372'036'854'775'807
```

### Special notations

Integers can be written in bases 2, 8, 10, and 16 using `base#digits` notation. The `0#` prefix is a shorthand for base 16. Negative notation (e.g. `-16#FF`) is not supported. Values wrap at 64 bits — all bits set gives `-1`:

```rebol
2#1111   ;==  15   (binary)
8#17     ;==  15   (octal)
10#15    ;==  15   (explicit decimal)
16#F     ;==  15   (hexadecimal)
0#F      ;==  15   (hexadecimal shorthand)

2#1111111111111111111111111111111111111111111111111111111111111111   ;== -1
0#FFFFFFFFFFFFFFFF                                                   ;== -1
```

Digits outside the valid range for the base, values exceeding 64 bits, or a negative prefix produce an error.


### Conversion

Use `to integer!` to convert from other types. Decimal values are truncated toward zero:

```rebol
to integer! "123"     ;== 123
to integer! true      ;== 1
to integer! false     ;== 0
to integer! 123.8     ;== 123
to integer! -123.8    ;== -123
```

Use `round` if you need rounding instead of truncation.

Convert from `binary!` — bytes are interpreted as big-endian (network byte order) and are not sign-extended:

```rebol
to integer! #{1000}   ;== 4096
to integer! #{8000}   ;== 32768   ; not -32768 — no sign extension
```

Convert to `binary!` — always produces 8 bytes in big-endian order:

```rebol
to binary! 32768   ;== #{0000000000008000}
to binary! -1      ;== #{FFFFFFFFFFFFFFFF}
```

Convert from `issue!` — useful for HTML hex color values:

```rebol
to integer! #8855DD   ;== 8934877
```

Note that this conversion is not directly reversible as an RGB string, because the integer does not carry information about its intended use. To convert back to a hex color string:

```rebol
to-rgb-str: func [n] [mold to-hex/size n 6]
to-rgb-str to integer! #A8446C   ;== "#A8446C"
```

For working with individual RGB components, use `tuple!` instead:

```rebol
rgb: to tuple! #8855DD   ;== 136.85.221
rgb/2                    ;== 85
```


### Arithmetic and type coercion

Standard arithmetic operators work on integers. When an integer and a decimal are combined, the integer is automatically coerced to a decimal and the result is a decimal:

```rebol
1.2 + 2    ;== 3.2
2 + 1.2    ;== 3.2
1.01 > 1   ;== true
0 < 0.001  ;== true
```

Integers cannot be combined directly with strings or other non-numeric types — doing so produces an error:

```rebol
1 + "2"   ;** expect-arg error
```

`97` and `#"a"` (the char with code point 97) have the same numeric value but are not `same?`. Similarly, `1` and `$1` (money) are not `strict-equal?`.

#### Increment and decrement

`++` and `--` increment or decrement a variable in place and return the value _before_ the change:

```rebol
a: 1
++ a   ;== 1
a      ;== 2
-- a   ;== 2
a      ;== 1
```

#### Integer division and remainder

`integer-divide` (also `//`) performs integer division, truncating toward zero. Accepts decimals which are truncated before dividing. Division by zero produces an error:

```rebol
integer-divide 23 10    ;== 2
23 // 10                ;== 2
23.5 // 10              ;== 2
23 // 10.5              ;== 2
2 // 0                  ;** zero-divide error
```

#### Min and max

`min` and `max` work across numeric types:

```rebol
max  3 1      ;== 3
max  3 1.0    ;== 3
min -3 2      ;== -3
min -3 $1     ;== -3
```


### Bit operations

#### Shift

`shift` performs an arithmetic (signed) left or right bit shift. Left shift by a positive amount, right shift by a negative amount. Left shifting into the sign bit is an overflow error:

```rebol
shift 1  1    ;==  2
shift 1 -1    ;==  0
shift 1 63    ;** overflow error
```

`shift/logical` performs an unsigned (logical) shift — right shift fills with zeros rather than sign bits:

```rebol
m: to-integer #{8000000000000000}   ;; minimum integer (most negative)
shift/logical m -63   ;==  1        ;; unsigned right shift
shift         m -63   ;== -1        ;; arithmetic right shift (sign extended)
```

The `<<` and `>>` operators are infix shorthands. Unlike `shift`, `<<` wraps around rather than erroring on overflow:

```rebol
2 << 3        ;==  16
1024 >> 1     ;== 512
1 << 63       ;== -9223372036854775808  ;; wraps — no error
1 << 64       ;==  1                    ;; full wrap-around
```


### Math functions

#### GCD and LCM

`gcd` returns the greatest common divisor — the largest integer that divides both arguments exactly. `lcm` returns the least common multiple — the smallest positive integer divisible by both arguments:

```rebol
gcd 54 24     ;==  6
gcd 24 54     ;==  6
gcd 3  0      ;==  3
gcd 21 -48    ;==  3

lcm 12 18     ;== 36
lcm 0  1      ;==  0
```

#### Primality test

```rebol
prime? 42                   ;== false
prime? 43                   ;== true
prime? 99'504'028'301'131   ;== true
```

#### Random

`random` returns a random integer in the range 1 to n:

```rebol
random 10   ;; a random integer between 1 and 10
```

Use `random/seed` to set the seed for reproducible sequences:

```rebol
random/seed 0
random 100
```


### Related

Use `integer?` to test whether a value is an `integer!`:

```rebol
integer? -1234   ;== true
integer? 1.0     ;== false
```

`form`, `mold`, and `print` all produce the decimal string representation of an integer:

```rebol
mold  123        ;== "123"
form  123        ;== "123"
print 123        ; prints: 123
```

Integers are members of the `number!`, `scalar!`, and `immediate!` typesets.


------------------------------------------------------------------
## issue!

> **WARNING:**
> This section is outdated... in current R3 version `issue!` is `word!` type, not `string!` like in R2!
> Question is, if it should not be changed!


An `issue!` is a series of characters used to sequence symbols or identifiers for things like telephone numbers, model numbers, serial numbers, and credit card numbers.

Issue values are a subset of series, and thus can be manipulated as series:


```rebol
probe copy/part find #888-555-1212 "555" 3
#555
```

### Format
Issues start with a number sign (#) and continue until the first delimiting character (such as a space) is reached.


```rebol
#707-467-8000
#A-0987654321-CD-09876
#1234-5678-4321-8765
#MG82/32-7
```

Values that contain delimiting characters should be written as strings rather than issues.



### Creation
The `to-issue` function converts data to the `issue!` datatype:


```rebol
probe to-issue "1234-56-7890"
#1234-56-7890
```



### Related
Use `issue?` to determine whether a value is an `issue!`  datatype.


```rebol
probe issue? #1234-56-7890
true
```

As issues are a subset of the series pseudotype, use `series?` to check this:


```rebol
probe series? #1234-56-7890
true
```

The `form` function returns an issue as a string without the number sign (#):


```rebol
probe form #1234-56-7890
1234-56-7890
```

The `mold` function returns an issue as a string that can be read by Rebol as an issue value:


```rebol
probe mold #1234-56-7890
#1234-56-7890
```

The `print` function prints an issue to standard output after doing a `reform` on it:


```rebol
print #1234-56-7890
1234-56-7890
```



------------------------------------------------------------------
## library!

This Rebol 2 datatype has not been implemented in Rebol 3.


------------------------------------------------------------------
## list!

This Rebol 2 datatype has not been implemented in Rebol 3.



------------------------------------------------------------------
## lit-path!

A `lit-path!` is a path that is not evaluated when encountered — it yields the path value itself rather than following it. This is the path equivalent of a `lit-word!`.

Prefixing a path with a quote `'` produces a `lit-path!`:

```rebol
'root/sub1/sub2
```

This is most commonly used to assign a path to a variable or pass it as an argument without triggering evaluation:

```rebol
path: 'USA/CA/Willits/population
probe path
;== USA/CA/Willits/population

; Now evaluate it explicitly
probe get path
;== 9935
```

Compare the two behaviours:

```rebol
; Evaluates immediately — returns the value at the path
probe USA/CA/Willits/population
;== 9935

; Does not evaluate — returns the path itself
probe 'USA/CA/Willits/population
;== USA/CA/Willits/population
```

A `lit-path!` becomes a plain `path!` once it has been assigned to a variable. Use a get-word (`:var`) to work with the path value itself afterwards — see `path!` for details on this distinction.

```rebol
probe lit-path? first ['root/sub]
;== true

probe path? path
;== true
```

### Related
Use `lit-path?` to test whether a value is a `lit-path!`. Use `to-lit-path` to convert other values:

```rebol
to-lit-path "root sub"   ;== 'root/sub
to-lit-path [root sub]   ;== 'root/sub
```

See `path!` for the full set of path types, series operations on paths, and how paths are evaluated.


------------------------------------------------------------------
## lit-word!

A `lit-word!` is a word that is not evaluated when encountered — it yields the word value itself rather than looking up what the word refers to. It is written as a word prefixed with a quote:

```rebol
'word
```

Compare the two behaviours:

```rebol
; Plain word — evaluates; returns or calls whatever it refers to
print
;** Error: missing argument

; lit-word — returns the word itself as a value
'print
;== print
```

This is most commonly used to pass a word as a symbol rather than as a reference:

```rebol
probe type? 'test
;== word!
```

Note that the elements of a block are not evaluated, so bare words inside a block are already treated as symbols — a `lit-word!` is typically needed outside of blocks:

```rebol
words: [if while loop until]
probe first words
;== if
```

Once assigned to a variable, a `lit-word!` becomes a plain `word!`:

```rebol
w: 'print
probe type? w
;== word!
```

### Related
Use `lit-word?` to test whether a value is a `lit-word!`. Use `to-lit-word` to convert other values:

```rebol
to-lit-word "test"   ;== 'test
to-lit-word 'test    ;== 'test
```

See `word!` for the full set of word types and how words are evaluated.


------------------------------------------------------------------
## logic!

The `logic!` datatype has two values: `#(true)` and `#(false)`. These are the actual literal forms of logic values. The words `true`, `false`, `on`, `off`, `yes`, and `no` are predefined variables that hold these values — they are not keywords, just convenient names.

`logic!` is a member of the `immediate!` typeset.


### Literal syntax

The canonical literal forms are:

```rebol
#(true)
#(false)
```

The predefined words evaluate to these values:

```rebol
true    ;== #(true)
false   ;== #(false)
on      ;== #(true)
off     ;== #(false)
yes     ;== #(true)
no      ;== #(false)
```

Since these are ordinary words, they can be reassigned — though doing so is strongly discouraged.


### Logic values in conditional expressions

Comparison expressions return logic values:

```rebol
100 = 100              ;== #(true)
10:31:00 < 10:30       ;== #(false)
3 < length? "hello"    ;== #(true)
```

Logic values are used as conditions in `if`, `either`, `while`, `until`, and similar functions:

```rebol
if age = 100 [print "Centennial human"]

print either flag ["on"] ["off"]
```

In a conditional context, `#(false)` and `none` are the only falsy values — everything else, including `0`, empty strings, and empty blocks, is truthy:

```rebol
if 0    [print "truthy"]   ; prints — 0 is not false!
if ""   [print "truthy"]   ; prints
if []   [print "truthy"]   ; prints
if none [print "truthy"]   ; does NOT print
```

`not` returns the complement:

```rebol
not #(true)      ;== #(false)
not #(false)     ;== #(true)
not none         ;== #(true)
not 0            ;== #(false)   ; 0 is truthy, so not 0 is false
```


### Creation

Use `to-logic` or `to logic!` to convert other values:

```rebol
to-logic 0       ;== #(false)
to-logic 200     ;== #(true)
to-logic none    ;== #(false)
to-logic []      ;== #(true)
to-logic "a"     ;== #(true)
```

The rule is: `none` and `0` convert to `#(false)`, everything else to `#(true)`.


### Display

`form`, `mold`, and `print` all produce `true` or `false` as plain text:

```rebol
form  #(true)    ;== "true"
mold  #(false)   ;== "#(false)"
print #(true)    ; true
```


### Related

Use `logic?` to test whether a value is a `logic!`:

```rebol
logic? #(true)   ;== true
logic? on        ;== true
logic? 1         ;== false
logic? none      ;== false
```


------------------------------------------------------------------
## map!


A map is a key-value data structure that provides efficient lookup by key. Unlike a block, where finding a value requires a linear scan, a map uses hashing internally to locate values quickly regardless of size.

Keys can be of almost any datatype — words, strings, integers, floats, pairs, dates, times, characters, binary values, tags, URLs, files, email addresses, and more. Values can be of any type, including `none`.

Maps are case-insensitive by default for most key types. Use the `/case` refinement on functions such as `select`, `find`, `remove/key`, and set operations to perform case-sensitive lookups. Binary keys are always compared case-sensitively.

Word-like keys (`word!`, `set-word!`, `get-word!`, `lit-word!`, `refinement!`) are all treated as equivalent keys — they are normalized internally:

```rebol
m: make map! [a 1 b: 2 :c 3 'd 4 /e 5]
keys-of m
;== [a b c d e]
```


### Construction

There are several equivalent ways to create a map:

```rebol
; map function
m: map [a: 1 b: 2]

; make
m: make map! [a: 1 b: 2]

; literal syntax (preferred for static data)
m: #[a: 1 b: 2]

; alternate literal syntax with explicit type
m: #(map! [a: 1 b: 2])

; empty maps
m: make map! []
m: #[]
```

A map can also be created from a `paren!`:

```rebol
m: make map! to paren! [a: 1 b: 2]
m/a
;== 1
```

Or from another map:

```rebol
m2: make map! m
```

Note that words inside a map retain their binding. A word key bound to a variable in the outer context can be retrieved with `get`:

```rebol
a: 1
m: make map! [k a]
get m/k
;== 1
```


### Accessing values

Use path notation for the most concise access:

```rebol
m: #[a: 1 b: 2]
m/a
;== 1
```

To use a variable or expression as a key, wrap it in parentheses:

```rebol
key: 'a
m/(:key)     ; using a get-word
;== 1

m/(key)      ; using a paren expression
;== 1
```

Non-word keys must always use the parenthesized form:

```rebol
m: #["foo" 42 <tag> 99]
m/("foo")
;== 42
m/(<tag>)
;== 99
```

`select` and `pick` also retrieve values by key:

```rebol
select m 'a       ;== 1
pick m 'b         ;== 2
```

When a key does not exist, `none` is returned:

```rebol
select m 'z
;== none
```


### Setting values

Assign through a path:

```rebol
m/a: 10
m/("new-key"): "hello"
```

Or use `put` or `poke`:

```rebol
put m 'b "foo"     ; returns the value
poke m 'c 3        ; returns the value
```

`append` and `insert` add key-value pairs from a block:

```rebol
m: make map! []
append m [a 1]
insert m [b 2]
values-of m
;== [1 2]
```

Use `append/part` to add only the first N elements of a block (must be an even number to form complete pairs):

```rebol
append/part m [c 3 d 4] 2
```

`append/dup` is not supported on maps and will produce an error.


### Removing entries

Remove a key and its value with `remove/key`:

```rebol
m: #[a: 1 b: 2]
remove/key m 'b
keys-of m
;== [a]
```

`remove/key` is case-insensitive by default. There is no `/case` refinement for `remove/key`; use `find/case` first to verify the key if needed.

Remove all entries with `clear`:

```rebol
clear m
empty? m
;== true
```

Use `remove-each` to remove entries conditionally:

```rebol
m: #[a 1 "b" 2 c _ d: 3]
remove-each [k v] m [any [string? k none? v]]
words-of m
;== [a d]
```

Use `remove-each/count` to get the number of removed entries:

```rebol
m: #[a 1 "b" 2 c _ d: 3]
remove-each/count [k v] m [any [string? k none? v]]
;== 2
```


### Case sensitivity

Most key types are case-insensitive by default:

```rebol
m: #[a: 1 A: 2]     ; only one entry — A and a are the same key
length? m
;== 1
```

Use `/case` to distinguish case:

```rebol
select m 'A           ;== 1   (case-insensitive, matches first)
select/case m 'A      ;== 2   (case-sensitive, matches A specifically)
```

Binary keys are always compared case-sensitively, regardless of `/case`:

```rebol
m: #[#{61} 1 #{41} 2]
select m #{41}        ;== 2
```

String and file keys follow the same case-insensitive default:

```rebol
m: make map! ["foo" 1 "FOO" 2]
length? m
;== 2   ; strings are case-sensitive by default — both are kept
```

Note: unlike words, strings and files are case-sensitive by default, so `"foo"` and `"FOO"` are distinct keys.


### Iterating

Use `foreach` to iterate over key-value pairs:

```rebol
m: #[a: 1 b: 2]
foreach [k v] m [
    print [k "=>" v]
]
; a => 1
; b => 2
```

The iteration order is consistent with `keys-of`.


### Reflection

```rebol
m: #[a: 1 b: 2]

keys-of m        ;== [a b]
values-of m      ;== [1 2]
body-of m        ;== [a: 1 b: 2]
length? m        ;== 2
empty? m         ;== false
```

`words-of` is an alias for `keys-of` when all keys are words. For maps with mixed key types, use `keys-of`.

Convert a map to a block:

```rebol
to block! m
;== [a: 1 b: 2]
```


### Copying

`copy` produces a shallow copy — nested series values are shared:

```rebol
m1: #[b: [1]]
m2: copy m1
same? m1/b m2/b     ;== true
```

`copy/deep` copies nested values as well:

```rebol
m3: copy/deep m1
same? m1/b m3/b     ;== false
```


### Comparison

Maps are compared order-independently — the order of keys does not affect equality:

```rebol
equal? #[a: 1 b: 2] #[b: 2 a: 1]
;== true
```

`equal?` is case-insensitive for string values:

```rebol
equal? #[a: 1 c: "a"] #[a: 1 c: "A"]
;== true
```

`strict-equal?` requires exact value matching including case:

```rebol
strict-equal? #[a: 1 c: "a"] #[a: 1 c: "A"]
;== false
```


### Set operations

Maps support `difference`, `exclude`, `intersect`, `union`, and `unique`. All are case-insensitive by default; use `/case` for case-sensitive behaviour.

```rebol
m1: #[a: 1 b: 2]
m2: #[a: 10 c: 3]

union m1 m2          ;== #[a: 1 b: 2 c: 3] (m1 values take precedence)
intersect m1 m2      ;== #[a: 1]           (keys in both, m1 values)
difference m1 m2     ;== #[b: 2 c: 3]      (keys in one but not both (symmetric))
exclude m1 m2        ;== #[b: 2]           (keys in m1 but not m2)
unique m1            ;== #[a: 1 b: 2]      (removes duplicate keys (none here))
```

### Protection

Use `protect` and `unprotect` to make a map read-only:

```rebol
m: map [a: 42]
protect m
m/a: 0              ;** Error: protected
m/a                 ;== 42
unprotect m
m/a: 0              ; ok now
```


### Display

`form` produces a human-readable string:

```rebol
form #[a: 1 b: 2]
;== "a: 1^/b: 2"
```

`mold` produces a string that can be reloaded as a map:

```rebol
mold #[a: 1 b: 2]
;== "#[a: 1 b: 2]"
```


### Related
Use `map?` to test whether a value is a `map!`:

```rebol
map? #[a: 1]     ;== true
map? [a 1]       ;== false
```

> **Size Limit:**
> Currently, maps are limited to 2^26 - 1 (67'108'863) entries.


------------------------------------------------------------------
## module!


loadable context of code and data



------------------------------------------------------------------
## money!


There is a wide variety of international symbols for monetary denominations. Some symbols are used before the amount and some after. As a standard for representing international monetary values, the Rebol language uses the United States monetary format, but allows the inclusion of specific denominations.


### Format
The `money!` datatype uses standard IEEE floating point numbers allowing up to 15 digits of precision including cents.

The language limits the length to 64 characters. Values that are out of range or cannot be represented in 64 characters are flagged as an error.

Monetary values are prefixed with an optional currency designator, followed by a dollar sign ($). A plus (+) or minus (-) can appear immediately before the first character (currency designator or dollar sign) to indicate sign.


```rebol
$123
-$123
$123.45
US$12
US$12.34
-US$12.34
$12,34
-$12,34
DEM$12,34
```

To break long numbers into readable segments, a single quote `'` can be placed anywhere between two digits within the amount, but not before the amount.


```rebol
probe $1'234.56
$1234.56

probe $1'234'567,89
$1234567.89
```

Do not use commas and periods to break up large amounts, as both these characters represent decimal points.

The `money!` datatype is a hybrid datatype. Conceptually money is scalar -- an amount of money. However, because the currency designation is stored as a string, the `money!` datatype has two elements:

- `string!`  - The currency designator string, which can have 3 characters maximum.
- `decimal!` - The money amount.


To demonstrate this, the following money is specified with the USD prefix:

```rebol
my-money: USD$12345.67
```

Here are the two components:

```rebol
probe first my-money
USD

probe second my-money
12345.67

probe pick my-money 3       ; only two components
none
```

If no currency designator is used, the currency designator string is empty:


```rebol
my-money: $12345.67

probe first my-money
""

probe second my-money
12345.67
```

Various international currencies can be specified in the currency designator, such as:


```rebol
my-money: DKM$12'345,67

probe first my-money
DKM

probe second my-money
12345.67
```



### Creation
Use the `to-money` function to convert money from a `string!`, `integer!`, `decimal!`, or `block!`.


```rebol
probe to-money 123
$123.00

probe to-money "123"
$123.00

probe to-money 12.34
$12.34

probe to-money [DEM 12.34]
DEM$12.34

probe to-money [USA 12 34]
USA$12.34
```

Money can be added, subtracted, and compared with other money of the same currency. An error occurs if a different currency is used for such operations (automatic conversions are not currently supplied).


```rebol
probe $100 + $10
$110.00

probe $100 - $50
$50.00

probe equal? DEM$100.11 DEM$100.11
true
```

Money can be multiplied and divided by integers and decimals. Money can also be divided by money, resulting in an integer or decimal.


```rebol
probe $100 + 11
$111.00

probe $100 / 4
$25.00

probe $100 * 5
$500.00

probe $100 - 20.50
$79.50

probe 10 + $1.20
$11.20

probe 10 - $0.25
$9.75

probe $10 / .50
$20.00

probe 10 * $0.75
$7.50
```


### Related
Use `money?` to determine whether a value is an `money!`  datatype.


```rebol
probe money? USD$12.34
true
```

Use the `form`, `print`, and `mold` functions with a money argument to print a money value with the currency designator and dollar sign ($), as a decimal number with two digits of decimal precision.


```rebol
probe form USD$12.34
USD$12.34

probe mold USD$12.34
USD$12.34

print USD$12.34
USD$12.34
```



------------------------------------------------------------------
## native!

A `native!` is a function implemented directly in the interpreter's host language (C) rather than in Rebol code. Natives have the same calling interface as regular functions — they accept arguments, support refinements, and return values — but their bodies are not accessible as Rebol code.

Most of Rebol's built-in functions are natives: `if`, `loop`, `do`, `reduce`, and so on.

To list all natives:

```rebol
help native!
```

### Reflection

`spec-of` returns the argument spec, just as with other function types:

```rebol
spec-of :if
spec-of :reduce
```

`body-of` on a native returns `none` — there is no Rebol-level body to inspect.

### Related

Use `native?` to test whether a value is a `native!`:

```rebol
native? :if       ;== true
native? :append   ;== false   ; append is an action!
native? :+        ;== false   ; + is an op!
```

`native!` is a member of the `any-function!` typeset.



------------------------------------------------------------------
## none!

The `none!` datatype has a single value representing the absence of a value. It is distinct from `0`, `#(false)`, empty strings, and empty blocks — it is an explicit value meaning "nothing here".

The literal forms are `#(none)` and `_` (they are equivalent):

```rebol
#(none)    ;== _
_          ;== _
```

The word `none` is predefined to hold `_` — it is not a keyword, just a convenience:

```rebol
none       ;== _
```

`none!` is a member of the `immediate!` typeset.


### Common uses

Many series functions return `_` when nothing is found:

```rebol
find "abcd" "e"      ;== _
pick [1 2 3] 10      ;== _
select [a 1 b 2] 'c  ;== _
```

It is useful as a placeholder for missing values in data structures:

```rebol
email-database: [
    "Bobby" bob@rebol.com  40
    "Linda" _              23
    "Sara"  sara@rebol.net 33
]
```

It can be used to disable or clear settings:

```rebol
secure _
date/zone: _    ; remove timezone from a date
```


### Conditional behaviour

In conditional expressions, `_` is falsy — the same effect as `#(false)`:

```rebol
if find "abcd" "e" [print "found"]   ; does not print — find returned _

if _ [print "yes"]                   ; does not print
if 0 [print "yes"]                   ; prints — 0 is truthy!
```


### Creation

Any value can be converted to `_` using `to none!` — it always returns `_` regardless of input:

```rebol
to none! 42           ;== _
to none! "hello"      ;== _
to none! #(true)      ;== _
```


### Display

`mold` produces the literal form; `form` produces the word `none`:

```rebol
mold  _               ;== "_"
form  _               ;== "none"
print _               ; none
```


### Related

Use `none?` to test whether a value is a `none!`:

```rebol
none? _               ;== #(true)
none? find [1 2 3] 4  ;== #(true)
none? 1               ;== #(false)
```


------------------------------------------------------------------
## object!


context of names with values

### Creation
There are a couple issues to be addressed with object creation:

- Should objects deep copy values found in their body (init) blocks?
- Should objects deep copy values found in their parent object?

The best way to analyze this situation is to create a test case. The test below determines how the major aggregate types are handled:

```code
b1: reduce/no-set [
    str: "abc"
    bin: #{010203}
    blk: [a b c]
    vec: make vector! [integer! 32 [1 2 3 4]]
    img: make image! [2x1 #{010101 020202}]
    obj: make object! [data: "abc"]
]

o1: make object! b1
o2: make object! b1
o3: make o1 []
o4: make o1 b1

compare: func ['a 'b][
    print ["comparing" a "to" b]
    a: get a
    b: get b
    foreach [word val] a [
        if same? :val get in b word [
            print ["  " word "field is shared"]
        ]
    ]
    print ""
]

compare o1 o2
compare o1 o3
compare o1 o4
```


So, the values of the object body block are not copied, but the values of parent fields are copied, with the exception of vectors, images and objects.

Comparing with R2 the difference (other than vector! missing in R2) is in the second case:


```rebol
comparing o1 to o3
   obj field is shared
```

So, even the image is copied (although there is a bug in R2 in this regard.) It should also be noted that block values are deep copied in both R2 and R3.

If our goal for R3 is to remain "almost compatible" with R2, then we need to copy images and not copy objects. Also, to be consistent so that users don't have to remember extra rules, we should also copy vectors.

We can now ask these questions:

- What if the user does not want any copying?
- What if the user wants to copy everything?

Clearly, we need a few other options. How best to provide them?

If we don't want to add refinements to `make`, then perhaps we can use `copy` to provide some of the functionality?

If we `copy` of an object and do not specify `/deep` then the object is copied but none of its values are copied. Everything is shared.

If we use `/deep`, then all of the source object's values are deep copied. (But, it should be noted that nothing is rebound to the new object. You would need to do that step manually.)

In summary:

- `make` will deep copy all values, except objects
- `copy` will shallow copy the object only
- `copy` `/deep` will deep copy the entire object, including sub-objects



------------------------------------------------------------------
## op!

### Concept

An `op!` is an infix operator — a function that takes exactly two arguments, one on its left and one on its right. Unlike regular functions which are called with arguments following the function word, an `op!` is placed between its arguments:

```rebol
1 + 2     ; + is an op!
2 * 3     ; * is an op!
```

All built-in arithmetic and comparison operators (`+`, `-`, `*`, `/`, `=`, etc.) are `op!` values. To list all defined operators:
```code
help op!
```

### Construction

An `op!` can be created from a two-argument spec block, an existing `function!`, or an existing `action!`. The function or spec must take exactly two arguments — one or three or more arguments produce a `bad-make-arg` error.

#### From a spec block

```rebol
+*: make op! [[a b] [a + (a * b)]]
1 +* 2   ;== 3   ; 1 + (1 * 2)
2 +* 2   ;== 6   ; 2 + (2 * 2)
```

The spec block follows the same conventions as `func` — it can include argument descriptions and `/local` variables:

```rebol
.: make op! [[a "val1" b "val2" /local c] [c: none join a b]]
"a" . "b"        ;== "ab"
"a" . ["b" "c"]  ;== "abc"
```

#### From an existing function

```rebol
fce: func [a b] [a * b]
op2: make op! :fce
2 op2 3   ;== 6
```

#### From an existing action

```rebol
op1: make op! :remainder
6 op1 3   ;== 0
```

### Reflection

Use `spec-of` and `body-of` to inspect an `op!`:

```rebol
spec-of :+*   ;== [a b]
body-of :+*   ;== [a + (a * b)]

spec-of :.    ;== [a "val1" b "val2" /local c]
body-of :.    ;== [c: none join a b]
```

### Related

Use `op?` to test whether a value is an `op!`:

```rebol
op? :+    ;== true
op? :add  ;== false
```


------------------------------------------------------------------
## pair!


A pair! datatype is used to indicate spatial coordinates, such as positions on a display.  They are used for both positions and sizes.  Pairs are used primarily in Rebol/View.


### Format
A pair  is specified as integers separated by an x` character.

```rebol
100x50

1024x800

-50x200
```

### Creation
Use `to-pair` to convert block or string values into a pair datatype:

```rebol
p: to-pair "640x480" 
probe p
640x480

p: to-pair [800 600] 
probe p
800x600
```

### Related
Use `pair?` to determine whether a value is a `pair!` datatype:

```rebol
probe pair? 400x200
true

probe pair? pair
true
```

Pairs can be used with most integer math operators:

```rebol
100x200 + 10x20

10x20 * 2x4

100x30 / 10x3

100x100 * 3

10x10 + 3
```

Pairs can be viewed by their individual coordinates:

```rebol
pair: 640x480
probe first pair
640

probe second pair
480
```

All pair values support the `/x` and `/y` refinements. These refinements allow the viewing and manipulation of individual pair coordinates.

Viewing individual coordinates:

```rebol
probe pair/x
640

probe pair/y
480
```

Modifying individual coordinates:

```rebol
pair/x: 800
pair/y: 600
probe pair
800x600
```


------------------------------------------------------------------
## paren!


A `paren!` datatype is a block that is immediately evaluated.  It is identical to a block in every way, except that it is evaluated when it is encountered and its result is returned.

When used within an evaluated expression, a `paren!` allows you to control the order of evaluation:

```rebol
print 1 + (2 * 3)
7

print 1 + 2 * 3
9
```

The value of a `paren!` can be accessed and modified in the same way as any block. However, when referring to a `paren!`, care must be taken to prevent if from being evaluated. If you store a paren in a variable, you will need to use a get-word form (`:word`) to prevent it from being evaluated.

Parens are a type of series, thus anything that can be done with a series can be done with paren values.

```rebol
paren: first [(1 + 2 * 3 / 4)]

print type? :paren
paren!

print length :paren
7

print first :paren
1

print last :paren
4

insert :paren [10 + 5 *]
probe :paren
(10 + 5 * 1 + 2 * 3 / 4)

print paren
12.75
```

### Format
Parens are identified by their open and closing parenthesis. They can span multiple lines and contain any data, including other paren values.


### Creation
The `make` function can be used to allocate a paren value:

```rebol
paren: make paren! 10
insert :paren 10
insert :paren `+
insert :paren 20

print :paren
20 + 10

print paren
30
```

The `to-paren` function converts data to the `paren!` datatype:

```rebol
probe to-paren "123 456"
(123 456)

probe to-paren [123 456]
(123 456)
```


### Related
Use `paren?` to test the datatype.

```rebol
blk: [(3 + 3)]
probe pick blk 1
(3 + 3)

probe paren? pick blk 1
true
```

As parens are a subset of the `series!` pseudotype, use `series?` to check this:

```rebol
probe series? pick blk 1
true
```

Using `form` on a paren value creates a string from the contents contained in the paren:

```rebol
probe form pick blk 1
3 + 3
```



------------------------------------------------------------------
## path!


Paths are a collection of words and values delineated with forward slashes `/`. Paths are used to navigate to or find something.

Paths can be used on series, maps, functions, and objects.  How a path operates depends on the datatype being used. Thus paths can be used to select values from blocks, pick characters from strings, access variables in objects, refine the operation of a function:
```rebol
USA/CA/Ukiah/size (block selection)

names/12          (string position)

account/balance   (object function)

match/any         (function option)
```

The example below shows the simplicity of using a path to access a mini-database created from a few blocks:
```rebol
towns: [
    Hopland [
        phone #555-1234
        web   http://www.hopland.ca.gov
    ]

    Ukiah [
        phone #555-4321
        web   http://www.ukiah.com
        email info@ukiah.com
    ]
]

print towns/ukiah/web
http://www.ukiah.com
```

Summary of path constructs:

| Action       | Type Word | Type Test | Conversion
|--------------|-----------|-----------|-------------
| `root/word:` | set-path! | set-path? | to-set-path
| `:root/word` | get-path! | get-path? | to-get-path
| `root/word`  | path!     | path?     | to-path
| `'root/word` | lit-path! | lit-path? | to-lit-path

Examples of paths:

Evaluate an object's function:
```rebol
obj: make object! [
    hello: func [] [print "hello! hello!"]
]
obj/hello
hello! hello!
```

Evaluate an object's word:
```rebol
obj: make object! [
    text: "do you believe in magic?"
]
probe obj/text
do you believe in magic?
```

Function refinements:
```rebol
hello: func [/again] [
    print either again ["hello again!"]["hello"]
]
hello/again
hello again!
```

Select from blocks, or multiple blocks:
```rebol
USA: [
    CA [
        Ukiah [
            population 15050
            elevation [610 feet]
        ]
        Willits [
            population 5073
            elevation [1350 feet]
        ]
    ]
]

print USA/CA/Ukiah/population
15050

print form USA/CA/Willits/elevation
1350 feet
```

Pick elements from series and embedded series by their numeric position:
```rebol
string-series: "abcdefg"
block-series: ["John" 21 "Jake" 32 "Jackson" 43 "Joe" 52]
block-with-sub-series: [ "abc" [4 5 6 [7 8 9]]]

string-series/4             ;== #"d"
block-series/3              ;== "Jake"
block-series/6              ;== 43
block-with-sub-series/1/2   ;== #"b"
block-with-sub-series/2/2   ;== 5
block-with-sub-series/2/4/2 ;== 8
```

The words supplied as path selectors are symbolic and therefore unevaluated. This is necessary to allow the most intuitive form for object referencing. To use a word's reference, an explicit word value reference is required:
```rebol
city: 'Ukiah
probe USA/CA/:city
[
    population 15050
    elevation "610 feet"
]
```

Paths in blocks, maps and objects are evaluated by matching the word at the top level of the path, and verifying the word as a `series!`, `map!` or `object!` value. Then the next value in the path is sought and an implicit `select` is performed. The value following the matched value is returned. When the returned value is a block, map, or object, the path can be extended:

Getting the value associated with `CA` in `USA`:
```rebol
probe USA/CA
[
    Ukiah [
        population 15050
        elevation "610 feet"
    ]
    Willits [
        population 9935
        elevation "1350 feet"
    ]
]
```

Getting the value associated with `Willits` in `USA/CA`:
```rebol
probe USA/CA/Willits
[
    population 9935
    elevation "1350 feet"
]
```

Getting the value associated with `population` in `USA/CA/Willits`:
```rebol
probe USA/CA/Willits/population
9935
```

When a value is used in a path that does not exist at the given point in the structure, an error is produced:
```rebol
probe USA/CA/Mendocino
** Script Error: Invalid path value: Mendocino.
** Where: probe USA/CA/Mendocino
```

Paths can be used to change values in series, maps and objects:
```rebol
USA/CA/Willits/elevation: "1 foot, after the earthquake"
probe USA/CA/Willits
[
    population 9935
    elevation "1 foot, after the earthquake"
]

obj/text: "yes, I do believe in magic."
probe obj
make object! [
    text: "yes, I do believe in magic."
]
```

Series, functions, and objects can be mixed in paths.

Selecting from elements in a block inside an object:
```rebol
obj: make object! [
    USA: [
        CA [
            population "too many"
        ]
    ]
]
obj/USA/CA/population
;== "too many"
```

Using function refinements within an object:
```rebol
obj: make object! [
    hello: func [/again] [
        either again [
            "hello again"
        ] [
            "oh, hello"
        ]
    ]
]
obj/hello/again
;== "hello again"
```

Paths are themselves type of series, thus anything that can be done with a series can be done with path values:
```rebol
root: [sub1 [sub2 [
    word "a word at the end of the path"
    num 55
]   ]   ]
path: 'root/sub1/sub2/word
probe :path
;== root/sub1/sub2/word
```

In the previous example, the `:path` notation was used to get the path itself, not the path's value:
```rebol
probe path
;== "a word at the end of the path"
```

Looking at how long a path is:
```rebol
length? :path
;== 4
```

Finding a word within a path:
```rebol
find :path 'sub2
;== sub2/word
```

Changing a word in a path:
```rebol
change find :path 'word 'num
probe :path
;== root/sub1/sub2/num

path
;== 55
```


### Format
Paths are expressed relative to a root word by providing a number of selection expressions, each separated by a forward slash `/`. These expressions can be any value type. Their specific interpretation varies depending on the datatype of the root value.

The words supplied as selection expressions in paths are symbolic and are not evaluated. This is necessary to allow the most intuitive form for object referencing. To use a word's reference, an explicit word value reference is required:
```rebol
root/:word
```

This example uses the value of the variable, rather than its name.


### Creation

You can `make` an empty path of a given size with:
```rebol
path: make path! 10
insert :path 'test
insert tail :path 'this
probe :path
;== test/this
```

The `to-path` function converts data to the `path!` datatype:
```rebol
to-path [root sub]     ;== root/sub
to-path "root sub"     ;== root/sub
```

The `to-set-path` function converts other values to the `set-path!` datatype.
```rebol
to-set-path "root sub" ;== root/sub:
```

The `to-get-path` function converts other values to the `get-path!` datatype.
```rebol
to-get-path "root sub" ;== :root/sub
```

The `to-lit-path` function converts other values to the `lit-path!` datatype.
```rebol
to-lit-path "root sub" ;== 'root/sub
```

> **Note:**
> The `to-*` conversion functions are convenience wrappers around their `to <type>!` equivalents:
> ```rebol
> to-path  [root sub] ;== root/sub
> to path! [root sub] ;== root/sub
> ```
> When performance is critical, prefer the `to <type>!` form as it avoids the overhead of the wrapper function.

Use `as` to coerce a path to a related type without copying the underlying data. This is useful for treating a path as a block or vice versa:
```rebol
as block! 'root/sub   ;== [root sub]
as path! [root sub]   ;== root/sub
```


### Related
Use `path?`, `set-path?`, `get-path?`, and `lit-path?` to determine the datatype of a value.


```rebol
probe path? second [1 two "3"]
false

blk: [sub1 [sub2 [word 1]]]
blk2: [blk/sub1/sub2/word: 2]
if set-path? (pick blk2 1) [print "it is set"]
it is set

probe lit-path? first ['root/sub]
true
```

As paths are a subset of the `series!` typeset, use `series?` to check this:


```rebol
probe series? pick [root/sub] 1
true
```

Use `form` on a path value creates a string from the path:


```rebol
probe form pick [root/sub] 1
root/sub
```

Use `mold` on a path value creates a string of the path value itself, thus allowing it to be reloaded as a Rebol path value:


```rebol
probe mold pick [root/sub] 1
root/sub
```



------------------------------------------------------------------
## percent!

### Concept

A `percent!` value represents a ratio expressed as a percentage. Internally it is stored as a decimal — `100%` is `1.0`, `1%` is `0.01`. It is a member of the `number!` and `scalar!` typesets.

```rebol
number? 1%   ;== true
```

### Format

Percent values are written as a number followed immediately by `%`:

```rebol
0%  1%  10%  0.1%  100%  -1%
```

Scientific notation is also accepted:

```rebol
1E+2%       ;== 100%
3e34%
```

### Construction

`make percent!` accepts an integer or decimal, interpreting it as a ratio (not a percentage display value) — so `1` becomes `100%` and `0.5` becomes `50%`:

```rebol
make percent! 1      ;== 100%
make percent! 0.5    ;== 50%
```

A block of `[mantissa exponent]` constructs a scientific notation value:

```rebol
make percent! [1 18]   ;== 1e18%
```

### Conversion

```rebol
to percent! 1      ;== 100%
to percent! 1.0    ;== 100%

to decimal! 100%   ;== 1.0
to decimal! 1%     ;== 0.01

to integer! 100%   ;== 1
to integer! 1%     ;== 0    ; truncates toward zero
```

### Display

`form` and `mold` produce identical output — the value followed by `%`:

```rebol
form  0%     ;== "0%"
form  0.1%   ;== "0.1%"
form  100%   ;== "100%"
form -1%     ;== "-1%"
```

Large values use scientific notation:

```rebol
mold 3e34%        ;== "3e34%"
mold/all 3e34%    ;== "3.0000000000000003e34%"
```

`mold/all` preserves full precision and round-trips correctly through `load`:

```rebol
x: 9.9999999999999926e154%
same? x load mold/all x   ;== true
```

### Related

Use `percent?` to test whether a value is a `percent!`:

```rebol
percent? 10%    ;== true
percent? 0.1    ;== false
```


------------------------------------------------------------------
## port!


external series, an I/O channel



------------------------------------------------------------------
## rebcode!

> **Note:**
> This datatype has not been implemented in Rebol 3.


------------------------------------------------------------------
## refinement!

A `refinement!` is a word prefixed with a forward slash `/`. Refinements serve two distinct purposes: as optional modifiers to function calls, and as path steps when navigating into series, objects, and URLs.

`refinement!` is a member of the `any-word!` and `immediate!` typesets.


### Format

A refinement is written as `/` followed by a valid Rebol word:

```rebol
/only
/part
/case
/save-it
/test1
```


### As function modifiers

When used in a function call, a refinement enables an optional behaviour of that function:

```rebol
append/only [1 2] [3 4]   ;; appends [3 4] as a single element
copy/part "abcde" 3       ;; copies only 3 characters
find/case "abcABC" "A"    ;; case-sensitive search
```

Refinements are declared in function specs and can be combined:

```rebol
save-data: func [file data /limit n /reload] [...]

save-data/limit %out.txt data 100
save-data/limit/reload %out.txt data 100
```


### As path steps

Refinements also appear as steps in paths — when navigating objects, files, or URLs:

```rebol
system/version
system/catalog/datatypes

dir: %docs/core
read dir/file.txt

site: http://www.rebol.com
read site/index.html
```

In this context a refinement is functionally the same as a word step in a path.


### Creation

Refinements can be written as literals or converted from other types:

```rebol
/test

to-refinement "test"    ;== /test
to-refinement 'test     ;== /test
```


### Related

Use `refinement?` to test whether a value is a `refinement!`:

```rebol
refinement? /only    ;== true
refinement? 'only    ;== false
```



------------------------------------------------------------------
## routine!

> **Note:**
> This datatype has not been implemented in Rebol 3. See `library!`.



------------------------------------------------------------------
## set-path!

A `set-path!` assigns a value to the location a path points to. It is the path equivalent of a `set-word!`.

Appending a colon `:` to a path produces a `set-path!`:

```rebol
root/word:
```

When evaluated, the expression to the right of the `set-path!` is assigned to that location:

```rebol
USA/CA/Willits/population: 9999
probe USA/CA/Willits/population
;== 9999
```

This works on series, maps, and objects:

```rebol
; Series (block)
USA/CA/Willits/elevation: "1 foot, after the earthquake"

; Object field
obj/text: "yes, I do believe in magic."
```

Compare with a plain `path!`, which reads a value rather than setting it:

```rebol
; Reads the value
probe USA/CA/Willits/population
;== 9999

; Sets the value
USA/CA/Willits/population: 12345
```

### Related
Use `set-path?` to test whether a value is a `set-path!`. Use `to-set-path` to convert other values:

```rebol
to-set-path "root sub"   ;== root/sub:
to-set-path [root sub]   ;== root/sub:
```

See `path!` for the full set of path types, series operations on paths, and how paths are evaluated.

------------------------------------------------------------------
## set-word!

A `set-word!` assigns a value to a word within the current context. It is written as a word followed by a colon:

```rebol
word:
```

When evaluated, the expression to the right is evaluated and the result is bound to the word:

```rebol
name: "John"
count: 42
items: [a b c]
```

A `set-word!` is the most common way to define variables in REBOL. Compare with a plain `word!`, which retrieves a value rather than setting it:

```rebol
; Sets the value
count: 42

; Gets the value
print count
;== 42
```

### Related
Use `set-word?` to test whether a value is a `set-word!`. Use `to-set-word` to convert other values:

```rebol
to-set-word "test"   ;== test:
to-set-word 'test    ;== test:
```

See `word!` for the full set of word types and how words are evaluated.


------------------------------------------------------------------
## string!

A `string!` is a series of Unicode characters. All series operations work on strings — the unit of iteration is one character (`char!`). Strings are mutable and support in-place modification.


### Format

Strings are written with double quotes for single-line values:

```rebol
"This is a string."
"Hello, world!"
```

Braces `{ }` are used for multi-line strings or strings containing double quotes. All whitespace, newlines, and tabs inside braces are part of the string. Braces nest — a closing brace only ends the string when it balances the opening brace:

```rebol
{This is a
multi-line string.}

{Nested braces { like this } are fine.}
```

#### Escape sequences

Special characters are written with a caret `^` prefix:

| Sequence          | Description |
|-------------------|-------------|
| `^"`              | Double quote |
| `^}`              | Closing brace |
| `^^`              | Caret character |
| `^/` or `^(line)` | Newline |
| `^-` or `^(tab)`  | Tab |
| `^(page)`         | Form feed |
| `^(back)`         | Backspace |
| `^(null)` or `^@` | Null character |
| `^(esc)`          | Escape |
| `^(del)`          | Delete |
| `^A`–`^Z`         | Control characters (Ctrl+A–Ctrl+Z) |
| `^(xx)`           | Unicode code point in hex (up to 6 digits) |

```rebol
"line one^/line two"
"tab^-separated"
"smiley: ^(1F642)"
```


### Creation

Pre-allocate an empty string with `make`:

```rebol
make string! 40'000
```

Convert other types to string with `to-string` or `to string!`:

```rebol
to-string 29-2-2000        ;== "29-Feb-2000"
to-string 123456.789       ;== "123456.789"
to-string #"A"             ;== "A"
to-string #"^(00)"         ;== "^@"
to-string to-char 0        ;== "^@"
```

Converting a block produces a concatenated string (equivalent to `rejoin` without evaluation):

```rebol
to-string [123 456]                       ;== "123456"
to-string [225.225.225.0 none true 'word] ;== "225.225.225.0nonetrueword"
```


### Encoding and conversion

Strings in Rebol are Unicode (UTF-8 internally). Convert between binary encodings with `iconv`:

```rebol
iconv #{50F869686CE1736974} "ISO-8859-2"  ;== "Přihlásit"
iconv #{C5A1} 'utf-8                      ;== "š"
iconv/to "šik" 'utf-8 'utf-16le           ;== #{1B016101}
```

Convert to binary (UTF-8 encoded):

```rebol
to-binary "^(1234)"    ;== #{E188B4}
to-binary "šik"        ;== #{C5A16B}
```

Convert binary to string — expects valid UTF-8. BOM is handled automatically for UTF-16 and UTF-32:

```rebol
to-string #{EFBBBF616F75}   ;== "aou"   (UTF-8 with BOM)
```

Check for invalid UTF-8:

```rebol
invalid-utf? #{C2E0}        ;== #{C2E0}   (invalid sequence found)
invalid-utf? #{20C3A030}    ;== none      (valid UTF-8)
```

Encode and decode percent-encoding (URL encoding):

```rebol
enhex "šik"              ;== "%C5%A1ik"
dehex "%C5%A1ik"         ;== "šik"
enhex/uri "a b+"         ;== "a+b%2B"    ; space → +, + → %2B
dehex/uri "a+b%2B"       ;== "a b+"
```


### Joining strings

`join` concatenates a value with one or more others. The type of the result matches the first argument:

```rebol
join "a" "b"         ;== "ab"
join "a" ["b" 3]     ;== "ab3"
join %a  ["b" 3]     ;== %ab3
join <a> "b"         ;== <ab>
```

`ajoin` concatenates all values in a block into a string (or the type of the first element if it is a string-like type). `none` and `unset` values are skipped by default:

```rebol
ajoin ["a" "b" 3]           ;== "ab3"
ajoin ["a" none 3]          ;== "a3"    ; none skipped
ajoin/all ["a" none 3]      ;== "anone3" ; none included
ajoin/with ["a" "b" 3] #"/" ;== "a/b/3"
```

`form` converts a block to a space-separated string:

```rebol
form ["a" "b" 3]     ;== "a b 3"
form ["a" none 3]    ;== "a none 3"
```


### Finding and selecting

`find` returns the string at the matching position, or `none`:

```rebol
find "abcde" "bc"          ;== "bcde"
find "abcde" #"c"          ;== "cde"
find "123" 2               ;== "23"    ; integer matches digit
find "id: F00D" #{F00D}    ;== "F00D"  ; binary match
```

Search is case-insensitive by default:

```rebol
find "abcde" #"B"          ;== "bcde"
find/case "abcde" #"B"     ;== none
```

Key refinements:

```rebol
find/last "aabcabc" "ab"      ; last occurrence
find/reverse tail "abc" "ab"  ; search backwards from tail
find/tail "abcde" "bc"        ;== "de"     (position after match)
find/match "abcde" "ab"       ;== "cde"    (match only at current position)
find/any "abcd" "*c?"         ;== "abcd"   (wildcard: * = any chars, ? = one char)
find/same "aAbcdAe" "A"       ;== "AbcdAe" (exact identity match)
```

`select` returns the value following the match:

```rebol
select "abcde" "bcd"       ;== #"e"
select/any "abcde" "b?d"   ;== #"e"
select/last "ab1ab2" "ab"  ;== #"2"
```


### Modifying strings

`append` and `insert` add characters or strings:

```rebol
append "ab" "cd"           ;== "abcd"
append "ab" #"c"           ;== "abc"
append "" #"^(2190)"       ;== "←"   (Unicode char)
insert s: "bc" "a"
head s                     ;== "abc"
```

`change` replaces content at the current position:

```rebol
head change "abc" "X"      ;== "Xbc"
head change/part "abcd" "123" 2   ;== "123cd"
```

`remove` deletes from the current position:

```rebol
remove s: "abc"   ;== "bc"   ; s is now "bc"
remove/part "abcde" 3        ;== "de"
```

`take` removes and returns content:

```rebol
take "abc"                   ;== #"a"
take/part "123456" 2         ;== "12"
take/last "abc"              ;== #"c"
```

`replace` substitutes occurrences:

```rebol
replace "123456" "123" "ABCDE"    ;== "ABCDE456"
replace/all "1 2 3" #" " "!!"     ;== "1!!2!!3"
replace/all "<á>>" ">" #")"       ;== "<á))"
```

`swap` exchanges the characters at two positions:

```rebol
swap s1: "ab" s2: "AB"    ; s1 = "Ab", s2 = "aB"
swap s1: "ab" next s1     ; s1 = "ba"
```


### Sorting and reversing

`sort` modifies in place, case-insensitive by default:

```rebol
sort "ABCabcdefDEF"      ;== "AaBbCcdDeEfF"
sort/case "ABCabc"       ;== "ABCabc"
sort/reverse "abcd"      ;== "dcba"
sort/compare "abczyx" func [a b] [a > b]  ;== "zyxcba"

;; sort by all chars of each 3-char group
sort/all/skip "ba ab aa " 3               ;== "aa ab ba "

;; sort by 1st char of each 3-char group
sort/compare/skip "ba ab aa " 1 3         ;== "ab aa ba "

```

`reverse` modifies in place:

```rebol
reverse "abcd"           ;== "dcba"
reverse/part "abcd" 2    ;== "bacd"
```


### Trimming

`trim` removes whitespace from head and tail by default:

```rebol
trim " a b c "           ;== "a b c"
trim/head " a b c "      ;== "a b c "
trim/tail " a b c "      ;== " a b c"
trim/all "  a b  c  "   ;== "abc"
trim/with "hello" #"l"   ;== "heo"
trim/auto "^-one^/^-two" ;; removes common leading whitespace
```


### Case conversion

```rebol
uppercase "hello"        ;== "HELLO"
lowercase "HELLO"        ;== "hello"
uppercase/part "hello" 1 ;== "Hello"
uppercase/part tail "abcdefg" -4  ;== "abcDEFG"
```


### Tab and newline handling

`detab` expands tabs to spaces (default 4 spaces):

```rebol
detab "^-A"              ;== "    A"
detab/size "^-A" 2       ;== "  A"
```

`entab` converts leading spaces to tabs:

```rebol
entab "    A"            ;== "^-A"
entab/size "    A" 2     ;== "^-^-A"
```

`deline` normalizes line endings to `^/` (LF), optionally splitting into lines:

```rebol
deline "a^M^/b"             ;== "a^/b"
deline/lines "a^M^/b^M^/c"  ;== ["a" "b" "c"]
```

`enline` converts `^/` to the platform line ending:

```rebol
enline "a^/b"      ;; "a^/b" on Unix, "a^M^/b" on Windows
```


### Splitting

`split` divides a string by a delimiter:

```rebol
split "a.b.c" "."               ;== ["a" "b" "c"]
split "a.b.c." "."              ;== ["a" "b" "c" ""]
split "abcdef" 3                ;== ["abc" "def"]
split "abc|de/fgh" charset "|/" ;== ["abc" "de" "fgh"]
split "abc  de" [some #" "]     ;== ["abc" "de"]
split/parts "abcdefgh" 3        ;== ["abc" "def" "gh"]
split/at "a:b:c" #":"           ;== ["a" "b:c"]
```

`split-lines` splits on line endings:

```rebol
split-lines "a^/b^M^/c"         ;== ["a" "b" "c"]
```


### Padding

```rebol
pad "ab" 4          ;== "ab  "
pad "ab" -4         ;== "  ab"
pad/with 12 4 #"0"  ;== "1200"
pad/with 12 -4 #"0" ;== "0012"
```


### Template substitution

`reword` replaces `$key` patterns from a spec:

```rebol
reword "$a and $b" [a "foo" b "bar"]   ;== "foo and bar"
reword/escape "<name>" [name "world"] ["<" ">"]  ;== "world"
reword/case "$a$A" [a 1 A 2]          ;== "12"
```


### Copying

```rebol
copy "abc"                 ; independent copy
copy/part "abcde" 3        ;== "abc"
copy/part tail "abcde" -2  ;== "de"
```


### Display

`form` returns the string as-is (no quotes):

```rebol
form "hello"       ;== "hello"
```

`mold` returns the string with surrounding quotes and escape sequences:

```rebol
mold "hello"       ;== {"hello"}
mold "say ^"hi^""  ;== {{say "hi"}}
```


### Related

Use `string?` and `series?` to test the type:

```rebol
string? "abc"      ;== true
series? "abc"      ;== true
```

`string!` is a member of the `any-string!` and `series!` typesets. Other string-like types (`file!`, `url!`, `email!`, `tag!`, `ref!`) share the same underlying representation and can be coerced with `as`:

```rebol
as file! "hello"   ;== %hello
as tag!  "hello"   ;== <hello>
as url!  "hello"   ;== #(url! "hello")
```


------------------------------------------------------------------
## struct!

A `struct!` is a fixed-layout binary data structure with named, typed fields — similar to a C struct. Fields occupy a contiguous block of memory in a defined order, and the total byte size of a struct is the sum of its field sizes. This makes structs suitable for interfacing with native code, binary protocols, and memory-mapped data.

Structs are available from Rebol version 3.19.1 onwards. The earlier struct implementation used a different syntax and is not covered here.


### Field types

Each field in a struct has an explicit type. The supported types are:

| Type (Alias)           | Size    | Description |
|------------------------|---------|-------------|
| `int8!`   (`i8!`)      | 1 byte  | Signed 8-bit integer |
| `int16!`  (`i16!`)     | 2 bytes | Signed 16-bit integer |
| `int32!`  (`i32!`)     | 4 bytes | Signed 32-bit integer |
| `int64!`  (`i64!`)     | 8 bytes | Signed 64-bit integer |
| `uint8!`  (`u8!`)      | 1 byte  | Unsigned 8-bit integer |
| `uint16!` (`u16!`)     | 2 bytes | Unsigned 16-bit integer |
| `uint32!` (`u32!`)     | 4 bytes | Unsigned 32-bit integer |
| `uint64!` (`u64!`)     | 8 bytes | Unsigned 64-bit integer |
| `float!`  (`f32!`, `float32!`) | 4 bytes | 32-bit floating point |
| `double!` (`f64!`, `float64!`) | 8 bytes | 64-bit floating point |
| `word!`                | 4 bytes | Rebol word value |
| `rebval!`              | platform | Any Rebol value |
| `struct!`              | varies  | Nested struct (see below) |

Uninitialized numeric fields default to `0`, word fields default to `none` (displayed as `_`).


### Construction

#### Basic construction

```rebol
make struct! [a [int8!]]            ;; single int8 field, default 0
make struct! [a [int32!] b [int8!]] ;; two fields
```

#### Default values

The literal `#(struct! ...)` syntax accepts an optional second block that sets the default values for the struct. These defaults are baked into the struct itself and inherited when it is used as a prototype. Named fields and positional values are both supported; unspecified fields default to zero:

```rebol
#(struct! [a [int32!] b [int8!]] [b: 23])  ;; named — b is 23, a defaults to 0
#(struct! [a [int32!] b [int8!]] [23])     ;; positional — a is 23, b defaults to 0
```

Note: evaluation is not permitted inside literal struct syntax — only static values are allowed.

#### Literal syntax

```rebol
s: #(struct! [a [uint8!] b [uint8!]] [a: 1 b: 2])
```

#### From a prototype

Use an existing struct as a prototype. Only the fields you specify are overridden; others keep their prototype values:

```rebol
proto!: #(struct! [a [uint8!] b [uint8!]] [a: 1 b: 2])

s1: make proto! [a: 10]       ;; s1/a = 10, s1/b = 2
s2: make proto! [b: 20]       ;; s2/a = 1,  s2/b = 20
s3: make proto! [b: 20 a: 10] ;; s3/a = 10, s3/b = 20
s4: make proto! [10 20]       ;; s4/a = 10, s4/b = 20
```

The initializer block is evaluated (like `reduce/no-set`), so expressions are allowed:

```rebol
make proto! [3 * 10  4 * 10]       ;; positional
make proto! [b: 3 * 10  a: 4 * 10] ;; named
```

#### Registering a named struct type

Use `register` to associate a name with an existing struct. Before registration, a struct is identified internally by a numeric ID. After registration, that ID is replaced by the given name, which is then usable in the literal construction syntax:

```rebol
; Unregistered — shown with internal numeric ID
proto!: #(struct! [x [f32!] y [f32!]])
probe proto!
;== #(struct! 3695712 [x: 0.0 y: 0.0])

; Register the struct under the name f32-pair
register f32-pair proto!
probe proto!
;== #(struct! f32-pair [x: 0.0 y: 0.0])

; The name can now be used in literal construction syntax
pos: #(struct! f32-pair [100 200])
;== #(struct! f32-pair [x: 100.0 y: 200.0])
```


### Dimensional fields (arrays)

A field can hold a fixed-size array of a type by specifying a dimension in a nested block:

```rebol
make struct! [a [int8! [2]]]   ; field a holds 2 int8 values
```

The total byte size is `element-size * count`:

```rebol
length? make struct! [a [int8!  [2]]]   ;== 2
length? make struct! [a [int32! [2]]]   ;== 8
```

Reading a dimensional numeric field returns a vector:

```rebol
s: #(struct! [a [int32! [2]]])
s/a
;== #(int32! [0 0])
```

Setting a dimensional numeric field uses a vector:

```rebol
s/a: #(i32! [1 2])
s/a
;== #(int32! [1 2])
```

For `word!` dimensional fields, reading returns a block instead:

```rebol
s: make struct! [a [word! [2]]]
s/a
;== [_ _]
```


### Nested structs

A field can itself be a struct, either inline or by referencing a registered type:

```rebol
;; Inline nested struct
s: make struct! [
    id  [uint16!]
    pos [struct! [x [uint8!] y [uint8!]]]
]

;; Using a registered type
register pair8!: make struct! [x [uint8!] y [uint8!]]
s: make struct! [
    id  [uint16!]
    pos [struct! pair8!]
]
```

Access nested fields through chained paths:

```rebol
s/pos/x: 22
s/pos/y: 33
s/pos/x   ;== 22
```

Set an inner struct field from a block, named block, or struct value.

```rebol
s/pos: [1 2]                ;; positional
s/pos: [y: 1 x: 2]          ;; named
s/pos: make pair8! [3 4]    ;; from struct
```

Nested structs can also be arrays:

```rebol
s: make struct! [id [uint16!] pos [struct! pair8! [2]]]
s/pos/1/x: 10
s/pos/2/x: 20
```

Nesting can go arbitrarily deep:

```rebol
s: make struct! [a [uint32!] b [struct! [x [uint32!] y [struct! [yy [uint32!]]]]]]
s/b/x: 1
s/b/y/yy: 2
```


### Binary access

`length?` returns the byte size of the struct:

```rebol
length? make struct! [a [int32!]]           ;== 4
length? make struct! [a [int32!] b [int8!]] ;== 5
```

Convert to binary with `to binary!`:

```rebol
s: #(struct! [a [uint16!] b [int32!]] [1 -1])
to binary! s
;== #{0100FFFFFFFF}
```

Modify the raw binary contents with `change`:

```rebol
s: make pair8! [1 2]

change s [3 4]          ;; positional — #{0304}
change s [y: 3 x: 4]    ;; named — #{0403}
change s #{0101}        ;; raw binary
```

`change` with a binary longer than the struct is silently truncated to the struct size.

Structs containing `rebval!` fields cannot be modified via raw binary — doing so produces a `protected` error. The inner struct data of such fields can still be changed if it contains no `rebval!` fields itself.



### Rebol value fields (`rebval!`)

A `rebval!` field holds any Rebol value:

```rebol
s: make struct! [a [rebval!] b [rebval!]]
s/a: "Hello"
s/b: now
s/a   ;== "Hello"
```

`rebval!` fields hold a reference — modifying the referenced value affects the struct field:

```rebol
s/a: str: "Hello"
clear s/a
str   ;== ""   ;; the original string is modified
```

Clear a `rebval!` field by clearing the struct:

```rebol
clear s
s/a   ;== none
```



### Reflection

```rebol
s: #(struct! [a [uint16!] b [int32!] c [word!] d [uint8! [2]]] [a: 1 b: -1 c: foo])

spec-of s     ;== [a [uint16!] b [int32!] c [word!] d [uint8! [2]]]
body-of s     ;== [a: 1 b: -1 c: foo d: [0 0]]
words-of s    ;== [a b c d]
keys-of s     ;== [a b c d]
values-of s   ;== [1 -1 foo [0 0]]
```



### Copying

`copy` produces an independent copy of the struct:

```rebol
s: make pair8! [1 2]
s2: copy s
s/x: 3
s2/x   ;== 1   ; s2 is unaffected
```

`copy/part` and `copy/deep` are not supported on structs.



### Comparison

`=` compares field types only (field names are ignored):

```rebol
s1: #(struct! [a [uint8!] b [uint8!]])
s2: #(struct! [x [uint8!] y [uint8!]])
s1 = s2    ;== true   ; same field types
```

`==` (strict-equal?) also compares field names:

```rebol
s1 == s2   ;== false  ; different field names
```



### Related

Use `struct?` to test whether a value is a `struct!`:

```rebol
struct? #(struct! [a [int8!]])   ;== true
struct? #[a: 1]                  ;== false
```

Invalid construction raises a `malconstruct` or `invalid-arg` error. An empty struct is not allowed:

```rebol
make struct! []          ; ** Error: malconstruct
make struct! [a]         ; ** Error: malconstruct  (no field spec)
make struct! [a [23]]    ; ** Error: invalid-arg   (invalid type)
```


------------------------------------------------------------------
## tag!


Tags are used in HTML and other markup languages to indicate how text fields are to be treated. For example, the tag `<HTML>` at the beginning of a file indicates that it should be parsed by the rules of the Hypertext Markup Language. A tag with a forward slash `/`, such as `</HTML>`, indicates the closing of the tag.

Tags are a subset of series, and thus can be manipulated as such:

```rebol
a-tag: <img src="mypic.jpg">
probe a-tag
<img src="mypic.jpg">

append a-tag { alt="My Picture!"}
probe a-tag
<img src="mypic.jpg" alt="My Picture!">
```



### Format
Valid tags begin with an open angle bracket (<) and end with
a closing bracket (>). For example:


```rebol
<a href="index.html">
<img src="mypic.jpg" width="150" height="200">
```


### Creation
The `to-tag` function converts data to the `tag!` datatype:


```rebol
probe to-tag "title"
<title>
```

### Related
Use `tag?` to determine whether a value is an `tag!` datatype.

```rebol
probe tag? <a href="http://www.rebol.com/">
true
```

As tags are a subset of the series pseudotype, use `series?` to check this:

```rebol
probe series? <a href="http://www.rebol.com/">
true
```

The `form` function returns a tag as a string:

```rebol
probe form <a href="http://www.rebol.com/">
{<a href="http://www.rebol.com/">}
```

The `mold` function returns a tag as a string:

```rebol
probe mold <a href="http://www.rebol.com/">
{<a href="http://www.rebol.com/">}
```

The `print` function prints a tag to standard output after doing a `reform` on it:

```rebol
print <a href="http://www.rebol.com/">
<a href="http://www.rebol.com/">
```



------------------------------------------------------------------
## task!


evaluation environment (not yet implemented!)


------------------------------------------------------------------
## time!


The Rebol language supports the standard expression of time in hours, minutes, seconds, and subseconds. Both positive and negative times are permitted.

The `time!` datatype uses relative rather than absolute time. For example, `10:30` is 10 hours and 30 minutes rather than the time of 10:30 A.M. or P.M.



### Format
Times are expressed as a set of integers separated by colons `:`. Hours and minutes are required, but seconds are optional. Within each field, leading zeros are ignored:


```rebol
10:30
0:00
18:59
23:59:50
8:6:20
8:6:2
```

The minutes and seconds fields can contain values greater than 60. Values greater than 60 are automatically converted. For instance `0:120:00` is the same as `2:00`.


```rebol
probe 00:120:00
2:00
```

Subseconds are specified using a decimal in the seconds field. Use either a period or a comma as the decimal point. The hours and minutes fields become optional when the decimal is present. Subseconds are encoded to the nano-second, or one billionth (- US, one milliardth - GB) of a second:


```rebol
probe 32:59:29.5
32:59:29.5

probe 1:10,25
0:01:10.25

probe 0:0.000000001
0:00:00.000000001

probe 0:325.2
0:05:25.2
```

Times are output in a standard hours, minutes, seconds, and subseconds format, regardless of how they are entered:


```rebol
probe 0:87363.21
24:16:03.21
```



### Access
Time values have three refinements that can be used to return specific information about the value:

| Refinement | Description
| `/hour`   | Gets the value's hour.
| `/minute` | Gets the value's minute.
| `/second` | Gets the value's second.

Here's how to use a time value's refinements:

```rebol
lapsed-time: 91:32:12.14
probe lapsed-time/hour
91

probe lapsed-time/minute
32

probe lapsed-time/second
12.14
```

Times with time zones can only be used with the `date!`.


### Creation
Times can be converted using the `to-time` function:

```rebol
probe to-time "10:30"
10:30

probe to-time [10 30]
10:30

probe to-time [0 10 30]
0:10:30

probe to-time [10 30 20.5]
10:30:20.5
```

In the previous examples, the values are not evaluated. To evaluate values as mathematical expressions, use the reduce function:

```rebol
probe to-time reduce [10 30 + 5]
10:35
```

In various math operations involving time values, the time values, integers, or decimals are converted as shown below:

```rebol
probe 10:30 + 1
10:30:01

probe 10:00 - 10
9:59:50

probe 0:00 - 10
-0:00:10

probe 5:10 * 3
15:30

probe 0:0:0.000000001 * 1'500'600
0:00:00.0015006

probe 8:40:20 / 4
2:10:05

probe 8:40:20 / 2:20:05
3

probe 8:40:20 // 4:20
0:00:20
```



### Related
Use `time?` to determine whether a value is a `time!`  datatype:


```rebol
probe time? 10:30
true

probe time? 10.30
false
```

Use the `now` function with the `/time` refinement to return the current local date and time:


```rebol
print now/time
14:42:15
```

Use the `wait` function to wait for a duration, port, or both.

If a value is a `time!` datatype, `wait` delays for that period of time. If a value is a `date!`/`time!`, `wait` waits until the indicated date and time. If the value is an `integer!` or `decimal!`, the function waits the indicated number of seconds. If the value is a `port!`, the function will wait for an event from that port. If a block is specified, it will wait for any of the times or ports to occur. It returns the port that caused the wait to complete or returns `none!` if the timeout occurred. For example,


```rebol
probe now/time
14:42:16

wait 0:00:10
probe now/time
14:42:26
```



------------------------------------------------------------------
## tuple!

A `tuple!` is a sequence of integers separated by periods. Tuples are commonly used to represent version numbers, network addresses, and RGB color values.

```rebol
1.3.0              ; version
199.4.80.250       ; IPv4 address
255.255.255.0      ; network mask
0.80.255           ; RGB color
1.2.3.4.5.6.7.8.9.10.11.12  ; up to 12 elements
```

`tuple!` is a member of the `scalar!` and `immediate!` typesets.


### Format

A tuple requires at least two periods (minimum three elements). Two numbers separated by a single period are a `decimal!`, not a `tuple!`:

```rebol
1.2      ;== decimal!
1.2.3    ;== tuple!
1.2.     ;== 1.2.0  (tuple — trailing period adds a zero)
```

Each element can range from 0 to 255. Values outside this range are clipped to 0 or 255 during assignment:

```rebol
t: 1.2.3
t/1: 300     ; clipped to 255
t/2: -10     ; clipped to 0
t            ;== 255.0.3
```

A tuple can have between 3 and 12 elements:

```rebol
load "1.2.3.4.5.6.7.8.9.10.11.12"    ; valid — 12 elements
load "1.2.3.4.5.6.7.8.9.10.11.12.13" ; error — too long
```


### Construction

Write tuples as literals, or convert from other types with `to-tuple` / `to tuple!`:

```rebol
to-tuple "1.2.3"           ;== 1.2.3
to-tuple [1 2 3]           ;== 1.2.3
to-tuple "1"               ;== 1.0.0   ; extended to minimum 3 elements
to-tuple "1.2"             ;== 1.2.0

to-tuple #{010203}         ;== 1.2.3
to-tuple #010203           ;== 1.2.3   ; from issue!

;; decimal values in blocks are truncated to integer:
to-tuple [0.5 25.4 200.01] ;== 1.25.200
```

Converting back to the same type is a no-op:

```rebol
to-tuple 1.1.1             ;== 1.1.1
```


### Accessing and setting elements

Elements are accessed by 1-based integer index:

```rebol
t: 1.2.3.4
t/1    ;== 1
t/2    ;== 2
t/4    ;== 4
t/5    ;== none   ; out of range returns none
```

Set elements via path. Setting a position beyond the current length extends the tuple with zeros:

```rebol
t: 1.2.3
t/5: 5
t         ;== 1.2.3.0.5

t/12: 12  ;; extends up to the maximum
```

Set an element to `none` to shorten the tuple:

```rebol
t: 1.2.3.4
t/4: none
t       ;== 1.2.3
```

Note: `poke` is not supported on tuples — use path assignment instead.


### Math operations

Arithmetic operates element-wise. Values are clipped to 0–255:

```rebol
0.0.128 * 2           ;== 0.0.255     ; clipped at 255
128.128.128 + 0.255.0 ;== 128.255.128

1.1.1 / 0.1           ;== 10.10.10
1.1.1 * 2147483648.0  ;== 255.255.255 ; large values clip at 255
```

#### Bitwise operations

`or`, `and`, and `xor` operate on tuples with integers. Float arguments are not supported:

```rebol
1.2.3.4 or  1    ;== 1.3.3.5
1.2.3.4 and 1    ;== 1.0.1.0
1.2.3.4 xor 1    ;== 0.3.2.5
```

#### Complement

`complement` inverts each byte (equivalent to XOR with 255):

```rebol
complement 1.0.0 ;== 254.255.255
```

#### Power

`**` (power) is not supported on tuples and produces an error.


### Equality

`=` and `equiv?` treat a tuple and the same tuple with trailing zeros as equal. `==` (strict-equal?) and `same?` do not:

```rebol
equal?        1.2.3 1.2.3.0   ;== true
equiv?        1.2.3 1.2.3.0   ;== true
strict-equal? 1.2.3 1.2.3.0   ;== false
same?         1.2.3 1.2.3.0   ;== false
```


### Reversing

`reverse` reverses the elements of the tuple in place:

```rebol
reverse 1.2.3       ;== 3.2.1
reverse 1.2.3.4.5   ;== 5.4.3.2.1
```

`reverse/part` reverses only the first N elements:

```rebol
reverse/part 1.2.3.4.5 3   ;== 3.2.1.4.5
```


### Interpolation

`lerp` linearly interpolates between two tuples. Accepts a decimal or percent in the range 0.0–1.0 (100%). Values outside the range are clamped:

```rebol
lerp 10.100.255 255.128.64 0.0    ;== 10.100.255
lerp 10.100.255 255.128.64 0.3    ;== 83.108.197
lerp 10.100.255 255.128.64 1.0    ;== 255.128.64
lerp 10.100.255 255.128.64 30%    ;== 83.108.197
lerp 10.100.255 255.128.64 200%   ;== 255.128.64  ; clamped
```


### Related

Use `tuple?` to test whether a value is a `tuple!`:

```rebol
tuple? 1.2.3.4  ;== true
tuple? "1.2.3"  ;== false
```

`form` and `mold` both produce the dot-separated string representation:

```rebol
form 1.2.3.4    ;== "1.2.3.4"
mold 1.2.3.4    ;== "1.2.3.4"
```



------------------------------------------------------------------
## typeset!

### Concept

A `typeset!` is an efficient set of datatypes. Typesets are used throughout Rebol to specify what types a function argument accepts, and to group related types for testing. Internally a typeset is represented as a bitset of datatype flags, making membership tests very fast.

To list all built-in typesets and their members:

```code
help typeset!
```

### Construction

```rebol
make typeset! [block! map! object!]
```

Duplicate entries are allowed and silently ignored — a typeset is a set, so each type appears at most once:

```rebol
make typeset! [number! integer!]   ; integer! is already part of number!, no error
```

An empty typeset is valid:

```rebol
make typeset! []
```

Convert a typeset to a block of its member datatypes with `to-block`:

```rebol
to-block make typeset! [block! map!]
;== [block! map!]
```


### Testing membership

Use `find` to test whether a datatype is a member of a typeset:

```rebol
types: make typeset! [block! map! object!]

find types block!    ;== true
find types string!   ;== none
```

Use `empty?` to test whether a typeset has no members:

```rebol
empty? make typeset! []   ;== true
empty? types              ;== false
```


### Set operations

Typesets support the standard set operations, each returning a new `typeset!`:

```rebol
types: make typeset! [block! map! object!]

;; union — all types from both typesets
union types make typeset! [string!]
;== make typeset! [block! map! object! string!]

;; difference — types in one but not both (symmetric)
difference types make typeset! [object!]
;== make typeset! [block! map!]

;; complement — all types NOT in the typeset
not-types: complement types
find not-types integer!
;== true (integer! is not in types)
```


### Built-in typesets

Rebol defines a number of built-in typesets. Some notable ones:

`any-type!` covers all datatypes except `end!`, which is an internal sentinel:

```code
; end! is the only type not in any-type!
probe difference system/catalog/datatypes to-block any-type!
```

`scalar!` covers the primitive numeric and value types:

```code
probe to-block scalar!
```

`immediate!` covers all types whose values are not reference types (no allocation):

```code
probe to-block immediate!
```

`series!` covers all series types.

```code
probe to-block series!
```
Note that `bitset!` is not a series despite superficial similarity:
```rebol
find series! bitset!   ;== none
```


### Use in function specs

Typesets appear in function argument specs to restrict what types are accepted. Use `types-of` to retrieve the typeset for a specific argument:

```rebol
mold third types-of :insert
;== "make typeset! [none! logic!]"
```


### Related

Use `typeset?` to test whether a value is a `typeset!`:

```rebol
typeset? make typeset! [block!]   ;== true
typeset? block!                   ;== false
```


------------------------------------------------------------------
## unset!

`unset!` is the datatype of a word that has no value assigned to it. Accessing an unset word in a context where a value is expected produces an error. It is distinct from `none!` — `none` is an explicit value meaning "nothing", whereas `unset!` means the word has never been assigned at all.

```rebol
type? #(unset)
;== #(unset!)
```

### Creating unset words

Use `unset` to remove the value of a word:

```rebol
x: 42
unset 'x
value? 'x          ;== #(false)
```

Pass a block to unset multiple words at once:

```rebol
x: y: 1
unset [x y]
unset? x           ;== #(true)
unset? y           ;== #(true)
```

To unset all values in an object:

```rebol
o: make object! [x: 1 y: 2]
unset? o/x         ;== #(false)
value? in o 'x     ;== #(true)
unset in o words-of o
unset? o/x         ;== #(true)
value? in o 'x     ;== #(false)
```

Functions that produce no meaningful return value typically return `unset!`:

```rebol
type? print "hello"
; hello
;== #(unset!)
```

An empty paren expression also produces an unset value:

```rebol
type? ()
;== #(unset!)
```

Use `set/any` to set a word to an unset value:

```rebol
set 'x ()          ;** Script error: x needs a value
set/any 'x ()
value? 'x          ;== #(false)
```

### Testing

Use `unset?` to test whether a value is of type `unset!`:

```rebol
unset? ()          ;== true
unset? #(unset)    ;== true
unset? none        ;== false
```

Use `value?` to test whether a word has been assigned:

```rebol
x: 42
unset 'x
value? 'x          ;== #(false)

x: 42
value? 'x          ;== #(true)
```

Note that `get` on an unset word produces an error. Use `get/any` to retrieve the value safely:

```rebol
unset 'x
get 'x             ;** Script error: x has no value
get/any 'x         ;== #(unset)
```


------------------------------------------------------------------
## url!

A `url!` value represents a Uniform Resource Locator — an address used to identify a resource on a network or filesystem. URLs are a member of the `any-string!` and `series!` typesets, so all series operations apply.

```rebol
http://www.rebol.com/index.html
ftp://files.example.com/pub/data.zip
mailto:user@example.com
```


### Format

A URL begins with a scheme name followed by a colon, then scheme-specific content. Common schemes:

```rebol
http://host.dom/path/file
ftp://host.dom/path/file
ftp://user:password@host.dom/path/file
nntp://news.some-isp.net/some.news.group
mailto:name@domain
file://host/path/file
finger://user@host.dom
whois://rebol@rs.internic.net
daytime://everest.cclabs.missouri.edu
pop://user:passwd@host.dom/
tcp://host.dom:21
dns://host.dom
```

Restricted characters in URLs must be percent-encoded. `print` decodes them for display while `probe` shows the raw encoded form:

```rebol
probe http://www.somesite.dom/odd%28dir%29/odd%7Bfile%7D.txt
; http://www.somesite.dom/odd%28dir%29/odd%7Bfile%7D.txt

print http://www.somesite.dom/odd%28dir%29/odd%7Bfile%7D.txt
; http://www.somesite.dom/odd(dir)/odd{file}.txt
```

Use `enhex` and `dehex` to encode and decode percent-encoding:

```rebol
enhex as url! "http://example.com/path?q=hello world"
dehex http://example.com/path?q=hello%20world
```


### Construction

Write URL literals directly, or use `to-url` with a block. The first element is the scheme, the second is the host (optionally with `user:pass@` and port), and the remaining elements form the path:

```rebol
to-url [http www.rebol.com reboldoc.html]
;== http://www.rebol.com/reboldoc.html

to-url [http www.rebol.com %examples "websend.r"]
;== http://www.rebol.com/examples/websend.r
```

Use `as url!` or `as` to coerce a string to a URL without copying:

```rebol
as url! "http://example.com"   ;== http://example.com
```


### Series operations

Since `url!` is a series, standard operations apply:

```rebol
url: http://www.rebol.com/reboldoc.html

find url "rebol"               ;== "rebol.com/reboldoc.html"
find/reverse tail url "rebol"  ;== "reboldoc.html"
to-file find/reverse tail url "rebol"  ;== %reboldoc.html

length? http://www.rebol.com   ;== 19
```


### Related

Use `url?` to test whether a value is a `url!`:

```rebol
url? http://www.rebol.com    ;== true
url? "http://www.rebol.com"  ;== false
```

`url!` is a member of the `any-string!` and `series!` typesets:

```rebol
series? http://www.rebol.com      ;== true
any-string? http://www.rebol.com  ;== true
```

Use `as` to coerce between `any-string!` types without copying:

```rebol
as string! http://www.rebol.com   ;== "http://www.rebol.com"
as file!   http://www.rebol.com   ;== %http://www.rebol.com
```

------------------------------------------------------------------
## utype!


user defined datatype



------------------------------------------------------------------
## vector!


A `vector!` is a fixed-type series of numeric or word values stored in a compact binary form. Unlike a block, all elements must be of the same type, and that type is declared at construction time. This makes vectors memory-efficient and suitable for numeric computation, binary data manipulation, and interfacing with native code.

Vectors are series and support the full range of series operations: `next`, `skip`, `head`, `tail`, `copy`, `append`, `insert`, `change`, `clear`, `reverse`, `sort`, and so on. Math operations apply element-wise to the entire vector.


### Element types

Each vector has a declared element type. Short aliases are accepted in construction and canonical long names are used in output:

| Short  | Canonical  | Size    | Description             |
|--------|------------|---------|-------------------------|
| `i8!`  | `int8!`    | 1 byte  | Signed 8-bit integer    |
| `i16!` | `int16!`   | 2 bytes | Signed 16-bit integer   |
| `i32!` | `int32!`   | 4 bytes | Signed 32-bit integer   |
| `i64!` | `int64!`   | 8 bytes | Signed 64-bit integer   |
| `u8!`  | `uint8!`   | 1 byte  | Unsigned 8-bit integer  |
| `u16!` | `uint16!`  | 2 bytes | Unsigned 16-bit integer |
| `u32!` | `uint32!`  | 4 bytes | Unsigned 32-bit integer |
| `u64!` | `uint64!`  | 8 bytes | Unsigned 64-bit integer |
| `f32!` | `float32!` | 4 bytes | 32-bit floating point   |
| `f64!` | `float64!` | 8 bytes | 64-bit floating point   |

Additional aliases accepted in construction: `byte!` (= `uint8!`), `float!` (= `float32!`), `double!` (= `float64!`).

Signed vs. unsigned can also be specified explicitly with `signed` / `unsigned` words in the full construction form.


### Construction

#### Literal syntax

The most concise form uses the `#(type! [...])` literal syntax:

```rebol
#(i8!  [1 2 3])      ;== #(int8!  [1 2 3])
#(u16! [1 2 3])      ;== #(uint16! [1 2 3])
#(f32! [1 2 3])      ;== #(float32! [1.0 2.0 3.0])
#(u8!  [])           ;; empty vector
```

An optional trailing integer sets the initial index:

```rebol
v: #(i16! [1 2 3] 2)
index? v             ;== 2
mold v               ;== "#(int16! [2 3])"
```

#### Semi-compact construction with `make`

```rebol
make vector! [i8!]           ;; empty int8 vector
make vector! [i8!  3]        ;; 3 zero-initialized elements
make vector! [i8!  [1 2 3]]  ;; from block
make vector! [f32! [1 2 3]]  ;== #(float32! [1.0 2.0 3.0])
```

With an index:

```rebol
v: make vector! [i16! [1 2 3] 2]
index? v   ;== 2
```

#### Full construction form

```rebol
make vector! [integer! 32 [1 2 3 4]]    ;; signed 32-bit
make vector! [signed   integer! 32 [1 2 3 4]]
make vector! [unsigned integer! 32 [1 2 3 4]]

;; with size limit — crops or extends with zeros:
make vector! [integer! 16 2 [1 2 3 4]]  ;; length 2: [1 2]
make vector! [integer! 16 4 [1 2]]      ;; length 4: [1 2 0 0]
```

#### From binary data

```rebol
to vector! #{01FF}                            ;== #(uint8! [1 255])
make vector! [integer! 16 #{010002000300}]    ;== #(int16! [1 2 3])

b: to binary! #(f32! [1.0 -1.0])
make vector! compose [decimal! 32 (b)]        ;; round-trips through binary
```

#### Using get-words in the spec

Variables can be referenced in the construction block using get-words:

```rebol
data:  [1 2 3 4]
size:  2
index: 3

make vector! [uint8! :data]           ;== #(uint8! [1 2 3 4])
make vector! [uint8! :size :data]     ;== #(uint8! [1 2])
make vector! [uint8! :data :index]    ;== #(uint8! [3 4])
```

#### Type inference

When no type is specified, the type is inferred from the values:

```rebol
make vector! [1 2 3 4]       ;== #(int64! [1 2 3 4])
make vector! [1.0 2]         ;== #(float64! [1.0 2.0])
```

An empty block or zero size defaults to `int32!`:

```rebol
make vector! []    ;== #(int32! [])
make vector! 0     ;== #(int32! [])
```

Note: `to vector! []` is an error.


### Accessing elements

Vectors use 1-based indexing, consistent with other Rebol series:

```rebol
v: #(u32! [1 2 3])

v/1          ;== 1
first v      ;== 1
last v       ;== 3
pick v 2     ;== 2
pick v 0     ;== none
pick v 10    ;== none
```

Use `poke` to set a value by index:

```rebol
poke v 1 10
v/1          ;== 10
```

Poking out of range produces an error:

```rebol
poke v 10 1  ;** out-of-range error
```


### Series operations

Vectors support the standard series navigation and modification operations:

```rebol
v: #(u8! [1 2 3])

next v            ;== #(uint8! [2 3])
head v            ;== #(uint8! [1 2 3])
tail v            ;== #(uint8! [])
tail? tail v      ;== true
head? head v      ;== true
length? v         ;== 3
index? next v     ;== 2
```

`append`, `insert`, and `change` accept numbers, blocks, vectors, or binary data. Values are converted to the vector's element type:

```rebol
append #(i8! [1 2]) 3            ;== #(int8! [1 2 3])
append #(i8! [1 2]) [3 4]        ;== #(int8! [1 2 3 4])
append #(i8! [1 2]) #(i8! [3 4]) ;== #(int8! [1 2 3 4])
append #(i8! [1 2]) #{0304}      ;== #(int8! [1 2 3 4])

insert v: #(i8! [1 2]) 3
v   ;== #(int8! [3 1 2])

change v: #(i8! [1 2]) 9
v   ;== #(int8! [9 2])
```

When appending binary to an integer vector, the binary size must be a multiple of the element byte size:

```rebol
append #(i16! [1 2]) #{03}     ;** invalid-data error — odd byte count for 16-bit vector
```

`clear` empties the vector in place:

```rebol
v: #(i8! [1 2])
clear v
v   ;== #(int8! [])
```


### Copying

Assignment does not copy — both variables refer to the same vector:

```rebol
v1: #(u16! [1 2])
v2: v1
v2/1: 3
v1/1   ;== 3   ; v1 is also modified
```

Use `copy` to make an independent copy:

```rebol
v3: copy v1
v1/1: 9
v3/1   ;== 3   ; v3 is unaffected
```

`copy/part` copies a subset:

```rebol
v: #(u16! [1 2 3 4])
copy/part v 2               ;== #(uint16! [1 2])
copy/part skip v 2 2        ;== #(uint16! [3 4])
```


### Conversion

```rebol
to binary! #(u16! [1 2])           ;== #{01000200}
to binary! #(i32! [1 2])           ;== #{0100000002000000}
to binary! #(f32! [1.0 2.0])       ;== #{0000803F00000040}

;; binary reflects current position, not head:
to binary! next #(u16! [1 2])      ;== #{0200}

to-block #(u16! [1 2])             ;== [1 2]
to-block make vector! 0            ;== []
```

`mold` and `load` round-trip correctly:

```rebol
v: #(i32! [1 2 3])
v = load mold v    ;== true
```


### Sorting

`sort` modifies the vector in place and operates from the current position:

```rebol
sort #(i32! [2 4 1 3])                ;== #(int32! [1 2 3 4])
sort/reverse #(i32! [2 4 1 3])        ;== #(int32! [4 3 2 1])
sort/part #(i32! [2 4 1 3]) 3         ;== #(int32! [1 2 4 3])

;; sort from next position — head element is unaffected:
head sort next #(i32! [2 4 1 3])      ;== #(int32! [2 1 3 4])
```

`sort/skip` and `sort/compare` are not supported on vectors.


### Reversing

`reverse` modifies the vector in place:

```rebol
reverse #(u8! [1 2 3])               ;== #(uint8! [3 2 1])
reverse/part #(u8! [1 2 3]) 2        ;== #(uint8! [2 1 3])
head reverse next #(u8! [1 2 3])     ;== #(uint8! [1 3 2])
```


### Random shuffle

`random` shuffles the vector in place and returns the same vector:

```rebol
v: #(i32! [1 2 3 4 5])
same? v random v    ;== true
```


### Math operations

Arithmetic operations apply element-wise and return a new vector of the same type. The scalar can appear on either side:

```rebol
#(u8! [1 2 3 4]) + 200     ;== #(uint8! [201 202 203 204])
1 + #(u8! [1 2 3 4])       ;== #(uint8! [2 3 4 5])
#(u8! [4 8 12]) / 4        ;== #(uint8! [1 2 3])
#(f64! [1 2 3]) * 0.5      ;== #(float64! [0.5 1.0 1.5])
```

Integer overflow wraps (truncates to the element's bit width):

```rebol
#(u8! [200]) + 200         ;== #(uint8! [144])   ((200+200) mod 256)
```

Float scalars are converted to integer when operating on integer vectors:

```rebol
#(i8! [1 2 3]) * 2.4       ;== #(int8! [2 4 6])  (2.4 truncated to 2)
```

Operations between two vectors use matching elements up to the length of the shorter one:

```rebol
#(i8! [1 2]) + #(i8! [3 4])     ;== #(int8! [4 6])
#(i16! [1 2]) + #(i16! [3 4 5]) ;== #(int16! [4 6])  (only 2 elements)
```

Division by zero produces an error. Reverse division (`scalar / vector`) is not supported:

```rebol
#(u16! [1 2]) / 0    ;** zero-divide error
10 / #(u16! [1 2])   ;** error
```

#### Bitwise operations

`or`, `and`, `xor` are supported on integer vectors only. Applying them to float vectors produces a `not-related` error:

```rebol
#(i32! [1 2 3 4]) or  2   ;== #(int32! [3 2 3 6])
#(i32! [1 2 3 4]) and 10  ;== #(int32! [0 2 2 0])
#(i32! [1 2 3 4]) xor 2   ;== #(int32! [3 0 1 6])

;; vector or vector:
#(i32! [1 2 3 4]) or #(i32! [5 6 7 8])   ;== #(int32! [5 6 7 12])
```

#### Remainder

`%` is supported on all vector types including floats:

```rebol
#(i32! [1 2 3 4]) % 2        ;== #(int32! [1 0 1 0])
#(f64! [1 2 3 4]) % 2        ;== #(float64! [1.0 0.0 1.0 0.0])
#(i32! [1 2]) % 0            ;** zero-divide error
```

#### Operating on a sub-range

Math operations respect the current position — use `skip` to operate on a sub-range:

```rebol
2 + skip #(i8! [1 2 3 4]) 2   ;== #(int8! [5 6])
```

The original vector is not modified.


### Finding minimum and maximum

Access `min`/`max` (or `minimum`/`maximum`) via path:

```rebol
v: #(i8! [1 -2 0])
v/min    ;== -2
v/max    ;== 1
```

Returns `none` for an empty vector.

Use `find-min` and `find-max` to get a position (like `find`):

```rebol
v: #(i32! [1 2 3 -1])
first find-max v   ;== 3
first find-min v   ;== -1
```


### Statistics

The following statistical fields are available: `minimum`, `maximum`, `range`, `sum`, `mean`, `median`, `variance`, `population-deviation`, `sample-deviation`. Each can be accessed as a path accessor or queried with `query`:

```rebol
v: make vector! [1 20 2 10]

v/variance              ;== 232.75
v/mean                  ;== 8.25
v/sum                   ;== 33
```

`query` retrieves multiple fields at once:

```rebol
v: #(int8! [-2 -1 1 2 4])

query v [minimum maximum range sum mean median variance population-deviation sample-deviation]
;== [minimum: -2 maximum: 4 range: 6 sum: 4 mean: 0.8 median: 1.0 variance: 22.8 ...]

;; get-word form returns values without labels:
query v [:minimum :maximum :sum]
;== [-2 4 4]

;; single field:
query v 'sum   ;== 4
```


### Reflection

```rebol
v: make vector! [unsigned integer! 16 2]

spec-of v          ;== [unsigned integer! 16 2]
reflect v 'type    ;== integer!
reflect v 'size    ;== 16
reflect v 'length  ;== 2
reflect v 'signed  ;== false

;; same via accessors:
v/type     ;== integer!
v/size     ;== 16
v/length   ;== 2
v/signed   ;== false

;; also available via query:
query v 'size    ;== 16
size? v          ;== 16
```


### Comparison

Vectors are compared element by element. Length matters — a shorter vector is less than a longer one with the same prefix:

```rebol
#(u16! [1 2]) =  #(u16! [1 2])     ;== true
#(u16! [1 2]) <  #(u16! [1 2 0])   ;== true
#(u16! [1 2]) <  #(u16! [2 2])     ;== true
#(u16! [2 2]) >  #(u16! [1 2])     ;== true
```


### Related

Use `vector?` to test whether a value is a `vector!`:

```rebol
vector? #(u8! [1 2])   ;== true
vector? [1 2]          ;== false
```




------------------------------------------------------------------
## word!


Words are the symbols used by Rebol. A word may or may not be a variable, depending on how it is used. Words are quite often used directly as symbols, rather than variables. It is important to understand the difference.

Rebol does not use keywords — those specific words that can only be used in one way.

For example, in C code, an `if` statement may be written:

```c
if (n > 1) n = 0;
```

The word `if` is a keyword. You cannot use it in any other way or for any other purpose.

In Rebol, words are symbols defined within dynamically created contexts. There are no restrictions on what words are used or how they are used.

For example, the word `if` is used several ways here:

```rebol
if n > 1 [n: 0]

words: [if while loop until]

help if

obj: object [
    if: 12
    fi: 21
    print if
]
```

So, the context defines the word's value and its usage.



### Notation
There are a few different formats for words, depending on their intended usage:

| Notation | Meaning |
|----------|---------|
| `word`   | Get the **natural value** of the word. (If the value is a function, evaluate it, otherwise return it.) |
| `word:`  | Sets the word (like assignment) to a value. |
| `:word`  | Gets the word's value without evaluating it. (Useful for getting the value of a function.) |
| `'word`  | Treat word as a value (a word symbol). Does not evaluate it. |
| `/word`  | Treat the word as a refinement. Used mainly for optional arguments. |


### Word types

| Action  | Type Word   | Type Test   | Conversion    |
|---------|-------------|-------------|---------------|
| `word:` | `set-word!` | `set-word?` | `to-set-word` |
| `:word` | `get-word!` | `get-word?` | `to-get-word` |
| `word`  | `word!`     | `word?`     | `to-word`     |
| `'word` | `lit-word!` | `lit-word?` | `to-lit-word` |


### Syntax
Words are composed of alphabetic characters, numbers, and any of the following characters:

```
? ! . ' + - * & | = _ ~
```

A word cannot begin with a number, and there are also some restrictions on words that could be interpreted as numbers. For instance, `-1` and `+1` are numbers, not words.

The end of a word is marked by a space, a newline, or one of the following characters:

```
[ ] ( ) { } " : ; /
```

Thus, the square brackets of a block are not part of a word:

```rebol
[test]
```

The following characters are not allowed in words:

```
@ # $ % ^ ,
```

Words can be of any length, but cannot extend past the end of a line.

```rebol
this-is-a-very-long-word-used-as-an-example
```

Sample words are:

```rebol
Copy print test

number?  time?  date!

image-files  l'image

++ -- == +-

***** *new-line*

left&right left|right
```

The Rebol language is not case-sensitive. The following words:

```rebol
blue
Blue
BLUE
```

all refer to the same word. The case of the word is preserved when it is printed.

Words can be reused. The meaning of a word is dependent on its context, so words can be reused in different contexts. You can reuse any word, even predefined Rebol words. For instance, the Rebol word `if` can be used in your code differently than how it is used by the Rebol interpreter.



### Creation
The `to-word` function converts values to the `word!` datatype.

```rebol
to-word "test"     ;== test
```

The `to-set-word` function converts values to the `set-word!` datatype.

```rebol
to-set-word "test" ;== test:
```

The `to-get-word` function converts values to the `get-word!` datatype.

```rebol
to-get-word "test" ;== :test
```

The `to-lit-word` function converts values to the `lit-word!` datatype.

```rebol
to-lit-word "test" ;== 'test
```

> **Note:**
> The `to-*` conversion functions are convenience wrappers around their `to <type>!` equivalents:
> ```rebol
> to-word "test"   ;== test
> to word! "test"  ;== test
> ```
> When performance is critical, prefer the `to <type>!` form as it avoids the overhead of the wrapper function.



### Related
Use `word?`, `set-word?`, `get-word?`, and `lit-word?` to test the datatype.

```rebol
word? second [1 two "3"]
;== #(true)

if set-word? first [word: 10] ["it is set"]
;== "it is set"

get-word? second [pr: :print]
;== #(true)

lit-word? first ['foo bar]
;== #(true)
```


------------------------------------------------------------------
