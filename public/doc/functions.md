;; The content of this file is parsed to extract function details and usage examples.
;; The function description, along with details of its arguments and refinements, isn't
;; included in this document. Instead, it is sourced directly from the function specification.
;; The original data in this file were collected from https://www.rebol.com/r3/docs/functions.html

## ABOUT
[[ license usage help ]]

Displays REBOL title and version information on the REBOL console.
```text
>> about
╔══════════════════════════════════════════════════════════════════════════╗
║                                                                          ║
║  REBOL/Bulk 3.18.3 (Oldes branch)                                        ║
║                                                                          ║
║    Copyright  2012 REBOL Technologies                                    ║
║               2012-2024 Rebol Open Source Contributors                   ║
║               Apache 2.0 License, see LICENSE.                           ║
║    Website    https://github.com/Oldes/Rebol3                            ║
║                                                                          ║
║    Platform   Windows | x64-pc-win32-pe | cl                             ║
║    Build      19-Feb-2025/13:20                                          ║
║                                                                          ║
║    Home       C:\Users\oldes\Rebol\                                      ║
║                                                                          ║
╚══════════════════════════════════════════════════════════════════════════╝
```

------------------------------------------------------------------
## ABS
@@ ABSOLUTE

------------------------------------------------------------------
## ABSOLUTE
[[ abs sign? negate - ]]

Returns a positive value equal in magnitude.
```rebol
>> absolute -123
== 123
>> absolute -1:23
== 1:23
>> absolute -1x4
== 1x4
```

------------------------------------------------------------------
## ACCESS-OS
------------------------------------------------------------------
## ACOS
[[ arccosine ]]

------------------------------------------------------------------
## ACTION?
[[ function? op? native? any-function? type? ]]

Actions are special functions that operate with datatypes. See `action!` for more.
```rebol
>> action? :add
== true
>> action? :append
== true
>> action? :+
== false
>> action? "add"
== false
```

------------------------------------------------------------------
## ADD
[[ + - subtract ]]

Note: The `+` operator is a special infix form for this function.

Many different datatypes support addition.


```rebol
print add 123 1
124

print add 1.23 .004
1.234

print add 1.2.3.4 4.3.2.1
5.5.5.5

print add $1.01 $0.0000000001
$1.0100000001

print add 3:00 -4:00
-1:00

print add 31-Dec-1999 1
1-Jan-2000
```

When adding values of different datatypes, the values must be compatible. Auto conversion of the values will occur into the datatype that has the most expansive representation. For example an integer added to a decimal will produce a decimal.

------------------------------------------------------------------
## AJOIN
[[ join rejoin form reform append ]]

The `join` and `rejoin` functions return the same datatype as their first element, be it a `string!`, `file!`, `binary!`, `tag!`, `email!` or whatever. However, there are times when you just want to construct a `string!`, and that's the purpose of `ajoin`.

For example:


```rebol
ajoin ["test" 123]
"test123"
```

It is similar to `reform` but does not insert spaces between values:


```rebol
reform ["test" 123]
"test 123"
```

Note that the block is always evaluated:


```rebol
time: 10:30
ajoin [time/hour "h" time/minute "m"]
"10h30m"
```

The `ajoin` function is equivalent to:


```rebol
to-string reduce block
```


###### How it differs
Here are examples that show how `ajoin` differs from `join` and `rejoin`.

Compare:


```rebol
ajoin [<test> 123]
"<test>123"
```

with:


```rebol
rejoin [<test> 123]
<test123>
```

and:


```rebol
join <test> 123
<test123>
```

Notice that the last two examples return a `tag!`, not a `string!`.

------------------------------------------------------------------
## ALL
[[ any and or case switch ]]

The `all` function is the most common way to test multiple conditions, such as in the line:


```rebol
if all [num > 1  num < 1000] [do something]
```

It works by evaluating each expression in a block until one of the expressions returns `none!` or false, in which case a `none!` is returned. Otherwise, the value of the last expression will be returned.


```rebol
print all [1 none]
none

print all [none 1]
none

print all [1 2]
2

print all [10 > 1 "yes"]
yes

print all [1 > 10 "yes"]
none

time: 10:30
if all [time > 10:00 time < 11:00] [print "time is now"]
time is now
```

No other expressions are evaluated beyond the point where a value fails:


```rebol
a: 0
all [none a: 2]
print a
0

a: 0
all [1 a: 2]
print a
2

day: 10
time: 9:45
ready: all [day > 5  time < 10:00  time: 12:00]
print time
12:00
```

The `any` function is a companion of `all` to test for the opposite condition, where any one of the values will result in a true result.

------------------------------------------------------------------
## ALL-OF
[[ any-of ]]

```rebol
>> all-of x [33 -1 24] [x > 0]
== #(none)

>> all-of x [33 -1 24] [integer? x]
== #(true)
```

------------------------------------------------------------------
## ALSO
[[ if either any all ]]

The `also` function lets you evaluate two expressions, but return the first, rather than the second. This function may seem a bit odd at first, but in many cases it can save you from needing another temporary variable.

Consider the case where you want to evaluate a block and return its result, but before returning the result, you want to change directories.

You could write:
```rebol
result: do block
change-dir old-dir
return result
```

Or, you could write
```rebol
return also do block change-dir old-dir
```

In fact, that's actually what happens in the `in-dir` function.
Another case might be an I/O port used by a function that wants to `return` the port's data but also `close` it:
```rebol
return also port/locals/buffer close port
```

If you `close` the port first, the buffer cannot be accessed.

------------------------------------------------------------------
## ALTER
[[ find remove insert unique intersect exclude difference ]]

The `alter` function helps you manage small data-sets. It either adds or removes a value depending on whether the value is already included. (The word `alter` is short for the word "alternate", the action taking place.)

For example, let's say you want to keep track of a few options used by your code. The options may be: flour, sugar, salt, and pepper. The following code will create a new block (to hold the data set) and add to it:


```rebol
options: copy []
alter options 'salt
probe options
[salt]

alter options 'sugar
probe options
[salt sugar]
```

You can use functions like `find` to test the presence of an option in the set:


```rebol
if find options 'salt [print "Salt was found"]
Salt was found
```

If you use `alter` a second time for the same option word, it will be removed:


```rebol
alter options 'salt
probe options
[sugar]
```

Normally `alter` values are symbolic words (such as those shown above) but any datatype can be used such as integers, strings, etc.


```rebol
alter options 120
alter options "test"
probe options
[sugar 120 "test"]
```

Also, `alter` returns true if the value was added to the series, or false if the value was removed.

------------------------------------------------------------------
## AND
[[ or all not xor logic? integer? ]]

For `logic!` values, both values must be true to return true, otherwise a false is returned. AND is an infix operator.


```rebol
print true and true
true

print true and false
false

print (10 < 20) and (20 > 15)
true
```


```html
<fieldset class="fset"><legend>Programming style</legend>
<p>It's usually better to use <a href="#all">all</a> for anding conditional logic, such as the example above.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if all [10 &lt; 20 20 &gt; 15] ...</code></pre></div>
</fieldset>
```

For `integer!`, `tuple!`, `binary!`, and other datatypes, each bit is separately anded.


```rebol
print 123 and 1
1

print 1.2.3.4 and 255.0.255.0
1.0.3.0
```

------------------------------------------------------------------
## AND~
[[ and or xor or~ xor~ ]]

This is the primary function behind the `and` operator. It can be used where you want prefix rather than infix notation:


```rebol
bits: and~ mask 3
```

------------------------------------------------------------------
## ANY
[[ all or and case switch ]]

The `any` function is the most common way to test for one of multiple conditions, such as in the line:


```rebol
if any [a > 10  b > 20  c > 30] [do something]
```

Here, if any one of the conditions produces a true result, the `if` will evaluate the block.

This function works by evaluating each expression in a block until one of the expressions returns a value other than `none!` or false, in which case the value is returned. Otherwise, `none!` will be returned.

Examples to help show how it works:


```rebol
print any [1 none]
1

print any [none 1]
1

print any [none none]
none

print any [false none]
none

print any [true none]
true

time: 10:30
if any [time > 10:00  time < 11:00] [print "time is now"]
time is now
```

No other expressions are evaluated beyond the point where a successful value is found. This can be useful. For example:


```rebol
a: 0
any [none a: 2]
print a
2

a: 0
any [1 a: 2]
print a
0

day: 10
time: 9:45
ready: any [day > 5  time < 10:00  time: 12:00]
print time
9:45
```

The `any` function is also useful for setting default values. For example:


```rebol
size: any [size 100]
```

If size was `none!`, then it gets set to 100. This works even better if there are alternative defaults:


```rebol
size: any [size prefs/size 100]
```

Another use for `any` is to emulate a sequence of if...elseif...elseif...else. Instead of writing:


```rebol
either cond-1 [
    code-1
] [
    either cond-2 [
        code-2
    ] [
        either cond-3 ...
    ]
]
```

it is possible to write:


```rebol
any [
    if cond-1 [
        code-1
        true ; in case code-1 returns FALSE or NONE
    ]
    if cond-2 [
        code-2
        true
    ]
    ...
]
```

Also see the `case` function for more about this code pattern.

The `all` function is a companion of `any` to test for the opposite condition, where all of the values must be true to return a true result.

------------------------------------------------------------------
## ANY-BLOCK?
[[ type? block? paren? path? any-function? any-string? any-word? ]]

Returns true only if the value is a `block!` (any kind of block) and false for all other values.


```rebol
>> any-object? "foo"
== #(false)

>> any-block? [1 2]
== #(true)

>> any-block? first [(1 2) 3]
== #(true)

>> any-block? 'a/b/c
== #(true)

>> any-block? 12
== #(false)
```

To learn what datatypes are blocks:


```rebol
print any-block!
block! paren! path! set-path! get-path! lit-path!
```

------------------------------------------------------------------
## ANY-FUNCTION?
[[ type? function? native? op? any-block? any-string? any-word? ]]

Returns true if the value is any type of function and returns false for all other values.


```rebol
>> any-function? :find
== #(true)

>> any-function? :+
== #(true)

>> any-function? func [] [print "hi"]
== #(true)

>> any-function? 123
== #(false)
```

To learn what datatypes are functions:


```rebol
print any-function!
native! action! rebcode! command! op! closure! function!
```

------------------------------------------------------------------
## ANY-OBJECT?
[[ type? ]]

```rebol
>> any-object? system
== #(true)

>> any-object? try [1 / 0]
== #(true)

>> any-object? "foo"
== #(false)
```

------------------------------------------------------------------
## ANY-OF
[[ all-of ]]

```rebol
>> any-of x [-1 4 10] [x > 0]
== 4

>> any-of [x y] [1 4 10 8 5 -3] [(x - 2) = y]
== [10 8]
```

------------------------------------------------------------------
## ANY-PATH?

Returns true if the value is any type of `path!` and returns false for all other values.


```rebol
>> any-path? 'test/this
== #(true)

>> any-path? first [example/item: 10]
== #(true)

>> any-path? second [print :example/item]
== #(true)

>> any-path? 123
== #(false)
```

To learn what datatypes are paths:


```rebol
print any-path!
path! set-path! get-path! lit-path!
```

------------------------------------------------------------------
## ANY-STRING?
[[ type? string? file? email? url? any-block? any-function? ]]

Returns true for any type of string, and false for all other values.


```rebol
>> any-string? "Hello"
== #(true)

>> any-string? email@rebol.com
== #(true)

>> any-string? ftp://ftp.rebol.com
== #(true)

>> any-string? %dir/file.txt
== #(true)

>> any-string? @name
== #(true)

>> any-string? 11-Jan-2000
== #(false)
```

To see what datatypes are strings:


```rebol
print any-string!
string! file! email! ref! url! tag!
```

------------------------------------------------------------------
## ANY-WORD?
[[ type? any-block? any-function? any-string? ]]

Returns true for any type of word and false for all other values.


```rebol
>> any-word? 'word
== #(true)

>> any-word? /word
== #(true)

>> any-word? #issue
== #(true)

>> any-word? first [set-word: 'lit-word :get-word]
== #(true)

>> any-word? second [set-word: 'lit-word :get-word]
== #(true)

>> any-word? third [set-word: 'lit-word :get-word]
== #(true)

>> any-word? 123
== #(false)
```

To see what datatypes are words:


```rebol
print any-word!
word! set-word! get-word! lit-word! refinement! issue!
```

------------------------------------------------------------------
## APPEND
[[ insert change remove repend ]]

The `append` function is a shortcut for doing an `insert` at the tail of any type of [series](https://www.rebol.com/r3/docs/concepts/series.html) and returning the head:


```rebol
head insert tail series value
```

Basic examples:


```rebol
string: copy "hello"
probe append string " there"
"hello there"

file: copy %file
probe append file ".txt"
%file.txt

url: copy http://
probe append url "www.rebol.com"
http://www.rebol.com
```

The /only refinement forces a block to be appended as a single block element, rather than appending the separate elements of the block:


```rebol
block: copy [1 2 3]
probe append block [4 5 6]
[1 2 3 4 5 6]

block: copy [1 2 3]
probe append/only block [4 5 6]
[1 2 3 [4 5 6]]
```

To learn more about the operation of the other refinements, see the `insert` function.

------------------------------------------------------------------
## APPLY
[[ do switch case ]]

When you evaluate a function, you normally provide any arguments directly in-line with its call:


```rebol
append data 123
```

However, there are times when you want to store the arguments as a single block and pass them to the function. This is the purpose of the `apply` function. The above example can be written as:


```rebol
apply :append [data 123]
```

or, using a variable to hold the block:


```rebol
args: [data 123]
apply :append args
```

If any arguments are missing from the block, a `none!` is passed instead:


```rebol
data: [456]
apply :append [data]
probe data
[456 none]
```

Function refinements can also be passed in the order they are specified by the arguments spec block. For example, we can see:


```rebol
>> ? append
USAGE:
    APPEND series value /part length /only /dup count
```

So in this example we use the /dup refinement:


```rebol
data: [456]
apply :append [data 1 none none none true 3]
probe data
[456 1 1 1]
```

Note that the refinement itself must be set to true.

------------------------------------------------------------------
## ARCCOSINE
[[ arcsine arctangent cosine exp log-10 log-2 log-e power sine square-root tangent ]]

The `arccosine` provides the inverse of the `cosine` function.


```rebol
print arccosine .5
60.0
```

Note that arccosine goes to infinity at 90 degrees and will cause a numeric overflow.

------------------------------------------------------------------
## ARCSINE
[[ arccosine arctangent cosine exp log-10 log-2 log-e power sine square-root tangent ]]

The `arcsine` provides the inverse of the `sine` function.


```rebol
>> arcsine .5
== 30.0
```

Note that arccsine goes to infinity at 0 and each 180 degrees and will cause a numeric overflow.

------------------------------------------------------------------
## ARCTANGENT
[[ arccosine arcsine cosine exp log-10 log-2 log-e power sine square-root tangent ]]

The `arctangent` function provides the inverse of the `tangent` function.


```rebol
>> arctangent .22
== 12.4074185274007
```

------------------------------------------------------------------
## ARCTANGENT2
------------------------------------------------------------------
## ARRAY
[[ make pick poke ]]

In REBOL, arrays are simply blocks that are initialized to a specific size with all elements set to an initial value (v:none by default). The `array` function is used to create and initialize arrays.

Supplying a single integer as the argument to `array` will create an array of a single dimension. The example below creates a five element array with values set to none:
```rebol
>> block: array 5
== [#(none) #(none) #(none) #(none) #(none)]

>> length? block
== 5
```

To initialize an array to values other than NONE, use the /initial refinement. The example below intializes a block with zero values:
```rebol
>> block: array/initial 5 0
== [0 0 0 0 0]
```

To create an array of multiple dimensions, provide a block of integers as the argument to the `array` function. Each integer specifies the size of that dimension of the array. (In REBOL, such multidimensional arrays are created using blocks of blocks.)
```rebol
>> xy-block: array [2 3]
== [[#(none) #(none) #(none)] [#(none) #(none) #(none)]]

>> xy-block: array/initial [2 3] 0
== [[0 0 0] [0 0 0]]
```

Once an array has been created, you can use paths or the `pick` and `poke` functions to set and get values of the block based on their indices:
```rebol
block/3: 1000
poke block 5 now
probe block
[0 0 1000 0 12-Feb-2009/17:46:59-8:00]

probe block/3
1000

repeat n 5 [poke block n n]
probe block
[1 2 3 4 5]

xy-block/2/1: 1.2.3
xy-block/1/3: copy "test"
probe xy-block
[[0 0 "test"] [1.2.3 0 0]]

probe xy-block/2/1
1.2.3

repeat y 2 [
    dim: pick xy-block y
    repeat x 3 [poke dim x to-pair reduce [x y]]
]
probe xy-block
```


###### Coding Style Notes
REBOL uses the concept of expandable series for holding and manipulating data, rather than the concept of fixed size arrays. For example, in REBOL you would normally write:


```rebol
block: copy []
repeat n 5 [append block n]
```

rather than:


```rebol
block: array 5
repeat n 5 [poke block n n]
```

In other words, REBOL does not require you to specify the size of data arrays (blocks, bytes, or strings) in advance. They are dynamic.

------------------------------------------------------------------
## AS
------------------------------------------------------------------
## AS-BLUE
------------------------------------------------------------------
## AS-CYAN
------------------------------------------------------------------
## AS-GRAY
------------------------------------------------------------------
## AS-GREEN
------------------------------------------------------------------
## AS-PAIR
[[ to-pair pair? ]]

Provides a shortcut for creating `pair!` values from separate X and
Y integers.


```rebol
print as-pair 100 50
100x50
```

------------------------------------------------------------------
## AS-PURPLE
------------------------------------------------------------------
## AS-RED
------------------------------------------------------------------
## AS-WHITE
------------------------------------------------------------------
## AS-YELLOW
------------------------------------------------------------------
## ASCII?
[[ latin? utf8? ]]

```rebol
>> ascii? "hello"
== #(true)

>> ascii? "česko"
== #(false) ;; because (to integer! #"č") == 269
```

------------------------------------------------------------------
## ASIN
------------------------------------------------------------------
## ASK
[[ confirm input prin print ]]

Provides a common prompting function that is the same as a `prin` followed by an `input`. The resulting input will
have spaces trimmed from its head and tail. The /hide refinement hides input with "*" characters. The function returns a string!.

Example, where the user enters Luke as input:


```rebol
ask "Your name, please? "
Your name, please? Luke
== "Luke"
```

------------------------------------------------------------------
## ASSERT
[[ all try ]]

In code, it is common to check conditions that should always be valid or true. For example, a check may be made for a value to be in range or of a given datatype.

Since the conditions are always supposed to be true, it's often not worth the effort to provide a detailed error message or explanation if the condition fails, and often such information would only be meaningful to the programmer, not the end user.

To make it easier to check such conditions, the `assert` function is provided.

Assert can check "truth" conditions, or with a refinement, it can check datatype validity conditions.


####### Asserting truth
To check truth conditions, the argument of `assert` is a block of one or more conditions, and each is checked (similar to `all`) to be true:


```rebol
num: 10
assert [num > 20]
** Script error: assertion failed for: [num > 20]
** Where: assert
** Near: assert [num > 20]
```

Note that for compound assertions, the error message will indicate the assertion that failed:


```rebol
num: 10
age: 20
assert [num > 0 age > 50]
** Script error: assertion failed for: [age > 50]
** Where: assert
** Near: assert [num > 0 age > 50]
```

Look at the error line closely, and you can tell which one failed.

Note: only the first three elements of the failed assertion will be shown (to help avoid long error lines.)


####### Asserting datatypes
It is also common to validate datatypes using the /type refinement:


```rebol
age: "37"
name: "Bob"
assert/type [age integer! name string!]
** Script error: datatype assertion failed for: age
** Where: assert
** Near: assert/type [age integer! name string!]
```

It fails because age is actually a string, not an integer.

The `assert` function is useful for validating value before a section of code that depends on those value:


```rebol
assert/type [
    spec object!
    body block!
    spec/size number!
    spec/name [string! none!]
    spec/options [block! none!]
]
```

Note that `assert` is safe to use on all function datatypes. The functions will not be evaluated as part of the process; therefore, `assert` is an easy way to prevent function passage in unwanted cases.

------------------------------------------------------------------
## AT
[[ skip pick head tail ]]

Provides a simple way to index into any type of [series](https://www.rebol.com/r3/docs/concepts/series.html). `at` returns the series at the new index point.

Note that the operation is relative to the current position within the series.

A positive integer N moves to the position N in the series:


```rebol
numbers: [11 22 33]
print at numbers 2
22 33
```

An index of 0 is the same as an index of 1:


```rebol
print at numbers 0
11 22 33
```

Using a negative index N, you can go N values backwards in a series:


```rebol
numbers: at numbers 3
print numbers
33

print at numbers -1
22 33
```

More examples, combined with other series functions:


```rebol
words: [grand grape great good]
print first at words 2
grape

remove at words 2
insert at words 3 [super]
probe words
[grand great super good]
```

------------------------------------------------------------------
## ATAN
------------------------------------------------------------------
## ATAN2
------------------------------------------------------------------
## ATTEMPT
[[ try error? ]]

The `attempt` function is a shortcut for the frequent case of:


```rebol
error? try [block]
```

More accurately, this is performed:


```rebol
if not error? try [set/any 'val block] [val]
```

The format for `attempt` is:


```rebol
attempt [block]
```

`attempt` is useful where you either do not care about the error result or you want to make simple types of decisions based on the error.


```rebol
attempt [make-dir %fred]
```

`attempt` returns the result of the block if an error did not occur.  If an error did occur, a none is returned.

In the line:


```rebol
value: attempt [load %data]
probe value
none
```

the value is set to none if the %data file cannot be loaded (e.g. it is missing or contains an error).  This allows you to write conditional code such as:


```rebol
if not value: attempt [load %data] [print "Problem"]
Problem
```

Or code such as:


```rebol
value: any [attempt [load %data] [12 34]]
probe value
[12 34]
```

------------------------------------------------------------------
## ATZ
[[ at ]]

```rebol
>> blk: [1 2 3 4]
== [1 2 3 4]

>> at blk 2
== [2 3 4]

>> atz blk 2
== [3 4]
```

------------------------------------------------------------------
## AVERAGE

```rebol
>> average [1 2 3]
== 2
```

------------------------------------------------------------------
## BACK
[[ next last head tail head? tail? ]]

Works on any type of [series](https://www.rebol.com/r3/docs/concepts/series.html). If the series is at its head, it will remain at its head. `back` will not go past the head, nor will it wrap to the tail.


```rebol
print back tail "abcd"
d

str: tail "time"
until [
    str: back str
    print str
    head? str
]
e
me
ime
time

blk: tail [1 2 3 4]
until [
    blk: back blk
    print first blk
    head? blk
]
4
3
2
1
```

------------------------------------------------------------------
## BINARY

This is quite complex dialect which requires own documentation. But it may be
used for binary data streaming in both directions like:
```rebol
>> stream: binary bin: #{}
== make object! [
    type: 'bincode
    buffer: #{}
    buffer-write: #{}
    r-mask: 0
    w-mask: 0
]

>> binary/write stream [UI8 1 SI16 -2 UI16BYTES "hello"]
== make object! [
    type: 'bincode
    buffer: #{01FFFE000568656C6C6F}
    buffer-write: #{}
    r-mask: 0
    w-mask: 0
]

>> bin
== #{01FFFE000568656C6C6F}

>> binary/read stream 'UI8
== 1

>> binary/read stream [SI16 UI16BYTES]
== [-2 #{68656C6C6F}]
```

------------------------------------------------------------------
## BINARY?
[[ type? ]]

Returns FALSE for all other values.


```rebol
>> binary? #{13ff acd0}
== #(true)

>> binary? 2#{00001000}
== #(true)

>> binary? 1234
== #(false)
```

------------------------------------------------------------------
## BIND
[[ bind? use do func function does make import ]]

Binds meaning to words in a block. That is, it gives words a context in which they can be interpreted. This allows blocks to be exchanged between different contexts, which permits their words to be understood. For instance a function may want to treat words in a global database as being local to that function.

The second argument to `bind` is a word from the context in which the block is to be bound. Normally, this is a word from the local context (e.g. one of the function arguments), but it can be a word from any context within the system.

`bind` will modify the block it is given. To avoid that, use the /copy refinement. It will create a new block that is returned as the result.


```rebol
words: [a b c]
fun: func [a b c][print bind words 'a]
fun 1 2 3
fun "hi" "there" "fred"
hi there fred

words: [a b c]
object: make object! [
    a: 1
    b: 2
    c: 3
    prove: func [] [print bind words 'a]
]
object/prove
1 2 3

settings: [start + duration]
schedule: function [start] [duration] [
    duration: 1:00
    do bind settings 'start
]
print schedule 10:30
11:30
```

Editor note: Describe /new here
Editor note: Describe /set here

------------------------------------------------------------------
## BITSET?
[[ charset ]]

Returns FALSE for all other values.


```rebol
>> bitset? make bitset! "abc"
== #(true)

>> bitset? charset "abc"
== #(true)

>> bitset? 123
== #(false)
```

------------------------------------------------------------------
## BLOCK?
[[ type? ]]

Returns FALSE for all other values.


```rebol
>> block? [1 2 3]
== #(true)

>> block? "1 2 3"
== #(false)

>> data: load "1 2 3"  ;  converts "1 2 3" into a block
== [1 2 3]
```

------------------------------------------------------------------
## BLUR

```rebol
img: load %same/image.png
blur img 5 ;; blurs the original image!
```

------------------------------------------------------------------
## BODY-OF
[[ reflect spec-of title-of types-of values-of words-of keys-of ]]

```rebol
>> body-of object [a: 1]
== [
    a: 1
]

>> body-of func[][1 + 1]
== [1 + 1]
```

------------------------------------------------------------------
## BREAK
[[ continue catch exit return loop repeat for forall foreach forever forskip while until ]]

The `break` function stops loop functions.

For example:


```rebol
repeat n 5 [
    print n
    if n > 2 [break]
]
1
2
3
```

The current loop is immediately terminated and evaluation resumes after the `repeat` function.


###### Return Value
The `break` /return refinement will return a value from a loop. It is commonly used to return a specific value or pass to a conditional expression when the loop is terminated early.

Here's an example:


```rebol
print repeat n 5 [
    if n > pi [break/return n]
    none
]
4
```

An example using `foreach` :


```rebol
values: [8:30 breakfast 12:00 lunch 5:00 dinner]
meal: foreach [time event] [
    if time > 14:00 [break/return event]
    none
]
probe meal
dinner
```


###### Important Scoping Rule
The `break` function acts immediately on the "closest block".

Although `break` can be placed anywhere within the block being repeated, even within a sub-block or function, because `break` is a function that is not directly bound to the loop, it will break the closest loop, not necessarily the intended loop. This does not affect most programs but could affect custom-made loop functions.

In this example, even though the `break` appears in the `repeat` loop, it applies to the a-loop `loop` block and has no effect on the outer `repeat` loop.


```rebol
a-loop: func [count block] [loop count block]
repeat a 3 [
    print a
    a-loop 4 [break]
]
1
2
3
```

------------------------------------------------------------------
## BROWSE

If the browser cannot be found, nothing will happen.

------------------------------------------------------------------
## CALL
[[ do launch ]]

The `call` function interfaces to the operating system's command shell to execute programs, shell commands, and redirect command input and output.

`call` is normally blocked by the security level specified with the `secure` function. To use it, you must change your `secure` settings or run the script with reduced security (at your own risk):


```rebol
secure call
```

The `call` function accepts one argument, which can be a string or a block specifying a shell command and its arguments. The following example shows a string as the `call` argument.


```rebol
call "cp source.txt dest.txt"
```

Use a block argument with `call` when you want to include REBOL values in the call to a shell command, as shown in the following example:


```rebol
source: %source.txt
dest: %dest.txt
call reduce ["cp" source dest]
```

The `call` function translates the file names in a block to the notation used by the shell. For example:


```rebol
[dir %/c/windows]
```

will convert the file name to windows shell syntax before doing it.

When shell commands are called, they normally run as a separate process in parallel with REBOL. They are asynchronous to REBOL. However, there are times when you want to wait for a shell command to finish, such as when you are executing multiple shell commands.

In addition, every shell command has a return code, which normally indicates the success or failure of the command. Typically, a shell command returns zero when it is successful and a non-zero value when it is unsuccessful.

The /wait refinement causes the `call` function to wait for a command's return code and return it to the REBOL program. You can then use the return code to verify that a command executed successfully, as shown in the following example:


```rebol
if zero? call/wait "dir" [
    print "worked"
]
```

In the above example, `call` successfully executes the Windows dir command, which is indicated by the zero return value. However, in the next example, `call` is unsuccessful at executing the xcopy command, which is indicated by the return value other than zero.


```rebol
if not zero? code: call/wait "xcopy" [
    print ["failed:" code]
]
```

In Windows and Unix (Linux), input to a shell command can be redirected from a file, URL, string, or port. By default, a shell command's output and errors are ignored by REBOL. However, shell command output and errors can be redirected to a file, URL, port, string, or the REBOL console.


```rebol
instr: "data"
outstr: copy ""
errstr: copy ""
call/input/output/error "sort" instr outstr errstr
print [outstr errstr]
```

See the REBOL Command Shell Interface documentation for more details.


Editor note: Proper link to the REBOL Command Shell Interface?

------------------------------------------------------------------
## CASE
[[ switch if either select find ]]

The `case` function provides a useful way to evaluate different expressions depending on specific conditions. It differs from the `switch` function because the conditions are evaluated and can be an expression of any length.

The basic form of `case` is:


```rebol
case [
    cond1 [code1]
    cond2 [code2]
    cond3 [code3]
]
```

The if a condition is true (that is, it is not false or none ) then the block that follows it is evaluated, otherwise the next condition is evaluated.


```rebol
num: 50
case [
    num < 10 [print "small"]
    num < 100 [print "medium"]
    num < 1000 [print "large"] 
]
medium
```

To create a default case, simply use true as your last condition:


```rebol
num: 10000
case [
    num < 10 [print "small"]
    num < 100 [print "medium"]
    num < 1000 [print "large"] 
    true [print "huge"]
]
huge
```


###### Return Value
The `case` function will return the value of the last expression it evaluated. This can come in handy:


```rebol
num: 50
value: case [
    num < 10 [num + 2]
    num < 100 [num / 2]
    true [0]
]
print value
25
```


###### Evaluating All
Normally the `case` function stops after the first true condition is found and its block evaluated. However, the /all option forces `case` to evaluate the expressions for all true conditions.


```rebol
num: 50
case/all [
    num < 10 [print "small"]
    num < 100 [print "medium"]
    num < 1000 [print "large"] 
]
medium
large
```

------------------------------------------------------------------
## CATCH
[[ throw do try ]]

`catch` and `throw` go together. They provide a way to exit from a block without evaluating the rest of the block.
To use it, provide `catch` with a block to evaluate. If within that block a `throw` is evaluated, it will return from the `catch` at that point.

The result of the `catch` will be whatever was passed as the argument to the `throw`.


```rebol
write %file.txt "i am a happy little file with no real purpose"
print catch [
    if exists? %file.txt [throw "Doc found"]
    "Doc not found"
]
Doc not found
```

When using multiple `catch` functions, provide them with a name using the /name refinement to identify which one will `catch` which `throw`.


Editor note: Example with /name

Editor note: Example of using catch in a function spec.

------------------------------------------------------------------
## CAUSE-ERROR

Editor note: Description is a stub.
`cause-error` constructs and immediately throws an `error!`.


Editor note: Link to concept of error types?

Editor note: Argument description is a stub.
The err-type argument controls the general type of error to construct, valid values are the words of the system/catalog/errors object. The err-id argument selects a specific error type within the err-type class of errors. The args argument is used to pass error-specific values


Editor note: Description of error IDs is a stub.
All information about the currently available error types can be found in system/catalog/errors:


```rebol
>> words-of system/catalog/errors
== [Throw Note Syntax Script Math Access Command resv700 User Internal]
```

The specific errors within a given class can be inspected similarly:


```rebol
>> ? system/catalog/errors/math        
SYSTEM/CATALOG/ERRORS/MATH is an object of value: 
   code            integer!  400 
   type            string!   "math error" 
   zero-divide     string!   "attempt to divide by zero" 
   overflow        string!   "math or number overflow" 
   positive        string!   "positive number required"
```

All words except for code and type within an error type are possible specific errors. Their associated value is part of the error message that will displayed to the user if the error remains unhandled.

Some errors take arguments:


```rebol
>> ? system/catalog/errors/script/no-value   
SYSTEM/CATALOG/ERRORS/SCRIPT/NO-VALUE is a block of value: [:arg1 "has no value"]
```

As an example, this no-value error which takes a single argument can be caused as follows:


```rebol
>> cause-error 'script 'no-value 'Foo  
** script error: Foo has no value
```

Similarly, the two-argument no-arg error can be caused as follows:


```rebol
>> cause-error 'script 'no-arg [Foo bar] 
** script error: Foo is missing its bar argument
```

------------------------------------------------------------------
## CD
[[ change-dir delete ls list-dir make-dir mkdir pwd rm what-dir ]]

Variant of `change-dir` for shell use. Supports inputting words as directory names:


```rebol
cd ..
cd somewhere
```

------------------------------------------------------------------
## CHANGE
[[ append clear insert remove sort ]]

The `change` function modifies any type of [series](https://www.rebol.com/r3/docs/concepts/series.html), such as a `string!` or `block!`, at its current index position.

It has many variations, but let's take a simple example that modifies a `string!` series:


```rebol
name: "bog"
change name "d"
probe name
"dog"

change next name "i"
probe name
"dig"

change tail name "it"
probe name
"digit"
```

Here is an example that changes a `block!` series:


```rebol
colors: [red green blue]
change colors 'gold
probe colors
[gold green blue]

change at colors 3 [silver orange teal]
probe colors
[gold green silver orange teal]
```

As you can see, if the second argument is a single value, it will
replace the value at the current position in the first
series. However, if the second argument is a series compatible
with the first (block or string-based datatype), all of 
its values will replace those of the first argument or
series.


###### Result
<b>Be sure to note that <a href="#change">change</a> returns the series position just past the modification.</b>

This allows you to cascade multiple changes.

For example:


```rebol
test: "abcde"
change change test "1" "23"
probe test
"123de"
```

So, you must use `head` if you need the string at its starting position:


```rebol
probe head change "bog" "d"
"dog"

probe head change [1 4 5] [1 2 3]
[1 2 3]

probe head change [123 "test"] "the"
["the" "test"]
```


###### Partial changes
The /PART refinement changes a specified number of elements within the target series.

In this line, the 2 indicates that the "ab" are both replaced with the new string, "123":


```rebol
probe head change/part "abcde" "123" 2
"123cde"
```


###### Duplication

```rebol
probe head change/dup "abc" "->" 5
"->->->->->"
```


Editor note: This section is new or has has recently changed and is still under construction.

```rebol
title: copy "how it REBOL"
change title "N"
probe title
"Now it REBOL"

change find title "t" "s"
probe title
"Now is REBOL"

blk: copy ["now" 12:34 "REBOL"]
change next blk "is"
probe blk
["now" "is" "REBOL"]

probe head change/only [1 4 5] [1 2 3]
[[1 2 3] 4 5]

probe head change/only [1 4 5] [[1 2 3]]
[[[1 2 3]] 4 5]

string: copy "crush those grapes"
change/part string "eat" find/tail string "crush"
probe string
"eat those grapes"
```

------------------------------------------------------------------
## CHANGE-DIR
[[ make-dir what-dir list-dir ]]

Changes the value of system/script/path. This value is used for file-related operations. Any file path that does not begin with a slash (/) will be relative to the path in system/script/path. When a script file is executed using the `do` native, the path will automatically be set to the directory containing the path. When REBOL starts, it is set to the current directory where REBOL is started.


```rebol
current: what-dir
make-dir %./rebol-temp/
probe current
%/C/REBOL/3.0/docs/scripts/

change-dir %./rebol-temp/
probe what-dir
%/C/REBOL/3.0/docs/scripts/rebol-temp/

change-dir current
delete %./rebol-temp/
probe what-dir
%/C/REBOL/3.0/docs/scripts/
```

Note that the shorter shell friendly `cd` also exists.

------------------------------------------------------------------
## CHAR?
[[ type? ]]

Returns FALSE for all other values.


```rebol
>> char? #"1"
== #(true)

>> char? 1
== #(false)
```

------------------------------------------------------------------
## CHARSET
[[ complement char? ]]

The `charset` function is a shortcut for:
```rebol
make bitset! value
```

It is used often for character based bitsets.
```rebol
chars: charset "aeiou"
print find chars "o"
true

print find "there you go" chars
ere you go

digits: charset "0123456789"
area-code: ["(" 3 digits ")"]
phone-num: [3 digits "-" 4 digits]
print parse "(707)467-8000" [[area-code | none] phone-num]
true
```

------------------------------------------------------------------
## CHECK
------------------------------------------------------------------
## CHECKSUM
[[ string? any-string? ]]

Generally, a checksum is a number which accompanies data to verify that the data has not changed (did not have 
errors).

Available checksum method may differ between Rebol versions. What is available can be found in "system/catalog/checksums"

```rebol
>> data: "foo" foreach method system/catalog/checksums [print [pad method 10  mold/flat checksum data method]]
adler32    42074437
crc24      5804686
crc32      -1938594527
md4        #{0AC6700C491D70FB8650940B1CA1E4B2}
md5        #{ACBD18DB4CC2F85CEDEF654FCCC4A4D8}
ripemd160  #{42CFA211018EA492FDEE45AC637B7972A0AD6873}
sha1       #{0BEEC7B5EA3F0FDBC95D0DD47F3C5BC275DA8A33}
sha224     #{0808F64E60D58979FCB676C96EC938270DEA42445AEEFCD3A4E6F8DB}
sha256     #{2C26B46B68FFC68FF99B453C1D30413413422D706483BFA0F98A5E886266E7AE}
sha384     #{98C11FFDFDD540676B1A137CB1A22B2A70350C9A44171D6B1180C6BE5CBB2EE3F79D532C8A1DD9EF2E8E08E752A3BABB}
sha512     #{F7FBBA6E0636F890E56FBBF3283E524C6FA3204AE298382D624741D0DC6638326E282C41BE5E4254D8820772C5518A2C5A8C0C7F7EDA19594A7EB539453E1ED7}
sha3-224   #{F4F6779E153C391BBD29C95E72B0708E39D9166C7CEA51D1F10EF58A}
sha3-256   #{76D3BC41C9F588F7FCD0D5BF4718F8F84B1C41B20882703100B9EB9413807C01}
sha3-384   #{665551928D13B7D84EE02734502B018D896A0FB87EED5ADB4C87BA91BBD6489410E11B0FBCC06ED7D0EBAD559E5D3BB5}
sha3-512   #{4BCA2B137EDC580FE50A88983EF860EBACA36C857B1F492839D6D7392452A63C82CBEBC68E3B70A2A1480B4BB5D437A7CBA6ECF9D89F9FF3CCD14CD6146EA7E7}
xxh3       #{AB6E5F64077E7D8A}
xxh32      #{E20F0DD9}
xxh64      #{33BF00A859C4BA3F}
xxh128     #{79AEF92E83454121AB6E5F64077E7D8A}
tcp        39201
```

------------------------------------------------------------------
## CLEAN-PATH
[[ split-path change-dir dir? list-dir to-real-file ]]

Rebuilds a directory path after decoding parent (..) and
current (.) path indicators.

```rebol
>> clean-path %com/www/../../../graphics/image.jpg
== %/C/REBOL/3.0/docs/graphics/image.jpg

>> messy-path: %/rebol/scripts/neat-stuff/../../experiments/./tests
== %/rebol/scripts/neat-stuff/../../experiments/./tests

>> neat-path: clean-path messy-path
== %/rebol/experiments/tests
```

URLs are returned unmodified (because the true paths may not
be known).

------------------------------------------------------------------
## CLEAR
[[ remove append change insert sort ]]

`clear` is similar to `remove` but removes through the end of the series rather than just a single value. It returns at the current index position in the series.


```rebol
str: copy "with all things considered"
clear skip str 8
print str
with all

str: copy "get there quickly"
clear find str "qui"
print str
get there

head clear find %file.txt %.txt
%file
```

------------------------------------------------------------------
## CLEAR-THRU
------------------------------------------------------------------
## CLOS
------------------------------------------------------------------
## CLOSE
[[ open load do ]]

Closes a port opened earlier with the `open` function. Any changes to the port data that have been buffered will be written.


```rebol
port: open %test-file.txt
insert port "Date: "
insert port form now
insert port newline
close port

print read %test-file.txt
read
```

------------------------------------------------------------------
## CLOSURE
[[ closure? does func function has ]]

A closure is a special type of function that has persistent variables.

With a closure you can write a block inside the closure body and the block will remain persistent:


```rebol
add2: closure [c d] [[c + d]]
do add2 1 2
3
```

This works because the variables of a closure remain valid, even outside the closure after it has been called. Such variables have indefinite extent. They are not limited to the lifetime of the function.

Note, however, that this luxury provided by closures is not without its costs. Closures require more time to evaluate as well as more memory space.

In essence a closure is an object. When you define the closure, it constructs a prototype object, and each time you call the closure, the prototype object is instantiated and the body code is evaluated within that context.

More about closures [here](http://www.rebol.net/wiki/Closures).

More about the benefits and costs of closures [here](http://www.rebol.net/wiki/R2_vs._R3_Contexts).

------------------------------------------------------------------
## CLOSURE?
[[ function? ]]

Returns true if the input is a `closure!`


```rebol
>> closure? make closure! [[][]]
== #(true)
```

Editor note: Are there better examples?

------------------------------------------------------------------
## COLLECT

Using the internal keep function, will collect values spread around a block to be stored in another block and returned:
```rebol
>> collect [keep 1 2 3 keep 4]
== [1 4]
```

Can also be used with the `parse` function:
```rebol
>> collect [
    parse [a b c d e] [
        any ['c | 'e | set w word! (keep w)]
    ]
]
== [a b d]
```

Blocks are collected and appended to the output as a series of values:
```rebol
>> collect [keep 1 keep [2 3]]
== [1 2 3]
```

The keep function has a refinement /only to append blocks as blocks to the output:
```rebol
>> collect [keep 1 keep/only [2 3]]
== [1 [2 3]]
```

------------------------------------------------------------------
## COLLECT-WORDS

```rebol
>> collect-words [a: 1 + b]
== [a + b]

>> collect-words/set [a: 1 + b]
== [a]

>> collect-words/set/as [a: 1 + b] set-word!
== [a:]
```

------------------------------------------------------------------
## COLOR-DISTANCE

```rebol
>> color-distance 0.0.0 0.0.0
== 0.0

>> color-distance 0.0.0 255.0.0
== 402.874670338059

>> color-distance 0.0.0 255.255.0
== 649.929226916285

>> color-distance 0.0.0 255.255.255
== 764.833315173967
```

------------------------------------------------------------------
## COMBINE
------------------------------------------------------------------
## COMMAND?
------------------------------------------------------------------
## COMMENT
[[ do ]]

This function can be used to add comments to a script or to remove a block from evaluation. Note that this function is only effective in evaluated code and has no effect in data blocks. That is, within a data block comments will appear as data. In many cases, using `comment` is not necessary. Placing braces around any expression will prevent if from being evaluated (so long as it is not part of another expression).


```rebol
comment "This is a comment."

comment [print "As a comment, this is not printed"]
```

Note also that if the expression can't be loaded using `load`, the expression can't be commented out:


```rebol
comment [a,b]
** Syntax error: invalid "word" -- "a,b"
** Near: (line 1) comment [a,b]
```

------------------------------------------------------------------
## COMPLEMENT
[[ negate not and or xor charset ]]

The `complement` function is used for bit-masking `integer!` and `tuple!` values or inverting `bitset!` values (charsets).


```rebol
complement 0
-1

complement -1
0

complement 0.255.0
255.0.255

chars: complement charset "ther "
find "there it goes" chars
it goes
```

------------------------------------------------------------------
## COMPLEMENT?
------------------------------------------------------------------
## COMPOSE
[[ reduce append repend rejoin insert ]]

The `compose` function builds a block of values, evaluating `paren!` expressions and inserting their results. It is a very useful method of building new blocks.


```rebol
compose [result of 1 + 2 = (1 + 2)]
[result of 1 + 2 = 3]
```

Notice that only the `paren!` expression is evaluated. All other values are left unchanged.

Here's another example, as might be used to create a header block (that has field names):


```rebol
compose [time: (now/time) date: (now/date)]
[time: 17:47:13 date: 12-Feb-2009]
```


###### Sub-Blocks
If the result of an expression is a block, then the elements of that block are inserted into the output block:


```rebol
colors: ["red" "green" "blue"]
compose [1 2 3 (colors)]
[1 2 3 "red" "green" "blue"]
```

If you want to insert the actual block, rather than its elements, there are a couple ways to do so. You can use the /only refinement:


```rebol
colors: ["red" "green" "blue"]
compose/only [1 2 3 (colors)]
[1 2 3 ["red" "green" "blue"]]
```

Or, you can add a `reduce` to put the block within another block:


```rebol
colors: ["red" "green" "blue"]
compose [1 2 3 (reduce [colors])]
[1 2 3 ["red" "green" "blue"]]
```


###### Evaluating All Parens
To evaluate all paren expressions, regardless of how deep the are nested within blocks, use the /deep refinement:


```rebol
compose/deep [1 [2 [(1 + 2) 4]]]
[1 [2 [3 4]]]
```

You can use /deep and /only together:


```rebol
colors: ["red" "green" "blue"]
compose [1 2 3 [4 (colors)]]
[1 2 3 [4 "red" "green" "blue"]]
```


###### Memory usage for large blocks
For most blocks you don't need to worry about memory because REBOL's automatic storage manager will efficiently handle it; however, when building large block series with `compose`, you can manage memory even more carefully.

For example, you might write:


```rebol
append series compose [a (b) (c)]
```

The word a and the evaluated results of b and c are appended to the series.

If this is done a lot, a large number of temporary series are generated, which take memory and also must be garbage collected later.

The /into refinement helps optimize the situation:


```rebol
compose/into [a (b) (c)] tail series
```

It requires no intermediate storage.

------------------------------------------------------------------
## COMPRESS
[[ decompress ]]

Editor note: Describe the method that compress uses to compress data

```rebol
print compress "now is the dawning"
#{789CCBCB2F57C82C5628C9485548492CCFCBCC4B07003EB606BA12000000}

string: form first system/words
print length? string
8329

small: compress string
print length? small
3947
```

As with all compressed files, keep an uncompressed copy of the original data file as a backup.

------------------------------------------------------------------
## CONFIRM
[[ ask input prin ]]

This function provides a method of prompting the user for a true ("y" or "yes") or false ("n" or "no") response. Alternate responses can be identified with the /with refinement.


```rebol
confirm "Answer: 14. Y or N? "

confirm/with "Use A or B? " ["A" "B"]
```

------------------------------------------------------------------
## CONSTRUCT
[[ make context ]]

This function creates new objects but without evaluating the object's specification (as is done in the `make` and `context` functions).

When you `construct` an object, only literal types are accepted. Functional evaluation is not performed. This allows your code to directly import objects (such as those sent from unsafe external sources such as email, cgi, etc.) without concern that they may include "hidden" side effects using executable code.

`construct` is used in the same way as the `context` function:


```rebol
obj: construct [
    name: "Fred"
    age: 27
    city: "Ukiah"
]
probe obj
make object! [
    name: "Fred"
    age: 27
    city: "Ukiah"
]
```

But, very limited evaluation takes place.  That means object specifications like:


```rebol
obj: construct [
    name: uppercase "Fred"
    age: 20 + 7
    time: now
]
probe obj
make object! [
    name: 'uppercase
    age: 20
    time: 'now
]
```

do not produce evaluated results.

Except with the /only refinement, the `construct` function does perform evaluation on the words true, on, yes, false, off, no and none to produce their expected values. Literal words and paths will also be evaluated to produce their respective words and paths.  For example:


```rebol
obj: construct [
    a: yes
    b: none
    c: 'word
]
probe obj
make object! [
    a: true
    b: none
    c: word
]

type? obj/a
logic!

type? obj/c
word!
```

The `construct` function is useful for importing external objects, such as preference settings from a file, CGI query responses, encoded email, etc.

To provide a template object that contains default variable values (similar to `make`), use the /with refinement. The example below would use an existing object called standard-prefs as the template.


```rebol
prefs: construct/with load %prefs.r standard-prefs
```

------------------------------------------------------------------
## CONTEXT
[[ make ]]

This function creates a unique new object. It is just a shortcut for `make` `object!`.


```rebol
person: context [
    name: "Fred"
    age: 24
    birthday: 20-Jan-1986
    language: "REBOL"
]
probe person
make object! [
    name: "Fred"
    age: 24
    birthday: 20-Jan-1986
    language: "REBOL"
]

person2: make person [
    name "Bob"
]
probe person2
make object! [
    name: "Bob"
    age: 24
    birthday: 20-Jan-1986
    language: "REBOL"
]
```

------------------------------------------------------------------
## CONTEXT?
------------------------------------------------------------------
## CONTINUE
[[ break catch exit return loop repeat for forall foreach forever forskip while until ]]

The `continue` function is the opposite of `break`. It jumps back to the top of the loop instead of exiting the loop.

For example:


```rebol
repeat n 5 [
    if n < 3 [continue]
    print n
]
3
4
5
```

------------------------------------------------------------------
## COPY
[[ make form mold join ajoin rejoin ]]

The `copy` function will copy any [series](https://www.rebol.com/r3/docs/concepts/series.html), such as `string!` or `block!`, and most other compound datatypes such as `object!` or `function!`. It is not used for immediate datatypes, such as `integer!`, `decimal!`, `time!`, `date!`, and others.


```html
<fieldset class="fset"><legend>How it Works</legend>
<p>It is important to understand <a href="#copy">copy</a> to program in REBOL properly.</p>
<p>To save memory, all strings, blocks, and other <a href="/r3/docs/concepts/series.html" class="con">series</a> are accessed by reference (e.g. as pointers.) If you need to modify a series, and you do not want it to change in other locations, you must use <a href="#copy">copy</a> first.</p>
<p>Note that some functions, such as <a href="#join">join</a> and <a href="#rejoin">rejoin</a>, will copy automatically. That's because they are constructing new values.</p>
</fieldset>
```

This example shows what happens if you don't copy:


```rebol
name: "Tesla"
print name
Tesla

name2: name
insert name2 "Nicola "
print name2
Nicola Tesla

print name
Nicola Tesla
```

That's because, it's the same string:


```rebol
same? name name2
true
```

Here's the example using `copy` for the second string:


```rebol
name: "Tesla"
print name
Tesla

name2: copy name
insert name2 "Nicola "
print name2
Nicola Tesla

print name
Tesla

same? name name2
false
```

The same behavior is also true for blocks. This example shows various results:


```rebol
block1: [1 2 3]
block2: block1
block3: copy block1
append block1 4
append block2 5
append block4 6
probe block1
[1 2 3 4 5]

probe block2
[1 2 3 4 5]

probe block3
[1 2 3 6]
```

There will be times in your code where you'll want to `append` to or `insert` in a string or other series. You will need to think about what result you desire.

Compare this example:


```rebol
str1: "Nicola"
str2: append str1 " Tesla"
print str1
Nicola Tesla

print str2
Nicola Tesla
```

with this example that uses the `copy` function:


```rebol
str1: "Nicola"
str2: append copy str1 " Tesla"
print str1
Nicola

print str2
Nicola Tesla
```


###### Copy Part
It is fairly common to copy just a sub-string or sub-block. To do so, use the /part refinement. The length of the result is determined by an integer size or by the ending position location.


```rebol
name: "Nicola Tesla"
copy/part name 6
"Nicola"

copy/part skip name 7 5
"Tesla"

copy/part find name "Tesla" tail name
"Tesla"
```

Notice that the ending position can be a length or a position within the string (as shown by the `tail` example above.)


####### About Substrings
If you use other languages, you will notice that this result is similar to what a substr function provides. Although we recommend using `copy` with /part, you can easily define your own substr function this way:


```rebol
substr: func [arg [series!] start length] [
    copy/part skip arg start length
]
```

For example:


```rebol
substr "string example" 7 7
"example"
```

We should explain why we don't normally define a substr function. Most of the time when you're extracting substrings, you are either using a function like `find` or you're using a loop of some kind. Therefore, you don't really care about the starting offset of a string, you only care about the current location.

For example:


```rebol
str: "This is an example string."
str2: copy/part find str "ex" 7
```

And, in fact, it's common to write use two `find` functions in this way:


```rebol
start: find str "ex"
end: find start "le"
str2: copy/part start end
```

which advanced users often write in one line this way:


```rebol
str2: copy/part s: find str "ex" find s "le"
```

Of course, if the string might not be found, this is a helpful pattern to use:


```rebol
str2: all [
    start: find str "ex"
    end: find start "le"
    copy/part start end
]
```

If the start or end are not found, then str2 is set to none.

Here's an example of a simple loop that finds substrings:


```rebol
str: "this example is an example"
pat: "example"
while [str: find str pat] [
    print copy/part str length? pat
    str: skip str length? pat
]
```


###### Copy Deep
When copying blocks, keep in mind that simple use of the `copy` function does not make copies of series values within a block.

Notice that the `copy` here does not copy the name string:


```rebol
person1: ["Tesla" 10-July-1856 Serbian]
person2: copy person1
insert person/2 "Nicola "
probe person1
["Nicola Tesla" 10-July-1856 Serbian]
```

If you need to copy both the block and all series values within it, use `copy` with the /deep refinement:


```rebol
person1: ["Tesla" 10-July-1856 Serbian]
person2: copy/deep person1
insert person/2 "Nicola "
probe person1
["Tesla" 10-July-1856 Serbian]

probe person2
["Nicola Tesla" 10-July-1856 Serbian]
```

Here both the block and the string are separate series.

Also be aware that if your block contains other blocks, they will be deep copied as well, including all strings and other series within them.

If you want to deep copy only a specific datatype, such as just strings or just blocks, you can use the /types refinement.

Here are a few examples of its usage:


```rebol
copy/deep/types block string!
copy/deep/types block any-string!
copy/deep/types block make typeset! [string! url! file!]
```


###### Copy Objects
If you use `copy` on an object, a copy of the object is returned. This can be useful when objects are used only as simple storage structures. Note that rebinding is not done; therefore, do not use `copy` on objects when that is required.


###### Helpful Hint
To see a list of functions that modify their series (not copy), type this line:


```rebol
? modifies
Found these related words:
alter           function! If a value is not found in a series, append i...
append          action!   Inserts a value at tail of series and returns...
bind            native!   Binds words to the specified context. (Modifi...
change          action!   Changes a value in a series and returns the s...
clear           action!   Removes all values. For series, removes from ...
decloak         native!   Decodes a binary string scrambled previously ...
deline          native!   Converts string terminators to standard forma...
detab           native!   Converts tabs in a string to spaces (default ...
encloak         native!   Scrambles a binary string based on a key. (Mo...
enline          native!   Converts standard string terminators to curre...
entab           native!   Converts spaces in a string to tabs (default ...
insert          action!   Inserts into a series and returns the series ...
lowercase       native!   Converts string of characters to lowercase. (...
...
```

------------------------------------------------------------------
## COS
------------------------------------------------------------------
## COSINE
[[ arccosine arcsine arctangent sine tangent ]]

Ratio between the length of the adjacent side to
the length of the hypotenuse of a right triangle.


```rebol
print cosine 90
0.0

print (cosine 45) = (sine 45)
true

print cosine/radians pi
-1.0
```

------------------------------------------------------------------
## CREATE

Creates the file or URL object that is specified.


```rebol
create %testfile.txt
read %./
[%testfile.txt]
```

------------------------------------------------------------------
## CURSOR

This only works in a View window.


```rebol
cursor 1
cursor 2
cursor 3
cursor 4
cursor 5
cursor 6
```


Editor note: Describe all cursors here
------------------------------------------------------------------
## DATATYPE?

Returns false for all other values.


```rebol
print datatype? integer!
true

print datatype? 1234
false
```

------------------------------------------------------------------
## DATE?
[[ type? ]]

Returns false for all other values.


```rebol
print date? 1/3/69
true

print date? 12:39
false
```

------------------------------------------------------------------
## DEBASE
[[ enbase dehex ]]

Converts from an encoded string to the binary value. Primarily used for BASE-64 decoding.


```rebol
>> debase "MTIzNA==" 64
== #{31323334}

>> debase "12AB C456" 16
== #{12ABC456}

>> enbased: enbase "a string of text" 64
== "YSBzdHJpbmcgb2YgdGV4dA=="

>> string? enbased            ;; enbased value is a string
== #(true)

>> debased: debase enbased 64 ;; converts to binary value
== #{6120737472696E67206F662074657874}

>> to string! debased   ;; converts back to original string
== "a string of text"        
```

If the input value cannot be decoded (such as when the proper number of characters is missing), an 'invalid-data error is thrown. This behavior is different from Rebol2, where none is returned.

```rebol
>> debase "AA" 16
== #{AA}

>> debase "A" 16

** Script error: data not in correct format: "A"
```

------------------------------------------------------------------
## DECIMAL?
[[ number? type? ]]

Returns false for all other values.


```rebol
>> decimal? 1.2
== #(true)

>> decimal? 1
== #(false)
```

------------------------------------------------------------------
## DECLOAK
[[ encloak ]]

`decloak` is a low strength decryption method that is used with `encloak`. See the `encloak` function for a complete description and examples.

------------------------------------------------------------------
## DECODE
[[ encode load enbase debase ]]

Used to call codecs to decode binary data (bytes) into related datatypes.

Codecs are identified by words that symbolize their types. For example the word png is used to identify the PNG codec.

See the system/codecs for a list of loaded codecs. Codecs can be native (built-in), externally loaded, or even coded in REBOL.

[More about Encode and Decode](http://www.rebol.net/cgi-bin/r3blog.r?view=0184)


###### Examples
The line:


```rebol
image: load %photo.jpg
```

is roughly equivalent to:


```rebol
data: read %photo.jpg  ; returns binary data
image: decode 'jpeg data
```

------------------------------------------------------------------
## DECODE-URL

This is a handy function that saves you the effort of writing
your own URL parser.


```rebol
probe decode-url http://user:pass@www.rebol.com/file.txt
[scheme: 'http pass: "pass" user: "user" host: "www.rebol.com" path: "/file.txt"]
```

------------------------------------------------------------------
## DECOMPRESS
[[ compress enbase debase ]]

Examples:


```rebol
write %file.txt read http://www.rebol.net
size? %file.txt
5539

save %file.comp compress read %file.txt
size? %file.comp
2119

write %file.decomp decompress load %file.comp
size? %file.decomp
5539
```

If the data passed to the `decompress` function has been altered or corrupted, a decompression error will occur.

A typical error is out of memory, if the decompressed file length appears to be wrong (perhaps several gigabytes instead of 5539 bytes) to `decompress`.

Using the /limit refinement, puts a hard limit to the size of the decompressed file:


```rebol
decompress/limit read %file.comp 5000
** Script error: maximum limit reached: 5539
** Where: decompress
** Near: decompress/limit read %file.comp 5000
```

This can help avoiding that a decompress operation on a corrupt file suddenly eats all system resources.


###### Special Notes
`decompress` can decompress any ZLIB data as long as the data has the length of the uncompressed data in binary little-endian representation appended:


```rebol
zlib-decompress: func [
    zlib-data [binary!]
    length [integer!] "known uncompressed zlib data length"
][
    decompress head insert tail zlib-data third make struct! [value [integer!]] reduce [length]
]
```

------------------------------------------------------------------
## DEDUPLICATE
------------------------------------------------------------------
## DEFAULT
[[ value? any all ]]

The `default` function is a clear way to indicate that you want a variable set to a default value if it's not already been set.

For example:


```rebol
default size 100
```

would set size to 100 if it's not already been set to some other value.

You can think of `default` as a shortcut for `any` when used like this:


```rebol
size: any [size 100]
```

However, `default` avoids the need to specify the size word twice and also makes the intention of your code more clear. It's quite often used for global configuration variables that may or may not have been set by prior code.

------------------------------------------------------------------
## DEHEX
[[ enhex ]]

Converts the standard URL hex sequence that begins with a % followed by a valid hex value. Otherwise, the sequence  is not converted and will appear as written.


```rebol
>> dehex "a%20b"
== "a b"

>> dehex/uri "a+b"
== "a b"

>> dehex/escape "a#20b" #"#"
== "a b"
```

------------------------------------------------------------------
## DELECT
[[ parse ]]

DELECT stands for DEcode diaLECT. It is used to implement REBOL's internal dialects such as DRAW, EFFECT, RICH TEXT, SECURE, and VID, but its function is available to all users.

This is used for parsing unordered dialects. In unordered dialects, the order of arguments is less important than their type.

Here's a simple example. First the dialect is specified as a context:


```rebol
dialect: context [
    default: [tuple!]
    single: [string!]
    double: [integer! string!]
]
```

Then an input and output block is specified. The input block contains the data to parse. The output block stores the result:


```rebol
inp: [1.2.3 single "test" double "test" 123]
out: make block! 4  ; (any initial size works)
```

Now the input is processed using `delect`, one step at a time:


```rebol
while [inp: delect dialect inp out] [
  ?? out
  ?? inp
]
```

To read more about `delect`, see [here](http://rebol.net/wiki/Delect).

------------------------------------------------------------------
## DELETE
[[ create exists? ]]

Deletes the file or URL object that is specified. If the file or URL refers to an empty directory, then the directory will be deleted.


```rebol
write %delete-test.r "This file is no longer needed."
delete %delete-test.r
write
```

------------------------------------------------------------------
## DELETE-DIR
------------------------------------------------------------------
## DELETE-THRU
------------------------------------------------------------------
## DELINE
[[ enline read ]]

Useful for converting OS dependent string terminators to LF.

CRLF string termination:
```rebol
>> deline "a^M^/b" ; Windows, DOS, CP/M, OS/2, Symbian
== "a^/b"
```

CR string termination:
```rebol
>> deline "a^Mb" ; MacOS 1-9
== "a^/b"
```

LF string termination:
```rebol
>> deline "a^/b" ; MacOSX, AmigaOS, FreeBSD, GNU/Linux, BeOS, RiscOS
== "a^/b"
```

When using the /LINES refinement, the string will be split in blocks of strings per line:
```rebol
>> deline/lines "a^M^/b"
== [
    "a"
    "b"
]
```

Note that when reading from disk, READ/STRING provides the same functionality.
```rebol
>> write %test.txt ajoin ["a" CRLF "b"]
== %test.txt

>> read/string %test.txt
== "a^/b"

>> to string! read %test.txt
== "a^M^/b"
```

------------------------------------------------------------------
## DELTA-PROFILE
[[ delta-time dp dt ]]

Provides detailed profiling information captured during the evaluation of a block.

See [Profiler](http://www.rebol.net/wiki/Profiler) for detailed examples.

Simple example:


```rebol
>> dp [loop 10 [next "a"]]
== make object! [
    timer: 39
    evals: 31
    eval-natives: 14
    eval-functions: 1
    series-made: 1
    series-freed: 0
    series-expanded: 0
    series-bytes: 432
    series-recycled: 0
    made-blocks: 1
    made-objects: 0
    recycles: 0
]
```

------------------------------------------------------------------
## DELTA-TIME
[[ delta-profile dt dp ]]

Returns the amount of time required to evaluate a given block.

Example:


```rebol
>> dt [loop 1000000 [next "a"]]
0:00:00.25
```

See [Profiler](http://www.rebol.net/wiki/Profiler) for detailed information about timing and profiling.

------------------------------------------------------------------
## DETAB
[[ entab ]]

The REBOL language default tab size is four spaces. `detab` will remove tabs from the entire string even beyond the first non-space character.

The series passed to this function is modified as a result.


```rebol
text: "^-lots^-^-of^-^-tabs^-^-^-^-here"
print detab copy text
    lots        of      tabs                here
```

Use the /size refinement for other sizes such as eight:


```rebol
print detab/size text 8
        lots            of              tabs                            here
```

------------------------------------------------------------------
## DH
------------------------------------------------------------------
## DH-INIT
------------------------------------------------------------------
## DIFFERENCE
[[ intersect union exclude unique ]]

Returns the elements of two series that are not present in both. Both series arguments must be of the same datatype (string, block, etc.) Newer versions of REBOL also let you use `difference` to compute the difference between date/times.


```rebol
lunch: [ham cheese bread carrot]
dinner: [ham salad carrot rice]
probe difference lunch dinner
[cheese bread salad rice]

probe difference [1 3 2 4] [3 5 4 6]
[1 2 5 6]

string1: "CBAD"    ; A B C D scrambled
string2: "EDCF"    ; C D E F scrambled
probe difference string1 string2
"BAEF"
```

Date differences produce a time in hours:


```rebol
probe difference 1-Jan-2002/0:00 1-Feb-2002/0:00
-744:00

probe difference 1-Jan-2003/10:30 now
-59449:55:14
```

This is different from when using `subtract`, which returns the difference in days:


```rebol
probe subtract 1-Jan-2002/0:00 1-Feb-2002/0:00
-31

probe subtract 1-Jan-2003/10:30 now
-2477
```

There is a limit to the time period that can be differenced between dates (determined by the internal size of the `time!` datatype).

Note that performing this function over very large data sets can be CPU intensive.

------------------------------------------------------------------
## DIR
------------------------------------------------------------------
## DIR?
[[ make-dir modified? exists? ]]

```html
<fieldset class="fset"><legend>Under Review</legend>
<p>This function is under review for redefinition.</p>
</fieldset>
```

Returns false if it is not a directory.


```rebol
print dir? %file.txt
false

print dir? %.
true
```

Note that the file that is input, is read from disk, if it exists. The function returns true, when the input either ends in / or if the name exists on disk as a directory.

------------------------------------------------------------------
## DIR-TREE
------------------------------------------------------------------
## DIRIZE

Convert a file name to a directory name.

For example:


```rebol
probe dirize %dir
%dir/
```

It is useful in cases where paths are used:


```rebol
dir: %files/examples
new-dir: dirize dir/new-code
probe new-dir
%files/examples/new-code/
```

This is useful because the PATH notation does not allow you to write:


```rebol
new-dir: dirize dir/new-code/
```

------------------------------------------------------------------
## DIVIDE
[[ / // multiply ]]

If the second value is zero, an error will occur.

Examples:


```rebol
print divide 123.1 12
10.25833333333333

print divide 10:00 4
2:30
```

When dividing values of different datatypes, they must be compatible:


```rebol
divide 4x5 $2.7
** Script error: incompatible argument for divide of pair!
** Where: divide
** Near: divide 4x5 $2.7
```

------------------------------------------------------------------
## DO
[[ reduce load import loop repeat call launch ]]

The `do` function evaluates a script file or a series of expressions and returns a result.

It performs the fundamental interpretive action of the REBOL language and is used internally within many other functions such as `if`, `case`, `while`, `loop`, `repeat`, `foreach`, and others.


###### Most Common Use
Most of the time `do` is used to evaluate a script from a `file!` or `url!` as shown in these examples:


```rebol
do %setup.r
Settings done.

do http://www.rebol.com/speed.r
Console:   0:00:01.609 - 314 KC/S
Processor: 0:00:00.406 - 2128 RHz (REBOL-Hertz)
Memory:    0:00:00.657 - 72 MB/S
Disk/File: 0:00:00.234 - 130 MB/S
```

Note that `do` of a `file!` or `url!` requires that the script contain a valid REBOL header; otherwise, you'll get an "Script is missing a REBOL header" error.


```html
<fieldset class="fset"><legend>Warning</legend>
<p>Only <a href="#do">do</a> a <span class="datatype">url!</span> script that you have reason to trust. It is advised that you <a href="#read">read</a> a script first and examine it closely to make sure it is safe to evaluate.</p>
</fieldset>
```


###### Other Uses
The `do` function can also be called to evaluate other types of arguments such as a `block!`, `path!`, `string!`, or `function!`.


```rebol
do [1 + 2]
3

do "1 + 2"  ; see special note below
3
```

Expressions are evaluated left to right and the final result is returned. For example:


```rebol
do [1 + 2 3 * 4]
12
```

To obtain all results, use the `reduce` function instead.


```rebol
print reduce [1 + 2 3 * 4]
3 12
```


###### Other Examples
Selecting a block to evaluate:


```rebol
blk: [
    [print "test"]
    [loop 3 [print "loop"]]
]
do first blk
test

do second blk
loop
loop
loop
```


###### Refinements
The /args refinement allows you to pass arguments to another script and is used with a file, or URL.  Arguments passed with /args are stored in system/script/args within the context of the loaded script.

The /next refinement returns a block consisting of two elements. The first element is the evaluated return of the first expression encountered. The second element is the original block with the current index placed after  the last evaluated expression.


###### Special Notes
Evaluating strings is much slower than evaluating blocks and values. That's because REBOL is a symbolic language, not a string language. It is considered bad practice to convert values to strings and join them together to pass to `do` for evaluation. This can be done directly without strings.

For example, writing code like this is a poor practice:


```rebol
str: "1234 + "
code: join str "10"
do code
1244
```

Instead, just use:


```rebol
blk: [1234 +]
code: join blk 10
do code
1244
```

In other words, you can `join` values in blocks just as easily as strings.

------------------------------------------------------------------
## DO-CALLBACK
------------------------------------------------------------------
## DO-CODEC
[[ decode encode ]]

This is an internal native function used to call codecs. It is normally called by the `encode` and `decode` functions.

See the system/catalog/codecs for a list of loaded codecs. Codecs can be native (built-in), externally loaded, or coded in REBOL.

------------------------------------------------------------------
## DO-COMMANDS
[[ do reduce ]]

High speed `command!` block evaluation for [extensions](https://www.rebol.com/r3/docs/concepts/extensions.html).

Originally created to evaluate [graphics rendering commands](%r3/docs/view/draw.html), it can be used for any external sequence of commands that require maximum speed (e.g. high speed math processing such as FFTs, image processing, audio processing.)


###### Special Evaluation Method
The greater speed of command blocks is obtained through the use of a special evaluation method:


```html
<ul>
<li>Evaluation is strictly linear. Sub-expressions, control branching, and recursion are not allowed so no stack management is required.</li>
<li>Arguments are already reduced to their final values (or variables that hold those values.)</li>
<li>Special variations of function arguments are not allowed. Only word and 'word forms are allowed.</li>
<li>Arguments must appear in the correct order and no optional arguments are allowed.</li>
<li>Arguments are placed directly within the command argument frame, not on the primary evaluator stack.</li>
</ul>
```


####### Why is it Useful?
In subsystems like the [R3 GUI](%r3/docs/gui/gui), graphical elements are rendered by generating semi-static [draw blocks](%r3/docs/view/draw.html) either during style definition (definition of a button), face instantiation (creating an instance of a button), or face state modification (eg. hovering over a button).

The advantage of the static form of such draw blocks is that they require no further evaluation, hence take no additional memory or CPU time. In fact, the state of the GUI at any specific time is simply a sequence of draw block renderings. Therefore, a fast method of calling draw functions can greatly speed-up the rendering time of the GUI.

For special draw dialects (like the one used in the GUI) where optional or datatype-ordered arguments are allowed, a conversion from the dialect block to the command block is required. However, this conversion was already being performed in order to reduce the run-time overhead of the dialects (to avoid the NxM argument reordering penalty), so no additional overhead is incurred.


###### General Form
The general form is:


```rebol
do-commands [
    command1 arg11 arg12
    command2 arg21 arg22 arg23
    result: command3 arg31
    ...
]
```

Notice that set-words for results are allowed. In addition, the result of the final command will be returned from the `do-commands` function.


###### Argument Requirements
Command blocks are written in a reduced minimal form. They consist of one or more commands followed by their arguments. The arguments must be actual values or variables; sub-expressions and operators are not allowed. If necessary, use `reduce` with /only or `compose` to preprocess command blocks.

For example, you can write:


```rebol
line 0x0 100x100
line 100x100 200x200
```

and the command can also be variables:


```rebol
line start1 end1
line start2 end2
```

Sub expressions are not allowed:


```rebol
line 0x0 base + 10   ; error
line 0x0 add base 10 ; error
```

However, if necessary you can escape to parens for sub-expressions, but it reduces run-time performance:


```rebol
line 0x0 (base + 10) ; ok, but slow
```


###### Errors
An error will occur if any value other than a command is found:


```rebol
multiply 10 20
** Script error: expected command! not multiply
```

An error will also occur if an argument is not of the correct datatype, or if the block ends before all of its actual arguments are provided.

------------------------------------------------------------------
## DO-EVENTS

Process user events in GUI windows.  When this function is called the program becomes event driven. This function does not return until all windows have been closed.

------------------------------------------------------------------
## DO-THRU
------------------------------------------------------------------
## DOES
[[ closure exit func function has return use ]]

`does` provides a shortcut for defining functions that have no arguments or local variables.


```rebol
rand10: does [random 10]
print rand10
5

this-month: does [now/month]
print this-month
2
```

This function is provided as a coding convenience and it is otherwise identical to using `func` or `function`.

------------------------------------------------------------------
## DP
@@ DELTA-PROFILE

------------------------------------------------------------------
## DS

Having such a code in the console:
```rebol
>> fun: func[a][ if a > 0 [ds]  ]
>> fun 1
```
Will output:
```text
STACK[16] ds[0] native!

STACK[12] if[3] native!
        condition: #(true)
        true-branch: [ds]
        only: #(none)

STACK[5] fun[1] function!
        a: 1
```

------------------------------------------------------------------
## DT
@@ DELTA-TIME

------------------------------------------------------------------
## DUMP

Note: A debug build is required to use this function!

------------------------------------------------------------------
## DUMP-OBJ
[[ help ? ?? ]]

This function provides an easy way to view the contents of an object. The function is friendly to `print`. It is an alternative to `mold` and `probe` which may display too much information for deeply structured objects.


```rebol
>> print dump-obj object [a: 1 b: "hello"]
  a               integer!   1
  b               string!    "hello"
```

------------------------------------------------------------------
## ECDH
------------------------------------------------------------------
## ECDSA
------------------------------------------------------------------
## ECHO
[[ print trace ]]

Write output to a file in addition to the user console. The previous contents of a file will be overwritten. The echo can be stopped with `echo` none or by starting another `echo`.


```rebol
echo %helloworld.txt
print "Hello World!"
echo none
Hello World!
```

------------------------------------------------------------------
## EIGHTH
[[ first second third pick ]]

This is an ordinal.

See the `first` function for examples. If no value is found, none is returned.

------------------------------------------------------------------
## EITHER
[[ if any all unless case switch pick ]]

The `either` function will evaluate one block or the other depending on a condition.

This function provides the same capability as the if-else statements found in other languages. Because REBOL is a functional language, it is not desirable to use the word else within the expression.

Here's an example:


```rebol
either 2 > 1 [print "greater"] [print "not greater"]
greater

either 1 > 2 [print "greater"] [print "not greater"]
not greater
```

The condition can be the result of several expressions within `any` or `and`, or any other function that produces a result:


```rebol
either all [
    time > 10:20
    age > 20
    find users "bob"
] [print "that's true"] [print "that's false"]
that's true
```

In addition, it can be pointed out that the evaluated blocks can be within a variable:


```rebol
blk1: [print "that's true"]
blk2: [print "that's false"]
either 2 > 1 blk1 blk2
that's true
```


###### Return Value
The `either` function returns the result of the block that it evaluates.


```rebol
print either 2 > 1 ["greater"] ["not greater"]
greater
```


###### Simplification
The above example is pretty common, but it should be noted that it can be easily refactored:


```rebol
either 2 > 1 [print "greater"] [print "not greater"]
```

is better written as:


```rebol
print either 2 > 1 ["greater"] ["not greater"]
```

or even better written as:


```rebol
print pick ["greater" "not greater"] 2 > 1
```

The importance of this is that you're picking from a choice of two strings, and you're doing it here with one less block than the code above it.

Be careful with this last method. The `pick` function only allows true and false, not none. See `either` for more details.


###### A Common Error
A common error is to forget to provide the second block to the `either` function. This usually happens when you simplify an expression, and forget to change the `either` to an `if` function.

This is wrong:


```rebol
either 2 > 1 [print "greater"]
```

and it may become quite confusing as to why your program isn't working correctly.

You should have written:


```rebol
if 2 > 1 [print "greater"]
```

------------------------------------------------------------------
## ELLIPSIZE
------------------------------------------------------------------
## EMAIL?
[[ type? ]]

Returns false for all other values.


```rebol
print email? info@rebol.com
true

print email? http://www.REBOL.com
false
```

------------------------------------------------------------------
## EMPTY?
[[ tail? none? found? ]]

This is a synonym for `tail?` The check is made relative to the current location in the series.


```rebol
print empty? []
true

print empty? [1]
false
```

The `empty?` function is useful for all types of series. For instance, you can use it to check a string returned from the
user:


```rebol
str: ask "Enter name:"
if empty? str [print "Name is required"]
```

It is often used in conjunction with `trim` to remove black spaces from the ends of a string before checking it:


```rebol
if empty? trim str [print "Name is required"]
```

------------------------------------------------------------------
## ENBASE
[[ debase dehex ]]

Converts from a string or binary into an encode string value.


```rebol
>> enbase "Here is a string." 64
== "SGVyZSBpcyBhIHN0cmluZy4="

>> enbase #{12abcd45} 16
== "12ABCD45"
```

The `debase` function is used to convert the binary back again. For example:


```rebol
>> str: enbase "This is a string" 16
== "54686973206973206120737472696E67"

>> debase str 16
== #{54686973206973206120737472696E67}
```

------------------------------------------------------------------
## ENCLOAK
[[ decloak ]]

`encloak` is a low strength encryption method that can be useful for hiding passwords and other such values. It is not a replacement for AES or Blowfish, but works for noncritical data.

<b>Do not use it for top secret information!</b>

To cloak a binary string, provide the binary string and a cloaking key to the `encloak` function:


```rebol
>> bin: encloak #{54686973206973206120737472696E67} "a-key"
== #{4972E8CD78CE343EC727810866AE5F6B}
```

To cloak a string of characters, convert it using `to-binary` :


```rebol
>> bin: encloak to-binary "This is a string" "a-key"
== #{4972E8CD78CE343EC727810866AE5F6B}
```

The result is an encrypted binary value which can be decloaked with the line:


```rebol
>> decloak bin "a-key"
== #{54686973206973206120737472696E67}

>> to string! bin
== "This is a string"
```

The stronger your key, the better the encryption. For important data use a much longer key that is harder to guess. Also, do not forget your key, or it may be difficult or impossible to recover your data.

Now you have a simple way to save out a hidden string, such as a password:


```rebol
key: ask "Cloak key? (do not forget it) "
data: to-binary "string to hide"
save %data encloak data key
```

To read the data and decloak it:


```rebol
key: ask "Cloak key? "
data: load %data
data: to-string decloak data key
```

Of course you can cloak any kind of data using these functions, even non-character data such as programs, images, sounds, etc. In those cases you do not need the `to-binary` conversion shown above.

Note that by default, the cloak functions will hash your key strings into 160 bit SHA1 secure cryptographic hashes. If you have created your own hash key (of any length), you use the /with refinement to provide it.

------------------------------------------------------------------
## ENCODE
[[ decode load enbase debase ]]

Used to call codecs to encode datatypes into binary data (bytes).

Codecs are identified by words that symbolize their types. For example the word png is used to identify the PNG codec.

See the system/codecs for a list of loaded codecs. Codecs can be native (built-in), externally loaded, or even coded in REBOL.


###### Examples
The line:


```rebol
save %photo.bmp image
```

Is roughly equivalent to:


```rebol
data: encode 'bmp image
write %photo.bmp data
```

------------------------------------------------------------------
## ENCODING?
[[ decode encode ]]

```rebol
>> encoding? read %test.wav
== wav

>> encoding? read %test.png
== png
```

------------------------------------------------------------------
## ENHEX
[[ dehex ]]

```rebol
>> enhex "a b"
== "a%20b"

>> enhex/uri "a b"
== "a+b"

>> enhex/escape "a b" #"#"
== "a#20b"
```

------------------------------------------------------------------
## ENLINE
[[ deline ]]

Basic example:


```rebol
enline "a^/b"
"a^/M^/b"
```

To convert from any string termination format to, use `enline` after the `deline` function:


```rebol
enline deline "a^Mb"
"a^/M^/b"
```

See `deline` for more information about string termination formats.

------------------------------------------------------------------
## ENTAB
[[ detab ]]

The REBOL language default tab-size is four spaces. Use the /size refinement for other sizes such as eight. `entab` will only place tabs at the beginning of the line (prior to the first non-space character).

The series passed to this function is modified as a result.


```rebol
text: {
    no
    tabs
    in
    this
    sentence
} 
remove head remove back tail text
probe text
{    no
    tabs
    in
    this
    sentence}

probe entab copy text
{^-no
   tabs
   in
   this
   sentence}

print entab copy text
        no
   tabs
   in
   this
   sentence

probe entab/size copy text 2
{^-^-no
^- tabs
^- in
^- this
^- sentence}

print entab/size copy text 2
     no
  tabs
  in
  this
  sentence
```

The opposite function is `detab` which converts tabs back to spaces:


```rebol
probe entab text
{^-no
   tabs
   in
   this
   sentence}

probe detab text
{    no
    tabs
    in
    this
    sentence}
```

------------------------------------------------------------------
## ENUM
------------------------------------------------------------------
## EQUAL?
[[ = <> == =? not-equal? strict-equal? ]]

String-based datatypes are considered equal when they
are identical or differ only by character casing
(uppercase = lowercase). Use `==` or find/match/case to
compare strings by casing.


```rebol
print equal? 123 123
true

print equal? "abc" "abc"
true

print equal? [1 2 3] [1 2 4]
false

print equal? 12-june-1998 12-june-1999
false

print equal? 1.2.3.4 1.2.3.0
false

print equal? 1:23 1:23
true
```

------------------------------------------------------------------
## EQUIV?
------------------------------------------------------------------
## ERROR?

Returns false for all other values. This is useful for determining if a `try` function returned an error.


```rebol
if error? try [1 + "x"][
    print "Did not work."
]
Did not work.
```

------------------------------------------------------------------
## EVEN?
[[ odd? zero? ]]

Returns true only if the argument is an even integer value. If the argument is a decimal, only its integer portion is
examined.


```rebol
print even? 100
true

print even? 7
false
```

------------------------------------------------------------------
## EVENT?

Returns true if the value is an event datatype.

------------------------------------------------------------------
## EVOKE

This is useful for analyzing hard REBOL crashes that lead to assertion errors and other crashes that aren't related to your script errors, but directly exposes bugs in the REBOL kernel. This is helpful information for REBOL Technologies to fix these bugs.

To enable this kind of analysis, have this at the beginning of your program:


```rebol
secure [debug allow] 
evoke 'crash-dump
```

If REBOL crashes, you will get a stack dump. You can force a crash using:


```rebol
evoke 'crash
--REBOL Kernel Dump--
Evaluator:
    Cycles:  110001
    Counter: 4907
    Dose:    10000
    Signals: #00000000
    Sigmask: #FFFFFFFF
    DSP:     5
    DSF:     1
Memory/GC:
    Ballast: 1709360
    Disable: 1
    Protect: 1
    Infants: 1

STACK[5] evoke[1] native!
        chant: crash
```


###### Special Notes
Common for all operations with evoke is that debugging must be allowed using:


```rebol
secure [debug allow]
```

`evoke` also allows other debug output, mostly used internally by REBOL Technologies to help test REBOL 3.

The function can also be used to monitor the garbage collector:


```rebol
evoke 'watch-recycle
```

or to monitor object copying:


```rebol
evoke 'watch-obj-copy
```

or to set the stack size:


```rebol
evoke 'stack-size 2000000
```

or to debug `delect` information:


```rebol
evoke 'delect
```

------------------------------------------------------------------
## EXCLUDE
[[ difference intersect union unique ]]

Returns the elements of the first set less the elements
of the second set. In other words, it removes from the
first set all elements that are part of the second set.


```rebol
lunch: [ham cheese bread carrot]
dinner: [ham salad carrot rice]
probe exclude lunch dinner
[cheese bread]

probe exclude [1 3 2 4] [3 5 4 6]
[1 2]

string1: "CBAD"    ; A B C D scrambled
string2: "EDCF"    ; C D E F scrambled
probe exclude string1 string2
"BA"

items: [1 1 2 3 2 4 5 1 2]
probe exclude items items  ; get unique set
[]

str: "abcacbaabcca"
probe exclude str str
""
```

Note that performing this function over very large
data sets can be CPU intensive.

------------------------------------------------------------------
## EXISTS?
[[ read write delete modified? size? ]]

Returns false if the file does not exist.


```rebol
print exists? %file.txt
false

print exists? %doc.r
false
```

------------------------------------------------------------------
## EXISTS-THRU?
------------------------------------------------------------------
## EXIT
[[ return catch break ]]

`exit` is used to return from a function without returning a value.


```rebol
test-str: make function! [str] [
    if not string? str [exit]
    print str
]
test-str 10
test-str "right"
```

Note: Use `quit` to exit the interpreter.

------------------------------------------------------------------
## EXP
[[ log-10 log-2 log-e power ]]

The `exp` function returns the exponential value of the argument provided.


```rebol
print exp 3
20.08553692318766
```

On overflow, an error is returned (which can be trapped with the `try` function). On underflow, a 0 is returned.

------------------------------------------------------------------
## EXTEND
[[ context ]]

This function is useful to extend `object!`, `map!` or `block!` values using a word/value pair. It returns the input value. It performs no copy.

Examples:


```rebol
a: [b: 1 c: 2]
extend a 'd 3
= 3
probe a
[b: 1 c: 2 d: 3]

a: make object! [b: 1 c: 2]
extend a 'd 3
3
probe a
make object! [
    b: 1
    c: 2
    d: 3
]

a: make map! [b: 1 c: 2]
extend a 'd 3
3
probe a
make map! [
    b: 1
    c: 2
    d: 3
]
```

------------------------------------------------------------------
## EXTRACT

Returns a series of values from regularly spaced positions within a specified series. For example:


```rebol
data: ["Dog" 10 "Cat" 15 "Fish" 20]
probe extract data 2
["Dog" "Cat" "Fish"]
```

Essentially, `extract` lets you access a series as a record or "row" of a given length (specified by the width argument). The default, as shown above, extracts the first value. If you wanted to extract the second value (the second "column" of data):


```rebol
data: ["Dog" 10 "Cat" 15 "Fish" 20]
probe extract/index data 2 2
[10 15 20]
```

In the example below, the width of each row is three:


```rebol
people: [
    1 "Bob" "Smith"
    2 "Cat" "Walker"
    3 "Ted" "Jones"
]
block: extract people 3
probe block
[
 1
 2
 3
]

block: extract/index people 3 2
probe block
["Bob" "Cat" "Ted"]
```

Of course, `extract` works on any [series](https://www.rebol.com/r3/docs/concepts/series.html), not just those that appear in a row format (such as that above). The example below creates a block containing every other word from a string:


```rebol
str: "This is a given block here"
blk: parse str none
probe blk
["This" "is" "a" "given" "block" "here"]

probe extract blk 2
["This" "a" "block"]

probe extract/index blk 2 2
["is" "given" "here"]
```

Here is an example that uses `extract` to obtain the names of all the predefined REBOL/View VID styles:


```rebol
probe extract system/view/vid/vid-styles 2
```

------------------------------------------------------------------
## FIFTH
[[ pick first second third fourth ]]

This is an ordinal.

See the `first` function for examples. If no value is found, none is returned.


```rebol
print fifth "REBOL"
L

print fifth [11 22 33 44 55 66]
55
```

------------------------------------------------------------------
## FILE-CHECKSUM
------------------------------------------------------------------
## FILE?
[[ type? ]]

Returns false for all other values. Note that `file?` does not check for the existence of a file, but whether or not a value is the FILE! datatype.


```rebol
print file? %file.txt
true

print file? "REBOL"
false
```

Note also this is not a direct opposite to the `dir?` function as `dir?` does not test against a datatype, where `file?` does.

------------------------------------------------------------------
## FILE-TYPE?
------------------------------------------------------------------
## FILTER
------------------------------------------------------------------
## FIND
[[ select pick ]]

Returns `none!` if the value was not found. Otherwise, returns a position in the series where the value was found. Many refinements to this function are available.


####### Refinements
Use /tail to return the position just past the match.

Use /case to specify that the search should be case sensitive. Note that using `find` on a binary string will do a case-insensitive search.

The /match refinement can be used to perform a character by character match of the input value to the series. The position just past the match is returned.

Wildcards can be specified with /any.

The /only refinement applies to block values and is ignored for strings.

The /last refinement causes `find` to search from the tail of the series toward the head.

And, /reverse searches backwards from the current position toward the head.


```rebol
probe find "here and now" "and"
"and now"

probe find/tail "here and now" "and"
" now"

probe find [12:30 123 c@d.com] 123
[123 c@d.com]

probe find [1 2 3 4] 5
none

probe find/match "here and now" "here"
" and now"

probe find/match "now and here" "here"
none

probe find [1 2 3 4 3 2 1] 2
[2 3 4 3 2 1]

probe find/last %file.fred.txt "."
%.txt

probe find/last [1 2 3 4 3 2 1] 2
[2 1]

probe find/any "here is a string" "s?r"
none
```

------------------------------------------------------------------
## FIND-ALL
------------------------------------------------------------------
## FIND-MAX
------------------------------------------------------------------
## FIND-MIN
------------------------------------------------------------------
## FIND-SCRIPT

This is a high-speed lower level function to scan UTF-8 for a REBOL script signature, useful during loading of scripts and to ensure that scripts are proper UTF-8.


Editor note: Not sure about the description
------------------------------------------------------------------
## FIRST
[[ pick second third fourth fifth ]]

This is an ordinal. It returns the first value in any type of [series](https://www.rebol.com/r3/docs/concepts/series.html) at the current position. If no value is found, none is returned.


```rebol
print first "REBOL"
R

print first [11 22 33 44 55 66]
11

print first 1:30
1

print first 199.4.80.1
199

print first 12:34:56.78
12
```

------------------------------------------------------------------
## FIRST+

Example:


```rebol
blk: [a b c]
first+ blk
a

first+ blk
b

first+ blk
c

first+ blk
none
```

------------------------------------------------------------------
## FLUSH
------------------------------------------------------------------
## FOR
[[ loop repeat forall foreach forever forskip map-each remove-each ]]

The first argument is used as a local variable to keep track of the current value. It is initially set to the START value and after each evaluation of the block the BUMP value is added to it until the END value is reached (inclusive).


```rebol
for num 0 30 10 [ print num ]
30

for num 4 -37 -15 [ print num ]
-26
```

------------------------------------------------------------------
## FORALL
[[ for foreach forskip forever while until ]]

The `forall` function moves through a series one value at a time.

The word argument is a variable that moves through the series. Prior to evaluation, the word argument must be set to the desired starting position within the series (normally the head, but any position is valid). After each evaluation of the block, the word will be advanced to the next position within the series.


```rebol
cities: ["Eureka" "Ukiah" "Santa Rosa" "Mendocino"]
forall cities [print first cities]
Eureka
Ukiah
Santa Rosa
Mendocino

chars: "abcdef"
forall chars [print first chars]
a
b
c
d
e
f
```

When `forall` finishes the word is reset to the starting position of the series.


```rebol
chars: next "abcdef"
"bcdef"

forall chars []
chars
"bcdef"
```

The result of `forall` is the result of the last expression of the block:


```rebol
chars: "abcdef"
forall chars [first chars]
#"f"
```

Or the result of a break/return from the block:


```rebol
chars: "abcdef"
forall chars [break/return 5]
5
```

The `forall` function can be thought of as a shortcut for:


```rebol
[
    original: series
    while [not tail? series] [
        x: (your code)
        series: next series
    ]
    series: original
    :x
]
```

------------------------------------------------------------------
## FOREACH
[[ remove-each map-each for forall forskip repeat ]]

The `foreach` function repeats the evaluation of a block for each element of a series. It is used often in programs.

Example:


```rebol
values: [11 22 33]
foreach value values [print value]
11
22
33
```

Another example that prints each word in a block along with its value:


```rebol
colors: [red green blue]
foreach color colors [print [color get color]]
red 255.0.0
green 0.255.0
blue 0.0.255
```

If the series is a string, each character will be fetched:


```rebol
string: "REBOL"
foreach char string [print char]
R
E
B
O
L
```

This example will print each filename from a directory block:


```rebol
files: read %.
foreach file files [
    if find file ".t" [print file]
]
file.txt
file2.txt
newfile.txt
output.txt
```


```html
<fieldset class="fset"><legend>Local Variables</legend>
<p>The variables used to hold the <a href="#foreach">foreach</a> values are local to the block. Their value are only set within the block that is being repeated. Once the loop has exited, the variables return to their previously set values.</p>
</fieldset>
```


###### Multiple Elements
When a block contains groups of values that are related, `foreach` function can fetch all elements at the same time. For example, here is a block that contains a time, string, and price. By providing the `foreach` function with a block of words for the group, each of their values can be fetched and printed.


```rebol
movies: [
     8:30 "Contact"      $4.95
    10:15 "Ghostbusters" $3.25
    12:45 "Matrix"       $4.25
]

foreach [time title price] movies [
    print ["watch" title "at" time "for" price]
]
watch Contact at 8:30 for $4.95
watch Ghostbusters at 10:15 for $3.25
watch Matrix at 12:45 for $4.25
```

In the above example, the `foreach` value block:


```rebol
[time title price]
```

specifies that three values are to be fetched from movies for each evaluation of the block.


###### Series Reference
To reference the series itself during `foreach` you can use a `set-word!` within the variable block. This operation is similar to the `forall` and `forskip` functions.

Example:


```rebol
foreach [v1: v2] [1 2 3] [?? [v1 v2]]
v1: [1 2 3] v2: 1
v1: [2 3] v2: 2
v1: [3] v2: 3
```

Notice that the v1 set-word does not affect the index position.

If you are using this option to remove values, please see the `remove-each` function which is many times faster for large series.


###### Foreach of Objects and Maps
The `foreach` function can also be used with `object!` and `map!` datatypes.

When using a single word argument, `foreach` will obtain the object field name or map key.


```rebol
fruits: make object! [apple: 10 orange: 12 banana: 30]
foreach field fruits [print field]
apple
orange
banana
```

Note that each word is bound back to the object, and can be used to access the field value with `get` and `set`.

If a second word argument is provided, it will obtain the value of each entry:


```rebol
foreach [field value] fruits [print [field value]]
apple 10
orange 12
banana 30
```

The same behavior applies to the `map!` datatype, except that empty keys (those set to none) will be skipped.

When a `set-word!` is used in the variables block, it will obtain the object value itself.

------------------------------------------------------------------
## FOREVER
[[ loop repeat for while until ]]

Evaluates a block continuously, or until a break or error condition is met.


```rebol
forever [
    if (random 10) > 5 [break]
]
```

------------------------------------------------------------------
## FORM
[[ print reform mold remold ajoin join rejoin ]]

The `form` function converts a value to a human readable string. It is commonly used by `print` for output.


```rebol
form 1234
"1234"

form 10:30
"10:30"

form %image.jpg
"image.jpg"
```

When given a block of values, spaces are inserted between each values (except after a newline).


```rebol
form [1 2 3]
"1 2 3"
```

To avoid the spaces between values use `ajoin`, `join`, or `rejoin`.

The `reform` function combines `reduce` with `form` to evaluate values:


```rebol
reform [1 + 2 3 + 4]
"3 7"
```

To produce REBOL-readable output, use the `mold` function.

------------------------------------------------------------------
## FORM-OID
------------------------------------------------------------------
## FORMAT

This is useful for table output in the console, where fixed-width fonts are used. It can also be used to specially format numbers or complex values.

The first input, is the dialect. It's a combination of positive or negative formatting integers and strings or chars, that are to be inserted between the integers.

A positive integer N, means the value will be left adjusted with N chars for space.

A negative integer N, means the value will be right adjusted with N chars for space.

In both cases, a value that takes up more space than N, is truncated to N chars.

The second input is the values, either as a block or as a single value.

Example:


```rebol
format [-3 -3 -4] [1 2 3]
"  1  2   3"
```

Format a time value using /pad to add zeroes:


```rebol
format/pad [-2 ":" -2 ":" -2] [12 47 9] 0
"12:47:09"
```

It can also be used to pad zeroes to a single numeric value:


```rebol
format/pad [-8] 5125 0
"00005125"
```

------------------------------------------------------------------
## FORMAT-DATE-TIME
------------------------------------------------------------------
## FORMAT-TIME
------------------------------------------------------------------
## FORSKIP
[[ for forall foreach skip ]]

Prior to evaluation, the word must be set to the desired starting position within the series (normally the head, but any position is valid). After each evaluation of the block, the word's position in the series is changed by skipping the number of values specified by the second argument (see the `skip` function).


```rebol
areacodes: [
    "Ukiah"         707
    "San Francisco" 415
    "Sacramento"    916
]
forskip areacodes 2 [
    print [ first areacodes "area code is" second areacodes]
]
Sacramento area code is 916
```

------------------------------------------------------------------
## FOURTH
[[ first second third fifth pick ]]

This is an ordinal.

See the `first` function for examples. If no value is found, none is returned.


```rebol
print fourth "REBOL"
O

print fourth [11 22 33 44 55 66]
44

print fourth 199.4.80.1
1
```

------------------------------------------------------------------
## FRACTION
------------------------------------------------------------------
## FRAME?
------------------------------------------------------------------
## FUNC
[[ closure does has funco funct function use make function? return exit ]]

The `func` function creates new functions from a spec block and a body block.

General form:


```rebol
name: func [spec] [body]
```

The spec block specifies the interface to the function. It can begin with an optional title string which used by the `help` function. That is followed by words that specify the arguments to the function. Each of argument can include an optional block of datatypes to specify the valid datatypes for the argument. Each may be followed by a comment string which describes the argument in more detail.

The argument words may also specify a few variations on the way the argument will be evaluated. The most common is 'word which indicates that a word is expected that should not be evaluated (the function wants its name, not its value). A :word may also be given which will get the value of the argument, but not perform full evaluation.

To add refinements to a function supply a slash (/) in front of an argument's word. Within the function the refinement can be tested to determine if the refinement was present. If a refinement is followed by more arguments, they will be associated with that refinement and are only evaluated when the refinement is present.

Local variables are specified after a /local refinement.

A function returns the last expression it evaluated. You can also use `return` and `exit` to exit the function. A `return` is given a value to return. `exit` returns no value.


```rebol
sum: func [a b] [a + b]
print sum 123 321
444

sum: func [nums [block!] /average /local total] [
    total: 0
    foreach num nums [total: total + num]
    either average [total / (length? nums)][total]
]
print sum [123 321 456 800]
print sum/average [123 321 456 800]
425

print-word: func ['word] [print form word]
print-word testing
testing
```

------------------------------------------------------------------
## FUNCO
[[ closure does has func funct function use make function? return exit ]]

Similar to `func`, except the spec or body is not copied.

------------------------------------------------------------------
## FUNCT

This is similar to `func`, except all set-words are assumed locals. This way, it's not necessary to specify the /local part of the spec, although you still can.

Example:


```rebol
f: funct [a] [
    b: a
]
f 7
7

b
** Script error: b has no value
```

If you still desire to create non-local values in the function, use `set` to set words:


```rebol
f: funct [a] [
    b: a
    set 'c b / 2
]
f 7
3.5

c
3.5
```

If c still needs to be local, you can add the local refinement:


```rebol
unset 'c ; make sure it's not set
f: funct [a /local c] [
    b: a
    set 'c b / 2
]
f 7
3.5

c
** Script error: c has no value
```

------------------------------------------------------------------
## FUNCTION
[[ func does has make use function? return exit ]]

```html
<fieldset class="fset"><legend>Warning!</legend>
<p>The descripton of <a href="#function">function</a> given below is up-to-date, however the spec shown above is not current. <a href="#function">function</a> was <a href="http://www.rebol.com/article/0543.html" class="lnk">recently adapted</a> from a 3-argument to a 2-argument variant.</p>
</fieldset>
```

This is similar to `func`, except all set-words are assumed locals. This way, it's not necessary to specify the /local part of the spec, although you still can.

Example:


```rebol
average: function [block] [
    total: 0
    foreach number block [total: number + total]
    total / (length? block)
]
print average [1 10 12.34]
7.78

total
** Script error: total has no value
```

If you still desire to create non-local values in the function, use `set` to set words:


```rebol
f: function [a] [
    b: a
    set 'c b / 2
]
f 7
3.5

c
3.5
```

If c still needs to be local, you can add the local refinement:


```rebol
unset 'c ; make sure it's not set
f: function [a /local c] [
    b: a
    set 'c b / 2
]
f 7
3.5

c
** Script error: c has no value
```

------------------------------------------------------------------
## FUNCTION?
[[ any-function? type? ]]

Returns false for all other values.


```rebol
print function? :func
true

print function? "test"
false
```

------------------------------------------------------------------
## GCD
------------------------------------------------------------------
## GENERATE
------------------------------------------------------------------
## GET
[[ set value? in ]]

The argument to `get` must be a word, so the argument must be quoted or extracted from a block. To get the value of a word residing in an object, use the `in` function.


```rebol
value: 123
print get 'value
123

print get second [the value here]
123

print get in system/console 'prompt
>>
```

If the argument to `get` is an object, the result is the same as that of `values-of`.

------------------------------------------------------------------
## GET-ENV
[[ list-env ]]

This function will return the string associated with an OS environment variable.


```rebol
probe get-env "COMPUTERNAME"
"BIGBOY"
```

To obtain a list of all environment variables and their values, use `list-env`.

------------------------------------------------------------------
## GET-PATH?
[[ path? set-path? lit-path? ]]

Returns false for all other values.


```rebol
get-path? to-get-path 'path/to/somewhere
true
```

------------------------------------------------------------------
## GET-WORD?
[[ word? set-word? lit-word? ]]

Returns false for all other values.


```rebol
print get-word? second [pr: :print]
true
```

------------------------------------------------------------------
## GOB?

Returns false for all other values.


```rebol
gob? make gob! [text: "this is a gob!"]
true
```

------------------------------------------------------------------
## GREATER-OR-EQUAL?
[[ >= < <= > = <> equal? lesser-or-equal? min max not-equal? ]]

Returns false for all other values. Both values must be of the same datatype or an error will occur. For string-based datatypes, the sorting order is used for comparison with character casing ignored (uppercase = lowercase).


```rebol
print greater-or-equal? "abc" "abb"
true

print greater-or-equal? 16-June-1999 12-june-1999
true

print greater-or-equal? 1.2.3.4 4.3.2.1
false

print greater-or-equal? 1:00 11:00
false
```

------------------------------------------------------------------
## GREATER?
[[ > < <= >= = <> lesser? min max ]]

Returns false for all other values. The values must be of the same datatype or an error will occur. For string-based datatypes, the sorting order is used for comparison with character casing ignored (uppercase = lowercase).


```rebol
print greater? "abc" "abb"
true

print greater? 16-June-1999 12-june-1999
true

print greater? 4.3.2.1 1.2.3.4
true

print greater? 11:00 12:00
false
```

------------------------------------------------------------------
## GUI-METRIC
------------------------------------------------------------------
## HALT
[[ quit break exit catch ]]

Useful for program debugging.


```rebol
div: 10
if error? try [100 / div] [
    print "math error"
    halt
]
```

------------------------------------------------------------------
## HANDLE-EVENTS

This is used internally in the `view` function.

------------------------------------------------------------------
## HANDLE?

Returns false for all other values.


Editor note: Need example.
------------------------------------------------------------------
## HANDLED-EVENTS?
------------------------------------------------------------------
## HAS
[[ func function does exit return use ]]

Defines a function that consists of local variables only. This is a shortcut for `func` and `function`.

For example:


```rebol
ask-name: has [name] [
    name: ask "What is your name?"
    print ["Hello" name]
]

ask-name
Hello Luke
```

The example above is a shortcut for:


```rebol
ask-name: func [/local name] [...]
```

------------------------------------------------------------------
## HASH
------------------------------------------------------------------
## HASH?
------------------------------------------------------------------
## HEAD
[[ head? tail tail? ]]

The insert function returns at the current string position, so `head` adjusts the index back to the head:


```rebol
str: "all things"
print head insert str "with "
with all things
```

Now here is not at the head:


```rebol
here: find str "all"
print here
all things
```

Now we print at the head:


```rebol
print head here
with all things
```

------------------------------------------------------------------
## HEAD?
[[ head tail tail? ]]

```rebol
cds: [
    "Rockin' REBOLs"
    "Carl's Addiction"
    "Jumpin' Jim"
]
print head? cds
true

cds: tail cds
print head? cds
false

until [
    cds: back cds
    print first cds
    head? cds
]
Rockin' REBOLs
```

------------------------------------------------------------------
## HELP
[[ ? what ?? docs ]]

The `help` function provides information about words and values.

Type `help` or `?` at the console prompt to view a summary of help:


```rebol
>> help
To use HELP, supply a word or value as an argument:

    help insert

Also, the ? is a shortcut for help:

    ? insert
    ? system
    ? system/options

To search all internal help strings and values:

    help "insert"
    help to-   ; (a partial word)

To see detailed online web docs for a function:

    help/doc forall

For all on-line web documentation, just type:

    docs

To see words with values of a specific datatype:

    help native!
    help function!
    help datatype!

Other debug functions:

    ? self - show words and values (in context)
    ?? - display a variable and its value
    probe - print a value (molded)
    source func - show source code of func
    trace - trace evaluation steps
    what - show a list of known functions
    why? - explain more about last error (via web) 

Other information:

    chat - open DevBase developer forum/BBS
    docs - open DocBase document wiki website
    bugs - open CureCore bug database website
    demo - run demo launcher (from rebol.com)
    about - see general product info
    upgrade - check for newer versions
    changes - show changes for recent version
    install - install (when applicable)
    license - show user license
    usage - view program options
```


###### Help about a Function
If you provide a function word as an argument, `help` prints all of the information related to that function.

For instance, if you type:


```rebol
>> help insert
```

you will see:


```rebol
USAGE:
    INSERT series value /part range /only /dup count

DESCRIPTION:
     Inserts into a series and returns the series after the insert. (Modifies)
     INSERT is an action value.

ARGUMENTS:
     series -- Series at point to insert (series! port! map! gob! object! bitset! port!)
     value -- The value to insert (any-type!)

REFINEMENTS:
     /part -- Limits to a given length or position.
         length (number! series! pair!)
     /only -- Only inserts a block as a single value (not the contents of the block)
     /dup -- Duplicates the insert a specified number of times.
         count (number! pair!)
```

For more detailed information, you can use the doc refinement:


```rebol
>> help/doc insert
```

to open the web browser to the page related to that function.


###### Help about Datatypes
All datatypes are explained through help.

To obtain a list of all REBOL datatypes, type:


```rebol
>> ? datatype!

Found these related words:
    action!         datatype! datatype native function (standard polymorphic)
    binary!         datatype! string series of bytes
    bitset!         datatype! set of bit flags
    block!          datatype! series of values
    char!           datatype! 8bit and 16bit character
    ...
```

For help on a specific datatype:


```rebol
help integer!
integer! is a datatype
It is defined as a 64 bit integer
It is of the general type scalar
Found these related words:
   zero            integer!  0
```

To list all words that are function! datatypes, type:


```rebol
>> ? function!
```

and the result would be:


```rebol
Found these related words:
    ?               function! Prints information about words and values.
    ??              function! Debug print a word, path, or block of such, f...
    about           function! Information about REBOL
    alter           function! If a value is not found in a series, append i...
    any-block?      function! Return TRUE if value is any type of block.
    any-function?   function! Return TRUE if value is any type of function.
    any-object?     function! Return TRUE if value is any type of object.
    any-path?       function! Return TRUE if value is any type of path.
    any-string?     function! Return TRUE if value is any type of string.
    any-word?       function! Return TRUE if value is any type of word.
    array           function! Makes and initializes a series of a given siz...
    as-pair         function! Combine X and Y values into a pair.
    ask             function! Ask the user for input.
    ...
```


###### Help Search
The `help` function also finds words that contain a specified string. For example, to find all of the words that include the string `path!`, type:


```rebol
>> ? "path"
```

and the result will be:


```rebol
Found these related words:
    ??              function! Debug print a word, path, or block of such, f...
    any-path!       typeset!  [path! set-path! get-path! lit-path!]
    any-path?       function! Return TRUE if value is any type of path.
    assert          native!   Assert that condition is true, else throw an ...
    cd              function! Change directory (shell shortcut function).
    change-dir      native!   Changes the current directory path.
    clean-path      function! Returns new directory path with //, . and .. ...
    dirize          function! Returns a copy of the path turned into a dire...
    file!           datatype! file name or path
    ...
```


###### Help on Objects
If you use `help` on an object, it will list a summary of the object's fields.


```rebol
>> ? system
SYSTEM is an object of value:
    product         word!     core
    version         tuple!    2.100.90.3.1
    build           date!     14-Oct-2009/22:40:04
    license         string!   {Alpha prototype version. For testing only. U...
    catalog         object!   [datatypes actions natives errors reflectors ...
    contexts        object!   [root system exports user]
    state           object!   [note last-error]
    intrinsic       object!   [do make-module make-port parse-url begin]
    modules         block!    length: 3
    ...
```


###### Help on Errors
There is a special mechanism for getting help on errors.

When you get an error message at the console, you can type `why?` to see info about that specific error.

For example:


```rebol
>> test
** Script error: test has no value

>> why?
Opening web browser...
```

and, this page, [no-value](https://www.rebol.com/r3/docs/errors/script-no-value.html), would be displayed.

See `why?` for more about this function.

------------------------------------------------------------------
## HSV-TO-RGB
------------------------------------------------------------------
## ICONV
------------------------------------------------------------------
## IF
[[ either any all unless switch select ]]

The `if` function will evaluate the block when its first argument is true.

True is defined to be any value that is not false or none.


```rebol
if 2 > 1 [print "that's true"]
that's true
```

The condition can be the result of several expressions within `any` or `and`, or any other function that produces a result:


```rebol
if all [
    time > 10:20
    age > 20
    find users "bob"
] [print "that's true"]
that's true
```

In addition, it can be pointed out that the block can be in a variable also:


```rebol
blk: [print "that's true"]
if 2 > 1 blk
that's true
```


###### Return Value
When the condition is true, the `if` function returns the value that is the result of evaluating the block. Otherwise, it returns none. This is a useful feature.

For example:


```rebol
print if 2 > 1 [1 + 2]
3

print if 1 > 2 [1 + 2]
none

names: ["Carl" "Brian" "Steve"]
print if find names "Carl" ["Person found"]
Person found
```


###### Where's the Else?
Unlike most other languages, REBOL uses functions, not commands to evaluate all expressions. Therefore, it's not desirable to use the word else if you need that behavior. Instead, use the `either` function:


```rebol
either 2 > 1 [print "greater"] [print "not greater"]
greater

either 1 > 2 [print "greater"] [print "not greater"]
not greater
```


###### Simplification
The above example is pretty common, but it should be noted that it can be easily refactored:


```rebol
either 2 > 1 [print "greater"] [print "not greater"]
```

is better written as:


```rebol
print either 2 > 1 ["greater"] ["not greater"]
```

or even better written as:


```rebol
print pick ["greater" "not greater"] 2 > 1
```

The importance of this is that you're picking from a choice of two strings, and you're doing it here with one less block than the code above it.

Be careful with this last method. The `pick` function only allows true and false, not none. See `either` for more details.

In addition, it should be noted that the `any` function used earlier didn't really require the `if` at all. It could have been written as:


```rebol
all [
    time > 10:20
    age > 20
    find users "bob"
    print "that's true"
]
```


###### A Common Error
A common error is to use `if` and add an "else" block without using the `either` function. The extra block gets ignored:


```rebol
n: 0
if 1 > 2 [n: 1] [n: 2]
print n
0
```

The second block is ignored in this case and not evaluated.

The code should have used the `either` function:


```rebol
n: 0
either 1 > 2 [n: 1] [n: 2]
print n
2
```


###### The /Else refinement is obsolete
The /Else refinement is obsolete and will be removed in future versions. Avoid it.

------------------------------------------------------------------
## IMAGE
------------------------------------------------------------------
## IMAGE-DIFF
------------------------------------------------------------------
## IMAGE?
[[ to-image ]]

Returns true if the value is an `image!` datatype.

This function is often used after the `load` function to verify that the data is in fact an image. For example:


```rebol
img: load %test-image.png
if not image? img [alert "Not an image file!"]
```

------------------------------------------------------------------
## IMPORT
[[ do load ]]

The `import` function is used to import modules into your runtime environment. For a full description see the [modules: loading modules](https://www.rebol.com/r3/docs/concepts/modules-loading.html) section of this documentation.

For example, you can write:


```rebol
import 'mysql
```

and the system will search for the mysql module.

You can also use a filename or URL for the module identifier:


```rebol
import %mysql.r

import http://www.rebol.com/mods/mysql.r
```


####### Return value
When successful, the `import` function returns a `module!` datatype as its result.

This allows you to write:


```rebol
mysql: import 'mysql
```

Now, the mysql variable can be used to refer to values within the mysql module.

For example the module value is used here to reference a function:


```rebol
mysql/open-db %my-database.sql
```

See below for more.


####### Useful refinements
Like the header needs field, the `import` function also lets you specify a version and a checksum.

These are all supported:


```rebol
import/version mysql 1.2.3

import/check mysql #{A94A8FE5CCB19BA61C4C0873D391E987982FBBD3}

import/version/check mysql 1.2.3 #{A94A8FE5CCB19BA61C4C0873D391E987982FBBD3}
```


####### When to use IMPORT
The benefit of using the `import` function compared to the needs header field is that the arguments can be variables.

A basic example is:


```rebol
mod: 'mysql
import mod
```

Or, something like:


```rebol
mod-list: [
    mysql 1.2.3
    db-gui 2.4.5
    http-server 1.0.1
]

foreach [id ver] mod-list [
    import/version id ver
]
```

------------------------------------------------------------------
## IN
[[ set get ]]

Return the word from within another context. This function is normally used with `set` and `get`.


```rebol
set-console: func ['word value] [
    set in system/console word value
]
set-console prompt "==>"
set-console result "-->"
```

This is a useful function for accessing the words and values of an object. The `in` function will obtain a word from an object's context. For example, if you create an object:


```rebol
example: make object! [ name: "fred" age: 24 ]
```

You can access the object's name and age fields with:


```rebol
print example/name
print example/age
24
```

But you can also access them with:


```rebol
print get in example 'name
print get in example 'age
24
```

The `in` function returns the name and age words as they are within the example object. If you type:


```rebol
print in example 'name
name
```

The result will be the word name, but with a value as it exists in the example object. The `get` function then fetches their values.  This is the best way to obtain a value from an object, regardless of its datatype (such as in the case of a function).

A `set` can also be used:


```rebol
print set in example 'name "Bob"
Bob
```

Using `in`, here is a way to print the values of all the fields of an object:


```rebol
foreach word words-of example [
    probe get in example word
]
24
```

Here is another example that sets all the values of an object to none:


```rebol
foreach word words-of example [
    set in example word none
]
```

The `in` function can also be used to quickly check for the existence of a word within an object:


```rebol
if in example 'name [print example/name]
none

if in example 'address [print example/address]
```

This is useful for objects that have optional variables.


###### Advanced binding uses
In R3, `in` can also be used for binding a block to an object to support this useful idiom:


```rebol
do in example [age + 1]
25
```

Identically, a `paren!` can be used as the rebound block:


```rebol
do in example second [(age + 1) (age + 20)]
44
```

------------------------------------------------------------------
## IN-DIR

This is useful if you need to temporarily switch to a different directory to do something, and then switch back without manually doing so.

Example:


```rebol
in-dir %tmp-dir/ [tmp-files: read %.]
```

------------------------------------------------------------------
## INDEX?
[[ length? offset? head head? tail tail? pick skip ]]

The index function returns the position within a series. For
example, the first value in a series is an index of one, the
second is an index of two, etc.


```rebol
str: "with all things considered"
print index? str
1

print index? find str "things"
10

blk: [264 "Rebol Dr." "Calpella" CA 95418]
print index? find blk 95418
5
```

Use the OFFSET? function when you need the index difference
between two positions in a series.

------------------------------------------------------------------
## INDEXZ?
------------------------------------------------------------------
## INIT-WORDS
------------------------------------------------------------------
## INPUT
[[ ask confirm ]]

Returns a string from the standard input device
(normally the keyboard, but can also be a file or an
interactive shell). The string does not include
the new-line character used to terminate it.

The /HIDE refinement hides input with "*" characters.


```rebol
prin "Enter a name: "
name: input
print [name "is" length? name "characters long"]
Luke is 4 characters long
```

------------------------------------------------------------------
## INSERT
[[ append change clear remove join ]]

If the value is a series compatible with the first
(block or string-based datatype), then all of its values
will be inserted. The series position just past the
insert is returned, allowing multiple inserts to be
cascaded together.


####### Refinements
/part allows you to specify how many elements you want
to insert.

/only will force a block to be insert, rather than its
individual elements. (Is only done if first argument
is a block datatype.)

/dup will cause the inserted series to be repeated a
given number of times. (Positive integer or zero)

The series will be modified.


```rebol
str: copy "here this"
insert str "now "
print str
now here this

insert tail str " message"
print str
now here this message

insert tail str reduce [tab now]
print str
now here this message   12-Feb-2009/17:47:52-8:00

insert insert str "Tom, " "Tina, "
print str
Tom, Tina, now here this message    12-Feb-2009/17:47:52-8:00

insert/dup str "." 7
print str
.......Tom, Tina, now here this message 12-Feb-2009/17:47:52-8:00

insert/part tail str next "!?$" 1
print str
.......Tom, Tina, now here this message 12-Feb-2009/17:47:52-8:00?

blk: copy ["hello"]
insert blk 'print
probe blk
[print "hello"]

insert tail blk http://www.rebol.com
probe blk
[print "hello" http://www.rebol.com]

insert/only blk [separate block]
probe blk
[[separate block] print "hello" http://www.rebol.com]
```

------------------------------------------------------------------
## INTEGER?
[[ type? ]]

Returns FALSE for all other values.


```rebol
print integer? -1234
true

print integer? "string"
false
```

------------------------------------------------------------------
## INTERN
------------------------------------------------------------------
## INTERSECT
[[ difference union exclude unique ]]

Returns all elements within two blocks or series that 
exist in both.


```rebol
lunch: [ham cheese bread carrot]
dinner: [ham salad carrot rice]
probe intersect lunch dinner
[ham carrot]

probe intersect [1 3 2 4] [3 5 4 6]
[3 4]

string1: "CBAD"    ; A B C D scrambled
string2: "EDCF"    ; C D E F scrambled
probe intersect string1 string2
"CD"

items: [1 1 2 3 2 4 5 1 2]
probe intersect items items  ; get unique set
[1 2 3 4 5]

str: "abcacbaabcca"
probe intersect str str
"abc"
```

To obtain a unique set (to remove duplicate values)
you can use UNIQUE.

Note that performing this function over very large
data sets can be CPU intensive.

------------------------------------------------------------------
## INVALID-UTF?
------------------------------------------------------------------
## ISSUE?
[[ type? ]]

Returns FALSE for all other values.


```rebol
print issue? #1234-5678-9012
true

print issue? #467-8000
true

print issue? $12.56
false
```

------------------------------------------------------------------
## JOIN
[[ ajoin rejoin form reform append repend mold remold ]]

Returns a new [series](https://www.rebol.com/r3/docs/concepts/series.html) that joins together a value with another value or block of values.


```rebol
join "super" "duper"
"superduper"

join %file ".txt"
%file.txt
```

This differs from `append` and `repend` because a new value is created, and the first argument is not modified in any way.

The <b>first argument determines the datatype of the returned value</b>.
When the first argument is a type of [series](https://www.rebol.com/r3/docs/concepts/series.html), the return value will 
be that type of series (d:string, `file!`, `url!`, `block!`, etc.)

When the first argument is a scalar value (such as `integer!`, `date!`, `time!`, and others), the return  will always be a `string!`.

When the second argument is a `block!`, it will be evaluated and all of its values joined 
to the return value.


```rebol
join http:// ["www.rebol.com/" %index.html]
http://www.rebol.com/index.html

join "t" ["e" "s" "t"]
"test"

join 11:11 "PM"
"11:11PM"
```

Note that it also works for `block!` series, but returns a block, not a string:


```rebol
join [1] ["two" 3 "four"]
[1 "two" 3 "four"]
```

And, this case is important to note:


```rebol
join <a> "test"
<atest>
```

(See `rejoin` for more detail on this case.)

If you want the result here to be a `string!`, use the `ajoin` function instead.

------------------------------------------------------------------
## KEYS-OF
------------------------------------------------------------------
## LAST

LAST returns the last value of a series. If the series is empty,
LAST will cause an error.


```rebol
print last "abcde"
e

print last [1 2 3 4 5]
5

print last %file
e

probe last 'system/options
options
```

If you do not want an error when the series is empty, use the 
PICK function instead:


```rebol
string: ""
print pick back tail string 1
none
```

------------------------------------------------------------------
## LAST?
------------------------------------------------------------------
## LATIN1?
[[ ascii? utf8? ]]

```rebol
>> latin1? "mýdlo"
== #(true) ;; because (to integer! #"ý") == 253

>> latin1? "česko"
== #(false) ;; because (to integer! #"č") == 269
```

------------------------------------------------------------------
## LAUNCH
[[ call do ]]

The LAUNCH function is used to run REBOL scripts as a separate
process. When LAUNCH is called, a new process is created and
passed the script file name or URL to be processed. The process
is created as a subprocess of the main REBOL process.

Launch has certain restrictions depending on the REBOL system
used. Also, within Unix/Linux systems, launch will use the
same shell standard files as the main REBOL process, and output
will be merged.


```rebol
launch %calculator.r

launch http://www.rebol.com/scripts/news.r
```

------------------------------------------------------------------
## LCM
------------------------------------------------------------------
## LENGTH?
[[ head tail? offset? ]]

The length? function returns the number of values from the current position of a series to the tail of the series.

For example:


```rebol
print length? "REBOL"
5
```

but, in the case of an offset position from `skip` :


```rebol
print length? skip "REBOL" 2
3
```

or from `find` :


```rebol
print length? find "REBOL" "L"
1
```

Other examples:


```rebol
print length? [1 2 3 4 5]
5

print length? [1 2 3 [4 5]]
4

print length? read http://www.rebol.com
7216

obj: object [a: 10 b: 20]
print length? obj
2
```

------------------------------------------------------------------
## LESSER-OR-EQUAL?
[[ <= < > >= = <> min max ]]

Returns FALSE for all other values. For string-based
datatypes, the sorting order is used for comparison
with character casing ignored (uppercase = lowercase).


```rebol
print lesser-or-equal? "abc" "abd"
true

print lesser-or-equal? 10-June-1999 12-june-1999
true

print lesser-or-equal? 4.3.2.1 1.2.3.4
false

print lesser-or-equal? 1:23 10:00
true
```

------------------------------------------------------------------
## LESSER?
[[ <= > >= = <> min max ]]

Returns FALSE for all other values. The values must be
of the same datatype, or an error will occur. For
string-based datatypes, the sorting order is used for
comparison with character casing ignored (uppercase =
lowercase).


```rebol
print lesser? "abc" "abcd"
true

print lesser? 12-june-1999 10-june-1999
false

print lesser? 1.2.3.4 4.3.2.1
true

print lesser? 1:30 2:00
true
```

------------------------------------------------------------------
## LIBRARY?

Returns TRUE if the value is a LIBRARY datatype.

------------------------------------------------------------------
## LICENSE
[[ about ]]

Returns the REBOL end user license agreement for the currently
running version of REBOL.


```rebol
license
```

For SDK and other specially licensed versions of REBOL, the
license function may return an empty string.

------------------------------------------------------------------
## LIMIT-USAGE
------------------------------------------------------------------
## LIST-DIR
[[ change-dir make-dir what-dir read ]]

Lists the files and directories of the specified path in a
sorted multi-column output. If no path is specified, the
directory specified in system/script/path is listed. Directory
names are followed by a slash (/) in the output listing.


```rebol
list-dir
```

To obtain a block of files for use by your program, use the LOAD
function. The example below returns a block that contains the names of all
files and directories in the local directory.


```rebol
files: load %./
print length? files
probe files
[%autos.txt %build-docs.r %bulk-modify.r %cgi.r %convert-orig.r %CVS/ %emit-html.r %eval-examples.r %fix-args.r %fred/ %funcs.r %helloworld.txt %merge-funcs.r %newfile.txt %notes.txt %public/ %replace.r %scan-doc.r %scan-titles.r %strip-title.r %test-file.txt %trash.me]
```

------------------------------------------------------------------
## LIST-ENV
[[ get-env ]]

This function will return a `map!` of OS environment variables and their values.


```rebol
>> list-env
== #[
    "=::" "::\"
    "ALLUSERSPROFILE" "C:\ProgramData"
    "APPDATA" "C:\Users\oldes\AppData\Roaming"
   ...
```

------------------------------------------------------------------
## LIST-THRU
------------------------------------------------------------------
## LIT-PATH?

Returns true if the value is a literal path datatype.

```rebol
>> lit-path? first ['some/path other/path]
== #(true)

>> lit-path? second ['some/path other/path]
== #(false)
```

------------------------------------------------------------------
## LIT-WORD?
[[ word? set-word? get-word? ]]

Returns FALSE for all other values.


```rebol
>> lit-word? first ['foo bar]
== #(true)
```

------------------------------------------------------------------
## LOAD
[[ save read do import bind ]]

Reads and converts external data, including programs, data
structures, images, and sounds into memory storage objects that
can be directly accessed and manipulated by programs.

The argument to LOAD can be a file, URL, string, or binary
value. When a file name or URL is provided, the data is read
from disk or network first, then it is loaded. In the case of a
string or binary value, it is loaded directly from memory.

Here are a few examples of using LOAD:


```rebol
script: load %dict-notes.r
image: load %image.png
sound: load %whoosh.wav

;data: load http://www.rebol.com/example.r
;data: load ftp://ftp.rebol.com/example.r

data: load "1 2 luke fred@example.com"
code: load {loop 10 [print "hello"]}
```

LOAD is often called for a text file that contains REBOL code or
data that needs to be brought into memory. The text is first
searched for a REBOL header, and if a header is found, it is
evaluated first. (However, unlike the DO function, LOAD does not
require that there be a header.)

If the load results in a single value, it will be returned. If
it results in a block, the block will be returned. No evaluation
of the block will be done; however, words in the block will be
bound to the global context.

If the header object is desired, use the /HEADER option to
return it as the first element in the block.

The /ALL refinement is used to load an entire script as a block.
The header is not evaluated.

The /NEXT refinement was removed - use TRANSCODE/NEXT instead

------------------------------------------------------------------
## LOAD-EXTENSION
------------------------------------------------------------------
## LOAD-JSON
[[ to-json decode ]]

```rebol
>> load-json to-json [1 2 3]
== [1 2 3]

>> load-json to-json #[a: 1 b: "test"]
== #[
    a: 1
    b: "test"
]
```
It is same like using `decode`.
```rebol
>> decode 'json {{"a":1,"b":"test"}}
== #[
    a: 1
    b: "test"
]
```

------------------------------------------------------------------
## LOAD-THRU
------------------------------------------------------------------
## LOG-10
[[ exp log-2 log-e power ]]

The LOG-10 function returns the base-10 logarithm of the number
provided. The argument must be a positive value, otherwise an
error will occur (which can be trapped with the TRY function).


```rebol
print log-10 100
2.0

print log-10 1000
3.0

print log-10 1234
3.091315159697223
```

------------------------------------------------------------------
## LOG-2
[[ exp log-10 log-e power ]]

The LOG-10 function returns the base-2 logarithm of the number
provided. The argument must be a positive value, otherwise an
error will occur (which can be trapped with the TRY function).


```rebol
print log-2 2
1.0

print log-2 4
2.0

print log-2 256
8.0

print log-2 1234
10.26912667914941
```

------------------------------------------------------------------
## LOG-E
[[ exp log-10 log-2 power ]]

The LOG-E function returns the natural logarithm of the number
provided. The argument must be a positive value, otherwise an
error will occur (which can be trapped with the TRY function).


```rebol
print log-e 1234
7.118016204465333

print exp log-e 1234
1234.0
```

------------------------------------------------------------------
## LOGIC?
[[ type? ]]

Returns FALSE for all other values. Note that all
conditional functions will accept more than just a LOGIC
value. A NONE will act as FALSE, and all other values
other than logic will act as TRUE.


```rebol
print logic? true
true

print logic? 123
false
```

------------------------------------------------------------------
## LOOP
[[ repeat for while until do break continue ]]

The `loop` function is the simplest way to repeat the evaluation of a block. This function is very efficient and should be used if no loop counter is required.


```rebol
loop 3 [print "hi"]
hi
hi
hi
```

Here's an example that creates a block of 10 random integers:


```rebol
block: make block! 10
loop 10 [append block random 100]
probe block
[31 25 53 20 40 2 30 79 47 79]
```


###### Returned Value
When finished the `loop` function returns the final value the block:


```rebol
num: 0
print loop 10 [num: num + 1]
10
```


###### Other Notes

```html
<ul>
<li>Negative or zero loop counts do not evaluate the block.</li>
<li>If a <span class="datatype">decimal!</span> count is used, it will be truncated to a lower integer value.</li>
<li>The <a href="#break">break</a> function can be used to stop the loop at any time.</li>
<li>The <a href="#repeat">repeat</a> function is similar to <a href="#loop">loop</a>, except that it allows a variable to keep track of the current loop counter.</li>
</ul>
```

------------------------------------------------------------------
## LOWERCASE
[[ uppercase trim ]]

The series passed to this function is modified as
a result.


```rebol
>> lowercase "ABCDEF"
== "abcdef"

>> lowercase/part "ABCDEF" 3
== "abcDEF"
```

------------------------------------------------------------------
## LS
@@ LIST-DIR

------------------------------------------------------------------
## MAKE
[[ copy type? ]]

The TYPE argument indicates the datatype to create.

The form of the constructor is determined by the
datatype. For most series datatypes, a number indicates
the size of the initial allocation.


```rebol
str: make string! 1000

blk: make block! 10

cash: make money! 1234.56
print cash
$1234.560000000000000

time: make time! [10 30 40]
print time
10:30:40
```

NOTE: MAKE when used with OBJECTS will modify the context of the
spec block (as if BIND was used on it). If you need to reuse the
spec block use MAKE in combination with COPY/deep like this:


```rebol
make object! copy/deep spec
```

------------------------------------------------------------------
## MAKE-BANNER
------------------------------------------------------------------
## MAKE-DIR
[[ change-dir what-dir list-dir delete ]]

Creates a new directory at the specified location. This
operation can be performed for files or FTP URLs.


```rebol
make-dir %New-Dir/
delete %New-Dir/
```

------------------------------------------------------------------
## MAP

Description is needed.

------------------------------------------------------------------
## MAP-EACH

```rebol
>> map-each w [1 2 3][w * 100]
== [100 200 300]
```

------------------------------------------------------------------
## MAP-EVENT

No description provided.

------------------------------------------------------------------
## MAP-GOB-OFFSET

No description provided.

------------------------------------------------------------------
## MAP?

Returns FALSE for all other values.
```rebol
>> map? #[a: 1]
== #(true)

>> map? object [a: 1]
== #(false)
```

------------------------------------------------------------------
## MAX
[[ min maximum-of < > maximum ]]

Returns the maximum of two values.


```rebol
print max 0 100
100

print max 0 -100
0

print max 4.56 4.2
4.56
```

The maximum value is computed by comparison, so MAX can also be
used for non-numeric datatypes as well.


```rebol
print max 1.2.3 1.2.8
1.2.8

print max "abc" "abd"
abd

print max 12:00 11:00
12:00

print max 1-Jan-1920 20-Feb-1952
20-Feb-1952
```

Using MAX on xy pairs will return the maximum of each X and Y
coordinate separately.


```rebol
print max 100x10 200x20
200x20
```

------------------------------------------------------------------
## MAXIMUM
[[ max < > min ]]

See the MAX function for details.

------------------------------------------------------------------
## MIN
[[ max < > minimum-of maximum-of ]]

Returns the minimum of two values.


```rebol
print min 0 100
0

print min 0 -100
-100

print min 4.56 4.2
4.2
```

The minimum value is computed by comparison, so MIN can also be
used for non-numeric datatypes as well.


```rebol
print min 1.2.3 1.2.8
1.2.3

print min "abc" "abd"
abc

print min 12:00 11:00
11:00

print min 1-Jan-1920 20-Feb-1952
1-Jan-1920
```

Using min on xy pairs will return the minimum of each X and Y
coordinate separately.


```rebol
print min 100x10 200x20
100x10
```

------------------------------------------------------------------
## MINIMUM
[[ < > min max ]]

See the MIN function for details.

------------------------------------------------------------------
## MKDIR
[[ cd change-dir delete list-dir ls make-dir pwd rm what-dir ]]

Note: Shell shortcut for `make-dir`.

------------------------------------------------------------------
## MOD
[[ modulo // remainder round ]]

Similar to REMAINDER, but the result is always non-negative.

------------------------------------------------------------------
## MODIFIED?
[[ exists? ]]

Returns NONE if the file does not exist.


```rebol
print modified? %file.txt
none
```

------------------------------------------------------------------
## MODIFY
------------------------------------------------------------------
## MODULE

Description is needed.

------------------------------------------------------------------
## MODULE?

Returns FALSE for all other values.
```rebol
>> module? object [a: 1]
== #(false)

>> module? system/modules/help
== #(true)
```

------------------------------------------------------------------
## MODULO
[[ mod // remainder round ]]

See MOD for details.

------------------------------------------------------------------
## MOLD
[[ form remold join insert reduce ]]

The `mold` function converts values to a source-code formatted string (REBOL-readable).


```rebol
print mold 10:30
10:30

print mold %image.jpg
%image.jpg

print mold [1 2 3]
[1 2 3]
```

The primary importance of `mold` is to produce strings that can be reloaded with `load`.


```rebol
str: mold [1 + 2]
probe load str
[1 + 2]
```

The `mold` function is the cousin of `form` which produces a human-readable string (used by the `print` function.) For example a block will be shown with brackets [ ] and strings will be " " quoted or use braces { } (if it is long or contains special characters).

Also, `remold` first uses `reduce` then `mold`.


###### The /only Refinement
In some cases it is useful to not `mold` the outermost brackets of blocks. This is done with the /only refinement:


```rebol
print mold/only [1 2 3]
1 2 3
```

This is commonly true for blocks of values that are saved to files:


```rebol
write %example.r mold/only [1 2 3]
```

See the `save` function.


###### The /all Refinement
For some values `mold` produces an approximate string value, not a perfect representation. If you attempt to load such a string, its value may be different.

For example:


```rebol
mold 'true
"true"

mold true
"true"
```

The first is the word true the second is the `logic!` value true -- they are different but represented by the same word. If you `load` the resulting string, you will only obtain the word true not the logic value:


```rebol
type? load mold true
word!
```

The /all option provides a more accurate transformation from values to strings and back (using `load`.)


```rebol
mold/all 'true
"true"

mold/all true
"#[true]"
```

Using `load`, you can see the difference:


```rebol
type? load mold/all 'true
word!

type? load mold/all true
logic!
```

Another difference occurs with strings that are indexed from their `head` positions. Sometimes this is desired, sometimes not. It can be seen here:


```rebol
mold next "ABC"
"BC"

mold/all next "ABC"
{#[string! "ABC" 2]}
```


####### Affected Datatypes
The following datatypes are affected: `unset!`, `none!`, `logic!`, `bitset!`, `image!`, `map!`, `datatype!`, `typeset!`, `native!`, `action!`, `op!`, `closure!`, `function!`, `object!`, `module!`, `error!`, `task!`, `port!`, `gob!`, `event!`, `handle!`.


```html
<fieldset class="fset"><legend>Note on Restoring Semantics</legend>
<p>It should also be noted that some datatypes cannot be returned to a source form without losing semantic information. For example, functions cannot maintain the binding (scoping context) of their words. If such semantics reproduction is required it is recommended that your code output entire blocks that as a whole are evaluated to produce the correct semantic result. This is commonly done in REBOL code, including the common storage of mezzanine and module functions and other definitions.</p>
</fieldset>
```


####### Accuracy of Decimals
The `decimal!` datatype is implemented as IEEE 754 binary floating point type. When molding `decimal!` values, mold/all will need to use the maximal precision 17 digits to allow for accurate transformation of Rebol decimals to string and back, as opposed to just `mold`, which uses a default precision 15 decimal digits.


###### The /flat Refinement
The /flat refinement is useful for minimizing the size of source strings. It properly removes leading indentation (from code lines, but not multi-line strings.) The /flat option is often used for data exchanged between systems or stored in files.

Here is code often used for saving a script in minimal format (in R3):


```rebol
write %output.r mold/only/flat code
```

For code larger than about 1K, you can also compress it:


```rebol
write %output.rc compress mold/only/flat code
```

Such a file can be reloaded with:


```rebol
load/all decompress read %output.rc
```

Note that if using R2, these lines must be modified to indicate binary format.


###### Code Complexity Comparisons
It should be noted that `mold` function is used for computing the relative complexity of code using the [Load Mold Sizing method](http://www.rebol.net/wiki/Load_Mold_Sizes).

------------------------------------------------------------------
## MOLD64
------------------------------------------------------------------
## MONEY?
[[ type? ]]

Returns FALSE for all other values.


```rebol
print money? $123
true

print money? 123.45
false
```

------------------------------------------------------------------
## MORE

Description is needed.

------------------------------------------------------------------
## MOVE

Description is needed.

------------------------------------------------------------------
## MULTIPLY
[[ / // divide ]]

The datatype of the second value may be restricted to
INTEGER or DECIMAL, depending on the datatype of the
first value (e.g. the first value is a time).


```rebol
print multiply 123 10
1230

print multiply 3:20 3
10:00

print multiply 0:01 60
1:00
```

------------------------------------------------------------------
## NATIVE?
[[ type? ]]

Returns FALSE for all other values. When passing a
function to NATIVE? to be checked, it must be denoted
with ":". This is because the ":word" notation passes a
word's reference, not the word's value. NATIVE? can only
determine whether or not a function is a native if it is
passed the function's reference.


```rebol
probe native? :native?   ; it's actually an ACTION!
false

probe native? "Vichy"
false

probe native? :if
true
```

------------------------------------------------------------------
## NEGATE
[[ + - positive? negative? complement not ]]

Returns the negative of the value provided.


```rebol
print negate 123
-123

print negate -123
123

print negate 123.45
-123.45

print negate -123.45
123.45

print negate 10:30
-10:30

print negate 100x20
-100x-20

print negate 100x-20
-100x20
```

------------------------------------------------------------------
## NEGATIVE?
[[ positive? ]]

Returns FALSE for all other values.


```rebol
print negative? -50
true

print negative? 50
false
```

------------------------------------------------------------------
## NEW-LINE
[[ new-line? ]]

Where the NEW-LINE? function queries the status of the a 
block for markers, the NEW-LINE function inserts or removes 
them. You can use it to generate formatted blocks.

Given a block at a specified offset, new-line? will return 
true if there is a marker at that position.


```rebol
dent-block: func [
    "Indent the contents of a block"
    block
][
    head new-line tail new-line block on on
]

b: [1 2 3 4 5 6]
probe dent-block b
[

1 2 3 4 5 6
```

]

If you want to put each item in a block on a new line, you 
can insert markers in bulk, using the /all refinement.


```rebol
b: [1 2 3 4 5 6]
probe new-line/all b on
[

1
2
3
4
5
6
```

]

If you don't know whether a block contains markers, you may 
want to remove all markers before formatting the data.


```rebol
b: [
    1 2 
    3 4
]
probe new-line/all b off
[1 2 3 4]
```

Another common need is formatting blocks into lines of fixed 
size groups of items; that's what the /skip refinement is for.


```rebol
b: [1 2 3 4 5 6]
probe new-line/skip b on 2
[

1 2
3 4
5 6
```

]

------------------------------------------------------------------
## NEW-LINE?
[[ new-line ]]

Given a block at a specified offset, new-line? will return 
true if there is a line marker at that position.


```rebol
b: [1 2 3 4 5 6]
forall b [if new-line? b [print index? b]]

b: [
    1 2
    3 4
    5 6
]
forall b [if new-line? b [print index? b]]
5
```

------------------------------------------------------------------
## NEXT
[[ back first head tail head? tail? ]]

If the series is at its tail, it will remain at its
tail. NEXT will not go past the tail, nor will it wrap
to the head.


```rebol
print next "ABCDE"
BCDE

print next next "ABCDE"
CDE

print next [1 2 3 4]
2 3 4

str: "REBOL"
loop length? str [
    print str
    str: next str
]
L

blk: [red green blue]
loop length? blk [
    probe blk
    blk: next blk
]
[blue]
```

------------------------------------------------------------------
## NINTH
[[ first second third pick ]]

See the FIRST function for examples.

An error will occur if no value is found. Use the PICK function to avoid this error.

------------------------------------------------------------------
## NONE?

Returns FALSE for all other values.


```rebol
print none? NONE
true

print none? pick "abc" 4
true

print none? find "abc" "d"
true
```

------------------------------------------------------------------
## NOT
[[ complement negate and or xor unless ]]

The `not` function is a `logic!` function that returns true if the value is false or none. It will return false for all other values.


```rebol
not true
false

not none
true

not (10 = 1)
true

not 0
false  ; take note of this

not 1
false
```

To complement an `integer!` use the `complement` function or `negate` function.

------------------------------------------------------------------
## NOT-EQUAL?
[[ <> = == equal? ]]

String-based datatypes are considered equal when they
are identical or differ only by character casing
(uppercase = lowercase). Use `==` or find/match/case to
compare strings by casing.


```rebol
print not-equal? "abc" "abcd"
true

print not-equal? [1 2 4] [1 2 3]
true

print not-equal? 12-sep-98 10:30
true
```

------------------------------------------------------------------
## NOT-EQUIV?
------------------------------------------------------------------
## NOW
[[ date? ]]

For accuracy, first verify that the time, date and
timezone are correctly set on the computer.


```rebol
print now
12-Feb-2009/17:47:54-8:00

print now/date
12-Feb-2009

print now/time
17:47:54

print now/zone
-8:00

print now/weekday
4
```

------------------------------------------------------------------
## NUMBER?
[[ integer? decimal? ]]

Returns FALSE for all other values.


```rebol
>> number? 1234
== #(true)

>> number? 12.3
== #(true)

>> number? "12"
== #(false)
```

------------------------------------------------------------------
## OBJECT

No description provided.

------------------------------------------------------------------
## OBJECT?
[[ type? ]]

Returns FALSE for all other values.
```rebol
>> object? system
== #(true)

>> object? 1
== #(false)
```

------------------------------------------------------------------
## ODD?
[[ even? ]]

Returns TRUE only if the argument is an odd integer value.
If the argument is a decimal, only its integer portion is
examined.


```rebol
print odd? 3
true

print odd? 100
false

print odd? 0
false
```

------------------------------------------------------------------
## OFFSET?
[[ index? length? head head? tail tail? pick skip ]]

Return the difference of the indexes for two positions within a
series.


```rebol
str: "abcd"
p1: next str
print offset? str p1
1

str: "abcd"
p1: next str
p2: find str "d"
print offset? p1 p2
2
```

------------------------------------------------------------------
## OP?

Returns FALSE for all other values.


```rebol
print op? :and
true

print op? :+
true
```

------------------------------------------------------------------
## OPEN
[[ close load do insert remove read write query ]]

Opens a port for I/O operations. The value returned from
OPEN can be used to examine or modify the data
associated with the port. The argument must be a
fully-specified port specification, an abbreviated port
specification such as a file path or URL, or a block
which is executed to modify a copy of the default port
specification.


```rebol
autos: open/new %autos.txt
insert autos "Ford"
insert tail autos " Chevy"
close autos
print read %autos.txt
```

------------------------------------------------------------------
## OPEN?

Description is needed.

------------------------------------------------------------------
## OR
[[ and not xor ]]

An infix-operator. For LOGIC values, both must be FALSE
to return FALSE; otherwise a TRUE is returned. For
integers, each bit is separately affected. Because it is
an infix operator, OR must be between the two values.


```rebol
print true or false
true

print (10 > 20) or (20 < 100)
true

print 122 or 1
123

print 1.2.3.4 or 255.255.255.0
255.255.255.4
```

------------------------------------------------------------------
## OR~
[[ and~ xor~ ]]

The trampoline action function for OR operator.

------------------------------------------------------------------
## PAD
------------------------------------------------------------------
## PAIR?
[[ to-pair as-pair ]]

Returns true if the value is an xy pair datatype.


```rebol
print pair? 120x40
true

print pair? 1234
false
```

See the PAIR! word for more detail.

------------------------------------------------------------------
## PAREN?
[[ type? ]]

Returns FALSE for all other values. A paren is identical
to a block, but is immediately evaluated when found.


```rebol
print paren? second [123 (456 + 7)]
true

print paren? [1 2 3]
false
```

------------------------------------------------------------------
## PARSE
[[ trim ]]

The `parse` function is used to match patterns of values and perform specific actions upon  such matches. A full summary can be found in [parsing: summary of parse operations](https://www.rebol.com/r3/docs/concepts/parsing-summary.html) .

Both `string!` and `block!` datatypes can be parsed. Parsing of strings matches specific characters or substrings. Parsing of blocks matches specific values, or specific datatypes, or sub-blocks.

Whereas most languages provide a method of parsing strings, the parsing of blocks is an important feature of the REBOL language.

The `parse` function takes two main arguments: an input to be parsed and the rules that are used to parse it. The rules are specified as a block of grammar productions that are to be matched.


###### General parse rules
Rules consist of these main elements:


```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Item
</th><th valign="top">
Description
</th>
<tr>
<td valign="top" bgcolor="white" >
keyword </td><td valign="top" bgcolor="white"> a special word of the dialect, listed in the table below
</td>
<tr>
<td valign="top" bgcolor="white" >
word </td><td valign="top" bgcolor="white"> get or set a variable (see below) - cannot be a keyword
</td>
<tr>
<td valign="top" bgcolor="white" >
path </td><td valign="top" bgcolor="white"> get or set a variable via a path (see below)
</td>
<tr>
<td valign="top" bgcolor="white" >
value </td><td valign="top" bgcolor="white"> match the input to a value (accepted datatypes depend on input datatype)
</td>
<tr>
<td valign="top" bgcolor="white" >
"|" </td><td valign="top" bgcolor="white"> backtrack and match to next alternate rule (or)
</td>
<tr>
<td valign="top" bgcolor="white" >
[block] </td><td valign="top" bgcolor="white"> a block of sub-rules
</td>
<tr>
<td valign="top" bgcolor="white" >
(paren) </td><td valign="top" bgcolor="white"> evaluate an expression (a production)
</td></tr></table>
```


###### List of keywords
Within the parse dialect, these words are treated as keywords and cannot be used as variables.


```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Keyword
</th><th valign="top">
Description
</th>
<tr>
<td valign="top" bgcolor="white" >
and rule
</td><td valign="top" bgcolor="white">
match the rule, but do not advance the input (allows matching multiple rules to the same input)
</td>
<tr>
<td valign="top" bgcolor="white" >
any rule
</td><td valign="top" bgcolor="white">
match the rule zero or more times; stop on failure or if input does not change.
</td>
<tr>
<td valign="top" bgcolor="white" >
break
</td><td valign="top" bgcolor="white">
break out of a match loop (such as any, some, while), always indicating success.
</td>
<tr>
<td valign="top" bgcolor="white" >
change rule <i>only</i> value
</td><td valign="top" bgcolor="white">
match the rule, and if true, change the input to the new value (can be different lengths)
</td>
<tr>
<td valign="top" bgcolor="white" >
copy word
</td><td valign="top" bgcolor="white">
set the word to a copy of the input for matched rules
</td>
<tr>
<td valign="top" bgcolor="white" >
do rule </td><td valign="top" bgcolor="white"> evaluate the input as code, then attempt to match to the rule
</td>
<tr>
<td valign="top" bgcolor="white" >
end
</td><td valign="top" bgcolor="white">
match end of input
</td>
<tr>
<td valign="top" bgcolor="white" >
fail
</td><td valign="top" bgcolor="white">
force current rule to fail, backtrack
</td>
<tr>
<td valign="top" bgcolor="white" >
if (expr)
</td><td valign="top" bgcolor="white">
evaluate the expression (in a paren) and if false or none, fail and backtrack
</td>
<tr>
<td valign="top" bgcolor="white" >
insert <i>only</i> value
</td><td valign="top" bgcolor="white">
insert a value at the current input position (with optional ONLY for blocks by reference); input position is adjusted just past the insert
</td>
<tr>
<td valign="top" bgcolor="white" >
into rule
</td><td valign="top" bgcolor="white">
match a series, then parse it with given rule; new series can be the same or different datatype.
</td>
<tr>
<td valign="top" bgcolor="white" >
opt rule
</td><td valign="top" bgcolor="white">
match to the rule once or not at all (zero or one times)
</td>
<tr>
<td valign="top" bgcolor="white" >
not rule
</td><td valign="top" bgcolor="white">
invert the result of the next rule
</td>
<tr>
<td valign="top" bgcolor="white" >
quote arg
</td><td valign="top" bgcolor="white">
accept next argument exactly as is (exception: paren)
</td>
<tr>
<td valign="top" bgcolor="white" >
reject
</td><td valign="top" bgcolor="white">
similar to break: break out of a match loop (such as any, some, while), but indicate failure.
</td>
<tr>
<td valign="top" bgcolor="white" >
remove rule
</td><td valign="top" bgcolor="white">
match the rule, and if true, remove the matched input
</td>
<tr>
<td valign="top" bgcolor="white" >
return rule
</td><td valign="top" bgcolor="white">
match the rule, and if true, immediately return the matched input as result of the PARSE function
</td>
<tr>
<td valign="top" bgcolor="white" >
set word
</td><td valign="top" bgcolor="white">
set the word to the value of the input for matched rules
</td>
<tr>
<td valign="top" bgcolor="white" >
skip
</td><td valign="top" bgcolor="white">
skip input (for the count range, if provided before it)
</td>
<tr>
<td valign="top" bgcolor="white" >
some rule
</td><td valign="top" bgcolor="white">
match to the rule one or more times; stop on failure or if input does not change.
</td>
<tr>
<td valign="top" bgcolor="white" >
then </td><td valign="top" bgcolor="white"> regardless of failure or success of what follows, skip the next alternate rule (branch)
</td>
<tr>
<td valign="top" bgcolor="white" >
thru rule
</td><td valign="top" bgcolor="white">
scan forward in input for matching rules, advance input to tail of the match
</td>
<tr>
<td valign="top" bgcolor="white" >
to rule
</td><td valign="top" bgcolor="white">
scan forward in input for matching rules, advance input to head of the match
</td>
<tr>
<td valign="top" bgcolor="white" >
while rule
</td><td valign="top" bgcolor="white">
like any, match to the rule zero or more times; stop on failure; does not care if input changes or not.
</td>
<tr>
<td valign="top" bgcolor="white" >
??
</td><td valign="top" bgcolor="white">
Debugging output. Prints the next parse rule value and shows the current input position (e.g. where you are in the string.)
</td></tr></table>
```

In addition, none is a special value that can be used as a default match rule. It is often used at the end of alternate rules to catch all no-match cases.


###### Simple Parse
There is also a simple parse
mode that does not require rules, but takes a string of
characters to use for splitting up the input string.

Parse also works in conjunction with bitsets (charset)
to specify groups of special characters.

The result returned from a simple parse is a block of
values. For rule-based parses, it returns TRUE if the
parse succeeded through the end of the input string.


```rebol
print parse "divide on spaces" none
divide on spaces

print parse "Harry Haiku, 264 River Rd., Ukiah, 95482" ","
Harry Haiku 264 River Rd. Ukiah 95482

page: read http://hq.rebol.net
parse page [thru <title> copy title to </title>]
print title
Now is REBOL

digits: charset "0123456789"
area-code: ["(" 3 digits ")"]
phone-num: [3 digits "-" 4 digits]
print parse "(707)467-8000" [[area-code | none] phone-num]
true
```

------------------------------------------------------------------
## PAST?

Description is needed.

------------------------------------------------------------------
## PATH?
[[ make ]]

Returns FALSE for all other values.


```rebol
print path? first [random/seed 10]
true
```

------------------------------------------------------------------
## PATH-THRU
------------------------------------------------------------------
## PERCENT?

Returns FALSE for all other values.
```rebol
>> percent? 10%
== #(true)

>> percent? 10
== #(false)
```

------------------------------------------------------------------
## PICK
[[ first second third fourth fifth find select ]]

The value is picked relative to the current position in
the series (not necessarily the head of the series).
The VALUE argument may be INTEGER or LOGIC. A positive
integer positions forward, a negative positions
backward. If the INTEGER is out of range, NONE is
returned. If the value is LOGIC, then TRUE refers to the
first position and FALSE to the second (same order as
EITHER). An attempt to pick a value beyond the limits
of the series will return NONE.


```rebol
str: "REBOL"

print pick str 2
E

print pick 199.4.80.1 3
80

print pick ["this" "that"] now/time > 12:00
this
```

------------------------------------------------------------------
## PICKZ
------------------------------------------------------------------
## POKE
[[ pick change ]]

Similar to CHANGE, but also takes an index into the series.


```rebol
str: "ABC"
poke str 2 #"/"
print str
A/C

print poke 1.2.3.4 2 10
10
```

------------------------------------------------------------------
## POKEZ
------------------------------------------------------------------
## PORT?
[[ type? ]]

Returns FALSE for all other values.


```rebol
file: open %newfile.txt
print port? file
close file
true

print port? "test"
false
```

------------------------------------------------------------------
## POSITIVE?
[[ negative? ]]

Returns FALSE for all other values.


```rebol
print positive? 50
true

print positive? -50
false
```

------------------------------------------------------------------
## POWER
[[ exp log-10 log-2 log-e ]]

```rebol
print power 12.3 5
281530.5684300001
```

------------------------------------------------------------------
## PREMULTIPLY
------------------------------------------------------------------
## PRIN
[[ print input echo ]]

No line termination is used, so the next value printed
will appear on the same line. If the value is a block,
each of its values will be evaluated first then printed.


```rebol
prin "The value is "
prin [1 + 2]

prin ["The time is" now/time]
```

------------------------------------------------------------------
## PRINT
[[ prin probe ?? form reform format mold remold ajoin join rejoin input echo ]]

The `print` function outputs values in "human-friendly" format (without source code syntax.)


```rebol
print 1234
1234

print "Example"
Example

print read %file.txt
(file output)

print read http://www.rebol.com
(web page output)
```

If the value is a block, it will be processed by `reduce` to evaluate each of its values, which will then be output:


```rebol
print ["The time is" now/time]
The time is 17:47:54

print ["You are using REBOL" system/product system/version]
You are using REBOL core 3.0.0.3.1
```


###### Removing Spaces
If you need to join strings and values together for output, use the `ajoin`, `join`, or `rejoin` functions.


```rebol
print ajoin ["REBOL/" system/product " V" system/version/1]]
REBOL/core V3

print ajoin ["The time is " 11:30 "AM"]
The time is 11:30AM
```


###### Related Functions
If a newline is not desired, use `prin` which does not terminate the output:


```rebol
prin "T"
print "est"
Test
```

The `print` function is based on the `reform` function, which combines the `reduce` and `form` functions.

Notice the difference between:


```rebol
str: reform ["The time is" now/time]
print str
The time is 17:47:54
```

and:


```rebol
str: form ["The time is" now/time]
print str
The time is now/time
```

The alternative to `form` is `mold` which produces source code string output, and `remold` combines `reduce` with `mold` in the same way.


```rebol
str: mold ["The time is" now/time]
print str
["The time is" now/time]

str: mold ["The time is" now/time]
print str
["The time is" 17:47:54]
```

The `probe` function is similar to `print` but is defined as:


```rebol
probe: func [value] [print mold :value :value]
```

The second use of value is to cause `probe` to return the value it was passed.

If you want to copy `print` output to a file as well as the console, use the `echo` function.


```rebol
echo %output.txt
print "Copying to file"
```

------------------------------------------------------------------
## PRINT-HORIZONTAL-LINE
------------------------------------------------------------------
## PRINT-TABLE
------------------------------------------------------------------
## PRINTF

Description is needed.

------------------------------------------------------------------
## PROBE
[[ ?? mold print trace source help what ]]

The `probe` function will `mold` a value into reloadable source format and display it.


```rebol
num: 1
probe [num + 2 "ABC"]
[num + 2 "ABC"]
```

Compare with the `print` function which will `reduce` the block:


```rebol
print [num + 2 "ABC"]
3 ABC
```


###### Return Value
The `probe` function also returns its argument value as its result, making it easy to insert into code for debugging purposes.

Examples:


```rebol
n: probe 1 + 2
3

print n
3

print 2 * probe pi * probe sine 45
0.707106781186547
2.22144146907918
4.44288293815837

word: 'here
if probe find [where here there] word [print "found"]
[here there]
found
```

See the `print` function for information about related functions.

------------------------------------------------------------------
## PROFILE
------------------------------------------------------------------
## PROTECT
[[ unprotect secure set ]]

The `protect` function provides the following features:


```html
<ul>
<li>protects <span class="datatype">string!</span>, <span class="datatype">block!</span>, and other series from modification (making them read-only.)</li>
<li>protects variables (words) from being <a href="#set">set</a> to new values.</li>
<li>protects <span class="datatype">object!</span>, <span class="datatype">module!</span>, and <span class="datatype">map!</span> from modification (by protecting all its words.)</li>
<li>hide words within objects or modules - making them private - a method of read and write protection.</li>
</ul>
```


###### Synopsis
The `protect` argument and refinements provide these various protections:


```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Argument
</th><th valign="top">
Refinement
</th><th valign="top">
Protection provided
</th>
<tr>
<td valign="top" bgcolor="white" >
<span class="datatype">word!</span> or <span class="datatype">path!</span> </td><td valign="top" bgcolor="white"> </td><td valign="top" bgcolor="white"> cannot <a href="#set">set</a> the word (variable)
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="datatype">word!</span> or <span class="datatype">path!</span> </td><td valign="top" bgcolor="white"> /hide </td><td valign="top" bgcolor="white"> cannot <a href="#bind">bind</a> to the word (variable)
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="datatype">string!</span> </td><td valign="top" bgcolor="white"> </td><td valign="top" bgcolor="white"> cannot modify the string
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="datatype">block!</span> </td><td valign="top" bgcolor="white"> </td><td valign="top" bgcolor="white"> cannot modify the block
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="datatype">block!</span> </td><td valign="top" bgcolor="white"> /deep </td><td valign="top" bgcolor="white"> cannot modify block or any series within it
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="datatype">block!</span> </td><td valign="top" bgcolor="white"> /words </td><td valign="top" bgcolor="white"> cannot <a href="#set">set</a> listed words or paths (variables)
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="datatype">block!</span> </td><td valign="top" bgcolor="white"> /hide </td><td valign="top" bgcolor="white"> cannot <a href="#bind">bind</a> to listed words or paths
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="datatype">object!</span> </td><td valign="top" bgcolor="white"> </td><td valign="top" bgcolor="white"> cannot modify object or <a href="#set">set</a> its words (variables)
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="datatype">object!</span> </td><td valign="top" bgcolor="white"> /deep </td><td valign="top" bgcolor="white"> cannot modify object, <a href="#set">set</a> its words, or modify any of its series values
</td></tr></table>
```


###### Protecting series (strings and blocks)
For example to use `protect` to prevent modification to a string:


```rebol
test: "text"
protect test
append test "a"
** Script error: protected value or series - cannot modify
```

The text string itself is now read-only. Any attempt to modify it will result in that
error message.

This also applies to other series:


```rebol
test: [100 "example" 10:20]
protect test
append test 1.2
** Script error: protected value or series - cannot modify
```

But notice:


```rebol
print append test/2 "x"
examplex
```

So, series within the block are still modifiable.

To protect all series found within a block, use the /deep refinement:


```rebol
test: [100 "example" 10:20]
protect/deep test
print append test/2 "x"
** Script error: protected value or series - cannot modify
```


###### Protecting objects and modules
It can also be applied to objects and modules, where its meaning becomes: do not let the fields of the object be modified. However, the contents of those fields can still be modified.


```rebol
person: make object! [
     name: "Bob"
     age: 32
]
protect person
person/name: "Ted"
** Script error: protected variable - cannot modify: name
```

However, you can still modify the contents of the name string:


```rebol
append person/name "a"
print person/name
Boba
```

To prevent that, you call `protect` with the /deep refinement to protect all series within the object:


```rebol
person: make object! [
     name: "Bob"
     age: 32
]
protect/deep person
append person/name "a"
** Script error: protected value or series - cannot modify
```


###### Protecting variables (words)
Protect can also be used to prevent a variable word from being modified using a set operation.


```rebol
test: "This word is protected!"
protect 'test
test: 123
** Script error: protected variable - cannot modify: test
```


###### Hiding variables (words)
To make a variable private, use the /hide refinement. In effect, this prevents any further bindings to the variable. It also blocks attempts at `select`, `in`, `get`, `mold`, and `form`, as well as `reflect` access.

For example, here is an object that defines a password variable that is hidden.
Once the object has been created, the pass variable is not accessible, except with the functions defined prior to the `protect`.


```rebol
manager: object [

    pass: none

    set-pass: func [pw][
        print "setting password..."
        pass: pw
        exit ; return nothing
    ]

    get-pass: does [
        checksum/secure to-binary pass
    ]

    protect/hide 'pass
]
```

The password can be accessed with the provided functions:


```rebol
manager/set-pass "bingo"
setting password...

print manager/get-pass
#{E410B808A7F76C6890C9ECACF2B564EC98204FDB}
```

But any other access is not allowed:


```rebol
probe manager/pass
** Script error: cannot access pass in path manager/pass

probe get in manager 'pass
none

probe select manager 'pass
none

probe words-of manager
[set-pass get-pass]
```

For security reasons, once hidden, a variable cannot be unhidden.


###### Compatibility

```html
<fieldset class="fset"><legend>Non-compatibility with R2</legend>
<p>When using a block with <a href="#protect">protect</a>, the meaning is not to protect the words of the block, but to protect the block series itself.</p>
<p>If you need the behavior of R2, use the /words refinement.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">protect/words [test this]</code></pre></div>
<p>Will protect the test and this variables.</p>
</fieldset>
```


###### Related articles

```html
<ul>
<li><a href="http://www.rebol.net/r3blogs/0186.html" class="lnk">Read-only strings, blocks, and objects</a></li>
<li><a href="http://www.rebol.net/r3blogs/0187.html" class="lnk">Interesting insights from PROTECT</a></li>
</ul>
```

(From the A43 release.)

------------------------------------------------------------------
## PROTECT-SYSTEM-OBJECT
------------------------------------------------------------------
## PROTECTED?
------------------------------------------------------------------
## PUT
------------------------------------------------------------------
## PWD
[[ cd change-dir delete list-dir ls make-dir mkdir rm what-dir ]]

Note: Shell shortcut for `what-dir`.

------------------------------------------------------------------
## Q
[[ halt exit quit ]]

Shortcut for QUIT.

See QUIT for details.

------------------------------------------------------------------
## QUERY
[[ open update ]]

Its argument is an unopened port specification. The
size, date and status fields in the port specification
will be updated with the appropriate information if the
query succeeds.

------------------------------------------------------------------
## QUIT
[[ halt exit q ]]

You can call `quit` to exit (terminate) your program at any point.


```rebol
time: 10:00
if time > 12:00 [
    print "time for lunch"
    quit
]
```

Without refinements, `quit` is a non-forceful exception (it will `throw` a quit exception.) This behavior allows a parent program to stop the termination.

To force an immediate quit (no exception), use the /now refinement:


```rebol
if bad-data [quit/now]
```

You can also return an `integer!` quit code to the operating system (shell) by using the `return` refinement:


```rebol
quit/return 40
```

Note that not all operating systems environments may support this quit code.


```html
<fieldset class="fset"><legend>Rarely used</legend>
<p>Most programs do not require <a href="#quit">quit</a>, and it can be problematic if your code is started by another REBOL program. Normally, when your program reaches the end, it will quit by itself. (If you want to prevent that behavior, use the -h command line option, or call <a href="#halt">halt</a> at the end of your code.)</p>
</fieldset>
```

------------------------------------------------------------------
## QUOTE
------------------------------------------------------------------
## RANDOM
[[ checksum now ]]

The value passed can be used to restrict the range of
the random result. For integers random begins at one,
not zero, and is inclusive of the value given. (This
conforms to the indexing style used for all series
datatypes, allowing random to be used directly with
functions like PICK.)


```rebol
loop 3 [print random 10]
1
5
3

lunch: ["Italian" "French" "Japanese" "American"]
print pick lunch random 4
American
```

If the given argument is a logic value, the result is actually the same as the result of the expression


```rebol
even? random 2
```

Example


```rebol
loop 4 [print random true]
false
false
false
true

loop 2 [print random 1:00:00]
0:12:20
0:48:22
```

For decimal value the function generates a uniformly distributed random number between zero (inclusive) and the given value (inclusive).


```rebol
loop 3 [print random 1.0]
0.209417212061865
0.878424991742667
0.93627033045037
```

Main properties:

<ol>
<li>the probability density in the interior points is the reciprocal of the given decimal VALUE argument</li>
<li>the probability density in the exterior points is 0.0</li>
<li>as specified by IEEE754, the bounds represent "close" interior well as "close" exterior real numbers. Therefore, the frequency of every bound corresponds to the length of the segment containing adjacent interior real values (real numbers, that are IEEE 754 - rounded to the value of the bound) multiplied by the interior density equal to the reciprocal of the given VALUE</li>
</ol>
RANDOM can also be used on all series datatypes:


```rebol
print random "abcdef"
dbcafe

print random [1 2 3 4 5]
2 4 5 3 1
```

In this case RANDOM randomly shuffles the given series "in place", yielding the original series with the same elements, just shuffled.
To cut it down, you can use CLEAR:


```rebol
key: random "abcdefghijklmnopqrstuv0123456789"
clear skip key 6
print key
anfruk
```

Here's an example password generator. Add more partial words
to get more variations:


```rebol
syls: ["ca" "ru" "lo" "ek" "-" "." "!"]
print rejoin random syls
.!ru-ekcalo
```

To initialize the random number generator, you can seed it with a value (to repeat the sequence) or the current time to start a unique seed.


```rebol
random/seed 123

random/seed now
```

That last line is a good example to provide a fairly random
starting value for the random number generator.

The /SECURE variant uses SHA1() of a repeating pattern of the integer bytes (20 bytes total) and it produces cryptographically secure 64-bit random numbers. Cryptographical security means, that it is infeasible to compute the state of the generator from its output. If you don't need to make computing of the generator state infeasible (needed especially when you use the generator to generate passwords, challenges, etc. and want to comply to the FIPS security standards), it is more efficient to use the raw variant (without /SECURE refinement). Even in that case it is not feasible to compute the state, since the state of present generator consists of too many bits to be computable from the output.


###### Algorithm
The RANDOM function uses a random generator by Donald E. Knuth adjusted to generate 62-bit random integers. Thus, the maximal obtainable random number is 2 to the power of 62 = 4611686018427387904.

If the RANDOM function obtains 0 as an argument, it yields 0. If the argument is a positive integer, the RANDOM function uses rejection, rejecting all "raw randoms" that exceed the largest obtainable multiple of the given VALUE argument. This way, the uniformity of the distribution is assured. In case the given VALUE exceeds the biggest obtainable "raw random", we would have to reject every "raw random" number, so in that case an overflow error is caused (It certainly is an error expecting a bigger random, than the "raw random" maximum).

If the given VALUE is negative, then the generated random integers are in the interval VALUE <= R <= -1.</p>
Uniformly distributed random decimals are generated using the integer output of the Knuth's generator as follows:


```rebol
tt62: to integer! 2 ** 62
4611686018427387904

random-dec: func [x [decimal!]] [(to decimal! (random tt62) - 1) / tt62 * x]

random/seed 0
random 1.0
0.209417212061865

random/seed 0
random-dec 1.0
0.209417212061865
```

In case the given decimal VALUE is positive, the generated random deviates are uniformly distributed in the interval 0.0 <= R <= VALUE, i.e. including bounds.</p>
In case the given decimal VALUE is negative, the random deviates are uniformly distributed in the interval VALUE <= R <= 0.0.</p>
Sometimes we need to obtain a uniformly distributed random number R, such that 0.0 < R < 1.0 (i.e. a uniformly distributed random number in the given interval, excluding the bounds). We can get such an R rejecting the bounds as follows:</p>

```rebol
random/seed 0
until [
    r: random 1.0
    all [
        r !== 0.0
        r !== 1.0
    ]
]
r
0.209417212061865
```

------------------------------------------------------------------
## RC4
------------------------------------------------------------------
## READ
[[ write open close load save ]]

Using READ is the simplest way to get information from
a file or URL. This is a higher level port operation
that opens a port, reads some or all of the data, then
closes the port and returns the data that was read. 
When used on a file, or URL, the contents of the file,
or URL are returned as a string.

The /LINES refinement returns read content as a series 
of lines. One line is created for each line terminator
found in the read data.

The /PART refinement reads the specified number of 
elements from the file, URL, or port. Reading a file
or URL will read the specified number of characters.
Used with /LINES, it reads a specified number of 
lines.

See the User's Guide for more detailed explanation of
using READ and its refinements.


```rebol
write %rebol-test-file.r "text file"
print read %rebol-test-file.r
read

write %rebol-test-file.r [
{A learned blockhead is a greater man
than an ignorant blockhead.
    -- Rooseveldt Franklin}
]
probe first read/lines %rebol-test-file.r
write

probe pick (read/lines %rebol-test-file.r) 3

probe read/part %rebol-test-file.r 9

probe read/with %rebol-test-file.r "blockhead"
write/append %matrix.avi to-binary "abcdefg"
```

------------------------------------------------------------------
## READ-THRU
------------------------------------------------------------------
## REBCODE?

No description provided.

------------------------------------------------------------------
## RECYCLE

This function will force a garbage collection of unused words
and values found in memory. This function is not required or
recommened for most scripts because the system does it
automatically as necessary.

To disable garbage collection, you can specify /off refinement.


```rebol
recycle/off
```

To enable it again, use /on:


```rebol
recycle/on
```

Note that recently used values may not be immediately garbage
collected, even though they are no longer being referenced by
your program.

------------------------------------------------------------------
## REDUCE
[[ compose do foreach ]]

The `reduce` function evaluates multiple expressions and returns a block of results. This is one of the most useful functions in REBOL.

For example:


```rebol
values: reduce [1 + 2 3 + 4]
probe values
[3 7]
```

Compare this with `do`, which only returns the result of the last expression:


```rebol
values: do [1 + 2 3 + 4]
probe values
7
```


###### Part of other functions
The `reduce` function is important because it enables you to create blocks of expressions that are evaluated and passed to other functions. Some functions, like `print`, use `reduce` as part of their operation, as shown in the following example:


```rebol
print [1 + 2  3 + 4]
3 7
```

The `rejoin`, `repend`, `reform`, `remold` functions also use `reduce` as part of their operation, as shown in the following examples:


```rebol
rejoin ["example" 1 + 2]
example3

str: copy "example"
repend str [1 + 2] ; modifies (uses append)
example3

reform ["example 1 + 2]
example 3

remold ["example" 1 + 2]
["example" 3]
```


###### Ignored reduction
For convenience, expressions that are fully evaluated simply pass-through the `reduce` function.


```rebol
reduce 123
123

reduce "example"
example
```

This makes it possible to use `reduce` in cases where other datatypes may be passed. For example, here is a common function for building HTML strings that relies on this behavior:


```rebol
html: make string! 1000
emit: func [data] [repend html data]

emit "test... "
emit ["number is: " 10]
print html
test... number is: 10
```


###### Blocks with set-words
When you `reduce` blocks that contain set-words, those words will be set. For example:


```rebol
a: 1
reduce [a: 2]
print a
2
```

There are times when you do not want this to occur. For example, if you're building a header for a file, you may want to leave the set-words alone.

The /no-set refinement can be used to handle this case.


```rebol
full-name: "Bob Smith"
reduce/no-set [name: full-name time: now + 10]
[name: "Bob Smith" time: 15-Aug-2010/16:10:50-7:00]
```


###### Memory usage for large blocks
For most blocks you don't need to worry about memory because REBOL's automatic storage manager will efficiently handle it; however, when building large block series with `reduce`, you can manage memory even more carefully.

For example, it is common to write:


```rebol
repend series [a b c]
```

which is shorthand for:


```rebol
append series reduce [a b c]
```

The evaluated results of a, b, and c are appended to the series.

If this is done a lot, a large number of temporary series are generated, which take memory and also must be garbage collected later.

The /into refinement helps optimize the situation:


```rebol
reduce/into [a b c] tail series
```

It requires no intermediate storage.


###### Common Problems
Although `reduce` will create a new outer block, all other series (blocks, strings, etc.) are referenced, not copied. If you modify those values, they will change in all blocks that reference them.

For example:


```rebol
str: "name"
probe result: reduce [str]
["name"]

insert str "new-"
probe result
["new-name"]
```

You can see that it's the same string. To change that behavior use the `copy` function:


```rebol
result: reduce [copy str]
```

or, for blocks that contain multiple strings or other values:


```rebol
result: copy/deep reduce [str]
```

------------------------------------------------------------------
## REF?
------------------------------------------------------------------
## REFINEMENT?

Returns FALSE for all other values.


```rebol
print refinement? /any
true

print refinement? 'any
false
```

------------------------------------------------------------------
## REFLECT
[[ body-of spec-of title-of types-of values-of words-of ]]

```rebol
>> reflect object [a: 1 b: 2] 'words
== [a b]

>> reflect object [a: 1 b: 2] 'values
== [1 2]
```
Or used on function:
```rebol
>> reflect :print 'words
== [value]

>> reflect :print 'title
== "Outputs a value followed by a line break."
```

------------------------------------------------------------------
## REFORM
[[ form mold remold join rejoin ]]

Identical to FORM but reduces its argument first.
Spaces are inserted between each value.


```rebol
probe reform ["the time is:" now/time]
"the time is: 17:47:54"

probe form ["the time is:" now/time]
"the time is: now/time"
```

------------------------------------------------------------------
## REGISTER-CODEC
------------------------------------------------------------------
## REJOIN
[[ join ajoin form reform ]]

Similar to `join` but accepts only one argument, the
block (which will be reduced first). No spaces are
inserted between values.


```rebol
rejoin ["time=" now/time]
time=17:47:54
```

Notice this important case:


```rebol
rejoin [<a> "test"]
<atest>
```

This is fine for lines like:


```rebol
rejoin [<a href=> "test.html"]
<a href=test.html>
```

But you can see it creates a problem in this case:


```rebol
rejoin [<a href=test.html> "test" </a>]
<a href=test.htmltest</a>>
```

If you want the result to be a `string!`, use the `ajoin` function instead.


```rebol
ajoin [<a href=test.html> "test" </a>]
"<a href=test.html>test</a>"
```

------------------------------------------------------------------
## RELEASE
------------------------------------------------------------------
## REMAINDER
[[ // / ]]

If the second number is zero, an error will occur.


```rebol
print remainder 123 10
3

print remainder 10 10
0

print remainder 10.2 10
0.1999999999999993
```

If the first value is positive, then the returned remainder is nonnegative.

If the first value is negative, then the returned remainder is nonpositive.

------------------------------------------------------------------
## REMOLD
[[ mold reduce reform form ]]

Identical to MOLD, but reduces its argument first.
Spaces are inserted between each values in a block.


```rebol
print remold ["the time is:" now/time]
["the time is:" 17:47:54]
```

------------------------------------------------------------------
## REMOVE
[[ append change clear insert sort ]]

Removes a single value from the current position in any type of [series](https://www.rebol.com/r3/docs/concepts/series.html).


```rebol
str: copy "send it here"
remove str
print str
end it here
```

Combine it with other functions to remove a value at a specific index:


```rebol
remove find str "it"
print str
end t here
```

You can remove any number of values with the /PART refinement:


```rebol
str: copy "send it here"
remove/part str 3
print str
d it here
```

The PART refinement also accepts an index of the series being removed form. It must be the same series.


```rebol
remove/part str find str "here"
print str
here
```

An example using a block!:


```rebol
blk: copy [red green blue]
remove next blk
probe blk
[red blue]
```

------------------------------------------------------------------
## REMOVE-EACH
[[ foreach remove map-each ]]

The `remove-each` function is a high performance method of removing specific elements from a series. It is similar to `foreach` but will remove one or more values depending on the result of the evaluated block.

In this example, `remove-each` is used to remove all strings from the block:


```rebol
values: [12 "abc" test 5 "de" 10:30]
remove-each value values [string? value]
probe values
[12 test 5 10:30]
```

Here, all integer values greater than 11 are removed:


```rebol
values: [12 "abc" test 5 "de" 10:30]
remove-each value values [all [integer? value value > 11]]
probe values
["abc" test 5 "de" 10:30]
```


###### Multiple Elements
The `remove-each` function can be used on multiple elements, just as `foreach` does.


```rebol
movies: [
     8:30 "Contact"      $4.95
    10:15 "Ghostbusters" $3.25
    12:45 "Matrix"       $4.25
]

foreach [time title price] movies [
    print [title "at" time "for" price]
    if price > $4.00 [print "removed" true]
]
Contact at 8:30 for $4.95
removed
Ghostbusters at 10:15 for $3.25
Matrix at 12:45 for $4.25
removed
```

This example also shows that the evaluated block may contain any other expressions as long as the last one returns true for removed values.

Also, notice here the way `if` is used for its return value.

------------------------------------------------------------------
## RENAME
[[ delete list-dir what-dir ]]

Renames a file within the same directory:


```rebol
write %testfile now
rename %testfile %remove.me
probe read %remove.me
delete %remove.me
write
```

This function cannot be used to move a file from 
one directory to another.

------------------------------------------------------------------
## REPEAT
[[ loop foreach forall forskip for while until ]]

The `repeat` function is an easy way to repeat the evaluation of a block with a loop counter.


```rebol
repeat num 3 [print num]
1
2
3
```

Here the num counter begins at one and continues up to and including the integer value given.


###### Other Notes

```html
<ul>
<li>Negative or zero loop counts do not evaluate the block.</li>
<li>If a <span class="datatype">decimal!</span> count is used, it will be truncated to a lower integer value.</li>
<li>The <a href="#break">break</a> function can be used to stop the loop at any time.</li>
<li>The <a href="#loop">loop</a> function is similar to <a href="#repeat">repeat</a>, except that it has no loop counter. If you don't need the counter, <a href="#loop">loop</a> is more efficient.</li>
<li>The evaluated block is deep copied and rebound (see <a href="#bind">bind</a> ) to a new context that holds the loop variable. For large nested repeat loops, you will want to consider this overhead. An alternative is to use <a href="#while">while</a>, <a href="#until">until</a>, or <a href="#loop">loop</a> which do not require the copy and bind.</li>
</ul>
```


###### In question...
If the value is a series, then the loop will repeat for each element of the series.

However, there's currently a difference between R2 and R3. In R2, if the value is a series, then the word holds the first value of each element of the series. In R3 it holds just the indexed series.


Editor note: Determine if this is intentional
------------------------------------------------------------------
## REPEND
[[ append insert reduce join ]]

REPEND stands for REDUCE APPEND. It performs the same operation
as APPEND (inserting elements at the tail of a series) but
Reduces the block of inserted elements first. Just like APPEND,
REPEND returns the head of the series.

For example, writing:


```rebol
numbers: [1 2 3]
probe repend numbers [2 + 2 2 + 3 3 + 3]
[1 2 3 4 5 6]
```

is the same as writing:


```rebol
numbers: [1 2 3]
probe append numbers reduce [2 + 2 2 + 3 3 + 3]
[1 2 3 4 5 6]
```

REPEND is very useful when you want to add to a series elements
that need to be evaluated first. The example below creates a
list of all the .r files in the current directory, along with
their sizes and modification dates.


```rebol
data: copy []
foreach file load %. [
    if %.r = suffix? file [
        repend data [file size? file modified? file]
    ]
]
probe data
[%build-docs.r 7915 13-Feb-2009/0:03:17.078 %bulk-modify.r 4210 7-Feb-2009/17:20:06.906 %cgi.r 5125 12-Feb-2009/20:54:51.578 %convert-orig.r 1112 7-Feb-2009/17:20:06.906 %emit-html.r 10587 13-Feb-2009/0:09:38.875 %eval-examples.r 2545 13-Feb-2009/1:46:59.765 %fix-args.r 416 13-Feb-2009/0:41:11.296 %funcs.r 1133 12-Feb-2009/18:54:32.875 %merge-funcs.r 1318 13-Feb-2009/0:42:03.718 %replace.r 197 7-Feb-2009/16:56:23 %scan-doc.r 3429 13-Feb-2009/0:05:33.062 %scan-titles.r 4402 12-Feb-2009/16:51:42.687 %strip-title.r 274 7-Feb-2009/17:20:06.953]
```

When used with strings, repend is a useful way to join values.
The example below is a common method of generating HTML web
page code:


```rebol
html: copy "<html><body>"
repend html [
    "Date is: " now/date <P>
    "Time is: " now/time <P>
    "Zone is: " now/zone <P>
    </body></html>
]
print html
<html><body>Date is: 12-Feb-2009<P>Time is: 17:47:54<P>Zone is: -8:00<P></body></html>
```

------------------------------------------------------------------
## REPLACE
[[ insert remove change ]]

Searches target block or series for specified data and 
replaces it with data from the replacement block or 
series. Block elements may be of any datatype.

The /ALL refinement replaces all occurrences of the 
searched data in the target block or series.


```rebol
str: "a time a spec a target"
replace str "a " "on "
print str
on ime a spec a target

replace/all str "a " "on "
print str
on ime on pec on arget

fruit: ["apples" "lemons" "bananas"]
replace fruit "lemons" "oranges"
print fruit
apples oranges bananas

numbers: [1 2 3 4 5 6 7 8 9]
replace numbers [4 5 6] ["four" "five" "six"]
print numbers
1 2 3 four five six 7 8 9
```

------------------------------------------------------------------
## REQUEST-DIR
------------------------------------------------------------------
## REQUEST-FILE
[[ to-local-file to-rebol-file ]]

Opens the standard operating system file requester to allow the user to select one or more files.


###### Details

####### Normal usage for read or load
The line:


```rebol
file: request-file
```

will open the file requester and return a single file name as a full file path. This is normally used to read or load files.

If the user clicks CANCEL or closes the file requestor, a NONE is returned.


####### For saving or writing files
To open the file requester to save a file:


```rebol
file: request-file/save
```

This will change the text of the window to indicate that a save (write) will be done.


####### Specifying a default file or directory
A default name can be provided for the file:


```rebol
file: request-file/file %test.txt
```

This also works with the /save option, and a full path can be provided, in which case the requester will show the directory where the file will be found.

In addition, just a directory can be used:


```rebol
file: request-file/file %/c/data/files/
```

Be sure to include the terminating slash to indicate a directory. Otherwise it will be treated as a file.


####### Allowing multiple file selection
To allow the selection of multiple files at the same time:


```rebol
files: request-file/multi

foreach file files [print file]
```

The result is returned as a block, and each file within the block is a full path.


####### Filtering file views
You can also provide file list filters to show only specific files. For example:


```rebol
file: request-file/filter [
    "REBOL Scripts" "*.r"
    "Text files" "*.txt"
]
```


####### Setting the window title
The /title refinement lets you modify the window title for the file requester to help make it more clear to users.


```rebol
file: request-file/save/title "Save your data file"
either file [save file data] [print "data not saved"]
```


```html
<fieldset class="fset"><legend>Changes from R2</legend>
<p>This function contains minor changes and cleanup relative to R2. Note that the default operation (with no refinements) returns a single file, not a block. This is the most common form of operation, so it is made standard here. In addition, the /multi option returns a block of full file paths, not a directory path followed by relative files.</p>
</fieldset>
```

------------------------------------------------------------------
## REQUEST-PASSWORD
------------------------------------------------------------------
## RESIZE
------------------------------------------------------------------
## RESOLVE

The `resolve` function is used to merge values from one context into another but avoids replacing existing values.

It is used mainly to support runtime environments, where newly exported functions must be merged into an existing lib context. Because lib can become quite large, performance must be optimized, which is the reason why `resolve` is a native function.


####### Basic Concept
This example will help to show the basic concept:


```rebol
obj1: object [a: 10]
obj2: object [b: 20]
append obj1 'b
resolve obj1 obj2
print obj1
a: 10
b: 20
```

But notice:


```rebol
obj1: object [a: 10]
obj2: object [a: 30 b: 20]
append obj1 'b
resolve obj1 obj2
print obj1
a: 10
b: 20
```

So, `resolve` has no affect on values that have already been set in the target context.

Note that protected words will not be modified, they are ignored. No error occurs.


####### Refinements

```html
<table border="0" cellpadding="5" cellspacing="1" bgcolor="#d0d0e0" class="doctable">
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>/only</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">only affect word values that are provided in a block argument that follows this refinement. In addition, this refinement also supports a special optimization where you can indicate the index of the starting point for changes. That is useful with large contexts such as lib and others.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>/all</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">forces <a href="#resolve">resolve</a> to change all values, not just those that are unset. This is similar to <a href="#append">append</a> on an <span class="datatype">object!</span> except that the source is an object, not a block.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>/extend</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">any words not found in the target context will be added. This eliminates the <a href="#append">append</a> step that was shown above (or a similar <a href="#bind">bind</a> step). This refinement optimizes such operations.
</td></tr>
</table>
```

------------------------------------------------------------------
## RETURN
[[ break exit catch ]]

Exits the current function immediately, returning
a value as the result of the function. To return no
value, use the EXIT function.


```rebol
fun: make function! [this-time] [
    return either this-time >= 12:00 ["after noon"][
        "before noon"]
]
print fun 9:00

print fun 18:00
```

------------------------------------------------------------------
## REVERSE
[[ insert replace sort find ]]

Reverses the order of elements in a series or tuple.


```rebol
blk: [1 2 3 4 5 6]
reverse blk
print blk
6 5 4 3 2 1
```

The /PART refinement reverses the specified number 
of elements from the current index forward. If the 
number of elements specified exceeds the number of 
elements left in the series or tuple, the elements from 
the current index to the end will be reversed.


```rebol
text: "It is possible to reverse one word in a sentence."
reverse/part (find text "reverse") (length? "reverse")
print text
It is possible to esrever one word in a sentence.
```

Note that reverse returns the starting position it was
given. (This change was made to newer versions.)


```rebol
blk: [1 2 3 4 5 6]
print reverse/part blk 4
4 3 2 1 5 6
```

Reverse also works for pairs and tuples:


```rebol
print reverse 10x20
print reverse 1.2.3
3.2.1
```

For tuple values the current index cannot be moved so the 
current index is always the beginning of the tuple.


```rebol
print reverse 1.2.3.4
4.3.2.1

print reverse/part 1.2.3.4 2
4.3.2.1
```

------------------------------------------------------------------
## REWORD
[[ compose replace ]]

This is a general substitution function useful for building web pages, form letters, and other documents.


###### Work In Process
The block substitution abilities are still pending but string substitution works well now.

------------------------------------------------------------------
## RGB-TO-HSV
------------------------------------------------------------------
## RM
[[ cd change-dir delete list-dir ls make-dir mkdir pwd what-dir ]]

Note: Shell shortcut for `delete`.

------------------------------------------------------------------
## ROUND
[[ mod modulo // remainder ]]

"Rounding is meant to loose precision in a controlled way." -- Volker Nitsch

The `round` function is quite flexible. With the various refinements
and the scale option, you can easily round in various ways. Most of the
refinements are mutually exclusive--that is, you should use only one of
them--the /to refinement is an obvious exception; it can be combined 
with any other refinement.

By default, `round` returns the nearest integer, with halves rounded up (away 
from zero).


```rebol
probe round 1.4999
1

probe round 1.5
2

probe round -1.5
-2
```

If the result of the rounding operation is a number! with no decimal component, 
and the SCALE value is not time! or money!, an integer will be returned. This 
makes it easy to use the result of ROUND directly with iterator functions such
as LOOP and REPEAT.

The /TO refinment controls the "precision" of the rounding. That is, the result
will be a multiple of the SCALE parameter. In order to round to a given number
of decimal places, you don't pass in the number of decimal places, but rather 
the "level of precision" they represent. For example, to round to two decimal
places, often used for money values, you would do this:


```rebol
probe round/to $1.333 .01
$0.5558830792256812207833088
```

To round to the nearest 1/8, often used for interest rates, you would do this:


```rebol
probe round/to 1.333 .125
1.375
```

To round to the nearst 1K increment (e.g. 1024 bytes):


```rebol
probe round/to 123'456 1024
123904
```

If the /TO refinement is used, and SCALE is a time! or money! value, the result 
will be coerced to that type. If SCALE is not used, or is not a time! or money! 
value, the datatype of the result will be the same as the valued being rounded.

The /EVEN refinement is designed to reduce bias when rounding large groups of
values. It is sometimes called Banker's rounding, or statistical rounding. For 
cases where the final digit of a number is 5 (e.g. 1.5 or 15), the previous 
digit will be rounded to an even result (2, 4, etc.).


```rebol
repeat i 10 [val: i + .5 print [val round/even val]]
10.5 10

repeat i 10 [val: i * 10 + 5 print [val round/even/to val 10]]
105 100
```

The /DOWN refinement rounds toward zero, ignoring discarded digits. It is often
called "truncate".


```rebol
probe round/down 1.999
1

probe round/down -1.999
-1

probe round/down/to 1999 1000
1000

probe round/down/to 1999 500
1500
```

The /HALF-DOWN refinement causes halves to round toward zero; by default they are
rounded up.


```rebol
probe round/half-down 1.5
1

probe round/half-down -1.5
-1

probe round/half-down 1.50000000001
2

probe round/half-down -1.50000000001
-2
```

The /HALF-CEILING refinement causes halves to round in a positive direction; by 
default they are rounded up (away from zero). This works like the default 
behavior for positive values, but is not the same for negative values.


```rebol
probe round -1.5
-2

probe round/half-ceiling -1.5
-1
```

/FLOOR causes numbers with any decimal component to be rounded in a negative 
direction. It works like /DOWN for positive numbers, but not for negative numbers.


```rebol
round/floor 1.999

round/floor -1.01

round/floor -1.00000000001
```

/CEILING is the reverse of /FLOOR; numbers with any decimal component are rounded
in a positive direction.


```rebol
round/ceiling 1.01

round/ceiling 1.0000000001

round/ceiling -1.999
```

If you are rounding extremely large numbers (e.g. 562'949'953'421'314), or using
very high precision decimal values (e.g. 13 or more decimal places), you may run
up against REBOL's native limits for values and its internal rounding rules. The
ROUND function is a mezzanine and has no control over that behavior.

Sometimes, it might appear that ROUND is doing something strange, so before 
submitting a bug to RAMBO, think about what you're actually asking it to do. For 
example, look at the results from this piece of code:


```rebol
repeat i 10 [
    scale: .9 + (i * .01) 
    print [scale  round/down/to 10.55 scale]
]
1.0 10.0
```

The results approach 10.55 for values from 0.91 to 0.95, but then jump back when 
using values in the range 0.96 to 0.99. Those are the expected results, because 
you're truncating, that is, truncating to the nearest multiple of SCALE.

The design and development of the ROUND function involved many members 
of the REBOL community. There was much debate about the interface (one
function with refinement versus individual functions for each rounding
type, what words to use for parameter names, behavior with regards to
type coercion).

------------------------------------------------------------------
## RSA
------------------------------------------------------------------
## RSA-INIT
------------------------------------------------------------------
## SAME?
[[ =? equal? ]]

Returns TRUE if the values are identical objects, not
just in value. For example, a TRUE would be returned if
two strings are the same string (occupy the same
location in memory). Returns FALSE for all other
values.


```rebol
a: "apple"
b: a
print same? a b
true

print same? a "apple"
false
```

------------------------------------------------------------------
## SAVE
[[ load mold write ]]

The `save` function is used to save REBOL code and data to a file, upload it to a URL, or store it into a local string.

When saving to a file or URL, the output of this function is always UTF-8 (an Unicode encoded format where ASCII is normal, but other characters are encoded.)

The format of the resulting output depends on what you need. The `save` function is designed to allow simple values to be easily saved to be loaded with `load` later:


```rebol
save %date.r now
load %date.r
26-Feb-2009/13:06:15-8:00
```

But, it also allows complex more complex data to be saved:


```rebol
save %data.r reduce ["Data" 1234 %filename now/time]
load %data.r
["Data" 1234 %filename 13:07:15]

save %options.r system/options
load %options.r
make object! [
    home: %/C/rebol/
    script: none
    path: %/C/rebol/
    boot: %/C/rebol/view.exe
    args: none
...
```

In general, `save` performs the appropriate conversion and formatting to preserve datatypes. For instance, if the value is a REBOL block, it will be saved as a REBOL script that, when loaded, will be identical.


Editor note: saving /all

Editor note: saving with headers
Note: Users must take care in how saved data is loaded. More on this below.

------------------------------------------------------------------
## SCALAR?

Description is needed.

------------------------------------------------------------------
## SCRIPT?

If the header is found, the script string will be returned
as of that point. If not found, then NONE is returned.


```rebol
print either script? %file.txt ["found"]["not found"]
```

------------------------------------------------------------------
## SECOND
[[ pick first third fourth fifth ]]

An error will occur if no value is found. Use the PICK
function to avoid this error.


```rebol
print second "REBOL"
E

print second [11 22 33 44 55 66]
22

print second 12-jun-1999
6

print second 199.4.80.1
4

print second 12:34:56.78
34
```

------------------------------------------------------------------
## SECURE
[[ protect load import ]]

The `secure` function controls file, network, evaluation, and all other external access and related policies.

The function uses a simple dialect to specify security sandboxes and other options that allow or deny access. You can set different security levels and multiple sandboxes for networking and specific files and directories.


###### What can be controlled
The `secure` function gives you control over policies for:


```html
<table border="0" cellpadding="5" cellspacing="1" bgcolor="#d0d0e0" class="doctable">
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>file</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">file read, write, and directory creation and listing
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>net</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">read and write access to the network interfaces
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>eval</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">limit the number of evaluation cycles allowed (always quits)
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>memory</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">limit the amount of memory used (always quits)
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>secure</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">control changes to security policies with <a href="#secure">secure</a>
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>protect</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">protecting and hiding values with <a href="#protect">protect</a>
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>debug</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">use of debug-related functions: <a href="#trace">trace</a> and <a href="#stack">stack</a>
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>envr</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">getting OS/shell environment variables with <a href="#get-env">get-env</a>
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>call</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">launching external programs with <a href="#call">call</a>
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>browse</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">opening the web browser with <a href="#browse">browse</a>
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>extension</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">importing <a href="/r3/docs/concepts/extensions.html" class="con">extensions</a> (may contain native code)
</td></tr>
</table>
```

A list of these for your current release can always be obtained with the line:


```rebol
secure query
```

(Which will also show their current policy settings.)


###### Usage

```html
<fieldset class="fset"><legend>R3 ASK not available</legend>
<p>In current releases of R3, the ASK option is not available. Use either THROW or QUIT instead.</p>
</fieldset>
```


####### The main argument
The argument to the `secure` function can be a word or a block.


```html
<table border="0" cellpadding="5" cellspacing="1" bgcolor="#d0d0e0" class="doctable">
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>word</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">a general, top-level action such as setting global security levels to allow or deny all access. It can also be used to query the current security policies.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>block</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">specify separate security policies for files, directories, networking, extensions, debugging, and other features.
</td></tr>
</table>
```


####### Argument as a word
If the argument is a word, it can be:


```html
<table border="0" cellpadding="5" cellspacing="1" bgcolor="#d0d0e0" class="doctable">
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>help</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">summarize what policies can be set
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>query</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">show current policies
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>allow</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">remove all policies (no security)
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>none</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">the same as allow (no security)
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>ask</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">require user permission on all policies
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>throw</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">throw an error for all violations
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>quit</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">exit the program for all violations
</td></tr>
</table>
```

For example, developers often type:


```rebol
secure none
```

to disable all security when developing new programs. <b>However, use this with care. Do not run (or <a href="#do">do</a>) any programs other than those that you trust.</b>

Another example is:


```rebol
secure quit
```

the program will quit immediately if any security violation occurs. Of course, this is a little extreme, and you won't get far. You'll want to specify a block for greater control. See the next section.


####### Argument as a block
To provide more detailed security, use a block:


```rebol
secure [
    net quit
    file ask
    %./ allow
]
```

This block will:


```html
<ul>
<li>disable networking (force a quit if attempted)</li>
<li>ask for user approval for all file access, except:</li>
<li>allow access to the local directory</li>
</ul>
```

As you can see, the security dialect consists of a block of paired values. The first value in the pair specifies what is being secured (file or net), and the second value specifies the level of security (allow, ask, throw, quit). The second value can also be a block to further specify read and write security.


###### Security policies
The security policies are:


```html
<table border="0" cellpadding="5" cellspacing="1" bgcolor="#d0d0e0" class="doctable">
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>allow</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">removes all READ and/or WRITE restrictions.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>ask</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">restricts immediate READ and/or WRITE access and prompts the user for each access attempt, requiring approval before the operation may be completed.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>throw</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">denies READ and/or WRITE access, throwing an error when a restricted access attempt is made.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>quit</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">denies READ and/or WRITE access and quits the script when restricted access is attempted.
</td></tr>
</table>
```

For example, to allow all network access, but to quit on any file access:


```rebol
secure [
    net allow ;allows any net access
    file quit ;any file access will cause the program to quit
]
```

If a block is used instead of a security level word, it can contain pairs of security levels and access types. This lets you specify a greater level of detail about the security you require.


###### Access types
The access types allowed are:


```html
<table border="0" cellpadding="5" cellspacing="1" bgcolor="#d0d0e0" class="doctable">
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>read</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">controls read access.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>write</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">controls write, delete, and rename access.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>execute</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">controls execute access.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>all</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">controls all access.
</td></tr>
</table>
```

The pairs are processed in the order they appear, with later pairs modifying the effect of earlier pairs. This permits setting one type of access without explicitly setting all others. For example:


```rebol
secure [
    net allow
    file [
        ask all
        allow read
        quit execute
    ]
]
```

The above sets the security level to ask for all operations except for reading (which is allowed).

This technique can also be used for individual files and directories. For example:


```rebol
secure [
    net allow
    file quit
    %source/ [ask read]
    %object/ [allow all]
]
```

will prompt the user if an attempt is made to read the %source directory, but it will allow all operations on the %object directory. Otherwise, it uses the default (quit).

If no security access level is specified for either network or file access, it defaults to ASK. The current settings will not be modified if an error occurs parsing the security block argument.


###### Querying security
The `secure` function returns the prior security settings before the new settings were made. This is a block with the global network and file settings followed by file or directory settings. The word query can also be used to obtain the current security settings without modifying them:


```rebol
probe secure query
[file allow net allow ...]
```

Using query, you can modify the current security level by querying the current settings, modifying them, then using the secure function to set the new values.


###### Securing security
Once you have your security policies set, it's a good idea to secure the `secure` function to prevent modifications. This is done in the same way as other policies.

For example:


```rebol
secure [secure quit]
```

will cause your program to immediately quit if any other code tries to modify the security policies.


###### User confirmation
Note that lowering the security level produces a change security settings requestor to the user. The exception is when the REBOL session is running in quiet mode which will, instead, terminate the REBOL session. No request is generated when security levels are raised. Note that the security request includes an option to allow all access for the remainder of the scripts processing.


###### Controlling security at startup
To disable all security on startup, you can start REBOL with:


```rebol
rebol -s args...
```

This policy allows open access for everything.

You can also use the --secure argument to specify any other default security level on startup.


###### Limiting evaluation (quota)
You can set `secure` to limit interpreter evaluation. This feature allows you to restrict server scripts (such as CGI) to a specific evaluation length to prevent runaway programs.

This example sets the limit to 50000 cycles, after which the program will immediately quit (the default behavior):


```rebol
>> secure [eval 50000]
>> loop 100000 [next "test"]
<quit>
```

Also, for debugging you can use the more detailed form of <w>secure:</p>

```rebol
>> secure [eval [throw 50000]]
>> loop 100000 [next "test"]
** Access error: security violation: eval
** Where: loop
** Near: loop 100000 [next "test"]
```

You can continue your debugging at the console, but secure will trap again on the next evaluation sample. To disable that behavior:


```rebol
>> secure [eval allow]
```

When tuning your program, to determine how many cycles your code needs, you can use:


```rebol
>> stats/evals
== 50403
```

However, add to that number a good margin of error for special conditions within your code. In many cases you will want to make it ten or twenty times larger, just to be sure.

A few notes:


```html
<ul>
<li>The maximum evaluation limit is 9e18.</li>
<li>The evaluation limit can be set only once and cannot be reset. However, for debugging after an eval THROW exception, you can use <w>secure to disable the trap (use: [eval allow]).</li>
<li>The limit is approximate. It is sampled at regular intervals (to avoid slowing down evaluation.) The sampling period is 10000 cycles, so that is the resolution of the limit. For example, if you set the limit to 1, it won't trap an error until 10000.</li>
<li>If the program quits, the exit code is set to 101, the same as any security termination; however, we may want to use special codes to indicate the reason for the quit.</li>
<li>Some types of loops are not yet checked, but we will add them. For example, PARSE cycles are not yet counted.</li>
<li>Time limits are not yet supported, but may be added in the future. However, the cycle limit is better for most cases, because it is CPU speed independent.</li>
</ul>
```


###### Limiting memory
You can set `secure` to limit the amount of memory allocated by your program. This feature allows you to restrict server scripts (such as CGI) to a specific memory usage to prevent runaway programs.


```rebol
>> secure [memory 2'000'000]
>> strings: []
>> loop 100000 [append strings make string! 100'000]
<quit>
```

This feature works the same way as the evaluation limit described above. Read that section for more details.

To determine how much memory your program has currently used:


```rebol
>> stats
== 913616
```

The number is shown in bytes.

In addition, it should be noted that the memory limit applies to actual memory consumed. Due to automatic memory allocation (garbage collection) it is possible for a program to run a indefinite amount of time on a specific amount of memory.

The memory limit can be set only once and cannot be reset. However, for debugging after an eval THROW exception, you can use <w>secure to disable the trap:</p>

```rebol
secure [memory allow]
```

------------------------------------------------------------------
## SELECT
[[ find switch ]]

Similar to the `find` function, but returns the next value
in the series rather than the position of the match.
Returns NONE if search failed.

The /only refinement is evaluated for a block argument 
and is ignored if the argument is a string.


```rebol
blk: [red 123 green 456 blue 789]
print select blk 'red
123

weather: [
    "Ukiah"      [clear 78 wind west at 5 MPH]
    "Santa Rosa" [overcast 65 wind north at 10 MPH]
    "Eureka"     [rain 62 wind north at 15 MPH]
]
probe select weather "Eureka"
[rain 62 wind north at 15 MPH]
```

------------------------------------------------------------------
## SELFLESS?
------------------------------------------------------------------
## SERIES?
[[ type? string? email? file? url? issue? tuple? block? paren? ]]

Returns FALSE for all other values.


```rebol
print series? "string"
true

print series? [1 2 3]
true

print series? 1234
false
```

------------------------------------------------------------------
## SET
[[ get in value? unset protect unprotect ]]

If the first argument is a block of words and the value
is not a block, all of the words in the block will be
set to the specified value. If the value is a block,
then each of the words in the first block will be set to
the respective values in the second block. If there are
not enough values in the second block, the remaining
words will be set to NONE

The /ANY refinement allows words to be set any datatype
including those such as UNSET! that are not normally
allowed. This is useful in situations where all values
must be handled.


```rebol
set 'test 1234
print test
1234

set [a b] 123
print a
123

print b
123

set [d e] [1 2]
print d
1

print e
2
```

You can also use `set-word!` within the `set` function:


```rebol
set [a: b:] [1 2]
```

This is useful if you use the `funct` function, which auto-detects local variables that use the set-word notation.

------------------------------------------------------------------
## SET-ENV
------------------------------------------------------------------
## SET-PATH?
[[ make ]]

Returns FALSE for all other values.


```rebol
if set-path? first [a/b/c: 10] [print "Path found"]
Path found
```

------------------------------------------------------------------
## SET-SCHEME
------------------------------------------------------------------
## SET-USER
------------------------------------------------------------------
## SET-WORD?

Returns FALSE for all other values.


```rebol
if set-word? first [word: 10] [print "it will be set"]
it will be set
```

------------------------------------------------------------------
## SEVENTH
[[ first second third pick ]]

See the FIRST function for examples.

An error will occur if no value is found. Use the PICK function to avoid this error.

------------------------------------------------------------------
## SHIFT

Supports right or left bits shifts on integers.

------------------------------------------------------------------
## SHIFT-LEFT
------------------------------------------------------------------
## SHIFT-RIGHT
------------------------------------------------------------------
## SHOW

This is a low-level View function that is used to display or
update a face. The face being displayed must be part of a
pane that is part of a window display.

The SHOW function is called frequently to update the display of
a face after changes have been made.  If the face contains a
pane of sub-faces, all of those faces will be redisplayed.

If you attempt to show a face and nothing happens, make sure
that the face is part of the display hierarchy.  That is, the
face must be present in the pane list of another face that is
being displayed.

For example, if you modify any of the attributes of a face,
you call the SHOW function to display the change.  The code
below shows this:


```rebol
view layout [
    bx: box 100x24 black
    button "Red" [bx/color: red  show bx]
    button "Green" [bx/color: green  show bx]
]
```

The example below creates a layout face and then removes faces
from its pane.  The SHOW function is called each time to refresh
the face and display what has happened.


```rebol
out: layout [
    h1 "Show Example"
    t1: text "Text 1"
    t2: text "Text 2"
]
view/new out
wait 1
remove find out/pane t2
show out
wait 1
remove find out/pane t1
show out
wait 1
append out/pane t2
show out
wait 1
unview
```

------------------------------------------------------------------
## SHOW-SOFT-KEYBOARD
------------------------------------------------------------------
## SIGN?
[[ abs negate ]]

The SIGN? function returns a positive, zero, or negative integer
based on the sign of its argument.


```rebol
print sign? 1000
1

print sign? 0
0

print sign? -1000
-1
```

The sign is returned as an integer to allow it to be used
as a multiplication term within an expression:


```rebol
val: -5
new: 2000 * sign? val
print new
-2000

size: 20
num: -30
if size > 10 [xy: 10x20 * sign? num]
print xy
-10x-20
```

------------------------------------------------------------------
## SIN
------------------------------------------------------------------
## SINE
[[ arccosine arcsine arctangent cosine tangent ]]

Ratio between the length of the opposite side to the
length of the hypotenuse of a right triangle.


```rebol
print sine 90
1.0

print (sine 45) = (cosine 45)
true

print sine/radians pi
0.0
```

------------------------------------------------------------------
## SINGLE?
------------------------------------------------------------------
## SIXTH
[[ first second third pick ]]

See the FIRST function for examples.

An error will occur if no value is found. Use the PICK function to avoid this error.

------------------------------------------------------------------
## SIZE?
[[ modified? exists? ]]

If the file or URL is a directory, it returns the number
of entries in the directory.


```rebol
print size? %file.txt
none
```

------------------------------------------------------------------
## SKIP
[[ at index? next back ]]

For example, SKIP series 1 is the same as NEXT. If skip
attempts to move beyond the head or tail it will be
stopped at the head or tail.


```rebol
str: "REBOL"
print skip str 3
OL

blk: [11 22 33 44 55]
print skip blk 3
44 55
```

------------------------------------------------------------------
## SORT
[[ append change clear insert remove ]]

Sorting will modify any type of [series](https://www.rebol.com/r3/docs/concepts/series.html) passed as the argument:


```rebol
blk: [799 34 12 934 -24 0]
sort blk
print blk
-24 0 12 34 799 934

print sort "dbeca"
"abcde"
```

Normally sorting is not sensitive to character cases:


```rebol
sort ["Fred" "fred" "FRED"]
["fred" "FRED" "Fred"]
```

But you can make it sensitive with the /CASE refinement:


```rebol
sort/case ["Fred" "fred" "FRED"]
["FRED" "Fred" "fred"]
```


Editor note: Sort bug here causes camel-case strings to be sorted incorrectly.
When using the /SKIP refinement, you can treat the series as a set of records of a fixed size. Here we sort by a "name" column, while "age" is skipped:


```rebol
name-ages: [
    "Larry" 45
    "Curly" 50
    "Mo" 42
]
print sort/skip name-ages 2
Curly 50 Larry 45 Mo 42
```

A /COMPARE function can be specified to perform the comparison. This allows you to change the ordering of the SORT:


```rebol
names: [
    "Larry"
    "Curly"
    "Mo"
]
print sort/compare names func [a b] [a < b]
Curly Larry Mo
```

The /ALL refinement will force the entire record to be passed as a series to the compare function. This is useful if you need to compare one or more fields of a record while also doing a skip operation.


Editor note: Need a good working example. This may not be possible until remaining SORT bugs are fixed.
When sorting `pair!` data (points and area sizes), the y coordinate is dominant. This is preferred to support the y sorting used by various graphics algorithms.


```rebol
probe sort [1x2 2x1 0x0 1x0 0x1 1x1]
[0x0 1x0 0x1 1x1 2x1 1x2]
```

------------------------------------------------------------------
## SOURCE
[[ what help ? ?? trace ]]

The `source` function displays the source code for REBOL defined functions.

For example, type:


```rebol
source join
```

The source to the `join` function will be returned:


```rebol
join: make function! [[
    "Concatenates values."
    value "Base value"
    rest "Value or block of values"
][
    value: either series? :value [copy value] [form :value]
    repend value :rest
]]
```

REBOL defined functions include the mezzanine functions (built-in interpreted functions) and user defined functions. Native functions have no source to display.

------------------------------------------------------------------
## SPEC-OF
[[ body-of reflect title-of types-of values-of words-of ]]

Description is needed.

------------------------------------------------------------------
## SPEED?
------------------------------------------------------------------
## SPLIT
[[ extract parse ]]

The `split` function is used to divide a [series](https://www.rebol.com/r3/docs/concepts/series.html) into subcomponents.
It provides several ways to specify how you want the split done.


####### Split into equal segments:
Given an integer as the dlm parameter, `split` will break the series
up into pieces of that size.


```rebol
probe split "1234567812345678" 4
["1234" "5678" "1234" "5678"]
["1234" "5678" "1234" "5678"]
```

If the series can't be evenly split, the last value will be shorter.


```rebol
probe split "1234567812345678" 3
["123" "456" "781" "234" "567" "8"]
["123" "456" "781" "234" "567" "8"]

probe split "1234567812345678" 5
["12345" "67812" "34567" "8"]
["12345" "67812" "34567" "8"]
```


####### Split into N segments:
Given an integer as dlm, and using the /into refinement, it breaks
the series into n pieces, rather than pieces of length n.


```rebol
probe split/into [1 2 3 4 5 6] 2
[[1 2 3] [4 5 6]]
[[1 2 3] [4 5 6]]

probe split/into "1234567812345678" 2
["12345678" "12345678"]
["12345678" "12345678"]
```

If the series can't be evenly split, the last value will be longer.


```rebol
probe split/into "1234567812345678" 3
["12345" "67812" "345678"]
["12345" "67812" "345678"]

probe split/into "1234567812345678" 5
["123" "456" "781" "234" "5678"]
["123" "456" "781" "234" "5678"]
```


####### Split into uneven segments:
If dlm is a block containing only integer values, those values 
determine the size of each piece returned. That is, each piece
can be a different size.


```rebol
probe split [1 2 3 4 5 6] [2 1 3]
[[1 2] [3] [4 5 6]]
[[1 2] [3] [4 5 6]]

probe split "1234567812345678" [4 4 2 2 1 1 1 1]
["1234" "5678" "12" "34" "5" "6" "7" "8"]
["1234" "5678" "12" "34" "5" "6" "7" "8"]

probe split first [(1 2 3 4 5 6 7 8 9)] 3
[[1 2 3] [4 5 6] [7 8 9]]
[(1 2 3) (4 5 6) (7 8 9)]

probe split #{0102030405060708090A} [4 3 1 2]
[#{01020304} #{050607} #{08} #{090A}]
[#{01020304} #{050607} #{08} #{090A}]
```

If the total of the dlm sizes is less than the length of the series,
the extra data will be ignored.


```rebol
probe split [1 2 3 4 5 6] [2 1]
[[1 2] [3]]
[[1 2] [3]]
```

If you have extra dlm sizes after the series data is exhausted, you
will get empty values.


```rebol
probe split [1 2 3 4 5 6] [2 1 3 5]
[[1 2] [3] [4 5 6] []]
[[1 2] [3] [4 5 6] []]
```

If the last dlm size would return more data than the series contains,
it returns all the remaining series data, and no more.


```rebol
probe split [1 2 3 4 5 6] [2 1 6]
[[1 2] [3] [4 5 6]]
[[1 2] [3] [4 5 6]]
```

Negative values can be used to skip in the series without returning
that part:


```rebol
probe split [1 2 3 4 5 6] [2 -2 2]
[[1 2] [5 6]]
[[1 2] [5 6]]
```


####### Simple delimiter splitting:
Char or any-string values can be used for simple splitting, much as
you would with `[bad-link:functions/parseall.txt]`, but with different behavior for strings
that have embedded quotes.


```rebol
probe split "abc,de,fghi,jk" #","
["abc" "de" "fghi" "j"]
["abc" "de" "fghi" "jk"]

probe split "abc<br>de<br>fghi<br>jk" <br>
["abc" "de" "fghi" "j"]
["abc" "de" "fghi" "jk"]
```

If you want to split at more than one character value, you can use
a `[bad-link:functions/charsetbitset.txt]`.


```rebol
probe split "abc|de/fghi:jk" charset "|/:"
["abc" "de" "fghi" "j"]
["abc" "de" "fghi" "jk"]
```

Note that for greater control, you can use simple `parse` rules:


```rebol
probe split "abc     de fghi  jk" [some #" "]
["abc" "de" "fghi" "j"]
["abc" "de" "fghi" "jk"]
```

------------------------------------------------------------------
## SPLIT-LINES
------------------------------------------------------------------
## SPLIT-PATH
[[ clean-path suffix? ]]

Returns a block consisting of two elements, the path and the file.
Can be used on URLs and files alike.


```rebol
probe split-path %tests/math/add.r
[%tests/math/ %add.r]

set [path file] split-path http://www.rebol.com/graphics/logo.gif
print path
http://www.rebol.com/graphics/

print file
logo.gif
```

------------------------------------------------------------------
## SQRT
------------------------------------------------------------------
## SQUARE-ROOT
[[ exp log-10 log-2 log-e power ]]

Returns the square-root of the number provided. If the
number is negative, an error will occur (which you can
trap with the TRY function).


```rebol
print square-root 4
2.0

print square-root 2
1.414213562373095
```

------------------------------------------------------------------
## STACK

No description provided.

------------------------------------------------------------------
## STATS
[[ help trace ]]

The STATS function returns a wide range of useful REBOL system
statistics, including information about memory usage, interpreter
cycles, and more.

If no refinement is provide, STATS returns the amount of memory
that it is using. This value must be computed from tables.

The /pools refinement returns information about the memory pools
that REBOL uses for managing its memory.

The /types refinement provides a summary of the number of each
datatype currently allocated by the system.


```rebol
foreach [type num] stats/types [
    print [type num]
]
```

The /series shows the number of series values, both string and
block oriented, as free space, etc.

The /frames provides the number of context frames used for objects
and functions.

The /recycle option summarizes garbage collection information.

The /evals provides counters for the number of interpreter cycles,
functions invoked, and blocks evaluated.

The /clear refinement can be used with the /evals refinement to clear
its counters.


```rebol
stats/evals/clear
loop 100 [print "hello"]
print stats/evals
```

------------------------------------------------------------------
## STRICT-EQUAL?
[[ == = <> strict-not-equal? ]]

Strict equality requires the values to not differ by
datatype (so 1 would not be equal to 1.0) nor by
character casing (so "abc" would not be equal to "ABC").


```rebol
print strict-equal? 123 123
true

print strict-equal? "abc" "ABC"
false
```

------------------------------------------------------------------
## STRICT-NOT-EQUAL?
[[ !== <> = == ]]

Returns FALSE if the values neither differ by datatype
(so 1 would not be equal to 1.0) nor by character casing
(so "abc" would not be equal to "ABC").


```rebol
print strict-not-equal? 124 123
true

print strict-not-equal? 12-sep-98 10:30
true
```

------------------------------------------------------------------
## STRING?
[[ type? ]]

Returns FALSE for all other values.


```rebol
print string? "with all things considered"
true

print string? 123
false
```

------------------------------------------------------------------
## STRUCT?

Returns TRUE if the value is a STRUCT datatype.

------------------------------------------------------------------
## SU
------------------------------------------------------------------
## SUBTRACT
[[ - + add absolute ]]

Note: The `+` operator is a special infix form for this function.

Many different datatypes support subtraction. Here are just a few:


```rebol
print subtract 123 1
122

print subtract 1.2.3.4 1.0.3.0
0.2.0.4

print subtract 12:00 11:00
1:00

print subtract 1-Jan-2000 1
31-Dec-1999
```

When subtracting values of different datatypes, the values must be compatible. Auto conversion of the values will occur into the datatype that has the most expansive representation. For example an integer subtracted from a decimal will produce a decimal.

------------------------------------------------------------------
## SUFFIX?
[[ find split-path ]]

The SUFFIX? function can be used to obtain the file extention
(e.g. .exe, .txt, .jpg, etc.) that is part of a filename.


```rebol
print suffix? %document.txt
.txt

print suffix? %program.exe
.exe

print suffix? %dir/path/doc.txt
.txt

print suffix? %file.type.r
.r

print suffix? http://www.rebol.com/doc.txt
.txt
```

If there is no suffix, a NONE is returned:


```rebol
print suffix? %filename
none
```

The suffix function can be used with any string datatype, but always
returns a FILE! datatype if the suffix was found.


```rebol
print type? suffix? %file.txt
file!

print type? suffix? "file.txt"
file!

print type? suffix? http://www.rebol.com/file.txt
file!
```

This was done to allow code such as:


```rebol
url: http://www.rebol.com/docs.html
if find [%.txt %.html %.htm %.doc] suffix? url [
    print [url "is a document file."]
]
http://www.rebol.com/docs.html is a document file.
```

------------------------------------------------------------------
## SUM
------------------------------------------------------------------
## SUPPLEMENT
------------------------------------------------------------------
## SWAP

Description is needed.

------------------------------------------------------------------
## SWAP-ENDIAN
------------------------------------------------------------------
## SWITCH
[[ case select find ]]

The `switch` function selects the block for a given choice and evaluates it.

For example:


```rebol
switch 22 [
    11 [print "here"]
    22 [print "there"]
]
there
```

This function is equivalent to writing a `select` like this:


```rebol
do select [
    11 [print "here"]
    22 [print "there"]
] 22
```


###### Variety of Datatypes
The selection choices can be of any datatype. Here are some examples:


```rebol
file: %user.r
switch file [
    %user.r [print "here"]
    %rebol.r [print "everywhere"]
    %file.r [print "there"]
]
here

url: ftp://ftp.rebol.org
switch url [  
    http://www.rebol.com [print "here"]
    http://www.cnet.com [print "there"]
    ftp://ftp.rebol.org [print "everywhere"]
]
everywhere

tag: <title>
print switch html [
    <pre>   ["preformatted text"]
    <title> ["page title"]
    <li>    ["bulleted list item"]
]
page title
```


###### Cases Not Evaluated
It's very important to note that the choices are not evaluated (think of them as constants.) This allows the choices to be words, as shown below. If you need evaluation of the case values, use the `case` function instead.


```rebol
person: 'mom
switch person [
    dad [print "here"]
    mom [print "there"]
    kid [print "everywhere"]
]
there
```

This most often becomes important when you want to `switch` based on a datatype value. You must be sure to use `type?` with a /word refinement:


```rebol
val: 123
switch type?/word [
    integer! [print "it's integer"]
    decimal! [print "it's decimal"]
    date! [print "it's a date"]
]
it's integer
```

Here the `type?` function returns the word (name) of the `datatype!`, not the datatype's type value.

Another possible approach is to evaluate the block of cases. For the example above:


```rebol
switch type? reduce [
    integer! [print "it's integer"]
    decimal! [print "it's decimal"]
    date! [print "it's a date"]
]
it's integer
```

This works because words like integer! are set to their actual datatype values.


###### Default Case
You can use the /default refinement to specify a default case.


```rebol
time: 14:00
switch/default time [
     8:00 [send wendy@domain.dom "Hey, get up"]
    12:30 [send cindy@dom.dom "Join me for lunch."]
    16:00 [send group@every.dom "Dinner anyone?"]
][
    print ["Nothing done at" time]
]
Nothing done at 14:00
```


###### Return Value
The `switch` function returns the value of the case block that it evaluated, or none otherwise.


```rebol
car: pick [Ford Chevy Dodge] random 3
print switch car [
    Ford [351 * 1.4]
    Chevy [454 * 5.3]
    Dodge [154 * 3.5]
]
491.4
```


###### Common Problems
The most common problem is to assume that `switch` evaluates your case values. It does not. This kind of code does not work:


```rebol
item1: 100
item2: 200
n: 100
switch n [
    item1 [...]
    item2 [...]
]
```

However, you can `reduce` the case block to its actual values:


```rebol
switch n reduce [
    item1 [...]
    item2 [...]
]
```

------------------------------------------------------------------
## TAG?

Returns FALSE for all other values.


```rebol
print tag? <title>
true

print tag? "title"
false
```

------------------------------------------------------------------
## TAIL
[[ tail? head head? ]]

Access to the tail allows insertion at the end of a
series (because insertion always occurs before the
specified element).


```rebol
blk: copy [11 22 33]
insert tail blk [44 55 66]
print blk
11 22 33 44 55 66
```

------------------------------------------------------------------
## TAIL?
[[ empty? tail head head? ]]

This function is the best way to detect the end of a
series while moving through it.


```rebol
print tail? "string"
false

print tail? tail "string"
true

str: "Ok"
print tail? tail str
true

print tail? next next str
true

items: [oven sink stove blender]
while [not tail? items] [
    print first items
    items: next items
]
blender

blk: [1 2]
print tail? tail blk
true

print tail? next next blk
true
```

------------------------------------------------------------------
## TAKE

The `take` function removes a value from a series and returns it as the result. It's a useful combination of `pick` with `remove`.

For example, used on blocks:


```rebol
data: [a b c d]
take data
a

probe data
[b c d]
```

Used on strings:


```rebol
str: "abcd"
take str
#"a"

probe str
"bcd"
```


###### For Queues and Stacks
The `take` function is quite useful for making queues and stacks.

An example queue is implemented as first in first out (FIFO) block. New values are added with `append` and removed with `take`.


```rebol
data: make block! 10
append data 1
append data 2
append data 3
take data
1

take data
2
```

An example stack is implemented as last in first out (LIFO). The difference is to use the /last refinement with `take`.


```rebol
data: make block! 10
append data 1
append data 2
append data 3
take/last data
3

take/last data
2
```

The data queued and stacked above can be any REBOL values, including string, functions, objects or whatever.

------------------------------------------------------------------
## TAN
------------------------------------------------------------------
## TANGENT
[[ arccosine arcsine arctangent cosine tangent ]]

Ratio between the length of the opposite side to
the length of the adjacent side of a right triangle.


```rebol
print tangent 30
0.5773502691896257

print tangent/radians 2 * pi
0.0
```

------------------------------------------------------------------
## TASK

Description is needed.

------------------------------------------------------------------
## TASK?

No description provided.

------------------------------------------------------------------
## TENTH
[[ first second third pick ]]

See the FIRST function for examples.

An error will occur if no value is found. Use the PICK function to avoid this error.

------------------------------------------------------------------
## THIRD
[[ first second fourth fifth pick ]]

An error will occur if no value is found. Use the PICK
function to avoid this error.


```rebol
print third "REBOL"
B

print third [11 22 33 44 55 66]
33

print third 12-jun-1999
12

print third 199.4.80.1
80

print third 12:34:56.78
56.78
```

------------------------------------------------------------------
## THROW
[[ catch return exit ]]

CATCH and THROW go together. They provide a method of
exiting from a block without evaluating the rest of the
block. To use it, provide CATCH with a block to
evaluate. If within that block a THROW is evaluated,
the script will return from the CATCH at that point. The
result of the CATCH will be the value that was passed as
the argument to the THROW. When using multiple CATCH
functions, provide them with a name to identify which
one will CATCH which THROW.


```rebol
print catch [
    if exists? %file.txt [throw "Doc file!"]
]
none
```

------------------------------------------------------------------
## TIME?
[[ type? ]]

Returns FALSE for all other values.


```rebol
print time? 12:00
true

print time? 123
false
```

------------------------------------------------------------------
## TINT
------------------------------------------------------------------
## TITLE-OF
[[ body-of reflect spec-of types-of values-of words-of ]]

```rebol
>> title-of :print
== "Outputs a value followed by a line break."
```

------------------------------------------------------------------
## TO
[[ make ]]

Every datatype provides a TO method to allow conversions from
other datatypes. The to-binary, to-block, and all other to-
functions are mezzanine functions that are based on this TO
function.

Here are a few examples:


```rebol
probe to file! "test.r"
%test.r

probe to path! [a b c]
a/b/c
```

The TO function lets the target datatype be specified as an
argument, allowing you to write code such as:


```rebol
flag: true
value: to either flag [integer!][decimal!] "123"
print value
123
```

The conversions that are allowed depend on the specific
datatype. Some datatypes allow special conversions, such as:


```rebol
print to integer! false
0

print to integer! true
1

print to logic! 1
true

print to time! 600  ; # of seconds
0:10
```

------------------------------------------------------------------
## TO-BINARY
[[ to ]]

Returns a binary! value made from the given value.


```rebol
probe to-binary "123456"
#{313233343536}
```

Notice, that the binary returned is not how the "actual storage" in computer memory looks. Instead, the bits are in "network order", which is, by convention, big endian:


```rebol
to-binary 1
#{0000000000000001}
```

------------------------------------------------------------------
## TO-BITSET
[[ to ]]

Returns a bitset! value made from the given value.


```rebol
probe to-bitset [#"a" - #"z" #"A" - #"Z"]
make bitset! #{00000000000000007FFFFFE07FFFFFE0}
```

------------------------------------------------------------------
## TO-BLOCK
[[ to to-paren to-path]]

Returns a block! value made from the given value.


NOTE: The behavior of this function differs from Rebol2 and Red!
Conversions using `to` from non-blocks only wrap the value in a block of the specified type. Use `make` if you expect tokenization!

```rebol
>> to-block "123 10:00"
== ["123 10:00"] ;; no tokenization!

>> make block! "123 10:00"
== [123 10:00]
```

For conversions from another block-like type, one can use the `as` function, which coerces the original value to another type without creating a new one.
```rebol
>> path: 'hello/world
== hello/world

>> blk: as block! path
== [hello world] ;; this value has coerced type

>> insert next blk 'cruel
== [world]

>> path
== hello/cruel/world ;; original value was modified too

>> append to-block path 42
== [hello cruel world 42] ;; this is new series value!

>> path
== hello/cruel/world ;; original value was not modified
```

------------------------------------------------------------------
## TO-CHAR
[[ to ]]

Returns a char! value made from the given value.

```rebol
>> to-char "a"
== #"a"

>> to-char 65
== #"A"
```

------------------------------------------------------------------
## TO-CLOSURE

No description provided.

------------------------------------------------------------------
## TO-COMMAND
------------------------------------------------------------------
## TO-DATATYPE
[[ make to ]]

Can be used to convert a `word!` containing a valid datatype name into a `datatype!`.
```rebol
>> to-datatype 'integer!
== #(integer!)

>> type? to-datatype 'integer!
== #(datatype!)

>> to-datatype "foo"

** Script error: cannot MAKE #(datatype!) from: "foo"
```

------------------------------------------------------------------
## TO-DATE
[[ to ]]

Returns a date! value made from the given value.

```rebol
>> to-date "12-April-1999"
== 12-Apr-1999
```
Also accepts a string in the Internet Message Date format (RFC2822).
```rebol
>> to-date "Mon, 1 Apr 2019 21:50:04 GMT"
== 1-Apr-2019/21:50:04

>> to-date "Thu, 28 Mar 2019 20:00:59 +0100"
== 28-Mar-2019/20:00:59+1:00
```

When the input is of type `integer!` or `decimal!`, it is treated as a Unix timestamp.
```rebol
>> to-date 123456789
== 29-Nov-1973/21:33:09

>> encode 'unixtime 29-Nov-1973/21:33:09
== 123456789

>> to-date 1741600660.239
== 10-Mar-2025/9:57:40.239
```

------------------------------------------------------------------
## TO-DECIMAL
[[ to ]]

Returns a decimal! value made from the given value.


```rebol
>> to-decimal 1
== 1.0

>> to-decimal 10-Mar-2025/9:57:40.239
== 1741600660.239 ;; Unix timestamp with a precision
```

------------------------------------------------------------------
## TO-DEGREES
[[ to-radians ]]

```rebol
>> to-degrees pi
== 180.0
```

------------------------------------------------------------------
## TO-EMAIL
[[ to ]]

Returns an email! value made from the given value.


```rebol
print to-email [luke rebol.com]
lukerebol.com
```

------------------------------------------------------------------
## TO-ERROR
[[ make to ]]

Returns an error! value made from the given value.


```rebol
probe disarm try [to-error "Oops! My error."]
make object! [

code: 308
type: 'Script
id: 'cannot-use
arg1: 'to
arg2: unset!
arg3: none
near: [to error! :value]
where: [to to-error try do attempt if emit parse foreach catch if either if do begin do]
```

]

Note that this differs from TO and MAKE in that you
have to wrap the call in a TRY block to catch the
error it makes.

------------------------------------------------------------------
## TO-EVENT

No description provided.

------------------------------------------------------------------
## TO-FILE
[[ to to-rebol-file to-local-file ]]

Returns a file! value made from the given value.


```rebol
>> to-file "test.txt"
== %test.txt
```

------------------------------------------------------------------
## TO-FUNCTION

```rebol
>> fun: to-function [[a][a * 10]]
>> fun 1
== 10
```

------------------------------------------------------------------
## TO-GET-PATH

Returns a `get-path!` value made from the given value.

```rebol
>> to-get-path [path to word]
== :path/to/word
```

------------------------------------------------------------------
## TO-GET-WORD
[[ to ]]

Returns a `get-word!` value made from the given value.


```rebol
probe to-get-word "test"
:test
```

------------------------------------------------------------------
## TO-GOB

No description provided.

------------------------------------------------------------------
## TO-HASH
------------------------------------------------------------------
## TO-HEX
[[ to-integer ]]

The TO-HEX function provides an easy way to convert an integer to
a hexidecimal value.


```rebol
>> to-hex 123
== #000000000000007B
```

The value returned is a string of the ISSUE datatype (not the BINARY
datatype). This allows you to convert hex values back to integers:


```rebol
>> to-integer #7B
== 123
```

Note: To convert HTML hex color values (like #80FF80) to REBOL
color values, it is easier to do the conversion to binary and
then use a base 16 encoding:


```rebol
to-html-color: func [color [tuple!]] [
    to-issue enbase to-binary color 16
]
print to-html-color 255.155.50
FF9B32
```

The TO-ISSUE function is just used to add the # to it.

To convert from an HTML color back to a REBOL color tuple, you
can use this:


```rebol
to-rebol-color: func [color [issue!]] [
    to-tuple debase color 16
]
to-rebol-color #FF9B32
```

If the HTML color value is a string, convert it to an issue first.
The function below will work for strings and issues:


```rebol
to-rebol-color2: func [color [string! issue!]] [
    if string? color [
        if find/match color "#" [color: next color]
        color: to-issue color
    ]
    to-tuple debase color 16
]
to-rebol-color2 "#FF9B32"
```

------------------------------------------------------------------
## TO-IDATE
------------------------------------------------------------------
## TO-IMAGE
[[ to ]]

This is a special conversion function that is used for
converting a FACE object (such as those created by the layout
function) into an image bitmap in memory.

For example, the code below converts the OUT layout to a bitmap
image, then writes it out as a PNG file:


```rebol
out: layout [
    h2 "Title"
    field
    button "Done"
]
image: to-image out
save/png %test-image.png image
```

This function provides a useful way to save REBOL generated
images for use in other programs or web pages (which also allows
you to print the images). For example, you can display the image
above in a web browser with this code:


```rebol
write %test-page.html trim/auto {
    <html><body>
    <h2>Image:</h2>
    <img src="test-image.png">
    </body></html>
}
browse %test-page.html
write
```

------------------------------------------------------------------
## TO-INTEGER
[[ to to-hex ]]

Returns an integer! value made from the given value.


```rebol
print to-integer "123"
123

print to-integer 123.9
123

print to-integer #"A" ; convert to the character value
65

print to-integer #102030 ; convert hex value (see to-hex for info)
1056816
```

------------------------------------------------------------------
## TO-ISSUE
[[ to to-hex ]]

Returns an issue! value made from the given value.


```rebol
print to-issue "1234-56-7890"
1234-56-7890
```

To convert HTML RGB color values (that look like #000000), see
the to-hex function.

------------------------------------------------------------------
## TO-ITIME

```rebol
>> to-itime now/time
== "09:46:03"
```

------------------------------------------------------------------
## TO-JSON
[[ load-json ]]

```rebol
>> to-json #[a: 1 b: ["hello"]]
== {{"a":1,"b":["hello"]}}
```

`to-json` is basically the same as using `encode`
```rebol
>> encode 'json #[a: 1 b: ["hello"]]
== {{"a":1,"b":["hello"]}}
```
But it provides easy option for producing nicely formatted output.
```rebol
>> to-json/pretty #[a: 1 b: ["hello"]] "  "
== {{
  "a": 1,
  "b": [
    "hello"
  ]
}}
```
------------------------------------------------------------------
## TO-LIT-PATH
[[ to ]]

Returns a lit-path! value made from the given value.


```rebol
>> to-lit-path [a b c]
== 'a/b/c
```

------------------------------------------------------------------
## TO-LIT-WORD
[[ to ]]

Returns a ilt-word! value made from the given value.


```rebol
>> to-lit-word "test"
== 'test
```

------------------------------------------------------------------
## TO-LOCAL-FILE
[[ to-file to-rebol-file ]]

This function provides a way to convert standard, system
independent REBOL file formats into the file format used by
the local operating system.


```rebol
probe to-local-file %/c/temp
"c:\temp"

probe to-local-file what-dir
"C:\REBOL\3.0\docs\scripts\"
```

Note that the format of the file path depends on your local
system. Be careful how you use this function across systems.

------------------------------------------------------------------
## TO-LOGIC
[[ to make ]]

Returns a logic! value made from the given value.


```rebol
print to-logic 1
print to-logic 0
false
```

------------------------------------------------------------------
## TO-MAP
[[ to make ]]

```rebol
>> to-map [a: 1 b: 2]
== #[
    a: 1
    b: 2
]
```

------------------------------------------------------------------
## TO-MODULE
[[ to make ]]



------------------------------------------------------------------
## TO-MONEY
[[ to make ]]

Returns a money! value made from the given value.


```rebol
>> to-money 123.4
== $123.4
```

NOTE: Currency types are not supported yet!

------------------------------------------------------------------
## TO-OBJECT
[[ to make ]]

This function currently works only for conversions from an `error!` value.
```rebol
>> to-object try [1 / 0]
== make object! [
    code: 400
    type: 'Math
    id: 'zero-divide
    arg1: #(none)
    arg2: #(none)
    arg3: #(none)
    near: [/ 0]
    where: [/ try]
]
```

------------------------------------------------------------------
## TO-PAIR
[[ to as-pair pair? ]]

Returns a pair! value made from the given value.


```rebol
>> to-pair [120 50]
== 120x50

>> x: 100 y: 50
>> to-pair reduce [x y]
== 100x50
```

This last line is done so often that the `as-pair` function was created.
```rebol
>> as-pair x y
== 100x50
```


------------------------------------------------------------------
## TO-PAREN
[[ to to-path to-block]]

Returns a paren! value made from the given value.

NOTE: The behavior of this function differs from Rebol2 and Red!
Conversions using `to` from non-blocks only wrap the value in a block of the specified type. Use `make` if you expect tokenization!

```rebol
>> to-paren "123 456"
== ("123 456")

>> make paren! "123 456"
== (123 456)
```

For conversions from another block-like type, one can use the `as` function, which coerces the original value to another type without creating a new one.
```rebol
>> blk: ["hello" "world"]
== ["hello" "world"]

>> par: as paren! blk
== ("hello" "world")

>> uppercase par/2
== "WORLD"

>> blk
== ["hello" "WORLD"]
```

------------------------------------------------------------------
## TO-PATH
[[ to to-paren to-block]]

Returns a path! value made from the given value.


```rebol
colors: make object! [reds: ["maroon" "brick" "sunset"]]
p-reds: to-path [colors reds]
print form :p-reds
colors/reds

print p-reds
colors/reds

insert tail p-reds "bright"
print colors/reds
maroon brick sunset

print p-reds
colors/reds/"bright"
```

------------------------------------------------------------------
## TO-PERCENT

No description provided.

------------------------------------------------------------------
## TO-PORT
[[ make to ]]

Returns a port! value made from the given value.


```rebol
probe to-port [scheme: 'checksum]
```

------------------------------------------------------------------
## TO-RADIANS
[[ to-degrees ]]

```rebol
>> to-radians 180.0
== 3.14159265358979
```

------------------------------------------------------------------
## TO-REAL-FILE
[[ to-local-file to-rebol-file what-dir ]]

```rebol
>> to-real-file %../Rebol
== %/C/Users/oldes/Rebol/

>> to-real-file ".."
== %/C/Users/oldes/
```

------------------------------------------------------------------
## TO-REBOL-FILE
[[ to-local-file to-real-file ]]

This function provides a standard way to convert local operating
system files into REBOL's standard machine independent format.


```rebol
>> to-rebol-file %../Rebol
== %../Rebol

>> to-rebol-file "../Rebol"
== %../Rebol

>> to-rebol-file "C:\Program Files\"
== %/C/Program%20Files/
```

Note that the format of the file path depends on your local
system. Be careful how you use this function across systems.

------------------------------------------------------------------
## TO-REF
[[ to ]]

Returns a `ref!` value made from the given value.

```rebol
>> to-ref "Oldes"
== @Oldes
```

------------------------------------------------------------------
## TO-REFINEMENT
[[ to ]]

Returns a `refinement!` value made from the given value.


```rebol
>> to-refinement 'REBOL
== /REBOL
```

------------------------------------------------------------------
## TO-RELATIVE-FILE
[[ to-real-file what-dir ]]

```
>> what-dir
== %/C/Users/oldes/Rebol/

>> to-relative-file %/C/Users/Oldes/Rebol/temp
== %temp
```

------------------------------------------------------------------
## TO-SET-PATH
[[ to to-path to-get-path to-lit-path ]]

Returns a `set-path!` value made from the given value.


```rebol
>> to-set-path [some path]
== some/path:
```

------------------------------------------------------------------
## TO-SET-WORD
[[ to to-word to-get-word to-lit-word]]

Returns a `set-word!` value made from the given value.


```rebol
>> to-set-word "test"
== test:
```

------------------------------------------------------------------
## TO-STRING
[[ to form mold]]

Returns a `string!` value made from the given value.


```rebol
>> to-string [123 456]
== "123456"
```

------------------------------------------------------------------
## TO-TAG
[[ to ]]

Returns a `tag!` value made from the given value.


```rebol
>> to-tag ";comment:"
== <;comment:>
```

------------------------------------------------------------------
## TO-TIME
[[ to to-itime to-date ]]

Returns a `time!` value made from the given value.


Integer and decimal values are interpreted as a number of seconds.
```rebol
>> to-time 75
== 0:01:15

>> to-time 75.5
== 0:01:15.5
```

A block may contain up to three values. The first two must be 
integers, and correspond to the hour and minute values. The
third value can be an integer or decimal value, and corresponds
to the number of seconds.
```rebol
>> to-time [0 1 15.5]
== 0:01:15.5
```

------------------------------------------------------------------
## TO-TUPLE
[[ to to-hex ]]

Returns a `tuple!` value made from the given value.


```rebol
>> to-tuple [12 34 56]
== 12.34.56
```

To convert REBOL RGB color tuples to HTML hex color values, see
the `to-hex` function.

Tuples can have up to 12 segments.

------------------------------------------------------------------
## TO-TYPESET

Returns a `typeset!` value made from the given value.

```rebol
>> types: to-typeset [string! file! url!]
== make typeset! [string! file! url!]

>> find types #(url!)
== #(true)
```

------------------------------------------------------------------
## TO-URL
[[ to as ]]

Returns a `url!` value made from the given value.


```rebol
>> to-url "http://www.rebol.com"
== http://www.rebol.com
```

------------------------------------------------------------------
## TO-VALUE
[[ to ]]

```rebol
>> to-value ()
== #(none)

>> to-value 1
== 1

>> to-value #(unset)
== #(none)
```

------------------------------------------------------------------
## TO-VECTOR

Currently, `to-vector` can only be used with a valid vector specification.
```rebol
>> to-vector [uint8! 3]
== make vector! [unsigned integer! 8 3 [0 0 0]]

>> to-vector [int16! [1 2 3]]
== make vector! [integer! 16 3 [1 2 3]]
```

Vectors can be created using construction syntax.
```rebol
>> #(uint8! 3)
== make vector! [unsigned integer! 8 3 [0 0 0]]

>> #(int16! [1 2 3])
== make vector! [integer! 16 3 [1 2 3]]
```

Currently there are these vector types:
* Signed integers: `int8!`, `int16!`, `int32!`, `int64!`
* Unsigned integers: `uint8!`, `uint16!`, `uint32!`, `uint64!`
* 32bit decimal: `float!`
* 64bit decimal: `double!`


------------------------------------------------------------------
## TO-WORD
[[ to to-set-word to-get-word to-lit-word ]]

Returns a `word!` value made from the given value.


```rebol
>> to-word "test"
== test
```

------------------------------------------------------------------
## TRACE
[[ echo probe stack ]]

The `trace` lets you watch the evaluation of your script, expression by expression.

The three most common arguments to `trace` are shown here:


```rebol
trace on   ; turn on trace
trace off  ; turn off trace
trace 5    ; turn on, but trace only 5 levels deep
```

Once enabled, when you evaluate an expression, you will see each step as a single line:

```rebol
>> print 123
 1: print : native! [value]
 2: 123
--> print
123
<-- print == unset!
```


###### Understanding the format
The `trace` format uses these formatting notations to indicate what your code is doing:


```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Notation
</th><th valign="top">
Meaning
</th>
<tr>
<td valign="top" bgcolor="white" >
(indent)
</td><td valign="top" bgcolor="white">
The indentation for each line indicates the depth of the code.
</td>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">N:</div>
</td><td valign="top" bgcolor="white">
The index number of the value in the code block (that is to be evaluated.)
</td>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">--&gt;</div>
</td><td valign="top" bgcolor="white">
Entry into a function, followed by its formal argument list.
</td>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">&lt;--</div>
</td><td valign="top" bgcolor="white">
Return from a function, followed by the value it returned (==).
</td></tr></table>
```


####### Simple example
To help understand the format, here's a description for each line in the earlier example:


```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Code
</th><th valign="top">
Meaning
</th>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">&gt;&gt; print 123</div>
</td><td valign="top" bgcolor="white">
Typed into the console to evaluate.
</td>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">1: print : native! [value]</div>
</td><td valign="top" bgcolor="white">
The value at block index 1 is the word <a href="#print">print</a>. It's value is looked up and found to be a <span class="datatype">native!</span> function that takes value as an argument.
</td>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">2: 123</div>
</td><td valign="top" bgcolor="white">
The value at block index 2 is the integer 123.
</td>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">--&gt; print</div>
</td><td valign="top" bgcolor="white">
The argument is valid and the <a href="#print">print</a> function is entered. The --&gt; means "enter into the function."
</td>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">123</div>
</td><td valign="top" bgcolor="white">
Output is printed.
</td>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">&lt;-- print == unset!</div>
</td><td valign="top" bgcolor="white">
The <a href="#print">print</a> function returns, but it has no return value (it is unset.) The &lt;-- means "return from the function."
</td></tr></table>
```


####### Larger example
Here is a user defined function to compute the average of a block of numbers.


```rebol
ave: func [nums [block!] /local val][
    val: 0
    foreach num nums [val: val + num]
    val / length? nums
]
```

Tracing the evaluation, you will see how each new level is indented and begins a new sequence of index numbers. Notice also the `foreach` loop.


```rebol
>> ave [1 2 3]
 1: ave : function! [nums /local val]
 2: [1 2 3]
--> ave
     1: val:
     2: 0
     3: foreach : native! ['word data body]
     5: nums : [1 2 3]
     6: [val: val + num]
    --> foreach
         1: val:
         2: val : 0
         3: + : op! [value1 value2]
         4: num : 1
        --> +
        <-- + == 1
         1: val:
         2: val : 1
         3: + : op! [value1 value2]
         4: num : 2
        --> +
        <-- + == 3
         1: val:
         2: val : 3
         3: + : op! [value1 value2]
         4: num : 3
        --> +
        <-- + == 6
    <-- foreach == 6
     7: val : 6
     8: / : op! [value1 value2]
     9: length? : action! [series]
    10: nums : [1 2 3]
    --> length?
    <-- length? == 3
    --> /
    <-- / == 2
<-- ave == 2
== 2
```


###### Minimizing the output
At times the trace output will be a lot more than you want. The trick becomes how to cut it down without losing the information you need.. There are three methods:

<ol>
<li>Specify a trace depth.</li>
<li>Locate the <a href="#trace">trace</a> on and off lines deeper within your code.</li>
<li>Trace only functions, not all values.</li>
<li>Use the backtrace option. (see more below)</li>
</ol>

####### Setting trace depth
Using the example above, set the trace depth to 2, and run it again. You will see:


```rebol
>> trace 2
>> ave [1 2 3]
 1: ave : function! [nums /local val]
 2: [1 2 3]
--> ave
     1: val:
     2: 0
     3: foreach : native! ['word data body]
     5: nums : [1 2 3]
     6: [val: val + num]
    --> foreach
    <-- foreach == 6
     7: val : 6
     8: / : op! [value1 value2]
     9: length? : action! [series]
    10: nums : [1 2 3]
    --> length?
    <-- length? == 3
    --> /
    <-- / == 2
<-- ave == 2
== 2
```

The output has been reduced. You no longer see the foreach loop operate.


####### Locating trace within your code
Most of the time you don't need to trace your entire program, just part of it. So, it is useful just to put `trace` in your code where you need it.

Using the same example as above:


```rebol
ave: func [nums [block!] /local val][
    val: 0
    trace on
    foreach num nums [val: val + num]
    trace off
    val / length? nums
]
```

You will now see:


```rebol
>> ave [1 2 3]
<-- trace == unset!
 5: foreach : native! ['word data body]
 7: nums : [1 2 3]
 8: [val: val + num]
--> foreach
     1: val:
     2: val : 0
     3: + : op! [value1 value2]
     4: num : 1
    --> +
    <-- + == 1
     1: val:
     2: val : 1
     3: + : op! [value1 value2]
     4: num : 2
    --> +
    <-- + == 3
     1: val:
     2: val : 3
     3: + : op! [value1 value2]
     4: num : 3
    --> +
    <-- + == 6
<-- foreach == 6
 9: trace : native! [mode /back]
10: off : false
--> trace
== 2
```


####### Tracing functions only
With the /function refinement you can trace just function calls and their returns. The evaluation of each code block value is not shown, saving a few lines.


```rebol
>> trace/function on
>> ave [1 2 3]
    --> ave [1 2 3] . .
        --> foreach num [1 2 3] [val: val + num]
            --> + 0 1
        <-- + == 1
            --> + 1 2
        <-- + == 3
            --> + 3 3
        <-- + == 6
    <-- foreach == 6
        --> length? [1 2 3]
    <-- length? == 3
        --> / 6 3
    <-- / == 2
<-- ave == 2
```

In this mode, the function call lines will show the arguments passed to the functions. (A dot is used to show NONE value slots, such as those for unused refinements or local variables.)


###### Backtrace
At times it is important to know what your code was doing immediately before a crash. In such cases, you don't want to see trace output until after the crash. That is the purpose of the /back refinement: to tell `trace` to redirect its output to an internal buffer that you can examine later.

To enable backtrace:


```rebol
>> trace/back on
```

Then, run your code. When your crash occurs, type:


```rebol
>> trace/back 20
```

to see the last 20 lines (or however many lines you want to see.)

You can also modify your trace depth as you would normally. For example:


```rebol
>> trace/back on
>> trace 5
```

will only trace down five levels of code.

When you are done with the backtrace, you can disable it with:


```rebol
>> trace/back off
```

and that will also free memory used by the backtrace buffer.

To use backtrace with the /function refinement:


```rebol
>> trace/back/function on
```

This will also speed-up trace evaluation.


####### Example backtrace
Here is an example session:


```rebol
>> trace/back on
>> test: func [a] [if integer? a [loop a [bug]]]
>> test 10
** Script error: bug has no value
** Where: loop if test
** Near: loop a [bug]

>> trace/back 10
    --> if
         1: loop : native! [count block]
         2: a : 10
         3: [bug]
        --> loop
             1: bug : unset!
            **: error : Script no-value
 1: trace/back
 2: 20
--> trace
```

So, it's not hard to see what was going on when the script crashed. Backtrace can be quite handy when you need it.


####### Important notes

```html
<ul>
<li>Tracing is disabled automatically when you display the backtrace. (This prevents additional accumulation of trace information, allowing you to redisplay the buffer without interference from additional console lines.)</li>
<li>Backtrace will slow down your program by a factor of 20 (because for each value that is evaluated, it must store a log record).</li>
<li>The internal backtrace buffer is 100KB. On average, the most it will hold is 100 pages of backtrace.</li>
<li>Enabling normal trace will disable backtrace and delete the backtrace buffer.</li>
<li>Backtrace may interfere with some kinds of tracing, especially if the bug is related to a defect within the REBOL interpreter itself.</li>
</ul>
```

The `stack` function can also be used to show stack related backtrace information.

------------------------------------------------------------------
## TRANSCODE
[[ to-block ]]

The `transcode` function translates source code and data into the block value memory format that can be interpreted by REBOL.


###### Input
The source input to `transcode` must be Unicode UTF-8. This is a `binary!` encoded format, and should not be confused with a `string!`, which is a decoded in-memory indexable string.

If you need to `transcode` a string, you must convert it to a UTF-8 binary first. This can be done with `to-binary`.


```rebol
data: transcode to-binary string
```


```html
<fieldset class="fset"><legend>Reduced efficiency</legend>
<p>In general, conversions to and from UTF-8 require extra time to for the Unicode conversion process. Therefore, is not a good idea to write REBOL code like TCL or PERL where computations are done on strings.</p>
<p>Don't write code such as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do append "1 +" n</code></pre></div>
<p>Because you can just as easily write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do append [1 +] n</code></pre></div>
<p>in REBOL.</p>
</fieldset>
```


###### Refinements
Without refinements, `transcode` will convert the entire input string.

Refinements are provided for partial translation:


```html
<table border="0" cellpadding="5" cellspacing="1" bgcolor="#d0d0e0" class="doctable">
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>/next</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">Translate the next full value. If it is a block, translate the entire block.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>/only</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">Translate the next singular value. If it is a block, translate only the first element of the block, and return it within a block.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>/error</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">Convert syntax errors to error objects and output them rather than throwing them as an error.
</td></tr>
</table>
```

These refinements can be used in various ways to parse REBOL source a value at a time.


###### Output
The output from `transcode` is a `block!` containing two values:

<ol>
<li>The translated value, block of values, or <span class="datatype">error!</span> object.</li>
<li>The <span class="datatype">binary!</span> source at the point where the translation ended.</li>
</ol>
For example:


```rebol
a: to-binary "a b c"
#{6120622063}

transcode/only a
[a #{20622063}]
```

------------------------------------------------------------------
## TRIM
[[ parse remove clear ]]

Trim removes unwanted values, normally it trims whitespace from a `string!` or `none!` values from a `block!` or `object!`.

Here is an example of a string:


```rebol
str: "  string   "
probe trim str
"string"
```

Note that the str is modified. To avoid that, use copy:


```rebol
new-str: trim copy str
```

For a `block!` :


```rebol
trim reduce [none 'a none 'b none]
[a b]
```

It removes the `none!` values from the block. (And it will also remove `unset!` values as well.)

Note that the block is modified. But, in this example, `reduce` creates a unique copy, so the original is not effected.

And for an `object!` :


```rebol
trim system/options
make object! [
    home: %/C/Program%20Files/
    path: %/C/rebol/r3/
    boot: %/C/rebol/r3/view.exe
    binary-base: 16
    decimal-digits: 15
]
```

Because object fields cannot be removed (due to binding) the result of `trim` of an object is always to return a new shallow object. (The values of the object are not deep-copied or rebound.)

The new object only shows fields that have actual value (not none or unset.)


###### Details on trimming strings
The default for TRIM is to remove whitespace characters (tabs
and spaces) from the heads and tails of every line of a string.
Empty leading and trailing lines are also trimmed.

When a string includes multiple lines, the head and tail
whitespace will be trimmed from each line (but not within the
line):


```rebol
str: {
    Now is the winter
    of our discontent
    made glorious summer
    by this sun of York.
}
probe trim str
{Now is the winter
of our discontent
made glorious summer
by this sun of York.
}
```

The line terminator of the final line is preserved.

As mentioned above, empty leading and trailing lines are also
trimmed:


```rebol
probe trim {

    Non-empty line.
    Non-empty line.
    Non-empty line.

}
{Non-empty line.
Non-empty line.
Non-empty line.
}
```

Note that TRIM modifies the string in the process.


```rebol
str: "  string   "
trim str
probe str
"string"
```

TRIM does not copy the string. If that's what you want, then use
TRIM with COPY to copy the string before trimming it.

Several refinements to TRIM are available. To trim just the head
and/or tail of a string you can use the /HEAD or /TAIL refinements.


```rebol
probe trim/head "  string  "
"string  "

probe trim/tail "  string  "
"  string"

probe trim/head/tail "  string  "
"string"
```

When using /HEAD or /TAIL, multiple lines are not affected:


```rebol
probe trim/head {  line 1
    line 2
    line 3
}
{line 1
line 2
line 3
}
```

To trim just the head and tail of a multiline string, but none
of its internal spacing:


```rebol
str: {  line 1
    line 2
        line 3
            line 4
                line 5  }
probe trim/head/tail str
{line 1
line 2
    line 3
        line 4
            line 5}
```

If you use TRIM/LINES then all lines and extra spaces will be
removed from the text. This is useful for word wrapping and web
page kinds of applications.


```rebol
str: {
    Now   is
    the
    winter
}
probe trim/lines str
"Now is^/the^/winter"
```

You can also remove /ALL space:


```rebol
probe trim/all " Now is   the winter "
"Nowisthewinter"

str: {
    Now   is
    the
    winter
}
probe trim/all str
"Nowisthewinter"
```

One of the most useful TRIM refinements is /AUTO which will do a
"smart" trim of the indentation of text lines. This mode detects
the indentation from the first line and preserves indentation
for the lines to follow:


```rebol
probe trim/auto {
    line 1
        line 2
        line 3
            line 4
    line 5
}
{line 1
 line 2
 line 3
     line 4
 line 5
 }
```

This is useful for sections of text that are embedded within
code and indented to the level of the code.

To trim other characters, the /WITH refinement is provided.
It takes an additional string that specifies what characters
to be removed.


```rebol
str: {This- is- a- line.}
probe trim/with str "-"
"This is a line."

str: {This- is- a- line.}
probe trim/with str "- ."
"Thisisaline"
```


###### TRIM on blocks
When `trim` is used on a `block!`, it strips all `none!` values from the block:


```rebol
trim reduce [1 2 none]
[1 2]
```

Note that `trim` modifies the argument block.


###### TRIM on objects
When `trim` is used on an `object!`, it will return a new object that has all `none!` values removed:


```rebol
obj: make object [arg1: 10 arg2: none]
trim obj
make object! [
    arg1: 10
]
```

------------------------------------------------------------------
## TRUE?
[[ false? ]]

```rebol
>> true? 1
== #(true)

>> true? 2
== #(true)

>> true? none
== #(false)

>> true? off
== #(false)
```
Note that `unset!` value is truthy!
```rebol
>> true? #(unset)
== #(true)
```

------------------------------------------------------------------
## TRUNCATE
[[ take remove ]]

```rebol
>> str: "12345"
== "12345"

>> truncate skip str 3
== "45"
```

This function is useful for removing processed data from an input buffer.


------------------------------------------------------------------
## TRY
[[ attempt error? do ]]

The `try` function evaluates a block and will capture any errors that occur during that evaluation.

The purpose of `try` is to give your own code the opportunity to handle errors, rather than causing your program to terminate with an error message.

For example, in this line:


```rebol
try [delete %afile.txt]
```
if the file does not exist, then the error will not cause your program to terminate.


###### Return Value
The `try` function returns an error value if an error happened, otherwise it returns the normal result of the block.

Taking the above example, we can do something special if an error happened:


```rebol
if error? try [delete %afile.txt] [print "delete failed"]
```

or, even use the error value itself:


```rebol
if error? err: try [delete %afile.txt] [print ["delete failed:" mold err]]
```

Sometimes you'll want to use the value that was returned:


```rebol
either error? val: try [1 + "x"] [print "nope"] [print val]
nope

either error? val: try [1 + 2] [print "nope"] [print val]
3
```


###### Exception Handling
The `try` function is for error handling, but there are times when you may be returning error objects as values, and you cannot distinguish between an error occurring and the error value itself. This is case rare, but it does happen.

For this situation the `/with` refinement is provided. If an error occurs, it will evaluate a exception handling function (or just a block). This indicates that an error exception happened (not just an error value being passed.)

The example below will catch the "zero-divide" error within a function. The error is passed as the argument to the exception function, and a value (zero in this case) is returned from the `try` function:


```rebol
>> try/with [1 / 0] :print

** Math error: attempt to divide by zero
** Where: / try
** Near: / 0
```
Or to provide a default value in case of the error:
```rebol
>> try/with [1 / 0] ['oh-no]
== oh-no
```

Last error is stored in the `system/state` object and may be used like:
```rebol
>> try [1 / 0]

** Math error: attempt to divide by zero
** Where: / try
** Near: / 0

>> system/state/last-error

** Math error: attempt to divide by zero
** Where: / try
** Near: / 0
```


###### Shortcut
The `attempt` function is shortcut for the common pattern where you don't care about the specific error, and mainly just want the non-error result.


```rebol
data: attempt [load %data.r]
```

The data will be either the data or none, if it failed to load.


------------------------------------------------------------------
## TUPLE?
[[ type? ]]

Returns FALSE for all other values.


```rebol
>> tuple? 1.2.3.4
== #(true)

>> tuple? "1.2.3.4"
== #(false)
```

------------------------------------------------------------------
## TYPE?
[[ make none? logic? integer? decimal? money? tuple? time? date? string? email? file? url? issue? word? block? paren? path? native? function? object? port? ]]

To check for a single datatype, use its datatype test
function (e.g. string?, time?) The /WORD refinement
returns the type as a word so you can use if for FIND,
SELECT, SWITCH, and other functions.


```rebol
>> type? 10
== #(integer!)

>> type? :type?
== #(native!)
```
```rebol
value: 10:30
print switch type?/word value [
    integer! [value + 10]
    decimal! [to-integer value]
    time!    [value/hour]
    date!    [first value/time]
]
10
```

------------------------------------------------------------------
## TYPES-OF
[[ body-of reflect spec-of title-of values-of words-of ]]

```rebol
>> spec-of :to-radians
== [
    "Converts degrees to radians"
    degrees [integer! decimal!] "Degrees to convert"
]

>> types-of :to-radians
== [make typeset! [integer! decimal!]]
```

------------------------------------------------------------------
## TYPESET?

```rebol
>> typeset? any-string!
== #(true)

>> typeset? string!
== #(false)
```

------------------------------------------------------------------
## UNBIND
[[ bind context? ]]

```rebol
>> a: 1 b: [a a]
== [a a] ;; words inside the block are bound

>> not none? context? first b
== #(true)

>> reduce b
== [1 1] ;; and so have the value

>> unbind b
== [a a]

>> context? first b
== #(none)

>> reduce b

** Script error: a word is not bound to a context
```

------------------------------------------------------------------
## UNDIRIZE
[[ dirize ]]

```rebol
>> undirize %some/path/
== %some/path
```

------------------------------------------------------------------
## UNFILTER
[[ filter ]]

Compression preprocessing, as used in PNG images.
```rebol
>> bin: #{01020304050102030405} ;; original data
== #{01020304050102030405}

>> filter bin 5 'sub
== #{01010101010101010101} ;; data filtered for good compression

>> unfilter/as #{01010101010101010101} 5 'sub
== #{01020304050102030405} ;; original data again
```

------------------------------------------------------------------
## UNHANDLE-EVENTS

No description provided.

------------------------------------------------------------------
## UNION
[[ difference intersect exclude unique ]]

Returns all elements present within two blocks or strings 
ignoring the duplicates.


```rebol
lunch: [ham cheese bread carrot]
dinner: [ham salad carrot rice]
probe union lunch dinner
[ham cheese bread carrot salad rice]

probe sort union [1 3 2 4] [3 5 4 6]
[1 2 3 4 5 6]

string1: "CBDA"    ; A B C D scrambled
string2: "EDCF"    ; C D E F scrambled
probe sort union string1 string2
"ABCDEF"

items: [1 1 2 3 2 4 5 1 2]
probe union items items  ; get unique set
[1 2 3 4 5]

str: "abcacbaabcca"
probe union str str
"abc"
```

To obtain a unique set (to remove duplicate values)
you can use UNIQUE.

Note that performing this function over very large
data sets can be CPU intensive.

------------------------------------------------------------------
## UNIQUE
[[ intersect union difference exclude ]]

Removes all duplicate values from a set or series:


```rebol
lunch: [ham cheese bread carrot ham ham carrot]
probe unique lunch
[ham cheese bread carrot]

probe unique [1 3 2 4 3 5 4 6]
[1 3 2 4 5 6]

string: "CBADEDCF"
probe unique string
"CBADEF"
```

Note that performing this function over very large
data sets can be CPU intensive.

------------------------------------------------------------------
## UNLESS
[[ if not either ]]

The `unless` function is the equivalent of writing `if` `not` of a condition.


```rebol
unless now/time > 12:00 [print "It's still morning"]
```

See the `if` function for a lot more information.


###### Why?
This function can take some getting used to. It has been provided to make PERL programmers happier, and it's marginally simpler and faster than writing an `if` `not` expression.

------------------------------------------------------------------
## UNPROTECT
[[ protect ]]

Unprotects a series, variable, or object that was protected earlier with `protect`.

For example:


```rebol
test: "text"
protect test
append test "a"
** Script error: protected value or series - cannot modify

unprotect test
append test "a"
probe texta
"texta"
```

To `unprotect` all series found within a block, use the /deep refinement:


```rebol
test: [100 "example" 10:20]
protect/deep test
print append "example" "x"
** Script error: protected value or series - cannot modify

unprotect/deep test
print append "example" "x"
examplex
```

See `protect` for other usage and information.

------------------------------------------------------------------
## UNSET
[[ set ]]

Using UNSET, the word's current value will be lost. If
a block is specified, all the words within the block
will be unset.


```rebol
test: "a value"
unset 'test
print value? 'test
false
```

------------------------------------------------------------------
## UNSET?
[[ value? ]]

Returns TRUE if a value is UNSET. Normally you should
use VALUE? to test if a word has a value.


```rebol
if unset? do [print "test"] [print "Nothing was returned"]
test
```

------------------------------------------------------------------
## UNTIL
[[ while repeat loop foreach for ]]

The `until` function evaluates a block until the block returns true. It is different from `while` because it only requires a single block, which also serves as the condition. However, the block is always evaluated at least once.

The general form is:


```rebol
while [cond] [body]
```

For example:


```rebol
num: 0
until[
    print num
    num: num + 1
    num >= 2
]
0
1
2
```

Another example:


```rebol
str: "test"
until [
    print str
    tail? str: next str
]
test
est
st
t
```


###### Return Value
The last value of the block is returned from the `until` function. Because this is also the termination condition, it will always be non-none non-false, but that can be useful at times.


###### Other Notes

```html
<ul>
<li>A <a href="#break">break</a> can be used to escape from the loop at any time.</li>
<li>A common mistake is to forget that block must return the test condition for the loop, which could result in an infinite loop.</li>
</ul>
```

------------------------------------------------------------------
## UNVIEW

The UNVIEW function is used to close a window previously opened
with the VIEW function. By default, the last window that has
been opened will be closed.  To close a specific window, use the
/only refinement and specify the window's face (that which was
returned from a layout, for example).  All windows can be closed
with the /all refinement.

The example below opens a window that displays a Close button.
Clicking on the button will evaluate the UNVIEW function and the
window will be closed.


```rebol
view layout [button "Close" [unview]]
```

Note that the VIEW function will not return until all windows
have been closed. (Use VIEW/new to return immediately after
the window is opened.)

The next example will open two windows, then use UNVIEW/only
to close each one separately.


```rebol
out1: layout [button "Close 2" [unview out2]]
out2: layout [button "Close 1" [unview out1]]
view/new out1
view/new out2
do-events
```

You could have closed both windows with the line:


```rebol
unview/all
```

------------------------------------------------------------------
## UPDATE
[[ read write insert remove query ]]

Updates the input or output of a port. If input is
expected, the port is checked for more input. If output
is pending then that output is written.


```rebol
out: open/new %trash.me
insert out "this is a test"
update out
insert out "this is just a test"
close out
```

------------------------------------------------------------------
## UPPERCASE
[[ lowercase trim ]]

The series passed to this function is modified as a
result.


```rebol
print uppercase "abcdef"
ABCDEF

print uppercase/part "abcdef" 1
Abcdef
```

------------------------------------------------------------------
## URL?
[[ type? ]]

Returns FALSE for all other values.


```rebol
print url? http://www.REBOL.com
true

print url? "test"
false
```

------------------------------------------------------------------
## USAGE
[[ help ? ]]

Displays REBOL command line arguments, including
options and examples.


```rebol
usage
```

SDK and special versions of REBOL may not include usage
information.

------------------------------------------------------------------
## USE

The first block contains a list of words which will be
local to the second block. The second block will be
evaluated and its results returned from the USE.


```rebol
total: 1234
nums: [123 321 456]
use [total] [
    total: 0
    foreach n nums [total: total + n]
    print total
]
900

print total
1234
```

Note: The USE function modifies the context (bindings) of the code
block (as if BIND was used on it). This can lead to problems for
recursive functions. To use the USE function recusively, you will
need to COPY/deep the code block first:


```rebol
words: [a]
body: [print a * b]
use words copy/deep body
```

------------------------------------------------------------------
## USER'S
[[ set-user ]]

It can be used in the following scenario:
```rebol
>> set-user/n Test
 [REBOL] Initialize user: Test
 [REBOL] Creating a new persistent storage file: /C/Users/oldes/Rebol/.Test.safe
Enter password:

>> user's key
== #(none) ;; Because the key has not been stored yet.

>> put system/user/data 'key "secret"
== "secret"

>> user's key
== "secret"

>> set-user ;; Removes current user
>> user's key
== #(none) ;; Because there is no user now

>> set-user Test
 [REBOL] Initialize user: Test
Enter password:

>> user's key
== "secret"
```

------------------------------------------------------------------
## UTF?
[[ invalid-utf? ]]

```rebol
>> utf? #{FEFF005700720069007400650072}
== 16

>> utf? #{FFFE570072006900740065007200}
== -16

>> utf? #{fffe0000650000007300000063000000}
== -32

>> utf? #{EFBBBFC3A4C3B6C3BC}
== 8
```


------------------------------------------------------------------
## UTYPE?

No description provided.

------------------------------------------------------------------
## VALUE?
[[ default unset? equal? strict-equal? same? ]]

The `value?` function returns true if the specified `word!` has a value. It returns false if not.


```rebol
>> value? 'system
== #(true)

>> value? 'not-defined
== #(false)
```

The word can be passed as a literal or as the result of other operations.


```rebol
>> value? first [system not-defined]
== #(true)

>> value? second [system not-defined]
== #(false)
```

------------------------------------------------------------------
## VALUES-OF
[[ body-of reflect spec-of title-of types-of words-of ]]

```rebol
>> values-of #[a: 1 b: 2]
== [1 2]

>> values-of object [a: 1 b: 2]
== [1 2]
```

------------------------------------------------------------------
## VECTOR?

```rebol
>> vector? #(uint8! 3)
== #(true)

>> vector? [1 2 3]
== #(false)
```

------------------------------------------------------------------
## VERSION
[[ about license ]]

```rebol
>> version
== {Rebol/Bulk 3.18.3 (9-Mar-2025/22:36 UTC)
Copyright (c) 2012 REBOL Technologies
Copyright (c) 2012-2025 Rebol Open Source Contributors
Source:       https://github.com/Oldes/Rebol3
}
```

------------------------------------------------------------------
## VIEW

NOTE: GUI system is only partially supported in this Rebol version!


------------------------------------------------------------------
## WAIT

If the value is a `time!`, delay for that period. If the
value is an `integer!` or `decimal!`, wait that number of
seconds. If the value is a `port!`, wait for an event from
that port. If a `block!` is specified, wait for any of the
times or ports to occur. Return the port that caused
the wait to complete or return none if the timeout
occurred.


```rebol
print now/time
17:48:19

wait 1
print now/time
17:48:22

wait 0:00:01
print now/time
17:48:23
```

------------------------------------------------------------------
## WAIT-FOR-KEY
------------------------------------------------------------------
## WAKE-UP

No description provided.

------------------------------------------------------------------
## WHAT
[[ help ? ]]

The `what` function lists globally exported functions and their titles or arguments.

For example:


```text
>> what
...
about               Information about REBOL
abs                 Returns the absolute value.
absolute            Returns the absolute value.
action              Creates datatype action (for internal usage only).
action?             Returns TRUE if it is this type.
add                 Returns the result of adding two values.
ajoin               Reduces and joins a block of values into a new string.
alias               Creates an alternate spelling for a word.
...
```

To see function arguments use:


```text
>> what/args
...
about                 []
abs                   [value]
absolute              [value]
action?               [value]
add                   [value1 value2]
ajoin                 [block]
...
```

Also see the `help` function which allows searching for functions.


###### Module Export Lists
To see a list of functions for a specific module, provide the module name:


```rebol
>> what/args help
?               ['word /into string]
a-an            [s]
about           []
dot             [value]
dump-obj        [obj /weak /match pattern /not-none]
form-pad        [val size]
form-type       [value]
form-val        [val]
help            ['word /into string]
license         []
list-codecs     []
out-description [des]
output          [value]
pad             [val size]
source          ['word]
usage           []
what            ['name /args]
```

------------------------------------------------------------------
## WHAT-DIR
[[ change-dir make-dir list-dir ]]

```rebol
>> what-dir
== %/C/Users/oldes/Rebol/
```

------------------------------------------------------------------
## WHILE
[[ until loop repeat for ]]

The `while` function repeats the evaluation of its two block arguments while the first block returns true. The first block is the condition block, the second block is the evaluation block. When the condition block returns false or `none!`, the expression block will no longer be evaluated and the loop terminates.

The general form is:


```rebol
while [cond] [body]
```

For example:


```rebol
num: 0
while [num < 3] [
    print num
    num: num + 1
]
0
1
2
```

Another example, using `while` to traverse a series (like `foreach` ):


```rebol
color: [red green blue]
while [not tail? color] [
    print first color
    color: next color
]
red
green
blue
```

Here is an example using a string series:


```rebol
str: "abc"
while [not tail? str: next str] [
    print ["length of" str "is" length? str]
]
length of abc is 3
length of bc is 2
length of c is 1
```


###### Condition Block
The condition block can contain any number of expressions, so long as the last expression returns the condition. To illustrate this, the next example adds a print to the condition block. This will print the index value of the color. It will then check for the tail of the color block, which is the condition used for the loop.


```rebol
color: [red green blue]
while [
    print index? color
    not tail? color
][
    print first color
    color: next color
]
1
red
2
green
3
blue
4
```


###### Return Value
The last value of the block is returned from the `while` function.


###### Other Notes

```html
<ul>
<li>A <a href="#break">break</a> can be used to escape from the loop at any time.</li>
<li>The most common mistake is to forget to provide a block for the
first argument (the condition).</li>
</ul>
```

------------------------------------------------------------------
## WILDCARD
------------------------------------------------------------------
## WILDCARD?
------------------------------------------------------------------
## WITH
------------------------------------------------------------------
## WORD?
[[ type? ]]

Returns FALSE for all other values. To test for "word:",
":word", or "'word", use the SET?, GET?, and LITERAL?
functions.


```rebol
print word? second [1 two "3"]
true
```

------------------------------------------------------------------
## WORDS-OF
[[ body-of reflect spec-of title-of types-of values-of ]]

No description provided.

------------------------------------------------------------------
## WRAP

```rebol
>> a: 1 ;; Having some value....
== 1

>> wrap load "a: 2" ;; Evaluate some code which is
                    ;; using the same value name
== 2

>> a
== 1 ;; Original value was not changed
```

------------------------------------------------------------------
## WRITE
[[ read open close load save form ]]

WRITE is typically used to write a file to disk, but
many other operations, such as writing data to URLs and
ports, are possible.

Normally a string or binary value is provided to this
function, but other types of data such as a number or a
time can be written. They will be converted to text.

The /BINARY refinement will write out data as its exact
representation. This is good for writing image, sound
and other binary data.

The /STRING refinement translates line terminators to
the operating system's line terminator. This behavior
is default.

The /APPEND refinement is useful logging purposes, as
it won't overwrite existing data.

The /LINES refinement can take a block of values and 
will write each value to a line. By default, WRITE will
write the block of values as a concatonated string of
formed values.

The /PART refinement will read the specified number of
elements from the data being written.
The /WITH refinement converts characters, or strings,
specified into line terminators.

See the User's Guide for more detailed explanation of
using READ and its refinements.


```rebol
write %junkme.txt "This is a junk file."
write

write %datetime.txt now
write

write/binary %data compress "this is compressed data"

write %rebol-test-file.r "some text"
print read %rebol-test-file.r
read

write/append %rebol-test-file.r "some more text"
print read %rebol-test-file.r

write %rebol-test-file.r reduce ["the time is:" form now/time]
print read %rebol-test-file.r
read

write/lines %rebol-test-file.r reduce ["time is:" form now/time]
print read %rebol-test-file.r

write/part %rebol-test-file.r "this is the day!" 7
print read %rebol-test-file.r
```

------------------------------------------------------------------
## XOR
[[ and or not ]]

For integers, each bit
is exclusively-or'd. For logic values, this is the
same as the not-equal function.


```rebol
print 122 xor 1
123

print true xor false
true

print false xor false
false

print 1.2.3.4 xor 1.0.0.0
0.2.3.4
```

------------------------------------------------------------------
## XOR~
[[ and~ or~ ]]

The trampoline action function for XOR operator.

------------------------------------------------------------------
## XTEST
------------------------------------------------------------------
## ZERO?
[[ positive? negative? ]]

Check the value of a word is zero.


```rebol
>> zero? 50
== #(false)

>> zero? 0
== #(true)
```

------------------------------------------------------------------
## -
------------------------------------------------------------------
## --
------------------------------------------------------------------
## ---
------------------------------------------------------------------
## &
------------------------------------------------------------------
## /
------------------------------------------------------------------
## //
------------------------------------------------------------------
## =
------------------------------------------------------------------
## ==
------------------------------------------------------------------
## =?
------------------------------------------------------------------
## >
------------------------------------------------------------------
## >=
------------------------------------------------------------------
## >>
------------------------------------------------------------------
## *
------------------------------------------------------------------
## **
------------------------------------------------------------------
## %
------------------------------------------------------------------
## |
------------------------------------------------------------------
## +
------------------------------------------------------------------
## ++
------------------------------------------------------------------
## ?
------------------------------------------------------------------
## ??
------------------------------------------------------------------
## <
------------------------------------------------------------------
## <=
------------------------------------------------------------------
## <>
------------------------------------------------------------------
## <<
------------------------------------------------------------------
## !
------------------------------------------------------------------
## !=
------------------------------------------------------------------
## !==
------------------------------------------------------------------
