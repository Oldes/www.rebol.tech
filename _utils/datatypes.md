
------------------------------------------------------------------
## action!

#### Concept
This is a variant of a `native!` function that is standardized across datatypes. (They implement a set of common polymorphic functions.)

For example, the `insert` function is an `action!` function. It performs the same abstract operation over a variety of datatypes:



#### List of Actions
A complete list of action functions can be found in system/catalog/actions.

They are listed below.


```html
<table cellpadding="3" cellspacing="0" border="0" border=0 width=75%>
<tr><td valign="top" width="300">
<p><b>Magnitude (scalar) oriented:</b></p>
<p>`add`</p>
<p>`subtract`</p>
<p>`multiply`</p>
<p>`divide`</p>
<p>`remainder`</p>
<p>`power`</p>
<p>`and~`</p>
<p>`or~`</p>
<p>`xor~`</p>
<p>`negate`</p>
<p>`complement`</p>
<p>`absolute`</p>
<p>`random`</p>
<p>`round`</p>
<p>`odd?`</p>
<p>`even?`</p>
</td><td width="20">&nbsp;</td><td valign="top" width="300">
<p><b>Series oriented:</b></p>
<p>`head`</p>
<p>`tail`</p>
<p>`head?`</p>
<p>`tail?`</p>
<p>`past?`</p>
<p>`next`</p>
<p>`back`</p>
<p>`skip`</p>
<p>`at`</p>
<p>`index?`</p>
<p>`length?`</p>
<p>`pick`</p>
<p>`find`</p>
<p>`select`</p>
<p>`reflect`</p>
<p>`make`</p>
<p>`to`</p>
<p>`copy`</p>
<p>`take`</p>
<p>`insert`</p>
<p>`append`</p>
<p>`remove`</p>
<p>`change`</p>
<p>`poke`</p>
<p>`clear`</p>
<p>`trim`</p>
<p>`swap`</p>
<p>`reverse`</p>
<p>`sort`</p>
</td><td width="20">&nbsp;</td><td valign="top" width="300">
<p><b>Port oriented:</b></p>
<p>`create`</p>
<p>`delete`</p>
<p>`open`</p>
<p>`close`</p>
<p>`read`</p>
<p>`write`</p>
<p>`open?`</p>
<p>`query`</p>
<p>`[bad-link:functions/modify.txt]`</p>
<p>`update`</p>
<p>`rename`</p>
</td></tr></table>
```



------------------------------------------------------------------
## binary!

#### Concept
The `binary!` datatype is a `series` of bytes (8-bits each, octets).

Binary is the 

#### Format
The source format for binary data can be base-2 (binary), base-16 (hex), and base-64. The default base for binary data in REBOL is base-16.

Binary strings are written as a number sign (#) followed by a string enclosed in braces. The characters within the string are encoded in one of several formats as specified by an optional number prior to the number sign. Base-16 is the default format.



#### Creation
The `to-binary` function converts data to the `binary!` datatype at the default base set in system/options/binary-base:



#### Related
Use `binary?` determine whether a value is an `binary!`  datatype.



------------------------------------------------------------------
## bitset!

#### Concept
Bitsets are bit-based data sets, `logic!` bitmaps. They map collections of integer and character values to true and false.

For example, bitsets define character classes used with the `parse` or `find` functions. They are also commonly used for allocation maps and search hash markers.

More information about bitsets, including details of changes from R2 to R3 can be found on the [DocBase Bitsets](http://www.rebol.net/wiki/Bitsets) page.



#### Creating bitsets
New bitsets are created with `make`, which accepts several datatypes as arguments, including a bitset specification block as described below. Bitsets can also be created from `copy` and `complement`.



#### Bitset specification block
If a block is provided for `make` (and also several of the other bitset-related functions) it represents bit settings in the following way:



#### Supported actions
These datatype [actions](action.html) are defined for the `bitset!` datatype:


```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Action
</th><th valign="top">
Description
</th>
<tr>
<td valign="top" bgcolor="white" >
`make` </td><td valign="top" bgcolor="white"> creates and returns a new bitset
</td>
<tr>
<td valign="top" bgcolor="white" >
`copy` </td><td valign="top" bgcolor="white"> returns a copy of a bitset
</td>
<tr>
<td valign="top" bgcolor="white" >
`complement` </td><td valign="top" bgcolor="white"> inverts each bit; returns a new bitset
</td>
<tr>
<td valign="top" bgcolor="white" >
`find` </td><td valign="top" bgcolor="white"> test that value is set
</td>
<tr>
<td valign="top" bgcolor="white" >
`append` </td><td valign="top" bgcolor="white"> add new bits to the set (set them to <span class="word">true</span>)
</td>
<tr>
<td valign="top" bgcolor="white" >
`poke` </td><td valign="top" bgcolor="white"> set one or more bits <span class="word">true</span> or <span class="word">false</span>
</td>
<tr>
<td valign="top" bgcolor="white" >
`remove` </td><td valign="top" bgcolor="white"> remove specific bits from the bitset (requires <span class="word">/part</span> refinement)
</td>
<tr>
<td valign="top" bgcolor="white" >
`clear` </td><td valign="top" bgcolor="white"> clear entire bitset
</td>
<tr>
<td valign="top" bgcolor="white" >
`length?` </td><td valign="top" bgcolor="white"> returns the number of bits used
</td>
<tr>
<td valign="top" bgcolor="white" >
`and` </td><td valign="top" bgcolor="white"> bitwise `and` of two bitsets; returns new bitset
</td>
<tr>
<td valign="top" bgcolor="white" >
`or` </td><td valign="top" bgcolor="white"> bitwise `or` of two bitsets; returns new bitset
</td>
<tr>
<td valign="top" bgcolor="white" >
`xor` </td><td valign="top" bgcolor="white"> bitwise `xor` of two bitsets; returns new bitset
</td></tr></table>
```

In addition, these actions are identical:


```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Action
</th><th valign="top">
Same as
</th>
<tr>
<td valign="top" bgcolor="white" >
`to` </td><td valign="top" bgcolor="white"> `make`
</td>
<tr>
<td valign="top" bgcolor="white" >
`insert` </td><td valign="top" bgcolor="white"> `append`
</td>
<tr>
<td valign="top" bgcolor="white" >
`pick` </td><td valign="top" bgcolor="white"> `find`
</td>
<tr>
<td valign="top" bgcolor="white" >
`negate` </td><td valign="top" bgcolor="white"> `complement`
</td></tr></table>
```

These comparisons are supported:


```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Action
</th><th valign="top">
Description
</th>
<tr>
<td valign="top" bgcolor="white" >
`equal?` </td><td valign="top" bgcolor="white"> the bitsets are equal
</td>
<tr>
<td valign="top" bgcolor="white" >
`not-equal?` </td><td valign="top" bgcolor="white"> the bitsets are not equal
</td>
<tr>
<td valign="top" bgcolor="white" >
`same?` </td><td valign="top" bgcolor="white"> the bitsets use the same memory storage
</td>
<tr>
<td valign="top" bgcolor="white" >
`tail?` </td><td valign="top" bgcolor="white"> provided to allow `empty?` to work for bitsets
</td>
<tr>
<td valign="top" bgcolor="white" >
`zero?` </td><td valign="top" bgcolor="white"> always returns <span class="word">false</span> (because bitsets are not scalar values)
</td></tr></table>
```



#### Using bitsets
When you use a bitset, you normally want to:


```html
<ul>
<li>check if a single bit is set or not</li>
<li>check for if any one or more of several bits are set or not</li>
<li>check that all specified bits are set</li>
<li>find a character in a string specified by a bitset</li>
<li>parse a string for characters specified in a bitset</li>
</ul>
```



#### Modification
You can modify the bits specified by a bitset in a few ways.



#### Special notes


------------------------------------------------------------------
## block!

#### Concept
Blocks are groups of values and words. Blocks are used everywhere, from a script itself to blocks of data and code provided in a script.

Block values are indicated by opening and closing square brackets ([ ]) with any amount of data contained between them.



#### Format
Blocks can contain any number of values or no values at all. They can extend over multiple lines and can include any type of value, including other blocks.

An empty block:



#### Creation
The `to-block` function converts data to the `block!` datatype:



#### Related
Use `block?` to determine whether a value is an `block!`  datatype.



------------------------------------------------------------------
## char!

#### Concept
Characters are not strings; they are the individual values from which strings are constructed. A character can be printable, unprintable, or a control symbol.



#### Format
A `char!` value is written as a number sign (#) followed by a string enclosed in double quotes. The number sign is necessary to distinguish a character from a string:



#### Creation
Characters can be converted to and from other datatypes with the `to-char` function:



#### Related
Use `char?` to determine whether a value is a `char!` datatype.



------------------------------------------------------------------
## closure!

#### Concept
Normally, a function takes a set of arguments, computes with them,
then returns a result. There are several types of functions, depending
on how they are implemented.

The most common function type is `function!`, and they are created with
code such as:



#### More detail
In essence a closure is an object. When you define the closure, it
constructs a prototype object, and each time you call the closure, the
prototype object is instantiated and the body code is evaluated within
that context.

Here is another usage example:



------------------------------------------------------------------
## command!

#### Concept
Editor note: details go here


------------------------------------------------------------------
## datatype!

#### Concept
type of datatype



#### Format


#### Creation


------------------------------------------------------------------
## date!

#### Concept
Around the world, dates are written in a variety of formats. However, most countries use the day-month-year format. One of the few exceptions is the United States, which commonly uses a month-day-year format. For example, a date written numerically as 2/1/1999 is ambiguous. The month could be interpreted as either February or January. Some countries use a dash (-), some use a forward slash (/), and others use a period (.) as a separator. Finally, computer people often prefer dates in the 
year-month-day (ISO) format so they can be easily sorted.



#### Format
The REBOL language is flexible, allowing `date!` datatypes to be expressed in a variety of formats. For example, the first day of March can be expressed in any of the following formats:



#### Access
Refinements can be used with a date value to get any of its defined fields:


```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Refinement
</th><th valign="top">
Description
</th>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/day</span>
</td><td valign="top" bgcolor="white">
Gets the day.
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/month</span>
</td><td valign="top" bgcolor="white">
Gets the month.
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/year</span>
</td><td valign="top" bgcolor="white">
Gets the year.
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/yearday</span>
</td><td valign="top" bgcolor="white">
Gets the day of the year.
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/weekday</span>
</td><td valign="top" bgcolor="white">
Gets the weekday (1 for Mon, 7 for Sun).
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/time</span>
</td><td valign="top" bgcolor="white">
Gets the time (if present).
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/hour</span>
</td><td valign="top" bgcolor="white">
Gets the time's hour (if present)
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/minute</span>
</td><td valign="top" bgcolor="white">
Gets the time's minute (if present).
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/second</span>
</td><td valign="top" bgcolor="white">
Gets the time's second (if present).
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/zone</span>
</td><td valign="top" bgcolor="white">
Gets the time zone (if present).
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/utc</span>
</td><td valign="top" bgcolor="white">
Returns the UTC (universal) time.
</td></tr></table>
```

Here's how these refinements work:



#### Creation
Use the `to-date` function to convert values to a date!:



#### Disabling timezone or using UTC
To disable the timezone, just set it to `none!` :



#### Related
Use `date?` to determine whether a value is a `date!`  datatype.



------------------------------------------------------------------
## decimal!

#### Concept
The `decimal!` datatype is based on 64-bit standard IEEE 754 binary floating point
numbers. They are distinguished from integer numbers by a decimal point
(a period or a comma is allowed for international usage, see the notes
below).



#### Format
Decimal values are a sequence of numeric digits, followed by a decimal point, which can be a period (.) or a comma (,), followed by more digits. A plus (+) or minus (-) immediately before the first digit indicates sign. Leading zeros before the decimal point are ignored. Extra spaces, commas, and periods are not allowed.



#### Creation
Use the `to-decimal` function to convert `string!`,
`integer!`, `block!`, or `decimal!` datatypes to a decimal
number:



#### Related
Use `decimal?` to determine whether a value is an `decimal!` datatype.



------------------------------------------------------------------
## email!

#### Concept
An email address is a datatype. The `email!` datatype allows for easy expression of email addresses:



#### Format
The standard format of an email address is a name, followed by an at sign (@), followed by a domain. An email address can be of any length, but must not include any of restricted characters, such as square brackets, quotes, braces, spaces, newlines, etc..

The following `email!` datatype formats are valid:



#### Access
Refinements can be used with an email value to get the user name or domain. The refinements are:


```html
<ul>
<li>'/user - Get the user name.</li>
<li>'/host - Get the domain.</li>
</ul>
```

Here's how these refinements work:



#### Creation
The `to-email` function converts data to the `email!` datatype:



#### Related
Use `email?` to determine whether a value is an `email!`  datatype.



------------------------------------------------------------------
## end!

#### Concept
This is 

------------------------------------------------------------------
## error!

#### Concept
errors and throws



#### Format


#### Creation


------------------------------------------------------------------
## event!

#### Concept
user interface event (efficiently sized)



#### Format


#### Creation


------------------------------------------------------------------
## file!

#### Concept
The `file!` datatype can be a file name, directory name, or directory path.



#### Format
Files are designated with a percent sign (%)followed by a sequence of characters:



#### Creation
The `to-file` function converts data to the `file!` datatype:



#### Related
Use `file?` to determine whether a value is an `file!` datatype.



------------------------------------------------------------------
## frame!

#### Concept
internal context frame



#### Format


#### Creation


------------------------------------------------------------------
## function!

#### Concept
The REBOL language contains a few different types of functions, including
`native!`, `action!`, `function!`, and `closure!`. The main thing that
makes them different is how they are evaluated.

The `function!` datatype is a higher level function that is interpreted.
They are also called 

#### Format
Functions consist of a specification and a body block. The specification part provides the interface specification and any embedded documentation. The body is the code of the function.

The formal definition of `function` is:



#### Creation
Normally, you create a `function!` using a helper function.
There are a few choices:


```html
<table border="0" cellpadding="5" cellspacing="1" bgcolor="#d0d0e0" class="doctable">
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>`func`</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">Is the most common function defining function.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>`funct`</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">Is similar to `func`, but by default makes internal variables locals.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>`has`</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">Is for creating functions that have no formal arguments, only local variables.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>`does`</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">Is for creating functions that have no variables at all.
</td></tr>
</table>
```

More about functions is found in `code: defining functions`.



------------------------------------------------------------------
## get-path!

#### Concept
the value of a path



#### Format


#### Creation


------------------------------------------------------------------
## get-word!

#### Concept
the value of a word (variable)



#### Format


#### Creation


------------------------------------------------------------------
## gob!

#### Concept


------------------------------------------------------------------
## handle!

#### Concept
arbitrary internal object or value



#### Format


#### Creation


------------------------------------------------------------------
## hash!

#### Concept
This REBOL 2 datatype has not been implemented in REBOL 3. A request to re-introduce it has been made in [Curecode](http://curecode.org/rebol3/ticket.rsp?id=1494)



------------------------------------------------------------------
## image!

#### Concept
The `image!` datatype is a series that holds RGBA images. This datatype is used with REBOL/View.

The external image formats supported are GIF, JPEG, PNG and BMP. The loaded image can be manipulated as a series.



#### Format
Images are normally loaded from a file.  However, they can be expressed in source code as well by making an image.  The block provided includes the image size and its RGBA data.



#### Creation
Empty images can be created using `make` or to-image:



#### Related
Use `image?` to determine whether a value is the `image!` datatype:



------------------------------------------------------------------
## integer!

#### Concept
In R3 the `integer!` datatype has been expanded to be a 64-bit value.

It ranges from:



#### Format
Integer values consist of a sequence of numeric digits. A plus (+) or minus (-) immediately before the first digit indicates sign. (There cannot be a space between the sign and the first digit.) Leading zeros are ignored.



#### Conversion
Use the `to` function can convert a `string!`, `logic!`, `decimal!`, or `integer!` datatype to an integer:



#### Type Coercion
If a decimal and integer are combined in an expression, the integer is converted to a decimal:



#### Related
Use `integer?` to determine whether a value is an `integer!` datatype.



------------------------------------------------------------------
## issue!

#### Concept
An `issue!` is a series of characters used to sequence symbols or identifiers for things like telephone numbers, model numbers, serial numbers, and credit card numbers.

Issue values are a subset of series, and thus can be manipulated as series:



#### Format
Issues start with a number sign (#) and continue until the first delimiting character (such as a space) is reached.



#### Creation
The `to-issue` function converts data to the `issue!` datatype:



#### Related
Use `issue?` to determine whether a value is an `issue!`  datatype.



------------------------------------------------------------------
## library!

#### Concept
external library reference



#### Format


#### Creation


------------------------------------------------------------------
## list!

#### Concept
This REBOL 2 datatype has not been implemented in REBOL 3.



------------------------------------------------------------------
## lit-path!

#### Concept
literal path value



#### Format


#### Creation


------------------------------------------------------------------
## lit-word!

#### Concept
literal word value



#### Format


#### Creation


------------------------------------------------------------------
## logic!

#### Concept
The `logic!` datatype consists of two states representing true and false. They are often returned from comparisons such as:



#### Format
Normally, logic values are retrieved from the evaluation of comparison expressions. However, words can be set to a logic value and used to turn the word on or off:



#### Creation
The `to-logic` function converts `integer!` or `none!` values to the `logic!` datatype:



#### Related
Use `logic?` to determine whether a value is a `logic!` datatype.



------------------------------------------------------------------
## map!

#### Concept
name-value pairs (hash associative)


```html
<fieldset class="fset"><legend>Size Limit</legend>
<p>Currently, maps are limited to 2^26 - 1 (67'108'863) entries.</p>
</fieldset>
```



#### Format


#### Creation


------------------------------------------------------------------
## module!

#### Concept
loadable context of code and data



#### Format


#### Creation


------------------------------------------------------------------
## money!

#### Concept
There is a wide variety of international symbols for monetary denominations. Some symbols are used before the amount and some after. As a standard for representing international monetary values, the REBOL language uses the United States monetary format, but allows the inclusion of specific denominations.



#### Format
The `money!` datatype uses standard IEEE floating point numbers allowing up to 15 digits of precision including cents.

The language limits the length to 64 characters. Values that are out of range or cannot be represented in 64 characters are flagged as an error.

Monetary values are prefixed with an optional currency designator, followed by a dollar sign ($). A plus (+) or minus (-) can appear immediately before the first character (currency designator or dollar sign) to indicate sign.



#### Creation
Use the `to-money` function to convert money from a `string!`, `integer!`, `decimal!`, or `block!`.



#### Related
Use `money?` to determine whether a value is an `money!`  datatype.



------------------------------------------------------------------
## native!

#### Concept
direct CPU evaluated function



#### Format


#### Creation


------------------------------------------------------------------
## none!

#### Concept
The `none!` datatype contains a single value that represents nothing or no value.

The concept of none is not the same as an empty block, empty string, or null character. It is an actual value that represents non-existence.

A `none!` value can be returned from various functions, primarily those involving series (for example, `pick` and `find`).

The REBOL word `none!` is defined as a `none!` datatype and contains a `none!` value. The word `none!` is not equivalent to zero or false. However, `none!` is interpreted as false by many functions.

A `none!` value has many uses such as a return value from series functions like `pick`, `find` and select:



#### Format
The word `none!` is predefined to hold a `none!` value.

Although `none!` is not equivalent to zero or false, it is valid within conditional expressions and has the same effect as false:



#### Creation
The `to-none` function always returns `none!`.



#### Related
Use `none?` to determine whether a value is a `none!` datatype.



------------------------------------------------------------------
## object!

#### Concept
context of names with values



#### Format


#### Creation
There are a couple issues to be addressed with object creation:



------------------------------------------------------------------
## op!

#### Concept
infix operator (special evaluation exception)



#### Format


#### Creation


------------------------------------------------------------------
## pair!

#### Concept
A pair! datatype is used to indicate spatial coordinates, such as positions on a display.  They are used for both positions and sizes.  Pairs are used primarily in REBOL/View.



#### Format
A pair  is specified as integers separated by an x character.



#### Creation
Use `to-pair` to convert block or string values into a pair datatype:



#### Related
Use `pair?` to determine whether a value is a `pair!` datatype:



------------------------------------------------------------------
## paren!

#### Concept
A `paren!` datatype is a block that is immediately evaluated.  It is identical to a block in every way, except that it is evaluated when it is encountered and its result is returned.

When used within an evaluated expression, a `paren!` allows you to control the order of evaluation:



#### Format
Parens are identified by their open and closing parenthesis. They can span multiple lines and contain any data, including other paren values.



#### Creation
The `make` function can be used to allocate a paren value:



#### Related
Use `paren?` to test the datatype.



------------------------------------------------------------------
## path!

#### Concept
Paths are a collection of words and values delineated with forward slashes (/). Paths are used to navigate to or find something.

Paths can be used on series, maps, functions, and objects.  How a path operates depends on the datatype being used. Thus aths can be used to select values from blocks, pick characters from strings, access variables in objects, refine the operation of a function:



#### Format
Paths are expressed relative to a root word by providing a number of selection expressions, each separated by a forward slash (/). These expressions can be words or values. Their specific interpretation vary depending on the datatype of the root value.

The words supplied as selection expressions in paths are symbolic and are not evaluated. This is necessary to allow the most intuitive form for object referencing. To use a word's reference, an explicit word value reference is required:



#### Creation
You can `make` an empty path of a given size with:



#### Related
Use `path?`, `set-path?`, `get-path?`, and `lit-path?` to determine the datatype of a value.



------------------------------------------------------------------
## percent!

#### Concept
special form of decimals (used mainly for layout)



#### Format


#### Creation


------------------------------------------------------------------
## port!

#### Concept
external series, an I/O channel



#### Format


#### Creation


------------------------------------------------------------------
## rebcode!

#### Concept
virtual machine function



#### Format


#### Creation


------------------------------------------------------------------
## refinement!

#### Concept
Refinements are modifiers, similar to adjectives used in natural
(human) languages. A refinement indicates a variation in the use
of, or extension in the meaning of, a function, object,
filename, URL, or path. Refinements are always symbolic in their
value.

Refinements are used for functions:



#### Format
Refinements are composed with a slash followed by a valid REBOL
word (see the words section below for definition). Examples are:



#### Creation
Refinements can be created literally in source code:



#### Related
To test for a refinement, use the refinement? function:



------------------------------------------------------------------
## routine!

#### Concept
This datatype has not been implemented in REBOL 3. See `library!`.



------------------------------------------------------------------
## set-path!

#### Concept
definition of a path's value



#### Format


#### Creation


------------------------------------------------------------------
## set-word!

#### Concept
definition of a word's value



#### Format


#### Creation


------------------------------------------------------------------
## string!

#### Concept
Strings are a series of characters. All operations performable on series values can be performed on strings.



#### Format
String values are written as a sequence of characters surrounded by double quotes " " or braces {}. Strings enclosed in double quotes are restricted to a single line and must not contain unprintable characters.



#### Creation
Use `make` to create a pre-allocated amount of space for an empty string:



#### Related
Use `string?` or `series?` to determine whether a value is an `string!`  datatype:



------------------------------------------------------------------
## struct!

#### Concept
native structure definition



#### Format


#### Creation


------------------------------------------------------------------
## tag!

#### Concept
Tags are used in HTML and other markup languages to indicate how text fields are to be treated. For example, the tag &lt;HTML&gt; at the beginning of a file indicates that it should be parsed by the rules of the Hypertext Markup Language. A tag with a forward slash (/), such as &lt;/HTML&gt;, indicates the closing of the tag.

Tags are a subset of series, and thus can be manipulated as such:



#### Format
Valid tags begin with an open angle bracket (&lt;) and end with
a closing bracket (&gt;). For example:



#### Creation
The `to-tag` function converts data to the `tag!` datatype:



#### Related
Use `tag?` to determine whether a value is an `tag!` datatype.



------------------------------------------------------------------
## task!

#### Concept
evaluation environment



#### Format


#### Creation


------------------------------------------------------------------
## time!

#### Concept
The REBOL language supports the standard expression of time in hours, minutes, seconds, and subseconds. Both positive and negative times are permitted.

The `time!` datatype uses relative rather than absolute time. For example, 10:30 is 10 hours and 30 minutes rather than the time of 10:30 A.M. or P.M.



#### Format
Times are expressed as a set of integers separated by colons (:).. Hours and minutes are required, but seconds are optional. Within each field, leading zeros are ignored:



#### Access
Time values have three refinements that can be used to return specific information about the value:


```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Refinement
</th><th valign="top">
Description
</th>
<tr>
<td valign="top" bgcolor="white" >
'/hour
</td><td valign="top" bgcolor="white">
Gets the value's hour.
</td>
<tr>
<td valign="top" bgcolor="white" >
'/minute
</td><td valign="top" bgcolor="white">
Gets the value's minute.
</td>
<tr>
<td valign="top" bgcolor="white" >
'/second
</td><td valign="top" bgcolor="white">
Gets the value's second.
</td></tr></table>
```

Here's how to use a time value's refinements:



#### Creation
Times can be converted using the `to-time` function:



#### Related
Use `time?` to determine whether a value is a `time!`  datatype:



------------------------------------------------------------------
## tuple!

#### Concept
It is common to represent version numbers, Internet addresses, and RGB color values as a sequence of three or four integers. These types of numbers are called a `tuple!` (as in quintuple) and are represented as a set of integers separated by periods.



#### Format
Each integer field of a `tuple!` datatype can range between 0 and 255. Negative integers produce an error.

Three to ten integers can be specified in a tuple. In the case where only two integers are given, there must be at least two periods, otherwise the value is treated as a decimal.



#### Creation
Use the `to-tuple` function to convert data to the `tuple!` datatype:



#### Related
Use `tuple?` to determine whether a value is a `tuple!` datatype.



------------------------------------------------------------------
## typeset!

#### Concept
set of datatypes



#### Format


#### Creation


------------------------------------------------------------------
## unset!

#### Concept
no value returned or set



#### Format


#### Creation


------------------------------------------------------------------
## url!

#### Concept
URL is an acronym for Uniform Resource Locator, an Internet standard used to access resources such as web pages, images, files, and email across the network. The best known URL scheme is that used for web locations such as http://www.REBOL.com.

URL values are a subset of series, and thus can be manipulated as series:



#### Format
The first part of a URL indicates its communications protocol, called a 
scheme. The language supports several schemes, including: web pages ('HTTP:), file transfer ('FTP:), newsgroups ('NNTP:), email ('MAILTO:), files ('FILE:), finger ('FINGER:), whois ('WHOIS:), small network time ('DAYTIME:), post office ('POP:), transmission control ('TCP:) and domain name service ('DNS:). These scheme names are followed by characters that are dependent on which scheme being used.



#### Creation
The `to-url` function converts blocks to the `url!` datatype, the first element in the block is the scheme, the second element is the domain (with or without user:pass and port) the remaining elements are the path and file:



#### Related
The datatype word is `url!`.

Use `url?` to test the datatype.



------------------------------------------------------------------
## utype!

#### Concept
user defined datatype



#### Format


#### Creation


------------------------------------------------------------------
## vector!

#### Concept
high performance arrays (single datatype)



#### Format


#### Creation


------------------------------------------------------------------
## word!

#### Concept
Words are the symbols used by REBOL.  A word may or may not be a variable, depending on how it is used.  Words are quite often used directly as symbols, rather than variables. It is important to understand the difference.

REBOL does not use keywords -- those specific words that can only be used in one way.

For example, in C code, an if statement may be written:



#### Formats
There are a few different formats for words, depending on their intended usage:


```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Notation
</th><th valign="top">
Meaning
</th>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">word</span>
</td><td valign="top" bgcolor="white">
Get the <b>natural value</b> of the word. (If the value is a function, evaluate it, otherwise return it.)
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">word:</span>
</td><td valign="top" bgcolor="white">
Sets the word (like assignment) to a value.
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">:word</span>
</td><td valign="top" bgcolor="white">
Gets the word's value without evaluating it. (Useful for getting the value of a function.)
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">'word</span>
</td><td valign="top" bgcolor="white">
Treat word as a value (a word symbol). Does not evaluate it.
</td>
<tr>
<td valign="top" bgcolor="white" >
<span class="word">/word</span>
</td><td valign="top" bgcolor="white">
Treat the word as a refinement. Used mainly for optional arguments.
</td></tr></table>
```



#### Related functions
```html
<table border="0" cellspacing="1" cellpadding="4" bgcolor="#505050" class="doctable">
<tr bgcolor="silver"><th align="top">
Action
</th><th valign="top">
Type Word
</th><th valign="top">
Type Test
</th><th valign="top">
Conversion
</th>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">word:</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">set-word!</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">set-word?</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">to-set-word</div>
</td>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">:word</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">get-word!</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">get-word?</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">to-get-word</div>
</td>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">word</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">word!</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">word?</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">to-word</div>
</td>
<tr>
<td valign="top" bgcolor="white" >
<div class="codeline">'word</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">lit-word!</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">lit-word?</div>
</td><td valign="top" bgcolor="white">
<div class="codeline">to-lit-word</div>
</td></tr></table>
```



#### Format
Words are composed of alphabetic characters, numbers, and any of the following characters:



#### Creation
The `to-word` function converts values to the `word!` datatype.



#### Related
Use `word?`, `set-word?`, `get-word?`, and `lit-word?` to test the datatype.


