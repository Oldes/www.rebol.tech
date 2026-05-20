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

Spaces, tabs and newlines are permitted within the string. Binary data can span multiple lines.
```rebol
probe #{
    3A
    18
    92
    56
}
#{3A189256}
```

Strings should contain the correct number of characters to create a binary result which is an integral number of bytes (integral multiple of 8 bits).

### Creation
The `to-binary` function converts data to the `binary!` datatype at the default base set in `system/options/binary-base`:
```rebol
probe to-binary "123"
#{313233}

probe to-binary "today is the day..."
#{746F64617920697320746865206461792E2E2E}
```

To convert an integer into its binary value, pass it in a block:
```rebol
probe to-binary [1]
#{01}

probe to-binary [11]
#{0B}
```

Converting a series of integers into a binary, returns the bit conversion for each integer concatenated into a single binary value:
```rebol
probe to-binary [1 1 1 1]
#{01010101}
```


### Related
Use `binary?` determine whether a value is an `binary!`  datatype.


```rebol
probe binary? #{616263}
true
```

Binary values are a type of series:


```rebol
probe series? #{616263}
true

probe length? #{616263} ; three hex values in this binary
3
```

Closely related to working with `binary!` datatypes are the functions `enbase` and `debase`. The `enbase` function converts strings to their base-2, base-16 or base-64 representations as strings. The `debase` function converts enbased strings to a binary value of the base specified in system/options/binary-base`.



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
</ul>

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



Characters are not strings; they are the individual values from which strings are constructed. A character can be printable, unprintable, or a control symbol.


### Format

A `char!` value is written as a number sign (#) followed by a string enclosed in double quotes. The number sign is necessary to distinguish a character from a string:
```rebol
#"R"    ; the single character: R
"R"     ; a string with the character: R
```

Characters can include escape sequences that begin with a caret `^` and are followed by one or more characters of encoding. This encoding can include the characters `#"^A"` to `#"^Z"` for `CTRL+A` to `CTRL+Z` (upper and lower case are the same):
```rebol
#"^A" #"^Z"
```

In addition, if parens are used within the character, they specify
a special value. For example, null can be written as:
```rebol
"^@"
"^(null)"
"^(00)"
```

The last line is written in hex format (base 16). Up to 4 hex digits can be provided, to cover all 16 bit Unicode characters (code-points).

Following is a table of control characters that can be used in Rebol.

| Character | Definition
|-----------|------------
| `#"^(null)"` or `#"^@"` | null (zero)
| `#"^(line)"` or `#"^/"` | new line
| `#"^(tab)"`  or `#"^-"` | horizontal tab
| `#"^(page)"` | new page (and page eject)
| `#"^(esc)"`  | escape
| `#"^(back)"` | backspace
| `#"^(del)"`  | delete
| `#"^^"`      | caret character
| `#"^""`      | quotation mark
| `#"(0)"` to `#"(FFFF)"` | hex forms of characters


### Creation

Characters can be converted to and from other datatypes with the `to-char` function:
```rebol
probe to-char "a"
;== #"a"

probe to-char "z"
;== #"z"
```

Characters follow the ASCII standard and can be constructed by specifying a character's numeric equivalent:
```rebol
probe to-char 65
;== #"A"

probe to-char 52
;== #"4"

probe to-char 52.3
;== #"4"
```

Another method of obtaining a character is to get the `first` character from a string:
```rebol
probe first "ABC"
;== #"A"
```

While characters in strings are not case sensitive, comparison between
individual characters is case sensitive:
```rebol
probe "a" = "A"
;== #(true)

probe #"a" = #"A"
;== #(false)
```

However, when used in many types of functions, the comparison is
not case sensitive unless you specify that option. Examples are:
```rebol
select [#"A" 1] #"a"
;== 1

select/case [#"A" 1] #"a"
;== _

find "abcde" #"B"
;== "bcde"

find/case "abcde" #"B"
;== _

switch #"A" [#"a" [true]]
;== #(true)
```


### Related

Use `char?` to determine whether a value is a `char!` datatype.

```rebol
char? "a"
;== #(false)

char? #"a"
;== #(true)
```

Use the `form` function to print a character without the number sign:
```rebol
form #"A"
;== "A"
```

Use `mold` on to print a character with the number sign and double quotes (and escape sequences for those characters that require it.):
```rebol
mold #"A"
;== {#"A"}
```



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

> **Note:**
> Needs documentation!


------------------------------------------------------------------
## datatype!

Datatypes are documented on this page. Note that new datatypes cannot be created at runtime.

To get a full list of available datatypes, run the following command:
```code
help datatype!
```


------------------------------------------------------------------
## date!


Around the world, dates are written in a variety of formats. However, most countries use the `day-month-year` format. One of the few exceptions is the United States, which commonly uses a `month-day-year` format. For example, a date written numerically as `2/1/1999` is ambiguous. The month could be interpreted as either February or January. Some countries use a dash `-`, some use a forward slash `/`, and others use a period `.` as a separator. Finally, computer people often prefer dates in the 
`year-month-day` (ISO) format so they can be easily sorted.


### Format
The Rebol language is flexible, allowing `date!` datatypes to be expressed in a variety of formats. For example, the first day of March can be expressed in any of the following formats:

```rebol
probe 1/3/1999
1-Mar-1999

probe 1-3-1999
1-Mar-1999

probe 1999-3-1  ;ISO format
1-Mar-1999
```

The year can span up to 9999 and down to 1. Leap days (February 29) can only be written for leap years:

```rebol
probe 29-2-2000
29-Feb-2000
```

The fields of dates can be separated with forward slashes `/` or dashes `-`. Dates can be written in either a year-month-day format or a day-month-year format:

```rebol
probe 1999-10-5
5-Oct-1999

probe 1999/10/5
5-Oct-1999

probe 5-10-1999
5-Oct-1999

probe 5/10/1999
5-Oct-1999
```

Because the international date formats that are not widely used in the USA, a month name or month abbreviation can also be used:

```rebol
probe 5/Oct/1999
5-Oct-1999

probe 5-October-1999
5-Oct-1999

probe 1999/oct/5
5-Oct-1999
```

When the year is the last field, it can be written as either a four digit or two digit number:

```rebol
probe 5/oct/99
5-Oct-1999

probe 5/oct/1999
5-Oct-1999
```

However, it is preferred to write the year in full. Otherwise, problems occur with date comparison and sorting operations. While two digits can be used to express a year, the interpretation of a two-digit year is relative to the current year and is only valid for 50 years in the future or in the past:


```rebol
probe 28-2-66   ;; refers to 1966
28-Feb-1966

probe 12-Mar-20 ;; refers to 2020
12-Mar-2020

probe 11-Mar-45 ;; refers to 2045, not 1945
11-Mar-2045
```

It is recommended to use a four-digit year to avoid potential problems.

To represent dates in the first century (which is rarely done because the Gregorian calendar did not exist), use leading zeros to represent the century (as in `9-4-0029`).

Dates can also include an optional time field and an optional time zone. The time is separated from the date with a forward slash (/). The time zone is appended using a plus (+) or minus (-), and no spaces are allowed. Time zones are written as a time shift (plus or minus) from GMT. The resolution of the time zone is to the half hour. If the time shift is an integer, it is assumed to be hours:

```rebol
probe 4/Apr/2000/6:00+8:00
4-Apr-2000/6:00+8:00

probe 1999-10-2/2:00-4:00
2-Oct-1999/2:00-4:00

probe 1/1/1990/12:20:25-6
1-Jan-1990/12:20:25
```

There can be no spaces within the date. For example:

```rebol
10 - 5 - 99
```

would be interpreted as a subtraction expression, not a date.


### Access
Refinements can be used with a date value to get any of its defined fields:

| Refinement | Description
| `/day`     | Gets the day.
| `/month`   | Gets the month.
| `/year`    | Gets the year.
| `/yearday` | Gets the day of the year.
| `/weekday` | Gets the weekday (1 for Mon, 7 for Sun).
| `/time`    | Gets the time (if present).
| `/hour`    | Gets the time's hour (if present)
| `/minute`  | Gets the time's minute (if present).
| `/second`  | Gets the time's second (if present).
| `/zone`    | Gets the time zone (if present).
| `/utc`     | Returns the UTC (universal) time.

Here's how these refinements work:

```rebol
some-date: 29-Feb-2000
probe some-date/day
29

probe some-date/month
2

probe some-date/year
2000

days: ["Mon" "Tue" "Wed" "Thu" "Fri" "Sat" "Sun"]
probe pick days some-date/weekday
Tue
```

When a time is present, the time related refinements can be used. The `/hour`, `/minute` and `/second` refinements are used with the `/time` refinement that isolates the time segment of the date value for them to work on, but they can also be used alone:

```rebol
lost-time: 29-Feb-2000/11:33:22.14-8:00
probe lost-time/time
11:33:22.14

probe lost-time/time/hour
11

probe lost-time/hour
11

probe lost-time/minute
33

probe lost-time/second
22.14

probe lost-time/zone
-8:00
```

Note that dates are normalized when any field of their time values is set. The date will be adjusted accordingly to make the time a valid 24 hour value.

```rebol
print d: now
23-Oct-2009/3:34:45-4:00

d/time: 50:00
print d
25-Oct-2009/2:00-4:00
```

### Creation

Use the `to-date` function to convert values to a `date!`:

```rebol
probe to-date "5-10-1999"
5-Oct-1999

probe to-date "5 10 1999 10:30"
5-Oct-1999/10:30

probe to-date [1999 10 5]
5-Oct-1999

probe to-date [5 10 1999 10:30 -8:00]
5-Oct-1999/10:30-8:00
```

> **Note:**
> When converting to a `date!`, the year must be specified as four digits.

Conversions can be applied to various math operations on dates:

```rebol
probe 5-Oct-1999 + 1
6-Oct-1999

probe 5-10-1999 - 10
25-Sep-1999

probe 5-Oct-1999/23:00 + 5:00
6-Oct-1999/4:00
```


### Disabling timezone or using UTC
To disable the timezone, just set it to `none!`:

```rebol
date/zone: none
```

However, since this normally indicates a UTC datestamp, it is better to use the /utc` refinement. You can write:

```rebol
date: date/utc
```

For example:

```rebol
date: now
19-Sep-2009/20:04:26-7:00

date: date/utc
20-Sep-2009/3:04:26
```

Note that the timezone is gone.
A Rebol 2 compatible way to do this is:

```rebol
date: now
19-Sep-2009/20:04:26-7:00

date: date - date/zone
20-Sep-2009/3:04:26-7:00

date/zone: none
none

date
20-Sep-2009/3:04:26
```


### Related

Use `date?` to determine whether a value is a `date!` datatype.

```rebol
probe date? 5/1/1999
true
```

The related function `to-idate` returns a standard Internet date string. The Internet date format is day, date, month, year, time (24-hour clock), and time zone offset from GMT.

```rebol
probe to-idate now
Mon, 18 May 2026 12:08:27 +0200
```

The `now` function returns the current date and time in full format including the time zone offset:

```rebol
probe now
18-May-2026/12:08:53+2:00
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


An email address is a datatype. The `email!` datatype allows for easy expression of email addresses:


```rebol
send luke@rebol.com {some message}

emails: [
    john@keats.dom
    lord@byron.dom
    edger@guest.dom
    alfred@tennyson.dom
]
mesg: {poetry reading at 8:00pm!}
foreach email emails [send email mesg]
```

Email is also one of the `series` datatypes, so the same rules that apply to series apply to emails:


```rebol
probe head change/part jane@doe.dom "john" 4
john@doe.dom
```



### Format
The standard format of an email address is a name, followed by an at sign `@`, followed by a domain. An email address can be of any length, but must not include any of restricted characters, such as square brackets, quotes, braces, spaces, newlines, etc..

The following `email!` datatype formats are valid:


```rebol
info@rebol.com
123@number-mail.org
my-name.here@an.example-domain.com
```

Upper and lower cases are preserved in email addresses.

> **Not implemented or outdated documentation:**
> ### Access
> Refinements can be used with an email value to get the user name or domain. The refinements are:
> 
> - `/user` - Get the user name.
> - `/host` - Get the domain.
> 
> Here's how these refinements work:
> 
> 
> ```rebol
> email: luke@rebol.com
> probe email/user
> luke
> 
> probe email/host
> rebol.com
> ```


### Creation
The `to-email` function converts data to the `email!` datatype:

```rebol
probe to-email "info@rebol.com"
info@rebol.com

probe to-email [info rebol.com]
info@rebol.com

probe to-email [info rebol com]
info@rebol.com

probe to-email [user some long domain name out there dom]
user@some.long.domain.name.out.there.dom
```


### Related
Use `email?` to determine whether a value is an `email!`  datatype.

```rebol
probe email? luke@rebol.com
true
```

As emails are part of the `series!` typeset, use `series?` to determine whether the value is a series:

```rebol
probe series? luke@rebol.com
true

probe pick luke@rebol.com 5
#"@"
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



The `image!` datatype is a series that holds RGBA images.

The external image formats supported are GIF, JPEG, PNG and BMP. The loaded image can be manipulated as a series.


### Format
Images are normally loaded from a file.  However, they can be expressed in source code as well by making an image.  The block provided includes the image size and its RGBA data.

```rebol
image: make image! [192x144 #{
    B34533B44634B44634B54735B7473
    84836B84836B84836BA4837BA4837
    BC4837BC4837BC4837BC4837BC483 ...
}
```


### Creation
Empty images can be created using `make` or to-image:`

```rebol
empty-img: make image! 300x300 

empty-img: to-image 150x300
```

The size of the image is provided.

Use `load` to load an image file. If the image's format is not supported, it will fail to load.

Loading an image:

```rebol
img: load %bay.jpg
```


### Related
Use `image?` to determine whether a value is the `image!` datatype:

```rebol
probe image? img
```

Images are included in the `series!` typeset:

```rebol
probe series? img
```

Use the `/size` refinement to return the pixel size of an image as a pair value:


```rebol
probe img/size
```

Use the `/rgb` and `/alpha` refinements to get the RGB and A component separately as binary values.


```rebol
probe img/rgb
probe img/alpha
```

The pixel values of an image are obtained using `pick` and changed using `poke`. The value returned by `pick` is an RGBA tuple value. The value replaced with `poke` also should be a tuple value of length 4.

Picking specific pixels:

```rebol
probe pick img 1 

probe pick img 1500
```

Poking specific pixels:

```rebol
poke img 1 255.255.255.0 
probe pick img 1 

poke img 1500 0.0.0.0 
probe pick img 1500
```


------------------------------------------------------------------
## integer!


In R3 the `integer!` datatype has been expanded to be a 64-bit value.

It ranges from:
```rebol
Minimum: -9223372036854775808
Maximum:  9223372036854775807
```


### Format
Integer values consist of a sequence of numeric digits. A plus (+) or minus (-) immediately before the first digit indicates sign. (There cannot be a space between the sign and the first digit.) Leading zeros are ignored.


```rebol
0 1234 +1234 -1234 00012 -0123
```

Do not  use commas or periods in integers. If a comma or period is found within an integer it is interpreted as a decimal value. However, you can use a single quote `'`  to separate the digits in long integers. Single quotes can appear anywhere after the first digit in the number, but not before the first digit.


```rebol
2'147'483'647
```


### Conversion
Use the `to` function can convert a `string!`, `logic!`, `decimal!`, or `integer!` datatype to an integer:


```rebol
to integer! "123"
123

to integer! false
0

to integer! true
1
```

Conversion from `decimal!` will be truncated towards zero:

```rebol
to integer! 123.8
123

to integer! -123.8
-123
```

Use the `round` function if you desire some other behavior.

To convert a `binary!` to an `integer!` value:


```rebol
to integer! #{1000}
4096
```

Note that the conversion treats the string in network-byte-order (big-endian) and it is not sign extended:


```rebol
to integer! #{8000}
32768
```

To convert from an `integer!` to a `binary!` (in network-byte-order):


```rebol
to binary! 32768
#{0000000000008000}
```

Note that the full hex bit pattern (8 bytes) is output.

As expected, negative values will set the first bit:


```rebol
to binary! -1
#{FFFFFFFFFFFFFFFF}
```

As a convenience for HTML color values, conversions from `issue!` values are also allowed:

```rebol
to integer! #8855DD
8934877
```

Note that to obtain the individual RGB color values, you might want to use a `tuple!` value instead:

```rebol
rgb: to tuple! #8855DD
136.85.221

rgb/2
85
```

> **Special Note:
> Note that for RGB values the above hex conversion is not reversible. That's because the intended use of the integer is not known (to be an RGB value.)
>
> However, you can define your own function for this conversion:
> ```rebol
> to-rgb-str: func [n] [mold to-hex/size n 6]
> ```
> This method is preferred because it does not depend on the zero padding at the head of the string, making it work for 32-bit versions of Rebol as well.
> Here's an example:
> ```rebol
> to-rgb-str to integer! #A8446C
> ;== "#A8446C"
> ```



### Type Coercion
If a decimal and integer are combined in an expression, the integer is converted to a decimal:

```rebol
1.2 + 2
3.2

2 + 1.2
3.2

1.01 > 1
true

0 < .001
true
```


### Related
Use `integer?` to determine whether a value is an `integer!` datatype.


```rebol
integer? -1234
true
```

Use the `form`, `print`, and `mold` functions with an integer argument to print a integer value as a string:


```rebol
mold 123
123

form 123
123

print 123
123
```



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


The `logic!` datatype consists of two states representing `true` and `false`. They are often returned from comparisons such as:


```rebol
age: 100
probe age = 100
true

time: 10:31:00
probe time < 10:30
false

str: "this is a string"
probe (length? str) > 10
true
```

The `logic!` datatype is most commonly used as parameters to conditional functions such as `if`, `while`, and `until`:


```rebol
if age = 100 [print "Centennial human"]
Centennial human

while [time > 6:30] [
    send person "Wake up!"
    wait [0:10]
]
```

The complement of a logic value is obtained from the `not` function:


```rebol
there: place = "Ukiah" 
if not there [...]
```



### Format
Normally, logic values are retrieved from the evaluation of comparison expressions. However, words can be set to a logic value and used to turn the word `on` or `off`:

```rebol
print-me: false
print either print-me ["turned on"]["turned off"]
turned off

print-me: true
print either print-me ["turned on"]["turned off"]
turned on
```

The `false` value is not equivalent to integer zero or `none!`. However, in conditional expressions `false` and `none!` have the same effect:

```rebol
print-me: none
print either print-me ["turned on"]["turned off"]
turned off
```

Just about any value assigned to a word has the same effect as `true`:

```rebol
print-me: "just a string"
print either print-me ["turned on"]["turned off"]
turned on

print-me: 11-11-1999
print either print-me ["turned on"]["turned off"]
turned on
```

The following words are predefined to hold logic values:

```rebol
true
on     ;same as true
yes    ;same as true
false
off    ;same as false
no     ;same as false
```

So, instead of `true` and `false`, when it makes sense, the words `on` and `off`, or `yes` and `no` can be used instead:

```rebol
print-me: yes
print either print-me ["turned on"]["turned off"]
turned on

print-me: no
print either print-me ["turned on"]["turned off"]
turned off

print-me: on
print either print-me ["turned on"]["turned off"]
turned on

print-me: off
print either print-me ["turned on"]["turned off"]
turned off
```


### Creation
The `to-logic` function converts `integer!` or `none!` values to the `logic!` datatype:

```rebol
probe to-logic 0
false

probe to-logic 200
true

probe to-logic none
false

probe to-logic []
true

probe to-logic "a"
true

probe to-logic none
false
```


### Related
Use `logic?` to determine whether a value is a `logic!` datatype.

```rebol
probe logic? 1
false

probe logic? on
true

probe logic? false
true
```

Use the functions `form`, `print`, and `mold` to print a logic value:

```rebol
probe form true
true

probe mold false
false

print true
true
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


direct CPU evaluated function



------------------------------------------------------------------
## none!


The `none!` datatype contains a single value that represents nothing or no value.

The concept of none is not the same as an empty block, empty string, or null character. It is an actual value that represents non-existence.

A `none!` value can be returned from various functions, primarily those involving series (for example, `pick` and `find`).

The Rebol word `none!` is defined as a `none!` datatype and contains a `none!` value. The word `none!` is not equivalent to zero` or false`. However, `none!` is interpreted as false` by many functions.

A `none!` value has many uses such as a return value from series functions like `pick`, `find` and select:`

```rebol
if (pick series 30) = none [...]
```

In databases, a `none!` can be a placeholder for missing values:

```rebol
email-database: [
    "Bobby" bob@rebol.com 40
    "Linda" none 23
    "Sara"  sara@rebol.net 33
]
```

It also can be used as a logic value:

```rebol
secure none
```


### Format
The word `none!` is predefined to hold a `none!` value.

Although `none!` is not equivalent to `zero` or `false`, it is valid within conditional expressions and has the same effect as `false`:

```rebol
probe find "abcd" "e"
none

if find "abcd" "e" [print "found"]
```

### Creation
The `to-none` function always returns `none!`.

### Related
Use `none?` to determine whether a value is a `none!` datatype.

```rebol
print none? 1
false

print none? find [1 2 3] 4
true
```

The `form`, `print`, and `mold` functions print the value `none!` when passed a `none!` argument.


```rebol
probe form none
none

probe mold none
none

print none
none
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


infix operator (special evaluation exception)



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


Refinements are modifiers, similar to adjectives used in natural
(human) languages. A refinement indicates a variation in the use
of, or extension in the meaning of, a function, object,
filename, URL, or path. Refinements are always symbolic in their
value.

Refinements are used for functions:

```rebol
block: [1 2]
append/only block [3 4]
```

objects:

```rebol
print system/version
```

files:

```rebol
dir: %docs/core
print read dir/file.txt
```

urls:

```rebol
site: http://www.rebol.com
print read site/index.html
```


### Format
Refinements are composed with a slash followed by a valid Rebol
word (see the words section below for definition). Examples are:

```rebol
/only
/test1
/save-it
```

Refinements are usually joined to other words, such as in the case
of:

```rebol
port: open/binary file
```

But refinements can also be written alone, as is done when specifying
refinements to a function:

```rebol
save-data: function [file data /limit /reload] ...
```


### Creation
Refinements can be created literally in source code:

```rebol
/test
```

or can be composed from the `to-refinement` word:

```rebol
probe to-refinement "test"
/test
```


### Related
To test for a refinement, use the `refinement?` function:

```rebol
probe refinement? /test
true

probe refinement? 'word
false
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


Strings are a series of characters. All operations performable on series values can be performed on strings.


### Format
String values are written as a sequence of characters surrounded by double quotes `" "` or braces `{ }`. Strings enclosed in double quotes are restricted to a single line and must not contain unprintable characters.


```rebol
"This is a short string of characters."
```

Strings enclosed in braces are used for larger sections of text that span multiple lines. All of the characters of the string, including spaces, tabs, quotes, and newlines are part of the string.


```rebol
{This is a long string of text that will 
not easily fit on a single line of source.
These are often used for documentation
purposes.}
```

Braces are counted within the string, so a string can include other braces as long as the number of closing braces matches the number of opening braces.


```rebol
{
This is another long string of text that would
never fit on a single line. This string also
includes braces { a few layers deep { and is 
valid because there are as many closing braces }
as there are open braces } in the string.
}
```

You can include special characters and operations in strings by prefixing them with a caret `^`.  Special characters include:

| Character | Definition
| `^"` | Inserts a double quote `"`.
| `^}` | Inserts a closing brace `}`.
| `^^` | Inserts a  caret `^`.
| `^/` | Starts a new line.
| `^(line)` | Starts a new line.
| `^-`      | Inserts a tab.
| `^(tab)`  | Inserts a tab.
| `^(page)` | Starts a new page.
| `^(back)` | Erases one character to the left of the insertion point.
| `^(null)` | Inserts a null character.
| `^(escape)` | Inserts an escape character.
| `^(letter)` | Inserts control-letter (A-Z).
| `^(xx)`     | Inserts an ASCII character by hexidecimal (xx) number. his format allows for expansion into unicode characters in the future.


### Creation
Use `make` to create a pre-allocated amount of space for an empty string:

```rebol
make string! 40'000 ; space for 40k characters
```

The `to-string` function converts data of other datatypes to a `string!` datatype:

```rebol
probe to-string 29-2-2000
"29-Feb-2000"

probe to-string 123456.789
"123456.789"

probe to-string #888-555-2341
"888-555-2341"
```

Converting a block of data to a string with `to-string` has the effect of doing a `rejoin`, but without evaluating the block's contents:

```rebol
probe to-string [123 456]
"123456"

probe to-string [225.225.225.0 none true 'word]
"225.225.225.0nonetrueword"
```


### Related
Use `string?` or `series?` to determine whether a value is an `string!`  datatype:


```rebol
print string? "123"
true

print series? "123"
true
```

The functions `form` and `mold` are closely related to strings, as they create strings from other datatypes. The `form` function makes a human readable version of a specified datatype, while `mold` makes a Rebol readable version.

```rebol
probe form "111 222 333"
"111 222 333"

probe mold "111 222 333"
{"111 222 333"}
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


It is common to represent version numbers, Internet addresses, and RGB color values as a sequence of three or four integers. These types of numbers are called a `tuple!` (as in quintuple) and are represented as a set of integers separated by periods.


```rebol
1.3.0 2.1.120 1.0.2.32     ; version
199.4.80.250 255.255.255.0 ; net addresses/masks
0.80.255 200.200.60        ; RGB colors
```



### Format
Each integer field of a `tuple!` datatype can range between 0 and 255. Negative integers produce an error.

Three to ten integers can be specified in a tuple. In the case where only two integers are given, there must be at least two periods, otherwise the value is treated as a decimal.


```rebol
probe 1.2     ; is decimal
1.2

probe type? 1.2
decimal!

probe 1.2.3   ; is tuple
1.2.3

probe 1.2.    ; is tuple
1.2.0

probe type? 1.2.
tuple!
```



### Creation
Use the `to-tuple` function to convert data to the `tuple!` datatype:


```rebol
probe to-tuple "12.34.56"
12.34.56

probe to-tuple [12 34 56]
12.34.56
```



### Related
Use `tuple?` to determine whether a value is a `tuple!` datatype.


```rebol
probe tuple? 1.2.3.4
true
```

Use the `form` function to print a tuple as a string:


```rebol
probe form 1.2.3.4
1.2.3.4
```

Use the `mold` function to convert a tuple into a string that can be read back into Rebol as a tuple:


```rebol
probe mold 1.2.3.4
1.2.3.4
```

Use the `print` function to print a tuple to standard output after using the  `reform` function:


```rebol
print 1.2.3.4
1.2.3.4
```


#### Auto Clipping
During math operations, elements of a tuple will clip at 0 and 255. This is done to make math easier for common tuple operations such generating as color values.


```rebol
print navy
0.0.128

print navy * 2
0.0.255

print gray
128.128.128

print gray + green
128.255.128
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


URL is an acronym for Uniform Resource Locator, an Internet standard used to access resources such as web pages, images, files, and email across the network. The best known URL scheme is that used for web locations such as http://www.rebol.com.

URL values are a subset of series, and thus can be manipulated as series:


```rebol
url: http://www.rebol.com/reboldoc.html
probe to-file find/reverse (tail url) "rebol"
%reboldoc.html
```



### Format
The first part of a URL indicates its communications protocol, called a 
scheme. The language supports several schemes, including: web pages (`HTTP:`), file transfer (`FTP:`), newsgroups (`NNTP:`), email (`MAILTO:`), files (`FILE:`), finger (`FINGER:`), whois (`WHOIS:`), small network time (`DAYTIME:`), post office (`POP:`), transmission control (`TCP:`) and domain name service (`DNS:`). These scheme names are followed by characters that are dependent on which scheme being used.

```rebol
http://host.dom/path/file
ftp://host.dom/path/file
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

Some fields are optional. For instance, the host can be followed by a port number if it differs from the default. An FTP URL supplies a default password if one is not specified:


```rebol
ftp://user:password@host.dom/path/file
```

Characters in a URL must conform to Internet standards. Restricted characters must be encoded in hexadecimal by preceding them with the escape character %:


```rebol
probe http://www.somesite.dom/odd%28dir%29/odd%7Bfile%7D.txt
http://www.somesite.dom/odd%28dir%29/odd%7Bfile%7D.txt

print http://www.somesite.dom/odd%28dir%29/odd%7Bfile%7D.txt
http://www.somesite.dom/odd(dir)/odd{file}.txt
```



### Creation
The `to-url` function converts blocks to the `url!` datatype, the first element in the block is the scheme, the second element is the domain (with or without `user:pass` and port) the remaining elements are the path and file:


```rebol
probe to-url [http www.rebol.com reboldoc.html]
http://www.rebol.com/reboldoc.html

probe to-url [http www.rebol.com %examples "websend.r"]
http://www.rebol.com/examples/websend.r

probe to-url [http usr:pass@host.com:80 "(path)" %index.html]
http://usr:pass@host.com:80/%28path%29/index.html
```



### Related
The datatype word is `url!`.

Use `url?` to test the datatype.


```rebol
probe url? ftp://ftp.rebol.com/
true
```

As urls are a subset of the series pseudotype, use `series?` to check this:


```rebol
probe series? http://www.rebol.com/
true
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
