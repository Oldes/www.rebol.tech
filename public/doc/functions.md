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

```html

<p>Note: The <a href="#+">+</a> operator is a special infix form for this function.</p>
<p>Many different datatypes support addition.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print add 123 1
124</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print add 1.23 .004
1.234</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print add 1.2.3.4 4.3.2.1
5.5.5.5</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print add $1.01 $0.0000000001
$1.0100000001</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print add 3:00 -4:00
-1:00</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print add 31-Dec-1999 1
1-Jan-2000</code></pre></div>
<p>When adding values of different datatypes, the values must be compatible. Auto conversion of the values will occur into the datatype that has the most expansive representation. For example an integer added to a decimal will produce a decimal.</p>

```
------------------------------------------------------------------
## AJOIN
[[ join rejoin form reform append ]]

```html

<p>The <a href="#join">join</a> and <a href="#rejoin">rejoin</a> functions return the same datatype as their first element, be it a <span class="datatype">string!</span>, <span class="datatype">file!</span>, <span class="datatype">binary!</span>, <span class="datatype">tag!</span>, <span class="datatype">email!</span> or whatever. However, there are times when you just want to construct a <span class="datatype">string!</span>, and that's the purpose of <a href="#ajoin">ajoin</a>.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">ajoin ["test" 123]
"test123"</code></pre></div>
<p>It is similar to <a href="#reform">reform</a> but does not insert spaces between values:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">reform ["test" 123]
"test 123"</code></pre></div>
<p>Note that the block is always evaluated:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">time: 10:30
ajoin [time/hour "h" time/minute "m"]
"10h30m"</code></pre></div>
<p>The <a href="#ajoin">ajoin</a> function is equivalent to:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">to-string reduce block</code></pre></div>
<h6 id="section-2">How it differs</h6>
<p>Here are examples that show how <a href="#ajoin">ajoin</a> differs from <a href="#join">join</a> and <a href="#rejoin">rejoin</a>.</p>
<p>Compare:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">ajoin [&lt;test&gt; 123]
"&lt;test&gt;123"</code></pre></div>
<p>with:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">rejoin [&lt;test&gt; 123]
&lt;test123&gt;</code></pre></div>
<p>and:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">join &lt;test&gt; 123
&lt;test123&gt;</code></pre></div>
<p>Notice that the last two examples return a <span class="datatype">tag!</span>, not a <span class="datatype">string!</span>.</p>

```
------------------------------------------------------------------
## ALL
[[ any and or case switch ]]

```html

<p>The <a href="#all">all</a> function is the most common way to test multiple conditions, such as in the line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if all [num &gt; 1  num &lt; 1000] [do something]</code></pre></div>
<p>It works by evaluating each expression in a block until one of the expressions returns <span class="datatype">none!</span> or false, in which case a <span class="datatype">none!</span> is returned. Otherwise, the value of the last expression will be returned.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print all [1 none]
none</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print all [none 1]
none</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print all [1 2]
2</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print all [10 &gt; 1 "yes"]
yes</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print all [1 &gt; 10 "yes"]
none</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">time: 10:30
if all [time &gt; 10:00 time &lt; 11:00] [print "time is now"]
time is now</code></pre></div>
<p>No other expressions are evaluated beyond the point where a value fails:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">a: 0
all [none a: 2]
print a
0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">a: 0
all [1 a: 2]
print a
2</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">day: 10
time: 9:45
ready: all [day &gt; 5  time &lt; 10:00  time: 12:00]
print time
12:00</code></pre></div>
<p>The <a href="#any">any</a> function is a companion of <a href="#all">all</a> to test for the opposite condition, where any one of the values will result in a true result.</p>

```
------------------------------------------------------------------
## ALL-OF
------------------------------------------------------------------
## ALSO
[[ if either any all ]]

```html

<p>The <a href="#also">also</a> function lets you evaluate two expressions, but return the first, rather than the second. This function may seem a bit odd at first, but in many cases it can save you from needing another temporary variable.</p>
<p>Consider the case where you want to evaluate a block and return its result, but before returning the result, you want to change directories.</p>
<p>You could write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">result: do block
change-dir old-dir
return result</code></pre></div>
<p>Or, you could write</p>
<div class="example-code"><pre class="code-block"><code class="rebol">return also do block change-dir old-dir</code></pre></div>
<p>In fact, that's actually what happens in the <a href="#in-dir">in-dir</a> function.</p>
<p>Another case might be an I/O port used by a function that wants to <a href="#return">return</a> the port's data but also <a href="#close">close</a> it:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">return also port/locals/buffer close port</code></pre></div>
<p>If you <a href="#close">close</a> the port first, the buffer cannot be accessed.</p>

```
------------------------------------------------------------------
## ALTER
[[ find remove insert unique intersect exclude difference ]]

```html

<p>The <a href="#alter">alter</a> function helps you manage small data-sets. It either adds or removes a value depending on whether the value is already included. (The word <a href="#alter">alter</a> is short for the word "alternate", the action taking place.)</p>
<p>For example, let's say you want to keep track of a few options used by your code. The options may be: flour, sugar, salt, and pepper. The following code will create a new block (to hold the data set) and add to it:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">options: copy []
alter options 'salt
probe options
[salt]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">alter options 'sugar
probe options
[salt sugar]</code></pre></div>
<p>You can use functions like <a href="#find">find</a> to test the presence of an option in the set:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if find options 'salt [print "Salt was found"]
Salt was found</code></pre></div>
<p>If you use <a href="#alter">alter</a> a second time for the same option word, it will be removed:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">alter options 'salt
probe options
[sugar]</code></pre></div>
<p>Normally <a href="#alter">alter</a> values are symbolic words (such as those shown above) but any datatype can be used such as integers, strings, etc.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">alter options 120
alter options "test"
probe options
[sugar 120 "test"]</code></pre></div>
<p>Also, <a href="#alter">alter</a> returns true if the value was added to the series, or false if the value was removed.</p>

```
------------------------------------------------------------------
## AND
[[ or all not xor logic? integer? ]]

```html

<p>For <span class="datatype">logic!</span> values, both values must be true to return true, otherwise a false is returned. AND is an infix operator.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print true and true
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print true and false
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print (10 &lt; 20) and (20 &gt; 15)
true</code></pre></div>
<fieldset class="fset"><legend>Programming style</legend>
<p>It's usually better to use <a href="#all">all</a> for anding conditional logic, such as the example above.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if all [10 &lt; 20 20 &gt; 15] ...</code></pre></div>
</fieldset>
<p>For <span class="datatype">integer!</span>, <span class="datatype">tuple!</span>, <span class="datatype">binary!</span>, and other datatypes, each bit is separately anded.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print 123 and 1
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print 1.2.3.4 and 255.0.255.0
1.0.3.0</code></pre></div>

```
------------------------------------------------------------------
## AND~
[[ and or xor or~ xor~ ]]

```html

<p>This is the primary function behind the <a href="#and">and</a> operator. It can be used where you want prefix rather than infix notation:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">bits: and~ mask 3</code></pre></div>

```
------------------------------------------------------------------
## ANY
[[ all or and case switch ]]

```html

<p>The <a href="#any">any</a> function is the most common way to test for one of multiple conditions, such as in the line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if any [a &gt; 10  b &gt; 20  c &gt; 30] [do something]</code></pre></div>
<p>Here, if any one of the conditions produces a true result, the <a href="#if">if</a> will evaluate the block.</p>
<p>This function works by evaluating each expression in a block until one of the expressions returns a value other than <span class="datatype">none!</span> or false, in which case the value is returned. Otherwise, <span class="datatype">none!</span> will be returned.</p>
<p>Examples to help show how it works:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print any [1 none]
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any [none 1]
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any [none none]
none</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any [false none]
none</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any [true none]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">time: 10:30
if any [time &gt; 10:00  time &lt; 11:00] [print "time is now"]
time is now</code></pre></div>
<p>No other expressions are evaluated beyond the point where a successful value is found. This can be useful. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">a: 0
any [none a: 2]
print a
2</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">a: 0
any [1 a: 2]
print a
0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">day: 10
time: 9:45
ready: any [day &gt; 5  time &lt; 10:00  time: 12:00]
print time
9:45</code></pre></div>
<p>The <a href="#any">any</a> function is also useful for setting default values. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">size: any [size 100]</code></pre></div>
<p>If size was <span class="datatype">none!</span>, then it gets set to 100. This works even better if there are alternative defaults:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">size: any [size prefs/size 100]</code></pre></div>
<p>Another use for <a href="#any">any</a> is to emulate a sequence of if...elseif...elseif...else. Instead of writing:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">either cond-1 [
    code-1
] [
    either cond-2 [
        code-2
    ] [
        either cond-3 ...
    ]
]</code></pre></div>
<p>it is possible to write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">any [
    if cond-1 [
        code-1
        true ; in case code-1 returns FALSE or NONE
    ]
    if cond-2 [
        code-2
        true
    ]
    ...
]</code></pre></div>
<p>Also see the <a href="#case">case</a> function for more about this code pattern.</p>
<p>The <a href="#all">all</a> function is a companion of <a href="#any">any</a> to test for the opposite condition, where all of the values must be true to return a true result.</p>

```
------------------------------------------------------------------
## ANY-BLOCK?
[[ block? paren? path? any-function? any-string? any-word? ]]

```html

<p>Returns true only if the value is a <span class="datatype">block!</span> (any kind of block) and false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-block? [1 2]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-block? first [(1 2) 3]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-block? 'a/b/c
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-block? 12
false</code></pre></div>
<p>To learn what datatypes are blocks:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-block!
block! paren! path! set-path! get-path! lit-path!</code></pre></div>

```
------------------------------------------------------------------
## ANY-FUNCTION?
[[ function? native? op? any-block? any-string? any-word? ]]

```html

<p>Returns true if the value is any type of function and returns false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-function? :find
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-function? :+
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-function? func [] [print "hi"]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-function? 123
false</code></pre></div>
<p>To learn what datatypes are functions:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-function!
native! action! rebcode! command! op! closure! function!</code></pre></div>

```
------------------------------------------------------------------
## ANY-OBJECT?
------------------------------------------------------------------
## ANY-OF
------------------------------------------------------------------
## ANY-PATH?

```html

<p>Returns true if the value is any type of <span class="datatype">path!</span> and returns false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-path? 'test/this
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-path? first [example/item: 10]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-path? second [print :example/item]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-path? 123
false</code></pre></div>
<p>To learn what datatypes are paths:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-path!
path! set-path! get-path! lit-path!</code></pre></div>

```
------------------------------------------------------------------
## ANY-STRING?
[[ string? file? email? url? any-block? any-function? ]]

```html

<p>Returns true for any type of string, and false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if any-string? "Hello" [print "a string"]
a string</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe any-string? email@rebol.com
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe any-string? ftp://ftp.rebol.com
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe any-string? %dir/file.txt
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe any-string? 11-Jan-2000
false</code></pre></div>
<p>To see what datatypes are strings:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-string!
string! file! email! url! tag! issue!</code></pre></div>

```
------------------------------------------------------------------
## ANY-WORD?
[[ any-block? any-function? any-string? ]]

```html

<p>Returns true for any type of word and false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-word? 'word
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-word? /word
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-word? first [set-word: 'lit-word :get-word]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-word? second [set-word: 'lit-word :get-word]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-word? third [set-word: 'lit-word :get-word]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-word? 123
false</code></pre></div>
<p>To see what datatypes are words:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print any-word!
word! set-word! get-word! lit-word! refinement!</code></pre></div>

```
------------------------------------------------------------------
## APPEND
[[ insert change remove repend ]]

```html

<p>The <a href="#append">append</a> function is a shortcut for doing an <a href="#insert">insert</a> at the tail of any type of <a href="/r3/docs/concepts/series.html" class="con">series</a> and returning the head:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">head insert tail series value</code></pre></div>
<p>Basic examples:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">string: copy "hello"
probe append string " there"
"hello there"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">file: copy %file
probe append file ".txt"
%file.txt</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">url: copy http://
probe append url "www.rebol.com"
http://www.rebol.com</code></pre></div>
<p>The /only refinement forces a block to be appended as a single block element, rather than appending the separate elements of the block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">block: copy [1 2 3]
probe append block [4 5 6]
[1 2 3 4 5 6]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">block: copy [1 2 3]
probe append/only block [4 5 6]
[1 2 3 [4 5 6]]</code></pre></div>
<p>To learn more about the operation of the other refinements, see the <a href="#insert">insert</a> function.</p>

```
------------------------------------------------------------------
## APPLY
[[ do switch case ]]

```html

<p>When you evaluate a function, you normally provide any arguments directly in-line with its call:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">append data 123</code></pre></div>
<p>However, there are times when you want to store the arguments as a single block and pass them to the function. This is the purpose of the <a href="#apply">apply</a> function. The above example can be written as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">apply :append [data 123]</code></pre></div>
<p>or, using a variable to hold the block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">args: [data 123]
apply :append args</code></pre></div>
<p>If any arguments are missing from the block, a <span class="datatype">none!</span> is passed instead:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: [456]
apply :append [data]
probe data
[456 none]</code></pre></div>
<p>Function refinements can also be passed in the order they are specified by the arguments spec block. For example, we can see:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; ? append
USAGE:
    APPEND series value /part length /only /dup count</code></pre></div>
<p>So in this example we use the /dup refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: [456]
apply :append [data 1 none none none true 3]
probe data
[456 1 1 1]</code></pre></div>
<p>Note that the refinement itself must be set to true.</p>

```
------------------------------------------------------------------
## ARCCOSINE
[[ arcsine arctangent cosine exp log-10 log-2 log-e power sine square-root tangent ]]

```html

<p>The <a href="#arccosine">arccosine</a> provides the inverse of the <a href="#cosine">cosine</a> function.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print arccosine .5
60.0</code></pre></div>
<p>Note that arccosine goes to infinity at 90 degrees and will cause a numeric overflow.</p>

```
------------------------------------------------------------------
## ARCSINE
[[ arccosine arctangent cosine exp log-10 log-2 log-e power sine square-root tangent ]]

```html

<p>The <a href="#arcsine">arcsine</a> provides the inverse of the <a href="#sine">sine</a> function.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print arcsine .5
30.0</code></pre></div>
<p>Note that arccsine goes to infinity at 0 and each 180 degrees and will cause a numeric overflow.</p>

```
------------------------------------------------------------------
## ARCTANGENT
[[ arccosine arcsine cosine exp log-10 log-2 log-e power sine square-root tangent ]]

```html

<p>The <a href="#arctangent">arctangent</a> function provides the inverse of the <a href="#tangent">tangent</a> function.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print arctangent .22
12.40741852740074</code></pre></div>

```
------------------------------------------------------------------
## ARCTANGENT2
------------------------------------------------------------------
## ARRAY
[[ make pick poke ]]

```html

<p>In REBOL, arrays are simply blocks that are initialized to a specific size with all elements set to an initial value (v:none by default). The <a href="#array">array</a> function is used to create and initialize arrays.</p>
<p>Supplying a single integer as the argument to <a href="#array">array</a> will create an array of a single dimension. The example below creates a five element array with values set to none:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">block: array 5
probe block
[none none none none none]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print length? block
5</code></pre></div>
<p>To initialize an array to values other than NONE, use the /initial refinement. The example below intializes a block with zero values:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">block: array/initial 5 0
probe block
[0 0 0 0 0]</code></pre></div>
<p>To create an array of multiple dimensions, provide a block of integers as the argument to the <a href="#array">array</a> function. Each integer specifies the size of that dimension of the array. (In REBOL, such multidimensional arrays are created using blocks of blocks.)</p>
<div class="example-code"><pre class="code-block"><code class="rebol">xy-block: array [2 3]
probe xy-block
[[none none none] [none none none]]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">xy-block: array/initial [2 3] 0
probe xy-block
[[0 0 0] [0 0 0]]</code></pre></div>
<p>Once an array has been created, you can use paths or the <a href="#pick">pick</a> and <a href="#poke">poke</a> functions to set and get values of the block based on their indices:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">block/3: 1000
poke block 5 now
probe block
[0 0 1000 0 12-Feb-2009/17:46:59-8:00]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe block/3
1000</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">repeat n 5 [poke block n n]
probe block
[1 2 3 4 5]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">xy-block/2/1: 1.2.3
xy-block/1/3: copy "test"
probe xy-block
[[0 0 "test"] [1.2.3 0 0]]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe xy-block/2/1
1.2.3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">repeat y 2 [
    dim: pick xy-block y
    repeat x 3 [poke dim x to-pair reduce [x y]]
]
probe xy-block</code></pre></div>
<h6 id="section-2">Coding Style Notes</h6>
<p>REBOL uses the concept of expandable series for holding and manipulating data, rather than the concept of fixed size arrays. For example, in REBOL you would normally write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">block: copy []
repeat n 5 [append block n]</code></pre></div>
<p>rather than:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">block: array 5
repeat n 5 [poke block n n]</code></pre></div>
<p>In other words, REBOL does not require you to specify the size of data arrays (blocks, bytes, or strings) in advance. They are dynamic.</p>

```
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

```html

<p>Provides a shortcut for creating <span class="datatype">pair!</span> values from separate X and
Y integers.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print as-pair 100 50
100x50</code></pre></div>
<p>See the <span class="datatype">pair!</span> word for more detail.</p>

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

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## ASIN
------------------------------------------------------------------
## ASK
[[ confirm input prin print ]]

```html

<p>Provides a common prompting function that is the same as a <a href="#prin">prin</a> followed by an <a href="#input">input</a>. The resulting input will
have spaces trimmed from its head and tail. The /hide refinement hides input with "*" characters. The function returns a string!.</p>
<p>Example, where the user enters Luke as input:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">ask "Your name, please? "
Your name, please? Luke
== "Luke"</code></pre></div>

```
------------------------------------------------------------------
## ASSERT
[[ all try ]]

```html

<p>In code, it is common to check conditions that should always be valid or true. For example, a check may be made for a value to be in range or of a given datatype.</p>
<p>Since the conditions are always supposed to be true, it's often not worth the effort to provide a detailed error message or explanation if the condition fails, and often such information would only be meaningful to the programmer, not the end user.</p>
<p>To make it easier to check such conditions, the <a href="#assert">assert</a> function is provided.</p>
<p>Assert can check "truth" conditions, or with a refinement, it can check datatype validity conditions.</p>
<h7 id="section-2">Asserting truth</h7>
<p>To check truth conditions, the argument of <a href="#assert">assert</a> is a block of one or more conditions, and each is checked (similar to <a href="#all">all</a>) to be true:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">num: 10
assert [num &gt; 20]
** Script error: assertion failed for: [num &gt; 20]
** Where: assert
** Near: assert [num &gt; 20]</code></pre></div>
<p>Note that for compound assertions, the error message will indicate the assertion that failed:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">num: 10
age: 20
assert [num &gt; 0 age &gt; 50]
** Script error: assertion failed for: [age &gt; 50]
** Where: assert
** Near: assert [num &gt; 0 age &gt; 50]</code></pre></div>
<p>Look at the error line closely, and you can tell which one failed.</p>
<p>Note: only the first three elements of the failed assertion will be shown (to help avoid long error lines.)</p>
<h7 id="section-3">Asserting datatypes</h7>
<p>It is also common to validate datatypes using the /type refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">age: "37"
name: "Bob"
assert/type [age integer! name string!]
** Script error: datatype assertion failed for: age
** Where: assert
** Near: assert/type [age integer! name string!]</code></pre></div>
<p>It fails because age is actually a string, not an integer.</p>
<p>The <a href="#assert">assert</a> function is useful for validating value before a section of code that depends on those value:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">assert/type [
    spec object!
    body block!
    spec/size number!
    spec/name [string! none!]
    spec/options [block! none!]
]</code></pre></div>
<p>Note that <a href="#assert">assert</a> is safe to use on all function datatypes. The functions will not be evaluated as part of the process; therefore, <a href="#assert">assert</a> is an easy way to prevent function passage in unwanted cases.</p>

```
------------------------------------------------------------------
## AT
[[ skip pick head tail ]]

```html

<p>Provides a simple way to index into any type of <a href="/r3/docs/concepts/series.html" class="con">series</a>. <a href="#at">at</a> returns the series at the new index point.</p>
<p>Note that the operation is relative to the current position within the series.</p>
<p>A positive integer N moves to the position N in the series:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">numbers: [11 22 33]
print at numbers 2
22 33</code></pre></div>
<p>An index of 0 is the same as an index of 1:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print at numbers 0
11 22 33</code></pre></div>
<p>Using a negative index N, you can go N values backwards in a series:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">numbers: at numbers 3
print numbers
33</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print at numbers -1
22 33</code></pre></div>
<p>More examples, combined with other series functions:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">words: [grand grape great good]
print first at words 2
grape</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">remove at words 2
insert at words 3 [super]
probe words
[grand great super good]</code></pre></div>

```
------------------------------------------------------------------
## ATAN
------------------------------------------------------------------
## ATAN2
------------------------------------------------------------------
## ATTEMPT
[[ try error? ]]

```html

<p>The <a href="#attempt">attempt</a> function is a shortcut for the frequent case of:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">error? try [block]</code></pre></div>
<p>More accurately, this is performed:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if not error? try [set/any 'val block] [val]</code></pre></div>
<p>The format for <a href="#attempt">attempt</a> is:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">attempt [block]</code></pre></div>
<p><a href="#attempt">attempt</a> is useful where you either do not care about the error result or you want to make simple types of decisions based on the error.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">attempt [make-dir %fred]</code></pre></div>
<p><a href="#attempt">attempt</a> returns the result of the block if an error did not occur.  If an error did occur, a none is returned.</p>
<p>In the line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">value: attempt [load %data]
probe value
none</code></pre></div>
<p>the value is set to none if the %data file cannot be loaded (e.g. it is missing or contains an error).  This allows you to write conditional code such as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if not value: attempt [load %data] [print "Problem"]
Problem</code></pre></div>
<p>Or code such as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">value: any [attempt [load %data] [12 34]]
probe value
[12 34]</code></pre></div>

```
------------------------------------------------------------------
## ATZ
------------------------------------------------------------------
## AVERAGE
------------------------------------------------------------------
## BACK
[[ next last head tail head? tail? ]]

```html

<p>Works on any type of <a href="/r3/docs/concepts/series.html" class="con">series</a>. If the series is at its head, it will remain at its head. <a href="#back">back</a> will not go past the head, nor will it wrap to the tail.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print back tail "abcd"
d</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: tail "time"
until [
    str: back str
    print str
    head? str
]
e
me
ime
time</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: tail [1 2 3 4]
until [
    blk: back blk
    print first blk
    head? blk
]
4
3
2
1</code></pre></div>

```
------------------------------------------------------------------
## BINARY
------------------------------------------------------------------
## BINARY?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print binary? #{13ff acd0}
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print binary? 1234
false</code></pre></div>

```
------------------------------------------------------------------
## BIND
[[ bind? use do func function does make import ]]

```html

<p>Binds meaning to words in a block. That is, it gives words a context in which they can be interpreted. This allows blocks to be exchanged between different contexts, which permits their words to be understood. For instance a function may want to treat words in a global database as being local to that function.</p>
<p>The second argument to <a href="#bind">bind</a> is a word from the context in which the block is to be bound. Normally, this is a word from the local context (e.g. one of the function arguments), but it can be a word from any context within the system.</p>
<p><a href="#bind">bind</a> will modify the block it is given. To avoid that, use the /copy refinement. It will create a new block that is returned as the result.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">words: [a b c]
fun: func [a b c][print bind words 'a]
fun 1 2 3
fun "hi" "there" "fred"
hi there fred</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">words: [a b c]
object: make object! [
    a: 1
    b: 2
    c: 3
    prove: func [] [print bind words 'a]
]
object/prove
1 2 3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">settings: [start + duration]
schedule: function [start] [duration] [
    duration: 1:00
    do bind settings 'start
]
print schedule 10:30
11:30</code></pre></div>
<p class="need">Editor note: Describe /new here<p>
<p class="need">Editor note: Describe /set here<p>

```
------------------------------------------------------------------
## BITSET?
[[ charset ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print bitset? make bitset! "abc"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print bitset? charset "abc"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print bitset? 123
false</code></pre></div>

```
------------------------------------------------------------------
## BLOCK?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print block? [1 2 3]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print block? "1 2 3"
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">data: load "1 2 3"  ;  converts "1 2 3" into a block
if block? data [print data]
1 2 3</code></pre></div>

```
------------------------------------------------------------------
## BLUR
------------------------------------------------------------------
## BODY-OF
[[ reflect spec-of title-of types-of values-of words-of ]]

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## BREAK
[[ continue catch exit return loop repeat for forall foreach forever forskip while until ]]

```html

<p>The <a href="#break">break</a> function stops loop functions.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">repeat n 5 [
    print n
    if n &gt; 2 [break]
]
1
2
3</code></pre></div>
<p>The current loop is immediately terminated and evaluation resumes after the <a href="#repeat">repeat</a> function.</p>
<h6 id="section-2">Return Value</h6>
<p>The <a href="#break">break</a> /return refinement will return a value from a loop. It is commonly used to return a specific value or pass to a conditional expression when the loop is terminated early.</p>
<p>Here's an example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print repeat n 5 [
    if n &gt; pi [break/return n]
    none
]
4</code></pre></div>
<p>An example using <a href="#foreach">foreach</a> :</p>
<div class="example-code"><pre class="code-block"><code class="rebol">values: [8:30 breakfast 12:00 lunch 5:00 dinner]
meal: foreach [time event] [
    if time &gt; 14:00 [break/return event]
    none
]
probe meal
dinner</code></pre></div>
<h6 id="section-3">Important Scoping Rule</h6>
<p>The <a href="#break">break</a> function acts immediately on the "closest block".</p>
<p>Although <a href="#break">break</a> can be placed anywhere within the block being repeated, even within a sub-block or function, because <a href="#break">break</a> is a function that is not directly bound to the loop, it will break the closest loop, not necessarily the intended loop. This does not affect most programs but could affect custom-made loop functions.</p>
<p>In this example, even though the <a href="#break">break</a> appears in the <a href="#repeat">repeat</a> loop, it applies to the a-loop <a href="#loop">loop</a> block and has no effect on the outer <a href="#repeat">repeat</a> loop.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">a-loop: func [count block] [loop count block]
repeat a 3 [
    print a
    a-loop 4 [break]
]
1
2
3</code></pre></div>

```
------------------------------------------------------------------
## BROWSE

```html

<p>If the browser cannot be found, nothing will happen.</p>

```
------------------------------------------------------------------
## CALL
[[ do launch ]]

```html

<p>The <a href="#call">call</a> function interfaces to the operating system's command shell to execute programs, shell commands, and redirect command input and output.</p>
<p><a href="#call">call</a> is normally blocked by the security level specified with the <a href="#secure">secure</a> function. To use it, you must change your <a href="#secure">secure</a> settings or run the script with reduced security (at your own risk):</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure call</code></pre></div>
<p>The <a href="#call">call</a> function accepts one argument, which can be a string or a block specifying a shell command and its arguments. The following example shows a string as the <a href="#call">call</a> argument.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">call "cp source.txt dest.txt"</code></pre></div>
<p>Use a block argument with <a href="#call">call</a> when you want to include REBOL values in the call to a shell command, as shown in the following example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">source: %source.txt
dest: %dest.txt
call reduce ["cp" source dest]</code></pre></div>
<p>The <a href="#call">call</a> function translates the file names in a block to the notation used by the shell. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">[dir %/c/windows]</code></pre></div>
<p>will convert the file name to windows shell syntax before doing it.</p>
<p>When shell commands are called, they normally run as a separate process in parallel with REBOL. They are asynchronous to REBOL. However, there are times when you want to wait for a shell command to finish, such as when you are executing multiple shell commands.</p>
<p>In addition, every shell command has a return code, which normally indicates the success or failure of the command. Typically, a shell command returns zero when it is successful and a non-zero value when it is unsuccessful.</p>
<p>The /wait refinement causes the <a href="#call">call</a> function to wait for a command's return code and return it to the REBOL program. You can then use the return code to verify that a command executed successfully, as shown in the following example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if zero? call/wait "dir" [
    print "worked"
]</code></pre></div>
<p>In the above example, <a href="#call">call</a> successfully executes the Windows dir command, which is indicated by the zero return value. However, in the next example, <a href="#call">call</a> is unsuccessful at executing the xcopy command, which is indicated by the return value other than zero.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if not zero? code: call/wait "xcopy" [
    print ["failed:" code]
]</code></pre></div>
<p>In Windows and Unix (Linux), input to a shell command can be redirected from a file, URL, string, or port. By default, a shell command's output and errors are ignored by REBOL. However, shell command output and errors can be redirected to a file, URL, port, string, or the REBOL console.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">instr: "data"
outstr: copy ""
errstr: copy ""
call/input/output/error "sort" instr outstr errstr
print [outstr errstr]</code></pre></div>
<p>See the REBOL Command Shell Interface documentation for more details.</p>
<p class="need">Editor note: Proper link to the REBOL Command Shell Interface?<p>

```
------------------------------------------------------------------
## CASE
[[ switch if either select find ]]

```html

<p>The <a href="#case">case</a> function provides a useful way to evaluate different expressions depending on specific conditions. It differs from the <a href="#switch">switch</a> function because the conditions are evaluated and can be an expression of any length.</p>
<p>The basic form of <a href="#case">case</a> is:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">case [
    cond1 [code1]
    cond2 [code2]
    cond3 [code3]
]</code></pre></div>
<p>The if a condition is true (that is, it is not false or none ) then the block that follows it is evaluated, otherwise the next condition is evaluated.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">num: 50
case [
    num &lt; 10 [print "small"]
    num &lt; 100 [print "medium"]
    num &lt; 1000 [print "large"] 
]
medium</code></pre></div>
<p>To create a default case, simply use true as your last condition:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">num: 10000
case [
    num &lt; 10 [print "small"]
    num &lt; 100 [print "medium"]
    num &lt; 1000 [print "large"] 
    true [print "huge"]
]
huge</code></pre></div>
<h6 id="section-2">Return Value</h6>
<p>The <a href="#case">case</a> function will return the value of the last expression it evaluated. This can come in handy:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">num: 50
value: case [
    num &lt; 10 [num + 2]
    num &lt; 100 [num / 2]
    true [0]
]
print value
25</code></pre></div>
<h6 id="section-3">Evaluating All</h6>
<p>Normally the <a href="#case">case</a> function stops after the first true condition is found and its block evaluated. However, the /all option forces <a href="#case">case</a> to evaluate the expressions for all true conditions.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">num: 50
case/all [
    num &lt; 10 [print "small"]
    num &lt; 100 [print "medium"]
    num &lt; 1000 [print "large"] 
]
medium
large</code></pre></div>

```
------------------------------------------------------------------
## CATCH
[[ throw do try ]]

```html

<p><a href="#catch">catch</a> and <a href="#throw">throw</a> go together. They provide a way to exit from a block without evaluating the rest of the block.
To use it, provide <a href="#catch">catch</a> with a block to evaluate. If within that block a <a href="#throw">throw</a> is evaluated, it will return from the <a href="#catch">catch</a> at that point.</p>
<p>The result of the <a href="#catch">catch</a> will be whatever was passed as the argument to the <a href="#throw">throw</a>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">write %file.txt "i am a happy little file with no real purpose"
print catch [
    if exists? %file.txt [throw "Doc found"]
    "Doc not found"
]
Doc not found</code></pre></div>
<p>When using multiple <a href="#catch">catch</a> functions, provide them with a name using the /name refinement to identify which one will <a href="#catch">catch</a> which <a href="#throw">throw</a>.</p>
<p class="need">Editor note: Example with /name<p>
<p class="need">Editor note: Example of using catch in a function spec.<p>

```
------------------------------------------------------------------
## CAUSE-ERROR

```html

<p class="need">Editor note: Description is a stub.<p>
<p><a href="#cause-error">cause-error</a> constructs and immediately throws an <span class="datatype">error!</span>.</p>
<p class="need">Editor note: Link to concept of error types?<p>
<p class="need">Editor note: Argument description is a stub.<p>
<p>The err-type argument controls the general type of error to construct, valid values are the words of the system/catalog/errors object. The err-id argument selects a specific error type within the err-type class of errors. The args argument is used to pass error-specific values</p>
<p class="need">Editor note: Description of error IDs is a stub.<p>
<p>All information about the currently available error types can be found in system/catalog/errors:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; words-of system/catalog/errors
== [Throw Note Syntax Script Math Access Command resv700 User Internal]</code></pre></div>
<p>The specific errors within a given class can be inspected similarly:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; ? system/catalog/errors/math        
SYSTEM/CATALOG/ERRORS/MATH is an object of value: 
   code            integer!  400 
   type            string!   "math error" 
   zero-divide     string!   "attempt to divide by zero" 
   overflow        string!   "math or number overflow" 
   positive        string!   "positive number required"</code></pre></div>
<p>All words except for code and type within an error type are possible specific errors. Their associated value is part of the error message that will displayed to the user if the error remains unhandled.</p>
<p>Some errors take arguments:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; ? system/catalog/errors/script/no-value   
SYSTEM/CATALOG/ERRORS/SCRIPT/NO-VALUE is a block of value: [:arg1 "has no value"]</code></pre></div>
<p>As an example, this no-value error which takes a single argument can be caused as follows:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; cause-error 'script 'no-value 'Foo  
** script error: Foo has no value</code></pre></div>
<p>Similarly, the two-argument no-arg error can be caused as follows:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; cause-error 'script 'no-arg [Foo bar] 
** script error: Foo is missing its bar argument</code></pre></div>

```
------------------------------------------------------------------
## CD
[[ change-dir delete ls list-dir make-dir mkdir pwd rm what-dir ]]

```html

<p>Variant of <a href="#change-dir">change-dir</a> for shell use. Supports inputting words as directory names:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">cd ..
cd somewhere</code></pre></div>

```
------------------------------------------------------------------
## CHANGE
[[ append clear insert remove sort ]]

```html

<p>The <a href="#change">change</a> function modifies any type of <a href="/r3/docs/concepts/series.html" class="con">series</a>, such as a <span class="datatype">string!</span> or <span class="datatype">block!</span>, at its current index position.</p>
<p>It has many variations, but let's take a simple example that modifies a <span class="datatype">string!</span> series:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">name: "bog"
change name "d"
probe name
"dog"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">change next name "i"
probe name
"dig"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">change tail name "it"
probe name
"digit"</code></pre></div>
<p>Here is an example that changes a <span class="datatype">block!</span> series:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">colors: [red green blue]
change colors 'gold
probe colors
[gold green blue]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">change at colors 3 [silver orange teal]
probe colors
[gold green silver orange teal]</code></pre></div>
<p>As you can see, if the second argument is a single value, it will
replace the value at the current position in the first
series. However, if the second argument is a series compatible
with the first (block or string-based datatype), all of 
its values will replace those of the first argument or
series.</p>
<h6 id="section-2">Result</h6>
<p><b>Be sure to note that <a href="#change">change</a> returns the series position just past the modification.</b></p>
<p>This allows you to cascade multiple changes.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">test: "abcde"
change change test "1" "23"
probe test
"123de"</code></pre></div>
<p>So, you must use <a href="#head">head</a> if you need the string at its starting position:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe head change "bog" "d"
"dog"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe head change [1 4 5] [1 2 3]
[1 2 3]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe head change [123 "test"] "the"
["the" "test"]</code></pre></div>
<h6 id="section-3">Partial changes</h6>
<p>The /PART refinement changes a specified number of elements within the target series.</p>
<p>In this line, the 2 indicates that the "ab" are both replaced with the new string, "123":</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe head change/part "abcde" "123" 2
"123cde"</code></pre></div>
<h6 id="section-4">Duplication</h6>
<div class="example-code"><pre class="code-block"><code class="rebol">probe head change/dup "abc" "-&gt;" 5
"-&gt;-&gt;-&gt;-&gt;-&gt;"</code></pre></div>
<p class="need">Editor note: This section is new or has has recently changed and is still under construction.<p>
<div class="example-code"><pre class="code-block"><code class="rebol">title: copy "how it REBOL"
change title "N"
probe title
"Now it REBOL"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">change find title "t" "s"
probe title
"Now is REBOL"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: copy ["now" 12:34 "REBOL"]
change next blk "is"
probe blk
["now" "is" "REBOL"]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe head change/only [1 4 5] [1 2 3]
[[1 2 3] 4 5]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe head change/only [1 4 5] [[1 2 3]]
[[[1 2 3]] 4 5]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">string: copy "crush those grapes"
change/part string "eat" find/tail string "crush"
probe string
"eat those grapes"</code></pre></div>

```
------------------------------------------------------------------
## CHANGE-DIR
[[ make-dir what-dir list-dir ]]

```html

<p>Changes the value of system/script/path. This value is used for file-related operations. Any file path that does not begin with a slash (/) will be relative to the path in system/script/path. When a script file is executed using the <a href="#do">do</a> native, the path will automatically be set to the directory containing the path. When REBOL starts, it is set to the current directory where REBOL is started.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">current: what-dir
make-dir %./rebol-temp/
probe current
%/C/REBOL/3.0/docs/scripts/</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">change-dir %./rebol-temp/
probe what-dir
%/C/REBOL/3.0/docs/scripts/rebol-temp/</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">change-dir current
delete %./rebol-temp/
probe what-dir
%/C/REBOL/3.0/docs/scripts/</code></pre></div>
<p>Note that the shorter shell friendly <a href="#cd">cd</a> also exists.</p>

```
------------------------------------------------------------------
## CHAR?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print char? #"1"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print char? 1
false</code></pre></div>

```
------------------------------------------------------------------
## CHARSET
[[ complement char? ]]

```html

<p>The <a href="#charset">charset</a> function is a shortcut for:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">make bitset! value</code></pre></div>
<p>It is used often for character based bitsets.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">chars: charset "aeiou"
print find chars "o"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print find "there you go" chars
ere you go</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">digits: charset "0123456789"
area-code: ["(" 3 digits ")"]
phone-num: [3 digits "-" 4 digits]
print parse "(707)467-8000" [[area-code | none] phone-num]
true</code></pre></div>

```
------------------------------------------------------------------
## CHECK
------------------------------------------------------------------
## CHECKSUM
[[ string? any-string? ]]

```html

<p>Generally, a checksum is a number which accompanies data to verify that the data has not changed (did not have 
errors).</p>
<p class="need">Editor note: R3 does not yet allow string! for checksums.<p>
<div class="example-code"><pre class="code-block"><code class="rebol">print checksum "now is the dawning"

print checksum "how is the dawning"</code></pre></div>
<p>The /secure refinement creates a binary string result that is cryptographically secure:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print checksum/secure "fred-key"

print checksum/secure form now</code></pre></div>
<p>The /tcp refinement is used to compute the standard TCP networking checksum. This is a weak but fast checksum method.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print checksum/tcp "now is the dawning"

print checksum/tcp "how is the dawning"</code></pre></div>

```
------------------------------------------------------------------
## CLEAN-PATH
[[ split-path change-dir dir? list-dir ]]

```html

<p>Rebuilds a directory path after decoding parent (..) and
current (.) path indicators.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe clean-path %com/www/../../../graphics/image.jpg
%/C/REBOL/3.0/docs/graphics/image.jpg</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">messy-path: %/rebol/scripts/neat-stuff/../../experiments/./tests
neat-path: clean-path messy-path
probe neat-path
%/rebol/experiments/tests</code></pre></div>
<p>URLs are returned unmodified (because the true paths may not
be known).</p>

```
------------------------------------------------------------------
## CLEAR
[[ remove append change insert sort ]]

```html

<p><a href="#clear">clear</a> is similar to <a href="#remove">remove</a> but removes through the end of the series rather than just a single value. It returns at the current index position in the series.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: copy "with all things considered"
clear skip str 8
print str
with all</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: copy "get there quickly"
clear find str "qui"
print str
get there</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">head clear find %file.txt %.txt
%file</code></pre></div>

```
------------------------------------------------------------------
## CLEAR-THRU
------------------------------------------------------------------
## CLOS
------------------------------------------------------------------
## CLOSE
[[ open load do ]]

```html

<p>Closes a port opened earlier with the <a href="#open">open</a> function. Any changes to the port data that have been buffered will be written.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">port: open %test-file.txt
insert port "Date: "
insert port form now
insert port newline
close port

print read %test-file.txt
read</code></pre></div>

```
------------------------------------------------------------------
## CLOSURE
[[ closure? does func function has ]]

```html

<p>A closure is a special type of function that has persistent variables.</p>
<p>With a closure you can write a block inside the closure body and the block will remain persistent:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">add2: closure [c d] [[c + d]]
do add2 1 2
3</code></pre></div>
<p>This works because the variables of a closure remain valid, even outside the closure after it has been called. Such variables have indefinite extent. They are not limited to the lifetime of the function.</p>
<p>Note, however, that this luxury provided by closures is not without its costs. Closures require more time to evaluate as well as more memory space.</p>
<p>In essence a closure is an object. When you define the closure, it constructs a prototype object, and each time you call the closure, the prototype object is instantiated and the body code is evaluated within that context.</p>
<p>More about closures <a href="http://www.rebol.net/wiki/Closures">here</a>.</p>
<p>More about the benefits and costs of closures <a href="http://www.rebol.net/wiki/R2_vs._R3_Contexts">here</a>.</p>

```
------------------------------------------------------------------
## CLOSURE?
[[ function? ]]

```html

<p>Returns true if the input is a <span class="datatype">closure!</span></p>
<div class="example-code"><pre class="code-block"><code class="rebol">closure? make closure! [[][]]
true</code></pre></div>
<p class="need">Editor note: Are there better examples?<p>

```
------------------------------------------------------------------
## COLLECT

```html

<p>Using the internal keep function, will collect values spread around a block to be stored in another block and returned:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">collect [keep 1 2 3 keep 4]
[1 4]</code></pre></div>
<p>Can also be used with the <a href="#parse">parse</a> function:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">collect [
    parse [a b c d e] [
        any ['c | 'e | set w word! (keep w)]
    ]
]
[a b d]</code></pre></div>
<p>Blocks are collected and appended to the output as a series of values:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">collect [keep 1 keep [2 3]]
[1 2 3]</code></pre></div>
<p>The keep function has a refinement /only to append blocks as blocks to the output:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">collect [keep 1 keep/only [2 3]]
[1 [2 3]]</code></pre></div>

```
------------------------------------------------------------------
## COLLECT-WORDS
------------------------------------------------------------------
## COLOR-DISTANCE
------------------------------------------------------------------
## COMBINE
------------------------------------------------------------------
## COMMAND?
------------------------------------------------------------------
## COMMENT
[[ do ]]

```html

<p>This function can be used to add comments to a script or to remove a block from evaluation. Note that this function is only effective in evaluated code and has no effect in data blocks. That is, within a data block comments will appear as data. In many cases, using <a href="#comment">comment</a> is not necessary. Placing braces around any expression will prevent if from being evaluated (so long as it is not part of another expression).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">comment "This is a comment."

comment [print "As a comment, this is not printed"]</code></pre></div>
<p>Note also that if the expression can't be loaded using <a href="#load">load</a>, the expression can't be commented out:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">comment [a,b]
** Syntax error: invalid "word" -- "a,b"
** Near: (line 1) comment [a,b]</code></pre></div>

```
------------------------------------------------------------------
## COMPLEMENT
[[ negate not and or xor charset ]]

```html

<p>The <a href="#complement">complement</a> function is used for bit-masking <span class="datatype">integer!</span> and <span class="datatype">tuple!</span> values or inverting <span class="datatype">bitset!</span> values (charsets).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">complement 0
-1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">complement -1
0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">complement 0.255.0
255.0.255</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">chars: complement charset "ther "
find "there it goes" chars
it goes</code></pre></div>

```
------------------------------------------------------------------
## COMPLEMENT?
------------------------------------------------------------------
## COMPOSE
[[ reduce append repend rejoin insert ]]

```html

<p>The <a href="#compose">compose</a> function builds a block of values, evaluating <span class="datatype">paren!</span> expressions and inserting their results. It is a very useful method of building new blocks.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">compose [result of 1 + 2 = (1 + 2)]
[result of 1 + 2 = 3]</code></pre></div>
<p>Notice that only the <span class="datatype">paren!</span> expression is evaluated. All other values are left unchanged.</p>
<p>Here's another example, as might be used to create a header block (that has field names):</p>
<div class="example-code"><pre class="code-block"><code class="rebol">compose [time: (now/time) date: (now/date)]
[time: 17:47:13 date: 12-Feb-2009]</code></pre></div>
<h6 id="section-2">Sub-Blocks</h6>
<p>If the result of an expression is a block, then the elements of that block are inserted into the output block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">colors: ["red" "green" "blue"]
compose [1 2 3 (colors)]
[1 2 3 "red" "green" "blue"]</code></pre></div>
<p>If you want to insert the actual block, rather than its elements, there are a couple ways to do so. You can use the /only refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">colors: ["red" "green" "blue"]
compose/only [1 2 3 (colors)]
[1 2 3 ["red" "green" "blue"]]</code></pre></div>
<p>Or, you can add a <a href="#reduce">reduce</a> to put the block within another block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">colors: ["red" "green" "blue"]
compose [1 2 3 (reduce [colors])]
[1 2 3 ["red" "green" "blue"]]</code></pre></div>
<h6 id="section-3">Evaluating All Parens</h6>
<p>To evaluate all paren expressions, regardless of how deep the are nested within blocks, use the /deep refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">compose/deep [1 [2 [(1 + 2) 4]]]
[1 [2 [3 4]]]</code></pre></div>
<p>You can use /deep and /only together:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">colors: ["red" "green" "blue"]
compose [1 2 3 [4 (colors)]]
[1 2 3 [4 "red" "green" "blue"]]</code></pre></div>
<h6 id="section-4">Memory usage for large blocks</h6>
<p>For most blocks you don't need to worry about memory because REBOL's automatic storage manager will efficiently handle it; however, when building large block series with <a href="#compose">compose</a>, you can manage memory even more carefully.</p>
<p>For example, you might write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">append series compose [a (b) (c)]</code></pre></div>
<p>The word a and the evaluated results of b and c are appended to the series.</p>
<p>If this is done a lot, a large number of temporary series are generated, which take memory and also must be garbage collected later.</p>
<p>The /into refinement helps optimize the situation:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">compose/into [a (b) (c)] tail series</code></pre></div>
<p>It requires no intermediate storage.</p>

```
------------------------------------------------------------------
## COMPRESS
[[ decompress ]]

```html

<p class="need">Editor note: Describe the method that compress uses to compress data<p>
<div class="example-code"><pre class="code-block"><code class="rebol">print compress "now is the dawning"
#{789CCBCB2F57C82C5628C9485548492CCFCBCC4B07003EB606BA12000000}</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">string: form first system/words
print length? string
8329</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">small: compress string
print length? small
3947</code></pre></div>
<p>As with all compressed files, keep an uncompressed copy of the original data file as a backup.</p>

```
------------------------------------------------------------------
## CONFIRM
[[ ask input prin ]]

```html

<p>This function provides a method of prompting the user for a true ("y" or "yes") or false ("n" or "no") response. Alternate responses can be identified with the /with refinement.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">confirm "Answer: 14. Y or N? "

confirm/with "Use A or B? " ["A" "B"]</code></pre></div>

```
------------------------------------------------------------------
## CONSTRUCT
[[ make context ]]

```html

<p>This function creates new objects but without evaluating the object's specification (as is done in the <a href="#make">make</a> and <a href="#context">context</a> functions).</p>
<p>When you <a href="#construct">construct</a> an object, only literal types are accepted. Functional evaluation is not performed. This allows your code to directly import objects (such as those sent from unsafe external sources such as email, cgi, etc.) without concern that they may include "hidden" side effects using executable code.</p>
<p><a href="#construct">construct</a> is used in the same way as the <a href="#context">context</a> function:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">obj: construct [
    name: "Fred"
    age: 27
    city: "Ukiah"
]
probe obj
make object! [
    name: "Fred"
    age: 27
    city: "Ukiah"
]</code></pre></div>
<p>But, very limited evaluation takes place.  That means object specifications like:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">obj: construct [
    name: uppercase "Fred"
    age: 20 + 7
    time: now
]
probe obj
make object! [
    name: 'uppercase
    age: 20
    time: 'now
]</code></pre></div>
<p>do not produce evaluated results.</p>
<p>Except with the /only refinement, the <a href="#construct">construct</a> function does perform evaluation on the words true, on, yes, false, off, no and none to produce their expected values. Literal words and paths will also be evaluated to produce their respective words and paths.  For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">obj: construct [
    a: yes
    b: none
    c: 'word
]
probe obj
make object! [
    a: true
    b: none
    c: word
]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">type? obj/a
logic!</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">type? obj/c
word!</code></pre></div>
<p>The <a href="#construct">construct</a> function is useful for importing external objects, such as preference settings from a file, CGI query responses, encoded email, etc.</p>
<p>To provide a template object that contains default variable values (similar to <a href="#make">make</a>), use the /with refinement. The example below would use an existing object called standard-prefs as the template.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">prefs: construct/with load %prefs.r standard-prefs</code></pre></div>

```
------------------------------------------------------------------
## CONTEXT
[[ make ]]

```html

<p>This function creates a unique new object. It is just a shortcut for <a href="#make">make</a> <span class="datatype">object!</span>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">person: context [
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
]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">person2: make person [
    name "Bob"
]
probe person2
make object! [
    name: "Bob"
    age: 24
    birthday: 20-Jan-1986
    language: "REBOL"
]</code></pre></div>

```
------------------------------------------------------------------
## CONTEXT?
------------------------------------------------------------------
## CONTINUE
[[ break catch exit return loop repeat for forall foreach forever forskip while until ]]

```html

<p>The <a href="#continue">continue</a> function is the opposite of <a href="#break">break</a>. It jumps back to the top of the loop instead of exiting the loop.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">repeat n 5 [
    if n &lt; 3 [continue]
    print n
]
3
4
5</code></pre></div>

```
------------------------------------------------------------------
## COPY
[[ make form mold join ajoin rejoin ]]

```html

<p>The <a href="#copy">copy</a> function will copy any <a href="/r3/docs/concepts/series.html" class="con">series</a>, such as <span class="datatype">string!</span> or <span class="datatype">block!</span>, and most other compound datatypes such as <span class="datatype">object!</span> or <span class="datatype">function!</span>. It is not used for immediate datatypes, such as <span class="datatype">integer!</span>, <span class="datatype">decimal!</span>, <span class="datatype">time!</span>, <span class="datatype">date!</span>, and others.</p>
<fieldset class="fset"><legend>How it Works</legend>
<p>It is important to understand <a href="#copy">copy</a> to program in REBOL properly.</p>
<p>To save memory, all strings, blocks, and other <a href="/r3/docs/concepts/series.html" class="con">series</a> are accessed by reference (e.g. as pointers.) If you need to modify a series, and you do not want it to change in other locations, you must use <a href="#copy">copy</a> first.</p>
<p>Note that some functions, such as <a href="#join">join</a> and <a href="#rejoin">rejoin</a>, will copy automatically. That's because they are constructing new values.</p>
</fieldset>
<p>This example shows what happens if you don't copy:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">name: "Tesla"
print name
Tesla</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">name2: name
insert name2 "Nicola "
print name2
Nicola Tesla</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print name
Nicola Tesla</code></pre></div>
<p>That's because, it's the same string:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">same? name name2
true</code></pre></div>
<p>Here's the example using <a href="#copy">copy</a> for the second string:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">name: "Tesla"
print name
Tesla</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">name2: copy name
insert name2 "Nicola "
print name2
Nicola Tesla</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print name
Tesla</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">same? name name2
false</code></pre></div>
<p>The same behavior is also true for blocks. This example shows various results:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">block1: [1 2 3]
block2: block1
block3: copy block1
append block1 4
append block2 5
append block4 6
probe block1
[1 2 3 4 5]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe block2
[1 2 3 4 5]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe block3
[1 2 3 6]</code></pre></div>
<p>There will be times in your code where you'll want to <a href="#append">append</a> to or <a href="#insert">insert</a> in a string or other series. You will need to think about what result you desire.</p>
<p>Compare this example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str1: "Nicola"
str2: append str1 " Tesla"
print str1
Nicola Tesla</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print str2
Nicola Tesla</code></pre></div>
<p>with this example that uses the <a href="#copy">copy</a> function:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str1: "Nicola"
str2: append copy str1 " Tesla"
print str1
Nicola</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print str2
Nicola Tesla</code></pre></div>
<h6 id="section-2">Copy Part</h6>
<p>It is fairly common to copy just a sub-string or sub-block. To do so, use the /part refinement. The length of the result is determined by an integer size or by the ending position location.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">name: "Nicola Tesla"
copy/part name 6
"Nicola"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">copy/part skip name 7 5
"Tesla"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">copy/part find name "Tesla" tail name
"Tesla"</code></pre></div>
<p>Notice that the ending position can be a length or a position within the string (as shown by the <a href="#tail">tail</a> example above.)</p>
<h7 id="section-3">About Substrings</h7>
<p>If you use other languages, you will notice that this result is similar to what a substr function provides. Although we recommend using <a href="#copy">copy</a> with /part, you can easily define your own substr function this way:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">substr: func [arg [series!] start length] [
    copy/part skip arg start length
]</code></pre></div>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">substr "string example" 7 7
"example"</code></pre></div>
<p>We should explain why we don't normally define a substr function. Most of the time when you're extracting substrings, you are either using a function like <a href="#find">find</a> or you're using a loop of some kind. Therefore, you don't really care about the starting offset of a string, you only care about the current location.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "This is an example string."
str2: copy/part find str "ex" 7</code></pre></div>
<p>And, in fact, it's common to write use two <a href="#find">find</a> functions in this way:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">start: find str "ex"
end: find start "le"
str2: copy/part start end</code></pre></div>
<p>which advanced users often write in one line this way:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str2: copy/part s: find str "ex" find s "le"</code></pre></div>
<p>Of course, if the string might not be found, this is a helpful pattern to use:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str2: all [
    start: find str "ex"
    end: find start "le"
    copy/part start end
]</code></pre></div>
<p>If the start or end are not found, then str2 is set to none.</p>
<p>Here's an example of a simple loop that finds substrings:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "this example is an example"
pat: "example"
while [str: find str pat] [
    print copy/part str length? pat
    str: skip str length? pat
]</code></pre></div>
<h6 id="section-4">Copy Deep</h6>
<p>When copying blocks, keep in mind that simple use of the <a href="#copy">copy</a> function does not make copies of series values within a block.</p>
<p>Notice that the <a href="#copy">copy</a> here does not copy the name string:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">person1: ["Tesla" 10-July-1856 Serbian]
person2: copy person1
insert person/2 "Nicola "
probe person1
["Nicola Tesla" 10-July-1856 Serbian]</code></pre></div>
<p>If you need to copy both the block and all series values within it, use <a href="#copy">copy</a> with the /deep refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">person1: ["Tesla" 10-July-1856 Serbian]
person2: copy/deep person1
insert person/2 "Nicola "
probe person1
["Tesla" 10-July-1856 Serbian]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe person2
["Nicola Tesla" 10-July-1856 Serbian]</code></pre></div>
<p>Here both the block and the string are separate series.</p>
<p>Also be aware that if your block contains other blocks, they will be deep copied as well, including all strings and other series within them.</p>
<p>If you want to deep copy only a specific datatype, such as just strings or just blocks, you can use the /types refinement.</p>
<p>Here are a few examples of its usage:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">copy/deep/types block string!
copy/deep/types block any-string!
copy/deep/types block make typeset! [string! url! file!]</code></pre></div>
<h6 id="section-5">Copy Objects</h6>
<p>If you use <a href="#copy">copy</a> on an object, a copy of the object is returned. This can be useful when objects are used only as simple storage structures. Note that rebinding is not done; therefore, do not use <a href="#copy">copy</a> on objects when that is required.</p>
<h6 id="section-6">Helpful Hint</h6>
<p>To see a list of functions that modify their series (not copy), type this line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">? modifies
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
...</code></pre></div>

```
------------------------------------------------------------------
## COS
------------------------------------------------------------------
## COSINE
[[ arccosine arcsine arctangent sine tangent ]]

```html

<p>Ratio between the length of the adjacent side to
the length of the hypotenuse of a right triangle.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print cosine 90
0.0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print (cosine 45) = (sine 45)
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print cosine/radians pi
-1.0</code></pre></div>

```
------------------------------------------------------------------
## CREATE

```html

<p>Creates the file or URL object that is specified.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">create %testfile.txt
read %./
[%testfile.txt]</code></pre></div>

```
------------------------------------------------------------------
## CURSOR

```html

<p>This only works in a View window.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">cursor 1
cursor 2
cursor 3
cursor 4
cursor 5
cursor 6</code></pre></div>
<p class="need">Editor note: Describe all cursors here<p>

```
------------------------------------------------------------------
## DATATYPE?

```html

<p>Returns false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print datatype? integer!
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print datatype? 1234
false</code></pre></div>

```
------------------------------------------------------------------
## DATE?
[[ type? ]]

```html

<p>Returns false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print date? 1/3/69
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print date? 12:39
false</code></pre></div>

```
------------------------------------------------------------------
## DEBASE
[[ enbase dehex ]]

```html

<p>Converts from an encoded string to the binary value. Primarily used for BASE-64 decoding.</p>
<p>The /base refinement allows selection of number base as 64, 16, 2. Default is base64.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe debase "MTIzNA=="
#{31323334}</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe debase/base "12AB C456" 16
#{12ABC456}</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">enbased: probe enbase "a string of text"
"YSBzdHJpbmcgb2YgdGV4dA=="</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe string? enbased         ; enbased value is a string
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">debased: probe debase enbased ; converts to binary value

probe to-string debased       ; converts back to original string</code></pre></div>
<p>If the input value cannot be decoded (such as when missing the proper number of characters), a none is returned.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe debase "100"

probe debase "1001"
#{D74D35}</code></pre></div>

```
------------------------------------------------------------------
## DECIMAL?
[[ number? type? ]]

```html

<p>Returns false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print decimal? 1.2
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print decimal? 1
false</code></pre></div>

```
------------------------------------------------------------------
## DECLOAK
[[ encloak ]]

```html

<p><a href="#decloak">decloak</a> is a low strength decryption method that is used with <a href="#encloak">encloak</a>. See the <a href="#encloak">encloak</a> function for a complete description and examples.</p>

```
------------------------------------------------------------------
## DECODE
[[ encode load enbase debase ]]

```html

<p>Used to call codecs to decode binary data (bytes) into related datatypes.</p>
<p>Codecs are identified by words that symbolize their types. For example the word png is used to identify the PNG codec.</p>
<p>See the system/codecs for a list of loaded codecs. Codecs can be native (built-in), externally loaded, or even coded in REBOL.</p>
<p><a href="http://www.rebol.net/cgi-bin/r3blog.r?view=0184" class="lnk">More about Encode and Decode</a></p>
<h6 id="section-2">Examples</h6>
<p>The line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">image: load %photo.jpg</code></pre></div>
<p>is roughly equivalent to:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: read %photo.jpg  ; returns binary data
image: decode 'jpeg data</code></pre></div>

```
------------------------------------------------------------------
## DECODE-URL

```html

<p>This is a handy function that saves you the effort of writing
your own URL parser.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe decode-url http://user:pass@www.rebol.com/file.txt
[scheme: 'http pass: "pass" user: "user" host: "www.rebol.com" path: "/file.txt"]</code></pre></div>

```
------------------------------------------------------------------
## DECOMPRESS
[[ compress enbase debase ]]

```html

<p>Examples:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">write %file.txt read http://www.rebol.net
size? %file.txt
5539</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">save %file.comp compress read %file.txt
size? %file.comp
2119</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">write %file.decomp decompress load %file.comp
size? %file.decomp
5539</code></pre></div>
<p>If the data passed to the <a href="#decompress">decompress</a> function has been altered or corrupted, a decompression error will occur.</p>
<p>A typical error is out of memory, if the decompressed file length appears to be wrong (perhaps several gigabytes instead of 5539 bytes) to <a href="#decompress">decompress</a>.</p>
<p>Using the /limit refinement, puts a hard limit to the size of the decompressed file:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">decompress/limit read %file.comp 5000
** Script error: maximum limit reached: 5539
** Where: decompress
** Near: decompress/limit read %file.comp 5000</code></pre></div>
<p>This can help avoiding that a decompress operation on a corrupt file suddenly eats all system resources.</p>
<h6 id="section-2">Special Notes</h6>
<p><a href="#decompress">decompress</a> can decompress any ZLIB data as long as the data has the length of the uncompressed data in binary little-endian representation appended:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">zlib-decompress: func [
    zlib-data [binary!]
    length [integer!] "known uncompressed zlib data length"
][
    decompress head insert tail zlib-data third make struct! [value [integer!]] reduce [length]
]</code></pre></div>

```
------------------------------------------------------------------
## DEDUPLICATE
------------------------------------------------------------------
## DEFAULT
[[ value? any all ]]

```html

<p>The <a href="#default">default</a> function is a clear way to indicate that you want a variable set to a default value if it's not already been set.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">default size 100</code></pre></div>
<p>would set size to 100 if it's not already been set to some other value.</p>
<p>You can think of <a href="#default">default</a> as a shortcut for <a href="#any">any</a> when used like this:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">size: any [size 100]</code></pre></div>
<p>However, <a href="#default">default</a> avoids the need to specify the size word twice and also makes the intention of your code more clear. It's quite often used for global configuration variables that may or may not have been set by prior code.</p>

```
------------------------------------------------------------------
## DEHEX
[[ to-hex debase enbase ]]

```html

<p>Converts the standard URL hex sequence that begins with a % followed by a valid hex value. Otherwise, the sequence  is not converted and will appear as written.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print dehex "www.com/a%20dir/file"
www.com/a dir/file</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print dehex "ABCD%45"
ABCDE</code></pre></div>

```
------------------------------------------------------------------
## DELECT
[[ parse ]]

```html

<p>DELECT stands for DEcode diaLECT. It is used to implement REBOL's internal dialects such as DRAW, EFFECT, RICH TEXT, SECURE, and VID, but its function is available to all users.</p>
<p>This is used for parsing unordered dialects. In unordered dialects, the order of arguments is less important than their type.</p>
<p>Here's a simple example. First the dialect is specified as a context:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">dialect: context [
    default: [tuple!]
    single: [string!]
    double: [integer! string!]
]</code></pre></div>
<p>Then an input and output block is specified. The input block contains the data to parse. The output block stores the result:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">inp: [1.2.3 single "test" double "test" 123]
out: make block! 4  ; (any initial size works)</code></pre></div>
<p>Now the input is processed using <a href="#delect">delect</a>, one step at a time:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">while [inp: delect dialect inp out] [
  ?? out
  ?? inp
]</code></pre></div>
<p>To read more about <a href="#delect">delect</a>, see <a href="http://rebol.net/wiki/Delect">here</a>.</p>

```
------------------------------------------------------------------
## DELETE
[[ create exists? ]]

```html

<p>Deletes the file or URL object that is specified. If the file or URL refers to an empty directory, then the directory will be deleted.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">write %delete-test.r "This file is no longer needed."
delete %delete-test.r
write</code></pre></div>

```
------------------------------------------------------------------
## DELETE-DIR
------------------------------------------------------------------
## DELETE-THRU
------------------------------------------------------------------
## DELINE
[[ enline read ]]

```html

<p>Useful for converting OS dependent string terminators to LF.</p>
<p>CRLF string termination:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">deline "a^M^/b" ; Windows, DOS, CP/M, OS/2, Symbian
"a^/b"</code></pre></div>
<p>CR string termination:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">deline "a^Mb" ; MacOS 1-9
"a^/b"</code></pre></div>
<p>LF string termination:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">deline "a^/b" ; MacOSX, AmigaOS, FreeBSD, GNU/Linux, BeOS, RiscOS
"a^/b"</code></pre></div>
<p>When using the /LINES refinement, the string will be split in blocks of strings per line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">deline/lines "a^M^/b"
[
    "a"
    "b"
]</code></pre></div>
<p>Note that when reading from disk, READ/STRING provides the same functionality. The file %/c/text.txt was first saved with WIndows XP Notepad, which gives CRLF. When read, it gives:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">read/string %/c/text.txt
"Windows text^/file"</code></pre></div>

```
------------------------------------------------------------------
## DELTA-PROFILE
[[ delta-time dp dt ]]

```html

<p>Provides detailed profiling information captured during the evaluation of a block.</p>
<p>See <a href="http://www.rebol.net/wiki/Profiler" class="lnk">Profiler</a> for detailed examples.</p>
<p>Simple example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; dp [loop 10 [next "a"]]
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
]</code></pre></div>

```
------------------------------------------------------------------
## DELTA-TIME
[[ delta-profile dt dp ]]

```html

<p>Returns the amount of time required to evaluate a given block.</p>
<p>Example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; dt [loop 1000000 [next "a"]]
0:00:00.25</code></pre></div>
<p>See <a href="http://www.rebol.net/wiki/Profiler" class="lnk">Profiler</a> for detailed information about timing and profiling.</p>

```
------------------------------------------------------------------
## DETAB
[[ entab ]]

```html

<p>The REBOL language default tab size is four spaces. <a href="#detab">detab</a> will remove tabs from the entire string even beyond the first non-space character.</p>
<p>The series passed to this function is modified as a result.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">text: "^-lots^-^-of^-^-tabs^-^-^-^-here"
print detab copy text
    lots        of      tabs                here</code></pre></div>
<p>Use the /size refinement for other sizes such as eight:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print detab/size text 8
        lots            of              tabs                            here</code></pre></div>

```
------------------------------------------------------------------
## DH
------------------------------------------------------------------
## DH-INIT
------------------------------------------------------------------
## DIFFERENCE
[[ intersect union exclude unique ]]

```html

<p>Returns the elements of two series that are not present in both. Both series arguments must be of the same datatype (string, block, etc.) Newer versions of REBOL also let you use <a href="#difference">difference</a> to compute the difference between date/times.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">lunch: [ham cheese bread carrot]
dinner: [ham salad carrot rice]
probe difference lunch dinner
[cheese bread salad rice]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe difference [1 3 2 4] [3 5 4 6]
[1 2 5 6]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">string1: "CBAD"    ; A B C D scrambled
string2: "EDCF"    ; C D E F scrambled
probe difference string1 string2
"BAEF"</code></pre></div>
<p>Date differences produce a time in hours:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe difference 1-Jan-2002/0:00 1-Feb-2002/0:00
-744:00</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe difference 1-Jan-2003/10:30 now
-59449:55:14</code></pre></div>
<p>This is different from when using <a href="#subtract">subtract</a>, which returns the difference in days:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe subtract 1-Jan-2002/0:00 1-Feb-2002/0:00
-31</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe subtract 1-Jan-2003/10:30 now
-2477</code></pre></div>
<p>There is a limit to the time period that can be differenced between dates (determined by the internal size of the <span class="datatype">time!</span> datatype).</p>
<p>Note that performing this function over very large data sets can be CPU intensive.</p>

```
------------------------------------------------------------------
## DIR
------------------------------------------------------------------
## DIR?
[[ make-dir modified? exists? ]]

```html

<fieldset class="fset"><legend>Under Review</legend>
<p>This function is under review for redefinition.</p>
</fieldset>
<p>Returns false if it is not a directory.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print dir? %file.txt
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print dir? %.
true</code></pre></div>
<p>Note that the file that is input, is read from disk, if it exists. The function returns true, when the input either ends in / or if the name exists on disk as a directory.</p>

```
------------------------------------------------------------------
## DIR-TREE
------------------------------------------------------------------
## DIRIZE

```html

<p>Convert a file name to a directory name.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe dirize %dir
%dir/</code></pre></div>
<p>It is useful in cases where paths are used:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">dir: %files/examples
new-dir: dirize dir/new-code
probe new-dir
%files/examples/new-code/</code></pre></div>
<p>This is useful because the PATH notation does not allow you to write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">new-dir: dirize dir/new-code/</code></pre></div>

```
------------------------------------------------------------------
## DIVIDE
[[ / // multiply ]]

```html

<p>If the second value is zero, an error will occur.</p>
<p>Examples:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print divide 123.1 12
10.25833333333333</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print divide 10:00 4
2:30</code></pre></div>
<p>When dividing values of different datatypes, they must be compatible:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">divide 4x5 $2.7
** Script error: incompatible argument for divide of pair!
** Where: divide
** Near: divide 4x5 $2.7</code></pre></div>

```
------------------------------------------------------------------
## DO
[[ reduce load import loop repeat call launch ]]

```html

<p>The <a href="#do">do</a> function evaluates a script file or a series of expressions and returns a result.</p>
<p>It performs the fundamental interpretive action of the REBOL language and is used internally within many other functions such as <a href="#if">if</a>, <a href="#case">case</a>, <a href="#while">while</a>, <a href="#loop">loop</a>, <a href="#repeat">repeat</a>, <a href="#foreach">foreach</a>, and others.</p>
<h6 id="section-2">Most Common Use</h6>
<p>Most of the time <a href="#do">do</a> is used to evaluate a script from a <span class="datatype">file!</span> or <span class="datatype">url!</span> as shown in these examples:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do %setup.r
Settings done.</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">do http://www.rebol.com/speed.r
Console:   0:00:01.609 - 314 KC/S
Processor: 0:00:00.406 - 2128 RHz (REBOL-Hertz)
Memory:    0:00:00.657 - 72 MB/S
Disk/File: 0:00:00.234 - 130 MB/S</code></pre></div>
<p>Note that <a href="#do">do</a> of a <span class="datatype">file!</span> or <span class="datatype">url!</span> requires that the script contain a valid REBOL header; otherwise, you'll get an "Script is missing a REBOL header" error.</p>
<fieldset class="fset"><legend>Warning</legend>
<p>Only <a href="#do">do</a> a <span class="datatype">url!</span> script that you have reason to trust. It is advised that you <a href="#read">read</a> a script first and examine it closely to make sure it is safe to evaluate.</p>
</fieldset>
<h6 id="section-3">Other Uses</h6>
<p>The <a href="#do">do</a> function can also be called to evaluate other types of arguments such as a <span class="datatype">block!</span>, <span class="datatype">path!</span>, <span class="datatype">string!</span>, or <span class="datatype">function!</span>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do [1 + 2]
3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">do "1 + 2"  ; see special note below
3</code></pre></div>
<p>Expressions are evaluated left to right and the final result is returned. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do [1 + 2 3 * 4]
12</code></pre></div>
<p>To obtain all results, use the <a href="#reduce">reduce</a> function instead.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print reduce [1 + 2 3 * 4]
3 12</code></pre></div>
<h6 id="section-4">Other Examples</h6>
<p>Selecting a block to evaluate:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [
    [print "test"]
    [loop 3 [print "loop"]]
]
do first blk
test</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">do second blk
loop
loop
loop</code></pre></div>
<h6 id="section-5">Refinements</h6>
<p>The /args refinement allows you to pass arguments to another script and is used with a file, or URL.  Arguments passed with /args are stored in system/script/args within the context of the loaded script.</p>
<p>The /next refinement returns a block consisting of two elements. The first element is the evaluated return of the first expression encountered. The second element is the original block with the current index placed after  the last evaluated expression.</p>
<h6 id="section-6">Special Notes</h6>
<p>Evaluating strings is much slower than evaluating blocks and values. That's because REBOL is a symbolic language, not a string language. It is considered bad practice to convert values to strings and join them together to pass to <a href="#do">do</a> for evaluation. This can be done directly without strings.</p>
<p>For example, writing code like this is a poor practice:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "1234 + "
code: join str "10"
do code
1244</code></pre></div>
<p>Instead, just use:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [1234 +]
code: join blk 10
do code
1244</code></pre></div>
<p>In other words, you can <a href="#join">join</a> values in blocks just as easily as strings.</p>

```
------------------------------------------------------------------
## DO-CALLBACK
------------------------------------------------------------------
## DO-CODEC
[[ decode encode ]]

```html

<p>This is an internal native function used to call codecs. It is normally called by the <a href="#encode">encode</a> and <a href="#decode">decode</a> functions.</p>
<p>See the system/catalog/codecs for a list of loaded codecs. Codecs can be native (built-in), externally loaded, or coded in REBOL.</p>

```
------------------------------------------------------------------
## DO-COMMANDS
[[ do reduce ]]

```html

<p>High speed <span class="datatype">command!</span> block evaluation for <a href="/r3/docs/concepts/extensions.html" class="con">extensions</a>.</p>
<p>Originally created to evaluate <a href="%r3/docs/view/draw.html" class="lnk">graphics rendering commands</a>, it can be used for any external sequence of commands that require maximum speed (e.g. high speed math processing such as FFTs, image processing, audio processing.)</p>
<h6 id="section-2">Special Evaluation Method</h6>
<p>The greater speed of command blocks is obtained through the use of a special evaluation method:</p>
<ul>
<li>Evaluation is strictly linear. Sub-expressions, control branching, and recursion are not allowed so no stack management is required.</li>
<li>Arguments are already reduced to their final values (or variables that hold those values.)</li>
<li>Special variations of function arguments are not allowed. Only word and 'word forms are allowed.</li>
<li>Arguments must appear in the correct order and no optional arguments are allowed.</li>
<li>Arguments are placed directly within the command argument frame, not on the primary evaluator stack.</li>
</ul>
<h7 id="section-3">Why is it Useful?</h7>
<p>In subsystems like the <a href="%r3/docs/gui/gui" class="lnk">R3 GUI</a>, graphical elements are rendered by generating semi-static <a href="%r3/docs/view/draw.html" class="lnk">draw blocks</a> either during style definition (definition of a button), face instantiation (creating an instance of a button), or face state modification (eg. hovering over a button).</p>
<p>The advantage of the static form of such draw blocks is that they require no further evaluation, hence take no additional memory or CPU time. In fact, the state of the GUI at any specific time is simply a sequence of draw block renderings. Therefore, a fast method of calling draw functions can greatly speed-up the rendering time of the GUI.</p>
<p>For special draw dialects (like the one used in the GUI) where optional or datatype-ordered arguments are allowed, a conversion from the dialect block to the command block is required. However, this conversion was already being performed in order to reduce the run-time overhead of the dialects (to avoid the NxM argument reordering penalty), so no additional overhead is incurred.</p>
<h6 id="section-4">General Form</h6>
<p>The general form is:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do-commands [
    command1 arg11 arg12
    command2 arg21 arg22 arg23
    result: command3 arg31
    ...
]</code></pre></div>
<p>Notice that set-words for results are allowed. In addition, the result of the final command will be returned from the <a href="#do-commands">do-commands</a> function.</p>
<h6 id="section-5">Argument Requirements</h6>
<p>Command blocks are written in a reduced minimal form. They consist of one or more commands followed by their arguments. The arguments must be actual values or variables; sub-expressions and operators are not allowed. If necessary, use <a href="#reduce">reduce</a> with /only or <a href="#compose">compose</a> to preprocess command blocks.</p>
<p>For example, you can write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">line 0x0 100x100
line 100x100 200x200</code></pre></div>
<p>and the command can also be variables:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">line start1 end1
line start2 end2</code></pre></div>
<p>Sub expressions are not allowed:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">line 0x0 base + 10   ; error
line 0x0 add base 10 ; error</code></pre></div>
<p>However, if necessary you can escape to parens for sub-expressions, but it reduces run-time performance:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">line 0x0 (base + 10) ; ok, but slow</code></pre></div>
<h6 id="section-6">Errors</h6>
<p>An error will occur if any value other than a command is found:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">multiply 10 20
** Script error: expected command! not multiply</code></pre></div>
<p>An error will also occur if an argument is not of the correct datatype, or if the block ends before all of its actual arguments are provided.</p>

```
------------------------------------------------------------------
## DO-EVENTS

```html

<p>Process user events in GUI windows.  When this function is called the program becomes event driven. This function does not return until all windows have been closed.</p>

```
------------------------------------------------------------------
## DO-THRU
------------------------------------------------------------------
## DOES
[[ closure exit func function has return use ]]

```html

<p><a href="#does">does</a> provides a shortcut for defining functions that have no arguments or local variables.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">rand10: does [random 10]
print rand10
5</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">this-month: does [now/month]
print this-month
2</code></pre></div>
<p>This function is provided as a coding convenience and it is otherwise identical to using <a href="#func">func</a> or <a href="#function">function</a>.</p>

```
------------------------------------------------------------------
## DP
[[ delta-profile delta-time dt ]]

```html

<p>A shortcut for <a href="#delta-profile">delta-profile</a>.</p>

```
------------------------------------------------------------------
## DS
------------------------------------------------------------------
## DT
[[ delta-time delta-profile dp ]]

```html

<p>A shortcut function for <a href="#delta-time">delta-time</a>.</p>

```
------------------------------------------------------------------
## DUMP

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## DUMP-OBJ
[[ help ? ?? ]]

```html

<p>This function provides an easy way to view the contents of an object. The function is friendly to <a href="#print">print</a>. It is an alternative to <a href="#mold">mold</a> and <a href="#probe">probe</a> which may display too much information for deeply structured objects.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print dump-obj system/intrinsic
do              function! Called for DO on datatypes that require more ...
make-module     function! [ spec [block!] "As [spec-block body-block]" ...
make-port       function! Creates a new port from a scheme specificatio...
parse-url       object!   [digit digits alpha-num scheme-char path-char...
begin           function! Called once boot is complete. Handles argumen...</code></pre></div>

```
------------------------------------------------------------------
## ECDH
------------------------------------------------------------------
## ECDSA
------------------------------------------------------------------
## ECHO
[[ print trace ]]

```html

<p>Write output to a file in addition to the user console. The previous contents of a file will be overwritten. The echo can be stopped with <a href="#echo">echo</a> none or by starting another <a href="#echo">echo</a>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">echo %helloworld.txt
print "Hello World!"
echo none
Hello World!</code></pre></div>

```
------------------------------------------------------------------
## EIGHTH
[[ first second third pick ]]

```html

<p>This is an ordinal.</p>
<p>See the <a href="#first">first</a> function for examples. If no value is found, none is returned.</p>

```
------------------------------------------------------------------
## EITHER
[[ if any all unless case switch pick ]]

```html

<p>The <a href="#either">either</a> function will evaluate one block or the other depending on a condition.</p>
<p>This function provides the same capability as the if-else statements found in other languages. Because REBOL is a functional language, it is not desirable to use the word else within the expression.</p>
<p>Here's an example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">either 2 &gt; 1 [print "greater"] [print "not greater"]
greater</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">either 1 &gt; 2 [print "greater"] [print "not greater"]
not greater</code></pre></div>
<p>The condition can be the result of several expressions within <a href="#any">any</a> or <a href="#and">and</a>, or any other function that produces a result:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">either all [
    time &gt; 10:20
    age &gt; 20
    find users "bob"
] [print "that's true"] [print "that's false"]
that's true</code></pre></div>
<p>In addition, it can be pointed out that the evaluated blocks can be within a variable:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">blk1: [print "that's true"]
blk2: [print "that's false"]
either 2 &gt; 1 blk1 blk2
that's true</code></pre></div>
<h6 id="section-2">Return Value</h6>
<p>The <a href="#either">either</a> function returns the result of the block that it evaluates.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print either 2 &gt; 1 ["greater"] ["not greater"]
greater</code></pre></div>
<h6 id="section-3">Simplification</h6>
<p>The above example is pretty common, but it should be noted that it can be easily refactored:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">either 2 &gt; 1 [print "greater"] [print "not greater"]</code></pre></div>
<p>is better written as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print either 2 &gt; 1 ["greater"] ["not greater"]</code></pre></div>
<p>or even better written as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print pick ["greater" "not greater"] 2 &gt; 1</code></pre></div>
<p>The importance of this is that you're picking from a choice of two strings, and you're doing it here with one less block than the code above it.</p>
<p>Be careful with this last method. The <a href="#pick">pick</a> function only allows true and false, not none. See <a href="#either">either</a> for more details.</p>
<h6 id="section-4">A Common Error</h6>
<p>A common error is to forget to provide the second block to the <a href="#either">either</a> function. This usually happens when you simplify an expression, and forget to change the <a href="#either">either</a> to an <a href="#if">if</a> function.</p>
<p>This is wrong:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">either 2 &gt; 1 [print "greater"]</code></pre></div>
<p>and it may become quite confusing as to why your program isn't working correctly.</p>
<p>You should have written:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if 2 &gt; 1 [print "greater"]</code></pre></div>

```
------------------------------------------------------------------
## ELLIPSIZE
------------------------------------------------------------------
## EMAIL?
[[ type? ]]

```html

<p>Returns false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print email? info@rebol.com
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print email? http://www.REBOL.com
false</code></pre></div>

```
------------------------------------------------------------------
## EMPTY?
[[ tail? none? found? ]]

```html

<p>This is a synonym for <a href="#tail?">tail?</a> The check is made relative to the current location in the series.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print empty? []
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print empty? [1]
false</code></pre></div>
<p>The <a href="#empty?">empty?</a> function is useful for all types of series. For instance, you can use it to check a string returned from the
user:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: ask "Enter name:"
if empty? str [print "Name is required"]</code></pre></div>
<p>It is often used in conjunction with <a href="#trim">trim</a> to remove black spaces from the ends of a string before checking it:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if empty? trim str [print "Name is required"]</code></pre></div>

```
------------------------------------------------------------------
## ENBASE
[[ debase dehex ]]

```html

<p>Converts from a string or binary into an encode string value. Primarily used for BASE-64 encoding.</p>
<p>The /base refinement allows selection of base as 64, 16, 2. Default is base64.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print enbase "Here is a string."
SGVyZSBpcyBhIHN0cmluZy4=</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print enbase/base #{12abcd45} 16
12ABCD45</code></pre></div>
<p>The <a href="#debase">debase</a> function is used to convert the binary back again. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">bin: enbase "This is a string"
print debase bin
#{54686973206973206120737472696E67}</code></pre></div>

```
------------------------------------------------------------------
## ENCLOAK
[[ decloak ]]

```html

<p><a href="#encloak">encloak</a> is a low strength encryption method that can be useful for hiding passwords and other such values. It is not a replacement for AES or Blowfish, but works for noncritical data.</p>
<p><b>Do not use it for top secret information!</b></p>
<p>To cloak a binary string, provide the binary string and a cloaking key to the <a href="#encloak">encloak</a> function:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">bin: encloak #{54686973206973206120737472696E67} "a-key"</code></pre></div>
<p>To cloak a string of characters, convert it using <a href="#to-binary">to-binary</a> :</p>
<div class="example-code"><pre class="code-block"><code class="rebol">bin: encloak to-binary "This is a string" "a-key"</code></pre></div>
<p>The result is an encrypted binary value which can be decloaked with the line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print decloak bin "a-key"</code></pre></div>
<p>The stronger your key, the better the encryption. For important data use a much longer key that is harder to guess. Also, do not forget your key, or it may be difficult or impossible to recover your data.</p>
<p>Now you have a simple way to save out a hidden string, such as a password:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">key: ask "Cloak key? (do not forget it) "
data: to-binary "string to hide"
save %data encloak data key</code></pre></div>
<p>To read the data and decloak it:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">key: ask "Cloak key? "
data: load %data
data: to-string decloak data key</code></pre></div>
<p>Of course you can cloak any kind of data using these functions, even non-character data such as programs, images, sounds, etc. In those cases you do not need the <a href="#to-binary">to-binary</a> conversion shown above.</p>
<p>Note that by default, the cloak functions will hash your key strings into 160 bit SHA1 secure cryptographic hashes. If you have created your own hash key (of any length), you use the /with refinement to provide it.</p>

```
------------------------------------------------------------------
## ENCODE
[[ decode load enbase debase ]]

```html

<p>Used to call codecs to encode datatypes into binary data (bytes).</p>
<p>Codecs are identified by words that symbolize their types. For example the word png is used to identify the PNG codec.</p>
<p>See the system/codecs for a list of loaded codecs. Codecs can be native (built-in), externally loaded, or even coded in REBOL.</p>
<h6 id="section-2">Examples</h6>
<p>The line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">save %photo.bmp image</code></pre></div>
<p>Is roughly equivalent to:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: encode 'bmp image
write %photo.bmp data</code></pre></div>

```
------------------------------------------------------------------
## ENCODING?
------------------------------------------------------------------
## ENHEX
------------------------------------------------------------------
## ENLINE
[[ deline ]]

```html

<p>Basic example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">enline "a^/b"
"a^/M^/b"</code></pre></div>
<p>To convert from any string termination format to, use <a href="#enline">enline</a> after the <a href="#deline">deline</a> function:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">enline deline "a^Mb"
"a^/M^/b"</code></pre></div>
<p>See <a href="#deline">deline</a> for more information about string termination formats.</p>

```
------------------------------------------------------------------
## ENTAB
[[ detab ]]

```html

<p>The REBOL language default tab-size is four spaces. Use the /size refinement for other sizes such as eight. <a href="#entab">entab</a> will only place tabs at the beginning of the line (prior to the first non-space character).</p>
<p>The series passed to this function is modified as a result.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">text: {
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
    sentence}</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe entab copy text
{^-no
   tabs
   in
   this
   sentence}</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print entab copy text
        no
   tabs
   in
   this
   sentence</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe entab/size copy text 2
{^-^-no
^- tabs
^- in
^- this
^- sentence}</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print entab/size copy text 2
     no
  tabs
  in
  this
  sentence</code></pre></div>
<p>The opposite function is <a href="#detab">detab</a> which converts tabs back to spaces:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe entab text
{^-no
   tabs
   in
   this
   sentence}</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe detab text
{    no
    tabs
    in
    this
    sentence}</code></pre></div>

```
------------------------------------------------------------------
## ENUM
------------------------------------------------------------------
## EQUAL?
[[ = <> == =? not-equal? strict-equal? ]]

```html

<p>String-based datatypes are considered equal when they
are identical or differ only by character casing
(uppercase = lowercase). Use <a href="#==">==</a> or find/match/case to
compare strings by casing.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print equal? 123 123
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print equal? "abc" "abc"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print equal? [1 2 3] [1 2 4]
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print equal? 12-june-1998 12-june-1999
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print equal? 1.2.3.4 1.2.3.0
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print equal? 1:23 1:23
true</code></pre></div>

```
------------------------------------------------------------------
## EQUIV?
------------------------------------------------------------------
## ERROR?

```html

<p>Returns false for all other values. This is useful for determining if a <a href="#try">try</a> function returned an error.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if error? try [1 + "x"][
    print "Did not work."
]
Did not work.</code></pre></div>

```
------------------------------------------------------------------
## EVEN?
[[ odd? zero? ]]

```html

<p>Returns true only if the argument is an even integer value. If the argument is a decimal, only its integer portion is
examined.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print even? 100
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print even? 7
false</code></pre></div>

```
------------------------------------------------------------------
## EVENT?

```html

<p>Returns true if the value is an event datatype.</p>

```
------------------------------------------------------------------
## EVOKE

```html

<p>This is useful for analyzing hard REBOL crashes that lead to assertion errors and other crashes that aren't related to your script errors, but directly exposes bugs in the REBOL kernel. This is helpful information for REBOL Technologies to fix these bugs.</p>
<p>To enable this kind of analysis, have this at the beginning of your program:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure [debug allow] 
evoke 'crash-dump</code></pre></div>
<p>If REBOL crashes, you will get a stack dump. You can force a crash using:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">evoke 'crash
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
        chant: crash</code></pre></div>
<h6 id="section-2">Special Notes</h6>
<p>Common for all operations with evoke is that debugging must be allowed using:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure [debug allow]</code></pre></div>
<p><a href="#evoke">evoke</a> also allows other debug output, mostly used internally by REBOL Technologies to help test REBOL 3.</p>
<p>The function can also be used to monitor the garbage collector:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">evoke 'watch-recycle</code></pre></div>
<p>or to monitor object copying:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">evoke 'watch-obj-copy</code></pre></div>
<p>or to set the stack size:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">evoke 'stack-size 2000000</code></pre></div>
<p>or to debug <a href="#delect">delect</a> information:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">evoke 'delect</code></pre></div>

```
------------------------------------------------------------------
## EXCLUDE
[[ difference intersect union unique ]]

```html

<p>Returns the elements of the first set less the elements
of the second set. In other words, it removes from the
first set all elements that are part of the second set.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">lunch: [ham cheese bread carrot]
dinner: [ham salad carrot rice]
probe exclude lunch dinner
[cheese bread]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe exclude [1 3 2 4] [3 5 4 6]
[1 2]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">string1: "CBAD"    ; A B C D scrambled
string2: "EDCF"    ; C D E F scrambled
probe exclude string1 string2
"BA"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">items: [1 1 2 3 2 4 5 1 2]
probe exclude items items  ; get unique set
[]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "abcacbaabcca"
probe exclude str str
""</code></pre></div>
<p>Note that performing this function over very large
data sets can be CPU intensive.</p>

```
------------------------------------------------------------------
## EXISTS?
[[ read write delete modified? size? ]]

```html

<p>Returns false if the file does not exist.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print exists? %file.txt
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print exists? %doc.r
false</code></pre></div>

```
------------------------------------------------------------------
## EXISTS-THRU?
------------------------------------------------------------------
## EXIT
[[ return catch break ]]

```html

<p><a href="#exit">exit</a> is used to return from a function without returning a value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">test-str: make function! [str] [
    if not string? str [exit]
    print str
]
test-str 10
test-str "right"</code></pre></div>
<p>Note: Use <a href="#quit">quit</a> to exit the interpreter.</p>

```
------------------------------------------------------------------
## EXP
[[ log-10 log-2 log-e power ]]

```html

<p>The <a href="#exp">exp</a> function returns the exponential value of the argument provided.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print exp 3
20.08553692318766</code></pre></div>
<p>On overflow, an error is returned (which can be trapped with the <a href="#try">try</a> function). On underflow, a 0 is returned.</p>

```
------------------------------------------------------------------
## EXTEND
[[ context ]]

```html

<p>This function is useful to extend <span class="datatype">object!</span>, <span class="datatype">map!</span> or <span class="datatype">block!</span> values using a word/value pair. It returns the input value. It performs no copy.</p>
<p>Examples:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">a: [b: 1 c: 2]
extend a 'd 3
= 3
probe a
[b: 1 c: 2 d: 3]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">a: make object! [b: 1 c: 2]
extend a 'd 3
3
probe a
make object! [
    b: 1
    c: 2
    d: 3
]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">a: make map! [b: 1 c: 2]
extend a 'd 3
3
probe a
make map! [
    b: 1
    c: 2
    d: 3
]</code></pre></div>

```
------------------------------------------------------------------
## EXTRACT

```html

<p>Returns a series of values from regularly spaced positions within a specified series. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: ["Dog" 10 "Cat" 15 "Fish" 20]
probe extract data 2
["Dog" "Cat" "Fish"]</code></pre></div>
<p>Essentially, <a href="#extract">extract</a> lets you access a series as a record or "row" of a given length (specified by the width argument). The default, as shown above, extracts the first value. If you wanted to extract the second value (the second "column" of data):</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: ["Dog" 10 "Cat" 15 "Fish" 20]
probe extract/index data 2 2
[10 15 20]</code></pre></div>
<p>In the example below, the width of each row is three:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">people: [
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
]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">block: extract/index people 3 2
probe block
["Bob" "Cat" "Ted"]</code></pre></div>
<p>Of course, <a href="#extract">extract</a> works on any <a href="/r3/docs/concepts/series.html" class="con">series</a>, not just those that appear in a row format (such as that above). The example below creates a block containing every other word from a string:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "This is a given block here"
blk: parse str none
probe blk
["This" "is" "a" "given" "block" "here"]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe extract blk 2
["This" "a" "block"]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe extract/index blk 2 2
["is" "given" "here"]</code></pre></div>
<p>Here is an example that uses <a href="#extract">extract</a> to obtain the names of all the predefined REBOL/View VID styles:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe extract system/view/vid/vid-styles 2</code></pre></div>

```
------------------------------------------------------------------
## FIFTH
[[ pick first second third fourth ]]

```html

<p>This is an ordinal.</p>
<p>See the <a href="#first">first</a> function for examples. If no value is found, none is returned.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print fifth "REBOL"
L</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print fifth [11 22 33 44 55 66]
55</code></pre></div>

```
------------------------------------------------------------------
## FILE-CHECKSUM
------------------------------------------------------------------
## FILE?
[[ type? ]]

```html

<p>Returns false for all other values. Note that <a href="#file?">file?</a> does not check for the existence of a file, but whether or not a value is the FILE! datatype.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print file? %file.txt
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print file? "REBOL"
false</code></pre></div>
<p>Note also this is not a direct opposite to the <a href="#dir?">dir?</a> function as <a href="#dir?">dir?</a> does not test against a datatype, where <a href="#file?">file?</a> does.</p>

```
------------------------------------------------------------------
## FILE-TYPE?
------------------------------------------------------------------
## FILTER
------------------------------------------------------------------
## FIND
[[ select pick ]]

```html

<p>Returns <span class="datatype">none!</span> if the value was not found. Otherwise, returns a position in the series where the value was found. Many refinements to this function are available.</p>
<h7 id="section-2">Refinements</h7>
<p>Use /tail to return the position just past the match.</p>
<p>Use /case to specify that the search should be case sensitive. Note that using <a href="#find">find</a> on a binary string will do a case-insensitive search.</p>
<p>The /match refinement can be used to perform a character by character match of the input value to the series. The position just past the match is returned.</p>
<p>Wildcards can be specified with /any.</p>
<p>The /only refinement applies to block values and is ignored for strings.</p>
<p>The /last refinement causes <a href="#find">find</a> to search from the tail of the series toward the head.</p>
<p>And, /reverse searches backwards from the current position toward the head.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe find "here and now" "and"
"and now"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe find/tail "here and now" "and"
" now"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe find [12:30 123 c@d.com] 123
[123 c@d.com]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe find [1 2 3 4] 5
none</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe find/match "here and now" "here"
" and now"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe find/match "now and here" "here"
none</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe find [1 2 3 4 3 2 1] 2
[2 3 4 3 2 1]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe find/last %file.fred.txt "."
%.txt</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe find/last [1 2 3 4 3 2 1] 2
[2 1]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe find/any "here is a string" "s?r"
none</code></pre></div>

```
------------------------------------------------------------------
## FIND-ALL
------------------------------------------------------------------
## FIND-MAX
------------------------------------------------------------------
## FIND-MIN
------------------------------------------------------------------
## FIND-SCRIPT

```html

<p>This is a high-speed lower level function to scan UTF-8 for a REBOL script signature, useful during loading of scripts and to ensure that scripts are proper UTF-8.</p>
<p class="need">Editor note: Not sure about the description<p>

```
------------------------------------------------------------------
## FIRST
[[ pick second third fourth fifth ]]

```html

<p>This is an ordinal. It returns the first value in any type of <a href="/r3/docs/concepts/series.html" class="con">series</a> at the current position. If no value is found, none is returned.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print first "REBOL"
R</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print first [11 22 33 44 55 66]
11</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print first 1:30
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print first 199.4.80.1
199</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print first 12:34:56.78
12</code></pre></div>

```
------------------------------------------------------------------
## FIRST+

```html

<p>Example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [a b c]
first+ blk
a</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">first+ blk
b</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">first+ blk
c</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">first+ blk
none</code></pre></div>

```
------------------------------------------------------------------
## FLUSH
------------------------------------------------------------------
## FOR
[[ loop repeat forall foreach forever forskip map-each remove-each ]]

```html

<p>The first argument is used as a local variable to keep track of the current value. It is initially set to the START value and after each evaluation of the block the BUMP value is added to it until the END value is reached (inclusive).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">for num 0 30 10 [ print num ]
30</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">for num 4 -37 -15 [ print num ]
-26</code></pre></div>

```
------------------------------------------------------------------
## FORALL
[[ for foreach forskip forever while until ]]

```html

<p>The <a href="#forall">forall</a> function moves through a series one value at a time.</p>
<p>The word argument is a variable that moves through the series. Prior to evaluation, the word argument must be set to the desired starting position within the series (normally the head, but any position is valid). After each evaluation of the block, the word will be advanced to the next position within the series.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">cities: ["Eureka" "Ukiah" "Santa Rosa" "Mendocino"]
forall cities [print first cities]
Eureka
Ukiah
Santa Rosa
Mendocino</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">chars: "abcdef"
forall chars [print first chars]
a
b
c
d
e
f</code></pre></div>
<p>When <a href="#forall">forall</a> finishes the word is reset to the starting position of the series.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">chars: next "abcdef"
"bcdef"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">forall chars []
chars
"bcdef"</code></pre></div>
<p>The result of <a href="#forall">forall</a> is the result of the last expression of the block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">chars: "abcdef"
forall chars [first chars]
#"f"</code></pre></div>
<p>Or the result of a break/return from the block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">chars: "abcdef"
forall chars [break/return 5]
5</code></pre></div>
<p>The <a href="#forall">forall</a> function can be thought of as a shortcut for:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">[
    original: series
    while [not tail? series] [
        x: (your code)
        series: next series
    ]
    series: original
    :x
]</code></pre></div>

```
------------------------------------------------------------------
## FOREACH
[[ remove-each map-each for forall forskip repeat ]]

```html

<p>The <a href="#foreach">foreach</a> function repeats the evaluation of a block for each element of a series. It is used often in programs.</p>
<p>Example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">values: [11 22 33]
foreach value values [print value]
11
22
33</code></pre></div>
<p>Another example that prints each word in a block along with its value:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">colors: [red green blue]
foreach color colors [print [color get color]]
red 255.0.0
green 0.255.0
blue 0.0.255</code></pre></div>
<p>If the series is a string, each character will be fetched:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">string: "REBOL"
foreach char string [print char]
R
E
B
O
L</code></pre></div>
<p>This example will print each filename from a directory block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">files: read %.
foreach file files [
    if find file ".t" [print file]
]
file.txt
file2.txt
newfile.txt
output.txt</code></pre></div>
<fieldset class="fset"><legend>Local Variables</legend>
<p>The variables used to hold the <a href="#foreach">foreach</a> values are local to the block. Their value are only set within the block that is being repeated. Once the loop has exited, the variables return to their previously set values.</p>
</fieldset>
<h6 id="section-2">Multiple Elements</h6>
<p>When a block contains groups of values that are related, <a href="#foreach">foreach</a> function can fetch all elements at the same time. For example, here is a block that contains a time, string, and price. By providing the <a href="#foreach">foreach</a> function with a block of words for the group, each of their values can be fetched and printed.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">movies: [
     8:30 "Contact"      $4.95
    10:15 "Ghostbusters" $3.25
    12:45 "Matrix"       $4.25
]

foreach [time title price] movies [
    print ["watch" title "at" time "for" price]
]
watch Contact at 8:30 for $4.95
watch Ghostbusters at 10:15 for $3.25
watch Matrix at 12:45 for $4.25</code></pre></div>
<p>In the above example, the <a href="#foreach">foreach</a> value block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">[time title price]</code></pre></div>
<p>specifies that three values are to be fetched from movies for each evaluation of the block.</p>
<h6 id="section-3">Series Reference</h6>
<p>To reference the series itself during <a href="#foreach">foreach</a> you can use a <span class="datatype">set-word!</span> within the variable block. This operation is similar to the <a href="#forall">forall</a> and <a href="#forskip">forskip</a> functions.</p>
<p>Example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">foreach [v1: v2] [1 2 3] [?? [v1 v2]]
v1: [1 2 3] v2: 1
v1: [2 3] v2: 2
v1: [3] v2: 3</code></pre></div>
<p>Notice that the v1 set-word does not affect the index position.</p>
<p>If you are using this option to remove values, please see the <a href="#remove-each">remove-each</a> function which is many times faster for large series.</p>
<h6 id="section-4">Foreach of Objects and Maps</h6>
<p>The <a href="#foreach">foreach</a> function can also be used with <span class="datatype">object!</span> and <span class="datatype">map!</span> datatypes.</p>
<p>When using a single word argument, <a href="#foreach">foreach</a> will obtain the object field name or map key.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">fruits: make object! [apple: 10 orange: 12 banana: 30]
foreach field fruits [print field]
apple
orange
banana</code></pre></div>
<p>Note that each word is bound back to the object, and can be used to access the field value with <a href="#get">get</a> and <a href="#set">set</a>.</p>
<p>If a second word argument is provided, it will obtain the value of each entry:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">foreach [field value] fruits [print [field value]]
apple 10
orange 12
banana 30</code></pre></div>
<p>The same behavior applies to the <span class="datatype">map!</span> datatype, except that empty keys (those set to none) will be skipped.</p>
<p>When a <span class="datatype">set-word!</span> is used in the variables block, it will obtain the object value itself.</p>

```
------------------------------------------------------------------
## FOREVER
[[ loop repeat for while until ]]

```html

<p>Evaluates a block continuously, or until a break or error condition is met.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">forever [
    if (random 10) &gt; 5 [break]
]</code></pre></div>

```
------------------------------------------------------------------
## FORM
[[ print reform mold remold ajoin join rejoin ]]

```html

<p>The <a href="#form">form</a> function converts a value to a human readable string. It is commonly used by <a href="#print">print</a> for output.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">form 1234
"1234"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">form 10:30
"10:30"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">form %image.jpg
"image.jpg"</code></pre></div>
<p>When given a block of values, spaces are inserted between each values (except after a newline).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">form [1 2 3]
"1 2 3"</code></pre></div>
<p>To avoid the spaces between values use <a href="#ajoin">ajoin</a>, <a href="#join">join</a>, or <a href="#rejoin">rejoin</a>.</p>
<p>The <a href="#reform">reform</a> function combines <a href="#reduce">reduce</a> with <a href="#form">form</a> to evaluate values:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">reform [1 + 2 3 + 4]
"3 7"</code></pre></div>
<p>To produce REBOL-readable output, use the <a href="#mold">mold</a> function.</p>

```
------------------------------------------------------------------
## FORM-OID
------------------------------------------------------------------
## FORMAT

```html

<p>This is useful for table output in the console, where fixed-width fonts are used. It can also be used to specially format numbers or complex values.</p>
<p>The first input, is the dialect. It's a combination of positive or negative formatting integers and strings or chars, that are to be inserted between the integers.</p>
<p>A positive integer N, means the value will be left adjusted with N chars for space.</p>
<p>A negative integer N, means the value will be right adjusted with N chars for space.</p>
<p>In both cases, a value that takes up more space than N, is truncated to N chars.</p>
<p>The second input is the values, either as a block or as a single value.</p>
<p>Example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">format [-3 -3 -4] [1 2 3]
"  1  2   3"</code></pre></div>
<p>Format a time value using /pad to add zeroes:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">format/pad [-2 ":" -2 ":" -2] [12 47 9] 0
"12:47:09"</code></pre></div>
<p>It can also be used to pad zeroes to a single numeric value:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">format/pad [-8] 5125 0
"00005125"</code></pre></div>

```
------------------------------------------------------------------
## FORMAT-DATE-TIME
------------------------------------------------------------------
## FORMAT-TIME
------------------------------------------------------------------
## FORSKIP
[[ for forall foreach skip ]]

```html

<p>Prior to evaluation, the word must be set to the desired starting position within the series (normally the head, but any position is valid). After each evaluation of the block, the word's position in the series is changed by skipping the number of values specified by the second argument (see the <a href="#skip">skip</a> function).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">areacodes: [
    "Ukiah"         707
    "San Francisco" 415
    "Sacramento"    916
]
forskip areacodes 2 [
    print [ first areacodes "area code is" second areacodes]
]
Sacramento area code is 916</code></pre></div>

```
------------------------------------------------------------------
## FOURTH
[[ first second third fifth pick ]]

```html

<p>This is an ordinal.</p>
<p>See the <a href="#first">first</a> function for examples. If no value is found, none is returned.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print fourth "REBOL"
O</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print fourth [11 22 33 44 55 66]
44</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print fourth 199.4.80.1
1</code></pre></div>

```
------------------------------------------------------------------
## FRACTION
------------------------------------------------------------------
## FRAME?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## FUNC
[[ closure does has funco funct function use make function? return exit ]]

```html

<p>The <a href="#func">func</a> function creates new functions from a spec block and a body block.</p>
<p>General form:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">name: func [spec] [body]</code></pre></div>
<p>The spec block specifies the interface to the function. It can begin with an optional title string which used by the <a href="#help">help</a> function. That is followed by words that specify the arguments to the function. Each of argument can include an optional block of datatypes to specify the valid datatypes for the argument. Each may be followed by a comment string which describes the argument in more detail.</p>
<p>The argument words may also specify a few variations on the way the argument will be evaluated. The most common is 'word which indicates that a word is expected that should not be evaluated (the function wants its name, not its value). A :word may also be given which will get the value of the argument, but not perform full evaluation.</p>
<p>To add refinements to a function supply a slash (/) in front of an argument's word. Within the function the refinement can be tested to determine if the refinement was present. If a refinement is followed by more arguments, they will be associated with that refinement and are only evaluated when the refinement is present.</p>
<p>Local variables are specified after a /local refinement.</p>
<p>A function returns the last expression it evaluated. You can also use <a href="#return">return</a> and <a href="#exit">exit</a> to exit the function. A <a href="#return">return</a> is given a value to return. <a href="#exit">exit</a> returns no value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">sum: func [a b] [a + b]
print sum 123 321
444</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">sum: func [nums [block!] /average /local total] [
    total: 0
    foreach num nums [total: total + num]
    either average [total / (length? nums)][total]
]
print sum [123 321 456 800]
print sum/average [123 321 456 800]
425</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print-word: func ['word] [print form word]
print-word testing
testing</code></pre></div>

```
------------------------------------------------------------------
## FUNCO
[[ closure does has func funct function use make function? return exit ]]

```html

<p>Similar to <a href="#func">func</a>, except the spec or body is not copied.</p>

```
------------------------------------------------------------------
## FUNCT

```html

<p>This is similar to <a href="#func">func</a>, except all set-words are assumed locals. This way, it's not necessary to specify the /local part of the spec, although you still can.</p>
<p>Example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">f: funct [a] [
    b: a
]
f 7
7</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">b
** Script error: b has no value</code></pre></div>
<p>If you still desire to create non-local values in the function, use <a href="#set">set</a> to set words:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">f: funct [a] [
    b: a
    set 'c b / 2
]
f 7
3.5</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">c
3.5</code></pre></div>
<p>If c still needs to be local, you can add the local refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">unset 'c ; make sure it's not set
f: funct [a /local c] [
    b: a
    set 'c b / 2
]
f 7
3.5</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">c
** Script error: c has no value</code></pre></div>

```
------------------------------------------------------------------
## FUNCTION
[[ func does has make use function? return exit ]]

```html

<fieldset class="fset"><legend>Warning!</legend>
<p>The descripton of <a href="#function">function</a> given below is up-to-date, however the spec shown above is not current. <a href="#function">function</a> was <a href="http://www.rebol.com/article/0543.html" class="lnk">recently adapted</a> from a 3-argument to a 2-argument variant.</p>
</fieldset>
<p>This is similar to <a href="#func">func</a>, except all set-words are assumed locals. This way, it's not necessary to specify the /local part of the spec, although you still can.</p>
<p>Example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">average: function [block] [
    total: 0
    foreach number block [total: number + total]
    total / (length? block)
]
print average [1 10 12.34]
7.78</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">total
** Script error: total has no value</code></pre></div>
<p>If you still desire to create non-local values in the function, use <a href="#set">set</a> to set words:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">f: function [a] [
    b: a
    set 'c b / 2
]
f 7
3.5</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">c
3.5</code></pre></div>
<p>If c still needs to be local, you can add the local refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">unset 'c ; make sure it's not set
f: function [a /local c] [
    b: a
    set 'c b / 2
]
f 7
3.5</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">c
** Script error: c has no value</code></pre></div>

```
------------------------------------------------------------------
## FUNCTION?
[[ any-function? type? ]]

```html

<p>Returns false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print function? :func
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print function? "test"
false</code></pre></div>

```
------------------------------------------------------------------
## GCD
------------------------------------------------------------------
## GENERATE
------------------------------------------------------------------
## GET
[[ set value? in ]]

```html

<p>The argument to <a href="#get">get</a> must be a word, so the argument must be quoted or extracted from a block. To get the value of a word residing in an object, use the <a href="#in">in</a> function.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">value: 123
print get 'value
123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print get second [the value here]
123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print get in system/console 'prompt
&gt;&gt;</code></pre></div>
<p>If the argument to <a href="#get">get</a> is an object, the result is the same as that of <a href="#values-of">values-of</a>.</p>

```
------------------------------------------------------------------
## GET-ENV
[[ list-env ]]

```html

<p>This function will return the string associated with an OS environment variable.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe get-env "COMPUTERNAME"
"BIGBOY"</code></pre></div>
<p>To obtain a list of all environment variables and their values, use <a href="#list-env">list-env</a>.</p>

```
------------------------------------------------------------------
## GET-PATH?
[[ path? set-path? lit-path? ]]

```html

<p>Returns false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">get-path? to-get-path 'path/to/somewhere
true</code></pre></div>

```
------------------------------------------------------------------
## GET-WORD?
[[ word? set-word? lit-word? ]]

```html

<p>Returns false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print get-word? second [pr: :print]
true</code></pre></div>

```
------------------------------------------------------------------
## GOB?

```html

<p>Returns false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">gob? make gob! [text: "this is a gob!"]
true</code></pre></div>

```
------------------------------------------------------------------
## GREATER-OR-EQUAL?
[[ >= < <= > = <> equal? lesser-or-equal? min max not-equal? ]]

```html

<p>Returns false for all other values. Both values must be of the same datatype or an error will occur. For string-based datatypes, the sorting order is used for comparison with character casing ignored (uppercase = lowercase).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print greater-or-equal? "abc" "abb"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print greater-or-equal? 16-June-1999 12-june-1999
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print greater-or-equal? 1.2.3.4 4.3.2.1
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print greater-or-equal? 1:00 11:00
false</code></pre></div>

```
------------------------------------------------------------------
## GREATER?
[[ > < <= >= = <> lesser? min max ]]

```html

<p>Returns false for all other values. The values must be of the same datatype or an error will occur. For string-based datatypes, the sorting order is used for comparison with character casing ignored (uppercase = lowercase).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print greater? "abc" "abb"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print greater? 16-June-1999 12-june-1999
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print greater? 4.3.2.1 1.2.3.4
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print greater? 11:00 12:00
false</code></pre></div>

```
------------------------------------------------------------------
## GUI-METRIC
------------------------------------------------------------------
## HALT
[[ quit break exit catch ]]

```html

<p>Useful for program debugging.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">div: 10
if error? try [100 / div] [
    print "math error"
    halt
]</code></pre></div>

```
------------------------------------------------------------------
## HANDLE-EVENTS

```html

<p>This is used internally in the <a href="#view">view</a> function.</p>

```
------------------------------------------------------------------
## HANDLE?

```html

<p>Returns false for all other values.</p>
<p class="need">Editor note: Need example.<p>

```
------------------------------------------------------------------
## HANDLED-EVENTS?
------------------------------------------------------------------
## HAS
[[ func function does exit return use ]]

```html

<p>Defines a function that consists of local variables only. This is a shortcut for <a href="#func">func</a> and <a href="#function">function</a>.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">ask-name: has [name] [
    name: ask "What is your name?"
    print ["Hello" name]
]

ask-name
Hello Luke</code></pre></div>
<p>The example above is a shortcut for:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">ask-name: func [/local name] [...]</code></pre></div>

```
------------------------------------------------------------------
## HASH
------------------------------------------------------------------
## HASH?
------------------------------------------------------------------
## HEAD
[[ head? tail tail? ]]

```html

<p>The insert function returns at the current string position, so <a href="#head">head</a> adjusts the index back to the head:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "all things"
print head insert str "with "
with all things</code></pre></div>
<p>Now here is not at the head:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">here: find str "all"
print here
all things</code></pre></div>
<p>Now we print at the head:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print head here
with all things</code></pre></div>

```
------------------------------------------------------------------
## HEAD?
[[ head tail tail? ]]

```html

<div class="example-code"><pre class="code-block"><code class="rebol">cds: [
    "Rockin' REBOLs"
    "Carl's Addiction"
    "Jumpin' Jim"
]
print head? cds
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">cds: tail cds
print head? cds
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">until [
    cds: back cds
    print first cds
    head? cds
]
Rockin' REBOLs</code></pre></div>

```
------------------------------------------------------------------
## HELP
[[ ? what ?? docs ]]

```html

<p>The <a href="#help">help</a> function provides information about words and values.</p>
<p>Type <a href="#help">help</a> or <a href="#?">?</a> at the console prompt to view a summary of help:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; help
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
    usage - view program options</code></pre></div>
<h6 id="section-2">Help about a Function</h6>
<p>If you provide a function word as an argument, <a href="#help">help</a> prints all of the information related to that function.</p>
<p>For instance, if you type:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; help insert</code></pre></div>
<p>you will see:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">USAGE:
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
         count (number! pair!)</code></pre></div>
<p>For more detailed information, you can use the doc refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; help/doc insert</code></pre></div>
<p>to open the web browser to the page related to that function.</p>
<h6 id="section-3">Help about Datatypes</h6>
<p>All datatypes are explained through help.</p>
<p>To obtain a list of all REBOL datatypes, type:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; ? datatype!

Found these related words:
    action!         datatype! datatype native function (standard polymorphic)
    binary!         datatype! string series of bytes
    bitset!         datatype! set of bit flags
    block!          datatype! series of values
    char!           datatype! 8bit and 16bit character
    ...</code></pre></div>
<p>For help on a specific datatype:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">help integer!
integer! is a datatype
It is defined as a 64 bit integer
It is of the general type scalar
Found these related words:
   zero            integer!  0</code></pre></div>
<p>To list all words that are function! datatypes, type:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; ? function!</code></pre></div>
<p>and the result would be:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">Found these related words:
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
    ...</code></pre></div>
<h6 id="section-4">Help Search</h6>
<p>The <a href="#help">help</a> function also finds words that contain a specified string. For example, to find all of the words that include the string <span class="datatype">path!</span>, type:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; ? "path"</code></pre></div>
<p>and the result will be:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">Found these related words:
    ??              function! Debug print a word, path, or block of such, f...
    any-path!       typeset!  [path! set-path! get-path! lit-path!]
    any-path?       function! Return TRUE if value is any type of path.
    assert          native!   Assert that condition is true, else throw an ...
    cd              function! Change directory (shell shortcut function).
    change-dir      native!   Changes the current directory path.
    clean-path      function! Returns new directory path with //, . and .. ...
    dirize          function! Returns a copy of the path turned into a dire...
    file!           datatype! file name or path
    ...</code></pre></div>
<h6 id="section-5">Help on Objects</h6>
<p>If you use <a href="#help">help</a> on an object, it will list a summary of the object's fields.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; ? system
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
    ...</code></pre></div>
<h6 id="section-6">Help on Errors</h6>
<p>There is a special mechanism for getting help on errors.</p>
<p>When you get an error message at the console, you can type <a href="#why?">why?</a> to see info about that specific error.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; test
** Script error: test has no value

&gt;&gt; why?
Opening web browser...</code></pre></div>
<p>and, this page, <a href="/r3/docs/errors/script-no-value.html" class="err">no-value</a>, would be displayed.</p>
<p>See <a href="#why?">why?</a> for more about this function.</p>

```
------------------------------------------------------------------
## HSV-TO-RGB
------------------------------------------------------------------
## ICONV
------------------------------------------------------------------
## IF
[[ either any all unless switch select ]]

```html

<p>The <a href="#if">if</a> function will evaluate the block when its first argument is true.</p>
<p>True is defined to be any value that is not false or none.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if 2 &gt; 1 [print "that's true"]
that's true</code></pre></div>
<p>The condition can be the result of several expressions within <a href="#any">any</a> or <a href="#and">and</a>, or any other function that produces a result:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if all [
    time &gt; 10:20
    age &gt; 20
    find users "bob"
] [print "that's true"]
that's true</code></pre></div>
<p>In addition, it can be pointed out that the block can be in a variable also:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [print "that's true"]
if 2 &gt; 1 blk
that's true</code></pre></div>
<h6 id="section-2">Return Value</h6>
<p>When the condition is true, the <a href="#if">if</a> function returns the value that is the result of evaluating the block. Otherwise, it returns none. This is a useful feature.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print if 2 &gt; 1 [1 + 2]
3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print if 1 &gt; 2 [1 + 2]
none</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">names: ["Carl" "Brian" "Steve"]
print if find names "Carl" ["Person found"]
Person found</code></pre></div>
<h6 id="section-3">Where's the Else?</h6>
<p>Unlike most other languages, REBOL uses functions, not commands to evaluate all expressions. Therefore, it's not desirable to use the word else if you need that behavior. Instead, use the <a href="#either">either</a> function:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">either 2 &gt; 1 [print "greater"] [print "not greater"]
greater</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">either 1 &gt; 2 [print "greater"] [print "not greater"]
not greater</code></pre></div>
<h6 id="section-4">Simplification</h6>
<p>The above example is pretty common, but it should be noted that it can be easily refactored:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">either 2 &gt; 1 [print "greater"] [print "not greater"]</code></pre></div>
<p>is better written as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print either 2 &gt; 1 ["greater"] ["not greater"]</code></pre></div>
<p>or even better written as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print pick ["greater" "not greater"] 2 &gt; 1</code></pre></div>
<p>The importance of this is that you're picking from a choice of two strings, and you're doing it here with one less block than the code above it.</p>
<p>Be careful with this last method. The <a href="#pick">pick</a> function only allows true and false, not none. See <a href="#either">either</a> for more details.</p>
<p>In addition, it should be noted that the <a href="#any">any</a> function used earlier didn't really require the <a href="#if">if</a> at all. It could have been written as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">all [
    time &gt; 10:20
    age &gt; 20
    find users "bob"
    print "that's true"
]</code></pre></div>
<h6 id="section-5">A Common Error</h6>
<p>A common error is to use <a href="#if">if</a> and add an "else" block without using the <a href="#either">either</a> function. The extra block gets ignored:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">n: 0
if 1 &gt; 2 [n: 1] [n: 2]
print n
0</code></pre></div>
<p>The second block is ignored in this case and not evaluated.</p>
<p>The code should have used the <a href="#either">either</a> function:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">n: 0
either 1 &gt; 2 [n: 1] [n: 2]
print n
2</code></pre></div>
<h6 id="section-6">The /Else refinement is obsolete</h6>
<p>The /Else refinement is obsolete and will be removed in future versions. Avoid it.</p>

```
------------------------------------------------------------------
## IMAGE
------------------------------------------------------------------
## IMAGE-DIFF
------------------------------------------------------------------
## IMAGE?
[[ to-image ]]

```html

<p>Returns true if the value is an <span class="datatype">image!</span> datatype.</p>
<p>This function is often used after the <a href="#load">load</a> function to verify that the data is in fact an image. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">img: load %test-image.png
if not image? img [alert "Not an image file!"]</code></pre></div>

```
------------------------------------------------------------------
## IMPORT
[[ do load ]]

```html

<p>The <a href="#import">import</a> function is used to import modules into your runtime environment. For a full description see the <a href="/r3/docs/concepts/modules-loading.html" class="con">modules: loading modules</a> section of this documentation.</p>
<p>For example, you can write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">import 'mysql</code></pre></div>
<p>and the system will search for the mysql module.</p>
<p>You can also use a filename or URL for the module identifier:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">import %mysql.r

import http://www.rebol.com/mods/mysql.r</code></pre></div>
<h7 id="section-2">Return value</h7>
<p>When successful, the <a href="#import">import</a> function returns a <span class="datatype">module!</span> datatype as its result.</p>
<p>This allows you to write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">mysql: import 'mysql</code></pre></div>
<p>Now, the mysql variable can be used to refer to values within the mysql module.</p>
<p>For example the module value is used here to reference a function:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">mysql/open-db %my-database.sql</code></pre></div>
<p>See below for more.</p>
<h7 id="section-3">Useful refinements</h7>
<p>Like the header needs field, the <a href="#import">import</a> function also lets you specify a version and a checksum.</p>
<p>These are all supported:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">import/version mysql 1.2.3

import/check mysql #{A94A8FE5CCB19BA61C4C0873D391E987982FBBD3}

import/version/check mysql 1.2.3 #{A94A8FE5CCB19BA61C4C0873D391E987982FBBD3}</code></pre></div>
<h7 id="section-4">When to use IMPORT</h7>
<p>The benefit of using the <a href="#import">import</a> function compared to the needs header field is that the arguments can be variables.</p>
<p>A basic example is:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">mod: 'mysql
import mod</code></pre></div>
<p>Or, something like:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">mod-list: [
    mysql 1.2.3
    db-gui 2.4.5
    http-server 1.0.1
]

foreach [id ver] mod-list [
    import/version id ver
]</code></pre></div>

```
------------------------------------------------------------------
## IN
[[ set get ]]

```html

<p>Return the word from within another context. This function is normally used with <a href="#set">set</a> and <a href="#get">get</a>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">set-console: func ['word value] [
    set in system/console word value
]
set-console prompt "==&gt;"
set-console result "--&gt;"</code></pre></div>
<p>This is a useful function for accessing the words and values of an object. The <a href="#in">in</a> function will obtain a word from an object's context. For example, if you create an object:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">example: make object! [ name: "fred" age: 24 ]</code></pre></div>
<p>You can access the object's name and age fields with:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print example/name
print example/age
24</code></pre></div>
<p>But you can also access them with:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print get in example 'name
print get in example 'age
24</code></pre></div>
<p>The <a href="#in">in</a> function returns the name and age words as they are within the example object. If you type:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print in example 'name
name</code></pre></div>
<p>The result will be the word name, but with a value as it exists in the example object. The <a href="#get">get</a> function then fetches their values.  This is the best way to obtain a value from an object, regardless of its datatype (such as in the case of a function).</p>
<p>A <a href="#set">set</a> can also be used:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print set in example 'name "Bob"
Bob</code></pre></div>
<p>Using <a href="#in">in</a>, here is a way to print the values of all the fields of an object:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">foreach word words-of example [
    probe get in example word
]
24</code></pre></div>
<p>Here is another example that sets all the values of an object to none:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">foreach word words-of example [
    set in example word none
]</code></pre></div>
<p>The <a href="#in">in</a> function can also be used to quickly check for the existence of a word within an object:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if in example 'name [print example/name]
none</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">if in example 'address [print example/address]</code></pre></div>
<p>This is useful for objects that have optional variables.</p>
<h6 id="section-2">Advanced binding uses</h6>
<p>In R3, <a href="#in">in</a> can also be used for binding a block to an object to support this useful idiom:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do in example [age + 1]
25</code></pre></div>
<p>Identically, a <span class="datatype">paren!</span> can be used as the rebound block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do in example second [(age + 1) (age + 20)]
44</code></pre></div>

```
------------------------------------------------------------------
## IN-DIR

```html

<p>This is useful if you need to temporarily switch to a different directory to do something, and then switch back without manually doing so.</p>
<p>Example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">in-dir %tmp-dir/ [tmp-files: read %.]</code></pre></div>

```
------------------------------------------------------------------
## INDEX?
[[ length? offset? head head? tail tail? pick skip ]]

```html

<p>The index function returns the position within a series. For
example, the first value in a series is an index of one, the
second is an index of two, etc.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "with all things considered"
print index? str
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print index? find str "things"
10</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [264 "Rebol Dr." "Calpella" CA 95418]
print index? find blk 95418
5</code></pre></div>
<p>Use the OFFSET? function when you need the index difference
between two positions in a series.</p>

```
------------------------------------------------------------------
## INDEXZ?
------------------------------------------------------------------
## INIT-WORDS
------------------------------------------------------------------
## INPUT
[[ ask confirm ]]

```html

<p>Returns a string from the standard input device
(normally the keyboard, but can also be a file or an
interactive shell). The string does not include
the new-line character used to terminate it.</p>
<p>The /HIDE refinement hides input with "*" characters.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">prin "Enter a name: "
name: input
print [name "is" length? name "characters long"]
Luke is 4 characters long</code></pre></div>

```
------------------------------------------------------------------
## INSERT
[[ append change clear remove join ]]

```html

<p>If the value is a series compatible with the first
(block or string-based datatype), then all of its values
will be inserted. The series position just past the
insert is returned, allowing multiple inserts to be
cascaded together.</p>
<h7 id="section-2">Refinements</h7>
<p>/part allows you to specify how many elements you want
to insert.</p>
<p>/only will force a block to be insert, rather than its
individual elements. (Is only done if first argument
is a block datatype.)</p>
<p>/dup will cause the inserted series to be repeated a
given number of times. (Positive integer or zero)</p>
<p>The series will be modified.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: copy "here this"
insert str "now "
print str
now here this</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">insert tail str " message"
print str
now here this message</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">insert tail str reduce [tab now]
print str
now here this message   12-Feb-2009/17:47:52-8:00</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">insert insert str "Tom, " "Tina, "
print str
Tom, Tina, now here this message    12-Feb-2009/17:47:52-8:00</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">insert/dup str "." 7
print str
.......Tom, Tina, now here this message 12-Feb-2009/17:47:52-8:00</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">insert/part tail str next "!?$" 1
print str
.......Tom, Tina, now here this message 12-Feb-2009/17:47:52-8:00?</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: copy ["hello"]
insert blk 'print
probe blk
[print "hello"]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">insert tail blk http://www.rebol.com
probe blk
[print "hello" http://www.rebol.com]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">insert/only blk [separate block]
probe blk
[[separate block] print "hello" http://www.rebol.com]</code></pre></div>

```
------------------------------------------------------------------
## INTEGER?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print integer? -1234
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print integer? "string"
false</code></pre></div>

```
------------------------------------------------------------------
## INTERN
------------------------------------------------------------------
## INTERSECT
[[ difference union exclude unique ]]

```html

<p>Returns all elements within two blocks or series that 
exist in both.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">lunch: [ham cheese bread carrot]
dinner: [ham salad carrot rice]
probe intersect lunch dinner
[ham carrot]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe intersect [1 3 2 4] [3 5 4 6]
[3 4]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">string1: "CBAD"    ; A B C D scrambled
string2: "EDCF"    ; C D E F scrambled
probe intersect string1 string2
"CD"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">items: [1 1 2 3 2 4 5 1 2]
probe intersect items items  ; get unique set
[1 2 3 4 5]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "abcacbaabcca"
probe intersect str str
"abc"</code></pre></div>
<p>To obtain a unique set (to remove duplicate values)
you can use UNIQUE.</p>
<p>Note that performing this function over very large
data sets can be CPU intensive.</p>

```
------------------------------------------------------------------
## INVALID-UTF?
------------------------------------------------------------------
## ISSUE?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print issue? #1234-5678-9012
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print issue? #467-8000
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print issue? $12.56
false</code></pre></div>

```
------------------------------------------------------------------
## JOIN
[[ ajoin rejoin form reform append repend mold remold ]]

```html

<p>Returns a new <a href="/r3/docs/concepts/series.html" class="con">series</a> that joins together a value with another value or block of values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">join "super" "duper"
"superduper"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">join %file ".txt"
%file.txt</code></pre></div>
<p>This differs from <a href="#append">append</a> and <a href="#repend">repend</a> because a new value is created, and the first argument is not modified in any way.</p>
<p>The <b>first argument determines the datatype of the returned value</b>.
When the first argument is a type of <a href="/r3/docs/concepts/series.html" class="con">series</a>, the return value will 
be that type of series (d:string, <span class="datatype">file!</span>, <span class="datatype">url!</span>, <span class="datatype">block!</span>, etc.)</p>
<p>When the first argument is a scalar value (such as <span class="datatype">integer!</span>, <span class="datatype">date!</span>, <span class="datatype">time!</span>, and others), the return  will always be a <span class="datatype">string!</span>.</p>
<p>When the second argument is a <span class="datatype">block!</span>, it will be evaluated and all of its values joined 
to the return value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">join http:// ["www.rebol.com/" %index.html]
http://www.rebol.com/index.html</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">join "t" ["e" "s" "t"]
"test"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">join 11:11 "PM"
"11:11PM"</code></pre></div>
<p>Note that it also works for <span class="datatype">block!</span> series, but returns a block, not a string:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">join [1] ["two" 3 "four"]
[1 "two" 3 "four"]</code></pre></div>
<p>And, this case is important to note:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">join &lt;a&gt; "test"
&lt;atest&gt;</code></pre></div>
<p>(See <a href="#rejoin">rejoin</a> for more detail on this case.)</p>
<p>If you want the result here to be a <span class="datatype">string!</span>, use the <a href="#ajoin">ajoin</a> function instead.</p>

```
------------------------------------------------------------------
## KEYS-OF
------------------------------------------------------------------
## LAST

```html

<p>LAST returns the last value of a series. If the series is empty,
LAST will cause an error.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print last "abcde"
e</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print last [1 2 3 4 5]
5</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print last %file
e</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe last 'system/options
options</code></pre></div>
<p>If you do not want an error when the series is empty, use the 
PICK function instead:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">string: ""
print pick back tail string 1
none</code></pre></div>

```
------------------------------------------------------------------
## LAST?
------------------------------------------------------------------
## LATIN1?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## LAUNCH
[[ call do ]]

```html

<p>The LAUNCH function is used to run REBOL scripts as a separate
process. When LAUNCH is called, a new process is created and
passed the script file name or URL to be processed. The process
is created as a subprocess of the main REBOL process.</p>
<p>Launch has certain restrictions depending on the REBOL system
used. Also, within Unix/Linux systems, launch will use the
same shell standard files as the main REBOL process, and output
will be merged.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">launch %calculator.r

launch http://www.rebol.com/scripts/news.r</code></pre></div>

```
------------------------------------------------------------------
## LCM
------------------------------------------------------------------
## LENGTH?
[[ head tail? offset? ]]

```html

<p>The length? function returns the number of values from the current position of a series to the tail of the series.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print length? "REBOL"
5</code></pre></div>
<p>but, in the case of an offset position from <a href="#skip">skip</a> :</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print length? skip "REBOL" 2
3</code></pre></div>
<p>or from <a href="#find">find</a> :</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print length? find "REBOL" "L"
1</code></pre></div>
<p>Other examples:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print length? [1 2 3 4 5]
5</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print length? [1 2 3 [4 5]]
4</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print length? read http://www.rebol.com
7216</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">obj: object [a: 10 b: 20]
print length? obj
2</code></pre></div>

```
------------------------------------------------------------------
## LESSER-OR-EQUAL?
[[ <= < > >= = <> min max ]]

```html

<p>Returns FALSE for all other values. For string-based
datatypes, the sorting order is used for comparison
with character casing ignored (uppercase = lowercase).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print lesser-or-equal? "abc" "abd"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print lesser-or-equal? 10-June-1999 12-june-1999
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print lesser-or-equal? 4.3.2.1 1.2.3.4
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print lesser-or-equal? 1:23 10:00
true</code></pre></div>

```
------------------------------------------------------------------
## LESSER?
[[ <= > >= = <> min max ]]

```html

<p>Returns FALSE for all other values. The values must be
of the same datatype, or an error will occur. For
string-based datatypes, the sorting order is used for
comparison with character casing ignored (uppercase =
lowercase).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print lesser? "abc" "abcd"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print lesser? 12-june-1999 10-june-1999
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print lesser? 1.2.3.4 4.3.2.1
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print lesser? 1:30 2:00
true</code></pre></div>

```
------------------------------------------------------------------
## LIBRARY?

```html

<p>Returns TRUE if the value is a LIBRARY datatype.</p>

```
------------------------------------------------------------------
## LICENSE
[[ about ]]

```html

<p>Returns the REBOL end user license agreement for the currently
running version of REBOL.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">license</code></pre></div>
<p>For SDK and other specially licensed versions of REBOL, the
license function may return an empty string.</p>

```
------------------------------------------------------------------
## LIMIT-USAGE
------------------------------------------------------------------
## LIST-DIR
[[ change-dir make-dir what-dir read ]]

```html

<p>Lists the files and directories of the specified path in a
sorted multi-column output. If no path is specified, the
directory specified in system/script/path is listed. Directory
names are followed by a slash (/) in the output listing.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">list-dir</code></pre></div>
<p>To obtain a block of files for use by your program, use the LOAD
function. The example below returns a block that contains the names of all
files and directories in the local directory.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">files: load %./
print length? files
probe files
[%autos.txt %build-docs.r %bulk-modify.r %cgi.r %convert-orig.r %CVS/ %emit-html.r %eval-examples.r %fix-args.r %fred/ %funcs.r %helloworld.txt %merge-funcs.r %newfile.txt %notes.txt %public/ %replace.r %scan-doc.r %scan-titles.r %strip-title.r %test-file.txt %trash.me]</code></pre></div>

```
------------------------------------------------------------------
## LIST-ENV
[[ get-env ]]

```html

<p>This function will return a <span class="datatype">map!</span> of OS environment variables and their values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe list-env
make map! [
   "ALLUSERSPROFILE" "C:\Documents and Settings\All Users"
   "APPDATA" "C:\Documents and Settings\Carl\Application Data"
   "CLIENTNAME" "Console"
   "CommonProgramFiles" "C:\Program Files\Common Files"
   ...</code></pre></div>

```
------------------------------------------------------------------
## LIST-THRU
------------------------------------------------------------------
## LIT-PATH?

```html

<p>Returns true if the value is a literal path datatype.</p>

```
------------------------------------------------------------------
## LIT-WORD?
[[ set-word? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe lit-word? first ['foo bar]
true</code></pre></div>

```
------------------------------------------------------------------
## LOAD
[[ save read do import bind ]]

```html

<p>Reads and converts external data, including programs, data
structures, images, and sounds into memory storage objects that
can be directly accessed and manipulated by programs.</p>
<p>The argument to LOAD can be a file, URL, string, or binary
value. When a file name or URL is provided, the data is read
from disk or network first, then it is loaded. In the case of a
string or binary value, it is loaded directly from memory.</p>
<p>Here are a few examples of using LOAD:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">script: load %dict-notes.r
image: load %image.png
sound: load %whoosh.wav

;data: load http://www.rebol.com/example.r
;data: load ftp://ftp.rebol.com/example.r

data: load "1 2 luke fred@example.com"
code: load {loop 10 [print "hello"]}</code></pre></div>
<p>LOAD is often called for a text file that contains REBOL code or
data that needs to be brought into memory. The text is first
searched for a REBOL header, and if a header is found, it is
evaluated first. (However, unlike the DO function, LOAD does not
require that there be a header.)</p>
<p>If the load results in a single value, it will be returned. If
it results in a block, the block will be returned. No evaluation
of the block will be done; however, words in the block will be
bound to the global context.</p>
<p>If the header object is desired, use the /HEADER option to
return it as the first element in the block.</p>
<p>The /ALL refinement is used to load an entire script as a block.
The header is not evaluated.</p>
<p>The /NEXT refinement was removed - use TRANSCODE/NEXT instead</p>

```
------------------------------------------------------------------
## LOAD-EXTENSION
------------------------------------------------------------------
## LOAD-JSON
------------------------------------------------------------------
## LOAD-THRU
------------------------------------------------------------------
## LOG-10
[[ exp log-2 log-e power ]]

```html

<p>The LOG-10 function returns the base-10 logarithm of the number
provided. The argument must be a positive value, otherwise an
error will occur (which can be trapped with the TRY function).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print log-10 100
2.0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print log-10 1000
3.0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print log-10 1234
3.091315159697223</code></pre></div>

```
------------------------------------------------------------------
## LOG-2
[[ exp log-10 log-e power ]]

```html

<p>The LOG-10 function returns the base-2 logarithm of the number
provided. The argument must be a positive value, otherwise an
error will occur (which can be trapped with the TRY function).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print log-2 2
1.0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print log-2 4
2.0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print log-2 256
8.0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print log-2 1234
10.26912667914941</code></pre></div>

```
------------------------------------------------------------------
## LOG-E
[[ exp log-10 log-2 power ]]

```html

<p>The LOG-E function returns the natural logarithm of the number
provided. The argument must be a positive value, otherwise an
error will occur (which can be trapped with the TRY function).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print log-e 1234
7.118016204465333</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print exp log-e 1234
1234.0</code></pre></div>

```
------------------------------------------------------------------
## LOGIC?
[[ type? ]]

```html

<p>Returns FALSE for all other values. Note that all
conditional functions will accept more than just a LOGIC
value. A NONE will act as FALSE, and all other values
other than logic will act as TRUE.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print logic? true
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print logic? 123
false</code></pre></div>

```
------------------------------------------------------------------
## LOOP
[[ repeat for while until do break continue ]]

```html

<p>The <a href="#loop">loop</a> function is the simplest way to repeat the evaluation of a block. This function is very efficient and should be used if no loop counter is required.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">loop 3 [print "hi"]
hi
hi
hi</code></pre></div>
<p>Here's an example that creates a block of 10 random integers:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">block: make block! 10
loop 10 [append block random 100]
probe block
[31 25 53 20 40 2 30 79 47 79]</code></pre></div>
<h6 id="section-2">Returned Value</h6>
<p>When finished the <a href="#loop">loop</a> function returns the final value the block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">num: 0
print loop 10 [num: num + 1]
10</code></pre></div>
<h6 id="section-3">Other Notes</h6>
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

```html

<p>The series passed to this function is modified as
a result.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print lowercase "ABCDEF"
abcdef</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print lowercase/part "ABCDEF" 3
abcDEF</code></pre></div>

```
------------------------------------------------------------------
## LS
[[ cd change-dir delete list-dir make-dir mkdir pwd rm what-dir ]]

```html

<p>Note: Shell shortcut for <a href="#list-dir">list-dir</a>.</p>

```
------------------------------------------------------------------
## MAKE
[[ copy type? ]]

```html

<p>The TYPE argument indicates the datatype to create.</p>
<p>The form of the constructor is determined by the
datatype. For most series datatypes, a number indicates
the size of the initial allocation.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: make string! 1000

blk: make block! 10

cash: make money! 1234.56
print cash
$1234.560000000000000</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">time: make time! [10 30 40]
print time
10:30:40</code></pre></div>
<p>NOTE: MAKE when used with OBJECTS will modify the context of the
spec block (as if BIND was used on it). If you need to reuse the
spec block use MAKE in combination with COPY/deep like this:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">make object! copy/deep spec</code></pre></div>

```
------------------------------------------------------------------
## MAKE-BANNER
------------------------------------------------------------------
## MAKE-DIR
[[ change-dir what-dir list-dir delete ]]

```html

<p>Creates a new directory at the specified location. This
operation can be performed for files or FTP URLs.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">make-dir %New-Dir/
delete %New-Dir/</code></pre></div>

```
------------------------------------------------------------------
## MAP

```html

<p>Description is needed.</p>

```
------------------------------------------------------------------
## MAP-EACH

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## MAP-EVENT

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## MAP-GOB-OFFSET

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## MAP?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## MAX
[[ min maximum-of < > maximum ]]

```html

<p>Returns the maximum of two values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print max 0 100
100</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print max 0 -100
0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print max 4.56 4.2
4.56</code></pre></div>
<p>The maximum value is computed by comparison, so MAX can also be
used for non-numeric datatypes as well.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print max 1.2.3 1.2.8
1.2.8</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print max "abc" "abd"
abd</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print max 12:00 11:00
12:00</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print max 1-Jan-1920 20-Feb-1952
20-Feb-1952</code></pre></div>
<p>Using MAX on xy pairs will return the maximum of each X and Y
coordinate separately.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print max 100x10 200x20
200x20</code></pre></div>

```
------------------------------------------------------------------
## MAXIMUM
[[ max < > min ]]

```html

<p>See the MAX function for details.</p>

```
------------------------------------------------------------------
## MIN
[[ max < > minimum-of maximum-of ]]

```html

<p>Returns the minimum of two values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print min 0 100
0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print min 0 -100
-100</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print min 4.56 4.2
4.2</code></pre></div>
<p>The minimum value is computed by comparison, so MIN can also be
used for non-numeric datatypes as well.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print min 1.2.3 1.2.8
1.2.3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print min "abc" "abd"
abc</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print min 12:00 11:00
11:00</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print min 1-Jan-1920 20-Feb-1952
1-Jan-1920</code></pre></div>
<p>Using min on xy pairs will return the minimum of each X and Y
coordinate separately.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print min 100x10 200x20
100x10</code></pre></div>

```
------------------------------------------------------------------
## MINIMUM
[[ < > min max ]]

```html

<p>See the MIN function for details.</p>

```
------------------------------------------------------------------
## MKDIR
[[ cd change-dir delete list-dir ls make-dir pwd rm what-dir ]]

```html

<p>Note: Shell shortcut for <a href="#make-dir">make-dir</a>.</p>

```
------------------------------------------------------------------
## MOD
[[ modulo // remainder round ]]

```html

<p>Similar to REMAINDER, but the result is always non-negative.</p>

```
------------------------------------------------------------------
## MODIFIED?
[[ exists? ]]

```html

<p>Returns NONE if the file does not exist.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print modified? %file.txt
none</code></pre></div>

```
------------------------------------------------------------------
## MODIFY
------------------------------------------------------------------
## MODULE

```html

<p>Description is needed.</p>

```
------------------------------------------------------------------
## MODULE?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## MODULO
[[ mod // remainder round ]]

```html

<p>See MOD for details.</p>

```
------------------------------------------------------------------
## MOLD
[[ form remold join insert reduce ]]

```html

<p>The <a href="#mold">mold</a> function converts values to a source-code formatted string (REBOL-readable).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print mold 10:30
10:30</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print mold %image.jpg
%image.jpg</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print mold [1 2 3]
[1 2 3]</code></pre></div>
<p>The primary importance of <a href="#mold">mold</a> is to produce strings that can be reloaded with <a href="#load">load</a>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: mold [1 + 2]
probe load str
[1 + 2]</code></pre></div>
<p>The <a href="#mold">mold</a> function is the cousin of <a href="#form">form</a> which produces a human-readable string (used by the <a href="#print">print</a> function.) For example a block will be shown with brackets [ ] and strings will be " " quoted or use braces { } (if it is long or contains special characters).</p>
<p>Also, <a href="#remold">remold</a> first uses <a href="#reduce">reduce</a> then <a href="#mold">mold</a>.</p>
<h6 id="section-2">The /only Refinement</h6>
<p>In some cases it is useful to not <a href="#mold">mold</a> the outermost brackets of blocks. This is done with the /only refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print mold/only [1 2 3]
1 2 3</code></pre></div>
<p>This is commonly true for blocks of values that are saved to files:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">write %example.r mold/only [1 2 3]</code></pre></div>
<p>See the <a href="#save">save</a> function.</p>
<h6 id="section-3">The /all Refinement</h6>
<p>For some values <a href="#mold">mold</a> produces an approximate string value, not a perfect representation. If you attempt to load such a string, its value may be different.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">mold 'true
"true"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">mold true
"true"</code></pre></div>
<p>The first is the word true the second is the <span class="datatype">logic!</span> value true -- they are different but represented by the same word. If you <a href="#load">load</a> the resulting string, you will only obtain the word true not the logic value:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">type? load mold true
word!</code></pre></div>
<p>The /all option provides a more accurate transformation from values to strings and back (using <a href="#load">load</a>.)</p>
<div class="example-code"><pre class="code-block"><code class="rebol">mold/all 'true
"true"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">mold/all true
"#[true]"</code></pre></div>
<p>Using <a href="#load">load</a>, you can see the difference:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">type? load mold/all 'true
word!</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">type? load mold/all true
logic!</code></pre></div>
<p>Another difference occurs with strings that are indexed from their <a href="#head">head</a> positions. Sometimes this is desired, sometimes not. It can be seen here:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">mold next "ABC"
"BC"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">mold/all next "ABC"
{#[string! "ABC" 2]}</code></pre></div>
<h7 id="section-4">Affected Datatypes</h7>
<p>The following datatypes are affected: <span class="datatype">unset!</span>, <span class="datatype">none!</span>, <span class="datatype">logic!</span>, <span class="datatype">bitset!</span>, <span class="datatype">image!</span>, <span class="datatype">map!</span>, <span class="datatype">datatype!</span>, <span class="datatype">typeset!</span>, <span class="datatype">native!</span>, <span class="datatype">action!</span>, <span class="datatype">op!</span>, <span class="datatype">closure!</span>, <span class="datatype">function!</span>, <span class="datatype">object!</span>, <span class="datatype">module!</span>, <span class="datatype">error!</span>, <span class="datatype">task!</span>, <span class="datatype">port!</span>, <span class="datatype">gob!</span>, <span class="datatype">event!</span>, <span class="datatype">handle!</span>.</p>
<fieldset class="fset"><legend>Note on Restoring Semantics</legend>
<p>It should also be noted that some datatypes cannot be returned to a source form without losing semantic information. For example, functions cannot maintain the binding (scoping context) of their words. If such semantics reproduction is required it is recommended that your code output entire blocks that as a whole are evaluated to produce the correct semantic result. This is commonly done in REBOL code, including the common storage of mezzanine and module functions and other definitions.</p>
</fieldset>
<h7 id="section-5">Accuracy of Decimals</h7>
<p>The <span class="datatype">decimal!</span> datatype is implemented as IEEE 754 binary floating point type. When molding <span class="datatype">decimal!</span> values, mold/all will need to use the maximal precision 17 digits to allow for accurate transformation of Rebol decimals to string and back, as opposed to just <a href="#mold">mold</a>, which uses a default precision 15 decimal digits.</p>
<h6 id="section-6">The /flat Refinement</h6>
<p>The /flat refinement is useful for minimizing the size of source strings. It properly removes leading indentation (from code lines, but not multi-line strings.) The /flat option is often used for data exchanged between systems or stored in files.</p>
<p>Here is code often used for saving a script in minimal format (in R3):</p>
<div class="example-code"><pre class="code-block"><code class="rebol">write %output.r mold/only/flat code</code></pre></div>
<p>For code larger than about 1K, you can also compress it:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">write %output.rc compress mold/only/flat code</code></pre></div>
<p>Such a file can be reloaded with:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">load/all decompress read %output.rc</code></pre></div>
<p>Note that if using R2, these lines must be modified to indicate binary format.</p>
<h6 id="section-7">Code Complexity Comparisons</h6>
<p>It should be noted that <a href="#mold">mold</a> function is used for computing the relative complexity of code using the <a href="http://www.rebol.net/wiki/Load_Mold_Sizes" class="lnk">Load Mold Sizing method</a>.</p>

```
------------------------------------------------------------------
## MOLD64
------------------------------------------------------------------
## MONEY?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print money? $123
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print money? 123.45
false</code></pre></div>

```
------------------------------------------------------------------
## MORE

```html

<p>Description is needed.</p>

```
------------------------------------------------------------------
## MOVE

```html

<p>Description is needed.</p>

```
------------------------------------------------------------------
## MULTIPLY
[[ / // divide ]]

```html

<p>The datatype of the second value may be restricted to
INTEGER or DECIMAL, depending on the datatype of the
first value (e.g. the first value is a time).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print multiply 123 10
1230</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print multiply 3:20 3
10:00</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print multiply 0:01 60
1:00</code></pre></div>

```
------------------------------------------------------------------
## NATIVE?
[[ type? ]]

```html

<p>Returns FALSE for all other values. When passing a
function to NATIVE? to be checked, it must be denoted
with ":". This is because the ":word" notation passes a
word's reference, not the word's value. NATIVE? can only
determine whether or not a function is a native if it is
passed the function's reference.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe native? :native?   ; it's actually an ACTION!
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe native? "Vichy"
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe native? :if
true</code></pre></div>

```
------------------------------------------------------------------
## NEGATE
[[ + - positive? negative? complement not ]]

```html

<p>Returns the negative of the value provided.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print negate 123
-123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print negate -123
123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print negate 123.45
-123.45</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print negate -123.45
123.45</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print negate 10:30
-10:30</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print negate 100x20
-100x-20</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print negate 100x-20
-100x20</code></pre></div>

```
------------------------------------------------------------------
## NEGATIVE?
[[ positive? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print negative? -50
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print negative? 50
false</code></pre></div>

```
------------------------------------------------------------------
## NEW-LINE
[[ new-line? ]]

```html

<p>Where the NEW-LINE? function queries the status of the a 
block for markers, the NEW-LINE function inserts or removes 
them. You can use it to generate formatted blocks.</p>
<p>Given a block at a specified offset, new-line? will return 
true if there is a marker at that position.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">dent-block: func [
    "Indent the contents of a block"
    block
][
    head new-line tail new-line block on on
]

b: [1 2 3 4 5 6]
probe dent-block b
[</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">1 2 3 4 5 6</code></pre></div>
<p>]</p>
<p>If you want to put each item in a block on a new line, you 
can insert markers in bulk, using the /all refinement.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">b: [1 2 3 4 5 6]
probe new-line/all b on
[</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">1
2
3
4
5
6</code></pre></div>
<p>]</p>
<p>If you don't know whether a block contains markers, you may 
want to remove all markers before formatting the data.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">b: [
    1 2 
    3 4
]
probe new-line/all b off
[1 2 3 4]</code></pre></div>
<p>Another common need is formatting blocks into lines of fixed 
size groups of items; that's what the /skip refinement is for.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">b: [1 2 3 4 5 6]
probe new-line/skip b on 2
[</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">1 2
3 4
5 6</code></pre></div>
<p>]</p>

```
------------------------------------------------------------------
## NEW-LINE?
[[ new-line ]]

```html

<p>Given a block at a specified offset, new-line? will return 
true if there is a line marker at that position.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">b: [1 2 3 4 5 6]
forall b [if new-line? b [print index? b]]

b: [
    1 2
    3 4
    5 6
]
forall b [if new-line? b [print index? b]]
5</code></pre></div>

```
------------------------------------------------------------------
## NEXT
[[ back first head tail head? tail? ]]

```html

<p>If the series is at its tail, it will remain at its
tail. NEXT will not go past the tail, nor will it wrap
to the head.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print next "ABCDE"
BCDE</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print next next "ABCDE"
CDE</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print next [1 2 3 4]
2 3 4</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "REBOL"
loop length? str [
    print str
    str: next str
]
L</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [red green blue]
loop length? blk [
    probe blk
    blk: next blk
]
[blue]</code></pre></div>

```
------------------------------------------------------------------
## NINTH
[[ first second third pick ]]

```html

<p>See the FIRST function for examples.</p>
<p>An error will occur if no value is found. Use the PICK function to avoid this error.</p>

```
------------------------------------------------------------------
## NONE?

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print none? NONE
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print none? pick "abc" 4
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print none? find "abc" "d"
true</code></pre></div>

```
------------------------------------------------------------------
## NOT
[[ complement negate and or xor unless ]]

```html

<p>The <a href="#not">not</a> function is a <span class="datatype">logic!</span> function that returns true if the value is false or none. It will return false for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">not true
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">not none
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">not (10 = 1)
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">not 0
false  ; take note of this</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">not 1
false</code></pre></div>
<p>To complement an <span class="datatype">integer!</span> use the <a href="#complement">complement</a> function or <a href="#negate">negate</a> function.</p>

```
------------------------------------------------------------------
## NOT-EQUAL?
[[ <> = == equal? ]]

```html

<p>String-based datatypes are considered equal when they
are identical or differ only by character casing
(uppercase = lowercase). Use <a href="#==">==</a> or find/match/case to
compare strings by casing.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print not-equal? "abc" "abcd"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print not-equal? [1 2 4] [1 2 3]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print not-equal? 12-sep-98 10:30
true</code></pre></div>

```
------------------------------------------------------------------
## NOT-EQUIV?
------------------------------------------------------------------
## NOW
[[ date? ]]

```html

<p>For accuracy, first verify that the time, date and
timezone are correctly set on the computer.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print now
12-Feb-2009/17:47:54-8:00</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print now/date
12-Feb-2009</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print now/time
17:47:54</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print now/zone
-8:00</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print now/weekday
4</code></pre></div>

```
------------------------------------------------------------------
## NUMBER?
[[ integer? decimal? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print number? 1234
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print number? 12.34
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print number? "1234"
false</code></pre></div>

```
------------------------------------------------------------------
## OBJECT

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## OBJECT?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print object? system
true</code></pre></div>

```
------------------------------------------------------------------
## ODD?
[[ even? ]]

```html

<p>Returns TRUE only if the argument is an odd integer value.
If the argument is a decimal, only its integer portion is
examined.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print odd? 3
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print odd? 100
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print odd? 0
false</code></pre></div>

```
------------------------------------------------------------------
## OFFSET?
[[ index? length? head head? tail tail? pick skip ]]

```html

<p>Return the difference of the indexes for two positions within a
series.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "abcd"
p1: next str
print offset? str p1
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "abcd"
p1: next str
p2: find str "d"
print offset? p1 p2
2</code></pre></div>

```
------------------------------------------------------------------
## OP?

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print op? :and
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print op? :+
true</code></pre></div>

```
------------------------------------------------------------------
## OPEN
[[ close load do insert remove read write query ]]

```html

<p>Opens a port for I/O operations. The value returned from
OPEN can be used to examine or modify the data
associated with the port. The argument must be a
fully-specified port specification, an abbreviated port
specification such as a file path or URL, or a block
which is executed to modify a copy of the default port
specification.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">autos: open/new %autos.txt
insert autos "Ford"
insert tail autos " Chevy"
close autos
print read %autos.txt</code></pre></div>

```
------------------------------------------------------------------
## OPEN?

```html

<p>Description is needed.</p>

```
------------------------------------------------------------------
## OR
[[ and not xor ]]

```html

<p>An infix-operator. For LOGIC values, both must be FALSE
to return FALSE; otherwise a TRUE is returned. For
integers, each bit is separately affected. Because it is
an infix operator, OR must be between the two values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print true or false
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print (10 &gt; 20) or (20 &lt; 100)
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print 122 or 1
123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print 1.2.3.4 or 255.255.255.0
255.255.255.4</code></pre></div>

```
------------------------------------------------------------------
## OR~
[[ and~ xor~ ]]

```html

<p>The trampoline action function for OR operator.</p>

```
------------------------------------------------------------------
## PAD
------------------------------------------------------------------
## PAIR?
[[ to-pair as-pair ]]

```html

<p>Returns true if the value is an xy pair datatype.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print pair? 120x40
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print pair? 1234
false</code></pre></div>
<p>See the PAIR! word for more detail.</p>

```
------------------------------------------------------------------
## PAREN?
[[ type? ]]

```html

<p>Returns FALSE for all other values. A paren is identical
to a block, but is immediately evaluated when found.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print paren? second [123 (456 + 7)]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print paren? [1 2 3]
false</code></pre></div>

```
------------------------------------------------------------------
## PARSE
[[ trim ]]

```html

<p>The <a href="#parse">parse</a> function is used to match patterns of values and perform specific actions upon  such matches. A full summary can be found in <a href="/r3/docs/concepts/parsing-summary.html" class="con">parsing: summary of parse operations</a> .</p>
<p>Both <span class="datatype">string!</span> and <span class="datatype">block!</span> datatypes can be parsed. Parsing of strings matches specific characters or substrings. Parsing of blocks matches specific values, or specific datatypes, or sub-blocks.</p>
<p>Whereas most languages provide a method of parsing strings, the parsing of blocks is an important feature of the REBOL language.</p>
<p>The <a href="#parse">parse</a> function takes two main arguments: an input to be parsed and the rules that are used to parse it. The rules are specified as a block of grammar productions that are to be matched.</p>
<h6 id="section-2">General parse rules</h6>
<p>Rules consist of these main elements:</p>
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
<h6 id="section-3">List of keywords</h6>
<p>Within the parse dialect, these words are treated as keywords and cannot be used as variables.</p>
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
<p>In addition, none is a special value that can be used as a default match rule. It is often used at the end of alternate rules to catch all no-match cases.</p>
<h6 id="section-4">Simple Parse</h6>
<p>There is also a simple parse
mode that does not require rules, but takes a string of
characters to use for splitting up the input string.</p>
<p>Parse also works in conjunction with bitsets (charset)
to specify groups of special characters.</p>
<p>The result returned from a simple parse is a block of
values. For rule-based parses, it returns TRUE if the
parse succeeded through the end of the input string.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print parse "divide on spaces" none
divide on spaces</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print parse "Harry Haiku, 264 River Rd., Ukiah, 95482" ","
Harry Haiku 264 River Rd. Ukiah 95482</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">page: read http://hq.rebol.net
parse page [thru &lt;title&gt; copy title to &lt;/title&gt;]
print title
Now is REBOL</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">digits: charset "0123456789"
area-code: ["(" 3 digits ")"]
phone-num: [3 digits "-" 4 digits]
print parse "(707)467-8000" [[area-code | none] phone-num]
true</code></pre></div>

```
------------------------------------------------------------------
## PAST?

```html

<p>Description is needed.</p>

```
------------------------------------------------------------------
## PATH?
[[ make ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print path? first [random/seed 10]
true</code></pre></div>

```
------------------------------------------------------------------
## PATH-THRU
------------------------------------------------------------------
## PERCENT?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## PICK
[[ first second third fourth fifth find select ]]

```html

<p>The value is picked relative to the current position in
the series (not necessarily the head of the series).
The VALUE argument may be INTEGER or LOGIC. A positive
integer positions forward, a negative positions
backward. If the INTEGER is out of range, NONE is
returned. If the value is LOGIC, then TRUE refers to the
first position and FALSE to the second (same order as
EITHER). An attempt to pick a value beyond the limits
of the series will return NONE.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "REBOL"

print pick str 2
E</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print pick 199.4.80.1 3
80</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print pick ["this" "that"] now/time &gt; 12:00
this</code></pre></div>

```
------------------------------------------------------------------
## PICKZ
------------------------------------------------------------------
## POKE
[[ pick change ]]

```html

<p>Similar to CHANGE, but also takes an index into the series.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "ABC"
poke str 2 #"/"
print str
A/C</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print poke 1.2.3.4 2 10
10</code></pre></div>

```
------------------------------------------------------------------
## POKEZ
------------------------------------------------------------------
## PORT?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">file: open %newfile.txt
print port? file
close file
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print port? "test"
false</code></pre></div>

```
------------------------------------------------------------------
## POSITIVE?
[[ negative? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print positive? 50
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print positive? -50
false</code></pre></div>

```
------------------------------------------------------------------
## POWER
[[ exp log-10 log-2 log-e ]]

```html

<div class="example-code"><pre class="code-block"><code class="rebol">print power 12.3 5
281530.5684300001</code></pre></div>

```
------------------------------------------------------------------
## PREMULTIPLY
------------------------------------------------------------------
## PRIN
[[ print input echo ]]

```html

<p>No line termination is used, so the next value printed
will appear on the same line. If the value is a block,
each of its values will be evaluated first then printed.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">prin "The value is "
prin [1 + 2]

prin ["The time is" now/time]</code></pre></div>

```
------------------------------------------------------------------
## PRINT
[[ prin probe ?? form reform format mold remold ajoin join rejoin input echo ]]

```html

<p>The <a href="#print">print</a> function outputs values in "human-friendly" format (without source code syntax.)</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print 1234
1234</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print "Example"
Example</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print read %file.txt
(file output)</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print read http://www.rebol.com
(web page output)</code></pre></div>
<p>If the value is a block, it will be processed by <a href="#reduce">reduce</a> to evaluate each of its values, which will then be output:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print ["The time is" now/time]
The time is 17:47:54</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print ["You are using REBOL" system/product system/version]
You are using REBOL core 3.0.0.3.1</code></pre></div>
<h6 id="section-2">Removing Spaces</h6>
<p>If you need to join strings and values together for output, use the <a href="#ajoin">ajoin</a>, <a href="#join">join</a>, or <a href="#rejoin">rejoin</a> functions.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print ajoin ["REBOL/" system/product " V" system/version/1]]
REBOL/core V3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print ajoin ["The time is " 11:30 "AM"]
The time is 11:30AM</code></pre></div>
<h6 id="section-3">Related Functions</h6>
<p>If a newline is not desired, use <a href="#prin">prin</a> which does not terminate the output:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">prin "T"
print "est"
Test</code></pre></div>
<p>The <a href="#print">print</a> function is based on the <a href="#reform">reform</a> function, which combines the <a href="#reduce">reduce</a> and <a href="#form">form</a> functions.</p>
<p>Notice the difference between:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: reform ["The time is" now/time]
print str
The time is 17:47:54</code></pre></div>
<p>and:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: form ["The time is" now/time]
print str
The time is now/time</code></pre></div>
<p>The alternative to <a href="#form">form</a> is <a href="#mold">mold</a> which produces source code string output, and <a href="#remold">remold</a> combines <a href="#reduce">reduce</a> with <a href="#mold">mold</a> in the same way.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: mold ["The time is" now/time]
print str
["The time is" now/time]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: mold ["The time is" now/time]
print str
["The time is" 17:47:54]</code></pre></div>
<p>The <a href="#probe">probe</a> function is similar to <a href="#print">print</a> but is defined as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe: func [value] [print mold :value :value]</code></pre></div>
<p>The second use of value is to cause <a href="#probe">probe</a> to return the value it was passed.</p>
<p>If you want to copy <a href="#print">print</a> output to a file as well as the console, use the <a href="#echo">echo</a> function.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">echo %output.txt
print "Copying to file"</code></pre></div>

```
------------------------------------------------------------------
## PRINT-HORIZONTAL-LINE
------------------------------------------------------------------
## PRINT-TABLE
------------------------------------------------------------------
## PRINTF

```html

<p>Description is needed.</p>

```
------------------------------------------------------------------
## PROBE
[[ ?? mold print trace source help what ]]

```html

<p>The <a href="#probe">probe</a> function will <a href="#mold">mold</a> a value into reloadable source format and display it.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">num: 1
probe [num + 2 "ABC"]
[num + 2 "ABC"]</code></pre></div>
<p>Compare with the <a href="#print">print</a> function which will <a href="#reduce">reduce</a> the block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print [num + 2 "ABC"]
3 ABC</code></pre></div>
<h6 id="section-2">Return Value</h6>
<p>The <a href="#probe">probe</a> function also returns its argument value as its result, making it easy to insert into code for debugging purposes.</p>
<p>Examples:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">n: probe 1 + 2
3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print n
3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print 2 * probe pi * probe sine 45
0.707106781186547
2.22144146907918
4.44288293815837</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">word: 'here
if probe find [where here there] word [print "found"]
[here there]
found</code></pre></div>
<p>See the <a href="#print">print</a> function for information about related functions.</p>

```
------------------------------------------------------------------
## PROFILE
------------------------------------------------------------------
## PROTECT
[[ unprotect secure set ]]

```html

<p>The <a href="#protect">protect</a> function provides the following features:</p>
<ul>
<li>protects <span class="datatype">string!</span>, <span class="datatype">block!</span>, and other series from modification (making them read-only.)</li>
<li>protects variables (words) from being <a href="#set">set</a> to new values.</li>
<li>protects <span class="datatype">object!</span>, <span class="datatype">module!</span>, and <span class="datatype">map!</span> from modification (by protecting all its words.)</li>
<li>hide words within objects or modules - making them private - a method of read and write protection.</li>
</ul>
<h6 id="section-2">Synopsis</h6>
<p>The <a href="#protect">protect</a> argument and refinements provide these various protections:</p>
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
<h6 id="section-3">Protecting series (strings and blocks)</h6>
<p>For example to use <a href="#protect">protect</a> to prevent modification to a string:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">test: "text"
protect test
append test "a"
** Script error: protected value or series - cannot modify</code></pre></div>
<p>The text string itself is now read-only. Any attempt to modify it will result in that
error message.</p>
<p>This also applies to other series:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">test: [100 "example" 10:20]
protect test
append test 1.2
** Script error: protected value or series - cannot modify</code></pre></div>
<p>But notice:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print append test/2 "x"
examplex</code></pre></div>
<p>So, series within the block are still modifiable.</p>
<p>To protect all series found within a block, use the /deep refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">test: [100 "example" 10:20]
protect/deep test
print append test/2 "x"
** Script error: protected value or series - cannot modify</code></pre></div>
<h6 id="section-4">Protecting objects and modules</h6>
<p>It can also be applied to objects and modules, where its meaning becomes: do not let the fields of the object be modified. However, the contents of those fields can still be modified.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">person: make object! [
     name: "Bob"
     age: 32
]
protect person
person/name: "Ted"
** Script error: protected variable - cannot modify: name</code></pre></div>
<p>However, you can still modify the contents of the name string:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">append person/name "a"
print person/name
Boba</code></pre></div>
<p>To prevent that, you call <a href="#protect">protect</a> with the /deep refinement to protect all series within the object:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">person: make object! [
     name: "Bob"
     age: 32
]
protect/deep person
append person/name "a"
** Script error: protected value or series - cannot modify</code></pre></div>
<h6 id="section-5">Protecting variables (words)</h6>
<p>Protect can also be used to prevent a variable word from being modified using a set operation.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">test: "This word is protected!"
protect 'test
test: 123
** Script error: protected variable - cannot modify: test</code></pre></div>
<h6 id="section-6">Hiding variables (words)</h6>
<p>To make a variable private, use the /hide refinement. In effect, this prevents any further bindings to the variable. It also blocks attempts at <a href="#select">select</a>, <a href="#in">in</a>, <a href="#get">get</a>, <a href="#mold">mold</a>, and <a href="#form">form</a>, as well as <a href="#reflect">reflect</a> access.</p>
<p>For example, here is an object that defines a password variable that is hidden.
Once the object has been created, the pass variable is not accessible, except with the functions defined prior to the <a href="#protect">protect</a>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">manager: object [

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
]</code></pre></div>
<p>The password can be accessed with the provided functions:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">manager/set-pass "bingo"
setting password...</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print manager/get-pass
#{E410B808A7F76C6890C9ECACF2B564EC98204FDB}</code></pre></div>
<p>But any other access is not allowed:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe manager/pass
** Script error: cannot access pass in path manager/pass</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe get in manager 'pass
none</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe select manager 'pass
none</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe words-of manager
[set-pass get-pass]</code></pre></div>
<p>For security reasons, once hidden, a variable cannot be unhidden.</p>
<h6 id="section-7">Compatibility</h6>
<fieldset class="fset"><legend>Non-compatibility with R2</legend>
<p>When using a block with <a href="#protect">protect</a>, the meaning is not to protect the words of the block, but to protect the block series itself.</p>
<p>If you need the behavior of R2, use the /words refinement.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">protect/words [test this]</code></pre></div>
<p>Will protect the test and this variables.</p>
</fieldset>
<h6 id="section-8">Related articles</h6>
<ul>
<li><a href="http://www.rebol.net/r3blogs/0186.html" class="lnk">Read-only strings, blocks, and objects</a></li>
<li><a href="http://www.rebol.net/r3blogs/0187.html" class="lnk">Interesting insights from PROTECT</a></li>
</ul>
<p>(From the A43 release.)</p>

```
------------------------------------------------------------------
## PROTECT-SYSTEM-OBJECT
------------------------------------------------------------------
## PROTECTED?
------------------------------------------------------------------
## PUT
------------------------------------------------------------------
## PWD
[[ cd change-dir delete list-dir ls make-dir mkdir rm what-dir ]]

```html

<p>Note: Shell shortcut for <a href="#what-dir">what-dir</a>.</p>

```
------------------------------------------------------------------
## Q
[[ halt exit quit ]]

```html

<p>Shortcut for QUIT.</p>
<p>See QUIT for details.</p>

```
------------------------------------------------------------------
## QUERY
[[ open update ]]

```html

<p>Its argument is an unopened port specification. The
size, date and status fields in the port specification
will be updated with the appropriate information if the
query succeeds.</p>

```
------------------------------------------------------------------
## QUIT
[[ halt exit q ]]

```html

<p>You can call <a href="#quit">quit</a> to exit (terminate) your program at any point.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">time: 10:00
if time &gt; 12:00 [
    print "time for lunch"
    quit
]</code></pre></div>
<p>Without refinements, <a href="#quit">quit</a> is a non-forceful exception (it will <a href="#throw">throw</a> a quit exception.) This behavior allows a parent program to stop the termination.</p>
<p>To force an immediate quit (no exception), use the /now refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if bad-data [quit/now]</code></pre></div>
<p>You can also return an <span class="datatype">integer!</span> quit code to the operating system (shell) by using the <a href="#return">return</a> refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">quit/return 40</code></pre></div>
<p>Note that not all operating systems environments may support this quit code.</p>
<fieldset class="fset"><legend>Rarely used</legend>
<p>Most programs do not require <a href="#quit">quit</a>, and it can be problematic if your code is started by another REBOL program. Normally, when your program reaches the end, it will quit by itself. (If you want to prevent that behavior, use the -h command line option, or call <a href="#halt">halt</a> at the end of your code.)</p>
</fieldset>

```
------------------------------------------------------------------
## QUOTE
------------------------------------------------------------------
## RANDOM
[[ checksum now ]]

```html

<p>The value passed can be used to restrict the range of
the random result. For integers random begins at one,
not zero, and is inclusive of the value given. (This
conforms to the indexing style used for all series
datatypes, allowing random to be used directly with
functions like PICK.)</p>
<div class="example-code"><pre class="code-block"><code class="rebol">loop 3 [print random 10]
1
5
3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">lunch: ["Italian" "French" "Japanese" "American"]
print pick lunch random 4
American</code></pre></div>
<p>If the given argument is a logic value, the result is actually the same as the result of the expression</p>
<div class="example-code"><pre class="code-block"><code class="rebol">even? random 2</code></pre></div>
<p>Example</p>
<div class="example-code"><pre class="code-block"><code class="rebol">loop 4 [print random true]
false
false
false
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">loop 2 [print random 1:00:00]
0:12:20
0:48:22</code></pre></div>
<p>For decimal value the function generates a uniformly distributed random number between zero (inclusive) and the given value (inclusive).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">loop 3 [print random 1.0]
0.209417212061865
0.878424991742667
0.93627033045037</code></pre></div>
<p>Main properties:</p>
<ol>
<li>the probability density in the interior points is the reciprocal of the given decimal VALUE argument</li>
<li>the probability density in the exterior points is 0.0</li>
<li>as specified by IEEE754, the bounds represent "close" interior well as "close" exterior real numbers. Therefore, the frequency of every bound corresponds to the length of the segment containing adjacent interior real values (real numbers, that are IEEE 754 - rounded to the value of the bound) multiplied by the interior density equal to the reciprocal of the given VALUE</li>
</ol>
<p>RANDOM can also be used on all series datatypes:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print random "abcdef"
dbcafe</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print random [1 2 3 4 5]
2 4 5 3 1</code></pre></div>
<p>In this case RANDOM randomly shuffles the given series "in place", yielding the original series with the same elements, just shuffled.
To cut it down, you can use CLEAR:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">key: random "abcdefghijklmnopqrstuv0123456789"
clear skip key 6
print key
anfruk</code></pre></div>
<p>Here's an example password generator. Add more partial words
to get more variations:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">syls: ["ca" "ru" "lo" "ek" "-" "." "!"]
print rejoin random syls
.!ru-ekcalo</code></pre></div>
<p>To initialize the random number generator, you can seed it with a value (to repeat the sequence) or the current time to start a unique seed.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">random/seed 123

random/seed now</code></pre></div>
<p>That last line is a good example to provide a fairly random
starting value for the random number generator.</p>
<p>The /SECURE variant uses SHA1() of a repeating pattern of the integer bytes (20 bytes total) and it produces cryptographically secure 64-bit random numbers. Cryptographical security means, that it is infeasible to compute the state of the generator from its output. If you don't need to make computing of the generator state infeasible (needed especially when you use the generator to generate passwords, challenges, etc. and want to comply to the FIPS security standards), it is more efficient to use the raw variant (without /SECURE refinement). Even in that case it is not feasible to compute the state, since the state of present generator consists of too many bits to be computable from the output.</p>
<h6 id="section-2">Algorithm</h6>
<p>The RANDOM function uses a random generator by Donald E. Knuth adjusted to generate 62-bit random integers. Thus, the maximal obtainable random number is 2 to the power of 62 = 4611686018427387904.</p>
<p>If the RANDOM function obtains 0 as an argument, it yields 0. If the argument is a positive integer, the RANDOM function uses rejection, rejecting all "raw randoms" that exceed the largest obtainable multiple of the given VALUE argument. This way, the uniformity of the distribution is assured. In case the given VALUE exceeds the biggest obtainable "raw random", we would have to reject every "raw random" number, so in that case an overflow error is caused (It certainly is an error expecting a bigger random, than the "raw random" maximum).</p>
<p>If the given VALUE is negative, then the generated random integers are in the interval VALUE <= R <= -1.</p>
<p>Uniformly distributed random decimals are generated using the integer output of the Knuth's generator as follows:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">tt62: to integer! 2 ** 62
4611686018427387904</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">random-dec: func [x [decimal!]] [(to decimal! (random tt62) - 1) / tt62 * x]

random/seed 0
random 1.0
0.209417212061865</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">random/seed 0
random-dec 1.0
0.209417212061865</code></pre></div>
<p>In case the given decimal VALUE is positive, the generated random deviates are uniformly distributed in the interval 0.0 <= R <= VALUE, i.e. including bounds.</p>
<p>In case the given decimal VALUE is negative, the random deviates are uniformly distributed in the interval VALUE <= R <= 0.0.</p>
<p>Sometimes we need to obtain a uniformly distributed random number R, such that 0.0 < R < 1.0 (i.e. a uniformly distributed random number in the given interval, excluding the bounds). We can get such an R rejecting the bounds as follows:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">random/seed 0
until [
    r: random 1.0
    all [
        r !== 0.0
        r !== 1.0
    ]
]
r
0.209417212061865</code></pre></div>

```
------------------------------------------------------------------
## RC4
------------------------------------------------------------------
## READ
[[ write open close load save ]]

```html

<p>Using READ is the simplest way to get information from
a file or URL. This is a higher level port operation
that opens a port, reads some or all of the data, then
closes the port and returns the data that was read. 
When used on a file, or URL, the contents of the file,
or URL are returned as a string.</p>
<p>The /LINES refinement returns read content as a series 
of lines. One line is created for each line terminator
found in the read data.</p>
<p>The /PART refinement reads the specified number of 
elements from the file, URL, or port. Reading a file
or URL will read the specified number of characters.
Used with /LINES, it reads a specified number of 
lines.</p>
<p>See the User's Guide for more detailed explanation of
using READ and its refinements.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">write %rebol-test-file.r "text file"
print read %rebol-test-file.r
read</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">write %rebol-test-file.r [
{A learned blockhead is a greater man
than an ignorant blockhead.
    -- Rooseveldt Franklin}
]
probe first read/lines %rebol-test-file.r
write</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe pick (read/lines %rebol-test-file.r) 3

probe read/part %rebol-test-file.r 9

probe read/with %rebol-test-file.r "blockhead"
write/append %matrix.avi to-binary "abcdefg"</code></pre></div>

```
------------------------------------------------------------------
## READ-THRU
------------------------------------------------------------------
## REBCODE?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## RECYCLE

```html

<p>This function will force a garbage collection of unused words
and values found in memory. This function is not required or
recommened for most scripts because the system does it
automatically as necessary.</p>
<p>To disable garbage collection, you can specify /off refinement.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">recycle/off</code></pre></div>
<p>To enable it again, use /on:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">recycle/on</code></pre></div>
<p>Note that recently used values may not be immediately garbage
collected, even though they are no longer being referenced by
your program.</p>

```
------------------------------------------------------------------
## REDUCE
[[ compose do foreach ]]

```html

<p>The <a href="#reduce">reduce</a> function evaluates multiple expressions and returns a block of results. This is one of the most useful functions in REBOL.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">values: reduce [1 + 2 3 + 4]
probe values
[3 7]</code></pre></div>
<p>Compare this with <a href="#do">do</a>, which only returns the result of the last expression:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">values: do [1 + 2 3 + 4]
probe values
7</code></pre></div>
<h6 id="section-2">Part of other functions</h6>
<p>The <a href="#reduce">reduce</a> function is important because it enables you to create blocks of expressions that are evaluated and passed to other functions. Some functions, like <a href="#print">print</a>, use <a href="#reduce">reduce</a> as part of their operation, as shown in the following example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print [1 + 2  3 + 4]
3 7</code></pre></div>
<p>The <a href="#rejoin">rejoin</a>, <a href="#repend">repend</a>, <a href="#reform">reform</a>, <a href="#remold">remold</a> functions also use <a href="#reduce">reduce</a> as part of their operation, as shown in the following examples:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">rejoin ["example" 1 + 2]
example3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: copy "example"
repend str [1 + 2] ; modifies (uses append)
example3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">reform ["example 1 + 2]
example 3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">remold ["example" 1 + 2]
["example" 3]</code></pre></div>
<h6 id="section-3">Ignored reduction</h6>
<p>For convenience, expressions that are fully evaluated simply pass-through the <a href="#reduce">reduce</a> function.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">reduce 123
123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">reduce "example"
example</code></pre></div>
<p>This makes it possible to use <a href="#reduce">reduce</a> in cases where other datatypes may be passed. For example, here is a common function for building HTML strings that relies on this behavior:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">html: make string! 1000
emit: func [data] [repend html data]

emit "test... "
emit ["number is: " 10]
print html
test... number is: 10</code></pre></div>
<h6 id="section-4">Blocks with set-words</h6>
<p>When you <a href="#reduce">reduce</a> blocks that contain set-words, those words will be set. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">a: 1
reduce [a: 2]
print a
2</code></pre></div>
<p>There are times when you do not want this to occur. For example, if you're building a header for a file, you may want to leave the set-words alone.</p>
<p>The /no-set refinement can be used to handle this case.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">full-name: "Bob Smith"
reduce/no-set [name: full-name time: now + 10]
[name: "Bob Smith" time: 15-Aug-2010/16:10:50-7:00]</code></pre></div>
<h6 id="section-5">Memory usage for large blocks</h6>
<p>For most blocks you don't need to worry about memory because REBOL's automatic storage manager will efficiently handle it; however, when building large block series with <a href="#reduce">reduce</a>, you can manage memory even more carefully.</p>
<p>For example, it is common to write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">repend series [a b c]</code></pre></div>
<p>which is shorthand for:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">append series reduce [a b c]</code></pre></div>
<p>The evaluated results of a, b, and c are appended to the series.</p>
<p>If this is done a lot, a large number of temporary series are generated, which take memory and also must be garbage collected later.</p>
<p>The /into refinement helps optimize the situation:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">reduce/into [a b c] tail series</code></pre></div>
<p>It requires no intermediate storage.</p>
<h6 id="section-6">Common Problems</h6>
<p>Although <a href="#reduce">reduce</a> will create a new outer block, all other series (blocks, strings, etc.) are referenced, not copied. If you modify those values, they will change in all blocks that reference them.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "name"
probe result: reduce [str]
["name"]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">insert str "new-"
probe result
["new-name"]</code></pre></div>
<p>You can see that it's the same string. To change that behavior use the <a href="#copy">copy</a> function:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">result: reduce [copy str]</code></pre></div>
<p>or, for blocks that contain multiple strings or other values:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">result: copy/deep reduce [str]</code></pre></div>

```
------------------------------------------------------------------
## REF?
------------------------------------------------------------------
## REFINEMENT?

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print refinement? /any
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print refinement? 'any
false</code></pre></div>

```
------------------------------------------------------------------
## REFLECT
[[ body-of spec-of title-of types-of values-of words-of ]]

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## REFORM
[[ form mold remold join rejoin ]]

```html

<p>Identical to FORM but reduces its argument first.
Spaces are inserted between each value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe reform ["the time is:" now/time]
"the time is: 17:47:54"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe form ["the time is:" now/time]
"the time is: now/time"</code></pre></div>

```
------------------------------------------------------------------
## REGISTER-CODEC
------------------------------------------------------------------
## REJOIN
[[ join ajoin form reform ]]

```html

<p>Similar to <a href="#join">join</a> but accepts only one argument, the
block (which will be reduced first). No spaces are
inserted between values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">rejoin ["time=" now/time]
time=17:47:54</code></pre></div>
<p>Notice this important case:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">rejoin [&lt;a&gt; "test"]
&lt;atest&gt;</code></pre></div>
<p>This is fine for lines like:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">rejoin [&lt;a href=&gt; "test.html"]
&lt;a href=test.html&gt;</code></pre></div>
<p>But you can see it creates a problem in this case:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">rejoin [&lt;a href=test.html&gt; "test" &lt;/a&gt;]
&lt;a href=test.htmltest&lt;/a&gt;&gt;</code></pre></div>
<p>If you want the result to be a <span class="datatype">string!</span>, use the <a href="#ajoin">ajoin</a> function instead.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">ajoin [&lt;a href=test.html&gt; "test" &lt;/a&gt;]
"&lt;a href=test.html&gt;test&lt;/a&gt;"</code></pre></div>

```
------------------------------------------------------------------
## RELEASE
------------------------------------------------------------------
## REMAINDER
[[ // / ]]

```html

<p>If the second number is zero, an error will occur.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print remainder 123 10
3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print remainder 10 10
0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print remainder 10.2 10
0.1999999999999993</code></pre></div>
<p>If the first value is positive, then the returned remainder is nonnegative.</p>
<p>If the first value is negative, then the returned remainder is nonpositive.</p>

```
------------------------------------------------------------------
## REMOLD
[[ mold reduce reform form ]]

```html

<p>Identical to MOLD, but reduces its argument first.
Spaces are inserted between each values in a block.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print remold ["the time is:" now/time]
["the time is:" 17:47:54]</code></pre></div>

```
------------------------------------------------------------------
## REMOVE
[[ append change clear insert sort ]]

```html

<p>Removes a single value from the current position in any type of <a href="/r3/docs/concepts/series.html" class="con">series</a>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: copy "send it here"
remove str
print str
end it here</code></pre></div>
<p>Combine it with other functions to remove a value at a specific index:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">remove find str "it"
print str
end t here</code></pre></div>
<p>You can remove any number of values with the /PART refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: copy "send it here"
remove/part str 3
print str
d it here</code></pre></div>
<p>The PART refinement also accepts an index of the series being removed form. It must be the same series.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">remove/part str find str "here"
print str
here</code></pre></div>
<p>An example using a block!:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: copy [red green blue]
remove next blk
probe blk
[red blue]</code></pre></div>

```
------------------------------------------------------------------
## REMOVE-EACH
[[ foreach remove map-each ]]

```html

<p>The <a href="#remove-each">remove-each</a> function is a high performance method of removing specific elements from a series. It is similar to <a href="#foreach">foreach</a> but will remove one or more values depending on the result of the evaluated block.</p>
<p>In this example, <a href="#remove-each">remove-each</a> is used to remove all strings from the block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">values: [12 "abc" test 5 "de" 10:30]
remove-each value values [string? value]
probe values
[12 test 5 10:30]</code></pre></div>
<p>Here, all integer values greater than 11 are removed:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">values: [12 "abc" test 5 "de" 10:30]
remove-each value values [all [integer? value value &gt; 11]]
probe values
["abc" test 5 "de" 10:30]</code></pre></div>
<h6 id="section-2">Multiple Elements</h6>
<p>The <a href="#remove-each">remove-each</a> function can be used on multiple elements, just as <a href="#foreach">foreach</a> does.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">movies: [
     8:30 "Contact"      $4.95
    10:15 "Ghostbusters" $3.25
    12:45 "Matrix"       $4.25
]

foreach [time title price] movies [
    print [title "at" time "for" price]
    if price &gt; $4.00 [print "removed" true]
]
Contact at 8:30 for $4.95
removed
Ghostbusters at 10:15 for $3.25
Matrix at 12:45 for $4.25
removed</code></pre></div>
<p>This example also shows that the evaluated block may contain any other expressions as long as the last one returns true for removed values.</p>
<p>Also, notice here the way <a href="#if">if</a> is used for its return value.</p>

```
------------------------------------------------------------------
## RENAME
[[ delete list-dir what-dir ]]

```html

<p>Renames a file within the same directory:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">write %testfile now
rename %testfile %remove.me
probe read %remove.me
delete %remove.me
write</code></pre></div>
<p>This function cannot be used to move a file from 
one directory to another.</p>

```
------------------------------------------------------------------
## REPEAT
[[ loop foreach forall forskip for while until ]]

```html

<p>The <a href="#repeat">repeat</a> function is an easy way to repeat the evaluation of a block with a loop counter.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">repeat num 3 [print num]
1
2
3</code></pre></div>
<p>Here the num counter begins at one and continues up to and including the integer value given.</p>
<h6 id="section-2">Other Notes</h6>
<ul>
<li>Negative or zero loop counts do not evaluate the block.</li>
<li>If a <span class="datatype">decimal!</span> count is used, it will be truncated to a lower integer value.</li>
<li>The <a href="#break">break</a> function can be used to stop the loop at any time.</li>
<li>The <a href="#loop">loop</a> function is similar to <a href="#repeat">repeat</a>, except that it has no loop counter. If you don't need the counter, <a href="#loop">loop</a> is more efficient.</li>
<li>The evaluated block is deep copied and rebound (see <a href="#bind">bind</a> ) to a new context that holds the loop variable. For large nested repeat loops, you will want to consider this overhead. An alternative is to use <a href="#while">while</a>, <a href="#until">until</a>, or <a href="#loop">loop</a> which do not require the copy and bind.</li>
</ul>
<h6 id="section-3">In question...</h6>
<p>If the value is a series, then the loop will repeat for each element of the series.</p>
<p>However, there's currently a difference between R2 and R3. In R2, if the value is a series, then the word holds the first value of each element of the series. In R3 it holds just the indexed series.</p>
<p class="need">Editor note: Determine if this is intentional<p>

```
------------------------------------------------------------------
## REPEND
[[ append insert reduce join ]]

```html

<p>REPEND stands for REDUCE APPEND. It performs the same operation
as APPEND (inserting elements at the tail of a series) but
Reduces the block of inserted elements first. Just like APPEND,
REPEND returns the head of the series.</p>
<p>For example, writing:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">numbers: [1 2 3]
probe repend numbers [2 + 2 2 + 3 3 + 3]
[1 2 3 4 5 6]</code></pre></div>
<p>is the same as writing:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">numbers: [1 2 3]
probe append numbers reduce [2 + 2 2 + 3 3 + 3]
[1 2 3 4 5 6]</code></pre></div>
<p>REPEND is very useful when you want to add to a series elements
that need to be evaluated first. The example below creates a
list of all the .r files in the current directory, along with
their sizes and modification dates.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: copy []
foreach file load %. [
    if %.r = suffix? file [
        repend data [file size? file modified? file]
    ]
]
probe data
[%build-docs.r 7915 13-Feb-2009/0:03:17.078 %bulk-modify.r 4210 7-Feb-2009/17:20:06.906 %cgi.r 5125 12-Feb-2009/20:54:51.578 %convert-orig.r 1112 7-Feb-2009/17:20:06.906 %emit-html.r 10587 13-Feb-2009/0:09:38.875 %eval-examples.r 2545 13-Feb-2009/1:46:59.765 %fix-args.r 416 13-Feb-2009/0:41:11.296 %funcs.r 1133 12-Feb-2009/18:54:32.875 %merge-funcs.r 1318 13-Feb-2009/0:42:03.718 %replace.r 197 7-Feb-2009/16:56:23 %scan-doc.r 3429 13-Feb-2009/0:05:33.062 %scan-titles.r 4402 12-Feb-2009/16:51:42.687 %strip-title.r 274 7-Feb-2009/17:20:06.953]</code></pre></div>
<p>When used with strings, repend is a useful way to join values.
The example below is a common method of generating HTML web
page code:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">html: copy "&lt;html&gt;&lt;body&gt;"
repend html [
    "Date is: " now/date &lt;P&gt;
    "Time is: " now/time &lt;P&gt;
    "Zone is: " now/zone &lt;P&gt;
    &lt;/body&gt;&lt;/html&gt;
]
print html
&lt;html&gt;&lt;body&gt;Date is: 12-Feb-2009&lt;P&gt;Time is: 17:47:54&lt;P&gt;Zone is: -8:00&lt;P&gt;&lt;/body&gt;&lt;/html&gt;</code></pre></div>

```
------------------------------------------------------------------
## REPLACE
[[ insert remove change ]]

```html

<p>Searches target block or series for specified data and 
replaces it with data from the replacement block or 
series. Block elements may be of any datatype.</p>
<p>The /ALL refinement replaces all occurrences of the 
searched data in the target block or series.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "a time a spec a target"
replace str "a " "on "
print str
on ime a spec a target</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">replace/all str "a " "on "
print str
on ime on pec on arget</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">fruit: ["apples" "lemons" "bananas"]
replace fruit "lemons" "oranges"
print fruit
apples oranges bananas</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">numbers: [1 2 3 4 5 6 7 8 9]
replace numbers [4 5 6] ["four" "five" "six"]
print numbers
1 2 3 four five six 7 8 9</code></pre></div>

```
------------------------------------------------------------------
## REQUEST-DIR
------------------------------------------------------------------
## REQUEST-FILE
[[ to-local-file to-rebol-file ]]

```html

<p>Opens the standard operating system file requester to allow the user to select one or more files.</p>
<h6 id="section-2">Details</h6>
<h7 id="section-3">Normal usage for read or load</h7>
<p>The line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">file: request-file</code></pre></div>
<p>will open the file requester and return a single file name as a full file path. This is normally used to read or load files.</p>
<p>If the user clicks CANCEL or closes the file requestor, a NONE is returned.</p>
<h7 id="section-4">For saving or writing files</h7>
<p>To open the file requester to save a file:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">file: request-file/save</code></pre></div>
<p>This will change the text of the window to indicate that a save (write) will be done.</p>
<h7 id="section-5">Specifying a default file or directory</h7>
<p>A default name can be provided for the file:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">file: request-file/file %test.txt</code></pre></div>
<p>This also works with the /save option, and a full path can be provided, in which case the requester will show the directory where the file will be found.</p>
<p>In addition, just a directory can be used:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">file: request-file/file %/c/data/files/</code></pre></div>
<p>Be sure to include the terminating slash to indicate a directory. Otherwise it will be treated as a file.</p>
<h7 id="section-6">Allowing multiple file selection</h7>
<p>To allow the selection of multiple files at the same time:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">files: request-file/multi

foreach file files [print file]</code></pre></div>
<p>The result is returned as a block, and each file within the block is a full path.</p>
<h7 id="section-7">Filtering file views</h7>
<p>You can also provide file list filters to show only specific files. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">file: request-file/filter [
    "REBOL Scripts" "*.r"
    "Text files" "*.txt"
]</code></pre></div>
<h7 id="section-8">Setting the window title</h7>
<p>The /title refinement lets you modify the window title for the file requester to help make it more clear to users.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">file: request-file/save/title "Save your data file"
either file [save file data] [print "data not saved"]</code></pre></div>
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

```html

<p>The <a href="#resolve">resolve</a> function is used to merge values from one context into another but avoids replacing existing values.</p>
<p>It is used mainly to support runtime environments, where newly exported functions must be merged into an existing lib context. Because lib can become quite large, performance must be optimized, which is the reason why <a href="#resolve">resolve</a> is a native function.</p>
<h7 id="section-2">Basic Concept</h7>
<p>This example will help to show the basic concept:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">obj1: object [a: 10]
obj2: object [b: 20]
append obj1 'b
resolve obj1 obj2
print obj1
a: 10
b: 20</code></pre></div>
<p>But notice:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">obj1: object [a: 10]
obj2: object [a: 30 b: 20]
append obj1 'b
resolve obj1 obj2
print obj1
a: 10
b: 20</code></pre></div>
<p>So, <a href="#resolve">resolve</a> has no affect on values that have already been set in the target context.</p>
<p>Note that protected words will not be modified, they are ignored. No error occurs.</p>
<h7 id="section-3">Refinements</h7>
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

```html

<p>Exits the current function immediately, returning
a value as the result of the function. To return no
value, use the EXIT function.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">fun: make function! [this-time] [
    return either this-time &gt;= 12:00 ["after noon"][
        "before noon"]
]
print fun 9:00

print fun 18:00</code></pre></div>

```
------------------------------------------------------------------
## REVERSE
[[ insert replace sort find ]]

```html

<p>Reverses the order of elements in a series or tuple.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [1 2 3 4 5 6]
reverse blk
print blk
6 5 4 3 2 1</code></pre></div>
<p>The /PART refinement reverses the specified number 
of elements from the current index forward. If the 
number of elements specified exceeds the number of 
elements left in the series or tuple, the elements from 
the current index to the end will be reversed.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">text: "It is possible to reverse one word in a sentence."
reverse/part (find text "reverse") (length? "reverse")
print text
It is possible to esrever one word in a sentence.</code></pre></div>
<p>Note that reverse returns the starting position it was
given. (This change was made to newer versions.)</p>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [1 2 3 4 5 6]
print reverse/part blk 4
4 3 2 1 5 6</code></pre></div>
<p>Reverse also works for pairs and tuples:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print reverse 10x20
print reverse 1.2.3
3.2.1</code></pre></div>
<p>For tuple values the current index cannot be moved so the 
current index is always the beginning of the tuple.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print reverse 1.2.3.4
4.3.2.1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print reverse/part 1.2.3.4 2
4.3.2.1</code></pre></div>

```
------------------------------------------------------------------
## REWORD
[[ compose replace ]]

```html

<p>This is a general substitution function useful for building web pages, form letters, and other documents.</p>
<h6 id="section-2">Work In Process</h6>
<p>The block substitution abilities are still pending but string substitution works well now.</p>

```
------------------------------------------------------------------
## RGB-TO-HSV
------------------------------------------------------------------
## RM
[[ cd change-dir delete list-dir ls make-dir mkdir pwd what-dir ]]

```html

<p>Note: Shell shortcut for <a href="#delete">delete</a>.</p>

```
------------------------------------------------------------------
## ROUND
[[ mod modulo // remainder ]]

```html

<p>"Rounding is meant to loose precision in a controlled way." -- Volker Nitsch</p>
<p>The <a href="#round">round</a> function is quite flexible. With the various refinements
and the scale option, you can easily round in various ways. Most of the
refinements are mutually exclusive--that is, you should use only one of
them--the /to refinement is an obvious exception; it can be combined 
with any other refinement.</p>
<p>By default, <a href="#round">round</a> returns the nearest integer, with halves rounded up (away 
from zero).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round 1.4999
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round 1.5
2</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round -1.5
-2</code></pre></div>
<p>If the result of the rounding operation is a number! with no decimal component, 
and the SCALE value is not time! or money!, an integer will be returned. This 
makes it easy to use the result of ROUND directly with iterator functions such
as LOOP and REPEAT.</p>
<p>The /TO refinment controls the "precision" of the rounding. That is, the result
will be a multiple of the SCALE parameter. In order to round to a given number
of decimal places, you don't pass in the number of decimal places, but rather 
the "level of precision" they represent. For example, to round to two decimal
places, often used for money values, you would do this:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/to $1.333 .01
$0.5558830792256812207833088</code></pre></div>
<p>To round to the nearest 1/8, often used for interest rates, you would do this:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/to 1.333 .125
1.375</code></pre></div>
<p>To round to the nearst 1K increment (e.g. 1024 bytes):</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/to 123'456 1024
123904</code></pre></div>
<p>If the /TO refinement is used, and SCALE is a time! or money! value, the result 
will be coerced to that type. If SCALE is not used, or is not a time! or money! 
value, the datatype of the result will be the same as the valued being rounded.</p>
<p>The /EVEN refinement is designed to reduce bias when rounding large groups of
values. It is sometimes called Banker's rounding, or statistical rounding. For 
cases where the final digit of a number is 5 (e.g. 1.5 or 15), the previous 
digit will be rounded to an even result (2, 4, etc.).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">repeat i 10 [val: i + .5 print [val round/even val]]
10.5 10</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">repeat i 10 [val: i * 10 + 5 print [val round/even/to val 10]]
105 100</code></pre></div>
<p>The /DOWN refinement rounds toward zero, ignoring discarded digits. It is often
called "truncate".</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/down 1.999
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/down -1.999
-1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/down/to 1999 1000
1000</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/down/to 1999 500
1500</code></pre></div>
<p>The /HALF-DOWN refinement causes halves to round toward zero; by default they are
rounded up.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/half-down 1.5
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/half-down -1.5
-1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/half-down 1.50000000001
2</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/half-down -1.50000000001
-2</code></pre></div>
<p>The /HALF-CEILING refinement causes halves to round in a positive direction; by 
default they are rounded up (away from zero). This works like the default 
behavior for positive values, but is not the same for negative values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round -1.5
-2</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe round/half-ceiling -1.5
-1</code></pre></div>
<p>/FLOOR causes numbers with any decimal component to be rounded in a negative 
direction. It works like /DOWN for positive numbers, but not for negative numbers.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">round/floor 1.999

round/floor -1.01

round/floor -1.00000000001</code></pre></div>
<p>/CEILING is the reverse of /FLOOR; numbers with any decimal component are rounded
in a positive direction.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">round/ceiling 1.01

round/ceiling 1.0000000001

round/ceiling -1.999</code></pre></div>
<p>If you are rounding extremely large numbers (e.g. 562'949'953'421'314), or using
very high precision decimal values (e.g. 13 or more decimal places), you may run
up against REBOL's native limits for values and its internal rounding rules. The
ROUND function is a mezzanine and has no control over that behavior.</p>
<p>Sometimes, it might appear that ROUND is doing something strange, so before 
submitting a bug to RAMBO, think about what you're actually asking it to do. For 
example, look at the results from this piece of code:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">repeat i 10 [
    scale: .9 + (i * .01) 
    print [scale  round/down/to 10.55 scale]
]
1.0 10.0</code></pre></div>
<p>The results approach 10.55 for values from 0.91 to 0.95, but then jump back when 
using values in the range 0.96 to 0.99. Those are the expected results, because 
you're truncating, that is, truncating to the nearest multiple of SCALE.</p>
<p>The design and development of the ROUND function involved many members 
of the REBOL community. There was much debate about the interface (one
function with refinement versus individual functions for each rounding
type, what words to use for parameter names, behavior with regards to
type coercion).</p>

```
------------------------------------------------------------------
## RSA
------------------------------------------------------------------
## RSA-INIT
------------------------------------------------------------------
## SAME?
[[ =? equal? ]]

```html

<p>Returns TRUE if the values are identical objects, not
just in value. For example, a TRUE would be returned if
two strings are the same string (occupy the same
location in memory). Returns FALSE for all other
values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">a: "apple"
b: a
print same? a b
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print same? a "apple"
false</code></pre></div>

```
------------------------------------------------------------------
## SAVE
[[ load mold write ]]

```html

<p>The <a href="#save">save</a> function is used to save REBOL code and data to a file, upload it to a URL, or store it into a local string.</p>
<p>When saving to a file or URL, the output of this function is always UTF-8 (an Unicode encoded format where ASCII is normal, but other characters are encoded.)</p>
<p>The format of the resulting output depends on what you need. The <a href="#save">save</a> function is designed to allow simple values to be easily saved to be loaded with <a href="#load">load</a> later:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">save %date.r now
load %date.r
26-Feb-2009/13:06:15-8:00</code></pre></div>
<p>But, it also allows complex more complex data to be saved:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">save %data.r reduce ["Data" 1234 %filename now/time]
load %data.r
["Data" 1234 %filename 13:07:15]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">save %options.r system/options
load %options.r
make object! [
    home: %/C/rebol/
    script: none
    path: %/C/rebol/
    boot: %/C/rebol/view.exe
    args: none
...</code></pre></div>
<p>In general, <a href="#save">save</a> performs the appropriate conversion and formatting to preserve datatypes. For instance, if the value is a REBOL block, it will be saved as a REBOL script that, when loaded, will be identical.</p>
<p class="need">Editor note: saving /all<p>
<p class="need">Editor note: saving with headers<p>
<p>Note: Users must take care in how saved data is loaded. More on this below.</p>

```
------------------------------------------------------------------
## SCALAR?

```html

<p>Description is needed.</p>

```
------------------------------------------------------------------
## SCRIPT?

```html

<p>If the header is found, the script string will be returned
as of that point. If not found, then NONE is returned.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print either script? %file.txt ["found"]["not found"]</code></pre></div>

```
------------------------------------------------------------------
## SECOND
[[ pick first third fourth fifth ]]

```html

<p>An error will occur if no value is found. Use the PICK
function to avoid this error.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print second "REBOL"
E</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print second [11 22 33 44 55 66]
22</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print second 12-jun-1999
6</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print second 199.4.80.1
4</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print second 12:34:56.78
34</code></pre></div>

```
------------------------------------------------------------------
## SECURE
[[ protect load import ]]

```html

<p>The <a href="#secure">secure</a> function controls file, network, evaluation, and all other external access and related policies.</p>
<p>The function uses a simple dialect to specify security sandboxes and other options that allow or deny access. You can set different security levels and multiple sandboxes for networking and specific files and directories.</p>
<h6 id="section-2">What can be controlled</h6>
<p>The <a href="#secure">secure</a> function gives you control over policies for:</p>
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
<p>A list of these for your current release can always be obtained with the line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure query</code></pre></div>
<p>(Which will also show their current policy settings.)</p>
<h6 id="section-3">Usage</h6>
<fieldset class="fset"><legend>R3 ASK not available</legend>
<p>In current releases of R3, the ASK option is not available. Use either THROW or QUIT instead.</p>
</fieldset>
<h7 id="section-4">The main argument</h7>
<p>The argument to the <a href="#secure">secure</a> function can be a word or a block.</p>
<table border="0" cellpadding="5" cellspacing="1" bgcolor="#d0d0e0" class="doctable">
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>word</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">a general, top-level action such as setting global security levels to allow or deny all access. It can also be used to query the current security policies.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>block</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">specify separate security policies for files, directories, networking, extensions, debugging, and other features.
</td></tr>
</table>
<h7 id="section-5">Argument as a word</h7>
<p>If the argument is a word, it can be:</p>
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
<p>For example, developers often type:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure none</code></pre></div>
<p>to disable all security when developing new programs. <b>However, use this with care. Do not run (or <a href="#do">do</a>) any programs other than those that you trust.</b></p>
<p>Another example is:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure quit</code></pre></div>
<p>the program will quit immediately if any security violation occurs. Of course, this is a little extreme, and you won't get far. You'll want to specify a block for greater control. See the next section.</p>
<h7 id="section-6">Argument as a block</h7>
<p>To provide more detailed security, use a block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure [
    net quit
    file ask
    %./ allow
]</code></pre></div>
<p>This block will:</p>
<ul>
<li>disable networking (force a quit if attempted)</li>
<li>ask for user approval for all file access, except:</li>
<li>allow access to the local directory</li>
</ul>
<p>As you can see, the security dialect consists of a block of paired values. The first value in the pair specifies what is being secured (file or net), and the second value specifies the level of security (allow, ask, throw, quit). The second value can also be a block to further specify read and write security.</p>
<h6 id="section-7">Security policies</h6>
<p>The security policies are:</p>
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
<p>For example, to allow all network access, but to quit on any file access:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure [
    net allow ;allows any net access
    file quit ;any file access will cause the program to quit
]</code></pre></div>
<p>If a block is used instead of a security level word, it can contain pairs of security levels and access types. This lets you specify a greater level of detail about the security you require.</p>
<h6 id="section-8">Access types</h6>
<p>The access types allowed are:</p>
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
<p>The pairs are processed in the order they appear, with later pairs modifying the effect of earlier pairs. This permits setting one type of access without explicitly setting all others. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure [
    net allow
    file [
        ask all
        allow read
        quit execute
    ]
]</code></pre></div>
<p>The above sets the security level to ask for all operations except for reading (which is allowed).</p>
<p>This technique can also be used for individual files and directories. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure [
    net allow
    file quit
    %source/ [ask read]
    %object/ [allow all]
]</code></pre></div>
<p>will prompt the user if an attempt is made to read the %source directory, but it will allow all operations on the %object directory. Otherwise, it uses the default (quit).</p>
<p>If no security access level is specified for either network or file access, it defaults to ASK. The current settings will not be modified if an error occurs parsing the security block argument.</p>
<h6 id="section-9">Querying security</h6>
<p>The <a href="#secure">secure</a> function returns the prior security settings before the new settings were made. This is a block with the global network and file settings followed by file or directory settings. The word query can also be used to obtain the current security settings without modifying them:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe secure query
[file allow net allow ...]</code></pre></div>
<p>Using query, you can modify the current security level by querying the current settings, modifying them, then using the secure function to set the new values.</p>
<h6 id="section-10">Securing security</h6>
<p>Once you have your security policies set, it's a good idea to secure the <a href="#secure">secure</a> function to prevent modifications. This is done in the same way as other policies.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure [secure quit]</code></pre></div>
<p>will cause your program to immediately quit if any other code tries to modify the security policies.</p>
<h6 id="section-11">User confirmation</h6>
<p>Note that lowering the security level produces a change security settings requestor to the user. The exception is when the REBOL session is running in quiet mode which will, instead, terminate the REBOL session. No request is generated when security levels are raised. Note that the security request includes an option to allow all access for the remainder of the scripts processing.</p>
<h6 id="section-12">Controlling security at startup</h6>
<p>To disable all security on startup, you can start REBOL with:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">rebol -s args...</code></pre></div>
<p>This policy allows open access for everything.</p>
<p>You can also use the --secure argument to specify any other default security level on startup.</p>
<h6 id="section-13">Limiting evaluation (quota)</h6>
<p>You can set <a href="#secure">secure</a> to limit interpreter evaluation. This feature allows you to restrict server scripts (such as CGI) to a specific evaluation length to prevent runaway programs.</p>
<p>This example sets the limit to 50000 cycles, after which the program will immediately quit (the default behavior):</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; secure [eval 50000]
&gt;&gt; loop 100000 [next "test"]
&lt;quit&gt;</code></pre></div>
<p>Also, for debugging you can use the more detailed form of <w>secure:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; secure [eval [throw 50000]]
&gt;&gt; loop 100000 [next "test"]
** Access error: security violation: eval
** Where: loop
** Near: loop 100000 [next "test"]</code></pre></div>
<p>You can continue your debugging at the console, but secure will trap again on the next evaluation sample. To disable that behavior:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; secure [eval allow]</code></pre></div>
<p>When tuning your program, to determine how many cycles your code needs, you can use:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; stats/evals
== 50403</code></pre></div>
<p>However, add to that number a good margin of error for special conditions within your code. In many cases you will want to make it ten or twenty times larger, just to be sure.</p>
<p>A few notes:</p>
<ul>
<li>The maximum evaluation limit is 9e18.</li>
<li>The evaluation limit can be set only once and cannot be reset. However, for debugging after an eval THROW exception, you can use <w>secure to disable the trap (use: [eval allow]).</li>
<li>The limit is approximate. It is sampled at regular intervals (to avoid slowing down evaluation.) The sampling period is 10000 cycles, so that is the resolution of the limit. For example, if you set the limit to 1, it won't trap an error until 10000.</li>
<li>If the program quits, the exit code is set to 101, the same as any security termination; however, we may want to use special codes to indicate the reason for the quit.</li>
<li>Some types of loops are not yet checked, but we will add them. For example, PARSE cycles are not yet counted.</li>
<li>Time limits are not yet supported, but may be added in the future. However, the cycle limit is better for most cases, because it is CPU speed independent.</li>
</ul>
<h6 id="section-14">Limiting memory</h6>
<p>You can set <a href="#secure">secure</a> to limit the amount of memory allocated by your program. This feature allows you to restrict server scripts (such as CGI) to a specific memory usage to prevent runaway programs.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; secure [memory 2'000'000]
&gt;&gt; strings: []
&gt;&gt; loop 100000 [append strings make string! 100'000]
&lt;quit&gt;</code></pre></div>
<p>This feature works the same way as the evaluation limit described above. Read that section for more details.</p>
<p>To determine how much memory your program has currently used:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; stats
== 913616</code></pre></div>
<p>The number is shown in bytes.</p>
<p>In addition, it should be noted that the memory limit applies to actual memory consumed. Due to automatic memory allocation (garbage collection) it is possible for a program to run a indefinite amount of time on a specific amount of memory.</p>
<p>The memory limit can be set only once and cannot be reset. However, for debugging after an eval THROW exception, you can use <w>secure to disable the trap:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">secure [memory allow]</code></pre></div>

```
------------------------------------------------------------------
## SELECT
[[ find switch ]]

```html

<p>Similar to the <a href="#find">find</a> function, but returns the next value
in the series rather than the position of the match.
Returns NONE if search failed.</p>
<p>The /only refinement is evaluated for a block argument 
and is ignored if the argument is a string.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [red 123 green 456 blue 789]
print select blk 'red
123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">weather: [
    "Ukiah"      [clear 78 wind west at 5 MPH]
    "Santa Rosa" [overcast 65 wind north at 10 MPH]
    "Eureka"     [rain 62 wind north at 15 MPH]
]
probe select weather "Eureka"
[rain 62 wind north at 15 MPH]</code></pre></div>

```
------------------------------------------------------------------
## SELFLESS?
------------------------------------------------------------------
## SERIES?
[[ type? string? email? file? url? issue? tuple? block? paren? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print series? "string"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print series? [1 2 3]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print series? 1234
false</code></pre></div>

```
------------------------------------------------------------------
## SET
[[ get in value? unset protect unprotect ]]

```html

<p>If the first argument is a block of words and the value
is not a block, all of the words in the block will be
set to the specified value. If the value is a block,
then each of the words in the first block will be set to
the respective values in the second block. If there are
not enough values in the second block, the remaining
words will be set to NONE</p>
<p>The /ANY refinement allows words to be set any datatype
including those such as UNSET! that are not normally
allowed. This is useful in situations where all values
must be handled.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">set 'test 1234
print test
1234</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">set [a b] 123
print a
123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print b
123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">set [d e] [1 2]
print d
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print e
2</code></pre></div>
<p>You can also use <span class="datatype">set-word!</span> within the <a href="#set">set</a> function:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">set [a: b:] [1 2]</code></pre></div>
<p>This is useful if you use the <a href="#funct">funct</a> function, which auto-detects local variables that use the set-word notation.</p>

```
------------------------------------------------------------------
## SET-ENV
------------------------------------------------------------------
## SET-PATH?
[[ make ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if set-path? first [a/b/c: 10] [print "Path found"]
Path found</code></pre></div>

```
------------------------------------------------------------------
## SET-SCHEME
------------------------------------------------------------------
## SET-USER
------------------------------------------------------------------
## SET-WORD?

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if set-word? first [word: 10] [print "it will be set"]
it will be set</code></pre></div>

```
------------------------------------------------------------------
## SEVENTH
[[ first second third pick ]]

```html

<p>See the FIRST function for examples.</p>
<p>An error will occur if no value is found. Use the PICK function to avoid this error.</p>

```
------------------------------------------------------------------
## SHIFT

```html

<p>Supports right or left bits shifts on integers.</p>

```
------------------------------------------------------------------
## SHIFT-LEFT
------------------------------------------------------------------
## SHIFT-RIGHT
------------------------------------------------------------------
## SHOW

```html

<p>This is a low-level View function that is used to display or
update a face. The face being displayed must be part of a
pane that is part of a window display.</p>
<p>The SHOW function is called frequently to update the display of
a face after changes have been made.  If the face contains a
pane of sub-faces, all of those faces will be redisplayed.</p>
<p>If you attempt to show a face and nothing happens, make sure
that the face is part of the display hierarchy.  That is, the
face must be present in the pane list of another face that is
being displayed.</p>
<p>For example, if you modify any of the attributes of a face,
you call the SHOW function to display the change.  The code
below shows this:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">view layout [
    bx: box 100x24 black
    button "Red" [bx/color: red  show bx]
    button "Green" [bx/color: green  show bx]
]</code></pre></div>
<p>The example below creates a layout face and then removes faces
from its pane.  The SHOW function is called each time to refresh
the face and display what has happened.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">out: layout [
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
unview</code></pre></div>

```
------------------------------------------------------------------
## SHOW-SOFT-KEYBOARD
------------------------------------------------------------------
## SIGN?
[[ abs negate ]]

```html

<p>The SIGN? function returns a positive, zero, or negative integer
based on the sign of its argument.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print sign? 1000
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print sign? 0
0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print sign? -1000
-1</code></pre></div>
<p>The sign is returned as an integer to allow it to be used
as a multiplication term within an expression:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">val: -5
new: 2000 * sign? val
print new
-2000</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">size: 20
num: -30
if size &gt; 10 [xy: 10x20 * sign? num]
print xy
-10x-20</code></pre></div>

```
------------------------------------------------------------------
## SIN
------------------------------------------------------------------
## SINE
[[ arccosine arcsine arctangent cosine tangent ]]

```html

<p>Ratio between the length of the opposite side to the
length of the hypotenuse of a right triangle.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print sine 90
1.0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print (sine 45) = (cosine 45)
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print sine/radians pi
0.0</code></pre></div>

```
------------------------------------------------------------------
## SINGLE?
------------------------------------------------------------------
## SIXTH
[[ first second third pick ]]

```html

<p>See the FIRST function for examples.</p>
<p>An error will occur if no value is found. Use the PICK function to avoid this error.</p>

```
------------------------------------------------------------------
## SIZE?
[[ modified? exists? ]]

```html

<p>If the file or URL is a directory, it returns the number
of entries in the directory.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print size? %file.txt
none</code></pre></div>

```
------------------------------------------------------------------
## SKIP
[[ at index? next back ]]

```html

<p>For example, SKIP series 1 is the same as NEXT. If skip
attempts to move beyond the head or tail it will be
stopped at the head or tail.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "REBOL"
print skip str 3
OL</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [11 22 33 44 55]
print skip blk 3
44 55</code></pre></div>

```
------------------------------------------------------------------
## SORT
[[ append change clear insert remove ]]

```html

<p>Sorting will modify any type of <a href="/r3/docs/concepts/series.html" class="con">series</a> passed as the argument:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [799 34 12 934 -24 0]
sort blk
print blk
-24 0 12 34 799 934</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print sort "dbeca"
"abcde"</code></pre></div>
<p>Normally sorting is not sensitive to character cases:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">sort ["Fred" "fred" "FRED"]
["fred" "FRED" "Fred"]</code></pre></div>
<p>But you can make it sensitive with the /CASE refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">sort/case ["Fred" "fred" "FRED"]
["FRED" "Fred" "fred"]</code></pre></div>
<p class="need">Editor note: Sort bug here causes camel-case strings to be sorted incorrectly.<p>
<p>When using the /SKIP refinement, you can treat the series as a set of records of a fixed size. Here we sort by a "name" column, while "age" is skipped:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">name-ages: [
    "Larry" 45
    "Curly" 50
    "Mo" 42
]
print sort/skip name-ages 2
Curly 50 Larry 45 Mo 42</code></pre></div>
<p>A /COMPARE function can be specified to perform the comparison. This allows you to change the ordering of the SORT:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">names: [
    "Larry"
    "Curly"
    "Mo"
]
print sort/compare names func [a b] [a &lt; b]
Curly Larry Mo</code></pre></div>
<p>The /ALL refinement will force the entire record to be passed as a series to the compare function. This is useful if you need to compare one or more fields of a record while also doing a skip operation.</p>
<p class="need">Editor note: Need a good working example. This may not be possible until remaining SORT bugs are fixed.<p>
<p>When sorting <span class="datatype">pair!</span> data (points and area sizes), the y coordinate is dominant. This is preferred to support the y sorting used by various graphics algorithms.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe sort [1x2 2x1 0x0 1x0 0x1 1x1]
[0x0 1x0 0x1 1x1 2x1 1x2]</code></pre></div>

```
------------------------------------------------------------------
## SOURCE
[[ what help ? ?? trace ]]

```html

<p>The <a href="#source">source</a> function displays the source code for REBOL defined functions.</p>
<p>For example, type:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">source join</code></pre></div>
<p>The source to the <a href="#join">join</a> function will be returned:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">join: make function! [[
    "Concatenates values."
    value "Base value"
    rest "Value or block of values"
][
    value: either series? :value [copy value] [form :value]
    repend value :rest
]]</code></pre></div>
<p>REBOL defined functions include the mezzanine functions (built-in interpreted functions) and user defined functions. Native functions have no source to display.</p>

```
------------------------------------------------------------------
## SPEC-OF
[[ body-of reflect title-of types-of values-of words-of ]]

```html

<p>Description is needed.</p>

```
------------------------------------------------------------------
## SPEED?
------------------------------------------------------------------
## SPLIT
[[ extract parse ]]

```html

<p>The <a href="#split">split</a> function is used to divide a <a href="/r3/docs/concepts/series.html" class="con">series</a> into subcomponents.
It provides several ways to specify how you want the split done.</p>
<h7 id="section-2">Split into equal segments:</h7>
<p>Given an integer as the dlm parameter, <a href="#split">split</a> will break the series
up into pieces of that size.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split "1234567812345678" 4
["1234" "5678" "1234" "5678"]
["1234" "5678" "1234" "5678"]</code></pre></div>
<p>If the series can't be evenly split, the last value will be shorter.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split "1234567812345678" 3
["123" "456" "781" "234" "567" "8"]
["123" "456" "781" "234" "567" "8"]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split "1234567812345678" 5
["12345" "67812" "34567" "8"]
["12345" "67812" "34567" "8"]</code></pre></div>
<h7 id="section-3">Split into N segments:</h7>
<p>Given an integer as dlm, and using the /into refinement, it breaks
the series into n pieces, rather than pieces of length n.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split/into [1 2 3 4 5 6] 2
[[1 2 3] [4 5 6]]
[[1 2 3] [4 5 6]]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split/into "1234567812345678" 2
["12345678" "12345678"]
["12345678" "12345678"]</code></pre></div>
<p>If the series can't be evenly split, the last value will be longer.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split/into "1234567812345678" 3
["12345" "67812" "345678"]
["12345" "67812" "345678"]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split/into "1234567812345678" 5
["123" "456" "781" "234" "5678"]
["123" "456" "781" "234" "5678"]</code></pre></div>
<h7 id="section-4">Split into uneven segments:</h7>
<p>If dlm is a block containing only integer values, those values 
determine the size of each piece returned. That is, each piece
can be a different size.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split [1 2 3 4 5 6] [2 1 3]
[[1 2] [3] [4 5 6]]
[[1 2] [3] [4 5 6]]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split "1234567812345678" [4 4 2 2 1 1 1 1]
["1234" "5678" "12" "34" "5" "6" "7" "8"]
["1234" "5678" "12" "34" "5" "6" "7" "8"]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split first [(1 2 3 4 5 6 7 8 9)] 3
[[1 2 3] [4 5 6] [7 8 9]]
[(1 2 3) (4 5 6) (7 8 9)]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split #{0102030405060708090A} [4 3 1 2]
[#{01020304} #{050607} #{08} #{090A}]
[#{01020304} #{050607} #{08} #{090A}]</code></pre></div>
<p>If the total of the dlm sizes is less than the length of the series,
the extra data will be ignored.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split [1 2 3 4 5 6] [2 1]
[[1 2] [3]]
[[1 2] [3]]</code></pre></div>
<p>If you have extra dlm sizes after the series data is exhausted, you
will get empty values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split [1 2 3 4 5 6] [2 1 3 5]
[[1 2] [3] [4 5 6] []]
[[1 2] [3] [4 5 6] []]</code></pre></div>
<p>If the last dlm size would return more data than the series contains,
it returns all the remaining series data, and no more.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split [1 2 3 4 5 6] [2 1 6]
[[1 2] [3] [4 5 6]]
[[1 2] [3] [4 5 6]]</code></pre></div>
<p>Negative values can be used to skip in the series without returning
that part:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split [1 2 3 4 5 6] [2 -2 2]
[[1 2] [5 6]]
[[1 2] [5 6]]</code></pre></div>
<h7 id="section-5">Simple delimiter splitting:</h7>
<p>Char or any-string values can be used for simple splitting, much as
you would with <a href="#[bad-link:functions/parseall.txt]">[bad-link:functions/parseall.txt]</a>, but with different behavior for strings
that have embedded quotes.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split "abc,de,fghi,jk" #","
["abc" "de" "fghi" "j"]
["abc" "de" "fghi" "jk"]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split "abc&lt;br&gt;de&lt;br&gt;fghi&lt;br&gt;jk" &lt;br&gt;
["abc" "de" "fghi" "j"]
["abc" "de" "fghi" "jk"]</code></pre></div>
<p>If you want to split at more than one character value, you can use
a <a href="#[bad-link:functions/charsetbitset.txt]">[bad-link:functions/charsetbitset.txt]</a>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split "abc|de/fghi:jk" charset "|/:"
["abc" "de" "fghi" "j"]
["abc" "de" "fghi" "jk"]</code></pre></div>
<p>Note that for greater control, you can use simple <a href="#parse">parse</a> rules:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split "abc     de fghi  jk" [some #" "]
["abc" "de" "fghi" "j"]
["abc" "de" "fghi" "jk"]</code></pre></div>

```
------------------------------------------------------------------
## SPLIT-LINES
------------------------------------------------------------------
## SPLIT-PATH
[[ clean-path suffix? ]]

```html

<p>Returns a block consisting of two elements, the path and the file.
Can be used on URLs and files alike.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe split-path %tests/math/add.r
[%tests/math/ %add.r]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">set [path file] split-path http://www.rebol.com/graphics/logo.gif
print path
http://www.rebol.com/graphics/</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print file
logo.gif</code></pre></div>

```
------------------------------------------------------------------
## SQRT
------------------------------------------------------------------
## SQUARE-ROOT
[[ exp log-10 log-2 log-e power ]]

```html

<p>Returns the square-root of the number provided. If the
number is negative, an error will occur (which you can
trap with the TRY function).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print square-root 4
2.0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print square-root 2
1.414213562373095</code></pre></div>

```
------------------------------------------------------------------
## STACK

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## STATS
[[ help trace ]]

```html

<p>The STATS function returns a wide range of useful REBOL system
statistics, including information about memory usage, interpreter
cycles, and more.</p>
<p>If no refinement is provide, STATS returns the amount of memory
that it is using. This value must be computed from tables.</p>
<p>The /pools refinement returns information about the memory pools
that REBOL uses for managing its memory.</p>
<p>The /types refinement provides a summary of the number of each
datatype currently allocated by the system.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">foreach [type num] stats/types [
    print [type num]
]</code></pre></div>
<p>The /series shows the number of series values, both string and
block oriented, as free space, etc.</p>
<p>The /frames provides the number of context frames used for objects
and functions.</p>
<p>The /recycle option summarizes garbage collection information.</p>
<p>The /evals provides counters for the number of interpreter cycles,
functions invoked, and blocks evaluated.</p>
<p>The /clear refinement can be used with the /evals refinement to clear
its counters.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">stats/evals/clear
loop 100 [print "hello"]
print stats/evals</code></pre></div>

```
------------------------------------------------------------------
## STRICT-EQUAL?
[[ == = <> strict-not-equal? ]]

```html

<p>Strict equality requires the values to not differ by
datatype (so 1 would not be equal to 1.0) nor by
character casing (so "abc" would not be equal to "ABC").</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print strict-equal? 123 123
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print strict-equal? "abc" "ABC"
false</code></pre></div>

```
------------------------------------------------------------------
## STRICT-NOT-EQUAL?
[[ !== <> = == ]]

```html

<p>Returns FALSE if the values neither differ by datatype
(so 1 would not be equal to 1.0) nor by character casing
(so "abc" would not be equal to "ABC").</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print strict-not-equal? 124 123
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print strict-not-equal? 12-sep-98 10:30
true</code></pre></div>

```
------------------------------------------------------------------
## STRING?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print string? "with all things considered"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print string? 123
false</code></pre></div>

```
------------------------------------------------------------------
## STRUCT?

```html

<p>Returns TRUE if the value is a STRUCT datatype.</p>

```
------------------------------------------------------------------
## SU
------------------------------------------------------------------
## SUBTRACT
[[ - + add absolute ]]

```html

<p>Note: The <a href="#+">+</a> operator is a special infix form for this function.</p>
<p>Many different datatypes support subtraction. Here are just a few:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print subtract 123 1
122</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print subtract 1.2.3.4 1.0.3.0
0.2.0.4</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print subtract 12:00 11:00
1:00</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print subtract 1-Jan-2000 1
31-Dec-1999</code></pre></div>
<p>When subtracting values of different datatypes, the values must be compatible. Auto conversion of the values will occur into the datatype that has the most expansive representation. For example an integer subtracted from a decimal will produce a decimal.</p>

```
------------------------------------------------------------------
## SUFFIX?
[[ find split-path ]]

```html

<p>The SUFFIX? function can be used to obtain the file extention
(e.g. .exe, .txt, .jpg, etc.) that is part of a filename.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print suffix? %document.txt
.txt</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print suffix? %program.exe
.exe</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print suffix? %dir/path/doc.txt
.txt</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print suffix? %file.type.r
.r</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print suffix? http://www.rebol.com/doc.txt
.txt</code></pre></div>
<p>If there is no suffix, a NONE is returned:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print suffix? %filename
none</code></pre></div>
<p>The suffix function can be used with any string datatype, but always
returns a FILE! datatype if the suffix was found.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print type? suffix? %file.txt
file!</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print type? suffix? "file.txt"
file!</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print type? suffix? http://www.rebol.com/file.txt
file!</code></pre></div>
<p>This was done to allow code such as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">url: http://www.rebol.com/docs.html
if find [%.txt %.html %.htm %.doc] suffix? url [
    print [url "is a document file."]
]
http://www.rebol.com/docs.html is a document file.</code></pre></div>

```
------------------------------------------------------------------
## SUM
------------------------------------------------------------------
## SUPPLEMENT
------------------------------------------------------------------
## SWAP

```html

<p>Description is needed.</p>

```
------------------------------------------------------------------
## SWAP-ENDIAN
------------------------------------------------------------------
## SWITCH
[[ case select find ]]

```html

<p>The <a href="#switch">switch</a> function selects the block for a given choice and evaluates it.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">switch 22 [
    11 [print "here"]
    22 [print "there"]
]
there</code></pre></div>
<p>This function is equivalent to writing a <a href="#select">select</a> like this:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do select [
    11 [print "here"]
    22 [print "there"]
] 22</code></pre></div>
<h6 id="section-2">Variety of Datatypes</h6>
<p>The selection choices can be of any datatype. Here are some examples:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">file: %user.r
switch file [
    %user.r [print "here"]
    %rebol.r [print "everywhere"]
    %file.r [print "there"]
]
here</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">url: ftp://ftp.rebol.org
switch url [  
    http://www.rebol.com [print "here"]
    http://www.cnet.com [print "there"]
    ftp://ftp.rebol.org [print "everywhere"]
]
everywhere</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">tag: &lt;title&gt;
print switch html [
    &lt;pre&gt;   ["preformatted text"]
    &lt;title&gt; ["page title"]
    &lt;li&gt;    ["bulleted list item"]
]
page title</code></pre></div>
<h6 id="section-3">Cases Not Evaluated</h6>
<p>It's very important to note that the choices are not evaluated (think of them as constants.) This allows the choices to be words, as shown below. If you need evaluation of the case values, use the <a href="#case">case</a> function instead.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">person: 'mom
switch person [
    dad [print "here"]
    mom [print "there"]
    kid [print "everywhere"]
]
there</code></pre></div>
<p>This most often becomes important when you want to <a href="#switch">switch</a> based on a datatype value. You must be sure to use <a href="#type?">type?</a> with a /word refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">val: 123
switch type?/word [
    integer! [print "it's integer"]
    decimal! [print "it's decimal"]
    date! [print "it's a date"]
]
it's integer</code></pre></div>
<p>Here the <a href="#type?">type?</a> function returns the word (name) of the <span class="datatype">datatype!</span>, not the datatype's type value.</p>
<p>Another possible approach is to evaluate the block of cases. For the example above:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">switch type? reduce [
    integer! [print "it's integer"]
    decimal! [print "it's decimal"]
    date! [print "it's a date"]
]
it's integer</code></pre></div>
<p>This works because words like integer! are set to their actual datatype values.</p>
<h6 id="section-4">Default Case</h6>
<p>You can use the /default refinement to specify a default case.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">time: 14:00
switch/default time [
     8:00 [send wendy@domain.dom "Hey, get up"]
    12:30 [send cindy@dom.dom "Join me for lunch."]
    16:00 [send group@every.dom "Dinner anyone?"]
][
    print ["Nothing done at" time]
]
Nothing done at 14:00</code></pre></div>
<h6 id="section-5">Return Value</h6>
<p>The <a href="#switch">switch</a> function returns the value of the case block that it evaluated, or none otherwise.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">car: pick [Ford Chevy Dodge] random 3
print switch car [
    Ford [351 * 1.4]
    Chevy [454 * 5.3]
    Dodge [154 * 3.5]
]
491.4</code></pre></div>
<h6 id="section-6">Common Problems</h6>
<p>The most common problem is to assume that <a href="#switch">switch</a> evaluates your case values. It does not. This kind of code does not work:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">item1: 100
item2: 200
n: 100
switch n [
    item1 [...]
    item2 [...]
]</code></pre></div>
<p>However, you can <a href="#reduce">reduce</a> the case block to its actual values:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">switch n reduce [
    item1 [...]
    item2 [...]
]</code></pre></div>

```
------------------------------------------------------------------
## TAG?

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print tag? &lt;title&gt;
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print tag? "title"
false</code></pre></div>

```
------------------------------------------------------------------
## TAIL
[[ tail? head head? ]]

```html

<p>Access to the tail allows insertion at the end of a
series (because insertion always occurs before the
specified element).</p>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: copy [11 22 33]
insert tail blk [44 55 66]
print blk
11 22 33 44 55 66</code></pre></div>

```
------------------------------------------------------------------
## TAIL?
[[ empty? tail head head? ]]

```html

<p>This function is the best way to detect the end of a
series while moving through it.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print tail? "string"
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print tail? tail "string"
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "Ok"
print tail? tail str
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print tail? next next str
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">items: [oven sink stove blender]
while [not tail? items] [
    print first items
    items: next items
]
blender</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">blk: [1 2]
print tail? tail blk
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print tail? next next blk
true</code></pre></div>

```
------------------------------------------------------------------
## TAKE

```html

<p>The <a href="#take">take</a> function removes a value from a series and returns it as the result. It's a useful combination of <a href="#pick">pick</a> with <a href="#remove">remove</a>.</p>
<p>For example, used on blocks:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: [a b c d]
take data
a</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe data
[b c d]</code></pre></div>
<p>Used on strings:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "abcd"
take str
#"a"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe str
"bcd"</code></pre></div>
<h6 id="section-2">For Queues and Stacks</h6>
<p>The <a href="#take">take</a> function is quite useful for making queues and stacks.</p>
<p>An example queue is implemented as first in first out (FIFO) block. New values are added with <a href="#append">append</a> and removed with <a href="#take">take</a>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: make block! 10
append data 1
append data 2
append data 3
take data
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">take data
2</code></pre></div>
<p>An example stack is implemented as last in first out (LIFO). The difference is to use the /last refinement with <a href="#take">take</a>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: make block! 10
append data 1
append data 2
append data 3
take/last data
3</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">take/last data
2</code></pre></div>
<p>The data queued and stacked above can be any REBOL values, including string, functions, objects or whatever.</p>

```
------------------------------------------------------------------
## TAN
------------------------------------------------------------------
## TANGENT
[[ arccosine arcsine arctangent cosine tangent ]]

```html

<p>Ratio between the length of the opposite side to
the length of the adjacent side of a right triangle.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print tangent 30
0.5773502691896257</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print tangent/radians 2 * pi
0.0</code></pre></div>

```
------------------------------------------------------------------
## TASK

```html

<p>Description is needed.</p>

```
------------------------------------------------------------------
## TASK?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TENTH
[[ first second third pick ]]

```html

<p>See the FIRST function for examples.</p>
<p>An error will occur if no value is found. Use the PICK function to avoid this error.</p>

```
------------------------------------------------------------------
## THIRD
[[ first second fourth fifth pick ]]

```html

<p>An error will occur if no value is found. Use the PICK
function to avoid this error.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print third "REBOL"
B</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print third [11 22 33 44 55 66]
33</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print third 12-jun-1999
12</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print third 199.4.80.1
80</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print third 12:34:56.78
56.78</code></pre></div>

```
------------------------------------------------------------------
## THROW
[[ catch return exit ]]

```html

<p>CATCH and THROW go together. They provide a method of
exiting from a block without evaluating the rest of the
block. To use it, provide CATCH with a block to
evaluate. If within that block a THROW is evaluated,
the script will return from the CATCH at that point. The
result of the CATCH will be the value that was passed as
the argument to the THROW. When using multiple CATCH
functions, provide them with a name to identify which
one will CATCH which THROW.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print catch [
    if exists? %file.txt [throw "Doc file!"]
]
none</code></pre></div>

```
------------------------------------------------------------------
## TIME?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print time? 12:00
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print time? 123
false</code></pre></div>

```
------------------------------------------------------------------
## TINT
------------------------------------------------------------------
## TITLE-OF
[[ body-of reflect spec-of types-of values-of words-of ]]

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO
[[ make ]]

```html

<p>Every datatype provides a TO method to allow conversions from
other datatypes. The to-binary, to-block, and all other to-
functions are mezzanine functions that are based on this TO
function.</p>
<p>Here are a few examples:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to file! "test.r"
%test.r</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to path! [a b c]
a/b/c</code></pre></div>
<p>The TO function lets the target datatype be specified as an
argument, allowing you to write code such as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">flag: true
value: to either flag [integer!][decimal!] "123"
print value
123</code></pre></div>
<p>The conversions that are allowed depend on the specific
datatype. Some datatypes allow special conversions, such as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to integer! false
0</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print to integer! true
1</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print to logic! 1
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print to time! 600  ; # of seconds
0:10</code></pre></div>

```
------------------------------------------------------------------
## TO-BINARY
[[ to ]]

```html

<p>Returns a binary! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-binary "123456"
#{313233343536}</code></pre></div>
<p>Notice, that the binary returned is not how the "actual storage" in computer memory looks. Instead, the bits are in "network order", which is, by convention, big endian:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">to-binary 1
#{0000000000000001}</code></pre></div>

```
------------------------------------------------------------------
## TO-BITSET
[[ to ]]

```html

<p>Returns a bitset! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-bitset [#"a" - #"z" #"A" - #"Z"]
make bitset! #{00000000000000007FFFFFE07FFFFFE0}</code></pre></div>

```
------------------------------------------------------------------
## TO-BLOCK
[[ to ]]

```html

<p>Returns a block! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-block "123 10:30"
123 10:30</code></pre></div>

```
------------------------------------------------------------------
## TO-CHAR
[[ to ]]

```html

<p>Returns a char! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-char "a"
a</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-char 65
A</code></pre></div>

```
------------------------------------------------------------------
## TO-CLOSURE

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-COMMAND
------------------------------------------------------------------
## TO-DATATYPE
[[ make to ]]

```html

<p>Returns a datatype! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-datatype "REBOL"</code></pre></div>

```
------------------------------------------------------------------
## TO-DATE
[[ to ]]

```html

<p>Returns a date! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-date "12-April-1999"
12-Apr-1999</code></pre></div>

```
------------------------------------------------------------------
## TO-DECIMAL
[[ to ]]

```html

<p>Returns a decimal! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-decimal 12.3
12.3</code></pre></div>

```
------------------------------------------------------------------
## TO-DEGREES
------------------------------------------------------------------
## TO-EMAIL
[[ to ]]

```html

<p>Returns an email! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-email [luke rebol.com]
lukerebol.com</code></pre></div>

```
------------------------------------------------------------------
## TO-ERROR
[[ make to ]]

```html

<p>Returns an error! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe disarm try [to-error "Oops! My error."]
make object! [</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">code: 308
type: 'Script
id: 'cannot-use
arg1: 'to
arg2: unset!
arg3: none
near: [to error! :value]
where: [to to-error try do attempt if emit parse foreach catch if either if do begin do]</code></pre></div>
<p>]</p>
<p>Note that this differs from TO and MAKE in that you
have to wrap the call in a TRY block to catch the
error it makes.</p>

```
------------------------------------------------------------------
## TO-EVENT

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-FILE
[[ to ]]

```html

<p>Returns a file! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-file ask "What file would you like to create? "
test</code></pre></div>

```
------------------------------------------------------------------
## TO-FUNCTION

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-GET-PATH

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-GET-WORD
[[ to ]]

```html

<p>Returns a get-word! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-get-word "test"
:test</code></pre></div>

```
------------------------------------------------------------------
## TO-GOB

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-HASH
------------------------------------------------------------------
## TO-HEX
[[ to-integer ]]

```html

<p>The TO-HEX function provides an easy way to convert an integer to
a hexidecimal value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-hex 123
000000000000007B</code></pre></div>
<p>The value returned is a string of the ISSUE datatype (not the BINARY
datatype). This allows you to convert hex values back to integers:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-integer #7B
123</code></pre></div>
<p>Note: To convert HTML hex color values (like #80FF80) to REBOL
color values, it is easier to do the conversion to binary and
then use a base 16 encoding:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">to-html-color: func [color [tuple!]] [
    to-issue enbase/base to-binary color 16
]
print to-html-color 255.155.50
FF9B32</code></pre></div>
<p>The TO-ISSUE function is just used to add the # to it.</p>
<p>To convert from an HTML color back to a REBOL color tuple, you
can use this:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">to-rebol-color: func [color [issue!]] [
    to-tuple debase/base color 16
]
to-rebol-color #FF9B32</code></pre></div>
<p>If the HTML color value is a string, convert it to an issue first.
The function below will work for strings and issues:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">to-rebol-color2: func [color [string! issue!]] [
    if string? color [
        if find/match color "#" [color: next color]
        color: to-issue color
    ]
    to-tuple debase/base color 16
]
to-rebol-color2 "#FF9B32"</code></pre></div>

```
------------------------------------------------------------------
## TO-IDATE
------------------------------------------------------------------
## TO-IMAGE
[[ to ]]

```html

<p>This is a special conversion function that is used for
converting a FACE object (such as those created by the layout
function) into an image bitmap in memory.</p>
<p>For example, the code below converts the OUT layout to a bitmap
image, then writes it out as a PNG file:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">out: layout [
    h2 "Title"
    field
    button "Done"
]
image: to-image out
save/png %test-image.png image</code></pre></div>
<p>This function provides a useful way to save REBOL generated
images for use in other programs or web pages (which also allows
you to print the images). For example, you can display the image
above in a web browser with this code:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">write %test-page.html trim/auto {
    &lt;html&gt;&lt;body&gt;
    &lt;h2&gt;Image:&lt;/h2&gt;
    &lt;img src="test-image.png"&gt;
    &lt;/body&gt;&lt;/html&gt;
}
browse %test-page.html
write</code></pre></div>

```
------------------------------------------------------------------
## TO-INTEGER
[[ to to-hex ]]

```html

<p>Returns an integer! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-integer "123"
123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-integer 123.9
123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-integer #"A" ; convert to the character value
65</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-integer #102030 ; convert hex value (see to-hex for info)
1056816</code></pre></div>

```
------------------------------------------------------------------
## TO-ISSUE
[[ to to-hex ]]

```html

<p>Returns an issue! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-issue "1234-56-7890"
1234-56-7890</code></pre></div>
<p>To convert HTML RGB color values (that look like #000000), see
the to-hex function.</p>

```
------------------------------------------------------------------
## TO-ITIME
------------------------------------------------------------------
## TO-JSON
------------------------------------------------------------------
## TO-LIT-PATH
[[ to ]]

```html

<p>Returns a lit-path! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-lit-path [a b c]
'a/b/c</code></pre></div>

```
------------------------------------------------------------------
## TO-LIT-WORD
[[ to ]]

```html

<p>Returns a ilt-word! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-lit-word "test"
test</code></pre></div>

```
------------------------------------------------------------------
## TO-LOCAL-FILE
[[ to-rebol-file ]]

```html

<p>This function provides a way to convert standard, system
independent REBOL file formats into the file format used by
the local operating system.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-local-file %/c/temp
"c:\temp"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-local-file what-dir
"C:\REBOL\3.0\docs\scripts\"</code></pre></div>
<p>Note that the format of the file path depends on your local
system. Be careful how you use this function across systems.</p>

```
------------------------------------------------------------------
## TO-LOGIC
[[ to ]]

```html

<p>Returns a logic! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-logic 1
print to-logic 0
false</code></pre></div>

```
------------------------------------------------------------------
## TO-MAP

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-MODULE

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-MONEY
[[ to ]]

```html

<p>Returns a money! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-money 123.4
$123.4000000000000000</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-money [AUS 123.4]</code></pre></div>

```
------------------------------------------------------------------
## TO-OBJECT

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-PAIR
[[ to as-pair pair? ]]

```html

<p>Returns a pair! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-pair [120 50]

x: 100
y: 80
print to-pair reduce [x y]</code></pre></div>
<p>This last line is done so often that the AS-PAIR function was
created.</p>
<p>See the PAIR! word for more detail.</p>

```
------------------------------------------------------------------
## TO-PAREN
[[ to ]]

```html

<p>Returns a paren! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-paren "123 456"
123 456</code></pre></div>

```
------------------------------------------------------------------
## TO-PATH
[[ to ]]

```html

<p>Returns a path! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">colors: make object! [reds: ["maroon" "brick" "sunset"]]
p-reds: to-path [colors reds]
print form :p-reds
colors/reds</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print p-reds
colors/reds</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">insert tail p-reds "bright"
print colors/reds
maroon brick sunset</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print p-reds
colors/reds/"bright"</code></pre></div>

```
------------------------------------------------------------------
## TO-PERCENT

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-PORT
[[ make to ]]

```html

<p>Returns a port! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-port [scheme: 'checksum]</code></pre></div>

```
------------------------------------------------------------------
## TO-RADIANS
------------------------------------------------------------------
## TO-REAL-FILE
------------------------------------------------------------------
## TO-REBOL-FILE
[[ to-local-file ]]

```html

<p>This function provides a standard way to convert local operating
system files into REBOL's standard machine independent format.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-rebol-file "c:\temp"
%/c/temp</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-rebol-file "e:\program files\rebol"
%/e/program%20files/rebol</code></pre></div>
<p>Note that the format of the file path depends on your local
system. Be careful how you use this function across systems.</p>

```
------------------------------------------------------------------
## TO-REF
------------------------------------------------------------------
## TO-REFINEMENT
[[ to ]]

```html

<p>Returns a refinement! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-refinement 'REBOL
/REBOL</code></pre></div>

```
------------------------------------------------------------------
## TO-RELATIVE-FILE

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-SET-PATH
[[ to ]]

```html

<p>Returns a set-path! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">colors: make object! [blues: ["sky" "sea" "midnight"]]
ps-blues: to-set-path [colors blues]
print form :ps-blues
colors/blues:</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print ps-blues
colors/blues:</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">ps-blues compose [(ps-blues) "light"]
print colors/blues
sky sea midnight</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print ps-blues
colors/blues:</code></pre></div>

```
------------------------------------------------------------------
## TO-SET-WORD
[[ to ]]

```html

<p>Returns a set-word! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe to-set-word "test"
test:</code></pre></div>

```
------------------------------------------------------------------
## TO-STRING
[[ to ]]

```html

<p>Returns a string! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-string [123 456]
123456</code></pre></div>

```
------------------------------------------------------------------
## TO-TAG
[[ to ]]

```html

<p>Returns a tag! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-tag ";comment:"
&lt;;comment:&gt;</code></pre></div>

```
------------------------------------------------------------------
## TO-TIME
[[ to ]]

```html

<p>Returns a time! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-time 75
0:01:15</code></pre></div>
<p>Integer values are interpreted as a number of seconds.</p>
<p>A block may contain up to three values. The first two must be 
integers, and correspond to the hour and minute values. The
third value can be an integer or decimal value, and corresponds
to the number of seconds.</p>

```
------------------------------------------------------------------
## TO-TUPLE
[[ to to-hex ]]

```html

<p>Returns a tuple! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-tuple [12 34 56]
12.34.56</code></pre></div>
<p>To convert REBOL RGB color tuples to HTML hex color values, see
the to-hex function.</p>
<p>Tuples can have up to 10 segments.</p>

```
------------------------------------------------------------------
## TO-TYPESET

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-URL
[[ to ]]

```html

<p>Returns a url! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-url "info@rebol.com"
info@rebol.com</code></pre></div>

```
------------------------------------------------------------------
## TO-VALUE
------------------------------------------------------------------
## TO-VECTOR

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TO-WORD
[[ to ]]

```html

<p>Returns a word! value made from the given value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print to-word "test"
test</code></pre></div>

```
------------------------------------------------------------------
## TRACE
[[ echo probe stack ]]

```html

<p>The <a href="#trace">trace</a> lets you watch the evaluation of your script, expression by expression.</p>
<p>The three most common arguments to <a href="#trace">trace</a> are shown here:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">trace on   ; turn on trace
trace off  ; turn off trace
trace 5    ; turn on, but trace only 5 levels deep</code></pre></div>
<p>Once enabled, when you evaluate an expression, you will see each step as a single line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; print 123
 1: print : native! [value]
 2: 123
--&gt; print
123
&lt;-- print == unset!</code></pre></div>
<h6 id="section-2">Understanding the format</h6>
<p>The <a href="#trace">trace</a> format uses these formatting notations to indicate what your code is doing:</p>
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
<h7 id="section-3">Simple example</h7>
<p>To help understand the format, here's a description for each line in the earlier example:</p>
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
<h7 id="section-4">Larger example</h7>
<p>Here is a user defined function to compute the average of a block of numbers.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">ave: func [nums [block!] /local val][
    val: 0
    foreach num nums [val: val + num]
    val / length? nums
]</code></pre></div>
<p>Tracing the evaluation, you will see how each new level is indented and begins a new sequence of index numbers. Notice also the <a href="#foreach">foreach</a> loop.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; ave [1 2 3]
 1: ave : function! [nums /local val]
 2: [1 2 3]
--&gt; ave
     1: val:
     2: 0
     3: foreach : native! ['word data body]
     5: nums : [1 2 3]
     6: [val: val + num]
    --&gt; foreach
         1: val:
         2: val : 0
         3: + : op! [value1 value2]
         4: num : 1
        --&gt; +
        &lt;-- + == 1
         1: val:
         2: val : 1
         3: + : op! [value1 value2]
         4: num : 2
        --&gt; +
        &lt;-- + == 3
         1: val:
         2: val : 3
         3: + : op! [value1 value2]
         4: num : 3
        --&gt; +
        &lt;-- + == 6
    &lt;-- foreach == 6
     7: val : 6
     8: / : op! [value1 value2]
     9: length? : action! [series]
    10: nums : [1 2 3]
    --&gt; length?
    &lt;-- length? == 3
    --&gt; /
    &lt;-- / == 2
&lt;-- ave == 2
== 2</code></pre></div>
<h6 id="section-5">Minimizing the output</h6>
<p>At times the trace output will be a lot more than you want. The trick becomes how to cut it down without losing the information you need.. There are three methods:</p>
<ol>
<li>Specify a trace depth.</li>
<li>Locate the <a href="#trace">trace</a> on and off lines deeper within your code.</li>
<li>Trace only functions, not all values.</li>
<li>Use the backtrace option. (see more below)</li>
</ol>
<h7 id="section-6">Setting trace depth</h7>
<p>Using the example above, set the trace depth to 2, and run it again. You will see:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; trace 2
&gt;&gt; ave [1 2 3]
 1: ave : function! [nums /local val]
 2: [1 2 3]
--&gt; ave
     1: val:
     2: 0
     3: foreach : native! ['word data body]
     5: nums : [1 2 3]
     6: [val: val + num]
    --&gt; foreach
    &lt;-- foreach == 6
     7: val : 6
     8: / : op! [value1 value2]
     9: length? : action! [series]
    10: nums : [1 2 3]
    --&gt; length?
    &lt;-- length? == 3
    --&gt; /
    &lt;-- / == 2
&lt;-- ave == 2
== 2</code></pre></div>
<p>The output has been reduced. You no longer see the foreach loop operate.</p>
<h7 id="section-7">Locating trace within your code</h7>
<p>Most of the time you don't need to trace your entire program, just part of it. So, it is useful just to put <a href="#trace">trace</a> in your code where you need it.</p>
<p>Using the same example as above:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">ave: func [nums [block!] /local val][
    val: 0
    trace on
    foreach num nums [val: val + num]
    trace off
    val / length? nums
]</code></pre></div>
<p>You will now see:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; ave [1 2 3]
&lt;-- trace == unset!
 5: foreach : native! ['word data body]
 7: nums : [1 2 3]
 8: [val: val + num]
--&gt; foreach
     1: val:
     2: val : 0
     3: + : op! [value1 value2]
     4: num : 1
    --&gt; +
    &lt;-- + == 1
     1: val:
     2: val : 1
     3: + : op! [value1 value2]
     4: num : 2
    --&gt; +
    &lt;-- + == 3
     1: val:
     2: val : 3
     3: + : op! [value1 value2]
     4: num : 3
    --&gt; +
    &lt;-- + == 6
&lt;-- foreach == 6
 9: trace : native! [mode /back]
10: off : false
--&gt; trace
== 2</code></pre></div>
<h7 id="section-8">Tracing functions only</h7>
<p>With the /function refinement you can trace just function calls and their returns. The evaluation of each code block value is not shown, saving a few lines.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; trace/function on
&gt;&gt; ave [1 2 3]
    --&gt; ave [1 2 3] . .
        --&gt; foreach num [1 2 3] [val: val + num]
            --&gt; + 0 1
        &lt;-- + == 1
            --&gt; + 1 2
        &lt;-- + == 3
            --&gt; + 3 3
        &lt;-- + == 6
    &lt;-- foreach == 6
        --&gt; length? [1 2 3]
    &lt;-- length? == 3
        --&gt; / 6 3
    &lt;-- / == 2
&lt;-- ave == 2</code></pre></div>
<p>In this mode, the function call lines will show the arguments passed to the functions. (A dot is used to show NONE value slots, such as those for unused refinements or local variables.)</p>
<h6 id="section-9">Backtrace</h6>
<p>At times it is important to know what your code was doing immediately before a crash. In such cases, you don't want to see trace output until after the crash. That is the purpose of the /back refinement: to tell <a href="#trace">trace</a> to redirect its output to an internal buffer that you can examine later.</p>
<p>To enable backtrace:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; trace/back on</code></pre></div>
<p>Then, run your code. When your crash occurs, type:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; trace/back 20</code></pre></div>
<p>to see the last 20 lines (or however many lines you want to see.)</p>
<p>You can also modify your trace depth as you would normally. For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; trace/back on
&gt;&gt; trace 5</code></pre></div>
<p>will only trace down five levels of code.</p>
<p>When you are done with the backtrace, you can disable it with:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; trace/back off</code></pre></div>
<p>and that will also free memory used by the backtrace buffer.</p>
<p>To use backtrace with the /function refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; trace/back/function on</code></pre></div>
<p>This will also speed-up trace evaluation.</p>
<h7 id="section-10">Example backtrace</h7>
<p>Here is an example session:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; trace/back on
&gt;&gt; test: func [a] [if integer? a [loop a [bug]]]
&gt;&gt; test 10
** Script error: bug has no value
** Where: loop if test
** Near: loop a [bug]

&gt;&gt; trace/back 10
    --&gt; if
         1: loop : native! [count block]
         2: a : 10
         3: [bug]
        --&gt; loop
             1: bug : unset!
            **: error : Script no-value
 1: trace/back
 2: 20
--&gt; trace</code></pre></div>
<p>So, it's not hard to see what was going on when the script crashed. Backtrace can be quite handy when you need it.</p>
<h7 id="section-11">Important notes</h7>
<ul>
<li>Tracing is disabled automatically when you display the backtrace. (This prevents additional accumulation of trace information, allowing you to redisplay the buffer without interference from additional console lines.)</li>
<li>Backtrace will slow down your program by a factor of 20 (because for each value that is evaluated, it must store a log record).</li>
<li>The internal backtrace buffer is 100KB. On average, the most it will hold is 100 pages of backtrace.</li>
<li>Enabling normal trace will disable backtrace and delete the backtrace buffer.</li>
<li>Backtrace may interfere with some kinds of tracing, especially if the bug is related to a defect within the REBOL interpreter itself.</li>
</ul>
<p>The <a href="#stack">stack</a> function can also be used to show stack related backtrace information.</p>

```
------------------------------------------------------------------
## TRANSCODE
[[ to-block ]]

```html

<p>The <a href="#transcode">transcode</a> function translates source code and data into the block value memory format that can be interpreted by REBOL.</p>
<h6 id="section-2">Input</h6>
<p>The source input to <a href="#transcode">transcode</a> must be Unicode UTF-8. This is a <span class="datatype">binary!</span> encoded format, and should not be confused with a <span class="datatype">string!</span>, which is a decoded in-memory indexable string.</p>
<p>If you need to <a href="#transcode">transcode</a> a string, you must convert it to a UTF-8 binary first. This can be done with <a href="#to-binary">to-binary</a>.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: transcode to-binary string</code></pre></div>
<fieldset class="fset"><legend>Reduced efficiency</legend>
<p>In general, conversions to and from UTF-8 require extra time to for the Unicode conversion process. Therefore, is not a good idea to write REBOL code like TCL or PERL where computations are done on strings.</p>
<p>Don't write code such as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do append "1 +" n</code></pre></div>
<p>Because you can just as easily write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do append [1 +] n</code></pre></div>
<p>in REBOL.</p>
</fieldset>
<h6 id="section-3">Refinements</h6>
<p>Without refinements, <a href="#transcode">transcode</a> will convert the entire input string.</p>
<p>Refinements are provided for partial translation:</p>
<table border="0" cellpadding="5" cellspacing="1" bgcolor="#d0d0e0" class="doctable">
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>/next</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">Translate the next full value. If it is a block, translate the entire block.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>/only</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">Translate the next singular value. If it is a block, translate only the first element of the block, and return it within a block.
</td></tr>
<tr><td valign="top" bgcolor="#f0f0ff" nowrap><b>/error</b></td><td valign="top" bgcolor="#f0f0ff" width="95%">Convert syntax errors to error objects and output them rather than throwing them as an error.
</td></tr>
</table>
<p>These refinements can be used in various ways to parse REBOL source a value at a time.</p>
<h6 id="section-4">Output</h6>
<p>The output from <a href="#transcode">transcode</a> is a <span class="datatype">block!</span> containing two values:</p>
<ol>
<li>The translated value, block of values, or <span class="datatype">error!</span> object.</li>
<li>The <span class="datatype">binary!</span> source at the point where the translation ended.</li>
</ol>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">a: to-binary "a b c"
#{6120622063}</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">transcode/only a
[a #{20622063}]</code></pre></div>

```
------------------------------------------------------------------
## TRIM
[[ parse remove clear ]]

```html

<p>Trim removes unwanted values, normally it trims whitespace from a <span class="datatype">string!</span> or <span class="datatype">none!</span> values from a <span class="datatype">block!</span> or <span class="datatype">object!</span>.</p>
<p>Here is an example of a string:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "  string   "
probe trim str
"string"</code></pre></div>
<p>Note that the str is modified. To avoid that, use copy:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">new-str: trim copy str</code></pre></div>
<p>For a <span class="datatype">block!</span> :</p>
<div class="example-code"><pre class="code-block"><code class="rebol">trim reduce [none 'a none 'b none]
[a b]</code></pre></div>
<p>It removes the <span class="datatype">none!</span> values from the block. (And it will also remove <span class="datatype">unset!</span> values as well.)</p>
<p>Note that the block is modified. But, in this example, <a href="#reduce">reduce</a> creates a unique copy, so the original is not effected.</p>
<p>And for an <span class="datatype">object!</span> :</p>
<div class="example-code"><pre class="code-block"><code class="rebol">trim system/options
make object! [
    home: %/C/Program%20Files/
    path: %/C/rebol/r3/
    boot: %/C/rebol/r3/view.exe
    binary-base: 16
    decimal-digits: 15
]</code></pre></div>
<p>Because object fields cannot be removed (due to binding) the result of <a href="#trim">trim</a> of an object is always to return a new shallow object. (The values of the object are not deep-copied or rebound.)</p>
<p>The new object only shows fields that have actual value (not none or unset.)</p>
<h6 id="section-2">Details on trimming strings</h6>
<p>The default for TRIM is to remove whitespace characters (tabs
and spaces) from the heads and tails of every line of a string.
Empty leading and trailing lines are also trimmed.</p>
<p>When a string includes multiple lines, the head and tail
whitespace will be trimmed from each line (but not within the
line):</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: {
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
}</code></pre></div>
<p>The line terminator of the final line is preserved.</p>
<p>As mentioned above, empty leading and trailing lines are also
trimmed:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe trim {

    Non-empty line.
    Non-empty line.
    Non-empty line.

}
{Non-empty line.
Non-empty line.
Non-empty line.
}</code></pre></div>
<p>Note that TRIM modifies the string in the process.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "  string   "
trim str
probe str
"string"</code></pre></div>
<p>TRIM does not copy the string. If that's what you want, then use
TRIM with COPY to copy the string before trimming it.</p>
<p>Several refinements to TRIM are available. To trim just the head
and/or tail of a string you can use the /HEAD or /TAIL refinements.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe trim/head "  string  "
"string  "</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe trim/tail "  string  "
"  string"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe trim/head/tail "  string  "
"string"</code></pre></div>
<p>When using /HEAD or /TAIL, multiple lines are not affected:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe trim/head {  line 1
    line 2
    line 3
}
{line 1
line 2
line 3
}</code></pre></div>
<p>To trim just the head and tail of a multiline string, but none
of its internal spacing:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: {  line 1
    line 2
        line 3
            line 4
                line 5  }
probe trim/head/tail str
{line 1
line 2
    line 3
        line 4
            line 5}</code></pre></div>
<p>If you use TRIM/LINES then all lines and extra spaces will be
removed from the text. This is useful for word wrapping and web
page kinds of applications.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: {
    Now   is
    the
    winter
}
probe trim/lines str
"Now is^/the^/winter"</code></pre></div>
<p>You can also remove /ALL space:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe trim/all " Now is   the winter "
"Nowisthewinter"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: {
    Now   is
    the
    winter
}
probe trim/all str
"Nowisthewinter"</code></pre></div>
<p>One of the most useful TRIM refinements is /AUTO which will do a
"smart" trim of the indentation of text lines. This mode detects
the indentation from the first line and preserves indentation
for the lines to follow:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">probe trim/auto {
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
 }</code></pre></div>
<p>This is useful for sections of text that are embedded within
code and indented to the level of the code.</p>
<p>To trim other characters, the /WITH refinement is provided.
It takes an additional string that specifies what characters
to be removed.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: {This- is- a- line.}
probe trim/with str "-"
"This is a line."</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: {This- is- a- line.}
probe trim/with str "- ."
"Thisisaline"</code></pre></div>
<h6 id="section-3">TRIM on blocks</h6>
<p>When <a href="#trim">trim</a> is used on a <span class="datatype">block!</span>, it strips all <span class="datatype">none!</span> values from the block:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">trim reduce [1 2 none]
[1 2]</code></pre></div>
<p>Note that <a href="#trim">trim</a> modifies the argument block.</p>
<h6 id="section-4">TRIM on objects</h6>
<p>When <a href="#trim">trim</a> is used on an <span class="datatype">object!</span>, it will return a new object that has all <span class="datatype">none!</span> values removed:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">obj: make object [arg1: 10 arg2: none]
trim obj
make object! [
    arg1: 10
]</code></pre></div>

```
------------------------------------------------------------------
## TRUE?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TRUNCATE
------------------------------------------------------------------
## TRY
[[ attempt error? do ]]

```html

<p>The <a href="#try">try</a> function evaluates a block and will capture any errors that occur during that evaluation.</p>
<p>The purpose of <a href="#try">try</a> is to give your own code the opportunity to handle errors, rather than causing your program to terminate with an error message.</p>
<p>For example, in this line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">try [delete %afile.txt]</code></pre></div>
<p>if the file does not exist, then the error will not cause your program to terminate.</p>
<h6 id="section-2">Return Value</h6>
<p>The <a href="#try">try</a> function returns an error value if an error happened, otherwise it returns the normal result of the block.</p>
<p>Taking the above example, we can do something special if an error happened:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if error? try [delete %afile.txt] [print "delete failed"]</code></pre></div>
<p>or, even use the error value itself:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if error? err: try [delete %afile.txt] [print ["delete failed:" mold err]]</code></pre></div>
<p>Sometimes you'll want to use the value that was returned:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">either error? val: try [1 + "x"] [print "nope"] [print val]
nope</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">either error? val: try [1 + 2] [print "nope"] [print val]
3</code></pre></div>
<h6 id="section-3">Exception Handling</h6>
<p>The <a href="#try">try</a> function is for error handling, but there are times when you may be returning error objects as values, and you cannot distinguish between an error occurring and the error value itself. This is case rare, but it does happen.</p>
<p>For this situation the /except refinement is provided. If an error occurs, it will evaluate a exception handling function (or just a block). This indicates that an error exception happened (not just an error value being passed.)</p>
<p>The example below will catch the <a href="/r3/docs/errors/zero-divide.html" class="err">[bad-link:errors/zero-divide.txt]</a> error within a function. The error is passed as the argument to the exception function, and a value (zero in this case) is returned from the <a href="#try">try</a> function:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">try/except [1 / 0] func [value] [?? value 0]
value: make error! [
    code: 400
    type: 'Math
    id: 'zero-divide
    arg1: none
    arg2: none
    arg3: none
    near: [/ 0]
    where: [/ try]
 ]
 0</code></pre></div>
<h6 id="section-4">Shortcut</h6>
<p>The <a href="#attempt">attempt</a> function is shortcut for the common pattern where you don't care about the specific error, and mainly just want the non-error result.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">data: attempt [load %data.r]</code></pre></div>
<p>The data will be either the data or none, if it failed to load.</p>

```
------------------------------------------------------------------
## TUPLE?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print tuple? 1.2.3.4
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">version: 0.1.0
if tuple? version [print version]
0.1.0</code></pre></div>

```
------------------------------------------------------------------
## TYPE?
[[ make none? logic? integer? decimal? money? tuple? time? date? string? email? file? url? issue? word? block? paren? path? native? function? object? port? ]]

```html

<p>To check for a single datatype, use its datatype test
function (e.g. string?, time?) The /WORD refinement
returns the type as a word so you can use if for FIND,
SELECT, SWITCH, and other functions.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print type? 10
integer!</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print type? :type?
native!</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">value: 10:30
print switch type?/word value [
    integer! [value + 10]
    decimal! [to-integer value]
    time! [value/hour]
    date! [first value/time]
]
10</code></pre></div>

```
------------------------------------------------------------------
## TYPES-OF
[[ body-of reflect spec-of title-of values-of words-of ]]

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## TYPESET?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## UNBIND
------------------------------------------------------------------
## UNDIRIZE
------------------------------------------------------------------
## UNFILTER
------------------------------------------------------------------
## UNHANDLE-EVENTS

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## UNION
[[ difference intersect exclude unique ]]

```html

<p>Returns all elements present within two blocks or strings 
ignoring the duplicates.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">lunch: [ham cheese bread carrot]
dinner: [ham salad carrot rice]
probe union lunch dinner
[ham cheese bread carrot salad rice]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe sort union [1 3 2 4] [3 5 4 6]
[1 2 3 4 5 6]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">string1: "CBDA"    ; A B C D scrambled
string2: "EDCF"    ; C D E F scrambled
probe sort union string1 string2
"ABCDEF"</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">items: [1 1 2 3 2 4 5 1 2]
probe union items items  ; get unique set
[1 2 3 4 5]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "abcacbaabcca"
probe union str str
"abc"</code></pre></div>
<p>To obtain a unique set (to remove duplicate values)
you can use UNIQUE.</p>
<p>Note that performing this function over very large
data sets can be CPU intensive.</p>

```
------------------------------------------------------------------
## UNIQUE
[[ intersect union difference exclude ]]

```html

<p>Removes all duplicate values from a set or series:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">lunch: [ham cheese bread carrot ham ham carrot]
probe unique lunch
[ham cheese bread carrot]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">probe unique [1 3 2 4 3 5 4 6]
[1 3 2 4 5 6]</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">string: "CBADEDCF"
probe unique string
"CBADEF"</code></pre></div>
<p>Note that performing this function over very large
data sets can be CPU intensive.</p>

```
------------------------------------------------------------------
## UNLESS
[[ if not either ]]

```html

<p>The <a href="#unless">unless</a> function is the equivalent of writing <a href="#if">if</a> <a href="#not">not</a> of a condition.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">unless now/time &gt; 12:00 [print "It's still morning"]</code></pre></div>
<p>See the <a href="#if">if</a> function for a lot more information.</p>
<h6 id="section-2">Why?</h6>
<p>This function can take some getting used to. It has been provided to make PERL programmers happier, and it's marginally simpler and faster than writing an <a href="#if">if</a> <a href="#not">not</a> expression.</p>

```
------------------------------------------------------------------
## UNPROTECT
[[ protect ]]

```html

<p>Unprotects a series, variable, or object that was protected earlier with <a href="#protect">protect</a>.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">test: "text"
protect test
append test "a"
** Script error: protected value or series - cannot modify</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">unprotect test
append test "a"
probe texta
"texta"</code></pre></div>
<p>To <a href="#unprotect">unprotect</a> all series found within a block, use the /deep refinement:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">test: [100 "example" 10:20]
protect/deep test
print append "example" "x"
** Script error: protected value or series - cannot modify</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">unprotect/deep test
print append "example" "x"
examplex</code></pre></div>
<p>See <a href="#protect">protect</a> for other usage and information.</p>

```
------------------------------------------------------------------
## UNSET
[[ set ]]

```html

<p>Using UNSET, the word's current value will be lost. If
a block is specified, all the words within the block
will be unset.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">test: "a value"
unset 'test
print value? 'test
false</code></pre></div>

```
------------------------------------------------------------------
## UNSET?
[[ value? ]]

```html

<p>Returns TRUE if a value is UNSET. Normally you should
use VALUE? to test if a word has a value.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if unset? do [print "test"] [print "Nothing was returned"]
test</code></pre></div>

```
------------------------------------------------------------------
## UNTIL
[[ while repeat loop foreach for ]]

```html

<p>The <a href="#until">until</a> function evaluates a block until the block returns true. It is different from <a href="#while">while</a> because it only requires a single block, which also serves as the condition. However, the block is always evaluated at least once.</p>
<p>The general form is:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">while [cond] [body]</code></pre></div>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">num: 0
until[
    print num
    num: num + 1
    num &gt;= 2
]
0
1
2</code></pre></div>
<p>Another example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "test"
until [
    print str
    tail? str: next str
]
test
est
st
t</code></pre></div>
<h6 id="section-2">Return Value</h6>
<p>The last value of the block is returned from the <a href="#until">until</a> function. Because this is also the termination condition, it will always be non-none non-false, but that can be useful at times.</p>
<h6 id="section-3">Other Notes</h6>
<ul>
<li>A <a href="#break">break</a> can be used to escape from the loop at any time.</li>
<li>A common mistake is to forget that block must return the test condition for the loop, which could result in an infinite loop.</li>
</ul>

```
------------------------------------------------------------------
## UNVIEW

```html

<p>The UNVIEW function is used to close a window previously opened
with the VIEW function. By default, the last window that has
been opened will be closed.  To close a specific window, use the
/only refinement and specify the window's face (that which was
returned from a layout, for example).  All windows can be closed
with the /all refinement.</p>
<p>The example below opens a window that displays a Close button.
Clicking on the button will evaluate the UNVIEW function and the
window will be closed.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">view layout [button "Close" [unview]]</code></pre></div>
<p>Note that the VIEW function will not return until all windows
have been closed. (Use VIEW/new to return immediately after
the window is opened.)</p>
<p>The next example will open two windows, then use UNVIEW/only
to close each one separately.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">out1: layout [button "Close 2" [unview out2]]
out2: layout [button "Close 1" [unview out1]]
view/new out1
view/new out2
do-events</code></pre></div>
<p>You could have closed both windows with the line:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">unview/all</code></pre></div>

```
------------------------------------------------------------------
## UPDATE
[[ read write insert remove query ]]

```html

<p>Updates the input or output of a port. If input is
expected, the port is checked for more input. If output
is pending then that output is written.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">out: open/new %trash.me
insert out "this is a test"
update out
insert out "this is just a test"
close out</code></pre></div>

```
------------------------------------------------------------------
## UPPERCASE
[[ lowercase trim ]]

```html

<p>The series passed to this function is modified as a
result.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print uppercase "abcdef"
ABCDEF</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print uppercase/part "abcdef" 1
Abcdef</code></pre></div>

```
------------------------------------------------------------------
## URL?
[[ type? ]]

```html

<p>Returns FALSE for all other values.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print url? http://www.REBOL.com
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print url? "test"
false</code></pre></div>

```
------------------------------------------------------------------
## USAGE
[[ help ? ]]

```html

<p>Displays REBOL command line arguments, including
options and examples.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">usage</code></pre></div>
<p>SDK and special versions of REBOL may not include usage
information.</p>

```
------------------------------------------------------------------
## USE

```html

<p>The first block contains a list of words which will be
local to the second block. The second block will be
evaluated and its results returned from the USE.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">total: 1234
nums: [123 321 456]
use [total] [
    total: 0
    foreach n nums [total: total + n]
    print total
]
900</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print total
1234</code></pre></div>
<p>Note: The USE function modifies the context (bindings) of the code
block (as if BIND was used on it). This can lead to problems for
recursive functions. To use the USE function recusively, you will
need to COPY/deep the code block first:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">words: [a]
body: [print a * b]
use words copy/deep body</code></pre></div>

```
------------------------------------------------------------------
## USER'S
------------------------------------------------------------------
## UTF?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## UTYPE?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## VALUE?
[[ default unset? equal? strict-equal? same? ]]

```html

<p>The <a href="#value?">value?</a> function returns true if the specified <span class="datatype">word!</span> has a value. It returns false if not.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">test: 1234
value? 'test
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">value? 'not-defined
false</code></pre></div>
<p>The word can be passed as a literal or as the result of other operations.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">value? first [test this]
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">value? second [test this]
false</code></pre></div>

```
------------------------------------------------------------------
## VALUES-OF
[[ body-of reflect spec-of title-of types-of words-of ]]

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## VECTOR?

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## VERSION
------------------------------------------------------------------
## VIEW

```html

<p>The view function creates and updates windows. It takes a face
as its argument. The contents of the window is determined from a
face that holds  a block of the graphical objects. The window
face is normally created with the LAYOUT function, but faces can
be constructed directly from face objects and displayed as well.</p>
<p>The example below opens a window and displays some text and a
button.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">view layout [
    h2 "The time is currently:"
    h3 form now
    button "Close" [unview]
]</code></pre></div>
<p>The position and size of the window is determined from the  face
to be displayed.  In the example above, the size of the window
is automatically computed by the LAYOUT function. The window is
shown in the default position in the upper left area of the
screen.</p>
<p>The window's caption will be default be the title of the script
that is being run.  To provide a different caption, use the
/title refinement and a string.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">view/title layout [h1 "Window"] "A Window"</code></pre></div>
<p>The first use of view within an application is special. It
displays the window and initializes the graphical interface
system. Subsequent calls to VIEW update the window, they do not
create new windows unless the /new refinement is provided.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">view layout [
    button "Change" [
        view layout [button "Stop" [unview]]
    ]
]</code></pre></div>
<p>The first call to the VIEW function will not return immediately.
At that point your code becomes event driven, calling the
functions associated with various faces. While the first call to
VIEW remains active, any other calls to VIEW will return
immediately. The first call will return only after all windows
have been closed.</p>
<p>Additionally, calls to view can specify options, such as whether
the window has borders and is resizable.  Single options are
provided as a word and multiple options are specified in a block.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">out: layout [vh1 "This is a window."]
view/options out [resize no-title]</code></pre></div>

```
------------------------------------------------------------------
## WAIT

```html

<p>If the value is a <span class="datatype">time!</span>, delay for that period. If the
value is an <span class="datatype">integer!</span> or <span class="datatype">decimal!</span>, wait that number of
seconds. If the value is a <span class="datatype">port!</span>, wait for an event from
that port. If a <span class="datatype">block!</span> is specified, wait for any of the
times or ports to occur. Return the port that caused
the wait to complete or return none if the timeout
occurred.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print now/time
17:48:19</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">wait 1
print now/time
17:48:22</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">wait 0:00:01
print now/time
17:48:23</code></pre></div>

```
------------------------------------------------------------------
## WAIT-FOR-KEY
------------------------------------------------------------------
## WAKE-UP

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## WHAT
[[ help ? ]]

```html

<p>The <a href="#what">what</a> function lists globally exported functions and their titles or arguments.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; what
...
about               Information about REBOL
abs                 Returns the absolute value.
absolute            Returns the absolute value.
action              Creates datatype action (for internal usage only).
action?             Returns TRUE if it is this type.
add                 Returns the result of adding two values.
ajoin               Reduces and joins a block of values into a new string.
alias               Creates an alternate spelling for a word.
...</code></pre></div>
<p>To see function arguments use:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">&gt;&gt; what/args
...
about                 []
abs                   [value]
absolute              [value]
action?               [value]
add                   [value1 value2]
ajoin                 [block]
...</code></pre></div>
<p>Also see the <a href="#help">help</a> function which allows searching for functions.</p>
<h6 id="section-2">Module Export Lists</h6>
<p>To see a list of functions for a specific module, provide the module name:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">what module-name</code></pre></div>

```
------------------------------------------------------------------
## WHAT-DIR
[[ change-dir make-dir list-dir ]]

```html

<p>Returns the value of system/script/path, the default
directory for file operations.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print what-dir
/C/REBOL/3.0/docs/scripts/</code></pre></div>

```
------------------------------------------------------------------
## WHILE
[[ until loop repeat for ]]

```html

<p>The <a href="#while">while</a> function repeats the evaluation of its two block arguments while the first block returns true. The first block is the condition block, the second block is the evaluation block. When the condition block returns false or <span class="datatype">none!</span>, the expression block will no longer be evaluated and the loop terminates.</p>
<p>The general form is:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">while [cond] [body]</code></pre></div>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">num: 0
while [num &lt; 3] [
    print num
    num: num + 1
]
0
1
2</code></pre></div>
<p>Another example, using <a href="#while">while</a> to traverse a series (like <a href="#foreach">foreach</a> ):</p>
<div class="example-code"><pre class="code-block"><code class="rebol">color: [red green blue]
while [not tail? color] [
    print first color
    color: next color
]
red
green
blue</code></pre></div>
<p>Here is an example using a string series:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">str: "abc"
while [not tail? str: next str] [
    print ["length of" str "is" length? str]
]
length of abc is 3
length of bc is 2
length of c is 1</code></pre></div>
<h6 id="section-2">Condition Block</h6>
<p>The condition block can contain any number of expressions, so long as the last expression returns the condition. To illustrate this, the next example adds a print to the condition block. This will print the index value of the color. It will then check for the tail of the color block, which is the condition used for the loop.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">color: [red green blue]
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
4</code></pre></div>
<h6 id="section-3">Return Value</h6>
<p>The last value of the block is returned from the <a href="#while">while</a> function.</p>
<h6 id="section-4">Other Notes</h6>
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

```html

<p>Returns FALSE for all other values. To test for "word:",
":word", or "'word", use the SET?, GET?, and LITERAL?
functions.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print word? second [1 two "3"]
true</code></pre></div>

```
------------------------------------------------------------------
## WORDS-OF
[[ body-of reflect spec-of title-of types-of values-of ]]

```html

<p>No description provided.</p>

```
------------------------------------------------------------------
## WRAP
------------------------------------------------------------------
## WRITE
[[ read open close load save form ]]

```html

<p>WRITE is typically used to write a file to disk, but
many other operations, such as writing data to URLs and
ports, are possible.</p>
<p>Normally a string or binary value is provided to this
function, but other types of data such as a number or a
time can be written. They will be converted to text.</p>
<p>The /BINARY refinement will write out data as its exact
representation. This is good for writing image, sound
and other binary data.</p>
<p>The /STRING refinement translates line terminators to
the operating system's line terminator. This behavior
is default.</p>
<p>The /APPEND refinement is useful logging purposes, as
it won't overwrite existing data.</p>
<p>The /LINES refinement can take a block of values and 
will write each value to a line. By default, WRITE will
write the block of values as a concatonated string of
formed values.</p>
<p>The /PART refinement will read the specified number of
elements from the data being written.
The /WITH refinement converts characters, or strings,
specified into line terminators.</p>
<p>See the User's Guide for more detailed explanation of
using READ and its refinements.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">write %junkme.txt "This is a junk file."
write</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">write %datetime.txt now
write</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">write/binary %data compress "this is compressed data"

write %rebol-test-file.r "some text"
print read %rebol-test-file.r
read</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">write/append %rebol-test-file.r "some more text"
print read %rebol-test-file.r

write %rebol-test-file.r reduce ["the time is:" form now/time]
print read %rebol-test-file.r
read</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">write/lines %rebol-test-file.r reduce ["time is:" form now/time]
print read %rebol-test-file.r

write/part %rebol-test-file.r "this is the day!" 7
print read %rebol-test-file.r</code></pre></div>

```
------------------------------------------------------------------
## XOR
[[ and or not ]]

```html

<p>For integers, each bit
is exclusively-or'd. For logic values, this is the
same as the not-equal function.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print 122 xor 1
123</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print true xor false
true</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print false xor false
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print 1.2.3.4 xor 1.0.0.0
0.2.3.4</code></pre></div>

```
------------------------------------------------------------------
## XOR~
[[ and~ or~ ]]

```html

<p>The trampoline action function for XOR operator.</p>

```
------------------------------------------------------------------
## XTEST
------------------------------------------------------------------
## ZERO?
[[ positive? negative? ]]

```html

<p>Check the value of a word is zero.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">print zero? 50
false</code></pre></div>
<div class="example-code"><pre class="code-block"><code class="rebol">print zero? 0
true</code></pre></div>

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
