
<hr>
<section id="about">
 <a name="about"></a>
 <h2>ABOUT<a class="headerlink" href="#about" title="Link to this heading">¶</a></h2>
<p>Information about REBOL</p>

<h6>Usage:</h6>
<pre class="usage fs-6">about</span></pre>

<h6>Description:</h6>
<p>
Displays REBOL title and version information on the REBOL console.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">>> about</code></pre></div>
<div class="example-code"><pre class="text-block"><code>╔══════════════════════════════════════════════════════════════════════════╗
║<span class="ansi30 ansi107">                                                                          </span>║
║<span class="ansi30 ansi107">  <span class="ansi35">REBOL/Bulk 3.20.0 (Oldes branch)                                        <span class="ansi30 ansi107"></span></span></span>║
║<span class="ansi30 ansi107">                                                                          </span>║
║<span class="ansi30 ansi107">    <span class="ansi32">Copyright  <span class="ansi31">2012 REBOL Technologies                                    <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">    <span class="ansi32">           <span class="ansi31">2012-2025 Rebol Open Source Contributors                   <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">    <span class="ansi32">           <span class="ansi31">Apache 2.0 License, see LICENSE.                           <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">    <span class="ansi32">Website    <span class="ansi31">https://github.com/Oldes/Rebol3                            <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">                                                                          </span>║
║<span class="ansi30 ansi107">    <span class="ansi32">Platform   <span class="ansi31">Windows | x64-pc-win32-pe | cl                             <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">    <span class="ansi32">Build      <span class="ansi31">4-Oct-2025/19:17                                           <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">                                                                          </span>║
║<span class="ansi30 ansi107">    <span class="ansi32">Home       <span class="ansi31">C:\Users\oldes\                                            <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">    <span class="ansi32">Data       <span class="ansi31">C:\Users\oldes\Rebol\                                      <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">                                                                          </span>║
╚══════════════════════════════════════════════════════════════════════════╝

<span class="ansi1 ansi33">Important notes</span>:

  * Sandbox and security are not fully available.
  * Direct access to TCP HTTP required (no proxies).
  * Use at your own risk.
  * <span class="ansi1 ansi32">Try/except<span class="ansi1 ansi31"> is deprecated and will be removed!</span></span> Use <span class="ansi1 ansi32">try/with</span> instead.
  * This Rebol version has switched map and construction syntax!
    See: https://github.com/Oldes/Rebol-issues/issues/2589

<span class="ansi1 ansi33">Special functions</span>:

  <span class="ansi1 ansi32">Help</span>  - show built-in help information

</code></pre></div>
<div class="see-also">See also: <a href="#help">help</a>, <a href="#license">license</a>, <a href="#usage">usage</a></div>
</section>

<hr>
<section id="abs">
 <a name="abs"></a>
 <h2>ABS<a class="headerlink" href="#abs" title="Link to this heading">¶</a></h2>
<p>Note: Shell shortcut for <a href="#absolute">absolute</a>.</p>
</section>

<hr>
<section id="absolute">
 <a name="absolute"></a>
 <h2>ABSOLUTE<a class="headerlink" href="#absolute" title="Link to this heading">¶</a></h2>
<p>Returns the absolute value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">absolute <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number! pair! money! time!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns a positive value equal in magnitude.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; absolute -123
== 123
&gt;&gt; absolute -1:23
== 1:23
&gt;&gt; absolute -1x4
== 1x4</code></pre></div>
<div class="see-also">See also: <a href="#-">-</a>, <a href="#abs">abs</a>, <a href="#negate">negate</a>, <a href="#sign?">sign?</a></div>
</section>

<hr>
<section id="access-os">
 <a name="access-os"></a>
 <h2>ACCESS-OS<a class="headerlink" href="#access-os" title="Link to this heading">¶</a></h2>
<p>Access to various operating system functions (getuid, setuid, getpid, kill, etc.)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">access-os <span class="rebarg">field</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  field       [<span class="types">word!</span>] Valid words: uid, euid, gid, egid, pid
<span class="tit">REFINEMENTS:</span>
  /set        To set or kill pid (sig 15)
   value      [<span class="types">integer! block!</span>] Argument, such as uid, gid, or pid (in which case, it could be a block with the signal no)
</pre>
</section>

<hr>
<section id="acos">
 <a name="acos"></a>
 <h2>ACOS<a class="headerlink" href="#acos" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric arccosine.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">acos <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">decimal!</span>] In radians
</pre>

<h6>Description:</h6>

<div class="see-also">See also: <a href="#arccosine">arccosine</a></div>
</section>

<hr>
<section id="action?">
 <a name="action?"></a>
 <h2>ACTION?<a class="headerlink" href="#action?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">action? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Actions are special functions that operate with datatypes. See <span class="datatype">action!</span> for more.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; action? :add
== true
&gt;&gt; action? :append
== true
&gt;&gt; action? :+
== false
&gt;&gt; action? "add"
== false</code></pre></div>
<div class="see-also">See also: <a href="#any-function?">any-function?</a>, <a href="#function?">function?</a>, <a href="#native?">native?</a>, <a href="#op?">op?</a>, <a href="#type?">type?</a></div>
</section>

<hr>
<section id="add">
 <a name="add"></a>
 <h2>ADD<a class="headerlink" href="#add" title="Link to this heading">¶</a></h2>
<p>Returns the addition of two values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">add <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! date! vector!</span>] 
  value2      [<span class="types">scalar! date! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
Note: The <a href="#+">+</a> operator is a special infix form for this function.
</p>
<p>
Many different datatypes support addition.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print add 123 1
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
1-Jan-2000</code></pre></div><p>
When adding values of different datatypes, the values must be compatible. Auto conversion of the values will occur into the datatype that has the most expansive representation. For example an integer added to a decimal will produce a decimal.
</p>

<div class="see-also">See also: <a href="#+">+</a>, <a href="#-">-</a>, <a href="#subtract">subtract</a></div>
</section>

<hr>
<section id="ajoin">
 <a name="ajoin"></a>
 <h2>AJOIN<a class="headerlink" href="#ajoin" title="Link to this heading">¶</a></h2>
<p>Reduces and joins a block of values into a new string. Ignores none and unset values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">ajoin <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block!</span>] 
<span class="tit">REFINEMENTS:</span>
  /with       
   delimiter  [<span class="types">any-type!</span>] 
  /all        Do not ignore none and unset values
</pre>

<h6>Description:</h6>
<p>
The <a href="#join">join</a> and <a href="#rejoin">rejoin</a> functions return the same datatype as their first element, be it a <span class="datatype">string!</span>, <span class="datatype">file!</span>, <span class="datatype">binary!</span>, <span class="datatype">tag!</span>, <span class="datatype">email!</span> or whatever. However, there are times when you just want to construct a <span class="datatype">string!</span>, and that's the purpose of <a href="#ajoin">ajoin</a>.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">ajoin ["test" 123]
"test123"</code></pre></div><p>
It is similar to <a href="#reform">reform</a> but does not insert spaces between values:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">reform ["test" 123]
"test 123"</code></pre></div><p>
Note that the block is always evaluated:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">time: 10:30
ajoin [time/hour "h" time/minute "m"]
"10h30m"</code></pre></div><p>
The <a href="#ajoin">ajoin</a> function is equivalent to:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">to-string reduce block</code></pre></div>
<h6>How it differs</h6><p>
Here are examples that show how <a href="#ajoin">ajoin</a> differs from <a href="#join">join</a> and <a href="#rejoin">rejoin</a>.
</p>
<p>
Compare:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">ajoin [&lt;test&gt; 123]
"&lt;test&gt;123"</code></pre></div><p>
with:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">rejoin [&lt;test&gt; 123]
&lt;test123&gt;</code></pre></div><p>
and:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">join &lt;test&gt; 123
&lt;test123&gt;</code></pre></div><p>
Notice that the last two examples return a <span class="datatype">tag!</span>, not a <span class="datatype">string!</span>.
</p>

<div class="see-also">See also: <a href="#append">append</a>, <a href="#combine">combine</a>, <a href="#form">form</a>, <a href="#join">join</a>, <a href="#reform">reform</a>, <a href="#rejoin">rejoin</a></div>
</section>

<hr>
<section id="all">
 <a name="all"></a>
 <h2>ALL<a class="headerlink" href="#all" title="Link to this heading">¶</a></h2>
<p>Shortcut AND. Evaluates and returns at the first FALSE or NONE.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">all <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block!</span>] Block of expressions
</pre>

<h6>Description:</h6>
<p>
The <a href="#all">all</a> function is the most common way to test multiple conditions, such as in the line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if all [num &gt; 1  num &lt; 1000] [do something]</code></pre></div><p>
It works by evaluating each expression in a block until one of the expressions returns <span class="datatype">none!</span> or false, in which case a <span class="datatype">none!</span> is returned. Otherwise, the value of the last expression will be returned.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print all [1 none]
none

print all [none 1]
none

print all [1 2]
2

print all [10 &gt; 1 "yes"]
yes

print all [1 &gt; 10 "yes"]
none

time: 10:30
if all [time &gt; 10:00 time &lt; 11:00] [print "time is now"]
time is now</code></pre></div><p>
No other expressions are evaluated beyond the point where a value fails:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">a: 0
all [none a: 2]
print a
0

a: 0
all [1 a: 2]
print a
2

day: 10
time: 9:45
ready: all [day &gt; 5  time &lt; 10:00  time: 12:00]
print time
12:00</code></pre></div><p>
The <a href="#any">any</a> function is a companion of <a href="#all">all</a> to test for the opposite condition, where any one of the values will result in a true result.
</p>

<div class="see-also">See also: <a href="#and">and</a>, <a href="#any">any</a>, <a href="#case">case</a>, <a href="#or">or</a>, <a href="#switch">switch</a></div>
</section>

<hr>
<section id="all-of">
 <a name="all-of"></a>
 <h2>ALL-OF<a class="headerlink" href="#all-of" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if all value(s) pass the test, otherwise NONE.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">all-of <span class="rebarg">word</span> <span class="rebarg">data</span> <span class="rebarg">test</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word! block!</span>] Word or block of words to set each time (local)
  data        [<span class="types">series! any-object! map! none!</span>] The series to traverse
  test        [<span class="types">block!</span>] Condition to test each time
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; all-of x [33 -1 24] [x &gt; 0]
== #(none)

&gt;&gt; all-of x [33 -1 24] [integer? x]
== #(true)</code></pre></div>
<div class="see-also">See also: <a href="#any-of">any-of</a></div>
</section>

<hr>
<section id="also">
 <a name="also"></a>
 <h2>ALSO<a class="headerlink" href="#also" title="Link to this heading">¶</a></h2>
<p>Returns the first value, but also evaluates the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">also <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#also">also</a> function lets you evaluate two expressions, but return the first, rather than the second. This function may seem a bit odd at first, but in many cases it can save you from needing another temporary variable.
</p>
<p>
Consider the case where you want to evaluate a block and return its result, but before returning the result, you want to change directories.
</p>
<p>
You could write:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">result: do block
change-dir old-dir
return result</code></pre></div><p>
Or, you could write
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">return also do block change-dir old-dir</code></pre></div><p>
In fact, that's actually what happens in the <a href="#in-dir">in-dir</a> function.
Another case might be an I/O port used by a function that wants to <a href="#return">return</a> the port's data but also <a href="#close">close</a> it:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">return also port/locals/buffer close port</code></pre></div><p>
If you <a href="#close">close</a> the port first, the buffer cannot be accessed.
</p>

<div class="see-also">See also: <a href="#all">all</a>, <a href="#any">any</a>, <a href="#either">either</a>, <a href="#if">if</a></div>
</section>

<hr>
<section id="alter">
 <a name="alter"></a>
 <h2>ALTER<a class="headerlink" href="#alter" title="Link to this heading">¶</a></h2>
<p>Append value if not found, else remove it; returns true if added.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">alter <span class="rebarg">series</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! port! bitset!</span>] (modified)
  value        
<span class="tit">REFINEMENTS:</span>
  /case       Case-sensitive comparison
</pre>

<h6>Description:</h6>
<p>
The <a href="#alter">alter</a> function helps you manage small data-sets. It either adds or removes a value depending on whether the value is already included. (The word <a href="#alter">alter</a> is short for the word "alternate", the action taking place.)
</p>
<p>
For example, let's say you want to keep track of a few options used by your code. The options may be: flour, sugar, salt, and pepper. The following code will create a new block (to hold the data set) and add to it:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">options: copy []
alter options 'salt
probe options
[salt]

alter options 'sugar
probe options
[salt sugar]</code></pre></div><p>
You can use functions like <a href="#find">find</a> to test the presence of an option in the set:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if find options 'salt [print "Salt was found"]
Salt was found</code></pre></div><p>
If you use <a href="#alter">alter</a> a second time for the same option word, it will be removed:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">alter options 'salt
probe options
[sugar]</code></pre></div><p>
Normally <a href="#alter">alter</a> values are symbolic words (such as those shown above) but any datatype can be used such as integers, strings, etc.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">alter options 120
alter options "test"
probe options
[sugar 120 "test"]</code></pre></div><p>
Also, <a href="#alter">alter</a> returns true if the value was added to the series, or false if the value was removed.
</p>

<div class="see-also">See also: <a href="#difference">difference</a>, <a href="#exclude">exclude</a>, <a href="#find">find</a>, <a href="#insert">insert</a>, <a href="#intersect">intersect</a>, <a href="#remove">remove</a>, <a href="#unique">unique</a></div>
</section>

<hr>
<section id="and">
 <a name="and"></a>
 <h2>AND<a class="headerlink" href="#and" title="Link to this heading">¶</a></h2>
<p>Returns the first value ANDed with the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> and <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
  value2      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
For <span class="datatype">logic!</span> values, both values must be true to return true, otherwise a false is returned. AND is an infix operator.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print true and true
true

print true and false
false

print (10 &lt; 20) and (20 &gt; 15)
true</code></pre></div><fieldset class="fset"><legend>Programming style</legend>
<p>It's usually better to use <a href="#all">all</a> for anding conditional logic, such as the example above.</p>
<div class="example-code"><pre class="code-block"><code class="rebol">if all [10 &lt; 20 20 &gt; 15] ...</code></pre></div>
</fieldset><p>
For <span class="datatype">integer!</span>, <span class="datatype">tuple!</span>, <span class="datatype">binary!</span>, and other datatypes, each bit is separately anded.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print 123 and 1
1

print 1.2.3.4 and 255.0.255.0
1.0.3.0</code></pre></div>
<div class="see-also">See also: <a href="#all">all</a>, <a href="#integer?">integer?</a>, <a href="#logic?">logic?</a>, <a href="#not">not</a>, <a href="#or">or</a>, <a href="#xor">xor</a></div>
</section>

<hr>
<section id="and~">
 <a name="and~"></a>
 <h2>AND~<a class="headerlink" href="#and~" title="Link to this heading">¶</a></h2>
<p>Returns the first value ANDed with the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">and~ <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
  value2      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
This is the primary function behind the <a href="#and">and</a> operator. It can be used where you want prefix rather than infix notation:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">bits: and~ mask 3</code></pre></div>
<div class="see-also">See also: <a href="#and">and</a>, <a href="#or">or</a>, <a href="#or~">or~</a>, <a href="#xor">xor</a>, <a href="#xor~">xor~</a></div>
</section>

<hr>
<section id="any">
 <a name="any"></a>
 <h2>ANY<a class="headerlink" href="#any" title="Link to this heading">¶</a></h2>
<p>Shortcut OR. Evaluates and returns the first value that is not FALSE or NONE.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">any <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block!</span>] Block of expressions
</pre>

<h6>Description:</h6>
<p>
The <a href="#any">any</a> function is the most common way to test for one of multiple conditions, such as in the line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if any [a &gt; 10  b &gt; 20  c &gt; 30] [do something]</code></pre></div><p>
Here, if any one of the conditions produces a true result, the <a href="#if">if</a> will evaluate the block.
</p>
<p>
This function works by evaluating each expression in a block until one of the expressions returns a value other than <span class="datatype">none!</span> or false, in which case the value is returned. Otherwise, <span class="datatype">none!</span> will be returned.
</p>
<p>
Examples to help show how it works:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print any [1 none]
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
if any [time &gt; 10:00  time &lt; 11:00] [print "time is now"]
time is now</code></pre></div><p>
No other expressions are evaluated beyond the point where a successful value is found. This can be useful. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">a: 0
any [none a: 2]
print a
2

a: 0
any [1 a: 2]
print a
0

day: 10
time: 9:45
ready: any [day &gt; 5  time &lt; 10:00  time: 12:00]
print time
9:45</code></pre></div><p>
The <a href="#any">any</a> function is also useful for setting default values. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">size: any [size 100]</code></pre></div><p>
If size was <span class="datatype">none!</span>, then it gets set to 100. This works even better if there are alternative defaults:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">size: any [size prefs/size 100]</code></pre></div><p>
Another use for <a href="#any">any</a> is to emulate a sequence of if...elseif...elseif...else. Instead of writing:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">either cond-1 [
    code-1
] [
    either cond-2 [
        code-2
    ] [
        either cond-3 ...
    ]
]</code></pre></div><p>
it is possible to write:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">any [
    if cond-1 [
        code-1
        true ; in case code-1 returns FALSE or NONE
    ]
    if cond-2 [
        code-2
        true
    ]
    ...
]</code></pre></div><p>
Also see the <a href="#case">case</a> function for more about this code pattern.
</p>
<p>
The <a href="#all">all</a> function is a companion of <a href="#any">any</a> to test for the opposite condition, where all of the values must be true to return a true result.
</p>

<div class="see-also">See also: <a href="#all">all</a>, <a href="#and">and</a>, <a href="#case">case</a>, <a href="#or">or</a>, <a href="#switch">switch</a></div>
</section>

<hr>
<section id="any-block?">
 <a name="any-block?"></a>
 <h2>ANY-BLOCK?<a class="headerlink" href="#any-block?" title="Link to this heading">¶</a></h2>
<p>Return TRUE if value is any type of block.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">any-block? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns true only if the value is a <span class="datatype">block!</span> (any kind of block) and false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; any-object? "foo"
== #(false)

&gt;&gt; any-block? [1 2]
== #(true)

&gt;&gt; any-block? first [(1 2) 3]
== #(true)

&gt;&gt; any-block? 'a/b/c
== #(true)

&gt;&gt; any-block? 12
== #(false)</code></pre></div><p>
To learn what datatypes are blocks:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print any-block!
block! paren! path! set-path! get-path! lit-path!</code></pre></div>
<div class="see-also">See also: <a href="#any-function?">any-function?</a>, <a href="#any-string?">any-string?</a>, <a href="#any-word?">any-word?</a>, <a href="#block?">block?</a>, <a href="#paren?">paren?</a>, <a href="#path?">path?</a>, <a href="#type?">type?</a></div>
</section>

<hr>
<section id="any-function?">
 <a name="any-function?"></a>
 <h2>ANY-FUNCTION?<a class="headerlink" href="#any-function?" title="Link to this heading">¶</a></h2>
<p>Return TRUE if value is any type of function.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">any-function? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns true if the value is any type of function and returns false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; any-function? :find
== #(true)

&gt;&gt; any-function? :+
== #(true)

&gt;&gt; any-function? func [] [print "hi"]
== #(true)

&gt;&gt; any-function? 123
== #(false)</code></pre></div><p>
To learn what datatypes are functions:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print any-function!
native! action! rebcode! command! op! closure! function!</code></pre></div>
<div class="see-also">See also: <a href="#any-block?">any-block?</a>, <a href="#any-string?">any-string?</a>, <a href="#any-word?">any-word?</a>, <a href="#function?">function?</a>, <a href="#native?">native?</a>, <a href="#op?">op?</a>, <a href="#type?">type?</a></div>
</section>

<hr>
<section id="any-object?">
 <a name="any-object?"></a>
 <h2>ANY-OBJECT?<a class="headerlink" href="#any-object?" title="Link to this heading">¶</a></h2>
<p>Return TRUE if value is any type of object.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">any-object? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; any-object? system
== #(true)

&gt;&gt; any-object? try [1 / 0]
== #(true)

&gt;&gt; any-object? "foo"
== #(false)</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="any-of">
 <a name="any-of"></a>
 <h2>ANY-OF<a class="headerlink" href="#any-of" title="Link to this heading">¶</a></h2>
<p>Returns the first value(s) for which the test is not FALSE or NONE.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">any-of <span class="rebarg">word</span> <span class="rebarg">data</span> <span class="rebarg">test</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word! block!</span>] Word or block of words to set each time (local)
  data        [<span class="types">series! any-object! map! none!</span>] The series to traverse
  test        [<span class="types">block!</span>] Condition to test each time
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; any-of x [-1 4 10] [x &gt; 0]
== 4

&gt;&gt; any-of [x y] [1 4 10 8 5 -3] [(x - 2) = y]
== [10 8]</code></pre></div>
<div class="see-also">See also: <a href="#all-of">all-of</a></div>
</section>

<hr>
<section id="any-path?">
 <a name="any-path?"></a>
 <h2>ANY-PATH?<a class="headerlink" href="#any-path?" title="Link to this heading">¶</a></h2>
<p>Return TRUE if value is any type of path.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">any-path? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns true if the value is any type of <span class="datatype">path!</span> and returns false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; any-path? 'test/this
== #(true)

&gt;&gt; any-path? first [example/item: 10]
== #(true)

&gt;&gt; any-path? second [print :example/item]
== #(true)

&gt;&gt; any-path? 123
== #(false)</code></pre></div><p>
To learn what datatypes are paths:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print any-path!
path! set-path! get-path! lit-path!</code></pre></div>
</section>

<hr>
<section id="any-string?">
 <a name="any-string?"></a>
 <h2>ANY-STRING?<a class="headerlink" href="#any-string?" title="Link to this heading">¶</a></h2>
<p>Return TRUE if value is any type of string.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">any-string? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns true for any type of string, and false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; any-string? "Hello"
== #(true)

&gt;&gt; any-string? email@rebol.com
== #(true)

&gt;&gt; any-string? ftp://ftp.rebol.com
== #(true)

&gt;&gt; any-string? %dir/file.txt
== #(true)

&gt;&gt; any-string? @name
== #(true)

&gt;&gt; any-string? 11-Jan-2000
== #(false)</code></pre></div><p>
To see what datatypes are strings:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print any-string!
string! file! email! ref! url! tag!</code></pre></div>
<div class="see-also">See also: <a href="#any-block?">any-block?</a>, <a href="#any-function?">any-function?</a>, <a href="#email?">email?</a>, <a href="#file?">file?</a>, <a href="#string?">string?</a>, <a href="#type?">type?</a>, <a href="#url?">url?</a></div>
</section>

<hr>
<section id="any-word?">
 <a name="any-word?"></a>
 <h2>ANY-WORD?<a class="headerlink" href="#any-word?" title="Link to this heading">¶</a></h2>
<p>Return TRUE if value is any type of word.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">any-word? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns true for any type of word and false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; any-word? 'word
== #(true)

&gt;&gt; any-word? /word
== #(true)

&gt;&gt; any-word? #issue
== #(true)

&gt;&gt; any-word? first [set-word: 'lit-word :get-word]
== #(true)

&gt;&gt; any-word? second [set-word: 'lit-word :get-word]
== #(true)

&gt;&gt; any-word? third [set-word: 'lit-word :get-word]
== #(true)

&gt;&gt; any-word? 123
== #(false)</code></pre></div><p>
To see what datatypes are words:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print any-word!
word! set-word! get-word! lit-word! refinement! issue!</code></pre></div>
<div class="see-also">See also: <a href="#any-block?">any-block?</a>, <a href="#any-function?">any-function?</a>, <a href="#any-string?">any-string?</a>, <a href="#type?">type?</a></div>
</section>

<hr>
<section id="append">
 <a name="append"></a>
 <h2>APPEND<a class="headerlink" href="#append" title="Link to this heading">¶</a></h2>
<p>Inserts element(s) at tail; for series, returns head.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">append <span class="rebarg">series</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! port! map! gob! object! bitset!</span>] Any position (modified)
  value       [<span class="types">any-type!</span>] The value to insert
<span class="tit">REFINEMENTS:</span>
  /part       Limits to a given length or position
   range      [<span class="types">number! series! pair!</span>] 
  /only       Only insert a block as a single value (not the contents of the block)
  /dup        Duplicates the insert a specified number of times
   count      [<span class="types">number! pair!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#append">append</a> function is a shortcut for doing an <a href="#insert">insert</a> at the tail of any type of <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a> and returning the head:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">head insert tail series value</code></pre></div><p>
Basic examples:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">string: copy "hello"
probe append string " there"
"hello there"

file: copy %file
probe append file ".txt"
%file.txt

url: copy http://
probe append url "www.rebol.com"
http://www.rebol.com</code></pre></div><p>
The /only refinement forces a block to be appended as a single block element, rather than appending the separate elements of the block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">block: copy [1 2 3]
probe append block [4 5 6]
[1 2 3 4 5 6]

block: copy [1 2 3]
probe append/only block [4 5 6]
[1 2 3 [4 5 6]]</code></pre></div><p>
To learn more about the operation of the other refinements, see the <a href="#insert">insert</a> function.
</p>

<div class="see-also">See also: <a href="#change">change</a>, <a href="#insert">insert</a>, <a href="#remove">remove</a>, <a href="#repend">repend</a></div>
</section>

<hr>
<section id="apply">
 <a name="apply"></a>
 <h2>APPLY<a class="headerlink" href="#apply" title="Link to this heading">¶</a></h2>
<p>Apply a function to a reduced block of arguments.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">apply <span class="rebarg">func</span> <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  func        [<span class="types">any-function!</span>] Function value to apply
  block       [<span class="types">block!</span>] Block of args, reduced first (unless /only)
<span class="tit">REFINEMENTS:</span>
  /only       Use arg values as-is, do not reduce the block
</pre>

<h6>Description:</h6>
<p>
When you evaluate a function, you normally provide any arguments directly in-line with its call:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">append data 123</code></pre></div><p>
However, there are times when you want to store the arguments as a single block and pass them to the function. This is the purpose of the <a href="#apply">apply</a> function. The above example can be written as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">apply :append [data 123]</code></pre></div><p>
or, using a variable to hold the block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">args: [data 123]
apply :append args</code></pre></div><p>
If any arguments are missing from the block, a <span class="datatype">none!</span> is passed instead:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: [456]
apply :append [data]
probe data
[456 none]</code></pre></div><p>
Function refinements can also be passed in the order they are specified by the arguments spec block. For example, we can see:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; ? append
USAGE:
    APPEND series value /part length /only /dup count</code></pre></div><p>
So in this example we use the /dup refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: [456]
apply :append [data 1 none none none true 3]
probe data
[456 1 1 1]</code></pre></div><p>
Note that the refinement itself must be set to true.
</p>

<div class="see-also">See also: <a href="#case">case</a>, <a href="#do">do</a>, <a href="#switch">switch</a></div>
</section>

<hr>
<section id="arccosine">
 <a name="arccosine"></a>
 <h2>ARCCOSINE<a class="headerlink" href="#arccosine" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric arccosine (in degrees by default).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">arccosine <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number!</span>] 
<span class="tit">REFINEMENTS:</span>
  /radians    Returns result in radians
</pre>

<h6>Description:</h6>
<p>
The <a href="#arccosine">arccosine</a> provides the inverse of the <a href="#cosine">cosine</a> function.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print arccosine .5
60.0</code></pre></div><p>
Note that arccosine goes to infinity at 90 degrees and will cause a numeric overflow.
</p>

<div class="see-also">See also: <a href="#arcsine">arcsine</a>, <a href="#arctangent">arctangent</a>, <a href="#cosine">cosine</a>, <a href="#exp">exp</a>, <a href="#log-10">log-10</a>, <a href="#log-2">log-2</a>, <a href="#log-e">log-e</a>, <a href="#power">power</a>, <a href="#sine">sine</a>, <a href="#square-root">square-root</a>, <a href="#tangent">tangent</a></div>
</section>

<hr>
<section id="arcsine">
 <a name="arcsine"></a>
 <h2>ARCSINE<a class="headerlink" href="#arcsine" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric arcsine (in degrees by default).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">arcsine <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number!</span>] 
<span class="tit">REFINEMENTS:</span>
  /radians    Returns result in radians
</pre>

<h6>Description:</h6>
<p>
The <a href="#arcsine">arcsine</a> provides the inverse of the <a href="#sine">sine</a> function.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; arcsine .5
== 30.0</code></pre></div><p>
Note that arccsine goes to infinity at 0 and each 180 degrees and will cause a numeric overflow.
</p>

<div class="see-also">See also: <a href="#arccosine">arccosine</a>, <a href="#arctangent">arctangent</a>, <a href="#cosine">cosine</a>, <a href="#exp">exp</a>, <a href="#log-10">log-10</a>, <a href="#log-2">log-2</a>, <a href="#log-e">log-e</a>, <a href="#power">power</a>, <a href="#sine">sine</a>, <a href="#square-root">square-root</a>, <a href="#tangent">tangent</a></div>
</section>

<hr>
<section id="arctangent">
 <a name="arctangent"></a>
 <h2>ARCTANGENT<a class="headerlink" href="#arctangent" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric arctangent (in degrees by default).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">arctangent <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number!</span>] 
<span class="tit">REFINEMENTS:</span>
  /radians    Returns result in radians
</pre>

<h6>Description:</h6>
<p>
The <a href="#arctangent">arctangent</a> function provides the inverse of the <a href="#tangent">tangent</a> function.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; arctangent .22
== 12.4074185274007</code></pre></div>
<div class="see-also">See also: <a href="#arccosine">arccosine</a>, <a href="#arcsine">arcsine</a>, <a href="#cosine">cosine</a>, <a href="#exp">exp</a>, <a href="#log-10">log-10</a>, <a href="#log-2">log-2</a>, <a href="#log-e">log-e</a>, <a href="#power">power</a>, <a href="#sine">sine</a>, <a href="#square-root">square-root</a>, <a href="#tangent">tangent</a></div>
</section>

<hr>
<section id="arctangent2">
 <a name="arctangent2"></a>
 <h2>ARCTANGENT2<a class="headerlink" href="#arctangent2" title="Link to this heading">¶</a></h2>
<p>Returns the angle of the point, when measured counterclockwise from a circle's X axis (where 0x0 represents the center of the circle). The return value is in interval -180 to 180 degrees.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">arctangent2 <span class="rebarg">point</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  point       [<span class="types">pair!</span>] X/Y coordinate in space
<span class="tit">REFINEMENTS:</span>
  /radians    Result is in radians instead of degrees
</pre>
</section>

<hr>
<section id="array">
 <a name="array"></a>
 <h2>ARRAY<a class="headerlink" href="#array" title="Link to this heading">¶</a></h2>
<p>Makes and initializes a series of a given size.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">array <span class="rebarg">size</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  size        [<span class="types">integer! block!</span>] Size or block of sizes for each dimension
<span class="tit">REFINEMENTS:</span>
  /initial    Specify an initial value for all elements
   value       Initial value (will be called each time if a function)
</pre>

<h6>Description:</h6>
<p>
In REBOL, arrays are simply blocks that are initialized to a specific size with all elements set to an initial value (v:none by default). The <a href="#array">array</a> function is used to create and initialize arrays.
</p>
<p>
Supplying a single integer as the argument to <a href="#array">array</a> will create an array of a single dimension. The example below creates a five element array with values set to none:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; block: array 5
== [#(none) #(none) #(none) #(none) #(none)]

&gt;&gt; length? block
== 5</code></pre></div><p>
To initialize an array to values other than NONE, use the /initial refinement. The example below intializes a block with zero values:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; block: array/initial 5 0
== [0 0 0 0 0]</code></pre></div><p>
To create an array of multiple dimensions, provide a block of integers as the argument to the <a href="#array">array</a> function. Each integer specifies the size of that dimension of the array. (In REBOL, such multidimensional arrays are created using blocks of blocks.)
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; xy-block: array [2 3]
== [[#(none) #(none) #(none)] [#(none) #(none) #(none)]]

&gt;&gt; xy-block: array/initial [2 3] 0
== [[0 0 0] [0 0 0]]</code></pre></div><p>
Once an array has been created, you can use paths or the <a href="#pick">pick</a> and <a href="#poke">poke</a> functions to set and get values of the block based on their indices:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">block/3: 1000
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
probe xy-block</code></pre></div>
<h6>Coding Style Notes</h6><p>
REBOL uses the concept of expandable series for holding and manipulating data, rather than the concept of fixed size arrays. For example, in REBOL you would normally write:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">block: copy []
repeat n 5 [append block n]</code></pre></div><p>
rather than:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">block: array 5
repeat n 5 [poke block n n]</code></pre></div><p>
In other words, REBOL does not require you to specify the size of data arrays (blocks, bytes, or strings) in advance. They are dynamic.
</p>

<div class="see-also">See also: <a href="#make">make</a>, <a href="#pick">pick</a>, <a href="#poke">poke</a></div>
</section>

<hr>
<section id="as">
 <a name="as"></a>
 <h2>AS<a class="headerlink" href="#as" title="Link to this heading">¶</a></h2>
<p>Coerce a series into a compatible datatype without copying it.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">as <span class="rebarg">type</span> <span class="rebarg">spec</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  type        [<span class="types">any-block! any-string! datatype!</span>] The datatype or example value
  spec        [<span class="types">any-block! any-string!</span>] The series to coerce
</pre>
</section>

<hr>
<section id="as-blue">
 <a name="as-blue"></a>
 <h2>AS-BLUE<a class="headerlink" href="#as-blue" title="Link to this heading">¶</a></h2>
<p>Decorates a value with blue ANSI escape codes</p>

<h6>Usage:</h6>
<pre class="usage fs-6">as-blue <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>
</section>

<hr>
<section id="as-cyan">
 <a name="as-cyan"></a>
 <h2>AS-CYAN<a class="headerlink" href="#as-cyan" title="Link to this heading">¶</a></h2>
<p>Decorates a value with cyan ANSI escape codes</p>

<h6>Usage:</h6>
<pre class="usage fs-6">as-cyan <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>
</section>

<hr>
<section id="as-gray">
 <a name="as-gray"></a>
 <h2>AS-GRAY<a class="headerlink" href="#as-gray" title="Link to this heading">¶</a></h2>
<p>Decorates a value with gray ANSI escape codes</p>

<h6>Usage:</h6>
<pre class="usage fs-6">as-gray <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>
</section>

<hr>
<section id="as-green">
 <a name="as-green"></a>
 <h2>AS-GREEN<a class="headerlink" href="#as-green" title="Link to this heading">¶</a></h2>
<p>Decorates a value with green ANSI escape codes</p>

<h6>Usage:</h6>
<pre class="usage fs-6">as-green <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>
</section>

<hr>
<section id="as-pair">
 <a name="as-pair"></a>
 <h2>AS-PAIR<a class="headerlink" href="#as-pair" title="Link to this heading">¶</a></h2>
<p>Combine X and Y values into a pair.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">as-pair <span class="rebarg">x</span> <span class="rebarg">y</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  x           [<span class="types">number!</span>] 
  y           [<span class="types">number!</span>] 
</pre>

<h6>Description:</h6>
<p>
Provides a shortcut for creating <span class="datatype">pair!</span> values from separate X and
Y integers.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print as-pair 100 50
100x50</code></pre></div>
<div class="see-also">See also: <a href="#pair?">pair?</a>, <a href="#to-pair">to-pair</a></div>
</section>

<hr>
<section id="as-purple">
 <a name="as-purple"></a>
 <h2>AS-PURPLE<a class="headerlink" href="#as-purple" title="Link to this heading">¶</a></h2>
<p>Decorates a value with purple ANSI escape codes</p>

<h6>Usage:</h6>
<pre class="usage fs-6">as-purple <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>
</section>

<hr>
<section id="as-red">
 <a name="as-red"></a>
 <h2>AS-RED<a class="headerlink" href="#as-red" title="Link to this heading">¶</a></h2>
<p>Decorates a value with red ANSI escape codes</p>

<h6>Usage:</h6>
<pre class="usage fs-6">as-red <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>
</section>

<hr>
<section id="as-white">
 <a name="as-white"></a>
 <h2>AS-WHITE<a class="headerlink" href="#as-white" title="Link to this heading">¶</a></h2>
<p>Decorates a value with white ANSI escape codes</p>

<h6>Usage:</h6>
<pre class="usage fs-6">as-white <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>
</section>

<hr>
<section id="as-yellow">
 <a name="as-yellow"></a>
 <h2>AS-YELLOW<a class="headerlink" href="#as-yellow" title="Link to this heading">¶</a></h2>
<p>Decorates a value with yellow ANSI escape codes</p>

<h6>Usage:</h6>
<pre class="usage fs-6">as-yellow <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>
</section>

<hr>
<section id="ascii?">
 <a name="ascii?"></a>
 <h2>ASCII?<a class="headerlink" href="#ascii?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if value or string is in ASCII character range (below 128).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">ascii? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-string! char! integer!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; ascii? "hello"
== #(true)

&gt;&gt; ascii? "česko"
== #(false) ;; because (to integer! #"č") == 269</code></pre></div>
<div class="see-also">See also: <a href="#latin?">latin?</a>, <a href="#utf8?">utf8?</a></div>
</section>

<hr>
<section id="asin">
 <a name="asin"></a>
 <h2>ASIN<a class="headerlink" href="#asin" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric arcsine.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">asin <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">decimal!</span>] In radians
</pre>
</section>

<hr>
<section id="ask">
 <a name="ask"></a>
 <h2>ASK<a class="headerlink" href="#ask" title="Link to this heading">¶</a></h2>
<p>Ask the user for input.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">ask <span class="rebarg">question</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  question    [<span class="types">series!</span>] Prompt to user
<span class="tit">REFINEMENTS:</span>
  /hide       Turns off echoing inputs
  /char       Waits only on single key press and returns char as a result
   limit      [<span class="types">bitset! string! block! char! none!</span>] Limit input to specified chars or control words
</pre>

<h6>Description:</h6>
<p>
Provides a common prompting function that is the same as a <a href="#prin">prin</a> followed by an <a href="#input">input</a>. The resulting input will
have spaces trimmed from its head and tail. The /hide refinement hides input with "*" characters. The function returns a string!.
</p>
<p>
Example, where the user enters Luke as input:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">ask "Your name, please? "
Your name, please? Luke
== "Luke"</code></pre></div>
<div class="see-also">See also: <a href="#confirm">confirm</a>, <a href="#input">input</a>, <a href="#prin">prin</a>, <a href="#print">print</a></div>
</section>

<hr>
<section id="assert">
 <a name="assert"></a>
 <h2>ASSERT<a class="headerlink" href="#assert" title="Link to this heading">¶</a></h2>
<p>Assert that condition is true, else cause an assertion error.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">assert <span class="rebarg">conditions</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  conditions  [<span class="types">block!</span>] 
<span class="tit">REFINEMENTS:</span>
  /type       Safely check datatypes of variables (words and paths)
</pre>

<h6>Description:</h6>
<p>
In code, it is common to check conditions that should always be valid or true. For example, a check may be made for a value to be in range or of a given datatype.
</p>
<p>
Since the conditions are always supposed to be true, it's often not worth the effort to provide a detailed error message or explanation if the condition fails, and often such information would only be meaningful to the programmer, not the end user.
</p>
<p>
To make it easier to check such conditions, the <a href="#assert">assert</a> function is provided.
</p>
<p>
Assert can check "truth" conditions, or with a refinement, it can check datatype validity conditions.
</p>

<h7>Asserting truth</h7><p>
To check truth conditions, the argument of <a href="#assert">assert</a> is a block of one or more conditions, and each is checked (similar to <a href="#all">all</a>) to be true:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">num: 10
assert [num &gt; 20]
** Script error: assertion failed for: [num &gt; 20]
** Where: assert
** Near: assert [num &gt; 20]</code></pre></div><p>
Note that for compound assertions, the error message will indicate the assertion that failed:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">num: 10
age: 20
assert [num &gt; 0 age &gt; 50]
** Script error: assertion failed for: [age &gt; 50]
** Where: assert
** Near: assert [num &gt; 0 age &gt; 50]</code></pre></div><p>
Look at the error line closely, and you can tell which one failed.
</p>
<p>
Note: only the first three elements of the failed assertion will be shown (to help avoid long error lines.)
</p>

<h7>Asserting datatypes</h7><p>
It is also common to validate datatypes using the /type refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">age: "37"
name: "Bob"
assert/type [age integer! name string!]
** Script error: datatype assertion failed for: age
** Where: assert
** Near: assert/type [age integer! name string!]</code></pre></div><p>
It fails because age is actually a string, not an integer.
</p>
<p>
The <a href="#assert">assert</a> function is useful for validating value before a section of code that depends on those value:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">assert/type [
    spec object!
    body block!
    spec/size number!
    spec/name [string! none!]
    spec/options [block! none!]
]</code></pre></div><p>
Note that <a href="#assert">assert</a> is safe to use on all function datatypes. The functions will not be evaluated as part of the process; therefore, <a href="#assert">assert</a> is an easy way to prevent function passage in unwanted cases.
</p>

<div class="see-also">See also: <a href="#all">all</a>, <a href="#try">try</a></div>
</section>

<hr>
<section id="at">
 <a name="at"></a>
 <h2>AT<a class="headerlink" href="#at" title="Link to this heading">¶</a></h2>
<p>Returns the series at the specified index, relative to the current position.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">at <span class="rebarg">series</span> <span class="rebarg">index</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port!</span>] 
  index       [<span class="types">number! logic! pair!</span>] 
</pre>

<h6>Description:</h6>
<p>
Provides a simple way to index into any type of <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a>. <a href="#at">at</a> returns the series at the new index point.
</p>
<p>
Note that the operation is relative to the current position within the series.
</p>
<p>
A positive integer N moves to the position N in the series:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">numbers: [11 22 33]
print at numbers 2
22 33</code></pre></div><p>
An index of 0 is the same as an index of 1:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print at numbers 0
11 22 33</code></pre></div><p>
Using a negative index N, you can go N values backwards in a series:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">numbers: at numbers 3
print numbers
33

print at numbers -1
22 33</code></pre></div><p>
More examples, combined with other series functions:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">words: [grand grape great good]
print first at words 2
grape

remove at words 2
insert at words 3 [super]
probe words
[grand great super good]</code></pre></div>
<div class="see-also">See also: <a href="#head">head</a>, <a href="#pick">pick</a>, <a href="#skip">skip</a>, <a href="#tail">tail</a></div>
</section>

<hr>
<section id="atan">
 <a name="atan"></a>
 <h2>ATAN<a class="headerlink" href="#atan" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric arctangent.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">atan <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">decimal!</span>] In radians
</pre>
</section>

<hr>
<section id="atan2">
 <a name="atan2"></a>
 <h2>ATAN2<a class="headerlink" href="#atan2" title="Link to this heading">¶</a></h2>
<p>Returns the angle of the point y/x in the interval [-pi,+pi] radians.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">atan2 <span class="rebarg">y</span> <span class="rebarg">x</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  y           [<span class="types">decimal!</span>] The proportion of the Y-coordinate
  x           [<span class="types">decimal!</span>] The proportion of the X-coordinate
</pre>
</section>

<hr>
<section id="attempt">
 <a name="attempt"></a>
 <h2>ATTEMPT<a class="headerlink" href="#attempt" title="Link to this heading">¶</a></h2>
<p>Tries to evaluate a block and returns result or NONE on error.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">attempt <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block! paren!</span>] 
<span class="tit">REFINEMENTS:</span>
  /safer      Capture all possible errors and exceptions
</pre>

<h6>Description:</h6>
<p>
The <a href="#attempt">attempt</a> function is a shortcut for the frequent case of:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">error? try [block]</code></pre></div><p>
More accurately, this is performed:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if not error? try [set/any 'val block] [val]</code></pre></div><p>
The format for <a href="#attempt">attempt</a> is:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">attempt [block]</code></pre></div><p>
<a href="#attempt">attempt</a> is useful where you either do not care about the error result or you want to make simple types of decisions based on the error.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">attempt [make-dir %fred]</code></pre></div><p>
<a href="#attempt">attempt</a> returns the result of the block if an error did not occur.  If an error did occur, a none is returned.
</p>
<p>
In the line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">value: attempt [load %data]
probe value
none</code></pre></div><p>
the value is set to none if the %data file cannot be loaded (e.g. it is missing or contains an error).  This allows you to write conditional code such as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if not value: attempt [load %data] [print "Problem"]
Problem</code></pre></div><p>
Or code such as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">value: any [attempt [load %data] [12 34]]
probe value
[12 34]</code></pre></div>
<div class="see-also">See also: <a href="#error?">error?</a>, <a href="#try">try</a></div>
</section>

<hr>
<section id="atz">
 <a name="atz"></a>
 <h2>ATZ<a class="headerlink" href="#atz" title="Link to this heading">¶</a></h2>
<p>Returns the series at the specified 0-based index, relative to the current position.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">atz <span class="rebarg">series</span> <span class="rebarg">index</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port!</span>] 
  index       [<span class="types">number! logic! pair!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; blk: [1 2 3 4]
== [1 2 3 4]

&gt;&gt; at blk 2
== [2 3 4]

&gt;&gt; atz blk 2
== [3 4]</code></pre></div>
<div class="see-also">See also: <a href="#at">at</a></div>
</section>

<hr>
<section id="average">
 <a name="average"></a>
 <h2>AVERAGE<a class="headerlink" href="#average" title="Link to this heading">¶</a></h2>
<p>Returns the average of all values in a block</p>

<h6>Usage:</h6>
<pre class="usage fs-6">average <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block! vector! paren!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; average [1 2 3]
== 2</code></pre></div>
</section>

<hr>
<section id="back">
 <a name="back"></a>
 <h2>BACK<a class="headerlink" href="#back" title="Link to this heading">¶</a></h2>
<p>Returns the series at its previous position.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">back <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port!</span>] 
</pre>

<h6>Description:</h6>
<p>
Works on any type of <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a>. If the series is at its head, it will remain at its head. <a href="#back">back</a> will not go past the head, nor will it wrap to the tail.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print back tail "abcd"
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
1</code></pre></div>
<div class="see-also">See also: <a href="#head">head</a>, <a href="#head?">head?</a>, <a href="#last">last</a>, <a href="#next">next</a>, <a href="#tail">tail</a>, <a href="#tail?">tail?</a></div>
</section>

<hr>
<section id="binary">
 <a name="binary"></a>
 <h2>BINARY<a class="headerlink" href="#binary" title="Link to this heading">¶</a></h2>
<p>Entry point of the binary DSL (Bincode)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">binary <span class="rebarg">ctx</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  ctx         [<span class="types">object! binary! integer! none!</span>] Bincode context. If none, it will create a new one.
<span class="tit">REFINEMENTS:</span>
  /init       Initializes buffers in the context
   spec       [<span class="types">binary! integer! none!</span>] 
  /write      Write data into output buffer
   data       [<span class="types">binary! block!</span>] Data dialect
  /read       Read data from the input buffer
   code       [<span class="types">word! block! integer! binary!</span>] Input encoding
  /into       Put READ results in out block, instead of creating a new block
   out        [<span class="types">block!</span>] Target block for results, when /into is used
  /with       Additional input argument
   num        [<span class="types">integer!</span>] Bits/bytes number used with WORD! code type to resolve just single value
</pre>

<h6>Description:</h6>
<p>
This is quite complex dialect which requires own documentation. But it may be
used for binary data streaming in both directions like:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; stream: binary bin: #{}
== make object! [
    type: 'bincode
    buffer: #{}
    buffer-write: #{}
    r-mask: 0
    w-mask: 0
]

&gt;&gt; binary/write stream [UI8 1 SI16 -2 UI16BYTES "hello"]
== make object! [
    type: 'bincode
    buffer: #{01FFFE000568656C6C6F}
    buffer-write: #{}
    r-mask: 0
    w-mask: 0
]

&gt;&gt; bin
== #{01FFFE000568656C6C6F}

&gt;&gt; binary/read stream 'UI8
== 1

&gt;&gt; binary/read stream [SI16 UI16BYTES]
== [-2 #{68656C6C6F}]</code></pre></div>
</section>

<hr>
<section id="binary?">
 <a name="binary?"></a>
 <h2>BINARY?<a class="headerlink" href="#binary?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">binary? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; binary? #{13ff acd0}
== #(true)

&gt;&gt; binary? 2#{00001000}
== #(true)

&gt;&gt; binary? 1234
== #(false)</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="bind">
 <a name="bind"></a>
 <h2>BIND<a class="headerlink" href="#bind" title="Link to this heading">¶</a></h2>
<p>Binds words to the specified context.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">bind <span class="rebarg">word</span> <span class="rebarg">context</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">block! any-word!</span>] A word or block (modified) (returned)
  context     [<span class="types">any-word! object! module! port!</span>] A reference to the target context
<span class="tit">REFINEMENTS:</span>
  /copy       Bind and return a deep copy of a block, don't modify original
  /only       Bind only first block (not deep)
  /new        Add to context any new words found
  /set        Add to context any new set-words found
</pre>

<h6>Description:</h6>
<p>
Binds meaning to words in a block. That is, it gives words a context in which they can be interpreted. This allows blocks to be exchanged between different contexts, which permits their words to be understood. For instance a function may want to treat words in a global database as being local to that function.
</p>
<p>
The second argument to <a href="#bind">bind</a> is a word from the context in which the block is to be bound. Normally, this is a word from the local context (e.g. one of the function arguments), but it can be a word from any context within the system.
</p>
<p>
<a href="#bind">bind</a> will modify the block it is given. To avoid that, use the /copy refinement. It will create a new block that is returned as the result.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">words: [a b c]
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
11:30</code></pre></div><p>
Editor note: Describe /new here
Editor note: Describe /set here
</p>

<div class="see-also">See also: <a href="#bind?">bind?</a>, <a href="#do">do</a>, <a href="#does">does</a>, <a href="#func">func</a>, <a href="#function">function</a>, <a href="#import">import</a>, <a href="#make">make</a>, <a href="#use">use</a></div>
</section>

<hr>
<section id="bitset?">
 <a name="bitset?"></a>
 <h2>BITSET?<a class="headerlink" href="#bitset?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">bitset? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; bitset? make bitset! "abc"
== #(true)

&gt;&gt; bitset? charset "abc"
== #(true)

&gt;&gt; bitset? 123
== #(false)</code></pre></div>
<div class="see-also">See also: <a href="#charset">charset</a></div>
</section>

<hr>
<section id="block?">
 <a name="block?"></a>
 <h2>BLOCK?<a class="headerlink" href="#block?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">block? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; block? [1 2 3]
== #(true)

&gt;&gt; block? "1 2 3"
== #(false)

&gt;&gt; data: load "1 2 3"  ;  converts "1 2 3" into a block
== [1 2 3]</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="blur">
 <a name="blur"></a>
 <h2>BLUR<a class="headerlink" href="#blur" title="Link to this heading">¶</a></h2>
<p>Blur (Gaussian) given image</p>

<h6>Usage:</h6>
<pre class="usage fs-6">blur <span class="rebarg">image</span> <span class="rebarg">radius</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  image       [<span class="types">image!</span>] Image to blur (modified)
  radius      [<span class="types">number!</span>] Blur amount
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">img: load %same/image.png
blur img 5 ;; blurs the original image!</code></pre></div>
</section>

<hr>
<section id="body-of">
 <a name="body-of"></a>
 <h2>BODY-OF<a class="headerlink" href="#body-of" title="Link to this heading">¶</a></h2>
<p>Returns a copy of the body of any function, any object, map or struct</p>

<h6>Usage:</h6>
<pre class="usage fs-6">body-of <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-function! any-object! map! struct!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; body-of object [a: 1]
== [
    a: 1
]

&gt;&gt; body-of func[][1 + 1]
== [1 + 1]</code></pre></div>
<div class="see-also">See also: <a href="#keys-of">keys-of</a>, <a href="#reflect">reflect</a>, <a href="#spec-of">spec-of</a>, <a href="#title-of">title-of</a>, <a href="#types-of">types-of</a>, <a href="#values-of">values-of</a>, <a href="#words-of">words-of</a></div>
</section>

<hr>
<section id="break">
 <a name="break"></a>
 <h2>BREAK<a class="headerlink" href="#break" title="Link to this heading">¶</a></h2>
<p>Breaks out of a loop, while, until, repeat, foreach, etc.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">break</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /return     Forces the loop function to return a value
   value      [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#break">break</a> function stops loop functions.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">repeat n 5 [
    print n
    if n &gt; 2 [break]
]
1
2
3</code></pre></div><p>
The current loop is immediately terminated and evaluation resumes after the <a href="#repeat">repeat</a> function.
</p>

<h6>Return Value</h6><p>
The <a href="#break">break</a> /return refinement will return a value from a loop. It is commonly used to return a specific value or pass to a conditional expression when the loop is terminated early.
</p>
<p>
Here's an example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print repeat n 5 [
    if n &gt; pi [break/return n]
    none
]
4</code></pre></div><p>
An example using <a href="#foreach">foreach</a> :
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">values: [8:30 breakfast 12:00 lunch 5:00 dinner]
meal: foreach [time event] [
    if time &gt; 14:00 [break/return event]
    none
]
probe meal
dinner</code></pre></div>
<h6>Important Scoping Rule</h6><p>
The <a href="#break">break</a> function acts immediately on the "closest block".
</p>
<p>
Although <a href="#break">break</a> can be placed anywhere within the block being repeated, even within a sub-block or function, because <a href="#break">break</a> is a function that is not directly bound to the loop, it will break the closest loop, not necessarily the intended loop. This does not affect most programs but could affect custom-made loop functions.
</p>
<p>
In this example, even though the <a href="#break">break</a> appears in the <a href="#repeat">repeat</a> loop, it applies to the a-loop <a href="#loop">loop</a> block and has no effect on the outer <a href="#repeat">repeat</a> loop.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">a-loop: func [count block] [loop count block]
repeat a 3 [
    print a
    a-loop 4 [break]
]
1
2
3</code></pre></div>
<div class="see-also">See also: <a href="#catch">catch</a>, <a href="#continue">continue</a>, <a href="#exit">exit</a>, <a href="#for">for</a>, <a href="#forall">forall</a>, <a href="#foreach">foreach</a>, <a href="#forever">forever</a>, <a href="#forskip">forskip</a>, <a href="#loop">loop</a>, <a href="#repeat">repeat</a>, <a href="#return">return</a>, <a href="#until">until</a>, <a href="#while">while</a></div>
</section>

<hr>
<section id="browse">
 <a name="browse"></a>
 <h2>BROWSE<a class="headerlink" href="#browse" title="Link to this heading">¶</a></h2>
<p>Open web browser to a URL or local file.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">browse <span class="rebarg">url</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  url         [<span class="types">url! file! none!</span>] 
</pre>

<h6>Description:</h6>
<p>
If the browser cannot be found, nothing will happen.
</p>

</section>

<hr>
<section id="bugs">
 <a name="bugs"></a>
 <h2>BUGS<a class="headerlink" href="#bugs" title="Link to this heading">¶</a></h2>
<p>View bug database.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">bugs</span></pre>
</section>

<hr>
<section id="call">
 <a name="call"></a>
 <h2>CALL<a class="headerlink" href="#call" title="Link to this heading">¶</a></h2>
<p>Run another program; return immediately with the process ID.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">call <span class="rebarg">command</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  command     [<span class="types">any-string! block! file!</span>] An OS-local command line (quoted as necessary), a block with arguments, or an executable file
<span class="tit">REFINEMENTS:</span>
  /wait       Wait for command to terminate and then return the exit code
  /console    Runs command with I/O redirected to console
  /shell      Forces command to be run from shell
  /info       Returns process information object containing the ID of the process (or 0 if failed to run), includes the exit code when used with /wait
  /input      
   in         [<span class="types">string! binary! file! none!</span>] Redirects stdin to in
  /output     
   out        [<span class="types">string! binary! file! none!</span>] Redirects stdout to out
  /error      
   err        [<span class="types">string! binary! file! none!</span>] Redirects stderr to err
</pre>

<h6>Description:</h6>
<p>
The <a href="#call">call</a> function interfaces to the operating system's command shell to execute programs, shell commands, and redirect command input and output.
</p>
<p>
<a href="#call">call</a> is normally blocked by the security level specified with the <a href="#secure">secure</a> function. To use it, you must change your <a href="#secure">secure</a> settings or run the script with reduced security (at your own risk):
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure call</code></pre></div><p>
The <a href="#call">call</a> function accepts one argument, which can be a string or a block specifying a shell command and its arguments. The following example shows a string as the <a href="#call">call</a> argument.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">call "cp source.txt dest.txt"</code></pre></div><p>
Use a block argument with <a href="#call">call</a> when you want to include REBOL values in the call to a shell command, as shown in the following example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">source: %source.txt
dest: %dest.txt
call reduce ["cp" source dest]</code></pre></div><p>
The <a href="#call">call</a> function translates the file names in a block to the notation used by the shell. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">[dir %/c/windows]</code></pre></div><p>
will convert the file name to windows shell syntax before doing it.
</p>
<p>
When shell commands are called, they normally run as a separate process in parallel with REBOL. They are asynchronous to REBOL. However, there are times when you want to wait for a shell command to finish, such as when you are executing multiple shell commands.
</p>
<p>
In addition, every shell command has a return code, which normally indicates the success or failure of the command. Typically, a shell command returns zero when it is successful and a non-zero value when it is unsuccessful.
</p>
<p>
The /wait refinement causes the <a href="#call">call</a> function to wait for a command's return code and return it to the REBOL program. You can then use the return code to verify that a command executed successfully, as shown in the following example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if zero? call/wait "dir" [
    print "worked"
]</code></pre></div><p>
In the above example, <a href="#call">call</a> successfully executes the Windows dir command, which is indicated by the zero return value. However, in the next example, <a href="#call">call</a> is unsuccessful at executing the xcopy command, which is indicated by the return value other than zero.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if not zero? code: call/wait "xcopy" [
    print ["failed:" code]
]</code></pre></div><p>
In Windows and Unix (Linux), input to a shell command can be redirected from a file, URL, string, or port. By default, a shell command's output and errors are ignored by REBOL. However, shell command output and errors can be redirected to a file, URL, port, string, or the REBOL console.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">instr: "data"
outstr: copy ""
errstr: copy ""
call/input/output/error "sort" instr outstr errstr
print [outstr errstr]</code></pre></div><p>
See the REBOL Command Shell Interface documentation for more details.
</p>
<p>
Editor note: Proper link to the REBOL Command Shell Interface?
</p>

<div class="see-also">See also: <a href="#do">do</a>, <a href="#launch">launch</a></div>
</section>

<hr>
<section id="case">
 <a name="case"></a>
 <h2>CASE<a class="headerlink" href="#case" title="Link to this heading">¶</a></h2>
<p>Evaluates each condition, and when true, evaluates what follows it.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">case <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block!</span>] Block of cases (conditions followed by values)
<span class="tit">REFINEMENTS:</span>
  /all        Evaluate all cases (do not stop at first true case)
</pre>

<h6>Description:</h6>
<p>
The <a href="#case">case</a> function provides a useful way to evaluate different expressions depending on specific conditions. It differs from the <a href="#switch">switch</a> function because the conditions are evaluated and can be an expression of any length.
</p>
<p>
The basic form of <a href="#case">case</a> is:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">case [
    cond1 [code1]
    cond2 [code2]
    cond3 [code3]
]</code></pre></div><p>
The if a condition is true (that is, it is not false or none ) then the block that follows it is evaluated, otherwise the next condition is evaluated.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">num: 50
case [
    num &lt; 10 [print "small"]
    num &lt; 100 [print "medium"]
    num &lt; 1000 [print "large"] 
]
medium</code></pre></div><p>
To create a default case, simply use true as your last condition:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">num: 10000
case [
    num &lt; 10 [print "small"]
    num &lt; 100 [print "medium"]
    num &lt; 1000 [print "large"] 
    true [print "huge"]
]
huge</code></pre></div>
<h6>Return Value</h6><p>
The <a href="#case">case</a> function will return the value of the last expression it evaluated. This can come in handy:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">num: 50
value: case [
    num &lt; 10 [num + 2]
    num &lt; 100 [num / 2]
    true [0]
]
print value
25</code></pre></div>
<h6>Evaluating All</h6><p>
Normally the <a href="#case">case</a> function stops after the first true condition is found and its block evaluated. However, the /all option forces <a href="#case">case</a> to evaluate the expressions for all true conditions.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">num: 50
case/all [
    num &lt; 10 [print "small"]
    num &lt; 100 [print "medium"]
    num &lt; 1000 [print "large"] 
]
medium
large</code></pre></div>
<div class="see-also">See also: <a href="#either">either</a>, <a href="#find">find</a>, <a href="#if">if</a>, <a href="#select">select</a>, <a href="#switch">switch</a></div>
</section>

<hr>
<section id="catch">
 <a name="catch"></a>
 <h2>CATCH<a class="headerlink" href="#catch" title="Link to this heading">¶</a></h2>
<p>Catches a throw from a block and returns its value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">catch <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block!</span>] Block to evaluate
<span class="tit">REFINEMENTS:</span>
  /name       Catches a named throw
   word       [<span class="types">word! block!</span>] One or more names
  /all        Catches all throws, named and unnamed
  /quit       Special catch for QUIT native
  /with       
   callback   [<span class="types">block! function!</span>] Code to be evaluated on a catch
</pre>

<h6>Description:</h6>
<p>
<a href="#catch">catch</a> and <a href="#throw">throw</a> go together. They provide a way to exit from a block without evaluating the rest of the block.
To use it, provide <a href="#catch">catch</a> with a block to evaluate. If within that block a <a href="#throw">throw</a> is evaluated, it will return from the <a href="#catch">catch</a> at that point.
</p>
<p>
The result of the <a href="#catch">catch</a> will be whatever was passed as the argument to the <a href="#throw">throw</a>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">write %file.txt "i am a happy little file with no real purpose"
print catch [
    if exists? %file.txt [throw "Doc found"]
    "Doc not found"
]
Doc not found</code></pre></div><p>
When using multiple <a href="#catch">catch</a> functions, provide them with a name using the /name refinement to identify which one will <a href="#catch">catch</a> which <a href="#throw">throw</a>.
</p>
<p>
Editor note: Example with /name
</p>
<p>
Editor note: Example of using catch in a function spec.
</p>

<div class="see-also">See also: <a href="#do">do</a>, <a href="#throw">throw</a>, <a href="#try">try</a></div>
</section>

<hr>
<section id="cause-error">
 <a name="cause-error"></a>
 <h2>CAUSE-ERROR<a class="headerlink" href="#cause-error" title="Link to this heading">¶</a></h2>
<p>Causes an immediate error throw with the provided information.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">cause-error <span class="rebarg">err-type</span> <span class="rebarg">err-id</span> <span class="rebarg">args</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  err-type    [<span class="types">word!</span>] 
  err-id      [<span class="types">word!</span>] 
  args         
</pre>

<h6>Description:</h6>
<p>
Editor note: Description is a stub.
<a href="#cause-error">cause-error</a> constructs and immediately throws an <span class="datatype">error!</span>.
</p>
<p>
Editor note: Link to concept of error types?
</p>
<p>
Editor note: Argument description is a stub.
The err-type argument controls the general type of error to construct, valid values are the words of the system/catalog/errors object. The err-id argument selects a specific error type within the err-type class of errors. The args argument is used to pass error-specific values
</p>
<p>
Editor note: Description of error IDs is a stub.
All information about the currently available error types can be found in system/catalog/errors:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; words-of system/catalog/errors
== [Throw Note Syntax Script Math Access Command resv700 User Internal]</code></pre></div><p>
The specific errors within a given class can be inspected similarly:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; ? system/catalog/errors/math        
SYSTEM/CATALOG/ERRORS/MATH is an object of value: 
   code            integer!  400 
   type            string!   "math error" 
   zero-divide     string!   "attempt to divide by zero" 
   overflow        string!   "math or number overflow" 
   positive        string!   "positive number required"</code></pre></div><p>
All words except for code and type within an error type are possible specific errors. Their associated value is part of the error message that will displayed to the user if the error remains unhandled.
</p>
<p>
Some errors take arguments:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; ? system/catalog/errors/script/no-value   
SYSTEM/CATALOG/ERRORS/SCRIPT/NO-VALUE is a block of value: [:arg1 "has no value"]</code></pre></div><p>
As an example, this no-value error which takes a single argument can be caused as follows:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; cause-error 'script 'no-value 'Foo  
** script error: Foo has no value</code></pre></div><p>
Similarly, the two-argument no-arg error can be caused as follows:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; cause-error 'script 'no-arg [Foo bar] 
** script error: Foo is missing its bar argument</code></pre></div>
</section>

<hr>
<section id="cd">
 <a name="cd"></a>
 <h2>CD<a class="headerlink" href="#cd" title="Link to this heading">¶</a></h2>
<p>Change directory (shell shortcut function).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">cd <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path         Accepts %file, :variables and just words (as dirs)
</pre>

<h6>Description:</h6>
<p>
Variant of <a href="#change-dir">change-dir</a> for shell use. Supports inputting words as directory names:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">cd ..
cd somewhere</code></pre></div>
<div class="see-also">See also: <a href="#change-dir">change-dir</a>, <a href="#delete">delete</a>, <a href="#list-dir">list-dir</a>, <a href="#ls">ls</a>, <a href="#make-dir">make-dir</a>, <a href="#mkdir">mkdir</a>, <a href="#pwd">pwd</a>, <a href="#rm">rm</a>, <a href="#what-dir">what-dir</a></div>
</section>

<hr>
<section id="change">
 <a name="change"></a>
 <h2>CHANGE<a class="headerlink" href="#change" title="Link to this heading">¶</a></h2>
<p>Replaces element(s); returns just past the change.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">change <span class="rebarg">series</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port! struct!</span>] At position (modified)
  value       [<span class="types">any-type!</span>] The new value
<span class="tit">REFINEMENTS:</span>
  /part       Limits the amount to change to a given length or position
   range      [<span class="types">number! series! pair!</span>] 
  /only       Only change a block as a single value (not the contents of the block)
  /dup        Duplicates the change a specified number of times
   count      [<span class="types">number! pair!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#change">change</a> function modifies any type of <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a>, such as a <span class="datatype">string!</span> or <span class="datatype">block!</span>, at its current index position.
</p>
<p>
It has many variations, but let's take a simple example that modifies a <span class="datatype">string!</span> series:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">name: "bog"
change name "d"
probe name
"dog"

change next name "i"
probe name
"dig"

change tail name "it"
probe name
"digit"</code></pre></div><p>
Here is an example that changes a <span class="datatype">block!</span> series:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">colors: [red green blue]
change colors 'gold
probe colors
[gold green blue]

change at colors 3 [silver orange teal]
probe colors
[gold green silver orange teal]</code></pre></div><p>
As you can see, if the second argument is a single value, it will
replace the value at the current position in the first
series. However, if the second argument is a series compatible
with the first (block or string-based datatype), all of 
its values will replace those of the first argument or
series.
</p>

<h6>Result</h6><p>
<b>Be sure to note that <a href="#change">change</a> returns the series position just past the modification.</b>
</p>
<p>
This allows you to cascade multiple changes.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">test: "abcde"
change change test "1" "23"
probe test
"123de"</code></pre></div><p>
So, you must use <a href="#head">head</a> if you need the string at its starting position:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe head change "bog" "d"
"dog"

probe head change [1 4 5] [1 2 3]
[1 2 3]

probe head change [123 "test"] "the"
["the" "test"]</code></pre></div>
<h6>Partial changes</h6><p>
The /PART refinement changes a specified number of elements within the target series.
</p>
<p>
In this line, the 2 indicates that the "ab" are both replaced with the new string, "123":
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe head change/part "abcde" "123" 2
"123cde"</code></pre></div>
<h6>Duplication</h6><div class="example-code"><pre class="rebol-block"><code class="rebol">probe head change/dup "abc" "-&gt;" 5
"-&gt;-&gt;-&gt;-&gt;-&gt;"</code></pre></div><p>
Editor note: This section is new or has has recently changed and is still under construction.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">title: copy "how it REBOL"
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
"eat those grapes"</code></pre></div>
<div class="see-also">See also: <a href="#append">append</a>, <a href="#clear">clear</a>, <a href="#insert">insert</a>, <a href="#remove">remove</a>, <a href="#sort">sort</a></div>
</section>

<hr>
<section id="change-dir">
 <a name="change-dir"></a>
 <h2>CHANGE-DIR<a class="headerlink" href="#change-dir" title="Link to this heading">¶</a></h2>
<p>Changes the current directory path.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">change-dir <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file!</span>] 
</pre>

<h6>Description:</h6>
<p>
Changes the value of system/script/path. This value is used for file-related operations. Any file path that does not begin with a slash (/) will be relative to the path in system/script/path. When a script file is executed using the <a href="#do">do</a> native, the path will automatically be set to the directory containing the path. When REBOL starts, it is set to the current directory where REBOL is started.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">current: what-dir
make-dir %./rebol-temp/
probe current
%/C/REBOL/3.0/docs/scripts/

change-dir %./rebol-temp/
probe what-dir
%/C/REBOL/3.0/docs/scripts/rebol-temp/

change-dir current
delete %./rebol-temp/
probe what-dir
%/C/REBOL/3.0/docs/scripts/</code></pre></div><p>
Note that the shorter shell friendly <a href="#cd">cd</a> also exists.
</p>

<div class="see-also">See also: <a href="#list-dir">list-dir</a>, <a href="#make-dir">make-dir</a>, <a href="#what-dir">what-dir</a></div>
</section>

<hr>
<section id="changes">
 <a name="changes"></a>
 <h2>CHANGES<a class="headerlink" href="#changes" title="Link to this heading">¶</a></h2>
<p>What's new about this version.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">changes</span></pre>
</section>

<hr>
<section id="char?">
 <a name="char?"></a>
 <h2>CHAR?<a class="headerlink" href="#char?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">char? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; char? #"1"
== #(true)

&gt;&gt; char? 1
== #(false)</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="charset">
 <a name="charset"></a>
 <h2>CHARSET<a class="headerlink" href="#charset" title="Link to this heading">¶</a></h2>
<p>Makes a bitset of chars for the parse function.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">charset <span class="rebarg">chars</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  chars       [<span class="types">string! block! binary! char! integer!</span>] 
<span class="tit">REFINEMENTS:</span>
  /length     Preallocate this many bits
   len        [<span class="types">integer!</span>] Must be > 0
</pre>

<h6>Description:</h6>
<p>
The <a href="#charset">charset</a> function is a shortcut for:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">make bitset! value</code></pre></div><p>
It is used often for character based bitsets.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">chars: charset "aeiou"
print find chars "o"
true

print find "there you go" chars
ere you go

digits: charset "0123456789"
area-code: ["(" 3 digits ")"]
phone-num: [3 digits "-" 4 digits]
print parse "(707)467-8000" [[area-code | none] phone-num]
true</code></pre></div>
<div class="see-also">See also: <a href="#char?">char?</a>, <a href="#complement">complement</a></div>
</section>

<hr>
<section id="check">
 <a name="check"></a>
 <h2>CHECK<a class="headerlink" href="#check" title="Link to this heading">¶</a></h2>
<p>Temporary series debug check</p>

<h6>Usage:</h6>
<pre class="usage fs-6">check <span class="rebarg">val</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  val         [<span class="types">series!</span>] 
</pre>
</section>

<hr>
<section id="checksum">
 <a name="checksum"></a>
 <h2>CHECKSUM<a class="headerlink" href="#checksum" title="Link to this heading">¶</a></h2>
<p>Computes a checksum, CRC, hash, or HMAC.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">checksum <span class="rebarg">data</span> <span class="rebarg">method</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">binary! string! file!</span>] If string, it will be UTF8 encoded. File is dispatched to file-checksum function.
  method      [<span class="types">word!</span>] One of `system/catalog/checksums` and HASH
<span class="tit">REFINEMENTS:</span>
  /with       Extra value for HMAC key or hash table size; not compatible with TCP/CRC24/CRC32/ADLER32 methods.
   spec       [<span class="types">any-string! binary! integer!</span>] String or binary for MD5/SHA* HMAC key, integer for hash table size.
  /part       Limits to a given length
   length      
</pre>

<h6>Description:</h6>
<p>
Generally, a checksum is a number which accompanies data to verify that the data has not changed (did not have 
errors).
</p>
<p>
Available checksum method may differ between Rebol versions. What is available can be found in "system/catalog/checksums"
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; data: "foo" foreach method system/catalog/checksums [print [pad method 10  mold/flat checksum data method]]
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
tcp        39201</code></pre></div>
<div class="see-also">See also: <a href="#any-string?">any-string?</a>, <a href="#string?">string?</a></div>
</section>

<hr>
<section id="clean-path">
 <a name="clean-path"></a>
 <h2>CLEAN-PATH<a class="headerlink" href="#clean-path" title="Link to this heading">¶</a></h2>
<p>Returns new directory path with //, . and .. processed.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">clean-path <span class="rebarg">file</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  file        [<span class="types">file! url! string!</span>] 
<span class="tit">REFINEMENTS:</span>
  /only       Do not prepend current directory
  /dir        Add a trailing / if missing
</pre>

<h6>Description:</h6>
<p>
Rebuilds a directory path after decoding parent (..) and
current (.) path indicators.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; clean-path %com/www/../../../graphics/image.jpg
== %/C/REBOL/3.0/docs/graphics/image.jpg

&gt;&gt; messy-path: %/rebol/scripts/neat-stuff/../../experiments/./tests
== %/rebol/scripts/neat-stuff/../../experiments/./tests

&gt;&gt; neat-path: clean-path messy-path
== %/rebol/experiments/tests</code></pre></div><p>
URLs are returned unmodified (because the true paths may not
be known).
</p>

<div class="see-also">See also: <a href="#change-dir">change-dir</a>, <a href="#dir?">dir?</a>, <a href="#list-dir">list-dir</a>, <a href="#split-path">split-path</a>, <a href="#to-real-file">to-real-file</a></div>
</section>

<hr>
<section id="clear">
 <a name="clear"></a>
 <h2>CLEAR<a class="headerlink" href="#clear" title="Link to this heading">¶</a></h2>
<p>Removes elements from current position to tail; returns at new tail.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">clear <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! port! map! gob! bitset! struct! none!</span>] At position, if ordered collection (modified)
</pre>

<h6>Description:</h6>
<p>
<a href="#clear">clear</a> is similar to <a href="#remove">remove</a> but removes through the end of the series rather than just a single value. It returns at the current index position in the series.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: copy "with all things considered"
clear skip str 8
print str
with all

str: copy "get there quickly"
clear find str "qui"
print str
get there

head clear find %file.txt %.txt
%file</code></pre></div>
<div class="see-also">See also: <a href="#append">append</a>, <a href="#change">change</a>, <a href="#insert">insert</a>, <a href="#remove">remove</a>, <a href="#sort">sort</a></div>
</section>

<hr>
<section id="clos">
 <a name="clos"></a>
 <h2>CLOS<a class="headerlink" href="#clos" title="Link to this heading">¶</a></h2>
<p>Defines a closure function.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">clos <span class="rebarg">spec</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">block!</span>] Help string (opt) followed by arg words (and opt type and string)
  body        [<span class="types">block!</span>] The body block of the function
</pre>
</section>

<hr>
<section id="close">
 <a name="close"></a>
 <h2>CLOSE<a class="headerlink" href="#close" title="Link to this heading">¶</a></h2>
<p>Closes a port.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">close <span class="rebarg">port</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  port        [<span class="types">port!</span>] 
</pre>

<h6>Description:</h6>
<p>
Closes a port opened earlier with the <a href="#open">open</a> function. Any changes to the port data that have been buffered will be written.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">port: open %test-file.txt
insert port "Date: "
insert port form now
insert port newline
close port

print read %test-file.txt
read</code></pre></div>
<div class="see-also">See also: <a href="#do">do</a>, <a href="#load">load</a>, <a href="#open">open</a></div>
</section>

<hr>
<section id="closure">
 <a name="closure"></a>
 <h2>CLOSURE<a class="headerlink" href="#closure" title="Link to this heading">¶</a></h2>
<p>Defines a closure function with all set-words as locals.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">closure <span class="rebarg">spec</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">block!</span>] Help string (opt) followed by arg words (and opt type and string)
  body        [<span class="types">block!</span>] The body block of the function
<span class="tit">REFINEMENTS:</span>
  /with       Define or use a persistent object (self)
   object     [<span class="types">any-object! block! map!</span>] The object or spec
  /extern     
   words      [<span class="types">block!</span>] These words are not local
</pre>

<h6>Description:</h6>
<p>
A closure is a special type of function that has persistent variables.
</p>
<p>
With a closure you can write a block inside the closure body and the block will remain persistent:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">add2: closure [c d] [[c + d]]
do add2 1 2
3</code></pre></div><p>
This works because the variables of a closure remain valid, even outside the closure after it has been called. Such variables have indefinite extent. They are not limited to the lifetime of the function.
</p>
<p>
Note, however, that this luxury provided by closures is not without its costs. Closures require more time to evaluate as well as more memory space.
</p>
<p>
In essence a closure is an object. When you define the closure, it constructs a prototype object, and each time you call the closure, the prototype object is instantiated and the body code is evaluated within that context.
</p>
<p>
More about closures <a href="http://www.rebol.net/wiki/Closures">here</a>.
</p>
<p>
More about the benefits and costs of closures <a href="http://www.rebol.net/wiki/R2_vs._R3_Contexts">here</a>.
</p>

<div class="see-also">See also: <a href="#closure?">closure?</a>, <a href="#does">does</a>, <a href="#func">func</a>, <a href="#function">function</a>, <a href="#has">has</a></div>
</section>

<hr>
<section id="closure?">
 <a name="closure?"></a>
 <h2>CLOSURE?<a class="headerlink" href="#closure?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">closure? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns true if the input is a <span class="datatype">closure!</span>
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; closure? make closure! [[][]]
== #(true)</code></pre></div><p>
Editor note: Are there better examples?
</p>

<div class="see-also">See also: <a href="#function?">function?</a></div>
</section>

<hr>
<section id="collect">
 <a name="collect"></a>
 <h2>COLLECT<a class="headerlink" href="#collect" title="Link to this heading">¶</a></h2>
<p>Evaluates a block, storing values via KEEP function, and returns block of collected values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">collect <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  body        [<span class="types">block!</span>] Block to evaluate
<span class="tit">REFINEMENTS:</span>
  /into       Insert into a buffer instead (returns position after insert)
   output     [<span class="types">series!</span>] The buffer series (modified)
</pre>

<h6>Description:</h6>
<p>
Using the internal keep function, will collect values spread around a block to be stored in another block and returned:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; collect [keep 1 2 3 keep 4]
== [1 4]</code></pre></div><p>
Can also be used with the <a href="#parse">parse</a> function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; collect [
    parse [a b c d e] [
        any ['c | 'e | set w word! (keep w)]
    ]
]
== [a b d]</code></pre></div><p>
Blocks are collected and appended to the output as a series of values:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; collect [keep 1 keep [2 3]]
== [1 2 3]</code></pre></div><p>
The keep function has a refinement /only to append blocks as blocks to the output:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; collect [keep 1 keep/only [2 3]]
== [1 [2 3]]</code></pre></div>
</section>

<hr>
<section id="collect-words">
 <a name="collect-words"></a>
 <h2>COLLECT-WORDS<a class="headerlink" href="#collect-words" title="Link to this heading">¶</a></h2>
<p>Collect unique words used in a block (used for context construction).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">collect-words <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block!</span>] 
<span class="tit">REFINEMENTS:</span>
  /deep       Include nested blocks
  /set        Only include set-words
  /ignore     Ignore prior words
   words      [<span class="types">any-object! block! none!</span>] Words to ignore
  /as         Datatype of the words in the returned block
   type       [<span class="types">datatype!</span>] Any word type
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; collect-words [a: 1 + b]
== [a + b]

&gt;&gt; collect-words/set [a: 1 + b]
== [a]

&gt;&gt; collect-words/set/as [a: 1 + b] set-word!
== [a:]</code></pre></div>
</section>

<hr>
<section id="color-distance">
 <a name="color-distance"></a>
 <h2>COLOR-DISTANCE<a class="headerlink" href="#color-distance" title="Link to this heading">¶</a></h2>
<p>Human perception weighted Euclidean distance between two RGB colors</p>

<h6>Usage:</h6>
<pre class="usage fs-6">color-distance <span class="rebarg">a</span> <span class="rebarg">b</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  a           [<span class="types">tuple!</span>] 
  b           [<span class="types">tuple!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; color-distance 0.0.0 0.0.0
== 0.0

&gt;&gt; color-distance 0.0.0 255.0.0
== 402.874670338059

&gt;&gt; color-distance 0.0.0 255.255.0
== 649.929226916285

&gt;&gt; color-distance 0.0.0 255.255.255
== 764.833315173967</code></pre></div>
</section>

<hr>
<section id="combine">
 <a name="combine"></a>
 <h2>COMBINE<a class="headerlink" href="#combine" title="Link to this heading">¶</a></h2>
<p>Combines a block of values with a possibility to ignore by its types. Content of parens is evaluated.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">combine <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">block!</span>] Input values
<span class="tit">REFINEMENTS:</span>
  /with       Add delimiter between values
   delimiter   
  /into       Output results into a serie of required type
   out        [<span class="types">series!</span>] 
  /ignore     Fine tune, what value types will be ignored
   ignored    [<span class="types">typeset!</span>] Default is: #(typeset! [none! unset! error! any-function!])
  /only       Insert a block as a single value
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; combine [a b c]
== "abc"

&gt;&gt; combine [a #(none) b () c #(unset)]
== "abc"

&gt;&gt; combine/with [a #(none) b () c #(unset)] #"|"
== "a|b|c"

&gt;&gt; combine [{abc} (if false {def}) {ghi}]
== "abcghi"</code></pre></div>
<div class="see-also">See also: <a href="#ajoin">ajoin</a>, <a href="#compose">compose</a>, <a href="#reform">reform</a>, <a href="#rejoin">rejoin</a></div>
</section>

<hr>
<section id="command?">
 <a name="command?"></a>
 <h2>COMMAND?<a class="headerlink" href="#command?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">command? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id="comment">
 <a name="comment"></a>
 <h2>COMMENT<a class="headerlink" href="#comment" title="Link to this heading">¶</a></h2>
<p>Ignores the argument value and returns nothing.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">comment <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        A string, block, file, etc.
</pre>

<h6>Description:</h6>
<p>
This function can be used to add comments to a script or to remove a block from evaluation. Note that this function is only effective in evaluated code and has no effect in data blocks. That is, within a data block comments will appear as data. In many cases, using <a href="#comment">comment</a> is not necessary. Placing braces around any expression will prevent if from being evaluated (so long as it is not part of another expression).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">comment "This is a comment."

comment [print "As a comment, this is not printed"]</code></pre></div><p>
Note also that if the expression can't be loaded using <a href="#load">load</a>, the expression can't be commented out:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">comment [a,b]
** Syntax error: invalid "word" -- "a,b"
** Near: (line 1) comment [a,b]</code></pre></div>
<div class="see-also">See also: <a href="#do">do</a></div>
</section>

<hr>
<section id="complement">
 <a name="complement"></a>
 <h2>COMPLEMENT<a class="headerlink" href="#complement" title="Link to this heading">¶</a></h2>
<p>Returns the one's complement value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">complement <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">logic! integer! tuple! binary! bitset! typeset! image!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#complement">complement</a> function is used for bit-masking <span class="datatype">integer!</span> and <span class="datatype">tuple!</span> values or inverting <span class="datatype">bitset!</span> values (charsets).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">complement 0
-1

complement -1
0

complement 0.255.0
255.0.255

chars: complement charset "ther "
find "there it goes" chars
it goes</code></pre></div>
<div class="see-also">See also: <a href="#and">and</a>, <a href="#charset">charset</a>, <a href="#negate">negate</a>, <a href="#not">not</a>, <a href="#or">or</a>, <a href="#xor">xor</a></div>
</section>

<hr>
<section id="complement?">
 <a name="complement?"></a>
 <h2>COMPLEMENT?<a class="headerlink" href="#complement?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the bitset is complemented</p>

<h6>Usage:</h6>
<pre class="usage fs-6">complement? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">bitset!</span>] 
</pre>
</section>

<hr>
<section id="compose">
 <a name="compose"></a>
 <h2>COMPOSE<a class="headerlink" href="#compose" title="Link to this heading">¶</a></h2>
<p>Evaluates a block of expressions, only evaluating parens, and returns a block.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">compose <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        Block to compose
<span class="tit">REFINEMENTS:</span>
  /deep       Compose nested blocks
  /only       Insert a block as a single value (not the contents of the block)
  /into       Output results into a block with no intermediate storage
   out        [<span class="types">any-block!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#compose">compose</a> function builds a block of values, evaluating <span class="datatype">paren!</span> expressions and inserting their results. It is a very useful method of building new blocks.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">compose [result of 1 + 2 = (1 + 2)]
[result of 1 + 2 = 3]</code></pre></div><p>
Notice that only the <span class="datatype">paren!</span> expression is evaluated. All other values are left unchanged.
</p>
<p>
Here's another example, as might be used to create a header block (that has field names):
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">compose [time: (now/time) date: (now/date)]
[time: 17:47:13 date: 12-Feb-2009]</code></pre></div>
<h6>Sub-Blocks</h6><p>
If the result of an expression is a block, then the elements of that block are inserted into the output block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">colors: ["red" "green" "blue"]
compose [1 2 3 (colors)]
[1 2 3 "red" "green" "blue"]</code></pre></div><p>
If you want to insert the actual block, rather than its elements, there are a couple ways to do so. You can use the /only refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">colors: ["red" "green" "blue"]
compose/only [1 2 3 (colors)]
[1 2 3 ["red" "green" "blue"]]</code></pre></div><p>
Or, you can add a <a href="#reduce">reduce</a> to put the block within another block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">colors: ["red" "green" "blue"]
compose [1 2 3 (reduce [colors])]
[1 2 3 ["red" "green" "blue"]]</code></pre></div>
<h6>Evaluating All Parens</h6><p>
To evaluate all paren expressions, regardless of how deep the are nested within blocks, use the /deep refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">compose/deep [1 [2 [(1 + 2) 4]]]
[1 [2 [3 4]]]</code></pre></div><p>
You can use /deep and /only together:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">colors: ["red" "green" "blue"]
compose [1 2 3 [4 (colors)]]
[1 2 3 [4 "red" "green" "blue"]]</code></pre></div>
<h6>Memory usage for large blocks</h6><p>
For most blocks you don't need to worry about memory because REBOL's automatic storage manager will efficiently handle it; however, when building large block series with <a href="#compose">compose</a>, you can manage memory even more carefully.
</p>
<p>
For example, you might write:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">append series compose [a (b) (c)]</code></pre></div><p>
The word a and the evaluated results of b and c are appended to the series.
</p>
<p>
If this is done a lot, a large number of temporary series are generated, which take memory and also must be garbage collected later.
</p>
<p>
The /into refinement helps optimize the situation:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">compose/into [a (b) (c)] tail series</code></pre></div><p>
It requires no intermediate storage.
</p>

<div class="see-also">See also: <a href="#append">append</a>, <a href="#combine">combine</a>, <a href="#insert">insert</a>, <a href="#reduce">reduce</a>, <a href="#rejoin">rejoin</a>, <a href="#repend">repend</a></div>
</section>

<hr>
<section id="compress">
 <a name="compress"></a>
 <h2>COMPRESS<a class="headerlink" href="#compress" title="Link to this heading">¶</a></h2>
<p>Compresses data.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">compress <span class="rebarg">data</span> <span class="rebarg">method</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">binary! string!</span>] If string, it will be UTF8 encoded
  method      [<span class="types">word!</span>] One of `system/catalog/compressions`
<span class="tit">REFINEMENTS:</span>
  /part       
   length      Length of source data
  /level      
   lvl        [<span class="types">integer!</span>] Compression level 0-9
</pre>

<h6>Description:</h6>
<p>
Editor note: Describe the method that compress uses to compress data
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print compress "now is the dawning"
#{789CCBCB2F57C82C5628C9485548492CCFCBCC4B07003EB606BA12000000}

string: form first system/words
print length? string
8329

small: compress string
print length? small
3947</code></pre></div><p>
As with all compressed files, keep an uncompressed copy of the original data file as a backup.
</p>

<div class="see-also">See also: <a href="#decompress">decompress</a></div>
</section>

<hr>
<section id="confirm">
 <a name="confirm"></a>
 <h2>CONFIRM<a class="headerlink" href="#confirm" title="Link to this heading">¶</a></h2>
<p>Confirms a user choice.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">confirm <span class="rebarg">question</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  question    [<span class="types">series!</span>] Prompt to user
<span class="tit">REFINEMENTS:</span>
  /with       
   choices    [<span class="types">string! block!</span>] 
</pre>

<h6>Description:</h6>
<p>
This function provides a method of prompting the user for a true ("y" or "yes") or false ("n" or "no") response. Alternate responses can be identified with the /with refinement.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">confirm "Answer: 14. Y or N? "

confirm/with "Use A or B? " ["A" "B"]</code></pre></div>
<div class="see-also">See also: <a href="#ask">ask</a>, <a href="#input">input</a>, <a href="#prin">prin</a></div>
</section>

<hr>
<section id="construct">
 <a name="construct"></a>
 <h2>CONSTRUCT<a class="headerlink" href="#construct" title="Link to this heading">¶</a></h2>
<p>Creates an object with scant (safe) evaluation.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">construct <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block! string! binary!</span>] Specification (modified)
<span class="tit">REFINEMENTS:</span>
  /with       Default object
   object     [<span class="types">object!</span>] 
  /only       Values are kept as-is
</pre>

<h6>Description:</h6>
<p>
This function creates new objects but without evaluating the object's specification (as is done in the <a href="#make">make</a> and <a href="#context">context</a> functions).
</p>
<p>
When you <a href="#construct">construct</a> an object, only literal types are accepted. Functional evaluation is not performed. This allows your code to directly import objects (such as those sent from unsafe external sources such as email, cgi, etc.) without concern that they may include "hidden" side effects using executable code.
</p>
<p>
<a href="#construct">construct</a> is used in the same way as the <a href="#context">context</a> function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">obj: construct [
    name: "Fred"
    age: 27
    city: "Ukiah"
]
probe obj
make object! [
    name: "Fred"
    age: 27
    city: "Ukiah"
]</code></pre></div><p>
But, very limited evaluation takes place.  That means object specifications like:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">obj: construct [
    name: uppercase "Fred"
    age: 20 + 7
    time: now
]
probe obj
make object! [
    name: 'uppercase
    age: 20
    time: 'now
]</code></pre></div><p>
do not produce evaluated results.
</p>
<p>
Except with the /only refinement, the <a href="#construct">construct</a> function does perform evaluation on the words true, on, yes, false, off, no and none to produce their expected values. Literal words and paths will also be evaluated to produce their respective words and paths.  For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">obj: construct [
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
word!</code></pre></div><p>
The <a href="#construct">construct</a> function is useful for importing external objects, such as preference settings from a file, CGI query responses, encoded email, etc.
</p>
<p>
To provide a template object that contains default variable values (similar to <a href="#make">make</a>), use the /with refinement. The example below would use an existing object called standard-prefs as the template.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">prefs: construct/with load %prefs.r standard-prefs</code></pre></div>
<div class="see-also">See also: <a href="#context">context</a>, <a href="#make">make</a></div>
</section>

<hr>
<section id="context">
 <a name="context"></a>
 <h2>CONTEXT<a class="headerlink" href="#context" title="Link to this heading">¶</a></h2>
<p>Creates an object.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">context <span class="rebarg">spec</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">block!</span>] 
<span class="tit">REFINEMENTS:</span>
  /only       Do not bind nested blocks
</pre>

<h6>Description:</h6>
<p>
This function creates a unique new object. It is just a shortcut for <a href="#make">make</a> <span class="datatype">object!</span>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">person: context [
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
]</code></pre></div>
<div class="see-also">See also: <a href="#make">make</a></div>
</section>

<hr>
<section id="context?">
 <a name="context?"></a>
 <h2>CONTEXT?<a class="headerlink" href="#context?" title="Link to this heading">¶</a></h2>
<p>Returns the context in which a word is bound.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">context? <span class="rebarg">word</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">any-word!</span>] Word to check.
</pre>
</section>

<hr>
<section id="continue">
 <a name="continue"></a>
 <h2>CONTINUE<a class="headerlink" href="#continue" title="Link to this heading">¶</a></h2>
<p>Throws control back to top of loop.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">continue</span></pre>

<h6>Description:</h6>
<p>
The <a href="#continue">continue</a> function is the opposite of <a href="#break">break</a>. It jumps back to the top of the loop instead of exiting the loop.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">repeat n 5 [
    if n &lt; 3 [continue]
    print n
]
3
4
5</code></pre></div>
<div class="see-also">See also: <a href="#break">break</a>, <a href="#catch">catch</a>, <a href="#exit">exit</a>, <a href="#for">for</a>, <a href="#forall">forall</a>, <a href="#foreach">foreach</a>, <a href="#forever">forever</a>, <a href="#forskip">forskip</a>, <a href="#loop">loop</a>, <a href="#repeat">repeat</a>, <a href="#return">return</a>, <a href="#until">until</a>, <a href="#while">while</a></div>
</section>

<hr>
<section id="copy">
 <a name="copy"></a>
 <h2>COPY<a class="headerlink" href="#copy" title="Link to this heading">¶</a></h2>
<p>Copies a series, object, or other value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">copy <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">series! port! map! object! bitset! any-function! error! struct!</span>] At position
<span class="tit">REFINEMENTS:</span>
  /part       Limits to a given length or end position
   range      [<span class="types">number! series! pair!</span>] 
  /deep       Also copies series values within the block
  /types      What datatypes to copy
   kinds      [<span class="types">typeset! datatype!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#copy">copy</a> function will copy any <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a>, such as <span class="datatype">string!</span> or <span class="datatype">block!</span>, and most other compound datatypes such as <span class="datatype">object!</span> or <span class="datatype">function!</span>. It is not used for immediate datatypes, such as <span class="datatype">integer!</span>, <span class="datatype">decimal!</span>, <span class="datatype">time!</span>, <span class="datatype">date!</span>, and others.
</p>
<fieldset class="fset"><legend>How it Works</legend>
<p>It is important to understand <a href="#copy">copy</a> to program in REBOL properly.</p>
<p>To save memory, all strings, blocks, and other <a href="https://www.rebol.com/r3/docs/concepts/series.html" class="con">series</a> are accessed by reference (e.g. as pointers.) If you need to modify a series, and you do not want it to change in other locations, you must use <a href="#copy">copy</a> first.</p>
<p>Note that some functions, such as <a href="#join">join</a> and <a href="#rejoin">rejoin</a>, will copy automatically. That's because they are constructing new values.</p>
</fieldset><p>
This example shows what happens if you don't copy:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">name: "Tesla"
print name
Tesla

name2: name
insert name2 "Nicola "
print name2
Nicola Tesla

print name
Nicola Tesla</code></pre></div><p>
That's because, it's the same string:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">same? name name2
true</code></pre></div><p>
Here's the example using <a href="#copy">copy</a> for the second string:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">name: "Tesla"
print name
Tesla

name2: copy name
insert name2 "Nicola "
print name2
Nicola Tesla

print name
Tesla

same? name name2
false</code></pre></div><p>
The same behavior is also true for blocks. This example shows various results:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">block1: [1 2 3]
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
[1 2 3 6]</code></pre></div><p>
There will be times in your code where you'll want to <a href="#append">append</a> to or <a href="#insert">insert</a> in a string or other series. You will need to think about what result you desire.
</p>
<p>
Compare this example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str1: "Nicola"
str2: append str1 " Tesla"
print str1
Nicola Tesla

print str2
Nicola Tesla</code></pre></div><p>
with this example that uses the <a href="#copy">copy</a> function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str1: "Nicola"
str2: append copy str1 " Tesla"
print str1
Nicola

print str2
Nicola Tesla</code></pre></div>
<h6>Copy Part</h6><p>
It is fairly common to copy just a sub-string or sub-block. To do so, use the /part refinement. The length of the result is determined by an integer size or by the ending position location.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">name: "Nicola Tesla"
copy/part name 6
"Nicola"

copy/part skip name 7 5
"Tesla"

copy/part find name "Tesla" tail name
"Tesla"</code></pre></div><p>
Notice that the ending position can be a length or a position within the string (as shown by the <a href="#tail">tail</a> example above.)
</p>

<h7>About Substrings</h7><p>
If you use other languages, you will notice that this result is similar to what a substr function provides. Although we recommend using <a href="#copy">copy</a> with /part, you can easily define your own substr function this way:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">substr: func [arg [series!] start length] [
    copy/part skip arg start length
]</code></pre></div><p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">substr "string example" 7 7
"example"</code></pre></div><p>
We should explain why we don't normally define a substr function. Most of the time when you're extracting substrings, you are either using a function like <a href="#find">find</a> or you're using a loop of some kind. Therefore, you don't really care about the starting offset of a string, you only care about the current location.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "This is an example string."
str2: copy/part find str "ex" 7</code></pre></div><p>
And, in fact, it's common to write use two <a href="#find">find</a> functions in this way:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">start: find str "ex"
end: find start "le"
str2: copy/part start end</code></pre></div><p>
which advanced users often write in one line this way:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str2: copy/part s: find str "ex" find s "le"</code></pre></div><p>
Of course, if the string might not be found, this is a helpful pattern to use:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str2: all [
    start: find str "ex"
    end: find start "le"
    copy/part start end
]</code></pre></div><p>
If the start or end are not found, then str2 is set to none.
</p>
<p>
Here's an example of a simple loop that finds substrings:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "this example is an example"
pat: "example"
while [str: find str pat] [
    print copy/part str length? pat
    str: skip str length? pat
]</code></pre></div>
<h6>Copy Deep</h6><p>
When copying blocks, keep in mind that simple use of the <a href="#copy">copy</a> function does not make copies of series values within a block.
</p>
<p>
Notice that the <a href="#copy">copy</a> here does not copy the name string:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">person1: ["Tesla" 10-July-1856 Serbian]
person2: copy person1
insert person/2 "Nicola "
probe person1
["Nicola Tesla" 10-July-1856 Serbian]</code></pre></div><p>
If you need to copy both the block and all series values within it, use <a href="#copy">copy</a> with the /deep refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">person1: ["Tesla" 10-July-1856 Serbian]
person2: copy/deep person1
insert person/2 "Nicola "
probe person1
["Tesla" 10-July-1856 Serbian]

probe person2
["Nicola Tesla" 10-July-1856 Serbian]</code></pre></div><p>
Here both the block and the string are separate series.
</p>
<p>
Also be aware that if your block contains other blocks, they will be deep copied as well, including all strings and other series within them.
</p>
<p>
If you want to deep copy only a specific datatype, such as just strings or just blocks, you can use the /types refinement.
</p>
<p>
Here are a few examples of its usage:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">copy/deep/types block string!
copy/deep/types block any-string!
copy/deep/types block make typeset! [string! url! file!]</code></pre></div>
<h6>Copy Objects</h6><p>
If you use <a href="#copy">copy</a> on an object, a copy of the object is returned. This can be useful when objects are used only as simple storage structures. Note that rebinding is not done; therefore, do not use <a href="#copy">copy</a> on objects when that is required.
</p>

<h6>Helpful Hint</h6><p>
To see a list of functions that modify their series (not copy), type this line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">? modifies
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
<div class="see-also">See also: <a href="#ajoin">ajoin</a>, <a href="#form">form</a>, <a href="#join">join</a>, <a href="#make">make</a>, <a href="#mold">mold</a>, <a href="#rejoin">rejoin</a></div>
</section>

<hr>
<section id="cos">
 <a name="cos"></a>
 <h2>COS<a class="headerlink" href="#cos" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric cosine.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">cos <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">decimal!</span>] In radians
</pre>
</section>

<hr>
<section id="cosine">
 <a name="cosine"></a>
 <h2>COSINE<a class="headerlink" href="#cosine" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric cosine.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">cosine <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number!</span>] In degrees by default
<span class="tit">REFINEMENTS:</span>
  /radians    Value is specified in radians
</pre>

<h6>Description:</h6>
<p>
Ratio between the length of the adjacent side to
the length of the hypotenuse of a right triangle.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print cosine 90
0.0

print (cosine 45) = (sine 45)
true

print cosine/radians pi
-1.0</code></pre></div>
<div class="see-also">See also: <a href="#arccosine">arccosine</a>, <a href="#arcsine">arcsine</a>, <a href="#arctangent">arctangent</a>, <a href="#sine">sine</a>, <a href="#tangent">tangent</a></div>
</section>

<hr>
<section id="create">
 <a name="create"></a>
 <h2>CREATE<a class="headerlink" href="#create" title="Link to this heading">¶</a></h2>
<p>Send port a create request.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">create <span class="rebarg">port</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  port        [<span class="types">port! file! url! block!</span>] 
</pre>

<h6>Description:</h6>
<p>
Creates the file or URL object that is specified.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">create %testfile.txt
read %./
[%testfile.txt]</code></pre></div>
</section>

<hr>
<section id="cursor">
 <a name="cursor"></a>
 <h2>CURSOR<a class="headerlink" href="#cursor" title="Link to this heading">¶</a></h2>
<p>Changes the mouse cursor image.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">cursor <span class="rebarg">image</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  image       [<span class="types">integer! image! none!</span>] 
</pre>

<h6>Description:</h6>
<p>
This only works in a View window.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">cursor 1
cursor 2
cursor 3
cursor 4
cursor 5
cursor 6</code></pre></div><p>
Editor note: Describe all cursors here
</p>

</section>

<hr>
<section id="datatype?">
 <a name="datatype?"></a>
 <h2>DATATYPE?<a class="headerlink" href="#datatype?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">datatype? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print datatype? integer!
true

print datatype? 1234
false</code></pre></div>
</section>

<hr>
<section id="date?">
 <a name="date?"></a>
 <h2>DATE?<a class="headerlink" href="#date?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">date? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print date? 1/3/69
true

print date? 12:39
false</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="debase">
 <a name="debase"></a>
 <h2>DEBASE<a class="headerlink" href="#debase" title="Link to this heading">¶</a></h2>
<p>Decodes binary-coded string to binary value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">debase <span class="rebarg">value</span> <span class="rebarg">base</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">binary! any-string!</span>] The string to decode
  base        [<span class="types">integer!</span>] Binary base to use: 85, 64, 36, 16, or 2
<span class="tit">REFINEMENTS:</span>
  /url        Base 64 Decoding with URL and Filename Safe Alphabet
  /part       Limit the length of the input
   limit      [<span class="types">integer! binary! any-string!</span>] 
</pre>

<h6>Description:</h6>
<p>
Converts from an encoded string to the binary value. Primarily used for BASE-64 decoding.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; debase "MTIzNA==" 64
== #{31323334}

&gt;&gt; debase "12AB C456" 16
== #{12ABC456}

&gt;&gt; enbased: enbase "a string of text" 64
== "YSBzdHJpbmcgb2YgdGV4dA=="

&gt;&gt; string? enbased            ;; enbased value is a string
== #(true)

&gt;&gt; debased: debase enbased 64 ;; converts to binary value
== #{6120737472696E67206F662074657874}

&gt;&gt; to string! debased   ;; converts back to original string
== "a string of text"</code></pre></div><p>
If the input value cannot be decoded (such as when the proper number of characters is missing), an 'invalid-data error is thrown. This behavior is different from Rebol2, where none is returned.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; debase "AA" 16
== #{AA}

&gt;&gt; debase "A" 16

** Script error: data not in correct format: "A"</code></pre></div>
<div class="see-also">See also: <a href="#dehex">dehex</a>, <a href="#enbase">enbase</a></div>
</section>

<hr>
<section id="decimal?">
 <a name="decimal?"></a>
 <h2>DECIMAL?<a class="headerlink" href="#decimal?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">decimal? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; decimal? 1.2
== #(true)

&gt;&gt; decimal? 1
== #(false)</code></pre></div>
<div class="see-also">See also: <a href="#number?">number?</a>, <a href="#type?">type?</a></div>
</section>

<hr>
<section id="decloak">
 <a name="decloak"></a>
 <h2>DECLOAK<a class="headerlink" href="#decloak" title="Link to this heading">¶</a></h2>
<p>Decodes a binary string scrambled previously by encloak.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">decloak <span class="rebarg">data</span> <span class="rebarg">key</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">binary!</span>] Binary series to descramble (modified)
  key         [<span class="types">string! binary! integer!</span>] Encryption key or pass phrase
<span class="tit">REFINEMENTS:</span>
  /with       Use a string! key as-is (do not generate hash)
</pre>

<h6>Description:</h6>
<p>
<a href="#decloak">decloak</a> is a low strength decryption method that is used with <a href="#encloak">encloak</a>. See the <a href="#encloak">encloak</a> function for a complete description and examples.
</p>

<div class="see-also">See also: <a href="#encloak">encloak</a></div>
</section>

<hr>
<section id="decode">
 <a name="decode"></a>
 <h2>DECODE<a class="headerlink" href="#decode" title="Link to this heading">¶</a></h2>
<p>Decodes a series of bytes into the related datatype (e.g. image!).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">decode <span class="rebarg">type</span> <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  type        [<span class="types">word!</span>] Media type (jpeg, png, etc.)
  data         The data to decode
</pre>

<h6>Description:</h6>
<p>
Used to call codecs to decode binary data (bytes) into related datatypes.
</p>
<p>
Codecs are identified by words that symbolize their types. For example the word png is used to identify the PNG codec.
</p>
<p>
See the system/codecs for a list of loaded codecs. Codecs can be native (built-in), externally loaded, or even coded in REBOL.
</p>
<p>
<a href="http://www.rebol.net/cgi-bin/r3blog.r?view=0184">More about Encode and Decode</a>
</p>

<h6>Examples</h6><p>
The line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">image: load %photo.jpg</code></pre></div><p>
is roughly equivalent to:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: read %photo.jpg  ; returns binary data
image: decode 'jpeg data</code></pre></div>
<div class="see-also">See also: <a href="#debase">debase</a>, <a href="#enbase">enbase</a>, <a href="#encode">encode</a>, <a href="#load">load</a></div>
</section>

<hr>
<section id="decode-url">
 <a name="decode-url"></a>
 <h2>DECODE-URL<a class="headerlink" href="#decode-url" title="Link to this heading">¶</a></h2>
<p>Return object with URL components, or cause an error if not a valid URL</p>

<h6>Usage:</h6>
<pre class="usage fs-6">decode-url <span class="rebarg">url</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  url         [<span class="types">url! string!</span>] 
</pre>

<h6>Description:</h6>
<p>
This is a handy function that saves you the effort of writing
your own URL parser.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe decode-url http://user:pass@www.rebol.com/file.txt
[scheme: 'http pass: "pass" user: "user" host: "www.rebol.com" path: "/file.txt"]</code></pre></div>
</section>

<hr>
<section id="decompress">
 <a name="decompress"></a>
 <h2>DECOMPRESS<a class="headerlink" href="#decompress" title="Link to this heading">¶</a></h2>
<p>Decompresses data.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">decompress <span class="rebarg">data</span> <span class="rebarg">method</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">binary!</span>] Source data to decompress
  method      [<span class="types">word!</span>] One of `system/catalog/compressions`
<span class="tit">REFINEMENTS:</span>
  /part       Limits source data to a given length or position
   length     [<span class="types">number! series!</span>] Length of compressed data (must match end marker)
  /size       
   bytes      [<span class="types">integer!</span>] Number of uncompressed bytes.
</pre>

<h6>Description:</h6>
<p>
Examples:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">write %file.txt read http://www.rebol.net
size? %file.txt
5539

save %file.comp compress read %file.txt
size? %file.comp
2119

write %file.decomp decompress load %file.comp
size? %file.decomp
5539</code></pre></div><p>
If the data passed to the <a href="#decompress">decompress</a> function has been altered or corrupted, a decompression error will occur.
</p>
<p>
A typical error is out of memory, if the decompressed file length appears to be wrong (perhaps several gigabytes instead of 5539 bytes) to <a href="#decompress">decompress</a>.
</p>
<p>
Using the /limit refinement, puts a hard limit to the size of the decompressed file:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">decompress/limit read %file.comp 5000
** Script error: maximum limit reached: 5539
** Where: decompress
** Near: decompress/limit read %file.comp 5000</code></pre></div><p>
This can help avoiding that a decompress operation on a corrupt file suddenly eats all system resources.
</p>

<h6>Special Notes</h6><p>
<a href="#decompress">decompress</a> can decompress any ZLIB data as long as the data has the length of the uncompressed data in binary little-endian representation appended:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">zlib-decompress: func [
    zlib-data [binary!]
    length [integer!] "known uncompressed zlib data length"
][
    decompress head insert tail zlib-data third make struct! [value [integer!]] reduce [length]
]</code></pre></div>
<div class="see-also">See also: <a href="#compress">compress</a>, <a href="#debase">debase</a>, <a href="#enbase">enbase</a></div>
</section>

<hr>
<section id="deduplicate">
 <a name="deduplicate"></a>
 <h2>DEDUPLICATE<a class="headerlink" href="#deduplicate" title="Link to this heading">¶</a></h2>
<p>Removes duplicates from the data set.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">deduplicate <span class="rebarg">set</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  set         [<span class="types">block! string! binary!</span>] The data set (modified)
<span class="tit">REFINEMENTS:</span>
  /case       Use case-sensitive comparison
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="default">
 <a name="default"></a>
 <h2>DEFAULT<a class="headerlink" href="#default" title="Link to this heading">¶</a></h2>
<p>Set a word to a default value if it hasn't been set yet.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">default <span class="rebarg">word</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word! set-word! lit-word!</span>] The word (use :var for word! values)
  value        The value
</pre>

<h6>Description:</h6>
<p>
The <a href="#default">default</a> function is a clear way to indicate that you want a variable set to a default value if it's not already been set.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">default size 100</code></pre></div><p>
would set size to 100 if it's not already been set to some other value.
</p>
<p>
You can think of <a href="#default">default</a> as a shortcut for <a href="#any">any</a> when used like this:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">size: any [size 100]</code></pre></div><p>
However, <a href="#default">default</a> avoids the need to specify the size word twice and also makes the intention of your code more clear. It's quite often used for global configuration variables that may or may not have been set by prior code.
</p>

<div class="see-also">See also: <a href="#all">all</a>, <a href="#any">any</a>, <a href="#value?">value?</a></div>
</section>

<hr>
<section id="dehex">
 <a name="dehex"></a>
 <h2>DEHEX<a class="headerlink" href="#dehex" title="Link to this heading">¶</a></h2>
<p>Converts URL-style hex encoded (%xx) strings. If input is UTF-8 encode, you should first convert it to binary!</p>

<h6>Usage:</h6>
<pre class="usage fs-6">dehex <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-string! binary!</span>] The string to dehex
<span class="tit">REFINEMENTS:</span>
  /escape     
   char       [<span class="types">char!</span>] Can be used to change the default escape char #"%"
  /uri        Decode space from a special char (#"+" by default or #"_" when escape char is #"=")
</pre>

<h6>Description:</h6>
<p>
Converts the standard URL hex sequence that begins with a % followed by a valid hex value. Otherwise, the sequence  is not converted and will appear as written.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; dehex "a%20b"
== "a b"

&gt;&gt; dehex/uri "a+b"
== "a b"

&gt;&gt; dehex/escape "a#20b" #"#"
== "a b"</code></pre></div>
<div class="see-also">See also: <a href="#enhex">enhex</a></div>
</section>

<hr>
<section id="delect">
 <a name="delect"></a>
 <h2>DELECT<a class="headerlink" href="#delect" title="Link to this heading">¶</a></h2>
<p>Parses a common form of dialects. Returns updated input block.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">delect <span class="rebarg">dialect</span> <span class="rebarg">input</span> <span class="rebarg">output</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  dialect     [<span class="types">object!</span>] Describes the words and datatypes of the dialect
  input       [<span class="types">block!</span>] Input stream to parse
  output      [<span class="types">block!</span>] Resulting values, ordered as defined (modified)
<span class="tit">REFINEMENTS:</span>
  /in         Search for var words in specific objects (contexts)
   where      [<span class="types">block!</span>] Block of objects to search (non objects ignored)
  /all        Parse entire block, not just one command at a time
</pre>

<h6>Description:</h6>
<p>
DELECT stands for DEcode diaLECT. It is used to implement REBOL's internal dialects such as DRAW, EFFECT, RICH TEXT, SECURE, and VID, but its function is available to all users.
</p>
<p>
This is used for parsing unordered dialects. In unordered dialects, the order of arguments is less important than their type.
</p>
<p>
Here's a simple example. First the dialect is specified as a context:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">dialect: context [
    default: [tuple!]
    single: [string!]
    double: [integer! string!]
]</code></pre></div><p>
Then an input and output block is specified. The input block contains the data to parse. The output block stores the result:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">inp: [1.2.3 single "test" double "test" 123]
out: make block! 4  ; (any initial size works)</code></pre></div><p>
Now the input is processed using <a href="#delect">delect</a>, one step at a time:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">while [inp: delect dialect inp out] [
  ?? out
  ?? inp
]</code></pre></div><p>
To read more about <a href="#delect">delect</a>, see <a href="http://rebol.net/wiki/Delect">here</a>.
</p>

<div class="see-also">See also: <a href="#parse">parse</a></div>
</section>

<hr>
<section id="delete">
 <a name="delete"></a>
 <h2>DELETE<a class="headerlink" href="#delete" title="Link to this heading">¶</a></h2>
<p>Send port a delete request.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">delete <span class="rebarg">port</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  port        [<span class="types">port! file! url! block!</span>] 
</pre>

<h6>Description:</h6>
<p>
Deletes the file or URL object that is specified. If the file or URL refers to an empty directory, then the directory will be deleted.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">write %delete-test.r "This file is no longer needed."
delete %delete-test.r
write</code></pre></div>
<div class="see-also">See also: <a href="#create">create</a>, <a href="#exists?">exists?</a></div>
</section>

<hr>
<section id="delete-dir">
 <a name="delete-dir"></a>
 <h2>DELETE-DIR<a class="headerlink" href="#delete-dir" title="Link to this heading">¶</a></h2>
<p>Deletes a directory including all files and subdirectories.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">delete-dir <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file!</span>] 
</pre>
</section>

<hr>
<section id="deline">
 <a name="deline"></a>
 <h2>DELINE<a class="headerlink" href="#deline" title="Link to this heading">¶</a></h2>
<p>Converts string terminators to standard format, e.g. CRLF to LF.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">deline <span class="rebarg">string</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  string      [<span class="types">any-string!</span>] (modified)
<span class="tit">REFINEMENTS:</span>
  /lines      Return block of lines (works for LF, CR, CR-LF endings) (no modify)
</pre>

<h6>Description:</h6>
<p>
Useful for converting OS dependent string terminators to LF.
</p>
<p>
CRLF string termination:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; deline "a^M^/b" ; Windows, DOS, CP/M, OS/2, Symbian
== "a^/b"</code></pre></div><p>
CR string termination:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; deline "a^Mb" ; MacOS 1-9
== "a^/b"</code></pre></div><p>
LF string termination:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; deline "a^/b" ; MacOSX, AmigaOS, FreeBSD, GNU/Linux, BeOS, RiscOS
== "a^/b"</code></pre></div><p>
When using the /LINES refinement, the string will be split in blocks of strings per line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; deline/lines "a^M^/b"
== [
    "a"
    "b"
]</code></pre></div><p>
Note that when reading from disk, READ/STRING provides the same functionality.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; write %test.txt ajoin ["a" CRLF "b"]
== %test.txt

&gt;&gt; read/string %test.txt
== "a^/b"

&gt;&gt; to string! read %test.txt
== "a^M^/b"</code></pre></div>
<div class="see-also">See also: <a href="#enline">enline</a>, <a href="#read">read</a></div>
</section>

<hr>
<section id="delta-profile">
 <a name="delta-profile"></a>
 <h2>DELTA-PROFILE<a class="headerlink" href="#delta-profile" title="Link to this heading">¶</a></h2>
<p>Delta-profile of running a specific block.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">delta-profile <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block!</span>] 
</pre>

<h6>Description:</h6>
<p>
Provides detailed profiling information captured during the evaluation of a block.
</p>
<p>
See <a href="http://www.rebol.net/wiki/Profiler">Profiler</a> for detailed examples.
</p>
<p>
Simple example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; dp [loop 10 [next "a"]]
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
<div class="see-also">See also: <a href="#delta-time">delta-time</a>, <a href="#dp">dp</a>, <a href="#dt">dt</a></div>
</section>

<hr>
<section id="delta-time">
 <a name="delta-time"></a>
 <h2>DELTA-TIME<a class="headerlink" href="#delta-time" title="Link to this heading">¶</a></h2>
<p>Delta-time - returns the time it takes to evaluate the block.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">delta-time <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns the amount of time required to evaluate a given block.
</p>
<p>
Example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; dt [loop 1000000 [next "a"]]
0:00:00.25</code></pre></div><p>
See <a href="http://www.rebol.net/wiki/Profiler">Profiler</a> for detailed information about timing and profiling.
</p>

<div class="see-also">See also: <a href="#delta-profile">delta-profile</a>, <a href="#dp">dp</a>, <a href="#dt">dt</a></div>
</section>

<hr>
<section id="detab">
 <a name="detab"></a>
 <h2>DETAB<a class="headerlink" href="#detab" title="Link to this heading">¶</a></h2>
<p>Converts tabs to spaces (default tab size is 4).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">detab <span class="rebarg">string</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  string      [<span class="types">any-string! binary!</span>] (modified)
<span class="tit">REFINEMENTS:</span>
  /size       Specifies the number of spaces per tab
   number     [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
The REBOL language default tab size is four spaces. <a href="#detab">detab</a> will remove tabs from the entire string even beyond the first non-space character.
</p>
<p>
The series passed to this function is modified as a result.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">text: "^-lots^-^-of^-^-tabs^-^-^-^-here"
print detab copy text
    lots        of      tabs                here</code></pre></div><p>
Use the /size refinement for other sizes such as eight:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print detab/size text 8
        lots            of              tabs                            here</code></pre></div>
<div class="see-also">See also: <a href="#entab">entab</a></div>
</section>

<hr>
<section id="dh">
 <a name="dh"></a>
 <h2>DH<a class="headerlink" href="#dh" title="Link to this heading">¶</a></h2>
<p>Diffie-Hellman key exchange</p>

<h6>Usage:</h6>
<pre class="usage fs-6">dh <span class="rebarg">dh-key</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  dh-key      [<span class="types">handle!</span>] DH key created using `dh-init` function
<span class="tit">REFINEMENTS:</span>
  /public     Returns public key as a binary
  /secret     Computes secret result using peer's public key
   public-key [<span class="types">binary!</span>] Peer's public key
</pre>
</section>

<hr>
<section id="dh-init">
 <a name="dh-init"></a>
 <h2>DH-INIT<a class="headerlink" href="#dh-init" title="Link to this heading">¶</a></h2>
<p>Generates a new Diffie-Hellman private/public key pair</p>

<h6>Usage:</h6>
<pre class="usage fs-6">dh-init <span class="rebarg">g</span> <span class="rebarg">p</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  g           [<span class="types">binary!</span>] Generator
  p           [<span class="types">binary!</span>] Field prime
</pre>
</section>

<hr>
<section id="difference">
 <a name="difference"></a>
 <h2>DIFFERENCE<a class="headerlink" href="#difference" title="Link to this heading">¶</a></h2>
<p>Returns the special difference of two values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">difference <span class="rebarg">set1</span> <span class="rebarg">set2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  set1        [<span class="types">block! string! bitset! date! typeset! map!</span>] First data set
  set2        [<span class="types">block! string! bitset! date! typeset! map!</span>] Second data set
<span class="tit">REFINEMENTS:</span>
  /case       Uses case-sensitive comparison
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns the elements of two series that are not present in both. Both series arguments must be of the same datatype (string, block, etc.) Newer versions of REBOL also let you use <a href="#difference">difference</a> to compute the difference between date/times.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">lunch: [ham cheese bread carrot]
dinner: [ham salad carrot rice]
probe difference lunch dinner
[cheese bread salad rice]

probe difference [1 3 2 4] [3 5 4 6]
[1 2 5 6]

string1: "CBAD"    ; A B C D scrambled
string2: "EDCF"    ; C D E F scrambled
probe difference string1 string2
"BAEF"</code></pre></div><p>
Date differences produce a time in hours:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe difference 1-Jan-2002/0:00 1-Feb-2002/0:00
-744:00

probe difference 1-Jan-2003/10:30 now
-59449:55:14</code></pre></div><p>
This is different from when using <a href="#subtract">subtract</a>, which returns the difference in days:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe subtract 1-Jan-2002/0:00 1-Feb-2002/0:00
-31

probe subtract 1-Jan-2003/10:30 now
-2477</code></pre></div><p>
There is a limit to the time period that can be differenced between dates (determined by the internal size of the <span class="datatype">time!</span> datatype).
</p>
<p>
Note that performing this function over very large data sets can be CPU intensive.
</p>

<div class="see-also">See also: <a href="#exclude">exclude</a>, <a href="#intersect">intersect</a>, <a href="#union">union</a>, <a href="#unique">unique</a></div>
</section>

<hr>
<section id="dir">
 <a name="dir"></a>
 <h2>DIR<a class="headerlink" href="#dir" title="Link to this heading">¶</a></h2>
<p>Print contents of a directory (ls).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">dir <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file! word! path! string! unset!</span>] Accepts %file, :variables, and just words (as dirs)
<span class="tit">REFINEMENTS:</span>
  /f          Files only
  /d          Dirs only
  /r          Recursive
  /i          
   indent     [<span class="types">string! char!</span>] 
  /l          Limit recursive output to given maximal depth
   max-depth  [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="dir?">
 <a name="dir?"></a>
 <h2>DIR?<a class="headerlink" href="#dir?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the value looks like a directory spec (ends with a slash (or backslash)).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">dir? <span class="rebarg">target</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  target      [<span class="types">file! url! none!</span>] 
<span class="tit">REFINEMENTS:</span>
  /check      If the file is a directory on local storage (don't have to end with a slash)
</pre>

<h6>Description:</h6>
<fieldset class="fset"><legend>Under Review</legend>
<p>This function is under review for redefinition.</p>
</fieldset><p>
Returns false if it is not a directory.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print dir? %file.txt
false

print dir? %.
true</code></pre></div><p>
Note that the file that is input, is read from disk, if it exists. The function returns true, when the input either ends in / or if the name exists on disk as a directory.
</p>

<div class="see-also">See also: <a href="#exists?">exists?</a>, <a href="#make-dir">make-dir</a>, <a href="#modified?">modified?</a></div>
</section>

<hr>
<section id="dir-tree">
 <a name="dir-tree"></a>
 <h2>DIR-TREE<a class="headerlink" href="#dir-tree" title="Link to this heading">¶</a></h2>
<p>Prints a directory tree</p>

<h6>Usage:</h6>
<pre class="usage fs-6">dir-tree <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file! word! path! string! unset!</span>] Accepts %file, :variables, and just words (as dirs)
<span class="tit">REFINEMENTS:</span>
  /d          Dirs only
  /i          
   indent     [<span class="types">string! char!</span>] 
  /l          
   max-depth   
  /callback   
   on-value   [<span class="types">function!</span>] Function with [value depth] args - responsible to format value line
</pre>
</section>

<hr>
<section id="dirize">
 <a name="dirize"></a>
 <h2>DIRIZE<a class="headerlink" href="#dirize" title="Link to this heading">¶</a></h2>
<p>Returns a copy (always) of the path as a directory (ending slash).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">dirize <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file! string! url!</span>] 
</pre>

<h6>Description:</h6>
<p>
Convert a file name to a directory name.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe dirize %dir
%dir/</code></pre></div><p>
It is useful in cases where paths are used:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">dir: %files/examples
new-dir: dirize dir/new-code
probe new-dir
%files/examples/new-code/</code></pre></div><p>
This is useful because the PATH notation does not allow you to write:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">new-dir: dirize dir/new-code/</code></pre></div>
</section>

<hr>
<section id="divide">
 <a name="divide"></a>
 <h2>DIVIDE<a class="headerlink" href="#divide" title="Link to this heading">¶</a></h2>
<p>Returns the first value divided by the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">divide <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! vector!</span>] 
  value2      [<span class="types">scalar! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
If the second value is zero, an error will occur.
</p>
<p>
Examples:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print divide 123.1 12
10.25833333333333

print divide 10:00 4
2:30</code></pre></div><p>
When dividing values of different datatypes, they must be compatible:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">divide 4x5 $2.7
** Script error: incompatible argument for divide of pair!
** Where: divide
** Near: divide 4x5 $2.7</code></pre></div>
<div class="see-also">See also: <a href="#/">/</a>, <a href="#//">//</a>, <a href="#multiply">multiply</a></div>
</section>

<hr>
<section id="do">
 <a name="do"></a>
 <h2>DO<a class="headerlink" href="#do" title="Link to this heading">¶</a></h2>
<p>Evaluates a block, file, URL, function, word, or any other value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">do <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] Normally a file name, URL, or block
<span class="tit">REFINEMENTS:</span>
  /args       If value is a script, this will set its system/script/args
   arg         Args passed to a script (normally a string)
  /next       Do next expression only, return it, update block variable
   var        [<span class="types">word!</span>] Variable updated with new block position
</pre>

<h6>Description:</h6>
<p>
The <a href="#do">do</a> function evaluates a script file or a series of expressions and returns a result.
</p>
<p>
It performs the fundamental interpretive action of the REBOL language and is used internally within many other functions such as <a href="#if">if</a>, <a href="#case">case</a>, <a href="#while">while</a>, <a href="#loop">loop</a>, <a href="#repeat">repeat</a>, <a href="#foreach">foreach</a>, and others.
</p>

<h6>Most Common Use</h6><p>
Most of the time <a href="#do">do</a> is used to evaluate a script from a <span class="datatype">file!</span> or <span class="datatype">url!</span> as shown in these examples:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">do %setup.r
Settings done.

do http://www.rebol.com/speed.r
Console:   0:00:01.609 - 314 KC/S
Processor: 0:00:00.406 - 2128 RHz (REBOL-Hertz)
Memory:    0:00:00.657 - 72 MB/S
Disk/File: 0:00:00.234 - 130 MB/S</code></pre></div><p>
Note that <a href="#do">do</a> of a <span class="datatype">file!</span> or <span class="datatype">url!</span> requires that the script contain a valid REBOL header; otherwise, you'll get an "Script is missing a REBOL header" error.
</p>
<fieldset class="fset"><legend>Warning</legend>
<p>Only <a href="#do">do</a> a <span class="datatype">url!</span> script that you have reason to trust. It is advised that you <a href="#read">read</a> a script first and examine it closely to make sure it is safe to evaluate.</p>
</fieldset>
<h6>Other Uses</h6><p>
The <a href="#do">do</a> function can also be called to evaluate other types of arguments such as a <span class="datatype">block!</span>, <span class="datatype">path!</span>, <span class="datatype">string!</span>, or <span class="datatype">function!</span>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">do [1 + 2]
3

do "1 + 2"  ; see special note below
3</code></pre></div><p>
Expressions are evaluated left to right and the final result is returned. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">do [1 + 2 3 * 4]
12</code></pre></div><p>
To obtain all results, use the <a href="#reduce">reduce</a> function instead.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print reduce [1 + 2 3 * 4]
3 12</code></pre></div>
<h6>Other Examples</h6><p>
Selecting a block to evaluate:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">blk: [
    [print "test"]
    [loop 3 [print "loop"]]
]
do first blk
test

do second blk
loop
loop
loop</code></pre></div>
<h6>Refinements</h6><p>
The /args refinement allows you to pass arguments to another script and is used with a file, or URL.  Arguments passed with /args are stored in system/script/args within the context of the loaded script.
</p>
<p>
The /next refinement returns a block consisting of two elements. The first element is the evaluated return of the first expression encountered. The second element is the original block with the current index placed after  the last evaluated expression.
</p>

<h6>Special Notes</h6><p>
Evaluating strings is much slower than evaluating blocks and values. That's because REBOL is a symbolic language, not a string language. It is considered bad practice to convert values to strings and join them together to pass to <a href="#do">do</a> for evaluation. This can be done directly without strings.
</p>
<p>
For example, writing code like this is a poor practice:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "1234 + "
code: join str "10"
do code
1244</code></pre></div><p>
Instead, just use:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">blk: [1234 +]
code: join blk 10
do code
1244</code></pre></div><p>
In other words, you can <a href="#join">join</a> values in blocks just as easily as strings.
</p>

<div class="see-also">See also: <a href="#call">call</a>, <a href="#import">import</a>, <a href="#launch">launch</a>, <a href="#load">load</a>, <a href="#loop">loop</a>, <a href="#reduce">reduce</a>, <a href="#repeat">repeat</a></div>
</section>

<hr>
<section id="do-callback">
 <a name="do-callback"></a>
 <h2>DO-CALLBACK<a class="headerlink" href="#do-callback" title="Link to this heading">¶</a></h2>
<p>Internal function to process callback events.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">do-callback <span class="rebarg">event</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  event       [<span class="types">event!</span>] Callback event
</pre>
</section>

<hr>
<section id="do-codec">
 <a name="do-codec"></a>
 <h2>DO-CODEC<a class="headerlink" href="#do-codec" title="Link to this heading">¶</a></h2>
<p>Evaluate a CODEC function to encode or decode media types.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">do-codec <span class="rebarg">handle</span> <span class="rebarg">action</span> <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  handle      [<span class="types">handle!</span>] Internal link to codec
  action      [<span class="types">word!</span>] Decode, encode, identify
  data        [<span class="types">binary! image! string!</span>] 
</pre>

<h6>Description:</h6>
<p>
This is an internal native function used to call codecs. It is normally called by the <a href="#encode">encode</a> and <a href="#decode">decode</a> functions.
</p>
<p>
See the system/catalog/codecs for a list of loaded codecs. Codecs can be native (built-in), externally loaded, or coded in REBOL.
</p>

<div class="see-also">See also: <a href="#decode">decode</a>, <a href="#encode">encode</a></div>
</section>

<hr>
<section id="do-commands">
 <a name="do-commands"></a>
 <h2>DO-COMMANDS<a class="headerlink" href="#do-commands" title="Link to this heading">¶</a></h2>
<p>Evaluate a block of extension module command functions (special evaluation rules.)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">do-commands <span class="rebarg">commands</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  commands    [<span class="types">block!</span>] Series of commands and their arguments
</pre>

<h6>Description:</h6>
<p>
High speed <span class="datatype">command!</span> block evaluation for <a href="https://www.rebol.com/r3/docs/concepts/extensions.html">extensions</a>.
</p>
<p>
Originally created to evaluate <a href="https://www.rebol.com/r3/docs/view/draw.html">graphics rendering commands</a>, it can be used for any external sequence of commands that require maximum speed (e.g. high speed math processing such as FFTs, image processing, audio processing.)
</p>

<h6>Special Evaluation Method</h6><p>
The greater speed of command blocks is obtained through the use of a special evaluation method:
</p>
<ul>
<li>Evaluation is strictly linear. Sub-expressions, control branching, and recursion are not allowed so no stack management is required.</li>
<li>Arguments are already reduced to their final values (or variables that hold those values.)</li>
<li>Special variations of function arguments are not allowed. Only word and 'word forms are allowed.</li>
<li>Arguments must appear in the correct order and no optional arguments are allowed.</li>
<li>Arguments are placed directly within the command argument frame, not on the primary evaluator stack.</li>
</ul>
<h7>Why is it Useful?</h7><p>
In subsystems like the <a href="https://www.rebol.com/r3/docs/gui/gui">R3 GUI</a>, graphical elements are rendered by generating semi-static <a href="https://www.rebol.com/r3/docs/view/draw.html">draw blocks</a> either during style definition (definition of a button), face instantiation (creating an instance of a button), or face state modification (eg. hovering over a button).
</p>
<p>
The advantage of the static form of such draw blocks is that they require no further evaluation, hence take no additional memory or CPU time. In fact, the state of the GUI at any specific time is simply a sequence of draw block renderings. Therefore, a fast method of calling draw functions can greatly speed-up the rendering time of the GUI.
</p>
<p>
For special draw dialects (like the one used in the GUI) where optional or datatype-ordered arguments are allowed, a conversion from the dialect block to the command block is required. However, this conversion was already being performed in order to reduce the run-time overhead of the dialects (to avoid the NxM argument reordering penalty), so no additional overhead is incurred.
</p>

<h6>General Form</h6><p>
The general form is:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">do-commands [
    command1 arg11 arg12
    command2 arg21 arg22 arg23
    result: command3 arg31
    ...
]</code></pre></div><p>
Notice that set-words for results are allowed. In addition, the result of the final command will be returned from the <a href="#do-commands">do-commands</a> function.
</p>

<h6>Argument Requirements</h6><p>
Command blocks are written in a reduced minimal form. They consist of one or more commands followed by their arguments. The arguments must be actual values or variables; sub-expressions and operators are not allowed. If necessary, use <a href="#reduce">reduce</a> with /only or <a href="#compose">compose</a> to preprocess command blocks.
</p>
<p>
For example, you can write:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">line 0x0 100x100
line 100x100 200x200</code></pre></div><p>
and the command can also be variables:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">line start1 end1
line start2 end2</code></pre></div><p>
Sub expressions are not allowed:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">line 0x0 base + 10   ; error
line 0x0 add base 10 ; error</code></pre></div><p>
However, if necessary you can escape to parens for sub-expressions, but it reduces run-time performance:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">line 0x0 (base + 10) ; ok, but slow</code></pre></div>
<h6>Errors</h6><p>
An error will occur if any value other than a command is found:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">multiply 10 20
** Script error: expected command! not multiply</code></pre></div><p>
An error will also occur if an argument is not of the correct datatype, or if the block ends before all of its actual arguments are provided.
</p>

<div class="see-also">See also: <a href="#do">do</a>, <a href="#reduce">reduce</a></div>
</section>

<hr>
<section id="do-events">
 <a name="do-events"></a>
 <h2>DO-EVENTS<a class="headerlink" href="#do-events" title="Link to this heading">¶</a></h2>
<p>Waits for window events. Returns when all windows are closed.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">do-events</span></pre>

<h6>Description:</h6>
<p>
Process user events in GUI windows.  When this function is called the program becomes event driven. This function does not return until all windows have been closed.
</p>

</section>

<hr>
<section id="does">
 <a name="does"></a>
 <h2>DOES<a class="headerlink" href="#does" title="Link to this heading">¶</a></h2>
<p>A shortcut to define a function that has no arguments or locals.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">does <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  body        [<span class="types">block!</span>] The body block of the function
</pre>

<h6>Description:</h6>
<p>
<a href="#does">does</a> provides a shortcut for defining functions that have no arguments or local variables.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">rand10: does [random 10]
print rand10
5

this-month: does [now/month]
print this-month
2</code></pre></div><p>
This function is provided as a coding convenience and it is otherwise identical to using <a href="#func">func</a> or <a href="#function">function</a>.
</p>

<div class="see-also">See also: <a href="#closure">closure</a>, <a href="#exit">exit</a>, <a href="#func">func</a>, <a href="#function">function</a>, <a href="#has">has</a>, <a href="#return">return</a>, <a href="#use">use</a></div>
</section>

<hr>
<section id="dp">
 <a name="dp"></a>
 <h2>DP<a class="headerlink" href="#dp" title="Link to this heading">¶</a></h2>
<p>Note: Shell shortcut for <a href="#delta-profile">delta-profile</a>.</p>
</section>

<hr>
<section id="ds">
 <a name="ds"></a>
 <h2>DS<a class="headerlink" href="#ds" title="Link to this heading">¶</a></h2>
<p>Temporary stack debug</p>

<h6>Usage:</h6>
<pre class="usage fs-6">ds</span></pre>

<h6>Description:</h6>
<p>
Having such a code in the console:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; fun: func[a][ if a &gt; 0 [ds]  ]
&gt;&gt; fun 1</code></pre></div><p>
Will output:
</p>
<div class="example-code"><pre class="text-block"><code class="text">STACK[16] ds[0] native!

STACK[12] if[3] native!
        condition: #(true)
        true-branch: [ds]
        only: #(none)

STACK[5] fun[1] function!
        a: 1</code></pre></div>
</section>

<hr>
<section id="dt">
 <a name="dt"></a>
 <h2>DT<a class="headerlink" href="#dt" title="Link to this heading">¶</a></h2>
<p>Note: Shell shortcut for <a href="#delta-time">delta-time</a>.</p>
</section>

<hr>
<section id="dump">
 <a name="dump"></a>
 <h2>DUMP<a class="headerlink" href="#dump" title="Link to this heading">¶</a></h2>
<p>Temporary debug dump</p>

<h6>Usage:</h6>
<pre class="usage fs-6">dump <span class="rebarg">v</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  v            
<span class="tit">REFINEMENTS:</span>
  /fmt        only series format
</pre>

<h6>Description:</h6>
<p>
Note: A debug build is required to use this function!
</p>

</section>

<hr>
<section id="dump-obj">
 <a name="dump-obj"></a>
 <h2>DUMP-OBJ<a class="headerlink" href="#dump-obj" title="Link to this heading">¶</a></h2>
<p>Returns a string with information about an object value</p>

<h6>Usage:</h6>
<pre class="usage fs-6">dump-obj <span class="rebarg">obj</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  obj         [<span class="types">any-object! map!</span>] 
<span class="tit">REFINEMENTS:</span>
  /weak       Provides sorting and does not displays unset values
  /match      Include only those that match a string or datatype
   pattern     
  /not-none   Ignore NONE values
</pre>

<h6>Description:</h6>
<p>
This function provides an easy way to view the contents of an object. The function is friendly to <a href="#print">print</a>. It is an alternative to <a href="#mold">mold</a> and <a href="#probe">probe</a> which may display too much information for deeply structured objects.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; print dump-obj object [a: 1 b: "hello"]
  a               integer!   1
  b               string!    "hello"</code></pre></div>
<div class="see-also">See also: <a href="#?">?</a>, <a href="#??">??</a>, <a href="#help">help</a></div>
</section>

<hr>
<section id="ecdh">
 <a name="ecdh"></a>
 <h2>ECDH<a class="headerlink" href="#ecdh" title="Link to this heading">¶</a></h2>
<p>Elliptic-curve Diffie-Hellman key exchange</p>

<h6>Usage:</h6>
<pre class="usage fs-6">ecdh <span class="rebarg">key</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  key         [<span class="types">handle! none!</span>] Keypair to work with, may be NONE for /init refinement
<span class="tit">REFINEMENTS:</span>
  /init       Initialize ECC keypair.
   type       [<span class="types">word!</span>] One of supported curves: system/catalog/elliptic-curves
  /curve      Returns handles curve type
  /public     Returns public key as a binary
  /secret     Computes secret result using peer's public key
   public-key [<span class="types">binary!</span>] Peer's public key
</pre>
</section>

<hr>
<section id="ecdsa">
 <a name="ecdsa"></a>
 <h2>ECDSA<a class="headerlink" href="#ecdsa" title="Link to this heading">¶</a></h2>
<p>Elliptic Curve Digital Signature Algorithm</p>

<h6>Usage:</h6>
<pre class="usage fs-6">ecdsa <span class="rebarg">key</span> <span class="rebarg">hash</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  key         [<span class="types">handle! binary!</span>] Keypair to work with, created using ECDH function, or raw binary key (needs /curve)
  hash        [<span class="types">binary!</span>] Data to sign or verify
<span class="tit">REFINEMENTS:</span>
  /sign       Use private key to sign data, returns ASN1 encoded result
  /verify     Use public key to verify signed data, returns true or false
   signature  [<span class="types">binary!</span>] ASN1 encoded
  /curve      Used if key is just a binary
   type       [<span class="types">word!</span>] One of supported curves: system/catalog/elliptic-curves
</pre>
</section>

<hr>
<section id="echo">
 <a name="echo"></a>
 <h2>ECHO<a class="headerlink" href="#echo" title="Link to this heading">¶</a></h2>
<p>Copies console output to a file.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">echo <span class="rebarg">target</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  target      [<span class="types">file! none! logic!</span>] 
</pre>

<h6>Description:</h6>
<p>
Write output to a file in addition to the user console. The previous contents of a file will be overwritten. The echo can be stopped with <a href="#echo">echo</a> none or by starting another <a href="#echo">echo</a>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">echo %helloworld.txt
print "Hello World!"
echo none
Hello World!</code></pre></div>
<div class="see-also">See also: <a href="#print">print</a>, <a href="#trace">trace</a></div>
</section>

<hr>
<section id="eighth">
 <a name="eighth"></a>
 <h2>EIGHTH<a class="headerlink" href="#eighth" title="Link to this heading">¶</a></h2>
<p>Returns the eighth value of a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">eighth <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
This is an ordinal.
</p>
<p>
See the <a href="#first">first</a> function for examples. If no value is found, none is returned.
</p>

<div class="see-also">See also: <a href="#first">first</a>, <a href="#pick">pick</a>, <a href="#second">second</a>, <a href="#third">third</a></div>
</section>

<hr>
<section id="either">
 <a name="either"></a>
 <h2>EITHER<a class="headerlink" href="#either" title="Link to this heading">¶</a></h2>
<p>If TRUE condition return first arg, else second; evaluate blocks by default.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">either <span class="rebarg">condition</span> <span class="rebarg">true-branch</span> <span class="rebarg">false-branch</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  condition   [<span class="types">any-type!</span>] 
  true-branch  
  false-branch  
<span class="tit">REFINEMENTS:</span>
  /only       Suppress evaluation of block args.
</pre>

<h6>Description:</h6>
<p>
The <a href="#either">either</a> function will evaluate one block or the other depending on a condition.
</p>
<p>
This function provides the same capability as the if-else statements found in other languages. Because REBOL is a functional language, it is not desirable to use the word else within the expression.
</p>
<p>
Here's an example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">either 2 &gt; 1 [print "greater"] [print "not greater"]
greater

either 1 &gt; 2 [print "greater"] [print "not greater"]
not greater</code></pre></div><p>
The condition can be the result of several expressions within <a href="#any">any</a> or <a href="#and">and</a>, or any other function that produces a result:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">either all [
    time &gt; 10:20
    age &gt; 20
    find users "bob"
] [print "that's true"] [print "that's false"]
that's true</code></pre></div><p>
In addition, it can be pointed out that the evaluated blocks can be within a variable:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">blk1: [print "that's true"]
blk2: [print "that's false"]
either 2 &gt; 1 blk1 blk2
that's true</code></pre></div>
<h6>Return Value</h6><p>
The <a href="#either">either</a> function returns the result of the block that it evaluates.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print either 2 &gt; 1 ["greater"] ["not greater"]
greater</code></pre></div>
<h6>Simplification</h6><p>
The above example is pretty common, but it should be noted that it can be easily refactored:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">either 2 &gt; 1 [print "greater"] [print "not greater"]</code></pre></div><p>
is better written as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print either 2 &gt; 1 ["greater"] ["not greater"]</code></pre></div><p>
or even better written as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print pick ["greater" "not greater"] 2 &gt; 1</code></pre></div><p>
The importance of this is that you're picking from a choice of two strings, and you're doing it here with one less block than the code above it.
</p>
<p>
Be careful with this last method. The <a href="#pick">pick</a> function only allows true and false, not none. See <a href="#either">either</a> for more details.
</p>

<h6>A Common Error</h6><p>
A common error is to forget to provide the second block to the <a href="#either">either</a> function. This usually happens when you simplify an expression, and forget to change the <a href="#either">either</a> to an <a href="#if">if</a> function.
</p>
<p>
This is wrong:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">either 2 &gt; 1 [print "greater"]</code></pre></div><p>
and it may become quite confusing as to why your program isn't working correctly.
</p>
<p>
You should have written:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if 2 &gt; 1 [print "greater"]</code></pre></div>
<div class="see-also">See also: <a href="#all">all</a>, <a href="#any">any</a>, <a href="#case">case</a>, <a href="#if">if</a>, <a href="#pick">pick</a>, <a href="#switch">switch</a>, <a href="#unless">unless</a></div>
</section>

<hr>
<section id="ellipsize">
 <a name="ellipsize"></a>
 <h2>ELLIPSIZE<a class="headerlink" href="#ellipsize" title="Link to this heading">¶</a></h2>
<p>Truncate and add ellipsis if str is longer than len</p>

<h6>Usage:</h6>
<pre class="usage fs-6">ellipsize <span class="rebarg">str</span> <span class="rebarg">len</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  str         [<span class="types">string!</span>] (modified)
  len         [<span class="types">integer!</span>] Max length
<span class="tit">REFINEMENTS:</span>
  /one-line   Escape line breaks
</pre>
</section>

<hr>
<section id="email?">
 <a name="email?"></a>
 <h2>EMAIL?<a class="headerlink" href="#email?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">email? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print email? info@rebol.com
true

print email? http://www.REBOL.com
false</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="empty?">
 <a name="empty?"></a>
 <h2>EMPTY?<a class="headerlink" href="#empty?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if empty or NONE, or for series if index is at or beyond its tail.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">empty? <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! object! gob! port! bitset! typeset! map! none!</span>] 
</pre>

<h6>Description:</h6>
<p>
This is a synonym for <a href="#tail?">tail?</a> The check is made relative to the current location in the series.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print empty? []
true

print empty? [1]
false</code></pre></div><p>
The <a href="#empty?">empty?</a> function is useful for all types of series. For instance, you can use it to check a string returned from the
user:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: ask "Enter name:"
if empty? str [print "Name is required"]</code></pre></div><p>
It is often used in conjunction with <a href="#trim">trim</a> to remove black spaces from the ends of a string before checking it:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if empty? trim str [print "Name is required"]</code></pre></div>
<div class="see-also">See also: <a href="#found?">found?</a>, <a href="#none?">none?</a>, <a href="#tail?">tail?</a></div>
</section>

<hr>
<section id="enbase">
 <a name="enbase"></a>
 <h2>ENBASE<a class="headerlink" href="#enbase" title="Link to this heading">¶</a></h2>
<p>Encodes data into a textual representation using a specified binary base.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">enbase <span class="rebarg">value</span> <span class="rebarg">base</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">binary! any-string! integer!</span>] Non-binary values are first converted to binary
  base        [<span class="types">integer!</span>] Binary base to use: 85, 64, 36, 16, or 2
<span class="tit">REFINEMENTS:</span>
  /url        Base 64 Encoding with URL and Filename Safe Alphabet
  /part       Limit the length of the input
   limit      [<span class="types">integer! binary! any-string!</span>] 
  /flat       No line breaks
</pre>

<h6>Description:</h6>
<p>
Converts from a string or binary into an encode string value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; enbase "Here is a string." 64
== "SGVyZSBpcyBhIHN0cmluZy4="

&gt;&gt; enbase #{12abcd45} 16
== "12ABCD45"</code></pre></div><p>
The <a href="#debase">debase</a> function is used to convert the binary back again. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; str: enbase "This is a string" 16
== "54686973206973206120737472696E67"

&gt;&gt; debase str 16
== #{54686973206973206120737472696E67}</code></pre></div>
<div class="see-also">See also: <a href="#debase">debase</a>, <a href="#dehex">dehex</a></div>
</section>

<hr>
<section id="encloak">
 <a name="encloak"></a>
 <h2>ENCLOAK<a class="headerlink" href="#encloak" title="Link to this heading">¶</a></h2>
<p>Scrambles a binary string based on a key.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">encloak <span class="rebarg">data</span> <span class="rebarg">key</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">binary!</span>] Binary series to scramble (modified)
  key         [<span class="types">string! binary! integer!</span>] Encryption key or pass phrase
<span class="tit">REFINEMENTS:</span>
  /with       Use a string! key as-is (do not generate hash)
</pre>

<h6>Description:</h6>
<p>
<a href="#encloak">encloak</a> is a low strength encryption method that can be useful for hiding passwords and other such values. It is not a replacement for AES or Blowfish, but works for noncritical data.
</p>
<p>
<b>Do not use it for top secret information!</b>
</p>
<p>
To cloak a binary string, provide the binary string and a cloaking key to the <a href="#encloak">encloak</a> function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; bin: encloak #{54686973206973206120737472696E67} "a-key"
== #{4972E8CD78CE343EC727810866AE5F6B}</code></pre></div><p>
To cloak a string of characters, convert it using <a href="#to-binary">to-binary</a> :
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; bin: encloak to-binary "This is a string" "a-key"
== #{4972E8CD78CE343EC727810866AE5F6B}</code></pre></div><p>
The result is an encrypted binary value which can be decloaked with the line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; decloak bin "a-key"
== #{54686973206973206120737472696E67}

&gt;&gt; to string! bin
== "This is a string"</code></pre></div><p>
The stronger your key, the better the encryption. For important data use a much longer key that is harder to guess. Also, do not forget your key, or it may be difficult or impossible to recover your data.
</p>
<p>
Now you have a simple way to save out a hidden string, such as a password:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">key: ask "Cloak key? (do not forget it) "
data: to-binary "string to hide"
save %data encloak data key</code></pre></div><p>
To read the data and decloak it:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">key: ask "Cloak key? "
data: load %data
data: to-string decloak data key</code></pre></div><p>
Of course you can cloak any kind of data using these functions, even non-character data such as programs, images, sounds, etc. In those cases you do not need the <a href="#to-binary">to-binary</a> conversion shown above.
</p>
<p>
Note that by default, the cloak functions will hash your key strings into 160 bit SHA1 secure cryptographic hashes. If you have created your own hash key (of any length), you use the /with refinement to provide it.
</p>

<div class="see-also">See also: <a href="#decloak">decloak</a></div>
</section>

<hr>
<section id="encode">
 <a name="encode"></a>
 <h2>ENCODE<a class="headerlink" href="#encode" title="Link to this heading">¶</a></h2>
<p>Encodes a datatype (e.g. image!) into a series of bytes.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">encode <span class="rebarg">type</span> <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  type        [<span class="types">word!</span>] Media type (jpeg, png, etc.)
  data         The data to encode
<span class="tit">REFINEMENTS:</span>
  /as         Special encoding options
   options     Value specific to type of codec
</pre>

<h6>Description:</h6>
<p>
Used to call codecs to encode datatypes into binary data (bytes).
</p>
<p>
Codecs are identified by words that symbolize their types. For example the word png is used to identify the PNG codec.
</p>
<p>
See the system/codecs for a list of loaded codecs. Codecs can be native (built-in), externally loaded, or even coded in REBOL.
</p>

<h6>Examples</h6><p>
The line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">save %photo.bmp image</code></pre></div><p>
Is roughly equivalent to:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: encode 'bmp image
write %photo.bmp data</code></pre></div>
<div class="see-also">See also: <a href="#debase">debase</a>, <a href="#decode">decode</a>, <a href="#enbase">enbase</a>, <a href="#load">load</a></div>
</section>

<hr>
<section id="encoding?">
 <a name="encoding?"></a>
 <h2>ENCODING?<a class="headerlink" href="#encoding?" title="Link to this heading">¶</a></h2>
<p>Returns the media codec name for given binary data. (identify)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">encoding? <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">binary!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; encoding? read %test.wav
== wav

&gt;&gt; encoding? read %test.png
== png</code></pre></div>
<div class="see-also">See also: <a href="#decode">decode</a>, <a href="#encode">encode</a></div>
</section>

<hr>
<section id="enhex">
 <a name="enhex"></a>
 <h2>ENHEX<a class="headerlink" href="#enhex" title="Link to this heading">¶</a></h2>
<p>Converts string into URL-style hex encodeding (%xx) when needed.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">enhex <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-string! binary!</span>] The string to encode
<span class="tit">REFINEMENTS:</span>
  /escape     Can be used to change the default escape char #"%"
   char       [<span class="types">char!</span>] 
  /except     Can be used to specify, which chars can be left unescaped
   unescaped  [<span class="types">bitset!</span>] By default it is URI bitset when value is file or url, else URI-Component
  /uri        Encode space using a special char (#"+" by default or #"_" when escape char is #"=")
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; enhex "a b"
== "a%20b"

&gt;&gt; enhex/uri "a b"
== "a+b"

&gt;&gt; enhex/escape "a b" #"#"
== "a#20b"</code></pre></div>
<div class="see-also">See also: <a href="#dehex">dehex</a></div>
</section>

<hr>
<section id="enline">
 <a name="enline"></a>
 <h2>ENLINE<a class="headerlink" href="#enline" title="Link to this heading">¶</a></h2>
<p>Converts string terminators to native OS format, e.g. LF to CRLF.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">enline <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">any-string! block!</span>] (modified)
</pre>

<h6>Description:</h6>
<p>
Basic example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">enline "a^/b"
"a^/M^/b"</code></pre></div><p>
To convert from any string termination format to, use <a href="#enline">enline</a> after the <a href="#deline">deline</a> function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">enline deline "a^Mb"
"a^/M^/b"</code></pre></div><p>
See <a href="#deline">deline</a> for more information about string termination formats.
</p>

<div class="see-also">See also: <a href="#deline">deline</a></div>
</section>

<hr>
<section id="entab">
 <a name="entab"></a>
 <h2>ENTAB<a class="headerlink" href="#entab" title="Link to this heading">¶</a></h2>
<p>Converts spaces to tabs (default tab size is 4).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">entab <span class="rebarg">string</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  string      [<span class="types">any-string! binary!</span>] (modified)
<span class="tit">REFINEMENTS:</span>
  /size       Specifies the number of spaces per tab
   number     [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
The REBOL language default tab-size is four spaces. Use the /size refinement for other sizes such as eight. <a href="#entab">entab</a> will only place tabs at the beginning of the line (prior to the first non-space character).
</p>
<p>
The series passed to this function is modified as a result.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">text: {
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
  sentence</code></pre></div><p>
The opposite function is <a href="#detab">detab</a> which converts tabs back to spaces:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe entab text
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
    sentence}</code></pre></div>
<div class="see-also">See also: <a href="#detab">detab</a></div>
</section>

<hr>
<section id="enum">
 <a name="enum"></a>
 <h2>ENUM<a class="headerlink" href="#enum" title="Link to this heading">¶</a></h2>
<p>Creates enumeration object from given specification</p>

<h6>Usage:</h6>
<pre class="usage fs-6">enum <span class="rebarg">spec</span> <span class="rebarg">title</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">block!</span>] Specification with names and values.
  title       [<span class="types">string! word!</span>] Enumeration name
</pre>
</section>

<hr>
<section id="equal?">
 <a name="equal?"></a>
 <h2>EQUAL?<a class="headerlink" href="#equal?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are equal.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">equal? <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
String-based datatypes are considered equal when they
are identical or differ only by character casing
(uppercase = lowercase). Use <a href="#==">==</a> or find/match/case to
compare strings by casing.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print equal? 123 123
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
true</code></pre></div>
<div class="see-also">See also: <a href="#<>">&lt;&gt;</a>, <a href="#=">=</a>, <a href="#==">==</a>, <a href="#=?">=?</a>, <a href="#not-equal?">not-equal?</a>, <a href="#strict-equal?">strict-equal?</a></div>
</section>

<hr>
<section id="equiv?">
 <a name="equiv?"></a>
 <h2>EQUIV?<a class="headerlink" href="#equiv?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are equivalent.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">equiv? <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id="error?">
 <a name="error?"></a>
 <h2>ERROR?<a class="headerlink" href="#error?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">error? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values. This is useful for determining if a <a href="#try">try</a> function returned an error.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if error? try [1 + "x"][
    print "Did not work."
]
Did not work.</code></pre></div>
</section>

<hr>
<section id="even?">
 <a name="even?"></a>
 <h2>EVEN?<a class="headerlink" href="#even?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the number is even.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">even? <span class="rebarg">number</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  number      [<span class="types">number! char! date! money! time! pair!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns true only if the argument is an even integer value. If the argument is a decimal, only its integer portion is
examined.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; even? 100
== #(true)

&gt;&gt; even? 7
== #(false)</code></pre></div>
<div class="see-also">See also: <a href="#odd?">odd?</a>, <a href="#zero?">zero?</a></div>
</section>

<hr>
<section id="event?">
 <a name="event?"></a>
 <h2>EVENT?<a class="headerlink" href="#event?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">event? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns true if the value is an event datatype.
</p>

</section>

<hr>
<section id="evoke">
 <a name="evoke"></a>
 <h2>EVOKE<a class="headerlink" href="#evoke" title="Link to this heading">¶</a></h2>
<p>Special guru meditations. (Not for beginners.)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">evoke <span class="rebarg">chant</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  chant       [<span class="types">word! block! integer!</span>] Single or block of words ('? to list)
</pre>

<h6>Description:</h6>
<p>
This is useful for analyzing hard REBOL crashes that lead to assertion errors and other crashes that aren't related to your script errors, but directly exposes bugs in the REBOL kernel. This is helpful information for REBOL Technologies to fix these bugs.
</p>
<p>
To enable this kind of analysis, have this at the beginning of your program:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure [debug allow] 
evoke 'crash-dump</code></pre></div><p>
If REBOL crashes, you will get a stack dump. You can force a crash using:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">evoke 'crash</code></pre></div><div class="example-code"><pre class="text-block"><code class="text">--REBOL Kernel Dump--
Evaluator:
    Cycles:  50001
    Counter: 8027
    Dose:    10000
    Signals: #00000000
    Sigmask: #FFFFFFFF
    DSP:     5
    DSF:     1
Memory/GC:
    Ballast: 2998784
    Disable: 1
    Protect: 1
    Infants: 3

STACK[5] evoke[1] native!
        chant: crash</code></pre></div>
<h6>Special Notes</h6><p>
Common for all operations with evoke is that debugging must be allowed using:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure [debug allow]</code></pre></div><p>
<a href="#evoke">evoke</a> also allows other debug output, mostly used internally by REBOL Technologies to help test REBOL 3.
</p>
<p>
The function can also be used to monitor the garbage collector:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">evoke 'watch-recycle</code></pre></div><p>
or to monitor object copying:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">evoke 'watch-obj-copy</code></pre></div><p>
or to set the stack size:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">evoke 'stack-size 2000000</code></pre></div><p>
or to debug <a href="#delect">delect</a> information:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">evoke 'delect</code></pre></div>
</section>

<hr>
<section id="exclude">
 <a name="exclude"></a>
 <h2>EXCLUDE<a class="headerlink" href="#exclude" title="Link to this heading">¶</a></h2>
<p>Returns the first data set less the second data set.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">exclude <span class="rebarg">set1</span> <span class="rebarg">set2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  set1        [<span class="types">block! string! bitset! typeset! map!</span>] First data set
  set2        [<span class="types">block! string! bitset! typeset! map!</span>] Second data set
<span class="tit">REFINEMENTS:</span>
  /case       Uses case-sensitive comparison
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns the elements of the first set less the elements
of the second set. In other words, it removes from the
first set all elements that are part of the second set.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">lunch: [ham cheese bread carrot]
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
""</code></pre></div><p>
Note that performing this function over very large
data sets can be CPU intensive.
</p>

<div class="see-also">See also: <a href="#difference">difference</a>, <a href="#intersect">intersect</a>, <a href="#union">union</a>, <a href="#unique">unique</a></div>
</section>

<hr>
<section id="exists?">
 <a name="exists?"></a>
 <h2>EXISTS?<a class="headerlink" href="#exists?" title="Link to this heading">¶</a></h2>
<p>Determines if a file or URL exists.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">exists? <span class="rebarg">target</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  target      [<span class="types">file! url!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false if the file does not exist.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print exists? %file.txt
false

print exists? %doc.r
false</code></pre></div>
<div class="see-also">See also: <a href="#delete">delete</a>, <a href="#modified?">modified?</a>, <a href="#read">read</a>, <a href="#size?">size?</a>, <a href="#write">write</a></div>
</section>

<hr>
<section id="exit">
 <a name="exit"></a>
 <h2>EXIT<a class="headerlink" href="#exit" title="Link to this heading">¶</a></h2>
<p>Exits a function, returning no value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">exit</span></pre>

<h6>Description:</h6>
<p>
<a href="#exit">exit</a> is used to return from a function without returning a value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">test-str: make function! [str] [
    if not string? str [exit]
    print str
]
test-str 10
test-str "right"</code></pre></div><p>
Note: Use <a href="#quit">quit</a> to exit the interpreter.
</p>

<div class="see-also">See also: <a href="#break">break</a>, <a href="#catch">catch</a>, <a href="#return">return</a></div>
</section>

<hr>
<section id="exp">
 <a name="exp"></a>
 <h2>EXP<a class="headerlink" href="#exp" title="Link to this heading">¶</a></h2>
<p>Raises E (the base of natural logarithm) to the power specified</p>

<h6>Usage:</h6>
<pre class="usage fs-6">exp <span class="rebarg">power</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  power       [<span class="types">number!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#exp">exp</a> function returns the exponential value of the argument provided.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print exp 3
20.08553692318766</code></pre></div><p>
On overflow, an error is returned (which can be trapped with the <a href="#try">try</a> function). On underflow, a 0 is returned.
</p>

<div class="see-also">See also: <a href="#log-10">log-10</a>, <a href="#log-2">log-2</a>, <a href="#log-e">log-e</a>, <a href="#power">power</a></div>
</section>

<hr>
<section id="extend">
 <a name="extend"></a>
 <h2>EXTEND<a class="headerlink" href="#extend" title="Link to this heading">¶</a></h2>
<p>Extend an object, map, or block type with word and value pair.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">extend <span class="rebarg">obj</span> <span class="rebarg">word</span> <span class="rebarg">val</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  obj         [<span class="types">object! map! block! paren!</span>] object to extend (modified)
  word        [<span class="types">any-word!</span>] 
  val          
</pre>

<h6>Description:</h6>
<p>
This function is useful to extend <span class="datatype">object!</span>, <span class="datatype">map!</span> or <span class="datatype">block!</span> values using a word/value pair. It returns the input value. It performs no copy.
</p>
<p>
Examples:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">a: [b: 1 c: 2]
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
]</code></pre></div>
<div class="see-also">See also: <a href="#context">context</a></div>
</section>

<hr>
<section id="extract">
 <a name="extract"></a>
 <h2>EXTRACT<a class="headerlink" href="#extract" title="Link to this heading">¶</a></h2>
<p>Extracts a value from a series at regular intervals.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">extract <span class="rebarg">series</span> <span class="rebarg">width</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series!</span>] 
  width       [<span class="types">integer!</span>] Size of each entry (the skip)
<span class="tit">REFINEMENTS:</span>
  /index      Extract from an offset position
   pos         The position(s)
</pre>

<h6>Description:</h6>
<p>
Returns a series of values from regularly spaced positions within a specified series. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: ["Dog" 10 "Cat" 15 "Fish" 20]
probe extract data 2
["Dog" "Cat" "Fish"]</code></pre></div><p>
Essentially, <a href="#extract">extract</a> lets you access a series as a record or "row" of a given length (specified by the width argument). The default, as shown above, extracts the first value. If you wanted to extract the second value (the second "column" of data):
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: ["Dog" 10 "Cat" 15 "Fish" 20]
probe extract/index data 2 2
[10 15 20]</code></pre></div><p>
In the example below, the width of each row is three:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">people: [
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
["Bob" "Cat" "Ted"]</code></pre></div><p>
Of course, <a href="#extract">extract</a> works on any <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a>, not just those that appear in a row format (such as that above). The example below creates a block containing every other word from a string:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "This is a given block here"
blk: parse str none
probe blk
["This" "is" "a" "given" "block" "here"]

probe extract blk 2
["This" "a" "block"]

probe extract/index blk 2 2
["is" "given" "here"]</code></pre></div><p>
Here is an example that uses <a href="#extract">extract</a> to obtain the names of all the predefined REBOL/View VID styles:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe extract system/view/vid/vid-styles 2</code></pre></div>
</section>

<hr>
<section id="fifth">
 <a name="fifth"></a>
 <h2>FIFTH<a class="headerlink" href="#fifth" title="Link to this heading">¶</a></h2>
<p>Returns the fifth value of a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">fifth <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
This is an ordinal.
</p>
<p>
See the <a href="#first">first</a> function for examples. If no value is found, none is returned.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print fifth "REBOL"
L

print fifth [11 22 33 44 55 66]
55</code></pre></div>
<div class="see-also">See also: <a href="#first">first</a>, <a href="#fourth">fourth</a>, <a href="#pick">pick</a>, <a href="#second">second</a>, <a href="#third">third</a></div>
</section>

<hr>
<section id="file-checksum">
 <a name="file-checksum"></a>
 <h2>FILE-CHECKSUM<a class="headerlink" href="#file-checksum" title="Link to this heading">¶</a></h2>
<p>Computes a checksum of a given file's content</p>

<h6>Usage:</h6>
<pre class="usage fs-6">file-checksum <span class="rebarg">file</span> <span class="rebarg">method</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  file        [<span class="types">file!</span>] Using 256kB chunks
  method      [<span class="types">word!</span>] One of system/catalog/checksums
</pre>
</section>

<hr>
<section id="file?">
 <a name="file?"></a>
 <h2>FILE?<a class="headerlink" href="#file?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">file? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values. Note that <a href="#file?">file?</a> does not check for the existence of a file, but whether or not a value is the FILE! datatype.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print file? %file.txt
true

print file? "REBOL"
false</code></pre></div><p>
Note also this is not a direct opposite to the <a href="#dir?">dir?</a> function as <a href="#dir?">dir?</a> does not test against a datatype, where <a href="#file?">file?</a> does.
</p>

<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="file-type?">
 <a name="file-type?"></a>
 <h2>FILE-TYPE?<a class="headerlink" href="#file-type?" title="Link to this heading">¶</a></h2>
<p>Return the identifying word for a specific file type (or NONE).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">file-type? <span class="rebarg">file</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  file        [<span class="types">file! url!</span>] 
</pre>
</section>

<hr>
<section id="filter">
 <a name="filter"></a>
 <h2>FILTER<a class="headerlink" href="#filter" title="Link to this heading">¶</a></h2>
<p>PNG delta filter</p>

<h6>Usage:</h6>
<pre class="usage fs-6">filter <span class="rebarg">data</span> <span class="rebarg">width</span> <span class="rebarg">type</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">binary!</span>] Input
  width       [<span class="types">number!</span>] Scanline width
  type        [<span class="types">integer! word!</span>] 1..4 or one of: [sub up average paeth]
<span class="tit">REFINEMENTS:</span>
  /skip       
   bpp        [<span class="types">integer!</span>] Bytes per pixel
</pre>
</section>

<hr>
<section id="find">
 <a name="find"></a>
 <h2>FIND<a class="headerlink" href="#find" title="Link to this heading">¶</a></h2>
<p>Searches for a value; for series returns where found, else none.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">find <span class="rebarg">series</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port! bitset! typeset! object! map! none!</span>] 
  value       [<span class="types">any-type!</span>] 
<span class="tit">REFINEMENTS:</span>
  /part       Limits the search to a given length or position
   range      [<span class="types">number! series! pair!</span>] 
  /only       Treats a series value as only a single value
  /case       Characters are case-sensitive
  /same       Use "same?" as comparator
  /any        Enables the * and ? wildcards
  /with       Allows custom wildcards
   wild       [<span class="types">string!</span>] Specifies alternates for * and ?
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] 
  /last       Backwards from end of series
  /reverse    Backwards from the current position
  /tail       Returns the end of the series
  /match      Performs comparison and returns the head of the match (not imply /tail)
</pre>

<h6>Description:</h6>
<p>
Returns <span class="datatype">none!</span> if the value was not found. Otherwise, returns a position in the series where the value was found. Many refinements to this function are available.
</p>

<h7>Refinements</h7><p>
Use /tail to return the position just past the match.
</p>
<p>
Use /case to specify that the search should be case sensitive. Note that using <a href="#find">find</a> on a binary string will do a case-insensitive search.
</p>
<p>
The /match refinement can be used to perform a character by character match of the input value to the series. The position just past the match is returned.
</p>
<p>
Wildcards can be specified with /any.
</p>
<p>
The /only refinement applies to block values and is ignored for strings.
</p>
<p>
The /last refinement causes <a href="#find">find</a> to search from the tail of the series toward the head.
</p>
<p>
And, /reverse searches backwards from the current position toward the head.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe find "here and now" "and"
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
none</code></pre></div>
<div class="see-also">See also: <a href="#pick">pick</a>, <a href="#select">select</a></div>
</section>

<hr>
<section id="find-all">
 <a name="find-all"></a>
 <h2>FIND-ALL<a class="headerlink" href="#find-all" title="Link to this heading">¶</a></h2>
<p>Find all occurrences of a value within a series (allows modification).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">find-all <span class="rebarg">series</span> <span class="rebarg">value</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">word!</span>] Variable for block, string, or other series
  value        
  body        [<span class="types">block!</span>] Evaluated for each occurrence
</pre>
</section>

<hr>
<section id="find-max">
 <a name="find-max"></a>
 <h2>FIND-MAX<a class="headerlink" href="#find-max" title="Link to this heading">¶</a></h2>
<p>Returns the series where the largest value is found, or none if the series is empty.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">find-max <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series!</span>] Series to search
<span class="tit">REFINEMENTS:</span>
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="find-min">
 <a name="find-min"></a>
 <h2>FIND-MIN<a class="headerlink" href="#find-min" title="Link to this heading">¶</a></h2>
<p>Returns the series where the smallest value is found, or none if the series is empty.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">find-min <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series!</span>] Series to search
<span class="tit">REFINEMENTS:</span>
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="find-script">
 <a name="find-script"></a>
 <h2>FIND-SCRIPT<a class="headerlink" href="#find-script" title="Link to this heading">¶</a></h2>
<p>Find a script header within a binary string. Returns starting position.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">find-script <span class="rebarg">script</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  script      [<span class="types">binary!</span>] 
</pre>

<h6>Description:</h6>
<p>
This is a high-speed lower level function to scan UTF-8 for a REBOL script signature, useful during loading of scripts and to ensure that scripts are proper UTF-8.
</p>
<p>
Editor note: Not sure about the description
</p>

</section>

<hr>
<section id="first">
 <a name="first"></a>
 <h2>FIRST<a class="headerlink" href="#first" title="Link to this heading">¶</a></h2>
<p>Returns the first value of a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">first <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
This is an ordinal. It returns the first value in any type of <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a> at the current position. If no value is found, none is returned.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print first "REBOL"
R

print first [11 22 33 44 55 66]
11

print first 1:30
1

print first 199.4.80.1
199

print first 12:34:56.78
12</code></pre></div>
<div class="see-also">See also: <a href="#fifth">fifth</a>, <a href="#fourth">fourth</a>, <a href="#pick">pick</a>, <a href="#second">second</a>, <a href="#third">third</a></div>
</section>

<hr>
<section id="first+">
 <a name="first+"></a>
 <h2>FIRST+<a class="headerlink" href="#first+" title="Link to this heading">¶</a></h2>
<p>Return the FIRST of a series then increment the series index.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">first+ <span class="rebarg">word</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word!</span>] Word must refer to a series
</pre>

<h6>Description:</h6>
<p>
Example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">blk: [a b c]
first+ blk
a

first+ blk
b

first+ blk
c

first+ blk
none</code></pre></div>
</section>

<hr>
<section id="flush">
 <a name="flush"></a>
 <h2>FLUSH<a class="headerlink" href="#flush" title="Link to this heading">¶</a></h2>
<p>Flush output stream buffer.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">flush <span class="rebarg">port</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  port        [<span class="types">port!</span>] 
</pre>
</section>

<hr>
<section id="for">
 <a name="for"></a>
 <h2>FOR<a class="headerlink" href="#for" title="Link to this heading">¶</a></h2>
<p>Evaluate a block over a range of values. (See also: REPEAT)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">for <span class="rebarg">word</span> <span class="rebarg">start</span> <span class="rebarg">end</span> <span class="rebarg">bump</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word!</span>] Variable to hold current value
  start       [<span class="types">series! number! pair!</span>] Starting value
  end         [<span class="types">series! number! pair!</span>] Ending value
  bump        [<span class="types">number! pair!</span>] Amount to skip each time
  body        [<span class="types">block!</span>] Block to evaluate
</pre>

<h6>Description:</h6>
<p>
The first argument is used as a local variable to keep track of the current value. It is initially set to the START value and after each evaluation of the block the BUMP value is added to it until the END value is reached (inclusive).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">for num 0 30 10 [ print num ]
30

for num 4 -37 -15 [ print num ]
-26</code></pre></div>
<div class="see-also">See also: <a href="#forall">forall</a>, <a href="#foreach">foreach</a>, <a href="#forever">forever</a>, <a href="#forskip">forskip</a>, <a href="#loop">loop</a>, <a href="#map-each">map-each</a>, <a href="#remove-each">remove-each</a>, <a href="#repeat">repeat</a></div>
</section>

<hr>
<section id="forall">
 <a name="forall"></a>
 <h2>FORALL<a class="headerlink" href="#forall" title="Link to this heading">¶</a></h2>
<p>Evaluates a block for every value in a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">forall <span class="rebarg">word</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word!</span>] Word that refers to the series, set to each position in series
  body        [<span class="types">block!</span>] Block to evaluate each time
</pre>

<h6>Description:</h6>
<p>
The <a href="#forall">forall</a> function moves through a series one value at a time.
</p>
<p>
The word argument is a variable that moves through the series. Prior to evaluation, the word argument must be set to the desired starting position within the series (normally the head, but any position is valid). After each evaluation of the block, the word will be advanced to the next position within the series.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">cities: ["Eureka" "Ukiah" "Santa Rosa" "Mendocino"]
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
f</code></pre></div><p>
When <a href="#forall">forall</a> finishes the word is reset to the starting position of the series.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">chars: next "abcdef"
"bcdef"

forall chars []
chars
"bcdef"</code></pre></div><p>
The result of <a href="#forall">forall</a> is the result of the last expression of the block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">chars: "abcdef"
forall chars [first chars]
#"f"</code></pre></div><p>
Or the result of a break/return from the block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">chars: "abcdef"
forall chars [break/return 5]
5</code></pre></div><p>
The <a href="#forall">forall</a> function can be thought of as a shortcut for:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">[
    original: series
    while [not tail? series] [
        x: (your code)
        series: next series
    ]
    series: original
    :x
]</code></pre></div>
<div class="see-also">See also: <a href="#for">for</a>, <a href="#foreach">foreach</a>, <a href="#forever">forever</a>, <a href="#forskip">forskip</a>, <a href="#until">until</a>, <a href="#while">while</a></div>
</section>

<hr>
<section id="foreach">
 <a name="foreach"></a>
 <h2>FOREACH<a class="headerlink" href="#foreach" title="Link to this heading">¶</a></h2>
<p>Evaluates a block for each value(s) in a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">foreach <span class="rebarg">word</span> <span class="rebarg">data</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word! block!</span>] Word or block of words to set each time (local)
  data        [<span class="types">series! any-object! map! none!</span>] The series to traverse
  body        [<span class="types">block!</span>] Block to evaluate each time
</pre>

<h6>Description:</h6>
<p>
The <a href="#foreach">foreach</a> function repeats the evaluation of a block for each element of a series. It is used often in programs.
</p>
<p>
Example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">values: [11 22 33]
foreach value values [print value]
11
22
33</code></pre></div><p>
Another example that prints each word in a block along with its value:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">colors: [red green blue]
foreach color colors [print [color get color]]
red 255.0.0
green 0.255.0
blue 0.0.255</code></pre></div><p>
If the series is a string, each character will be fetched:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">string: "REBOL"
foreach char string [print char]
R
E
B
O
L</code></pre></div><p>
This example will print each filename from a directory block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">files: read %.
foreach file files [
    if find file ".t" [print file]
]
file.txt
file2.txt
newfile.txt
output.txt</code></pre></div><fieldset class="fset"><legend>Local Variables</legend>
<p>The variables used to hold the <a href="#foreach">foreach</a> values are local to the block. Their value are only set within the block that is being repeated. Once the loop has exited, the variables return to their previously set values.</p>
</fieldset>
<h6>Multiple Elements</h6><p>
When a block contains groups of values that are related, <a href="#foreach">foreach</a> function can fetch all elements at the same time. For example, here is a block that contains a time, string, and price. By providing the <a href="#foreach">foreach</a> function with a block of words for the group, each of their values can be fetched and printed.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">movies: [
     8:30 "Contact"      $4.95
    10:15 "Ghostbusters" $3.25
    12:45 "Matrix"       $4.25
]

foreach [time title price] movies [
    print ["watch" title "at" time "for" price]
]
watch Contact at 8:30 for $4.95
watch Ghostbusters at 10:15 for $3.25
watch Matrix at 12:45 for $4.25</code></pre></div><p>
In the above example, the <a href="#foreach">foreach</a> value block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">[time title price]</code></pre></div><p>
specifies that three values are to be fetched from movies for each evaluation of the block.
</p>

<h6>Series Reference</h6><p>
To reference the series itself during <a href="#foreach">foreach</a> you can use a <span class="datatype">set-word!</span> within the variable block. This operation is similar to the <a href="#forall">forall</a> and <a href="#forskip">forskip</a> functions.
</p>
<p>
Example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">foreach [v1: v2] [1 2 3] [?? [v1 v2]]
v1: [1 2 3] v2: 1
v1: [2 3] v2: 2
v1: [3] v2: 3</code></pre></div><p>
Notice that the v1 set-word does not affect the index position.
</p>
<p>
If you are using this option to remove values, please see the <a href="#remove-each">remove-each</a> function which is many times faster for large series.
</p>

<h6>Foreach of Objects and Maps</h6><p>
The <a href="#foreach">foreach</a> function can also be used with <span class="datatype">object!</span> and <span class="datatype">map!</span> datatypes.
</p>
<p>
When using a single word argument, <a href="#foreach">foreach</a> will obtain the object field name or map key.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">fruits: make object! [apple: 10 orange: 12 banana: 30]
foreach field fruits [print field]
apple
orange
banana</code></pre></div><p>
Note that each word is bound back to the object, and can be used to access the field value with <a href="#get">get</a> and <a href="#set">set</a>.
</p>
<p>
If a second word argument is provided, it will obtain the value of each entry:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">foreach [field value] fruits [print [field value]]
apple 10
orange 12
banana 30</code></pre></div><p>
The same behavior applies to the <span class="datatype">map!</span> datatype, except that empty keys (those set to none) will be skipped.
</p>
<p>
When a <span class="datatype">set-word!</span> is used in the variables block, it will obtain the object value itself.
</p>

<div class="see-also">See also: <a href="#for">for</a>, <a href="#forall">forall</a>, <a href="#forskip">forskip</a>, <a href="#map-each">map-each</a>, <a href="#remove-each">remove-each</a>, <a href="#repeat">repeat</a></div>
</section>

<hr>
<section id="forever">
 <a name="forever"></a>
 <h2>FOREVER<a class="headerlink" href="#forever" title="Link to this heading">¶</a></h2>
<p>Evaluates a block endlessly.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">forever <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  body        [<span class="types">block!</span>] Block to evaluate each time
</pre>

<h6>Description:</h6>
<p>
Evaluates a block continuously, or until a break or error condition is met.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">forever [
    if (random 10) &gt; 5 [break]
]</code></pre></div>
<div class="see-also">See also: <a href="#for">for</a>, <a href="#loop">loop</a>, <a href="#repeat">repeat</a>, <a href="#until">until</a>, <a href="#while">while</a></div>
</section>

<hr>
<section id="form">
 <a name="form"></a>
 <h2>FORM<a class="headerlink" href="#form" title="Link to this heading">¶</a></h2>
<p>Converts a value to a human-readable string.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">form <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] The value to form
</pre>

<h6>Description:</h6>
<p>
The <a href="#form">form</a> function converts a value to a human readable string. It is commonly used by <a href="#print">print</a> for output.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">form 1234
"1234"

form 10:30
"10:30"

form %image.jpg
"image.jpg"</code></pre></div><p>
When given a block of values, spaces are inserted between each values (except after a newline).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">form [1 2 3]
"1 2 3"</code></pre></div><p>
To avoid the spaces between values use <a href="#ajoin">ajoin</a>, <a href="#join">join</a>, or <a href="#rejoin">rejoin</a>.
</p>
<p>
The <a href="#reform">reform</a> function combines <a href="#reduce">reduce</a> with <a href="#form">form</a> to evaluate values:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">reform [1 + 2 3 + 4]
"3 7"</code></pre></div><p>
To produce REBOL-readable output, use the <a href="#mold">mold</a> function.
</p>

<div class="see-also">See also: <a href="#ajoin">ajoin</a>, <a href="#join">join</a>, <a href="#mold">mold</a>, <a href="#print">print</a>, <a href="#reform">reform</a>, <a href="#rejoin">rejoin</a>, <a href="#remold">remold</a></div>
</section>

<hr>
<section id="form-oid">
 <a name="form-oid"></a>
 <h2>FORM-OID<a class="headerlink" href="#form-oid" title="Link to this heading">¶</a></h2>
<p>Return the x.y.z.... style numeric string for the given OID</p>

<h6>Usage:</h6>
<pre class="usage fs-6">form-oid <span class="rebarg">oid</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  oid         [<span class="types">binary!</span>] 
</pre>
</section>

<hr>
<section id="format">
 <a name="format"></a>
 <h2>FORMAT<a class="headerlink" href="#format" title="Link to this heading">¶</a></h2>
<p>Format a string according to the format dialect.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">format <span class="rebarg">rules</span> <span class="rebarg">values</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  rules        A block in the format dialect. E.g. [10 -10 #"-" 4 $32 "green" $0]
  values       
<span class="tit">REFINEMENTS:</span>
  /pad        
   p           Pattern to use instead of spaces
</pre>

<h6>Description:</h6>
<p>
This is useful for table output in the console, where fixed-width fonts are used. It can also be used to specially format numbers or complex values.
</p>
<p>
The first input, is the dialect. It's a combination of positive or negative formatting integers and strings or chars, that are to be inserted between the integers.
</p>
<p>
A positive integer N, means the value will be left adjusted with N chars for space.
</p>
<p>
A negative integer N, means the value will be right adjusted with N chars for space.
</p>
<p>
In both cases, a value that takes up more space than N, is truncated to N chars.
</p>
<p>
The second input is the values, either as a block or as a single value.
</p>
<p>
Example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">format [-3 -3 -4] [1 2 3]
"  1  2   3"</code></pre></div><p>
Format a time value using /pad to add zeroes:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">format/pad [-2 ":" -2 ":" -2] [12 47 9] 0
"12:47:09"</code></pre></div><p>
It can also be used to pad zeroes to a single numeric value:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">format/pad [-8] 5125 0
"00005125"</code></pre></div>
</section>

<hr>
<section id="format-date-time">
 <a name="format-date-time"></a>
 <h2>FORMAT-DATE-TIME<a class="headerlink" href="#format-date-time" title="Link to this heading">¶</a></h2>
<p>replaces a subset of ISO 8601 abbreviations such as yyyy-MM-dd hh:mm:ss</p>

<h6>Usage:</h6>
<pre class="usage fs-6">format-date-time <span class="rebarg">value</span> <span class="rebarg">rule</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">date! time!</span>] 
  rule        [<span class="types">string! tag!</span>] 
</pre>
</section>

<hr>
<section id="format-time">
 <a name="format-time"></a>
 <h2>FORMAT-TIME<a class="headerlink" href="#format-time" title="Link to this heading">¶</a></h2>
<p>Convert a time value to a human readable string</p>

<h6>Usage:</h6>
<pre class="usage fs-6">format-time <span class="rebarg">time</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  time        [<span class="types">time!</span>] 
</pre>
</section>

<hr>
<section id="forskip">
 <a name="forskip"></a>
 <h2>FORSKIP<a class="headerlink" href="#forskip" title="Link to this heading">¶</a></h2>
<p>Evaluates a block for periodic values in a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">forskip <span class="rebarg">word</span> <span class="rebarg">size</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word!</span>] Word that refers to the series, set to each position in series
  size        [<span class="types">integer! decimal!</span>] Number of positions to skip each time
  body        [<span class="types">block!</span>] Block to evaluate each time
</pre>

<h6>Description:</h6>
<p>
Prior to evaluation, the word must be set to the desired starting position within the series (normally the head, but any position is valid). After each evaluation of the block, the word's position in the series is changed by skipping the number of values specified by the second argument (see the <a href="#skip">skip</a> function).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">areacodes: [
    "Ukiah"         707
    "San Francisco" 415
    "Sacramento"    916
]
forskip areacodes 2 [
    print [ first areacodes "area code is" second areacodes]
]
Sacramento area code is 916</code></pre></div>
<div class="see-also">See also: <a href="#for">for</a>, <a href="#forall">forall</a>, <a href="#foreach">foreach</a>, <a href="#skip">skip</a></div>
</section>

<hr>
<section id="fourth">
 <a name="fourth"></a>
 <h2>FOURTH<a class="headerlink" href="#fourth" title="Link to this heading">¶</a></h2>
<p>Returns the fourth value of a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">fourth <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
This is an ordinal.
</p>
<p>
See the <a href="#first">first</a> function for examples. If no value is found, none is returned.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print fourth "REBOL"
O

print fourth [11 22 33 44 55 66]
44

print fourth 199.4.80.1
1</code></pre></div>
<div class="see-also">See also: <a href="#fifth">fifth</a>, <a href="#first">first</a>, <a href="#pick">pick</a>, <a href="#second">second</a>, <a href="#third">third</a></div>
</section>

<hr>
<section id="fraction">
 <a name="fraction"></a>
 <h2>FRACTION<a class="headerlink" href="#fraction" title="Link to this heading">¶</a></h2>
<p>Returns the fractional part of a decimal value</p>

<h6>Usage:</h6>
<pre class="usage fs-6">fraction <span class="rebarg">number</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  number      [<span class="types">decimal!</span>] 
</pre>
</section>

<hr>
<section id="frame?">
 <a name="frame?"></a>
 <h2>FRAME?<a class="headerlink" href="#frame?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">frame? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id="func">
 <a name="func"></a>
 <h2>FUNC<a class="headerlink" href="#func" title="Link to this heading">¶</a></h2>
<p>Defines a user function with given spec and body.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">func <span class="rebarg">spec</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">block!</span>] Help string (opt) followed by arg words (and opt type and string)
  body        [<span class="types">block!</span>] The body block of the function
</pre>

<h6>Description:</h6>
<p>
The <a href="#func">func</a> function creates new functions from a spec block and a body block.
</p>
<p>
General form:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">name: func [spec] [body]</code></pre></div><p>
The spec block specifies the interface to the function. It can begin with an optional title string which used by the <a href="#help">help</a> function. That is followed by words that specify the arguments to the function. Each of argument can include an optional block of datatypes to specify the valid datatypes for the argument. Each may be followed by a comment string which describes the argument in more detail.
</p>
<p>
The argument words may also specify a few variations on the way the argument will be evaluated. The most common is 'word which indicates that a word is expected that should not be evaluated (the function wants its name, not its value). A :word may also be given which will get the value of the argument, but not perform full evaluation.
</p>
<p>
To add refinements to a function supply a slash (/) in front of an argument's word. Within the function the refinement can be tested to determine if the refinement was present. If a refinement is followed by more arguments, they will be associated with that refinement and are only evaluated when the refinement is present.
</p>
<p>
Local variables are specified after a /local refinement.
</p>
<p>
A function returns the last expression it evaluated. You can also use <a href="#return">return</a> and <a href="#exit">exit</a> to exit the function. A <a href="#return">return</a> is given a value to return. <a href="#exit">exit</a> returns no value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">sum: func [a b] [a + b]
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
testing</code></pre></div>
<div class="see-also">See also: <a href="#closure">closure</a>, <a href="#does">does</a>, <a href="#exit">exit</a>, <a href="#funco">funco</a>, <a href="#funct">funct</a>, <a href="#function">function</a>, <a href="#function?">function?</a>, <a href="#has">has</a>, <a href="#make">make</a>, <a href="#return">return</a>, <a href="#use">use</a></div>
</section>

<hr>
<section id="funco">
 <a name="funco"></a>
 <h2>FUNCO<a class="headerlink" href="#funco" title="Link to this heading">¶</a></h2>
<p>Non-copying function constructor (optimized for boot).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">funco <span class="rebarg">spec</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">block!</span>] Help string (opt) followed by arg words (and opt type and string)
  body        [<span class="types">block!</span>] The body block of the function
</pre>

<h6>Description:</h6>
<p>
Similar to <a href="#func">func</a>, except the spec or body is not copied.
</p>

<div class="see-also">See also: <a href="#closure">closure</a>, <a href="#does">does</a>, <a href="#exit">exit</a>, <a href="#func">func</a>, <a href="#funct">funct</a>, <a href="#function">function</a>, <a href="#function?">function?</a>, <a href="#has">has</a>, <a href="#make">make</a>, <a href="#return">return</a>, <a href="#use">use</a></div>
</section>

<hr>
<section id="funct">
 <a name="funct"></a>
 <h2>FUNCT<a class="headerlink" href="#funct" title="Link to this heading">¶</a></h2>
<p>Defines a function with all set-words as locals.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">funct <span class="rebarg">spec</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">block!</span>] Help string (opt) followed by arg words (and opt type and string)
  body        [<span class="types">block!</span>] The body block of the function
<span class="tit">REFINEMENTS:</span>
  /with       Define or use a persistent object (self)
   object     [<span class="types">any-object! block! map!</span>] The object or spec
  /extern     
   words      [<span class="types">block!</span>] These words are not local
</pre>

<h6>Description:</h6>
<p>
This is similar to <a href="#func">func</a>, except all set-words are assumed locals. This way, it's not necessary to specify the /local part of the spec, although you still can.
</p>
<p>
Example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">f: funct [a] [
    b: a
]
f 7
7

b
** Script error: b has no value</code></pre></div><p>
If you still desire to create non-local values in the function, use <a href="#set">set</a> to set words:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">f: funct [a] [
    b: a
    set 'c b / 2
]
f 7
3.5

c
3.5</code></pre></div><p>
If c still needs to be local, you can add the local refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">unset 'c ; make sure it's not set
f: funct [a /local c] [
    b: a
    set 'c b / 2
]
f 7
3.5

c
** Script error: c has no value</code></pre></div>
</section>

<hr>
<section id="function">
 <a name="function"></a>
 <h2>FUNCTION<a class="headerlink" href="#function" title="Link to this heading">¶</a></h2>
<p>Defines a function with all set-words as locals.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">function <span class="rebarg">spec</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">block!</span>] Help string (opt) followed by arg words (and opt type and string)
  body        [<span class="types">block!</span>] The body block of the function
<span class="tit">REFINEMENTS:</span>
  /with       Define or use a persistent object (self)
   object     [<span class="types">any-object! block! map!</span>] The object or spec
  /extern     
   words      [<span class="types">block!</span>] These words are not local
</pre>

<h6>Description:</h6>
<fieldset class="fset"><legend>Warning!</legend>
<p>The descripton of <a href="#function">function</a> given below is up-to-date, however the spec shown above is not current. <a href="#function">function</a> was <a href="http://www.rebol.com/article/0543.html" class="lnk">recently adapted</a> from a 3-argument to a 2-argument variant.</p>
</fieldset><p>
This is similar to <a href="#func">func</a>, except all set-words are assumed locals. This way, it's not necessary to specify the /local part of the spec, although you still can.
</p>
<p>
Example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">average: function [block] [
    total: 0
    foreach number block [total: number + total]
    total / (length? block)
]
print average [1 10 12.34]
7.78

total
** Script error: total has no value</code></pre></div><p>
If you still desire to create non-local values in the function, use <a href="#set">set</a> to set words:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">f: function [a] [
    b: a
    set 'c b / 2
]
f 7
3.5

c
3.5</code></pre></div><p>
If c still needs to be local, you can add the local refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">unset 'c ; make sure it's not set
f: function [a /local c] [
    b: a
    set 'c b / 2
]
f 7
3.5

c
** Script error: c has no value</code></pre></div>
<div class="see-also">See also: <a href="#does">does</a>, <a href="#exit">exit</a>, <a href="#func">func</a>, <a href="#function?">function?</a>, <a href="#has">has</a>, <a href="#make">make</a>, <a href="#return">return</a>, <a href="#use">use</a></div>
</section>

<hr>
<section id="function?">
 <a name="function?"></a>
 <h2>FUNCTION?<a class="headerlink" href="#function?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">function? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print function? :func
true

print function? "test"
false</code></pre></div>
<div class="see-also">See also: <a href="#any-function?">any-function?</a>, <a href="#type?">type?</a></div>
</section>

<hr>
<section id="gcd">
 <a name="gcd"></a>
 <h2>GCD<a class="headerlink" href="#gcd" title="Link to this heading">¶</a></h2>
<p>Returns the greatest common divisor</p>

<h6>Usage:</h6>
<pre class="usage fs-6">gcd <span class="rebarg">a</span> <span class="rebarg">b</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  a           [<span class="types">integer!</span>] 
  b           [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="generate">
 <a name="generate"></a>
 <h2>GENERATE<a class="headerlink" href="#generate" title="Link to this heading">¶</a></h2>
<p>Generate specified cryptographic key</p>

<h6>Usage:</h6>
<pre class="usage fs-6">generate <span class="rebarg">type</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  type        [<span class="types">word!</span>] Key type: system/catalog/elliptic-curves
</pre>
</section>

<hr>
<section id="get">
 <a name="get"></a>
 <h2>GET<a class="headerlink" href="#get" title="Link to this heading">¶</a></h2>
<p>Gets the value of a word or path, or values of an object.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">get <span class="rebarg">word</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word         Word, path, object to get
<span class="tit">REFINEMENTS:</span>
  /any        Allows word to have no value (allows unset)
</pre>

<h6>Description:</h6>
<p>
The argument to <a href="#get">get</a> must be a word, so the argument must be quoted or extracted from a block. To get the value of a word residing in an object, use the <a href="#in">in</a> function.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">value: 123
print get 'value
123

print get second [the value here]
123

print get in system/console 'prompt
&gt;&gt;</code></pre></div><p>
If the argument to <a href="#get">get</a> is an object, the result is the same as that of <a href="#values-of">values-of</a>.
</p>

<div class="see-also">See also: <a href="#in">in</a>, <a href="#set">set</a>, <a href="#value?">value?</a></div>
</section>

<hr>
<section id="get-cookies">
 <a name="get-cookies"></a>
 <h2>GET-COOKIES<a class="headerlink" href="#get-cookies" title="Link to this heading">¶</a></h2>
<p>Retrieves and formats valid cookies for HTTP requests.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">get-cookies <span class="rebarg">host</span> <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  host        [<span class="types">string!</span>] The host for which cookies are being retrieved.
  path        [<span class="types">string! file!</span>] The path for which cookies are being retrieved.
</pre>
</section>

<hr>
<section id="get-env">
 <a name="get-env"></a>
 <h2>GET-ENV<a class="headerlink" href="#get-env" title="Link to this heading">¶</a></h2>
<p>Returns the value of an OS environment variable (for current process).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">get-env <span class="rebarg">var</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  var         [<span class="types">any-string! any-word!</span>] 
</pre>

<h6>Description:</h6>
<p>
This function will return the string associated with an OS environment variable.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe get-env "COMPUTERNAME"
"BIGBOY"</code></pre></div><p>
To obtain a list of all environment variables and their values, use <a href="#list-env">list-env</a>.
</p>

<div class="see-also">See also: <a href="#list-env">list-env</a></div>
</section>

<hr>
<section id="get-path?">
 <a name="get-path?"></a>
 <h2>GET-PATH?<a class="headerlink" href="#get-path?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">get-path? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">get-path? to-get-path 'path/to/somewhere
true</code></pre></div>
<div class="see-also">See also: <a href="#lit-path?">lit-path?</a>, <a href="#path?">path?</a>, <a href="#set-path?">set-path?</a></div>
</section>

<hr>
<section id="get-word?">
 <a name="get-word?"></a>
 <h2>GET-WORD?<a class="headerlink" href="#get-word?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">get-word? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print get-word? second [pr: :print]
true</code></pre></div>
<div class="see-also">See also: <a href="#lit-word?">lit-word?</a>, <a href="#set-word?">set-word?</a>, <a href="#word?">word?</a></div>
</section>

<hr>
<section id="gob?">
 <a name="gob?"></a>
 <h2>GOB?<a class="headerlink" href="#gob?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">gob? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">gob? make gob! [text: "this is a gob!"]
true</code></pre></div>
</section>

<hr>
<section id="greater-or-equal?">
 <a name="greater-or-equal?"></a>
 <h2>GREATER-OR-EQUAL?<a class="headerlink" href="#greater-or-equal?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the first value is greater than or equal to the second value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">greater-or-equal? <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1       
  value2       
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values. Both values must be of the same datatype or an error will occur. For string-based datatypes, the sorting order is used for comparison with character casing ignored (uppercase = lowercase).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print greater-or-equal? "abc" "abb"
true

print greater-or-equal? 16-June-1999 12-june-1999
true

print greater-or-equal? 1.2.3.4 4.3.2.1
false

print greater-or-equal? 1:00 11:00
false</code></pre></div>
<div class="see-also">See also: <a href="#<">&lt;</a>, <a href="#<=">&lt;=</a>, <a href="#<>">&lt;&gt;</a>, <a href="#=">=</a>, <a href="#>">&gt;</a>, <a href="#>=">&gt;=</a>, <a href="#equal?">equal?</a>, <a href="#lesser-or-equal?">lesser-or-equal?</a>, <a href="#max">max</a>, <a href="#min">min</a>, <a href="#not-equal?">not-equal?</a></div>
</section>

<hr>
<section id="greater?">
 <a name="greater?"></a>
 <h2>GREATER?<a class="headerlink" href="#greater?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the first value is greater than the second value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">greater? <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1       
  value2       
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values. The values must be of the same datatype or an error will occur. For string-based datatypes, the sorting order is used for comparison with character casing ignored (uppercase = lowercase).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print greater? "abc" "abb"
true

print greater? 16-June-1999 12-june-1999
true

print greater? 4.3.2.1 1.2.3.4
true

print greater? 11:00 12:00
false</code></pre></div>
<div class="see-also">See also: <a href="#<">&lt;</a>, <a href="#<=">&lt;=</a>, <a href="#<>">&lt;&gt;</a>, <a href="#=">=</a>, <a href="#>">&gt;</a>, <a href="#>=">&gt;=</a>, <a href="#lesser?">lesser?</a>, <a href="#max">max</a>, <a href="#min">min</a></div>
</section>

<hr>
<section id="gui-metric">
 <a name="gui-metric"></a>
 <h2>GUI-METRIC<a class="headerlink" href="#gui-metric" title="Link to this heading">¶</a></h2>
<p>Returns specific gui related metric setting.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">gui-metric <span class="rebarg">keyword</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  keyword     [<span class="types">word!</span>] Available keywords: SCREENS, BORDER-FIXED, BORDER-SIZE, SCREEN-DPI, LOG-SIZE, PHYS-SIZE, SCREEN-SIZE, VIRTUAL-SCREEN-SIZE, TITLE-SIZE, WINDOW-MIN-SIZE, WORK-ORIGIN and WORK-SIZE.
<span class="tit">REFINEMENTS:</span>
  /set        
   val         Value used to set specific setting(works only on 'writable' keywords).
  /display    
   idx        [<span class="types">integer!</span>] Display index, starting with 0
</pre>
</section>

<hr>
<section id="halt">
 <a name="halt"></a>
 <h2>HALT<a class="headerlink" href="#halt" title="Link to this heading">¶</a></h2>
<p>Stops evaluation and returns to the input prompt.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">halt</span></pre>

<h6>Description:</h6>
<p>
Useful for program debugging.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">div: 10
if error? try [100 / div] [
    print "math error"
    halt
]</code></pre></div>
<div class="see-also">See also: <a href="#break">break</a>, <a href="#catch">catch</a>, <a href="#exit">exit</a>, <a href="#quit">quit</a></div>
</section>

<hr>
<section id="handle-events">
 <a name="handle-events"></a>
 <h2>HANDLE-EVENTS<a class="headerlink" href="#handle-events" title="Link to this heading">¶</a></h2>
<p>Adds a handler to the view event system.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">handle-events <span class="rebarg">handler</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  handler     [<span class="types">block!</span>] 
</pre>

<h6>Description:</h6>
<p>
This is used internally in the <a href="#view">view</a> function.
</p>

</section>

<hr>
<section id="handle?">
 <a name="handle?"></a>
 <h2>HANDLE?<a class="headerlink" href="#handle?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">handle? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns false for all other values.
</p>
<p>
Editor note: Need example.
</p>

</section>

<hr>
<section id="handled-events?">
 <a name="handled-events?"></a>
 <h2>HANDLED-EVENTS?<a class="headerlink" href="#handled-events?" title="Link to this heading">¶</a></h2>
<p>Returns event handler object matching a given name.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">handled-events? <span class="rebarg">name</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  name         
</pre>
</section>

<hr>
<section id="has">
 <a name="has"></a>
 <h2>HAS<a class="headerlink" href="#has" title="Link to this heading">¶</a></h2>
<p>A shortcut to define a function that has local variables but no arguments.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">has <span class="rebarg">vars</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  vars        [<span class="types">block!</span>] List of words that are local to the function
  body        [<span class="types">block!</span>] The body block of the function
</pre>

<h6>Description:</h6>
<p>
Defines a function that consists of local variables only. This is a shortcut for <a href="#func">func</a> and <a href="#function">function</a>.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">ask-name: has [name] [
    name: ask "What is your name?"
    print ["Hello" name]
]

ask-name
Hello Luke</code></pre></div><p>
The example above is a shortcut for:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">ask-name: func [/local name] [...]</code></pre></div>
<div class="see-also">See also: <a href="#does">does</a>, <a href="#exit">exit</a>, <a href="#func">func</a>, <a href="#function">function</a>, <a href="#return">return</a>, <a href="#use">use</a></div>
</section>

<hr>
<section id="hash">
 <a name="hash"></a>
 <h2>HASH<a class="headerlink" href="#hash" title="Link to this heading">¶</a></h2>
<p>Computes a hash value from any Rebol value. This number may change between different Rebol versions!</p>

<h6>Usage:</h6>
<pre class="usage fs-6">hash <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id="hash?">
 <a name="hash?"></a>
 <h2>HASH?<a class="headerlink" href="#hash?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">hash? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id="head">
 <a name="head"></a>
 <h2>HEAD<a class="headerlink" href="#head" title="Link to this heading">¶</a></h2>
<p>Returns the series at its beginning.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">head <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port!</span>] 
</pre>

<h6>Description:</h6>
<p>
The insert function returns at the current string position, so <a href="#head">head</a> adjusts the index back to the head:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "all things"
print head insert str "with "
with all things</code></pre></div><p>
Now here is not at the head:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">here: find str "all"
print here
all things</code></pre></div><p>
Now we print at the head:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print head here
with all things</code></pre></div>
<div class="see-also">See also: <a href="#head?">head?</a>, <a href="#tail">tail</a>, <a href="#tail?">tail?</a></div>
</section>

<hr>
<section id="head?">
 <a name="head?"></a>
 <h2>HEAD?<a class="headerlink" href="#head?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if a series is at its beginning.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">head? <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">cds: [
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
Rockin' REBOLs</code></pre></div>
<div class="see-also">See also: <a href="#head">head</a>, <a href="#tail">tail</a>, <a href="#tail?">tail?</a></div>
</section>

<hr>
<section id="help">
 <a name="help"></a>
 <h2>HELP<a class="headerlink" href="#help" title="Link to this heading">¶</a></h2>
<p>Prints information about words and values</p>

<h6>Usage:</h6>
<pre class="usage fs-6">help <span class="rebarg">word</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">any-type!</span>] 
<span class="tit">REFINEMENTS:</span>
  /doc        Open web browser to related documentation
  /into       Help text will be inserted into provided string instead of printed
   string     [<span class="types">string!</span>] Returned series will be past the insertion
</pre>

<h6>Description:</h6>
<p>
The <a href="#help">help</a> function provides information about words and values.
</p>
<p>
Type <a href="#help">help</a> or <a href="#?">?</a> at the console prompt to view a summary of help:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">>> help</code></pre></div>
<div class="example-code"><pre class="text-block"><code>
  <span class="ansi4 ansi1 ansi36">Use <span class="ansi1 ansi32">HELP<span class="ansi1 ansi36"> or <span class="ansi1 ansi32">?<span class="ansi1 ansi36"> to see built-in info</span></span></span></span></span>:
  <span class="ansi1 ansi32">
      help insert
      ? insert
  </span>
  <span class="ansi4 ansi1 ansi36">To search within the system, use quotes</span>:
  <span class="ansi1 ansi32">
      ? "insert"
  </span>
  <span class="ansi4 ansi1 ansi36">To browse online web documents</span>:
  <span class="ansi1 ansi32">
      help/doc insert
  </span>
  <span class="ansi4 ansi1 ansi36">To view words and values of a context or object</span>:
  
      <span class="ansi1 ansi32">? lib</span>            - the runtime library
      <span class="ansi1 ansi32">? self</span>           - your user context
      <span class="ansi1 ansi32">? system</span>         - the system object
      <span class="ansi1 ansi32">? system/options</span> - special settings
  
  <span class="ansi4 ansi1 ansi36">To see all words of a specific datatype</span>:
  <span class="ansi1 ansi32">
      ? native!
      ? function!
      ? datatype!
  </span>
  <span class="ansi4 ansi1 ansi36">To see all available codecs</span>:
  <span class="ansi1 ansi32">
      ? codecs
  </span>
  <span class="ansi4 ansi1 ansi36">Other debug functions</span>:
  
      <span class="ansi1 ansi32">??</span>      - display a variable and its value
      <span class="ansi1 ansi32">probe</span>   - print a value (molded)
      <span class="ansi1 ansi32">source</span>  - show source code of func
      <span class="ansi1 ansi32">trace</span>   - trace evaluation steps
      <span class="ansi1 ansi32">what</span>    - show a list of known functions
  
  <span class="ansi4 ansi1 ansi36">Other information</span>:
  
      <span class="ansi1 ansi32">about</span>   - see general product info
      <span class="ansi1 ansi32">license</span> - show user license
      <span class="ansi1 ansi32">usage</span>   - program cmd line options

</code></pre></div>
<h6>Help about a Function</h6><p>
If you provide a function word as an argument, <a href="#help">help</a> prints all of the information related to that function.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">>> help insert</code></pre></div>
<div class="example-code"><pre class="text-block"><code><span class="ansi4 ansi1 ansi36">USAGE</span>:
     <span class="ansi1 ansi32">INSERT series value</span>

<span class="ansi4 ansi1 ansi36">DESCRIPTION</span>:
     Inserts element(s); for series, returns just past the insert. 
     INSERT is an <span class="ansi1 ansi33">action!</span> value.

<span class="ansi4 ansi1 ansi36">ARGUMENTS</span>:
     <span class="ansi1 ansi32">series        </span><span class="ansi32">[series! port! map! gob! object! bitset!]</span> At position (modified).
     <span class="ansi1 ansi32">value         </span><span class="ansi32">[any-type!]</span> The value to insert.

<span class="ansi4 ansi1 ansi36">REFINEMENTS</span>:
     <span class="ansi1 ansi32">/part         </span>Limits to a given length or position
      <span class="ansi1 ansi33">range        <span class="ansi0 ansi32">[number! series! pair!]</span></span> 
     <span class="ansi1 ansi32">/only         </span>Only insert a block as a single value (not the contents of the block)
     <span class="ansi1 ansi32">/dup          </span>Duplicates the insert a specified number of times
      <span class="ansi1 ansi33">count        <span class="ansi0 ansi32">[number! pair!]</span></span> 

</code></pre></div><p>
For more detailed information, you can use the doc refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; help/doc insert</code></pre></div><p>
to open the web browser to the page related to that function.
</p>

<h6>Help about Datatypes</h6><p>
All datatypes are explained through help.
</p>
<p>
To obtain a list of all REBOL datatypes, type:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">>> ? datatype!</code></pre></div>
<div class="example-code"><pre class="text-block"><code><span class="ansi1 ansi32">DATATYPE!</span> is a datatype.
It is defined as a type of datatype.
It is of the general type <span class="ansi1 ansi32">symbol</span>.

Found these related words:
  <span class="ansi1 ansi32">end!           </span> datatype!  <span class="ansi32">internal marker for end of block</span>
  <span class="ansi1 ansi32">unset!         </span> datatype!  <span class="ansi32">no value returned or set</span>
  <span class="ansi1 ansi32">none!          </span> datatype!  <span class="ansi32">no value represented</span>
  <span class="ansi1 ansi32">logic!         </span> datatype!  <span class="ansi32">boolean true or false</span>
  <span class="ansi1 ansi32">integer!       </span> datatype!  <span class="ansi32">64 bit integer</span>
  <span class="ansi1 ansi32">decimal!       </span> datatype!  <span class="ansi32">64bit floating point number (IEEE standard)</span>
  <span class="ansi1 ansi32">percent!       </span> datatype!  <span class="ansi32">special form of decimals (used mainly for layout)</span>
  <span class="ansi1 ansi32">money!         </span> datatype!  <span class="ansi32">high precision decimals with denomination (opt)</span>
  <span class="ansi1 ansi32">char!          </span> datatype!  <span class="ansi32">8bit and 16bit character</span>
  <span class="ansi1 ansi32">pair!          </span> datatype!  <span class="ansi32">two dimensional point or size</span>
  <span class="ansi1 ansi32">tuple!         </span> datatype!  <span class="ansi32">sequence of small integers (colors, versions, IP)</span>
  <span class="ansi1 ansi32">time!          </span> datatype!  <span class="ansi32">time of day or duration</span>
  <span class="ansi1 ansi32">date!          </span> datatype!  <span class="ansi32">day, month, year, time of day, and timezone</span>
  <span class="ansi1 ansi32">binary!        </span> datatype!  <span class="ansi32">string series of bytes</span>
  <span class="ansi1 ansi32">string!        </span> datatype!  <span class="ansi32">string series of characters</span>
  <span class="ansi1 ansi32">file!          </span> datatype!  <span class="ansi32">file name or path</span>
  <span class="ansi1 ansi32">email!         </span> datatype!  <span class="ansi32">email address</span>
  <span class="ansi1 ansi32">ref!           </span> datatype!  <span class="ansi32">reference</span>
  <span class="ansi1 ansi32">url!           </span> datatype!  <span class="ansi32">uniform resource locator or identifier</span>
  <span class="ansi1 ansi32">tag!           </span> datatype!  <span class="ansi32">markup string (HTML or XML)</span>
  <span class="ansi1 ansi32">bitset!        </span> datatype!  <span class="ansi32">set of bit flags</span>
  <span class="ansi1 ansi32">image!         </span> datatype!  <span class="ansi32">RGB image with alpha channel</span>
  <span class="ansi1 ansi32">vector!        </span> datatype!  <span class="ansi32">high performance arrays (single datatype)</span>
  <span class="ansi1 ansi32">block!         </span> datatype!  <span class="ansi32">series of values</span>
  <span class="ansi1 ansi32">paren!         </span> datatype!  <span class="ansi32">automatically evaluating block</span>
  <span class="ansi1 ansi32">path!          </span> datatype!  <span class="ansi32">refinements to functions, objects, files</span>
  <span class="ansi1 ansi32">set-path!      </span> datatype!  <span class="ansi32">definition of a path's value</span>
  <span class="ansi1 ansi32">get-path!      </span> datatype!  <span class="ansi32">the value of a path</span>
  <span class="ansi1 ansi32">lit-path!      </span> datatype!  <span class="ansi32">literal path value</span>
  <span class="ansi1 ansi32">hash!          </span> datatype!  <span class="ansi32">series of values (using hash table)</span>
  <span class="ansi1 ansi32">map!           </span> datatype!  <span class="ansi32">name-value pairs (hash associative)</span>
  <span class="ansi1 ansi32">datatype!      </span> datatype!  <span class="ansi32">type of datatype</span>
  <span class="ansi1 ansi32">typeset!       </span> datatype!  <span class="ansi32">set of datatypes</span>
  <span class="ansi1 ansi32">word!          </span> datatype!  <span class="ansi32">word (symbol or variable)</span>
  <span class="ansi1 ansi32">set-word!      </span> datatype!  <span class="ansi32">definition of a word's value</span>
  <span class="ansi1 ansi32">get-word!      </span> datatype!  <span class="ansi32">the value of a word (variable)</span>
  <span class="ansi1 ansi32">lit-word!      </span> datatype!  <span class="ansi32">literal word value</span>
  <span class="ansi1 ansi32">refinement!    </span> datatype!  <span class="ansi32">variation of meaning or location</span>
  <span class="ansi1 ansi32">issue!         </span> datatype!  <span class="ansi32">identifying marker word</span>
  <span class="ansi1 ansi32">native!        </span> datatype!  <span class="ansi32">direct CPU evaluated function</span>
  <span class="ansi1 ansi32">action!        </span> datatype!  <span class="ansi32">datatype native function (standard polymorphic)</span>
  <span class="ansi1 ansi32">rebcode!       </span> datatype!  <span class="ansi32">virtual machine function</span>
  <span class="ansi1 ansi32">command!       </span> datatype!  <span class="ansi32">special dispatch-based function</span>
  <span class="ansi1 ansi32">op!            </span> datatype!  <span class="ansi32">infix operator (special evaluation exception)</span>
  <span class="ansi1 ansi32">closure!       </span> datatype!  <span class="ansi32">function with persistent locals (indefinite extent)</span>
  <span class="ansi1 ansi32">function!      </span> datatype!  <span class="ansi32">interpreted function (user-defined or mezzanine)</span>
  <span class="ansi1 ansi32">frame!         </span> datatype!  <span class="ansi32">internal context frame</span>
  <span class="ansi1 ansi32">object!        </span> datatype!  <span class="ansi32">context of names with values</span>
  <span class="ansi1 ansi32">module!        </span> datatype!  <span class="ansi32">loadable context of code and data</span>
  <span class="ansi1 ansi32">error!         </span> datatype!  <span class="ansi32">errors and throws</span>
  <span class="ansi1 ansi32">task!          </span> datatype!  <span class="ansi32">evaluation environment</span>
  <span class="ansi1 ansi32">port!          </span> datatype!  <span class="ansi32">external series, an I/O channel</span>
  <span class="ansi1 ansi32">gob!           </span> datatype!  <span class="ansi32">graphical object</span>
  <span class="ansi1 ansi32">event!         </span> datatype!  <span class="ansi32">user interface event (efficiently sized)</span>
  <span class="ansi1 ansi32">handle!        </span> datatype!  <span class="ansi32">arbitrary internal object or value</span>
  <span class="ansi1 ansi32">struct!        </span> datatype!  <span class="ansi32">native structure definition</span>
  <span class="ansi1 ansi32">library!       </span> datatype!  <span class="ansi32">external library reference</span>
  <span class="ansi1 ansi32">utype!         </span> datatype!  <span class="ansi32">user defined datatype</span>

</code></pre></div><p>
For help on a specific datatype:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">>> help integer!</code></pre></div>
<div class="example-code"><pre class="text-block"><code><span class="ansi1 ansi32">INTEGER!</span> is a datatype.
It is defined as a 64 bit integer.
It is of the general type <span class="ansi1 ansi32">scalar</span>.

Found these related words:
  <span class="ansi1 ansi32">zero           </span> integer!   <span class="ansi32">0</span>

</code></pre></div><p>
To list all words that are function! datatypes, type:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; ? function!</code></pre></div><p>
and the result would be:
</p>
<div class="example-code"><pre class="text-block"><code class="text">Found these related words:
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
<h6>Help Search</h6><p>
The <a href="#help">help</a> function also finds words that contain a specified string. For example, to find all of the words that include the string <span class="datatype">path!</span>, type:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; ? "path"</code></pre></div><p>
and the result will be:
</p>
<div class="example-code"><pre class="text-block"><code class="text">Found these related words:
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
<h6>Help on Objects</h6><p>
If you use <a href="#help">help</a> on an object, it will list a summary of the object's fields.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">>> ? system</code></pre></div>
<div class="example-code"><pre class="text-block"><code><span class="ansi1 ansi32">SYSTEM</span> is an <span class="ansi1 ansi33">object</span> of value: <span class="ansi32">
  <span class="ansi1 ansi32">product        </span></span> word!      <span class="ansi32">Bulk</span>
  <span class="ansi1 ansi32">platform       </span> word!      <span class="ansi32">Windows</span>
  <span class="ansi1 ansi32">version        </span> tuple!     <span class="ansi32">3.20.0</span>
  <span class="ansi1 ansi32">build          </span> object!    <span class="ansi32">[os os-version abi sys arch libc vendor target compiler date git]</span>
  <span class="ansi1 ansi32">user           </span> object!    <span class="ansi32">[name data]</span>
  <span class="ansi1 ansi32">options        </span> object!    <span class="ansi32">[boot path home data modules flags script args do-arg import debug secure version...</span>
  <span class="ansi1 ansi32">catalog        </span> object!    <span class="ansi32">[datatypes actions natives handles errors reflectors boot-flags bitsets structs c...</span>
  <span class="ansi1 ansi32">contexts       </span> object!    <span class="ansi32">[root sys lib user]</span>
  <span class="ansi1 ansi32">state          </span> object!    <span class="ansi32">[note last-error last-result wait-list cookies]</span>
  <span class="ansi1 ansi32">modules        </span> object!    <span class="ansi32">[help blend2d blurhash easing mathpresso miniaudio speak sqlite triangulate webp ...</span>
  <span class="ansi1 ansi32">codecs         </span> object!    <span class="ansi32">[text markup qoi pkix der crt ppk ssh-key safe utc-time unixtime ar gzip zip tar ...</span>
  <span class="ansi1 ansi32">dialects       </span> object!    <span class="ansi32">[secure draw effect text rebcode]</span>
  <span class="ansi1 ansi32">schemes        </span> object!    <span class="ansi32">[system console callback file dir event dns tcp udp checksum crypt clipboard seri...</span>
  <span class="ansi1 ansi32">ports          </span> object!    <span class="ansi32">[system event input output echo mail callback]</span>
  <span class="ansi1 ansi32">locale         </span> object!    <span class="ansi32">[language language* locale locale* months days]</span>
  <span class="ansi1 ansi32">script         </span> object!    <span class="ansi32">[title header parent path args]</span>
  <span class="ansi1 ansi32">standard       </span> object!    <span class="ansi32">[codec enum error script header scheme port port-spec-head port-spec-file port-sp...</span>
  <span class="ansi1 ansi32">view           </span> object!    <span class="ansi32">[screen-gob handler metrics]</span>
  <span class="ansi1 ansi32">license        </span> string!    <span class="ansi32">{^[[0m╔════════════════════════...</span>

</code></pre></div>
<h6>Help on Errors</h6><p>
There is a special mechanism for getting help on errors.
</p>
<p>
When you get an error message at the console, you can type <a href="#why?">why?</a> to see info about that specific error.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; test
** Script error: test has no value

&gt;&gt; why?
Opening web browser...</code></pre></div><p>
and, this page, <a href="https://www.rebol.com/r3/docs/errors/script-no-value.html">no-value</a>, would be displayed.
</p>
<p>
See <a href="#why?">why?</a> for more about this function.
</p>

<div class="see-also">See also: <a href="#?">?</a>, <a href="#??">??</a>, <a href="#docs">docs</a>, <a href="#what">what</a></div>
</section>

<hr>
<section id="hsv-to-rgb">
 <a name="hsv-to-rgb"></a>
 <h2>HSV-TO-RGB<a class="headerlink" href="#hsv-to-rgb" title="Link to this heading">¶</a></h2>
<p>Converts HSV (hue, saturation, value) to RGB</p>

<h6>Usage:</h6>
<pre class="usage fs-6">hsv-to-rgb <span class="rebarg">hsv</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  hsv         [<span class="types">tuple!</span>] 
</pre>
</section>

<hr>
<section id="iconv">
 <a name="iconv"></a>
 <h2>ICONV<a class="headerlink" href="#iconv" title="Link to this heading">¶</a></h2>
<p>Convert binary to text using specified codepage, or transcode to a new binary</p>

<h6>Usage:</h6>
<pre class="usage fs-6">iconv <span class="rebarg">data</span> <span class="rebarg">codepage</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">binary!</span>] 
  codepage    [<span class="types">word! integer! tag! string!</span>] Source codepage id
<span class="tit">REFINEMENTS:</span>
  /to         Transcode to a new binary
   target     [<span class="types">word! integer! tag! string!</span>] Target codepage id
</pre>
</section>

<hr>
<section id="if">
 <a name="if"></a>
 <h2>IF<a class="headerlink" href="#if" title="Link to this heading">¶</a></h2>
<p>If TRUE condition, return arg; evaluate blocks by default.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">if <span class="rebarg">condition</span> <span class="rebarg">true-branch</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  condition   [<span class="types">any-type!</span>] 
  true-branch  
<span class="tit">REFINEMENTS:</span>
  /only       Return block arg instead of evaluating it.
</pre>

<h6>Description:</h6>
<p>
The <a href="#if">if</a> function will evaluate the block when its first argument is true.
</p>
<p>
True is defined to be any value that is not false or none.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if 2 &gt; 1 [print "that's true"]
that's true</code></pre></div><p>
The condition can be the result of several expressions within <a href="#any">any</a> or <a href="#and">and</a>, or any other function that produces a result:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if all [
    time &gt; 10:20
    age &gt; 20
    find users "bob"
] [print "that's true"]
that's true</code></pre></div><p>
In addition, it can be pointed out that the block can be in a variable also:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">blk: [print "that's true"]
if 2 &gt; 1 blk
that's true</code></pre></div>
<h6>Return Value</h6><p>
When the condition is true, the <a href="#if">if</a> function returns the value that is the result of evaluating the block. Otherwise, it returns none. This is a useful feature.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print if 2 &gt; 1 [1 + 2]
3

print if 1 &gt; 2 [1 + 2]
none

names: ["Carl" "Brian" "Steve"]
print if find names "Carl" ["Person found"]
Person found</code></pre></div>
<h6>Where's the Else?</h6><p>
Unlike most other languages, REBOL uses functions, not commands to evaluate all expressions. Therefore, it's not desirable to use the word else if you need that behavior. Instead, use the <a href="#either">either</a> function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">either 2 &gt; 1 [print "greater"] [print "not greater"]
greater

either 1 &gt; 2 [print "greater"] [print "not greater"]
not greater</code></pre></div>
<h6>Simplification</h6><p>
The above example is pretty common, but it should be noted that it can be easily refactored:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">either 2 &gt; 1 [print "greater"] [print "not greater"]</code></pre></div><p>
is better written as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print either 2 &gt; 1 ["greater"] ["not greater"]</code></pre></div><p>
or even better written as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print pick ["greater" "not greater"] 2 &gt; 1</code></pre></div><p>
The importance of this is that you're picking from a choice of two strings, and you're doing it here with one less block than the code above it.
</p>
<p>
Be careful with this last method. The <a href="#pick">pick</a> function only allows true and false, not none. See <a href="#either">either</a> for more details.
</p>
<p>
In addition, it should be noted that the <a href="#any">any</a> function used earlier didn't really require the <a href="#if">if</a> at all. It could have been written as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">all [
    time &gt; 10:20
    age &gt; 20
    find users "bob"
    print "that's true"
]</code></pre></div>
<h6>A Common Error</h6><p>
A common error is to use <a href="#if">if</a> and add an "else" block without using the <a href="#either">either</a> function. The extra block gets ignored:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">n: 0
if 1 &gt; 2 [n: 1] [n: 2]
print n
0</code></pre></div><p>
The second block is ignored in this case and not evaluated.
</p>
<p>
The code should have used the <a href="#either">either</a> function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">n: 0
either 1 &gt; 2 [n: 1] [n: 2]
print n
2</code></pre></div>
<h6>The /Else refinement is obsolete</h6><p>
The /Else refinement is obsolete and will be removed in future versions. Avoid it.
</p>

<div class="see-also">See also: <a href="#all">all</a>, <a href="#any">any</a>, <a href="#either">either</a>, <a href="#select">select</a>, <a href="#switch">switch</a>, <a href="#unless">unless</a></div>
</section>

<hr>
<section id="image">
 <a name="image"></a>
 <h2>IMAGE<a class="headerlink" href="#image" title="Link to this heading">¶</a></h2>
<p>Interface to basic image encoding/decoding (only on Windows and macOS so far!)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">image</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /load       Image file to load or binary to decode
   src-file   [<span class="types">file! binary!</span>] 
  /save       Encodes image to file or binary
   dst-file   [<span class="types">none! file! binary!</span>] If NONE is used, binary is made internally
   dst-image  [<span class="types">none! image!</span>] If NONE, loaded image may be used if there is any
  /frame      Some image formats may contain multiple images
   num        [<span class="types">integer!</span>] 1-based index of the image to receive
  /as         Used to define which codec should be used
   type       [<span class="types">word!</span>] One of: [PNG JPEG JPEGXR BMP DDS GIF TIFF] read only: [DNG ICO HEIF]
</pre>
</section>

<hr>
<section id="image-diff">
 <a name="image-diff"></a>
 <h2>IMAGE-DIFF<a class="headerlink" href="#image-diff" title="Link to this heading">¶</a></h2>
<p>Count difference (using weighted RGB distance) of two images of the same size. Returns 0% if images are same and 100% if completely different.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">image-diff <span class="rebarg">a</span> <span class="rebarg">b</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  a           [<span class="types">image!</span>] If sizes of the input images are not same...
  b           [<span class="types">image!</span>] ... then only the smaller part is compared!
<span class="tit">REFINEMENTS:</span>
  /part       Limit computation only to a part of the image
   offset     [<span class="types">pair!</span>] Zero based top-left corner
   size       [<span class="types">pair!</span>] Size of the sub-image to use
</pre>
</section>

<hr>
<section id="image?">
 <a name="image?"></a>
 <h2>IMAGE?<a class="headerlink" href="#image?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">image? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns true if the value is an <span class="datatype">image!</span> datatype.
</p>
<p>
This function is often used after the <a href="#load">load</a> function to verify that the data is in fact an image. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">img: load %test-image.png
if not image? img [alert "Not an image file!"]</code></pre></div>
<div class="see-also">See also: <a href="#to-image">to-image</a></div>
</section>

<hr>
<section id="import">
 <a name="import"></a>
 <h2>IMPORT<a class="headerlink" href="#import" title="Link to this heading">¶</a></h2>
<p>Imports a module; locate, load, make, and setup its bindings.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">import <span class="rebarg">module</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  module      [<span class="types">any-word! file! url! string! binary! module! block!</span>] 
<span class="tit">REFINEMENTS:</span>
  /version    
   ver        [<span class="types">tuple!</span>] Module must be this version or greater
  /check      
   sum        [<span class="types">binary!</span>] Match checksum (must be set in header)
  /no-share   Force module to use its own non-shared global namespace
  /no-lib     Don't export to the runtime library (lib)
  /no-user    Don't export to the user context
</pre>

<h6>Description:</h6>
<p>
The <a href="#import">import</a> function is used to import modules into your runtime environment. For a full description see the <a href="https://www.rebol.com/r3/docs/concepts/modules-loading.html">modules: loading modules</a> section of this documentation.
</p>
<p>
For example, you can write:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">import 'mysql</code></pre></div><p>
and the system will search for the mysql module.
</p>
<p>
You can also use a filename or URL for the module identifier:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">import %mysql.r

import http://www.rebol.com/mods/mysql.r</code></pre></div>
<h7>Return value</h7><p>
When successful, the <a href="#import">import</a> function returns a <span class="datatype">module!</span> datatype as its result.
</p>
<p>
This allows you to write:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">mysql: import 'mysql</code></pre></div><p>
Now, the mysql variable can be used to refer to values within the mysql module.
</p>
<p>
For example the module value is used here to reference a function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">mysql/open-db %my-database.sql</code></pre></div><p>
See below for more.
</p>

<h7>Useful refinements</h7><p>
Like the header needs field, the <a href="#import">import</a> function also lets you specify a version and a checksum.
</p>
<p>
These are all supported:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">import/version mysql 1.2.3

import/check mysql #{A94A8FE5CCB19BA61C4C0873D391E987982FBBD3}

import/version/check mysql 1.2.3 #{A94A8FE5CCB19BA61C4C0873D391E987982FBBD3}</code></pre></div>
<h7>When to use IMPORT</h7><p>
The benefit of using the <a href="#import">import</a> function compared to the needs header field is that the arguments can be variables.
</p>
<p>
A basic example is:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">mod: 'mysql
import mod</code></pre></div><p>
Or, something like:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">mod-list: [
    mysql 1.2.3
    db-gui 2.4.5
    http-server 1.0.1
]

foreach [id ver] mod-list [
    import/version id ver
]</code></pre></div>
<div class="see-also">See also: <a href="#do">do</a>, <a href="#load">load</a></div>
</section>

<hr>
<section id="in">
 <a name="in"></a>
 <h2>IN<a class="headerlink" href="#in" title="Link to this heading">¶</a></h2>
<p>Returns the word or block in the object's context.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">in <span class="rebarg">object</span> <span class="rebarg">word</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  object      [<span class="types">any-object! block!</span>] 
  word        [<span class="types">any-word! block! paren!</span>] (modified if series)
</pre>

<h6>Description:</h6>
<p>
Return the word from within another context. This function is normally used with <a href="#set">set</a> and <a href="#get">get</a>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">set-console: func ['word value] [
    set in system/console word value
]
set-console prompt "==&gt;"
set-console result "--&gt;"</code></pre></div><p>
This is a useful function for accessing the words and values of an object. The <a href="#in">in</a> function will obtain a word from an object's context. For example, if you create an object:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">example: make object! [ name: "fred" age: 24 ]</code></pre></div><p>
You can access the object's name and age fields with:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print example/name
print example/age
24</code></pre></div><p>
But you can also access them with:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print get in example 'name
print get in example 'age
24</code></pre></div><p>
The <a href="#in">in</a> function returns the name and age words as they are within the example object. If you type:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print in example 'name
name</code></pre></div><p>
The result will be the word name, but with a value as it exists in the example object. The <a href="#get">get</a> function then fetches their values.  This is the best way to obtain a value from an object, regardless of its datatype (such as in the case of a function).
</p>
<p>
A <a href="#set">set</a> can also be used:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print set in example 'name "Bob"
Bob</code></pre></div><p>
Using <a href="#in">in</a>, here is a way to print the values of all the fields of an object:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">foreach word words-of example [
    probe get in example word
]
24</code></pre></div><p>
Here is another example that sets all the values of an object to none:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">foreach word words-of example [
    set in example word none
]</code></pre></div><p>
The <a href="#in">in</a> function can also be used to quickly check for the existence of a word within an object:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if in example 'name [print example/name]
none

if in example 'address [print example/address]</code></pre></div><p>
This is useful for objects that have optional variables.
</p>

<h6>Advanced binding uses</h6><p>
In R3, <a href="#in">in</a> can also be used for binding a block to an object to support this useful idiom:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">do in example [age + 1]
25</code></pre></div><p>
Identically, a <span class="datatype">paren!</span> can be used as the rebound block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">do in example second [(age + 1) (age + 20)]
44</code></pre></div>
<div class="see-also">See also: <a href="#get">get</a>, <a href="#set">set</a></div>
</section>

<hr>
<section id="in-dir">
 <a name="in-dir"></a>
 <h2>IN-DIR<a class="headerlink" href="#in-dir" title="Link to this heading">¶</a></h2>
<p>Evaluate a block while in a directory.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">in-dir <span class="rebarg">dir</span> <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  dir         [<span class="types">file!</span>] Directory to change to (changed back after)
  block       [<span class="types">block!</span>] Block to evaluate
</pre>

<h6>Description:</h6>
<p>
This is useful if you need to temporarily switch to a different directory to do something, and then switch back without manually doing so.
</p>
<p>
Example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">in-dir %tmp-dir/ [tmp-files: read %.]</code></pre></div>
</section>

<hr>
<section id="index?">
 <a name="index?"></a>
 <h2>INDEX?<a class="headerlink" href="#index?" title="Link to this heading">¶</a></h2>
<p>Returns the current position (index) of the series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">index? <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port! none!</span>] 
<span class="tit">REFINEMENTS:</span>
  /xy         Returns index as an XY pair offset
</pre>

<h6>Description:</h6>
<p>
The index function returns the position within a series. For
example, the first value in a series is an index of one, the
second is an index of two, etc.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "with all things considered"
print index? str
1

print index? find str "things"
10

blk: [264 "Rebol Dr." "Calpella" CA 95418]
print index? find blk 95418
5</code></pre></div><p>
Use the OFFSET? function when you need the index difference
between two positions in a series.
</p>

<div class="see-also">See also: <a href="#head">head</a>, <a href="#head?">head?</a>, <a href="#length?">length?</a>, <a href="#offset?">offset?</a>, <a href="#pick">pick</a>, <a href="#skip">skip</a>, <a href="#tail">tail</a>, <a href="#tail?">tail?</a></div>
</section>

<hr>
<section id="indexz?">
 <a name="indexz?"></a>
 <h2>INDEXZ?<a class="headerlink" href="#indexz?" title="Link to this heading">¶</a></h2>
<p>Returns the current 0-based position (index) of the series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">indexz? <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port! none!</span>] 
<span class="tit">REFINEMENTS:</span>
  /xy         Returns index as an XY pair offset
</pre>
</section>

<hr>
<section id="init-words">
 <a name="init-words"></a>
 <h2>INIT-WORDS<a class="headerlink" href="#init-words" title="Link to this heading">¶</a></h2>
<p></p>

<h6>Usage:</h6>
<pre class="usage fs-6">init-words <span class="rebarg">words</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  words       [<span class="types">block!</span>] 
</pre>
</section>

<hr>
<section id="input">
 <a name="input"></a>
 <h2>INPUT<a class="headerlink" href="#input" title="Link to this heading">¶</a></h2>
<p>Inputs a string from the console.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">input</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /hide       Turns off echoing inputs
</pre>

<h6>Description:</h6>
<p>
Returns a string from the standard input device
(normally the keyboard, but can also be a file or an
interactive shell). The string does not include
the new-line character used to terminate it.
</p>
<p>
The /HIDE refinement hides input with "*" characters.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">prin "Enter a name: "
name: input
print [name "is" length? name "characters long"]
Luke is 4 characters long</code></pre></div>
<div class="see-also">See also: <a href="#ask">ask</a>, <a href="#confirm">confirm</a></div>
</section>

<hr>
<section id="insert">
 <a name="insert"></a>
 <h2>INSERT<a class="headerlink" href="#insert" title="Link to this heading">¶</a></h2>
<p>Inserts element(s); for series, returns just past the insert.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">insert <span class="rebarg">series</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! port! map! gob! object! bitset!</span>] At position (modified)
  value       [<span class="types">any-type!</span>] The value to insert
<span class="tit">REFINEMENTS:</span>
  /part       Limits to a given length or position
   range      [<span class="types">number! series! pair!</span>] 
  /only       Only insert a block as a single value (not the contents of the block)
  /dup        Duplicates the insert a specified number of times
   count      [<span class="types">number! pair!</span>] 
</pre>

<h6>Description:</h6>
<p>
If the value is a series compatible with the first
(block or string-based datatype), then all of its values
will be inserted. The series position just past the
insert is returned, allowing multiple inserts to be
cascaded together.
</p>

<h7>Refinements</h7><p>
/part allows you to specify how many elements you want
to insert.
</p>
<p>
/only will force a block to be insert, rather than its
individual elements. (Is only done if first argument
is a block datatype.)
</p>
<p>
/dup will cause the inserted series to be repeated a
given number of times. (Positive integer or zero)
</p>
<p>
The series will be modified.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: copy "here this"
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
[[separate block] print "hello" http://www.rebol.com]</code></pre></div>
<div class="see-also">See also: <a href="#append">append</a>, <a href="#change">change</a>, <a href="#clear">clear</a>, <a href="#join">join</a>, <a href="#remove">remove</a></div>
</section>

<hr>
<section id="integer?">
 <a name="integer?"></a>
 <h2>INTEGER?<a class="headerlink" href="#integer?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">integer? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print integer? -1234
true

print integer? "string"
false</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="intern">
 <a name="intern"></a>
 <h2>INTERN<a class="headerlink" href="#intern" title="Link to this heading">¶</a></h2>
<p>Imports (internalize) words and their values from the lib into the user context.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">intern <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">block! any-word!</span>] Word or block of words to be added (deeply)
</pre>
</section>

<hr>
<section id="intersect">
 <a name="intersect"></a>
 <h2>INTERSECT<a class="headerlink" href="#intersect" title="Link to this heading">¶</a></h2>
<p>Returns the intersection of two data sets.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">intersect <span class="rebarg">set1</span> <span class="rebarg">set2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  set1        [<span class="types">block! string! bitset! typeset! map!</span>] first set
  set2        [<span class="types">block! string! bitset! typeset! map!</span>] second set
<span class="tit">REFINEMENTS:</span>
  /case       Uses case-sensitive comparison
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns all elements within two blocks or series that 
exist in both.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">lunch: [ham cheese bread carrot]
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
"abc"</code></pre></div><p>
To obtain a unique set (to remove duplicate values)
you can use UNIQUE.
</p>
<p>
Note that performing this function over very large
data sets can be CPU intensive.
</p>

<div class="see-also">See also: <a href="#difference">difference</a>, <a href="#exclude">exclude</a>, <a href="#union">union</a>, <a href="#unique">unique</a></div>
</section>

<hr>
<section id="invalid-utf?">
 <a name="invalid-utf?"></a>
 <h2>INVALID-UTF?<a class="headerlink" href="#invalid-utf?" title="Link to this heading">¶</a></h2>
<p>Checks UTF encoding; if correct, returns none else position of error.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">invalid-utf? <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">binary!</span>] 
<span class="tit">REFINEMENTS:</span>
  /utf        Check encodings other than UTF-8
   num        [<span class="types">integer!</span>] Bit size - positive for BE negative for LE
</pre>
</section>

<hr>
<section id="issue?">
 <a name="issue?"></a>
 <h2>ISSUE?<a class="headerlink" href="#issue?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">issue? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print issue? #1234-5678-9012
true

print issue? #467-8000
true

print issue? $12.56
false</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="join">
 <a name="join"></a>
 <h2>JOIN<a class="headerlink" href="#join" title="Link to this heading">¶</a></h2>
<p>Concatenates values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">join <span class="rebarg">value</span> <span class="rebarg">rest</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        Base value
  rest         Value or block of values
</pre>

<h6>Description:</h6>
<p>
Returns a new <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a> that joins together a value with another value or block of values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">join "super" "duper"
"superduper"

join %file ".txt"
%file.txt</code></pre></div><p>
This differs from <a href="#append">append</a> and <a href="#repend">repend</a> because a new value is created, and the first argument is not modified in any way.
</p>
<p>
The <b>first argument determines the datatype of the returned value</b>.
When the first argument is a type of <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a>, the return value will 
be that type of series (d:string, <span class="datatype">file!</span>, <span class="datatype">url!</span>, <span class="datatype">block!</span>, etc.)
</p>
<p>
When the first argument is a scalar value (such as <span class="datatype">integer!</span>, <span class="datatype">date!</span>, <span class="datatype">time!</span>, and others), the return  will always be a <span class="datatype">string!</span>.
</p>
<p>
When the second argument is a <span class="datatype">block!</span>, it will be evaluated and all of its values joined 
to the return value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">join http:// ["www.rebol.com/" %index.html]
http://www.rebol.com/index.html

join "t" ["e" "s" "t"]
"test"

join 11:11 "PM"
"11:11PM"</code></pre></div><p>
Note that it also works for <span class="datatype">block!</span> series, but returns a block, not a string:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">join [1] ["two" 3 "four"]
[1 "two" 3 "four"]</code></pre></div><p>
And, this case is important to note:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">join &lt;a&gt; "test"
&lt;atest&gt;</code></pre></div><p>
(See <a href="#rejoin">rejoin</a> for more detail on this case.)
</p>
<p>
If you want the result here to be a <span class="datatype">string!</span>, use the <a href="#ajoin">ajoin</a> function instead.
</p>

<div class="see-also">See also: <a href="#ajoin">ajoin</a>, <a href="#append">append</a>, <a href="#form">form</a>, <a href="#mold">mold</a>, <a href="#reform">reform</a>, <a href="#rejoin">rejoin</a>, <a href="#remold">remold</a>, <a href="#repend">repend</a></div>
</section>

<hr>
<section id="keys-of">
 <a name="keys-of"></a>
 <h2>KEYS-OF<a class="headerlink" href="#keys-of" title="Link to this heading">¶</a></h2>
<p>Returns a copy of the words of any function, any object, map, date, handle or struct</p>

<h6>Usage:</h6>
<pre class="usage fs-6">keys-of <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-function! any-object! map! date! handle! struct!</span>] 
</pre>
</section>

<hr>
<section id="last">
 <a name="last"></a>
 <h2>LAST<a class="headerlink" href="#last" title="Link to this heading">¶</a></h2>
<p>Returns the last value of a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">last <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">series! tuple! gob!</span>] 
</pre>

<h6>Description:</h6>
<p>
LAST returns the last value of a series. If the series is empty,
LAST will cause an error.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print last "abcde"
e

print last [1 2 3 4 5]
5

print last %file
e

probe last 'system/options
options</code></pre></div><p>
If you do not want an error when the series is empty, use the 
PICK function instead:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">string: ""
print pick back tail string 1
none</code></pre></div>
</section>

<hr>
<section id="last?">
 <a name="last?"></a>
 <h2>LAST?<a class="headerlink" href="#last?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the series length is 1.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">last? <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! port! map! tuple! bitset! object! gob! any-word!</span>] 
</pre>
</section>

<hr>
<section id="latin1?">
 <a name="latin1?"></a>
 <h2>LATIN1?<a class="headerlink" href="#latin1?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if value or string is in Latin-1 character range (below 256).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">latin1? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-string! char! integer!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; latin1? "mýdlo"
== #(true) ;; because (to integer! #"ý") == 253

&gt;&gt; latin1? "česko"
== #(false) ;; because (to integer! #"č") == 269</code></pre></div>
<div class="see-also">See also: <a href="#ascii?">ascii?</a>, <a href="#utf8?">utf8?</a></div>
</section>

<hr>
<section id="launch">
 <a name="launch"></a>
 <h2>LAUNCH<a class="headerlink" href="#launch" title="Link to this heading">¶</a></h2>
<p>Runs a script as a separate process; return immediately.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">launch <span class="rebarg">script</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  script      [<span class="types">file! string!</span>] The name of the script
<span class="tit">REFINEMENTS:</span>
  /with       
   args       [<span class="types">string! block! none!</span>] Arguments to the script
  /wait       Wait for the process to terminate
</pre>

<h6>Description:</h6>
<p>
The LAUNCH function is used to run REBOL scripts as a separate
process. When LAUNCH is called, a new process is created and
passed the script file name or URL to be processed. The process
is created as a subprocess of the main REBOL process.
</p>
<p>
Launch has certain restrictions depending on the REBOL system
used. Also, within Unix/Linux systems, launch will use the
same shell standard files as the main REBOL process, and output
will be merged.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">launch %calculator.r

launch http://www.rebol.com/scripts/news.r</code></pre></div>
<div class="see-also">See also: <a href="#call">call</a>, <a href="#do">do</a></div>
</section>

<hr>
<section id="lcm">
 <a name="lcm"></a>
 <h2>LCM<a class="headerlink" href="#lcm" title="Link to this heading">¶</a></h2>
<p>Returns the least common multiple</p>

<h6>Usage:</h6>
<pre class="usage fs-6">lcm <span class="rebarg">a</span> <span class="rebarg">b</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  a           [<span class="types">integer!</span>] 
  b           [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="length?">
 <a name="length?"></a>
 <h2>LENGTH?<a class="headerlink" href="#length?" title="Link to this heading">¶</a></h2>
<p>Returns the length (from the current position for series.)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">length? <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! port! map! tuple! bitset! object! gob! struct! any-word! none!</span>] 
</pre>

<h6>Description:</h6>
<p>
The length? function returns the number of values from the current position of a series to the tail of the series.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print length? "REBOL"
5</code></pre></div><p>
but, in the case of an offset position from <a href="#skip">skip</a> :
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print length? skip "REBOL" 2
3</code></pre></div><p>
or from <a href="#find">find</a> :
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print length? find "REBOL" "L"
1</code></pre></div><p>
Other examples:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print length? [1 2 3 4 5]
5

print length? [1 2 3 [4 5]]
4

print length? read http://www.rebol.com
7216

obj: object [a: 10 b: 20]
print length? obj
2</code></pre></div>
<div class="see-also">See also: <a href="#head">head</a>, <a href="#offset?">offset?</a>, <a href="#tail?">tail?</a></div>
</section>

<hr>
<section id="lesser-or-equal?">
 <a name="lesser-or-equal?"></a>
 <h2>LESSER-OR-EQUAL?<a class="headerlink" href="#lesser-or-equal?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the first value is less than or equal to the second value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">lesser-or-equal? <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1       
  value2       
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values. For string-based
datatypes, the sorting order is used for comparison
with character casing ignored (uppercase = lowercase).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print lesser-or-equal? "abc" "abd"
true

print lesser-or-equal? 10-June-1999 12-june-1999
true

print lesser-or-equal? 4.3.2.1 1.2.3.4
false

print lesser-or-equal? 1:23 10:00
true</code></pre></div>
<div class="see-also">See also: <a href="#<">&lt;</a>, <a href="#<=">&lt;=</a>, <a href="#<>">&lt;&gt;</a>, <a href="#=">=</a>, <a href="#>">&gt;</a>, <a href="#>=">&gt;=</a>, <a href="#max">max</a>, <a href="#min">min</a></div>
</section>

<hr>
<section id="lesser?">
 <a name="lesser?"></a>
 <h2>LESSER?<a class="headerlink" href="#lesser?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the first value is less than the second value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">lesser? <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1       
  value2       
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values. The values must be
of the same datatype, or an error will occur. For
string-based datatypes, the sorting order is used for
comparison with character casing ignored (uppercase =
lowercase).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print lesser? "abc" "abcd"
true

print lesser? 12-june-1999 10-june-1999
false

print lesser? 1.2.3.4 4.3.2.1
true

print lesser? 1:30 2:00
true</code></pre></div>
<div class="see-also">See also: <a href="#<=">&lt;=</a>, <a href="#<>">&lt;&gt;</a>, <a href="#=">=</a>, <a href="#>">&gt;</a>, <a href="#>=">&gt;=</a>, <a href="#max">max</a>, <a href="#min">min</a></div>
</section>

<hr>
<section id="library?">
 <a name="library?"></a>
 <h2>LIBRARY?<a class="headerlink" href="#library?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">library? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns TRUE if the value is a LIBRARY datatype.
</p>

</section>

<hr>
<section id="license">
 <a name="license"></a>
 <h2>LICENSE<a class="headerlink" href="#license" title="Link to this heading">¶</a></h2>
<p>Prints the REBOL/core license agreement</p>

<h6>Usage:</h6>
<pre class="usage fs-6">license</span></pre>

<h6>Description:</h6>
<p>
Returns the REBOL end user license agreement for the currently
running version of REBOL.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">>> license</code></pre></div>
<div class="example-code"><pre class="text-block"><code>╔══════════════════════════════════════════════════════════════════════════╗
║<span class="ansi30 ansi107">                                                                          </span>║
║<span class="ansi30 ansi107">    <span class="ansi32">Copyright  <span class="ansi31">2012 REBOL Technologies                                    <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">    <span class="ansi32">           <span class="ansi31">2012-2025 Rebol Open Source Contributors                   <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">    <span class="ansi32">           <span class="ansi31">Licensed under the Apache License, Version 2.0.            <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">    <span class="ansi32">           <span class="ansi31">https://www.apache.org/licenses/LICENSE-2.0                <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">                                                                          </span>║
║<span class="ansi30 ansi107">    <span class="ansi32">Notice     <span class="ansi31">https://github.com/Oldes/Rebol3/blob/master/NOTICE         <span class="ansi30"></span></span></span></span>║
║<span class="ansi30 ansi107">                                                                          </span>║
╚══════════════════════════════════════════════════════════════════════════╝

</code></pre></div><p>
For SDK and other specially licensed versions of REBOL, the
license function may return an empty string.
</p>

<div class="see-also">See also: <a href="#about">about</a></div>
</section>

<hr>
<section id="limit-usage">
 <a name="limit-usage"></a>
 <h2>LIMIT-USAGE<a class="headerlink" href="#limit-usage" title="Link to this heading">¶</a></h2>
<p>Set a usage limit only once (used for SECURE).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">limit-usage <span class="rebarg">field</span> <span class="rebarg">limit</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  field       [<span class="types">word!</span>] eval (count) or memory (bytes)
  limit       [<span class="types">number!</span>] 
</pre>
</section>

<hr>
<section id="list-dir">
 <a name="list-dir"></a>
 <h2>LIST-DIR<a class="headerlink" href="#list-dir" title="Link to this heading">¶</a></h2>
<p>Print contents of a directory (ls).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">list-dir <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file! word! path! string! unset!</span>] Accepts %file, :variables, and just words (as dirs)
<span class="tit">REFINEMENTS:</span>
  /f          Files only
  /d          Dirs only
  /r          Recursive
  /i          
   indent     [<span class="types">string! char!</span>] 
  /l          Limit recursive output to given maximal depth
   max-depth  [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
Lists the files and directories of the specified path in a
sorted multi-column output. If no path is specified, the
directory specified in system/script/path is listed. Directory
names are followed by a slash (/) in the output listing.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">list-dir</code></pre></div><p>
To obtain a block of files for use by your program, use the LOAD
function. The example below returns a block that contains the names of all
files and directories in the local directory.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">files: load %./
print length? files
probe files
[%autos.txt %build-docs.r %bulk-modify.r %cgi.r %convert-orig.r %CVS/ %emit-html.r %eval-examples.r %fix-args.r %fred/ %funcs.r %helloworld.txt %merge-funcs.r %newfile.txt %notes.txt %public/ %replace.r %scan-doc.r %scan-titles.r %strip-title.r %test-file.txt %trash.me]</code></pre></div>
<div class="see-also">See also: <a href="#change-dir">change-dir</a>, <a href="#make-dir">make-dir</a>, <a href="#read">read</a>, <a href="#what-dir">what-dir</a></div>
</section>

<hr>
<section id="list-env">
 <a name="list-env"></a>
 <h2>LIST-ENV<a class="headerlink" href="#list-env" title="Link to this heading">¶</a></h2>
<p>Returns a map of OS environment variables (for current process).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">list-env</span></pre>

<h6>Description:</h6>
<p>
This function will return a <span class="datatype">map!</span> of OS environment variables and their values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; list-env
== #[
    "=::" "::\"
    "ALLUSERSPROFILE" "C:\ProgramData"
    "APPDATA" "C:\Users\oldes\AppData\Roaming"
   ...</code></pre></div>
<div class="see-also">See also: <a href="#get-env">get-env</a></div>
</section>

<hr>
<section id="lit-path?">
 <a name="lit-path?"></a>
 <h2>LIT-PATH?<a class="headerlink" href="#lit-path?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">lit-path? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns true if the value is a literal path datatype.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; lit-path? first ['some/path other/path]
== #(true)

&gt;&gt; lit-path? second ['some/path other/path]
== #(false)</code></pre></div>
</section>

<hr>
<section id="lit-word?">
 <a name="lit-word?"></a>
 <h2>LIT-WORD?<a class="headerlink" href="#lit-word?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">lit-word? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; lit-word? first ['foo bar]
== #(true)</code></pre></div>
<div class="see-also">See also: <a href="#get-word?">get-word?</a>, <a href="#set-word?">set-word?</a>, <a href="#word?">word?</a></div>
</section>

<hr>
<section id="load">
 <a name="load"></a>
 <h2>LOAD<a class="headerlink" href="#load" title="Link to this heading">¶</a></h2>
<p>Loads code or data from a file, URL, string, or binary.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">load <span class="rebarg">source</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  source      [<span class="types">file! url! string! binary! block!</span>] Source or block of sources
<span class="tit">REFINEMENTS:</span>
  /header     Result includes REBOL header object (preempts /all)
  /all        Load all values (does not evaluate REBOL header)
  /as         Override default file-type; use NONE to always load as code
   type       [<span class="types">word! none!</span>] E.g. text, markup, jpeg, unbound, etc.
</pre>

<h6>Description:</h6>
<p>
Reads and converts external data, including programs, data
structures, images, and sounds into memory storage objects that
can be directly accessed and manipulated by programs.
</p>
<p>
The argument to LOAD can be a file, URL, string, or binary
value. When a file name or URL is provided, the data is read
from disk or network first, then it is loaded. In the case of a
string or binary value, it is loaded directly from memory.
</p>
<p>
Here are a few examples of using LOAD:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">script: load %dict-notes.r
image: load %image.png
sound: load %whoosh.wav

;data: load http://www.rebol.com/example.r
;data: load ftp://ftp.rebol.com/example.r

data: load "1 2 luke fred@example.com"
code: load {loop 10 [print "hello"]}</code></pre></div><p>
LOAD is often called for a text file that contains REBOL code or
data that needs to be brought into memory. The text is first
searched for a REBOL header, and if a header is found, it is
evaluated first. (However, unlike the DO function, LOAD does not
require that there be a header.)
</p>
<p>
If the load results in a single value, it will be returned. If
it results in a block, the block will be returned. No evaluation
of the block will be done; however, words in the block will be
bound to the global context.
</p>
<p>
If the header object is desired, use the /HEADER option to
return it as the first element in the block.
</p>
<p>
The /ALL refinement is used to load an entire script as a block.
The header is not evaluated.
</p>
<p>
The /NEXT refinement was removed - use TRANSCODE/NEXT instead
</p>

<div class="see-also">See also: <a href="#bind">bind</a>, <a href="#do">do</a>, <a href="#import">import</a>, <a href="#read">read</a>, <a href="#save">save</a></div>
</section>

<hr>
<section id="load-extension">
 <a name="load-extension"></a>
 <h2>LOAD-EXTENSION<a class="headerlink" href="#load-extension" title="Link to this heading">¶</a></h2>
<p>Low level extension module loader (for DLLs).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">load-extension <span class="rebarg">name</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  name        [<span class="types">file! binary!</span>] DLL file or UTF-8 source
<span class="tit">REFINEMENTS:</span>
  /dispatch   Specify native command dispatch (from hosted extensions)
   function   [<span class="types">handle!</span>] Command dispatcher (native)
</pre>
</section>

<hr>
<section id="load-json">
 <a name="load-json"></a>
 <h2>LOAD-JSON<a class="headerlink" href="#load-json" title="Link to this heading">¶</a></h2>
<p>Convert a JSON string to Rebol data</p>

<h6>Usage:</h6>
<pre class="usage fs-6">load-json <span class="rebarg">input</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  input       [<span class="types">string!</span>] The JSON string
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; load-json to-json [1 2 3]
== [1 2 3]

&gt;&gt; load-json to-json #[a: 1 b: "test"]
== #[
    a: 1
    b: "test"
]</code></pre></div><p>
It is same like using <a href="#decode">decode</a>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; decode 'json {{"a":1,"b":"test"}}
== #[
    a: 1
    b: "test"
]</code></pre></div>
<div class="see-also">See also: <a href="#decode">decode</a>, <a href="#to-json">to-json</a></div>
</section>

<hr>
<section id="log-10">
 <a name="log-10"></a>
 <h2>LOG-10<a class="headerlink" href="#log-10" title="Link to this heading">¶</a></h2>
<p>Returns the base-10 logarithm.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">log-10 <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number!</span>] 
</pre>

<h6>Description:</h6>
<p>
The LOG-10 function returns the base-10 logarithm of the number
provided. The argument must be a positive value, otherwise an
error will occur (which can be trapped with the TRY function).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print log-10 100
2.0

print log-10 1000
3.0

print log-10 1234
3.091315159697223</code></pre></div>
<div class="see-also">See also: <a href="#exp">exp</a>, <a href="#log-2">log-2</a>, <a href="#log-e">log-e</a>, <a href="#power">power</a></div>
</section>

<hr>
<section id="log-2">
 <a name="log-2"></a>
 <h2>LOG-2<a class="headerlink" href="#log-2" title="Link to this heading">¶</a></h2>
<p>Return the base-2 logarithm.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">log-2 <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number!</span>] 
</pre>

<h6>Description:</h6>
<p>
The LOG-10 function returns the base-2 logarithm of the number
provided. The argument must be a positive value, otherwise an
error will occur (which can be trapped with the TRY function).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print log-2 2
1.0

print log-2 4
2.0

print log-2 256
8.0

print log-2 1234
10.26912667914941</code></pre></div>
<div class="see-also">See also: <a href="#exp">exp</a>, <a href="#log-10">log-10</a>, <a href="#log-e">log-e</a>, <a href="#power">power</a></div>
</section>

<hr>
<section id="log-debug">
 <a name="log-debug"></a>
 <h2>LOG-DEBUG<a class="headerlink" href="#log-debug" title="Link to this heading">¶</a></h2>
<p>Outputs low-level debugging messages (visible for verbosity level 2 and higher)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">log-debug <span class="rebarg">id</span> <span class="rebarg">message</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  id          [<span class="types">any-word!</span>] 
  message      
</pre>
</section>

<hr>
<section id="log-e">
 <a name="log-e"></a>
 <h2>LOG-E<a class="headerlink" href="#log-e" title="Link to this heading">¶</a></h2>
<p>Returns the natural (base-E) logarithm of the given value</p>

<h6>Usage:</h6>
<pre class="usage fs-6">log-e <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number!</span>] 
</pre>

<h6>Description:</h6>
<p>
The LOG-E function returns the natural logarithm of the number
provided. The argument must be a positive value, otherwise an
error will occur (which can be trapped with the TRY function).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print log-e 1234
7.118016204465333

print exp log-e 1234
1234.0</code></pre></div>
<div class="see-also">See also: <a href="#exp">exp</a>, <a href="#log-10">log-10</a>, <a href="#log-2">log-2</a>, <a href="#power">power</a></div>
</section>

<hr>
<section id="log-error">
 <a name="log-error"></a>
 <h2>LOG-ERROR<a class="headerlink" href="#log-error" title="Link to this heading">¶</a></h2>
<p>Outputs critical issues and error messages (always visible)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">log-error <span class="rebarg">id</span> <span class="rebarg">message</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  id          [<span class="types">any-word!</span>] 
  message      
</pre>
</section>

<hr>
<section id="log-info">
 <a name="log-info"></a>
 <h2>LOG-INFO<a class="headerlink" href="#log-info" title="Link to this heading">¶</a></h2>
<p>Outputs general information messages (visible for verbosity level 1 and higher)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">log-info <span class="rebarg">id</span> <span class="rebarg">message</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  id          [<span class="types">any-word!</span>] 
  message      
</pre>
</section>

<hr>
<section id="log-trace">
 <a name="log-trace"></a>
 <h2>LOG-TRACE<a class="headerlink" href="#log-trace" title="Link to this heading">¶</a></h2>
<p>Outputs extremely granular debugging messages (visible for verbosity level 3 and higher)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">log-trace <span class="rebarg">id</span> <span class="rebarg">message</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  id          [<span class="types">any-word!</span>] 
  message      
</pre>
</section>

<hr>
<section id="log-warn">
 <a name="log-warn"></a>
 <h2>LOG-WARN<a class="headerlink" href="#log-warn" title="Link to this heading">¶</a></h2>
<p>Outputs potential problem messages (always visible unless the quiet option is set)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">log-warn <span class="rebarg">id</span> <span class="rebarg">message</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  id          [<span class="types">any-word!</span>] 
  message      
</pre>
</section>

<hr>
<section id="logic?">
 <a name="logic?"></a>
 <h2>LOGIC?<a class="headerlink" href="#logic?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">logic? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values. Note that all
conditional functions will accept more than just a LOGIC
value. A NONE will act as FALSE, and all other values
other than logic will act as TRUE.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print logic? true
true

print logic? 123
false</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="loop">
 <a name="loop"></a>
 <h2>LOOP<a class="headerlink" href="#loop" title="Link to this heading">¶</a></h2>
<p>Evaluates a block a specified number of times.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">loop <span class="rebarg">count</span> <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  count       [<span class="types">number!</span>] Number of repetitions
  block       [<span class="types">block!</span>] Block to evaluate
</pre>

<h6>Description:</h6>
<p>
The <a href="#loop">loop</a> function is the simplest way to repeat the evaluation of a block. This function is very efficient and should be used if no loop counter is required.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">loop 3 [print "hi"]
hi
hi
hi</code></pre></div><p>
Here's an example that creates a block of 10 random integers:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">block: make block! 10
loop 10 [append block random 100]
probe block
[31 25 53 20 40 2 30 79 47 79]</code></pre></div>
<h6>Returned Value</h6><p>
When finished the <a href="#loop">loop</a> function returns the final value the block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">num: 0
print loop 10 [num: num + 1]
10</code></pre></div>
<h6>Other Notes</h6><ul>
<li>Negative or zero loop counts do not evaluate the block.</li>
<li>If a <span class="datatype">decimal!</span> count is used, it will be truncated to a lower integer value.</li>
<li>The <a href="#break">break</a> function can be used to stop the loop at any time.</li>
<li>The <a href="#repeat">repeat</a> function is similar to <a href="#loop">loop</a>, except that it allows a variable to keep track of the current loop counter.</li>
</ul>
<div class="see-also">See also: <a href="#break">break</a>, <a href="#continue">continue</a>, <a href="#do">do</a>, <a href="#for">for</a>, <a href="#repeat">repeat</a>, <a href="#until">until</a>, <a href="#while">while</a></div>
</section>

<hr>
<section id="lowercase">
 <a name="lowercase"></a>
 <h2>LOWERCASE<a class="headerlink" href="#lowercase" title="Link to this heading">¶</a></h2>
<p>Converts string of characters to lowercase.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">lowercase <span class="rebarg">string</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  string      [<span class="types">any-string! char!</span>] (modified if series)
<span class="tit">REFINEMENTS:</span>
  /part       Limits to a given length or position
   length     [<span class="types">number! any-string!</span>] 
</pre>

<h6>Description:</h6>
<p>
The series passed to this function is modified as
a result.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; lowercase "ABCDEF"
== "abcdef"

&gt;&gt; lowercase/part "ABCDEF" 3
== "abcDEF"</code></pre></div>
<div class="see-also">See also: <a href="#trim">trim</a>, <a href="#uppercase">uppercase</a></div>
</section>

<hr>
<section id="ls">
 <a name="ls"></a>
 <h2>LS<a class="headerlink" href="#ls" title="Link to this heading">¶</a></h2>
<p>Note: Shell shortcut for <a href="#list-dir">list-dir</a>.</p>
</section>

<hr>
<section id="make">
 <a name="make"></a>
 <h2>MAKE<a class="headerlink" href="#make" title="Link to this heading">¶</a></h2>
<p>Constructs or allocates the specified datatype.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">make <span class="rebarg">type</span> <span class="rebarg">spec</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  type        [<span class="types">any-type!</span>] The datatype or an example value
  spec        [<span class="types">any-type!</span>] Attributes or size of the new value (modified)
</pre>

<h6>Description:</h6>
<p>
The TYPE argument indicates the datatype to create.
</p>
<p>
The form of the constructor is determined by the
datatype. For most series datatypes, a number indicates
the size of the initial allocation.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: make string! 1000

blk: make block! 10

cash: make money! 1234.56
print cash
$1234.560000000000000

time: make time! [10 30 40]
print time
10:30:40</code></pre></div><p>
NOTE: MAKE when used with OBJECTS will modify the context of the
spec block (as if BIND was used on it). If you need to reuse the
spec block use MAKE in combination with COPY/deep like this:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">make object! copy/deep spec</code></pre></div>
<div class="see-also">See also: <a href="#copy">copy</a>, <a href="#type?">type?</a></div>
</section>

<hr>
<section id="make-banner">
 <a name="make-banner"></a>
 <h2>MAKE-BANNER<a class="headerlink" href="#make-banner" title="Link to this heading">¶</a></h2>
<p>Build startup banner.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">make-banner <span class="rebarg">fmt</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  fmt          
</pre>
</section>

<hr>
<section id="make-dir">
 <a name="make-dir"></a>
 <h2>MAKE-DIR<a class="headerlink" href="#make-dir" title="Link to this heading">¶</a></h2>
<p>Creates the specified directory. No error if already exists.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">make-dir <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file! url!</span>] 
<span class="tit">REFINEMENTS:</span>
  /deep       Create subdirectories too
</pre>

<h6>Description:</h6>
<p>
Creates a new directory at the specified location. This
operation can be performed for files or FTP URLs.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">make-dir %New-Dir/
delete %New-Dir/</code></pre></div>
<div class="see-also">See also: <a href="#change-dir">change-dir</a>, <a href="#delete">delete</a>, <a href="#list-dir">list-dir</a>, <a href="#what-dir">what-dir</a></div>
</section>

<hr>
<section id="map">
 <a name="map"></a>
 <h2>MAP<a class="headerlink" href="#map" title="Link to this heading">¶</a></h2>
<p>Make a map value (hashed associative block).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">map <span class="rebarg">val</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  val          
</pre>

<h6>Description:</h6>
<p>
Description is needed.
</p>

</section>

<hr>
<section id="map-each">
 <a name="map-each"></a>
 <h2>MAP-EACH<a class="headerlink" href="#map-each" title="Link to this heading">¶</a></h2>
<p>Evaluates a block for each value(s) in a series and returns them as a block.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">map-each <span class="rebarg">word</span> <span class="rebarg">data</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word! block!</span>] Word or block of words to set each time (local)
  data        [<span class="types">block! vector!</span>] The series to traverse
  body        [<span class="types">block!</span>] Block to evaluate each time
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; map-each w [1 2 3][w * 100]
== [100 200 300]</code></pre></div>
</section>

<hr>
<section id="map-event">
 <a name="map-event"></a>
 <h2>MAP-EVENT<a class="headerlink" href="#map-event" title="Link to this heading">¶</a></h2>
<p>Returns event with inner-most graphical object and coordinate.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">map-event <span class="rebarg">event</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  event       [<span class="types">event!</span>] 
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="map-gob-offset">
 <a name="map-gob-offset"></a>
 <h2>MAP-GOB-OFFSET<a class="headerlink" href="#map-gob-offset" title="Link to this heading">¶</a></h2>
<p>Translates a gob and offset to the deepest gob and offset in it, returned as a block.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">map-gob-offset <span class="rebarg">gob</span> <span class="rebarg">xy</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  gob         [<span class="types">gob!</span>] Starting object
  xy          [<span class="types">pair!</span>] Staring offset
<span class="tit">REFINEMENTS:</span>
  /reverse    Translate from deeper gob to top gob.
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="map?">
 <a name="map?"></a>
 <h2>MAP?<a class="headerlink" href="#map?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">map? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; map? #[a: 1]
== #(true)

&gt;&gt; map? object [a: 1]
== #(false)</code></pre></div>
</section>

<hr>
<section id="max">
 <a name="max"></a>
 <h2>MAX<a class="headerlink" href="#max" title="Link to this heading">¶</a></h2>
<p>Returns the greater of the two values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">max <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! date! series!</span>] 
  value2      [<span class="types">scalar! date! series!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns the maximum of two values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print max 0 100
100

print max 0 -100
0

print max 4.56 4.2
4.56</code></pre></div><p>
The maximum value is computed by comparison, so MAX can also be
used for non-numeric datatypes as well.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print max 1.2.3 1.2.8
1.2.8

print max "abc" "abd"
abd

print max 12:00 11:00
12:00

print max 1-Jan-1920 20-Feb-1952
20-Feb-1952</code></pre></div><p>
Using MAX on xy pairs will return the maximum of each X and Y
coordinate separately.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print max 100x10 200x20
200x20</code></pre></div>
<div class="see-also">See also: <a href="#<">&lt;</a>, <a href="#>">&gt;</a>, <a href="#maximum">maximum</a>, <a href="#maximum-of">maximum-of</a>, <a href="#min">min</a></div>
</section>

<hr>
<section id="maximum">
 <a name="maximum"></a>
 <h2>MAXIMUM<a class="headerlink" href="#maximum" title="Link to this heading">¶</a></h2>
<p>Returns the greater of the two values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">maximum <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! date! series!</span>] 
  value2      [<span class="types">scalar! date! series!</span>] 
</pre>

<h6>Description:</h6>
<p>
See the MAX function for details.
</p>

<div class="see-also">See also: <a href="#<">&lt;</a>, <a href="#>">&gt;</a>, <a href="#max">max</a>, <a href="#min">min</a></div>
</section>

<hr>
<section id="min">
 <a name="min"></a>
 <h2>MIN<a class="headerlink" href="#min" title="Link to this heading">¶</a></h2>
<p>Returns the lesser of the two values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">min <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! date! series!</span>] 
  value2      [<span class="types">scalar! date! series!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns the minimum of two values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print min 0 100
0

print min 0 -100
-100

print min 4.56 4.2
4.2</code></pre></div><p>
The minimum value is computed by comparison, so MIN can also be
used for non-numeric datatypes as well.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print min 1.2.3 1.2.8
1.2.3

print min "abc" "abd"
abc

print min 12:00 11:00
11:00

print min 1-Jan-1920 20-Feb-1952
1-Jan-1920</code></pre></div><p>
Using min on xy pairs will return the minimum of each X and Y
coordinate separately.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print min 100x10 200x20
100x10</code></pre></div>
<div class="see-also">See also: <a href="#<">&lt;</a>, <a href="#>">&gt;</a>, <a href="#max">max</a>, <a href="#maximum-of">maximum-of</a>, <a href="#minimum-of">minimum-of</a></div>
</section>

<hr>
<section id="minimum">
 <a name="minimum"></a>
 <h2>MINIMUM<a class="headerlink" href="#minimum" title="Link to this heading">¶</a></h2>
<p>Returns the lesser of the two values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">minimum <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! date! series!</span>] 
  value2      [<span class="types">scalar! date! series!</span>] 
</pre>

<h6>Description:</h6>
<p>
See the MIN function for details.
</p>

<div class="see-also">See also: <a href="#<">&lt;</a>, <a href="#>">&gt;</a>, <a href="#max">max</a>, <a href="#min">min</a></div>
</section>

<hr>
<section id="mkdir">
 <a name="mkdir"></a>
 <h2>MKDIR<a class="headerlink" href="#mkdir" title="Link to this heading">¶</a></h2>
<p>Creates the specified directory. No error if already exists.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">mkdir <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file! url!</span>] 
<span class="tit">REFINEMENTS:</span>
  /deep       Create subdirectories too
</pre>

<h6>Description:</h6>
<p>
Note: Shell shortcut for <a href="#make-dir">make-dir</a>.
</p>

<div class="see-also">See also: <a href="#cd">cd</a>, <a href="#change-dir">change-dir</a>, <a href="#delete">delete</a>, <a href="#list-dir">list-dir</a>, <a href="#ls">ls</a>, <a href="#make-dir">make-dir</a>, <a href="#pwd">pwd</a>, <a href="#rm">rm</a>, <a href="#what-dir">what-dir</a></div>
</section>

<hr>
<section id="mod">
 <a name="mod"></a>
 <h2>MOD<a class="headerlink" href="#mod" title="Link to this heading">¶</a></h2>
<p>Compute a nonnegative remainder of A divided by B.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">mod <span class="rebarg">a</span> <span class="rebarg">b</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  a           [<span class="types">number! money! char! time!</span>] 
  b           [<span class="types">number! money! char! time!</span>] Must be nonzero.
</pre>

<h6>Description:</h6>
<p>
Similar to REMAINDER, but the result is always non-negative.
</p>

<div class="see-also">See also: <a href="#//">//</a>, <a href="#modulo">modulo</a>, <a href="#remainder">remainder</a>, <a href="#round">round</a></div>
</section>

<hr>
<section id="modified?">
 <a name="modified?"></a>
 <h2>MODIFIED?<a class="headerlink" href="#modified?" title="Link to this heading">¶</a></h2>
<p>Returns the last modified date of a file.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">modified? <span class="rebarg">target</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  target      [<span class="types">file! url!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns NONE if the file does not exist.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print modified? %file.txt
none</code></pre></div>
<div class="see-also">See also: <a href="#exists?">exists?</a></div>
</section>

<hr>
<section id="modify">
 <a name="modify"></a>
 <h2>MODIFY<a class="headerlink" href="#modify" title="Link to this heading">¶</a></h2>
<p>Change mode or control for port or file.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">modify <span class="rebarg">target</span> <span class="rebarg">field</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  target      [<span class="types">port! file!</span>] 
  field       [<span class="types">word! none!</span>] 
  value        
</pre>
</section>

<hr>
<section id="module">
 <a name="module"></a>
 <h2>MODULE<a class="headerlink" href="#module" title="Link to this heading">¶</a></h2>
<p>Creates a new module.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">module <span class="rebarg">spec</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">block!</span>] The header block of the module (modified)
  body        [<span class="types">block!</span>] The body block of the module (modified)
<span class="tit">REFINEMENTS:</span>
  /mixin      Mix in words from other modules
   words      [<span class="types">object!</span>] Words collected into an object
</pre>

<h6>Description:</h6>
<p>
Description is needed.
</p>

</section>

<hr>
<section id="module?">
 <a name="module?"></a>
 <h2>MODULE?<a class="headerlink" href="#module?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">module? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; module? object [a: 1]
== #(false)

&gt;&gt; module? system/modules/help
== #(true)</code></pre></div>
</section>

<hr>
<section id="modulo">
 <a name="modulo"></a>
 <h2>MODULO<a class="headerlink" href="#modulo" title="Link to this heading">¶</a></h2>
<p>Wrapper for MOD that handles errors like REMAINDER. Negligible values (compared to A and B) are rounded to zero.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">modulo <span class="rebarg">a</span> <span class="rebarg">b</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  a           [<span class="types">number! money! char! time!</span>] 
  b           [<span class="types">number! money! char! time!</span>] Absolute value will be used.
</pre>

<h6>Description:</h6>
<p>
See MOD for details.
</p>

<div class="see-also">See also: <a href="#//">//</a>, <a href="#mod">mod</a>, <a href="#remainder">remainder</a>, <a href="#round">round</a></div>
</section>

<hr>
<section id="mold">
 <a name="mold"></a>
 <h2>MOLD<a class="headerlink" href="#mold" title="Link to this heading">¶</a></h2>
<p>Converts a value to a REBOL-readable string.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">mold <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] The value to mold
<span class="tit">REFINEMENTS:</span>
  /only       For a block value, mold only its contents, no outer []
  /all        Use construction syntax
  /flat       No indentation
  /part       Limit the length of the result
   limit      [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#mold">mold</a> function converts values to a source-code formatted string (REBOL-readable).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print mold 10:30
10:30

print mold %image.jpg
%image.jpg

print mold [1 2 3]
[1 2 3]</code></pre></div><p>
The primary importance of <a href="#mold">mold</a> is to produce strings that can be reloaded with <a href="#load">load</a>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: mold [1 + 2]
probe load str
[1 + 2]</code></pre></div><p>
The <a href="#mold">mold</a> function is the cousin of <a href="#form">form</a> which produces a human-readable string (used by the <a href="#print">print</a> function.) For example a block will be shown with brackets </p>
<p>
Also, <a href="#remold">remold</a> first uses <a href="#reduce">reduce</a> then <a href="#mold">mold</a>.
</p>

<h6>The /only Refinement</h6><p>
In some cases it is useful to not <a href="#mold">mold</a> the outermost brackets of blocks. This is done with the /only refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print mold/only [1 2 3]
1 2 3</code></pre></div><p>
This is commonly true for blocks of values that are saved to files:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">write %example.r mold/only [1 2 3]</code></pre></div><p>
See the <a href="#save">save</a> function.
</p>

<h6>The /all Refinement</h6><p>
For some values <a href="#mold">mold</a> produces an approximate string value, not a perfect representation. If you attempt to load such a string, its value may be different.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">mold 'true
"true"

mold true
"true"</code></pre></div><p>
The first is the word true the second is the <span class="datatype">logic!</span> value true -- they are different but represented by the same word. If you <a href="#load">load</a> the resulting string, you will only obtain the word true not the logic value:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">type? load mold true
word!</code></pre></div><p>
The /all option provides a more accurate transformation from values to strings and back (using <a href="#load">load</a>.)
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">mold/all 'true
"true"

mold/all true
"#[true]"</code></pre></div><p>
Using <a href="#load">load</a>, you can see the difference:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">type? load mold/all 'true
word!

type? load mold/all true
logic!</code></pre></div><p>
Another difference occurs with strings that are indexed from their <a href="#head">head</a> positions. Sometimes this is desired, sometimes not. It can be seen here:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">mold next "ABC"
"BC"

mold/all next "ABC"
{#[string! "ABC" 2]}</code></pre></div>
<h7>Affected Datatypes</h7><p>
The following datatypes are affected: <span class="datatype">unset!</span>, <span class="datatype">none!</span>, <span class="datatype">logic!</span>, <span class="datatype">bitset!</span>, <span class="datatype">image!</span>, <span class="datatype">map!</span>, <span class="datatype">datatype!</span>, <span class="datatype">typeset!</span>, <span class="datatype">native!</span>, <span class="datatype">action!</span>, <span class="datatype">op!</span>, <span class="datatype">closure!</span>, <span class="datatype">function!</span>, <span class="datatype">object!</span>, <span class="datatype">module!</span>, <span class="datatype">error!</span>, <span class="datatype">task!</span>, <span class="datatype">port!</span>, <span class="datatype">gob!</span>, <span class="datatype">event!</span>, <span class="datatype">handle!</span>.
</p>
<fieldset class="fset"><legend>Note on Restoring Semantics</legend>
<p>It should also be noted that some datatypes cannot be returned to a source form without losing semantic information. For example, functions cannot maintain the binding (scoping context) of their words. If such semantics reproduction is required it is recommended that your code output entire blocks that as a whole are evaluated to produce the correct semantic result. This is commonly done in REBOL code, including the common storage of mezzanine and module functions and other definitions.</p>
</fieldset>
<h7>Accuracy of Decimals</h7><p>
The <span class="datatype">decimal!</span> datatype is implemented as IEEE 754 binary floating point type. When molding <span class="datatype">decimal!</span> values, mold/all will need to use the maximal precision 17 digits to allow for accurate transformation of Rebol decimals to string and back, as opposed to just <a href="#mold">mold</a>, which uses a default precision 15 decimal digits.
</p>

<h6>The /flat Refinement</h6><p>
The /flat refinement is useful for minimizing the size of source strings. It properly removes leading indentation (from code lines, but not multi-line strings.) The /flat option is often used for data exchanged between systems or stored in files.
</p>
<p>
Here is code often used for saving a script in minimal format (in R3):
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">write %output.r mold/only/flat code</code></pre></div><p>
For code larger than about 1K, you can also compress it:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">write %output.rc compress mold/only/flat code</code></pre></div><p>
Such a file can be reloaded with:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">load/all decompress read %output.rc</code></pre></div><p>
Note that if using R2, these lines must be modified to indicate binary format.
</p>

<h6>Code Complexity Comparisons</h6><p>
It should be noted that <a href="#mold">mold</a> function is used for computing the relative complexity of code using the <a href="http://www.rebol.net/wiki/Load_Mold_Sizes">Load Mold Sizing method</a>.
</p>

<div class="see-also">See also: <a href="#form">form</a>, <a href="#insert">insert</a>, <a href="#join">join</a>, <a href="#reduce">reduce</a>, <a href="#remold">remold</a></div>
</section>

<hr>
<section id="mold64">
 <a name="mold64"></a>
 <h2>MOLD64<a class="headerlink" href="#mold64" title="Link to this heading">¶</a></h2>
<p>Temporary function to mold binary base 64.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">mold64 <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data         
</pre>
</section>

<hr>
<section id="money?">
 <a name="money?"></a>
 <h2>MONEY?<a class="headerlink" href="#money?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">money? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print money? $123
true

print money? 123.45
false</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="more">
 <a name="more"></a>
 <h2>MORE<a class="headerlink" href="#more" title="Link to this heading">¶</a></h2>
<p>Print file (shell shortcut function).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">more <span class="rebarg">file</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  file        [<span class="types">file! word! path! string!</span>] Accepts %file and also just words (as file names)
</pre>

<h6>Description:</h6>
<p>
Description is needed.
</p>

</section>

<hr>
<section id="move">
 <a name="move"></a>
 <h2>MOVE<a class="headerlink" href="#move" title="Link to this heading">¶</a></h2>
<p>Move a value or span of values in a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">move <span class="rebarg">source</span> <span class="rebarg">offset</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  source      [<span class="types">series! gob!</span>] Source series (modified)
  offset      [<span class="types">integer!</span>] Offset to move by, or index to move to
<span class="tit">REFINEMENTS:</span>
  /part       Move part of a series
   length     [<span class="types">integer!</span>] The length of the part to move
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] Size of each record
  /to         Move to an index relative to the head of the series
</pre>

<h6>Description:</h6>
<p>
Description is needed.
</p>

</section>

<hr>
<section id="multiply">
 <a name="multiply"></a>
 <h2>MULTIPLY<a class="headerlink" href="#multiply" title="Link to this heading">¶</a></h2>
<p>Returns the first value multiplied by the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">multiply <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! vector!</span>] 
  value2      [<span class="types">scalar! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
The datatype of the second value may be restricted to
INTEGER or DECIMAL, depending on the datatype of the
first value (e.g. the first value is a time).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print multiply 123 10
1230

print multiply 3:20 3
10:00

print multiply 0:01 60
1:00</code></pre></div>
<div class="see-also">See also: <a href="#/">/</a>, <a href="#//">//</a>, <a href="#divide">divide</a></div>
</section>

<hr>
<section id="native?">
 <a name="native?"></a>
 <h2>NATIVE?<a class="headerlink" href="#native?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">native? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values. When passing a
function to NATIVE? to be checked, it must be denoted
with ":". This is because the ":word" notation passes a
word's reference, not the word's value. NATIVE? can only
determine whether or not a function is a native if it is
passed the function's reference.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe native? :native?   ; it's actually an ACTION!
false

probe native? "Vichy"
false

probe native? :if
true</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="negate">
 <a name="negate"></a>
 <h2>NEGATE<a class="headerlink" href="#negate" title="Link to this heading">¶</a></h2>
<p>Changes the sign of a number.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">negate <span class="rebarg">number</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  number      [<span class="types">number! pair! money! time! bitset!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns the negative of the value provided.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print negate 123
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
-100x20</code></pre></div>
<div class="see-also">See also: <a href="#+">+</a>, <a href="#-">-</a>, <a href="#complement">complement</a>, <a href="#negative?">negative?</a>, <a href="#not">not</a>, <a href="#positive?">positive?</a></div>
</section>

<hr>
<section id="negative?">
 <a name="negative?"></a>
 <h2>NEGATIVE?<a class="headerlink" href="#negative?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the number is negative.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">negative? <span class="rebarg">number</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  number      [<span class="types">number! money! time! pair!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print negative? -50
true

print negative? 50
false</code></pre></div>
<div class="see-also">See also: <a href="#positive?">positive?</a></div>
</section>

<hr>
<section id="new-line">
 <a name="new-line"></a>
 <h2>NEW-LINE<a class="headerlink" href="#new-line" title="Link to this heading">¶</a></h2>
<p>Sets or clears the new-line marker within a block or paren.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">new-line <span class="rebarg">position</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  position    [<span class="types">block! paren!</span>] Position to change marker (modified)
  value        Set TRUE for newline
<span class="tit">REFINEMENTS:</span>
  /all        Set/clear marker to end of series
  /skip       Set/clear marker periodically to the end of the series
   size       [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
Where the NEW-LINE? function queries the status of the a 
block for markers, the NEW-LINE function inserts or removes 
them. You can use it to generate formatted blocks.
</p>
<p>
Given a block at a specified offset, new-line? will return 
true if there is a marker at that position.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">dent-block: func [
    "Indent the contents of a block"
    block
][
    head new-line tail new-line block on on
]

b: [1 2 3 4 5 6]
probe dent-block b
[

1 2 3 4 5 6</code></pre></div><p>
</p>
<p>
If you want to put each item in a block on a new line, you 
can insert markers in bulk, using the /all refinement.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">b: [1 2 3 4 5 6]
probe new-line/all b on
[

1
2
3
4
5
6</code></pre></div><p>
</p>
<p>
If you don't know whether a block contains markers, you may 
want to remove all markers before formatting the data.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">b: [
    1 2 
    3 4
]
probe new-line/all b off
[1 2 3 4]</code></pre></div><p>
Another common need is formatting blocks into lines of fixed 
size groups of items; that's what the /skip refinement is for.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">b: [1 2 3 4 5 6]
probe new-line/skip b on 2
[

1 2
3 4
5 6</code></pre></div><p>
</p>

<div class="see-also">See also: <a href="#new-line?">new-line?</a></div>
</section>

<hr>
<section id="new-line?">
 <a name="new-line?"></a>
 <h2>NEW-LINE?<a class="headerlink" href="#new-line?" title="Link to this heading">¶</a></h2>
<p>Returns the state of the new-line marker within a block or paren.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">new-line? <span class="rebarg">position</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  position    [<span class="types">block! paren!</span>] Position to check marker
</pre>

<h6>Description:</h6>
<p>
Given a block at a specified offset, new-line? will return 
true if there is a line marker at that position.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">b: [1 2 3 4 5 6]
forall b [if new-line? b [print index? b]]

b: [
    1 2
    3 4
    5 6
]
forall b [if new-line? b [print index? b]]
5</code></pre></div>
<div class="see-also">See also: <a href="#new-line">new-line</a></div>
</section>

<hr>
<section id="next">
 <a name="next"></a>
 <h2>NEXT<a class="headerlink" href="#next" title="Link to this heading">¶</a></h2>
<p>Returns the series at its next position.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">next <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port!</span>] 
</pre>

<h6>Description:</h6>
<p>
If the series is at its tail, it will remain at its
tail. NEXT will not go past the tail, nor will it wrap
to the head.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print next "ABCDE"
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
[blue]</code></pre></div>
<div class="see-also">See also: <a href="#back">back</a>, <a href="#first">first</a>, <a href="#head">head</a>, <a href="#head?">head?</a>, <a href="#tail">tail</a>, <a href="#tail?">tail?</a></div>
</section>

<hr>
<section id="ninth">
 <a name="ninth"></a>
 <h2>NINTH<a class="headerlink" href="#ninth" title="Link to this heading">¶</a></h2>
<p>Returns the ninth value of a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">ninth <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
See the FIRST function for examples.
</p>
<p>
An error will occur if no value is found. Use the PICK function to avoid this error.
</p>

<div class="see-also">See also: <a href="#first">first</a>, <a href="#pick">pick</a>, <a href="#second">second</a>, <a href="#third">third</a></div>
</section>

<hr>
<section id="none?">
 <a name="none?"></a>
 <h2>NONE?<a class="headerlink" href="#none?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">none? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print none? NONE
true

print none? pick "abc" 4
true

print none? find "abc" "d"
true</code></pre></div>
</section>

<hr>
<section id="not">
 <a name="not"></a>
 <h2>NOT<a class="headerlink" href="#not" title="Link to this heading">¶</a></h2>
<p>Returns the logic complement.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">not <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] (Only FALSE and NONE return TRUE)
</pre>

<h6>Description:</h6>
<p>
The <a href="#not">not</a> function is a <span class="datatype">logic!</span> function that returns true if the value is false or none. It will return false for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">not true
false

not none
true

not (10 = 1)
true

not 0
false  ; take note of this

not 1
false</code></pre></div><p>
To complement an <span class="datatype">integer!</span> use the <a href="#complement">complement</a> function or <a href="#negate">negate</a> function.
</p>

<div class="see-also">See also: <a href="#and">and</a>, <a href="#complement">complement</a>, <a href="#negate">negate</a>, <a href="#or">or</a>, <a href="#unless">unless</a>, <a href="#xor">xor</a></div>
</section>

<hr>
<section id="not-equal?">
 <a name="not-equal?"></a>
 <h2>NOT-EQUAL?<a class="headerlink" href="#not-equal?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are not equal.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">not-equal? <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
String-based datatypes are considered equal when they
are identical or differ only by character casing
(uppercase = lowercase). Use <a href="#==">==</a> or find/match/case to
compare strings by casing.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print not-equal? "abc" "abcd"
true

print not-equal? [1 2 4] [1 2 3]
true

print not-equal? 12-sep-98 10:30
true</code></pre></div>
<div class="see-also">See also: <a href="#<>">&lt;&gt;</a>, <a href="#=">=</a>, <a href="#==">==</a>, <a href="#equal?">equal?</a></div>
</section>

<hr>
<section id="not-equiv?">
 <a name="not-equiv?"></a>
 <h2>NOT-EQUIV?<a class="headerlink" href="#not-equiv?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are not equivalent.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">not-equiv? <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id="now">
 <a name="now"></a>
 <h2>NOW<a class="headerlink" href="#now" title="Link to this heading">¶</a></h2>
<p>Returns date and time.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">now</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /year       Returns year only
  /month      Returns month only
  /day        Returns day of the month only
  /time       Returns time only
  /zone       Returns time zone offset from UCT (GMT) only
  /date       Returns date only
  /weekday    Returns day of the week as integer (Monday is day 1)
  /yearday    Returns day of the year (Julian)
  /precise    High precision time
  /utc        Universal time (no zone)
</pre>

<h6>Description:</h6>
<p>
For accuracy, first verify that the time, date and
timezone are correctly set on the computer.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print now
12-Feb-2009/17:47:54-8:00

print now/date
12-Feb-2009

print now/time
17:47:54

print now/zone
-8:00

print now/weekday
4</code></pre></div>
<div class="see-also">See also: <a href="#date?">date?</a></div>
</section>

<hr>
<section id="number?">
 <a name="number?"></a>
 <h2>NUMBER?<a class="headerlink" href="#number?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the value is any type of number and not a NaN. </p>

<h6>Usage:</h6>
<pre class="usage fs-6">number? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type! unset!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; number? 1234
== #(true)

&gt;&gt; number? 12.3
== #(true)

&gt;&gt; number? "12"
== #(false)</code></pre></div>
<div class="see-also">See also: <a href="#decimal?">decimal?</a>, <a href="#integer?">integer?</a></div>
</section>

<hr>
<section id="object">
 <a name="object"></a>
 <h2>OBJECT<a class="headerlink" href="#object" title="Link to this heading">¶</a></h2>
<p>Creates an object.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">object <span class="rebarg">spec</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">block!</span>] 
<span class="tit">REFINEMENTS:</span>
  /only       Do not bind nested blocks
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="object?">
 <a name="object?"></a>
 <h2>OBJECT?<a class="headerlink" href="#object?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">object? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; object? system
== #(true)

&gt;&gt; object? 1
== #(false)</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="odd?">
 <a name="odd?"></a>
 <h2>ODD?<a class="headerlink" href="#odd?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the number is odd.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">odd? <span class="rebarg">number</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  number      [<span class="types">number! char! date! money! time! pair!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns TRUE only if the argument is an odd integer value.
If the argument is a decimal, only its integer portion is
examined.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print odd? 3
true

print odd? 100
false

print odd? 0
false</code></pre></div>
<div class="see-also">See also: <a href="#even?">even?</a></div>
</section>

<hr>
<section id="offset?">
 <a name="offset?"></a>
 <h2>OFFSET?<a class="headerlink" href="#offset?" title="Link to this heading">¶</a></h2>
<p>Returns the offset between two series positions.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">offset? <span class="rebarg">series1</span> <span class="rebarg">series2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series1     [<span class="types">series!</span>] 
  series2     [<span class="types">series!</span>] 
</pre>

<h6>Description:</h6>
<p>
Return the difference of the indexes for two positions within a
series.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "abcd"
p1: next str
print offset? str p1
1

str: "abcd"
p1: next str
p2: find str "d"
print offset? p1 p2
2</code></pre></div>
<div class="see-also">See also: <a href="#head">head</a>, <a href="#head?">head?</a>, <a href="#index?">index?</a>, <a href="#length?">length?</a>, <a href="#pick">pick</a>, <a href="#skip">skip</a>, <a href="#tail">tail</a>, <a href="#tail?">tail?</a></div>
</section>

<hr>
<section id="op?">
 <a name="op?"></a>
 <h2>OP?<a class="headerlink" href="#op?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">op? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print op? :and
true

print op? :+
true</code></pre></div>
</section>

<hr>
<section id="open">
 <a name="open"></a>
 <h2>OPEN<a class="headerlink" href="#open" title="Link to this heading">¶</a></h2>
<p>Opens a port; makes a new port from a specification if necessary.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">open <span class="rebarg">spec</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">port! file! url! block! word!</span>] 
<span class="tit">REFINEMENTS:</span>
  /new        Create new file - if it exists, reset it (truncate)
  /read       Open for read access
  /write      Open for write access
  /seek       Optimize for random access
  /allow      Specifies protection attributes
   access     [<span class="types">block!</span>] 
</pre>

<h6>Description:</h6>
<p>
Opens a port for I/O operations. The value returned from
OPEN can be used to examine or modify the data
associated with the port. The argument must be a
fully-specified port specification, an abbreviated port
specification such as a file path or URL, or a block
which is executed to modify a copy of the default port
specification.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">autos: open/new %autos.txt
insert autos "Ford"
insert tail autos " Chevy"
close autos
print read %autos.txt</code></pre></div>
<div class="see-also">See also: <a href="#close">close</a>, <a href="#do">do</a>, <a href="#insert">insert</a>, <a href="#load">load</a>, <a href="#query">query</a>, <a href="#read">read</a>, <a href="#remove">remove</a>, <a href="#write">write</a></div>
</section>

<hr>
<section id="open?">
 <a name="open?"></a>
 <h2>OPEN?<a class="headerlink" href="#open?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if port is open.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">open? <span class="rebarg">port</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  port        [<span class="types">port!</span>] 
</pre>

<h6>Description:</h6>
<p>
Description is needed.
</p>

</section>

<hr>
<section id="or">
 <a name="or"></a>
 <h2>OR<a class="headerlink" href="#or" title="Link to this heading">¶</a></h2>
<p>Returns the first value ORed with the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> or <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
  value2      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
An infix-operator. For LOGIC values, both must be FALSE
to return FALSE; otherwise a TRUE is returned. For
integers, each bit is separately affected. Because it is
an infix operator, OR must be between the two values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print true or false
true

print (10 &gt; 20) or (20 &lt; 100)
true

print 122 or 1
123

print 1.2.3.4 or 255.255.255.0
255.255.255.4</code></pre></div>
<div class="see-also">See also: <a href="#and">and</a>, <a href="#not">not</a>, <a href="#xor">xor</a></div>
</section>

<hr>
<section id="or~">
 <a name="or~"></a>
 <h2>OR~<a class="headerlink" href="#or~" title="Link to this heading">¶</a></h2>
<p>Returns the first value ORed with the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">or~ <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
  value2      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
The trampoline action function for OR operator.
</p>

<div class="see-also">See also: <a href="#and~">and~</a>, <a href="#xor~">xor~</a></div>
</section>

<hr>
<section id="pad">
 <a name="pad"></a>
 <h2>PAD<a class="headerlink" href="#pad" title="Link to this heading">¶</a></h2>
<p>Pad a FORMed value on right side with spaces</p>

<h6>Usage:</h6>
<pre class="usage fs-6">pad <span class="rebarg">str</span> <span class="rebarg">n</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  str          Value to pad, FORM it if not a string
  n           [<span class="types">integer!</span>] Total size (in characters) of the new string (pad on left side if negative)
<span class="tit">REFINEMENTS:</span>
  /with       Pad with char
   c          [<span class="types">char!</span>] 
</pre>
</section>

<hr>
<section id="pair?">
 <a name="pair?"></a>
 <h2>PAIR?<a class="headerlink" href="#pair?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">pair? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns true if the value is an xy pair datatype.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print pair? 120x40
true

print pair? 1234
false</code></pre></div><p>
See the PAIR! word for more detail.
</p>

<div class="see-also">See also: <a href="#as-pair">as-pair</a>, <a href="#to-pair">to-pair</a></div>
</section>

<hr>
<section id="paren?">
 <a name="paren?"></a>
 <h2>PAREN?<a class="headerlink" href="#paren?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">paren? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values. A paren is identical
to a block, but is immediately evaluated when found.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print paren? second [123 (456 + 7)]
true

print paren? [1 2 3]
false</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="parse">
 <a name="parse"></a>
 <h2>PARSE<a class="headerlink" href="#parse" title="Link to this heading">¶</a></h2>
<p>Parses a string or block series according to grammar rules.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">parse <span class="rebarg">input</span> <span class="rebarg">rules</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  input       [<span class="types">series!</span>] Input series to parse
  rules       [<span class="types">block!</span>] Rules to parse
<span class="tit">REFINEMENTS:</span>
  /case       Uses case-sensitive comparison
</pre>

<h6>Description:</h6>
<p>
The <a href="#parse">parse</a> function is used to match patterns of values and perform specific actions upon  such matches. A full summary can be found in <a href="https://www.rebol.com/r3/docs/concepts/parsing-summary.html">parsing: summary of parse operations</a> .
</p>
<p>
Both <span class="datatype">string!</span> and <span class="datatype">block!</span> datatypes can be parsed. Parsing of strings matches specific characters or substrings. Parsing of blocks matches specific values, or specific datatypes, or sub-blocks.
</p>
<p>
Whereas most languages provide a method of parsing strings, the parsing of blocks is an important feature of the REBOL language.
</p>
<p>
The <a href="#parse">parse</a> function takes two main arguments: an input to be parsed and the rules that are used to parse it. The rules are specified as a block of grammar productions that are to be matched.
</p>

<h6>General parse rules</h6><p>
Rules consist of these main elements:
</p>
<table class="doctable">
<tr><th align="top">
Item
</th><th valign="top">
Description
</th>
<tr>
<td valign="top">
keyword </td><td valign="top"> a special word of the dialect, listed in the table below
</td>
<tr>
<td valign="top">
word </td><td valign="top"> get or set a variable (see below) - cannot be a keyword
</td>
<tr>
<td valign="top">
path </td><td valign="top"> get or set a variable via a path (see below)
</td>
<tr>
<td valign="top">
value </td><td valign="top"> match the input to a value (accepted datatypes depend on input datatype)
</td>
<tr>
<td valign="top">
"|" </td><td valign="top"> backtrack and match to next alternate rule (or)
</td>
<tr>
<td valign="top">
[block] </td><td valign="top"> a block of sub-rules
</td>
<tr>
<td valign="top">
(paren) </td><td valign="top"> evaluate an expression (a production)
</td></tr></table>
<h6>List of keywords</h6><p>
Within the parse dialect, these words are treated as keywords and cannot be used as variables.
</p>
<table class="doctable">
<tr><th align="top">
Keyword
</th><th valign="top">
Description
</th>
<tr>
<td valign="top">
and rule
</td><td valign="top">
match the rule, but do not advance the input (allows matching multiple rules to the same input)
</td>
<tr>
<td valign="top">
any rule
</td><td valign="top">
match the rule zero or more times; stop on failure or if input does not change.
</td>
<tr>
<td valign="top">
break
</td><td valign="top">
break out of a match loop (such as any, some, while), always indicating success.
</td>
<tr>
<td valign="top">
change rule <i>only</i> value
</td><td valign="top">
match the rule, and if true, change the input to the new value (can be different lengths)
</td>
<tr>
<td valign="top">
copy word
</td><td valign="top">
set the word to a copy of the input for matched rules
</td>
<tr>
<td valign="top">
do rule </td><td valign="top"> evaluate the input as code, then attempt to match to the rule
</td>
<tr>
<td valign="top">
end
</td><td valign="top">
match end of input
</td>
<tr>
<td valign="top">
fail
</td><td valign="top">
force current rule to fail, backtrack
</td>
<tr>
<td valign="top">
if (expr)
</td><td valign="top">
evaluate the expression (in a paren) and if false or none, fail and backtrack
</td>
<tr>
<td valign="top">
insert <i>only</i> value
</td><td valign="top">
insert a value at the current input position (with optional ONLY for blocks by reference); input position is adjusted just past the insert
</td>
<tr>
<td valign="top">
into rule
</td><td valign="top">
match a series, then parse it with given rule; new series can be the same or different datatype.
</td>
<tr>
<td valign="top">
opt rule
</td><td valign="top">
match to the rule once or not at all (zero or one times)
</td>
<tr>
<td valign="top">
not rule
</td><td valign="top">
invert the result of the next rule
</td>
<tr>
<td valign="top">
quote arg
</td><td valign="top">
accept next argument exactly as is (exception: paren)
</td>
<tr>
<td valign="top">
reject
</td><td valign="top">
similar to break: break out of a match loop (such as any, some, while), but indicate failure.
</td>
<tr>
<td valign="top">
remove rule
</td><td valign="top">
match the rule, and if true, remove the matched input
</td>
<tr>
<td valign="top">
return rule
</td><td valign="top">
match the rule, and if true, immediately return the matched input as result of the PARSE function
</td>
<tr>
<td valign="top">
set word
</td><td valign="top">
set the word to the value of the input for matched rules
</td>
<tr>
<td valign="top">
skip
</td><td valign="top">
skip input (for the count range, if provided before it)
</td>
<tr>
<td valign="top">
some rule
</td><td valign="top">
match to the rule one or more times; stop on failure or if input does not change.
</td>
<tr>
<td valign="top">
then </td><td valign="top"> regardless of failure or success of what follows, skip the next alternate rule (branch)
</td>
<tr>
<td valign="top">
thru rule
</td><td valign="top">
scan forward in input for matching rules, advance input to tail of the match
</td>
<tr>
<td valign="top">
to rule
</td><td valign="top">
scan forward in input for matching rules, advance input to head of the match
</td>
<tr>
<td valign="top">
while rule
</td><td valign="top">
like any, match to the rule zero or more times; stop on failure; does not care if input changes or not.
</td>
<tr>
<td valign="top">
??
</td><td valign="top">
Debugging output. Prints the next parse rule value and shows the current input position (e.g. where you are in the string.)
</td></tr></table><p>
In addition, none is a special value that can be used as a default match rule. It is often used at the end of alternate rules to catch all no-match cases.
</p>

<h6>Simple Parse</h6><p>
There is also a simple parse
mode that does not require rules, but takes a string of
characters to use for splitting up the input string.
</p>
<p>
Parse also works in conjunction with bitsets (charset)
to specify groups of special characters.
</p>
<p>
The result returned from a simple parse is a block of
values. For rule-based parses, it returns TRUE if the
parse succeeded through the end of the input string.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print parse "divide on spaces" none
divide on spaces

print parse "Harry Haiku, 264 River Rd., Ukiah, 95482" ","
Harry Haiku 264 River Rd. Ukiah 95482

page: read http://hq.rebol.net
parse page [thru &lt;title&gt; copy title to &lt;/title&gt;]
print title
Now is REBOL

digits: charset "0123456789"
area-code: ["(" 3 digits ")"]
phone-num: [3 digits "-" 4 digits]
print parse "(707)467-8000" [[area-code | none] phone-num]
true</code></pre></div>
<div class="see-also">See also: <a href="#trim">trim</a></div>
</section>

<hr>
<section id="past?">
 <a name="past?"></a>
 <h2>PAST?<a class="headerlink" href="#past?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if series is past its end.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">past? <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port!</span>] 
</pre>

<h6>Description:</h6>
<p>
Description is needed.
</p>

</section>

<hr>
<section id="path?">
 <a name="path?"></a>
 <h2>PATH?<a class="headerlink" href="#path?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">path? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print path? first [random/seed 10]
true</code></pre></div>
<div class="see-also">See also: <a href="#make">make</a></div>
</section>

<hr>
<section id="percent?">
 <a name="percent?"></a>
 <h2>PERCENT?<a class="headerlink" href="#percent?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">percent? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; percent? 10%
== #(true)

&gt;&gt; percent? 10
== #(false)</code></pre></div>
</section>

<hr>
<section id="pick">
 <a name="pick"></a>
 <h2>PICK<a class="headerlink" href="#pick" title="Link to this heading">¶</a></h2>
<p>Returns the value at the specified position.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">pick <span class="rebarg">aggregate</span> <span class="rebarg">index</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  aggregate   [<span class="types">series! map! gob! pair! date! time! tuple! bitset! port!</span>] 
  index        Index offset, symbol, or other value to use as index
</pre>

<h6>Description:</h6>
<p>
The value is picked relative to the current position in
the series (not necessarily the head of the series).
The VALUE argument may be INTEGER or LOGIC. A positive
integer positions forward, a negative positions
backward. If the INTEGER is out of range, NONE is
returned. If the value is LOGIC, then TRUE refers to the
first position and FALSE to the second (same order as
EITHER). An attempt to pick a value beyond the limits
of the series will return NONE.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "REBOL"

print pick str 2
E

print pick 199.4.80.1 3
80

print pick ["this" "that"] now/time &gt; 12:00
this</code></pre></div>
<div class="see-also">See also: <a href="#fifth">fifth</a>, <a href="#find">find</a>, <a href="#first">first</a>, <a href="#fourth">fourth</a>, <a href="#second">second</a>, <a href="#select">select</a>, <a href="#third">third</a></div>
</section>

<hr>
<section id="pickz">
 <a name="pickz"></a>
 <h2>PICKZ<a class="headerlink" href="#pickz" title="Link to this heading">¶</a></h2>
<p>Returns the value at the specified position. (0-based wrapper over PICK action)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">pickz <span class="rebarg">aggregate</span> <span class="rebarg">index</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  aggregate   [<span class="types">series! bitset! tuple!</span>] 
  index       [<span class="types">integer!</span>] Zero based
</pre>
</section>

<hr>
<section id="poke">
 <a name="poke"></a>
 <h2>POKE<a class="headerlink" href="#poke" title="Link to this heading">¶</a></h2>
<p>Replaces an element at a given position.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">poke <span class="rebarg">series</span> <span class="rebarg">index</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! port! map! gob! bitset!</span>] (modified)
  index        Index offset, symbol, or other value to use as index
  value       [<span class="types">any-type!</span>] The new value (returned)
</pre>

<h6>Description:</h6>
<p>
Similar to CHANGE, but also takes an index into the series.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "ABC"
poke str 2 #"/"
print str
A/C

print poke 1.2.3.4 2 10
10</code></pre></div>
<div class="see-also">See also: <a href="#change">change</a>, <a href="#pick">pick</a></div>
</section>

<hr>
<section id="pokez">
 <a name="pokez"></a>
 <h2>POKEZ<a class="headerlink" href="#pokez" title="Link to this heading">¶</a></h2>
<p>Replaces an element at a given position. (0-based wrapper over POKE action)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">pokez <span class="rebarg">series</span> <span class="rebarg">index</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! bitset! tuple!</span>] (modified)
  index       [<span class="types">integer!</span>] Zero based
  value       [<span class="types">any-type!</span>] The new value (returned)
</pre>
</section>

<hr>
<section id="port?">
 <a name="port?"></a>
 <h2>PORT?<a class="headerlink" href="#port?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">port? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">file: open %newfile.txt
print port? file
close file
true

print port? "test"
false</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="positive?">
 <a name="positive?"></a>
 <h2>POSITIVE?<a class="headerlink" href="#positive?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the value is positive.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">positive? <span class="rebarg">number</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  number      [<span class="types">number! money! time! pair!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print positive? 50
true

print positive? -50
false</code></pre></div>
<div class="see-also">See also: <a href="#negative?">negative?</a></div>
</section>

<hr>
<section id="power">
 <a name="power"></a>
 <h2>POWER<a class="headerlink" href="#power" title="Link to this heading">¶</a></h2>
<p>Returns the first number raised to the second number.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">power <span class="rebarg">number</span> <span class="rebarg">exponent</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  number      [<span class="types">number!</span>] 
  exponent    [<span class="types">number!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print power 12.3 5
281530.5684300001</code></pre></div>
<div class="see-also">See also: <a href="#exp">exp</a>, <a href="#log-10">log-10</a>, <a href="#log-2">log-2</a>, <a href="#log-e">log-e</a></div>
</section>

<hr>
<section id="premultiply">
 <a name="premultiply"></a>
 <h2>PREMULTIPLY<a class="headerlink" href="#premultiply" title="Link to this heading">¶</a></h2>
<p>Premultiplies RGB channel with its alpha channel</p>

<h6>Usage:</h6>
<pre class="usage fs-6">premultiply <span class="rebarg">image</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  image       [<span class="types">image!</span>] Image to premultiply (modified)
</pre>
</section>

<hr>
<section id="prime?">
 <a name="prime?"></a>
 <h2>PRIME?<a class="headerlink" href="#prime?" title="Link to this heading">¶</a></h2>
<p>Returns true if value is a prime number</p>

<h6>Usage:</h6>
<pre class="usage fs-6">prime? <span class="rebarg">number</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  number      [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="prin">
 <a name="prin"></a>
 <h2>PRIN<a class="headerlink" href="#prin" title="Link to this heading">¶</a></h2>
<p>Outputs a value with no line break.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">prin <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
No line termination is used, so the next value printed
will appear on the same line. If the value is a block,
each of its values will be evaluated first then printed.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">prin "The value is "
prin [1 + 2]

prin ["The time is" now/time]</code></pre></div>
<div class="see-also">See also: <a href="#echo">echo</a>, <a href="#input">input</a>, <a href="#print">print</a></div>
</section>

<hr>
<section id="print">
 <a name="print"></a>
 <h2>PRINT<a class="headerlink" href="#print" title="Link to this heading">¶</a></h2>
<p>Outputs a value followed by a line break.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">print <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] The value to print
</pre>

<h6>Description:</h6>
<p>
The <a href="#print">print</a> function outputs values in "human-friendly" format (without source code syntax.)
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print 1234
1234

print "Example"
Example

print read %file.txt
(file output)

print read http://www.rebol.com
(web page output)</code></pre></div><p>
If the value is a block, it will be processed by <a href="#reduce">reduce</a> to evaluate each of its values, which will then be output:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print ["The time is" now/time]
The time is 17:47:54

print ["You are using REBOL" system/product system/version]
You are using REBOL core 3.0.0.3.1</code></pre></div>
<h6>Removing Spaces</h6><p>
If you need to join strings and values together for output, use the <a href="#ajoin">ajoin</a>, <a href="#join">join</a>, or <a href="#rejoin">rejoin</a> functions.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print ajoin ["REBOL/" system/product " V" system/version/1]]
REBOL/core V3

print ajoin ["The time is " 11:30 "AM"]
The time is 11:30AM</code></pre></div>
<h6>Related Functions</h6><p>
If a newline is not desired, use <a href="#prin">prin</a> which does not terminate the output:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">prin "T"
print "est"
Test</code></pre></div><p>
The <a href="#print">print</a> function is based on the <a href="#reform">reform</a> function, which combines the <a href="#reduce">reduce</a> and <a href="#form">form</a> functions.
</p>
<p>
Notice the difference between:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: reform ["The time is" now/time]
print str
The time is 17:47:54</code></pre></div><p>
and:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: form ["The time is" now/time]
print str
The time is now/time</code></pre></div><p>
The alternative to <a href="#form">form</a> is <a href="#mold">mold</a> which produces source code string output, and <a href="#remold">remold</a> combines <a href="#reduce">reduce</a> with <a href="#mold">mold</a> in the same way.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: mold ["The time is" now/time]
print str
["The time is" now/time]

str: mold ["The time is" now/time]
print str
["The time is" 17:47:54]</code></pre></div><p>
The <a href="#probe">probe</a> function is similar to <a href="#print">print</a> but is defined as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe: func [value] [print mold :value :value]</code></pre></div><p>
The second use of value is to cause <a href="#probe">probe</a> to return the value it was passed.
</p>
<p>
If you want to copy <a href="#print">print</a> output to a file as well as the console, use the <a href="#echo">echo</a> function.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">echo %output.txt
print "Copying to file"</code></pre></div>
<div class="see-also">See also: <a href="#??">??</a>, <a href="#ajoin">ajoin</a>, <a href="#echo">echo</a>, <a href="#form">form</a>, <a href="#format">format</a>, <a href="#input">input</a>, <a href="#join">join</a>, <a href="#mold">mold</a>, <a href="#prin">prin</a>, <a href="#probe">probe</a>, <a href="#reform">reform</a>, <a href="#rejoin">rejoin</a>, <a href="#remold">remold</a></div>
</section>

<hr>
<section id="print-horizontal-line">
 <a name="print-horizontal-line"></a>
 <h2>PRINT-HORIZONTAL-LINE<a class="headerlink" href="#print-horizontal-line" title="Link to this heading">¶</a></h2>
<p></p>

<h6>Usage:</h6>
<pre class="usage fs-6">print-horizontal-line</span></pre>
</section>

<hr>
<section id="print-table">
 <a name="print-table"></a>
 <h2>PRINT-TABLE<a class="headerlink" href="#print-table" title="Link to this heading">¶</a></h2>
<p>Print a block of blocks as an ASCII table</p>

<h6>Usage:</h6>
<pre class="usage fs-6">print-table <span class="rebarg">headers</span> <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  headers     [<span class="types">block!</span>] 
  block       [<span class="types">block!</span>] 
</pre>
</section>

<hr>
<section id="printf">
 <a name="printf"></a>
 <h2>PRINTF<a class="headerlink" href="#printf" title="Link to this heading">¶</a></h2>
<p>Formatted print.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">printf <span class="rebarg">fmt</span> <span class="rebarg">val</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  fmt          Format
  val          Value or block of values
</pre>

<h6>Description:</h6>
<p>
Description is needed.
</p>

</section>

<hr>
<section id="probe">
 <a name="probe"></a>
 <h2>PROBE<a class="headerlink" href="#probe" title="Link to this heading">¶</a></h2>
<p>Debug print a molded value and returns that same value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">probe <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] The output is truncated to size defined in: system/options/probe-limit
</pre>

<h6>Description:</h6>
<p>
The <a href="#probe">probe</a> function will <a href="#mold">mold</a> a value into reloadable source format and display it.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">num: 1
probe [num + 2 "ABC"]
[num + 2 "ABC"]</code></pre></div><p>
Compare with the <a href="#print">print</a> function which will <a href="#reduce">reduce</a> the block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print [num + 2 "ABC"]
3 ABC</code></pre></div>
<h6>Return Value</h6><p>
The <a href="#probe">probe</a> function also returns its argument value as its result, making it easy to insert into code for debugging purposes.
</p>
<p>
Examples:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">n: probe 1 + 2
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
found</code></pre></div><p>
See the <a href="#print">print</a> function for information about related functions.
</p>

<div class="see-also">See also: <a href="#??">??</a>, <a href="#help">help</a>, <a href="#mold">mold</a>, <a href="#print">print</a>, <a href="#source">source</a>, <a href="#trace">trace</a>, <a href="#what">what</a></div>
</section>

<hr>
<section id="profile">
 <a name="profile"></a>
 <h2>PROFILE<a class="headerlink" href="#profile" title="Link to this heading">¶</a></h2>
<p>Profile code</p>

<h6>Usage:</h6>
<pre class="usage fs-6">profile <span class="rebarg">blocks</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  blocks      [<span class="types">block!</span>] Block of code values (block, word, or function) to profile
<span class="tit">REFINEMENTS:</span>
  /times      Running the test code multiple times, results are average
   count      [<span class="types">integer!</span>] Default value is 10, minimum is 2 and maximum 1000
  /quiet      Returns [time evaluations series-made series-expanded memory source] results only
</pre>
</section>

<hr>
<section id="protect">
 <a name="protect"></a>
 <h2>PROTECT<a class="headerlink" href="#protect" title="Link to this heading">¶</a></h2>
<p>Protect a series or a variable from being modified.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">protect <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">word! series! bitset! map! object! module!</span>] 
<span class="tit">REFINEMENTS:</span>
  /deep       Protect all sub-series/objects as well
  /words      Process list as words (and path words)
  /values     Process list of values (implied GET)
  /hide       Hide variables (avoid binding and lookup)
  /lock       Protect permanently (unprotect will fail)
</pre>

<h6>Description:</h6>
<p>
The <a href="#protect">protect</a> function provides the following features:
</p>
<ul>
<li>protects <span class="datatype">string!</span>, <span class="datatype">block!</span>, and other series from modification (making them read-only.)</li>
<li>protects variables (words) from being <a href="#set">set</a> to new values.</li>
<li>protects <span class="datatype">object!</span>, <span class="datatype">module!</span>, and <span class="datatype">map!</span> from modification (by protecting all its words.)</li>
<li>hide words within objects or modules - making them private - a method of read and write protection.</li>
</ul>
<h6>Synopsis</h6><p>
The <a href="#protect">protect</a> argument and refinements provide these various protections:
</p>
<table class="doctable">
<tr><th align="top">
Argument
</th><th valign="top">
Refinement
</th><th valign="top">
Protection provided
</th>
<tr>
<td valign="top">
<span class="datatype">word!</span> or <span class="datatype">path!</span> </td><td valign="top"> </td><td valign="top"> cannot <a href="#set">set</a> the word (variable)
</td>
<tr>
<td valign="top">
<span class="datatype">word!</span> or <span class="datatype">path!</span> </td><td valign="top"> /hide </td><td valign="top"> cannot <a href="#bind">bind</a> to the word (variable)
</td>
<tr>
<td valign="top">
<span class="datatype">string!</span> </td><td valign="top"> </td><td valign="top"> cannot modify the string
</td>
<tr>
<td valign="top">
<span class="datatype">block!</span> </td><td valign="top"> </td><td valign="top"> cannot modify the block
</td>
<tr>
<td valign="top">
<span class="datatype">block!</span> </td><td valign="top"> /deep </td><td valign="top"> cannot modify block or any series within it
</td>
<tr>
<td valign="top">
<span class="datatype">block!</span> </td><td valign="top"> /words </td><td valign="top"> cannot <a href="#set">set</a> listed words or paths (variables)
</td>
<tr>
<td valign="top">
<span class="datatype">block!</span> </td><td valign="top"> /hide </td><td valign="top"> cannot <a href="#bind">bind</a> to listed words or paths
</td>
<tr>
<td valign="top">
<span class="datatype">object!</span> </td><td valign="top"> </td><td valign="top"> cannot modify object or <a href="#set">set</a> its words (variables)
</td>
<tr>
<td valign="top">
<span class="datatype">object!</span> </td><td valign="top"> /deep </td><td valign="top"> cannot modify object, <a href="#set">set</a> its words, or modify any of its series values
</td></tr></table>
<h6>Protecting series (strings and blocks)</h6><p>
For example to use <a href="#protect">protect</a> to prevent modification to a string:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">test: "text"
protect test
append test "a"
** Script error: protected value or series - cannot modify</code></pre></div><p>
The text string itself is now read-only. Any attempt to modify it will result in that
error message.
</p>
<p>
This also applies to other series:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">test: [100 "example" 10:20]
protect test
append test 1.2
** Script error: protected value or series - cannot modify</code></pre></div><p>
But notice:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print append test/2 "x"
examplex</code></pre></div><p>
So, series within the block are still modifiable.
</p>
<p>
To protect all series found within a block, use the /deep refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">test: [100 "example" 10:20]
protect/deep test
print append test/2 "x"
** Script error: protected value or series - cannot modify</code></pre></div>
<h6>Protecting objects and modules</h6><p>
It can also be applied to objects and modules, where its meaning becomes: do not let the fields of the object be modified. However, the contents of those fields can still be modified.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">person: make object! [
     name: "Bob"
     age: 32
]
protect person
person/name: "Ted"
** Script error: protected variable - cannot modify: name</code></pre></div><p>
However, you can still modify the contents of the name string:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">append person/name "a"
print person/name
Boba</code></pre></div><p>
To prevent that, you call <a href="#protect">protect</a> with the /deep refinement to protect all series within the object:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">person: make object! [
     name: "Bob"
     age: 32
]
protect/deep person
append person/name "a"
** Script error: protected value or series - cannot modify</code></pre></div>
<h6>Protecting variables (words)</h6><p>
Protect can also be used to prevent a variable word from being modified using a set operation.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">test: "This word is protected!"
protect 'test
test: 123
** Script error: protected variable - cannot modify: test</code></pre></div>
<h6>Hiding variables (words)</h6><p>
To make a variable private, use the /hide refinement. In effect, this prevents any further bindings to the variable. It also blocks attempts at <a href="#select">select</a>, <a href="#in">in</a>, <a href="#get">get</a>, <a href="#mold">mold</a>, and <a href="#form">form</a>, as well as <a href="#reflect">reflect</a> access.
</p>
<p>
For example, here is an object that defines a password variable that is hidden.
Once the object has been created, the pass variable is not accessible, except with the functions defined prior to the <a href="#protect">protect</a>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">manager: object [

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
]</code></pre></div><p>
The password can be accessed with the provided functions:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">manager/set-pass "bingo"
setting password...

print manager/get-pass
#{E410B808A7F76C6890C9ECACF2B564EC98204FDB}</code></pre></div><p>
But any other access is not allowed:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe manager/pass
** Script error: cannot access pass in path manager/pass

probe get in manager 'pass
none

probe select manager 'pass
none

probe words-of manager
[set-pass get-pass]</code></pre></div><p>
For security reasons, once hidden, a variable cannot be unhidden.
</p>

<h6>Compatibility</h6><fieldset class="fset"><legend>Non-compatibility with R2</legend>
<p>When using a block with <a href="#protect">protect</a>, the meaning is not to protect the words of the block, but to protect the block series itself.</p>
<p>If you need the behavior of R2, use the /words refinement.</p>
<p>For example:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">protect/words [test this]</code></pre></div>
<p>Will protect the test and this variables.</p>
</fieldset>
<h6>Related articles</h6><ul>
<li><a href="http://www.rebol.net/r3blogs/0186.html" class="lnk">Read-only strings, blocks, and objects</a></li>
<li><a href="http://www.rebol.net/r3blogs/0187.html" class="lnk">Interesting insights from PROTECT</a></li>
</ul><p>
(From the A43 release.)
</p>

<div class="see-also">See also: <a href="#secure">secure</a>, <a href="#set">set</a>, <a href="#unprotect">unprotect</a></div>
</section>

<hr>
<section id="protect-system-object">
 <a name="protect-system-object"></a>
 <h2>PROTECT-SYSTEM-OBJECT<a class="headerlink" href="#protect-system-object" title="Link to this heading">¶</a></h2>
<p>Protect the system object and selected sub-objects.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">protect-system-object</span></pre>
</section>

<hr>
<section id="protected?">
 <a name="protected?"></a>
 <h2>PROTECTED?<a class="headerlink" href="#protected?" title="Link to this heading">¶</a></h2>
<p>Return true if immediate argument is protected from modification.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">protected? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">word! series! bitset! map! object! module!</span>] 
</pre>
</section>

<hr>
<section id="put">
 <a name="put"></a>
 <h2>PUT<a class="headerlink" href="#put" title="Link to this heading">¶</a></h2>
<p>Replaces the value following a key, and returns the new value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">put <span class="rebarg">series</span> <span class="rebarg">key</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">any-block! map! port! object!</span>] (modified)
  key         [<span class="types">any-type!</span>] 
  value       [<span class="types">any-type!</span>] The new value (returned)
<span class="tit">REFINEMENTS:</span>
  /case       Perform a case-sensitive search
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="pwd">
 <a name="pwd"></a>
 <h2>PWD<a class="headerlink" href="#pwd" title="Link to this heading">¶</a></h2>
<p>Returns the current directory path.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">pwd</span></pre>

<h6>Description:</h6>
<p>
Note: Shell shortcut for <a href="#what-dir">what-dir</a>.
</p>

<div class="see-also">See also: <a href="#cd">cd</a>, <a href="#change-dir">change-dir</a>, <a href="#delete">delete</a>, <a href="#list-dir">list-dir</a>, <a href="#ls">ls</a>, <a href="#make-dir">make-dir</a>, <a href="#mkdir">mkdir</a>, <a href="#rm">rm</a>, <a href="#what-dir">what-dir</a></div>
</section>

<hr>
<section id="q">
 <a name="q"></a>
 <h2>Q<a class="headerlink" href="#q" title="Link to this heading">¶</a></h2>
<p>Note: Shell shortcut for <a href="#quit">quit</a>.</p>
</section>

<hr>
<section id="query">
 <a name="query"></a>
 <h2>QUERY<a class="headerlink" href="#query" title="Link to this heading">¶</a></h2>
<p>Returns information about target if possible.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">query <span class="rebarg">target</span> <span class="rebarg">field</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  target      [<span class="types">port! file! url! block! vector! date! handle! word!</span>] 
  field       [<span class="types">word! block! none! datatype!</span>] NONE will return valid modes for target type
<span class="tit">REFINEMENTS:</span>
  /mode       ** DEPRECATED **
</pre>

<h6>Description:</h6>
<p>
Its argument is an unopened port specification. The
size, date and status fields in the port specification
will be updated with the appropriate information if the
query succeeds.
</p>

<div class="see-also">See also: <a href="#open">open</a>, <a href="#update">update</a></div>
</section>

<hr>
<section id="quit">
 <a name="quit"></a>
 <h2>QUIT<a class="headerlink" href="#quit" title="Link to this heading">¶</a></h2>
<p>Stops evaluation and exits the interpreter.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">quit</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /return     Returns a value (to prior script or command shell)
   value       Note: use integers for command shell
  /now        Quit immediately
</pre>

<h6>Description:</h6>
<p>
You can call <a href="#quit">quit</a> to exit (terminate) your program at any point.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">time: 10:00
if time &gt; 12:00 [
    print "time for lunch"
    quit
]</code></pre></div><p>
Without refinements, <a href="#quit">quit</a> is a non-forceful exception (it will <a href="#throw">throw</a> a quit exception.) This behavior allows a parent program to stop the termination.
</p>
<p>
To force an immediate quit (no exception), use the /now refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if bad-data [quit/now]</code></pre></div><p>
You can also return an <span class="datatype">integer!</span> quit code to the operating system (shell) by using the <a href="#return">return</a> refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">quit/return 40</code></pre></div><p>
Note that not all operating systems environments may support this quit code.
</p>
<fieldset class="fset"><legend>Rarely used</legend>
<p>Most programs do not require <a href="#quit">quit</a>, and it can be problematic if your code is started by another REBOL program. Normally, when your program reaches the end, it will quit by itself. (If you want to prevent that behavior, use the -h command line option, or call <a href="#halt">halt</a> at the end of your code.)</p>
</fieldset>
<div class="see-also">See also: <a href="#exit">exit</a>, <a href="#halt">halt</a>, <a href="#q">q</a></div>
</section>

<hr>
<section id="quote">
 <a name="quote"></a>
 <h2>QUOTE<a class="headerlink" href="#quote" title="Link to this heading">¶</a></h2>
<p>Returns the value passed to it without evaluation.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">quote <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; quote foo
== foo</code></pre></div><p>
Without <a href="#quote">quote</a> it throws an error:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; foo

** Script error: foo has no value</code></pre></div>
</section>

<hr>
<section id="random">
 <a name="random"></a>
 <h2>RANDOM<a class="headerlink" href="#random" title="Link to this heading">¶</a></h2>
<p>Returns a random value of the same datatype; or shuffles series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">random <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        Maximum value of result (modified when series)
<span class="tit">REFINEMENTS:</span>
  /seed       Restart or randomize
  /secure     Returns a cryptographically secure random number
  /only       Pick a random value from a series
</pre>

<h6>Description:</h6>
<p>
The value passed can be used to restrict the range of
the random result. For integers random begins at one,
not zero, and is inclusive of the value given. (This
conforms to the indexing style used for all series
datatypes, allowing random to be used directly with
functions like PICK.)
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">loop 3 [print random 10]
1
5
3

lunch: ["Italian" "French" "Japanese" "American"]
print pick lunch random 4
American</code></pre></div><p>
If the given argument is a logic value, the result is actually the same as the result of the expression
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">even? random 2</code></pre></div><p>
Example
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">loop 4 [print random true]
false
false
false
true

loop 2 [print random 1:00:00]
0:12:20
0:48:22</code></pre></div><p>
For decimal value the function generates a uniformly distributed random number between zero (inclusive) and the given value (inclusive).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">loop 3 [print random 1.0]
0.209417212061865
0.878424991742667
0.93627033045037</code></pre></div><p>
Main properties:
</p>
<p>
<ol>
<li>the probability density in the interior points is the reciprocal of the given decimal VALUE argument</li>
<li>the probability density in the exterior points is 0.0</li>
<li>as specified by IEEE754, the bounds represent "close" interior well as "close" exterior real numbers. Therefore, the frequency of every bound corresponds to the length of the segment containing adjacent interior real values (real numbers, that are IEEE 754 - rounded to the value of the bound) multiplied by the interior density equal to the reciprocal of the given VALUE</li>
</ol>
RANDOM can also be used on all series datatypes:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print random "abcdef"
dbcafe

print random [1 2 3 4 5]
2 4 5 3 1</code></pre></div><p>
In this case RANDOM randomly shuffles the given series "in place", yielding the original series with the same elements, just shuffled.
To cut it down, you can use CLEAR:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">key: random "abcdefghijklmnopqrstuv0123456789"
clear skip key 6
print key
anfruk</code></pre></div><p>
Here's an example password generator. Add more partial words
to get more variations:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">syls: ["ca" "ru" "lo" "ek" "-" "." "!"]
print rejoin random syls
.!ru-ekcalo</code></pre></div><p>
To initialize the random number generator, you can seed it with a value (to repeat the sequence) or the current time to start a unique seed.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">random/seed 123

random/seed now</code></pre></div><p>
That last line is a good example to provide a fairly random
starting value for the random number generator.
</p>
<p>
The /SECURE variant uses SHA1() of a repeating pattern of the integer bytes (20 bytes total) and it produces cryptographically secure 64-bit random numbers. Cryptographical security means, that it is infeasible to compute the state of the generator from its output. If you don't need to make computing of the generator state infeasible (needed especially when you use the generator to generate passwords, challenges, etc. and want to comply to the FIPS security standards), it is more efficient to use the raw variant (without /SECURE refinement). Even in that case it is not feasible to compute the state, since the state of present generator consists of too many bits to be computable from the output.
</p>

<h6>Algorithm</h6><p>
The RANDOM function uses a random generator by Donald E. Knuth adjusted to generate 62-bit random integers. Thus, the maximal obtainable random number is 2 to the power of 62 = 4611686018427387904.
</p>
<p>
If the RANDOM function obtains 0 as an argument, it yields 0. If the argument is a positive integer, the RANDOM function uses rejection, rejecting all "raw randoms" that exceed the largest obtainable multiple of the given VALUE argument. This way, the uniformity of the distribution is assured. In case the given VALUE exceeds the biggest obtainable "raw random", we would have to reject every "raw random" number, so in that case an overflow error is caused (It certainly is an error expecting a bigger random, than the "raw random" maximum).
</p>
<p>
If the given VALUE is negative, then the generated random integers are in the interval VALUE <= R <= -1.</p>
Uniformly distributed random decimals are generated using the integer output of the Knuth's generator as follows:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">tt62: to integer! 2 ** 62
4611686018427387904

random-dec: func [x [decimal!]] [(to decimal! (random tt62) - 1) / tt62 * x]

random/seed 0
random 1.0
0.209417212061865

random/seed 0
random-dec 1.0
0.209417212061865</code></pre></div><p>
In case the given decimal VALUE is positive, the generated random deviates are uniformly distributed in the interval 0.0 <= R <= VALUE, i.e. including bounds.</p>
In case the given decimal VALUE is negative, the random deviates are uniformly distributed in the interval VALUE <= R <= 0.0.</p>
Sometimes we need to obtain a uniformly distributed random number R, such that 0.0 < R < 1.0 (i.e. a uniformly distributed random number in the given interval, excluding the bounds). We can get such an R rejecting the bounds as follows:</p>
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">random/seed 0
until [
    r: random 1.0
    all [
        r !== 0.0
        r !== 1.0
    ]
]
r
0.209417212061865</code></pre></div>
<div class="see-also">See also: <a href="#checksum">checksum</a>, <a href="#now">now</a></div>
</section>

<hr>
<section id="rc4">
 <a name="rc4"></a>
 <h2>RC4<a class="headerlink" href="#rc4" title="Link to this heading">¶</a></h2>
<p>Encrypt/decrypt data (modifies) using RC4 algorithm.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">rc4</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /key        Provided only for the first time to get stream HANDLE!
   crypt-key  [<span class="types">binary!</span>] Crypt key.
  /stream     
   ctx        [<span class="types">handle!</span>] Stream cipher context.
   data       [<span class="types">binary!</span>] Data to encrypt/decrypt.
</pre>
</section>

<hr>
<section id="read">
 <a name="read"></a>
 <h2>READ<a class="headerlink" href="#read" title="Link to this heading">¶</a></h2>
<p>Read from a file, URL, or other port.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">read <span class="rebarg">source</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  source      [<span class="types">port! file! url! block! word!</span>] 
<span class="tit">REFINEMENTS:</span>
  /part       Partial read a given number of units (source relative)
   length     [<span class="types">number!</span>] 
  /seek       Read from a specific position (source relative)
   index      [<span class="types">number!</span>] 
  /string     Convert UTF and line terminators to standard text string
  /binary     Preserves contents exactly
  /lines      Convert to block of strings (implies /string)
  /all        Response may include additional information (source relative)
</pre>

<h6>Description:</h6>
<p>
Using READ is the simplest way to get information from
a file or URL. This is a higher level port operation
that opens a port, reads some or all of the data, then
closes the port and returns the data that was read. 
When used on a file, or URL, the contents of the file,
or URL are returned as a string.
</p>
<p>
The /LINES refinement returns read content as a series 
of lines. One line is created for each line terminator
found in the read data.
</p>
<p>
The /PART refinement reads the specified number of 
elements from the file, URL, or port. Reading a file
or URL will read the specified number of characters.
Used with /LINES, it reads a specified number of 
lines.
</p>
<p>
See the User's Guide for more detailed explanation of
using READ and its refinements.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">write %rebol-test-file.r "text file"
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
write/append %matrix.avi to-binary "abcdefg"</code></pre></div>
<div class="see-also">See also: <a href="#close">close</a>, <a href="#load">load</a>, <a href="#open">open</a>, <a href="#save">save</a>, <a href="#write">write</a></div>
</section>

<hr>
<section id="rebcode?">
 <a name="rebcode?"></a>
 <h2>REBCODE?<a class="headerlink" href="#rebcode?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">rebcode? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="recycle">
 <a name="recycle"></a>
 <h2>RECYCLE<a class="headerlink" href="#recycle" title="Link to this heading">¶</a></h2>
<p>Recycles unused memory.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">recycle</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /off        Disable auto-recycling
  /on         Enable auto-recycling
  /ballast    Trigger for auto-recycle (memory used)
   size       [<span class="types">integer!</span>] 
  /torture    Constant recycle (for internal debugging)
</pre>

<h6>Description:</h6>
<p>
This function will force a garbage collection of unused words
and values found in memory. This function is not required or
recommened for most scripts because the system does it
automatically as necessary.
</p>
<p>
To disable garbage collection, you can specify /off refinement.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">recycle/off</code></pre></div><p>
To enable it again, use /on:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">recycle/on</code></pre></div><p>
Note that recently used values may not be immediately garbage
collected, even though they are no longer being referenced by
your program.
</p>

</section>

<hr>
<section id="reduce">
 <a name="reduce"></a>
 <h2>REDUCE<a class="headerlink" href="#reduce" title="Link to this heading">¶</a></h2>
<p>Evaluates expressions and returns multiple results.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">reduce <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
<span class="tit">REFINEMENTS:</span>
  /no-set     Keep set-words as-is. Do not set them.
  /only       Only evaluate words and paths, not functions
   words      [<span class="types">block! none!</span>] Optional words that are not evaluated (keywords)
  /into       Output results into a block with no intermediate storage
   out        [<span class="types">any-block!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#reduce">reduce</a> function evaluates multiple expressions and returns a block of results. This is one of the most useful functions in REBOL.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">values: reduce [1 + 2 3 + 4]
probe values
[3 7]</code></pre></div><p>
Compare this with <a href="#do">do</a>, which only returns the result of the last expression:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">values: do [1 + 2 3 + 4]
probe values
7</code></pre></div>
<h6>Part of other functions</h6><p>
The <a href="#reduce">reduce</a> function is important because it enables you to create blocks of expressions that are evaluated and passed to other functions. Some functions, like <a href="#print">print</a>, use <a href="#reduce">reduce</a> as part of their operation, as shown in the following example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print [1 + 2  3 + 4]
3 7</code></pre></div><p>
The <a href="#rejoin">rejoin</a>, <a href="#repend">repend</a>, <a href="#reform">reform</a>, <a href="#remold">remold</a> functions also use <a href="#reduce">reduce</a> as part of their operation, as shown in the following examples:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">rejoin ["example" 1 + 2]
example3

str: copy "example"
repend str [1 + 2] ; modifies (uses append)
example3

reform ["example 1 + 2]
example 3

remold ["example" 1 + 2]
["example" 3]</code></pre></div>
<h6>Ignored reduction</h6><p>
For convenience, expressions that are fully evaluated simply pass-through the <a href="#reduce">reduce</a> function.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">reduce 123
123

reduce "example"
example</code></pre></div><p>
This makes it possible to use <a href="#reduce">reduce</a> in cases where other datatypes may be passed. For example, here is a common function for building HTML strings that relies on this behavior:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">html: make string! 1000
emit: func [data] [repend html data]

emit "test... "
emit ["number is: " 10]
print html
test... number is: 10</code></pre></div>
<h6>Blocks with set-words</h6><p>
When you <a href="#reduce">reduce</a> blocks that contain set-words, those words will be set. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">a: 1
reduce [a: 2]
print a
2</code></pre></div><p>
There are times when you do not want this to occur. For example, if you're building a header for a file, you may want to leave the set-words alone.
</p>
<p>
The /no-set refinement can be used to handle this case.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">full-name: "Bob Smith"
reduce/no-set [name: full-name time: now + 10]
[name: "Bob Smith" time: 15-Aug-2010/16:10:50-7:00]</code></pre></div>
<h6>Memory usage for large blocks</h6><p>
For most blocks you don't need to worry about memory because REBOL's automatic storage manager will efficiently handle it; however, when building large block series with <a href="#reduce">reduce</a>, you can manage memory even more carefully.
</p>
<p>
For example, it is common to write:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">repend series [a b c]</code></pre></div><p>
which is shorthand for:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">append series reduce [a b c]</code></pre></div><p>
The evaluated results of a, b, and c are appended to the series.
</p>
<p>
If this is done a lot, a large number of temporary series are generated, which take memory and also must be garbage collected later.
</p>
<p>
The /into refinement helps optimize the situation:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">reduce/into [a b c] tail series</code></pre></div><p>
It requires no intermediate storage.
</p>

<h6>Common Problems</h6><p>
Although <a href="#reduce">reduce</a> will create a new outer block, all other series (blocks, strings, etc.) are referenced, not copied. If you modify those values, they will change in all blocks that reference them.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "name"
probe result: reduce [str]
["name"]

insert str "new-"
probe result
["new-name"]</code></pre></div><p>
You can see that it's the same string. To change that behavior use the <a href="#copy">copy</a> function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">result: reduce [copy str]</code></pre></div><p>
or, for blocks that contain multiple strings or other values:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">result: copy/deep reduce [str]</code></pre></div>
<div class="see-also">See also: <a href="#compose">compose</a>, <a href="#do">do</a>, <a href="#foreach">foreach</a></div>
</section>

<hr>
<section id="ref?">
 <a name="ref?"></a>
 <h2>REF?<a class="headerlink" href="#ref?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">ref? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id="refinement?">
 <a name="refinement?"></a>
 <h2>REFINEMENT?<a class="headerlink" href="#refinement?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">refinement? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print refinement? /any
true

print refinement? 'any
false</code></pre></div>
</section>

<hr>
<section id="reflect">
 <a name="reflect"></a>
 <h2>REFLECT<a class="headerlink" href="#reflect" title="Link to this heading">¶</a></h2>
<p>Returns specific details about a datatype.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">reflect <span class="rebarg">value</span> <span class="rebarg">field</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
  field       [<span class="types">word!</span>] Such as: spec, body, words, values, title
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; reflect object [a: 1 b: 2] 'words
== [a b]

&gt;&gt; reflect object [a: 1 b: 2] 'values
== [1 2]</code></pre></div><p>
Or used on function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; reflect :print 'words
== [value]

&gt;&gt; reflect :print 'title
== "Outputs a value followed by a line break."</code></pre></div>
<div class="see-also">See also: <a href="#body-of">body-of</a>, <a href="#spec-of">spec-of</a>, <a href="#title-of">title-of</a>, <a href="#types-of">types-of</a>, <a href="#values-of">values-of</a>, <a href="#words-of">words-of</a></div>
</section>

<hr>
<section id="reform">
 <a name="reform"></a>
 <h2>REFORM<a class="headerlink" href="#reform" title="Link to this heading">¶</a></h2>
<p>Forms a reduced block and returns a string.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">reform <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        Value to reduce and form
</pre>

<h6>Description:</h6>
<p>
Identical to FORM but reduces its argument first.
Spaces are inserted between each value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe reform ["the time is:" now/time]
"the time is: 17:47:54"

probe form ["the time is:" now/time]
"the time is: now/time"</code></pre></div>
<div class="see-also">See also: <a href="#combine">combine</a>, <a href="#form">form</a>, <a href="#join">join</a>, <a href="#mold">mold</a>, <a href="#rejoin">rejoin</a>, <a href="#remold">remold</a></div>
</section>

<hr>
<section id="register">
 <a name="register"></a>
 <h2>REGISTER<a class="headerlink" href="#register" title="Link to this heading">¶</a></h2>
<p>Register value in a system/catalog</p>

<h6>Usage:</h6>
<pre class="usage fs-6">register <span class="rebarg">name</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  name        [<span class="types">word! set-word! lit-word!</span>] Unique ID for the value in the catalog
  value       [<span class="types">struct!</span>] Value to be registered (so far only structs)
</pre>
</section>

<hr>
<section id="register-codec">
 <a name="register-codec"></a>
 <h2>REGISTER-CODEC<a class="headerlink" href="#register-codec" title="Link to this heading">¶</a></h2>
<p>Registers non-native codec to system/codecs and it's suffixes into system/catalog/file-types</p>

<h6>Usage:</h6>
<pre class="usage fs-6">register-codec <span class="rebarg">codec</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  codec       [<span class="types">block! object!</span>] Codec to register (should be based on system/standard/codec template)
</pre>
</section>

<hr>
<section id="rejoin">
 <a name="rejoin"></a>
 <h2>REJOIN<a class="headerlink" href="#rejoin" title="Link to this heading">¶</a></h2>
<p>Reduces and joins a block of values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">rejoin <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block!</span>] Values to reduce and join
</pre>

<h6>Description:</h6>
<p>
Similar to <a href="#join">join</a> but accepts only one argument, the
block (which will be reduced first). No spaces are
inserted between values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">rejoin ["time=" now/time]
time=17:47:54</code></pre></div><p>
Notice this important case:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">rejoin [&lt;a&gt; "test"]
&lt;atest&gt;</code></pre></div><p>
This is fine for lines like:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">rejoin [&lt;a href=&gt; "test.html"]
&lt;a href=test.html&gt;</code></pre></div><p>
But you can see it creates a problem in this case:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">rejoin [&lt;a href=test.html&gt; "test" &lt;/a&gt;]
&lt;a href=test.htmltest&lt;/a&gt;&gt;</code></pre></div><p>
If you want the result to be a <span class="datatype">string!</span>, use the <a href="#ajoin">ajoin</a> function instead.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">ajoin [&lt;a href=test.html&gt; "test" &lt;/a&gt;]
"&lt;a href=test.html&gt;test&lt;/a&gt;"</code></pre></div>
<div class="see-also">See also: <a href="#ajoin">ajoin</a>, <a href="#combine">combine</a>, <a href="#form">form</a>, <a href="#join">join</a>, <a href="#reform">reform</a></div>
</section>

<hr>
<section id="release">
 <a name="release"></a>
 <h2>RELEASE<a class="headerlink" href="#release" title="Link to this heading">¶</a></h2>
<p>Release internal resources of the handle. Returns true on success.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">release <span class="rebarg">handle</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  handle      [<span class="types">handle!</span>] 
</pre>
</section>

<hr>
<section id="remainder">
 <a name="remainder"></a>
 <h2>REMAINDER<a class="headerlink" href="#remainder" title="Link to this heading">¶</a></h2>
<p>Returns the remainder of first value divided by second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">remainder <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! vector!</span>] 
  value2      [<span class="types">scalar! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
If the second number is zero, an error will occur.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print remainder 123 10
3

print remainder 10 10
0

print remainder 10.2 10
0.1999999999999993</code></pre></div><p>
If the first value is positive, then the returned remainder is nonnegative.
</p>
<p>
If the first value is negative, then the returned remainder is nonpositive.
</p>

<div class="see-also">See also: <a href="#/">/</a>, <a href="#//">//</a></div>
</section>

<hr>
<section id="remold">
 <a name="remold"></a>
 <h2>REMOLD<a class="headerlink" href="#remold" title="Link to this heading">¶</a></h2>
<p>Reduces and converts a value to a REBOL-readable string.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">remold <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        The value to reduce and mold
<span class="tit">REFINEMENTS:</span>
  /only       For a block value, mold only its contents, no outer []
  /all        Mold in serialized format
  /flat       No indentation
  /part       Limit the length of the result
   limit      [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
Identical to MOLD, but reduces its argument first.
Spaces are inserted between each values in a block.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print remold ["the time is:" now/time]
["the time is:" 17:47:54]</code></pre></div>
<div class="see-also">See also: <a href="#form">form</a>, <a href="#mold">mold</a>, <a href="#reduce">reduce</a>, <a href="#reform">reform</a></div>
</section>

<hr>
<section id="remove">
 <a name="remove"></a>
 <h2>REMOVE<a class="headerlink" href="#remove" title="Link to this heading">¶</a></h2>
<p>Removes element(s); returns same position.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">remove <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port! bitset! none! map!</span>] At position (modified)
<span class="tit">REFINEMENTS:</span>
  /part       Removes multiple elements or to a given position
   range      [<span class="types">number! series! pair! char!</span>] 
  /key        Removes a key from map.
   key-arg    [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Removes a single value from the current position in any type of <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: copy "send it here"
remove str
print str
end it here</code></pre></div><p>
Combine it with other functions to remove a value at a specific index:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">remove find str "it"
print str
end t here</code></pre></div><p>
You can remove any number of values with the /PART refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: copy "send it here"
remove/part str 3
print str
d it here</code></pre></div><p>
The PART refinement also accepts an index of the series being removed form. It must be the same series.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">remove/part str find str "here"
print str
here</code></pre></div><p>
An example using a block!:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">blk: copy [red green blue]
remove next blk
probe blk
[red blue]</code></pre></div>
<div class="see-also">See also: <a href="#append">append</a>, <a href="#change">change</a>, <a href="#clear">clear</a>, <a href="#insert">insert</a>, <a href="#sort">sort</a></div>
</section>

<hr>
<section id="remove-each">
 <a name="remove-each"></a>
 <h2>REMOVE-EACH<a class="headerlink" href="#remove-each" title="Link to this heading">¶</a></h2>
<p>Removes values for each block that returns truthy value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">remove-each <span class="rebarg">word</span> <span class="rebarg">data</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word! block!</span>] Word or block of words to set each time (local)
  data        [<span class="types">series! map!</span>] The series to traverse (modified)
  body        [<span class="types">block!</span>] Block to evaluate (return TRUE to remove)
<span class="tit">REFINEMENTS:</span>
  /count      Returns removal count
</pre>

<h6>Description:</h6>
<p>
The <a href="#remove-each">remove-each</a> function is a high performance method of removing specific elements from a series. It is similar to <a href="#foreach">foreach</a> but will remove one or more values depending on the result of the evaluated block.
</p>
<p>
In this example, <a href="#remove-each">remove-each</a> is used to remove all strings from the block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">values: [12 "abc" test 5 "de" 10:30]
remove-each value values [string? value]
probe values
[12 test 5 10:30]</code></pre></div><p>
Here, all integer values greater than 11 are removed:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">values: [12 "abc" test 5 "de" 10:30]
remove-each value values [all [integer? value value &gt; 11]]
probe values
["abc" test 5 "de" 10:30]</code></pre></div>
<h6>Multiple Elements</h6><p>
The <a href="#remove-each">remove-each</a> function can be used on multiple elements, just as <a href="#foreach">foreach</a> does.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">movies: [
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
removed</code></pre></div><p>
This example also shows that the evaluated block may contain any other expressions as long as the last one returns true for removed values.
</p>
<p>
Also, notice here the way <a href="#if">if</a> is used for its return value.
</p>

<div class="see-also">See also: <a href="#foreach">foreach</a>, <a href="#map-each">map-each</a>, <a href="#remove">remove</a></div>
</section>

<hr>
<section id="rename">
 <a name="rename"></a>
 <h2>RENAME<a class="headerlink" href="#rename" title="Link to this heading">¶</a></h2>
<p>Rename a file.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">rename <span class="rebarg">from</span> <span class="rebarg">to</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  from        [<span class="types">port! file! url! block!</span>] 
  to          [<span class="types">port! file! url! block!</span>] 
</pre>

<h6>Description:</h6>
<p>
Renames a file within the same directory:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">write %testfile now
rename %testfile %remove.me
probe read %remove.me
delete %remove.me
write</code></pre></div><p>
This function cannot be used to move a file from 
one directory to another.
</p>

<div class="see-also">See also: <a href="#delete">delete</a>, <a href="#list-dir">list-dir</a>, <a href="#what-dir">what-dir</a></div>
</section>

<hr>
<section id="repeat">
 <a name="repeat"></a>
 <h2>REPEAT<a class="headerlink" href="#repeat" title="Link to this heading">¶</a></h2>
<p>Evaluates a block a number of times or over a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">repeat <span class="rebarg">word</span> <span class="rebarg">value</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word!</span>] Word to set each time
  value       [<span class="types">number! series! pair! none!</span>] Maximum number or series to traverse
  body        [<span class="types">block!</span>] Block to evaluate each time
</pre>

<h6>Description:</h6>
<p>
The <a href="#repeat">repeat</a> function is an easy way to repeat the evaluation of a block with a loop counter.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">repeat num 3 [print num]
1
2
3</code></pre></div><p>
Here the num counter begins at one and continues up to and including the integer value given.
</p>

<h6>Other Notes</h6><ul>
<li>Negative or zero loop counts do not evaluate the block.</li>
<li>If a <span class="datatype">decimal!</span> count is used, it will be truncated to a lower integer value.</li>
<li>The <a href="#break">break</a> function can be used to stop the loop at any time.</li>
<li>The <a href="#loop">loop</a> function is similar to <a href="#repeat">repeat</a>, except that it has no loop counter. If you don't need the counter, <a href="#loop">loop</a> is more efficient.</li>
<li>The evaluated block is deep copied and rebound (see <a href="#bind">bind</a> ) to a new context that holds the loop variable. For large nested repeat loops, you will want to consider this overhead. An alternative is to use <a href="#while">while</a>, <a href="#until">until</a>, or <a href="#loop">loop</a> which do not require the copy and bind.</li>
</ul>
<h6>In question...</h6><p>
If the value is a series, then the loop will repeat for each element of the series.
</p>
<p>
However, there's currently a difference between R2 and R3. In R2, if the value is a series, then the word holds the first value of each element of the series. In R3 it holds just the indexed series.
</p>
<p>
Editor note: Determine if this is intentional
</p>

<div class="see-also">See also: <a href="#for">for</a>, <a href="#forall">forall</a>, <a href="#foreach">foreach</a>, <a href="#forskip">forskip</a>, <a href="#loop">loop</a>, <a href="#until">until</a>, <a href="#while">while</a></div>
</section>

<hr>
<section id="repend">
 <a name="repend"></a>
 <h2>REPEND<a class="headerlink" href="#repend" title="Link to this heading">¶</a></h2>
<p>Appends a reduced value to a series and returns the series head.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">repend <span class="rebarg">series</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! port! map! gob! object! bitset!</span>] Series at point to insert (modified)
  value        The value to insert
<span class="tit">REFINEMENTS:</span>
  /part       Limits to a given length or position
   length     [<span class="types">number! series! pair!</span>] 
  /only       Appends a block value as a block
  /dup        Duplicates the insert a specified number of times
   count      [<span class="types">number! pair!</span>] 
</pre>

<h6>Description:</h6>
<p>
REPEND stands for REDUCE APPEND. It performs the same operation
as APPEND (inserting elements at the tail of a series) but
Reduces the block of inserted elements first. Just like APPEND,
REPEND returns the head of the series.
</p>
<p>
For example, writing:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">numbers: [1 2 3]
probe repend numbers [2 + 2 2 + 3 3 + 3]
[1 2 3 4 5 6]</code></pre></div><p>
is the same as writing:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">numbers: [1 2 3]
probe append numbers reduce [2 + 2 2 + 3 3 + 3]
[1 2 3 4 5 6]</code></pre></div><p>
REPEND is very useful when you want to add to a series elements
that need to be evaluated first. The example below creates a
list of all the .r files in the current directory, along with
their sizes and modification dates.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: copy []
foreach file load %. [
    if %.r = suffix? file [
        repend data [file size? file modified? file]
    ]
]
probe data
[%build-docs.r 7915 13-Feb-2009/0:03:17.078 %bulk-modify.r 4210 7-Feb-2009/17:20:06.906 %cgi.r 5125 12-Feb-2009/20:54:51.578 %convert-orig.r 1112 7-Feb-2009/17:20:06.906 %emit-html.r 10587 13-Feb-2009/0:09:38.875 %eval-examples.r 2545 13-Feb-2009/1:46:59.765 %fix-args.r 416 13-Feb-2009/0:41:11.296 %funcs.r 1133 12-Feb-2009/18:54:32.875 %merge-funcs.r 1318 13-Feb-2009/0:42:03.718 %replace.r 197 7-Feb-2009/16:56:23 %scan-doc.r 3429 13-Feb-2009/0:05:33.062 %scan-titles.r 4402 12-Feb-2009/16:51:42.687 %strip-title.r 274 7-Feb-2009/17:20:06.953]</code></pre></div><p>
When used with strings, repend is a useful way to join values.
The example below is a common method of generating HTML web
page code:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">html: copy "&lt;html&gt;&lt;body&gt;"
repend html [
    "Date is: " now/date &lt;P&gt;
    "Time is: " now/time &lt;P&gt;
    "Zone is: " now/zone &lt;P&gt;
    &lt;/body&gt;&lt;/html&gt;
]
print html
&lt;html&gt;&lt;body&gt;Date is: 12-Feb-2009&lt;P&gt;Time is: 17:47:54&lt;P&gt;Zone is: -8:00&lt;P&gt;&lt;/body&gt;&lt;/html&gt;</code></pre></div>
<div class="see-also">See also: <a href="#append">append</a>, <a href="#insert">insert</a>, <a href="#join">join</a>, <a href="#reduce">reduce</a></div>
</section>

<hr>
<section id="replace">
 <a name="replace"></a>
 <h2>REPLACE<a class="headerlink" href="#replace" title="Link to this heading">¶</a></h2>
<p>Replaces a search value with the replace value within the target series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">replace <span class="rebarg">target</span> <span class="rebarg">search</span> <span class="rebarg">replace</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  target      [<span class="types">series!</span>] Series to replace within (modified)
  search       Value to be replaced (converted if necessary)
  replace      Value to replace with (called each time if a function)
<span class="tit">REFINEMENTS:</span>
  /all        Replace all occurrences
  /case       Case-sensitive replacement
  /tail       Return target after the last replacement position
</pre>

<h6>Description:</h6>
<p>
Searches target block or series for specified data and 
replaces it with data from the replacement block or 
series. Block elements may be of any datatype.
</p>
<p>
The /ALL refinement replaces all occurrences of the 
searched data in the target block or series.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "a time a spec a target"
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
1 2 3 four five six 7 8 9</code></pre></div>
<div class="see-also">See also: <a href="#change">change</a>, <a href="#insert">insert</a>, <a href="#remove">remove</a></div>
</section>

<hr>
<section id="request-dir">
 <a name="request-dir"></a>
 <h2>REQUEST-DIR<a class="headerlink" href="#request-dir" title="Link to this heading">¶</a></h2>
<p>Asks user to select a directory and returns full directory path (or block of paths).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">request-dir</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /title      Change heading on request
   text       [<span class="types">string!</span>] 
  /dir        Set starting directory
   name       [<span class="types">file!</span>] 
  /keep       Keep previous directory path
</pre>
</section>

<hr>
<section id="request-file">
 <a name="request-file"></a>
 <h2>REQUEST-FILE<a class="headerlink" href="#request-file" title="Link to this heading">¶</a></h2>
<p>Asks user to select a file and returns full file path (or block of paths).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">request-file</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /save       File save mode
  /multi      Allows multiple file selection, returned as a block
  /file       Default file name or directory
   name       [<span class="types">file!</span>] 
  /title      Window title
   text       [<span class="types">string!</span>] 
  /filter     Block of filters (filter-name filter)
   list       [<span class="types">block!</span>] 
</pre>

<h6>Description:</h6>
<p>
Opens the standard operating system file requester to allow the user to select one or more files.
</p>

<h6>Details</h6>
<h7>Normal usage for read or load</h7><p>
The line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">file: request-file</code></pre></div><p>
will open the file requester and return a single file name as a full file path. This is normally used to read or load files.
</p>
<p>
If the user clicks CANCEL or closes the file requestor, a NONE is returned.
</p>

<h7>For saving or writing files</h7><p>
To open the file requester to save a file:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">file: request-file/save</code></pre></div><p>
This will change the text of the window to indicate that a save (write) will be done.
</p>

<h7>Specifying a default file or directory</h7><p>
A default name can be provided for the file:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">file: request-file/file %test.txt</code></pre></div><p>
This also works with the /save option, and a full path can be provided, in which case the requester will show the directory where the file will be found.
</p>
<p>
In addition, just a directory can be used:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">file: request-file/file %/c/data/files/</code></pre></div><p>
Be sure to include the terminating slash to indicate a directory. Otherwise it will be treated as a file.
</p>

<h7>Allowing multiple file selection</h7><p>
To allow the selection of multiple files at the same time:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">files: request-file/multi

foreach file files [print file]</code></pre></div><p>
The result is returned as a block, and each file within the block is a full path.
</p>

<h7>Filtering file views</h7><p>
You can also provide file list filters to show only specific files. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">file: request-file/filter [
    "REBOL Scripts" "*.r"
    "Text files" "*.txt"
]</code></pre></div>
<h7>Setting the window title</h7><p>
The /title refinement lets you modify the window title for the file requester to help make it more clear to users.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">file: request-file/save/title "Save your data file"
either file [save file data] [print "data not saved"]</code></pre></div><fieldset class="fset"><legend>Changes from R2</legend>
<p>This function contains minor changes and cleanup relative to R2. Note that the default operation (with no refinements) returns a single file, not a block. This is the most common form of operation, so it is made standard here. In addition, the /multi option returns a block of full file paths, not a directory path followed by relative files.</p>
</fieldset>
<div class="see-also">See also: <a href="#to-local-file">to-local-file</a>, <a href="#to-rebol-file">to-rebol-file</a></div>
</section>

<hr>
<section id="request-password">
 <a name="request-password"></a>
 <h2>REQUEST-PASSWORD<a class="headerlink" href="#request-password" title="Link to this heading">¶</a></h2>
<p>Asks user for input without echoing, and the entered password is not stored in the command history.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">request-password</span></pre>
</section>

<hr>
<section id="resize">
 <a name="resize"></a>
 <h2>RESIZE<a class="headerlink" href="#resize" title="Link to this heading">¶</a></h2>
<p>Resizes an image to the given size.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">resize <span class="rebarg">image</span> <span class="rebarg">size</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  image       [<span class="types">image!</span>] Image to resize
  size        [<span class="types">pair! percent! integer!</span>] Size of the new image (integer value is used as width)
<span class="tit">REFINEMENTS:</span>
  /filter     Using given filter type (default is Lanczos)
   name       [<span class="types">word! integer!</span>] One of: system/catalog/filters
  /blur       
   factor     [<span class="types">number!</span>] The blur factor where > 1 is blurry, < 1 is sharp
</pre>
</section>

<hr>
<section id="resolve">
 <a name="resolve"></a>
 <h2>RESOLVE<a class="headerlink" href="#resolve" title="Link to this heading">¶</a></h2>
<p>Copy context by setting values in the target from those in the source.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">resolve <span class="rebarg">target</span> <span class="rebarg">source</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  target      [<span class="types">any-object!</span>] (modified)
  source      [<span class="types">any-object!</span>] 
<span class="tit">REFINEMENTS:</span>
  /only       
   from       [<span class="types">block! integer!</span>] Only specific words (exports) or new words in target (index to tail)
  /all        Set all words, even those in the target that already have a value
  /extend     Add source words to the target if necessary
</pre>

<h6>Description:</h6>
<p>
The <a href="#resolve">resolve</a> function is used to merge values from one context into another but avoids replacing existing values.
</p>
<p>
It is used mainly to support runtime environments, where newly exported functions must be merged into an existing lib context. Because lib can become quite large, performance must be optimized, which is the reason why <a href="#resolve">resolve</a> is a native function.
</p>

<h7>Basic Concept</h7><p>
This example will help to show the basic concept:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">obj1: object [a: 10]
obj2: object [b: 20]
append obj1 'b
resolve obj1 obj2
print obj1
a: 10
b: 20</code></pre></div><p>
But notice:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">obj1: object [a: 10]
obj2: object [a: 30 b: 20]
append obj1 'b
resolve obj1 obj2
print obj1
a: 10
b: 20</code></pre></div><p>
So, <a href="#resolve">resolve</a> has no affect on values that have already been set in the target context.
</p>
<p>
Note that protected words will not be modified, they are ignored. No error occurs.
</p>

<h7>Refinements</h7><table class="doctable">
<tr><td valign="top" nowrap><b>/only</b></td><td valign="top" width="95%">only affect word values that are provided in a block argument that follows this refinement. In addition, this refinement also supports a special optimization where you can indicate the index of the starting point for changes. That is useful with large contexts such as lib and others.
</td></tr>
<tr><td valign="top" nowrap><b>/all</b></td><td valign="top" width="95%">forces <a href="#resolve">resolve</a> to change all values, not just those that are unset. This is similar to <a href="#append">append</a> on an <span class="datatype">object!</span> except that the source is an object, not a block.
</td></tr>
<tr><td valign="top" nowrap><b>/extend</b></td><td valign="top" width="95%">any words not found in the target context will be added. This eliminates the <a href="#append">append</a> step that was shown above (or a similar <a href="#bind">bind</a> step). This refinement optimizes such operations.
</td></tr>
</table>
</section>

<hr>
<section id="return">
 <a name="return"></a>
 <h2>RETURN<a class="headerlink" href="#return" title="Link to this heading">¶</a></h2>
<p>Returns a value from a function.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">return <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Exits the current function immediately, returning
a value as the result of the function. To return no
value, use the EXIT function.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">fun: make function! [this-time] [
    return either this-time &gt;= 12:00 ["after noon"][
        "before noon"]
]
print fun 9:00

print fun 18:00</code></pre></div>
<div class="see-also">See also: <a href="#break">break</a>, <a href="#catch">catch</a>, <a href="#exit">exit</a></div>
</section>

<hr>
<section id="reverse">
 <a name="reverse"></a>
 <h2>REVERSE<a class="headerlink" href="#reverse" title="Link to this heading">¶</a></h2>
<p>Reverses the order of elements; returns at same position.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">reverse <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! tuple! pair!</span>] At position (modified)
<span class="tit">REFINEMENTS:</span>
  /part       Limits to a given length or position
   range      [<span class="types">number! series!</span>] 
</pre>

<h6>Description:</h6>
<p>
Reverses the order of elements in a series or tuple.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">blk: [1 2 3 4 5 6]
reverse blk
print blk
6 5 4 3 2 1</code></pre></div><p>
The /PART refinement reverses the specified number 
of elements from the current index forward. If the 
number of elements specified exceeds the number of 
elements left in the series or tuple, the elements from 
the current index to the end will be reversed.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">text: "It is possible to reverse one word in a sentence."
reverse/part (find text "reverse") (length? "reverse")
print text
It is possible to esrever one word in a sentence.</code></pre></div><p>
Note that reverse returns the starting position it was
given. (This change was made to newer versions.)
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">blk: [1 2 3 4 5 6]
print reverse/part blk 4
4 3 2 1 5 6</code></pre></div><p>
Reverse also works for pairs and tuples:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print reverse 10x20
print reverse 1.2.3
3.2.1</code></pre></div><p>
For tuple values the current index cannot be moved so the 
current index is always the beginning of the tuple.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print reverse 1.2.3.4
4.3.2.1

print reverse/part 1.2.3.4 2
4.3.2.1</code></pre></div>
<div class="see-also">See also: <a href="#find">find</a>, <a href="#insert">insert</a>, <a href="#replace">replace</a>, <a href="#sort">sort</a></div>
</section>

<hr>
<section id="reword">
 <a name="reword"></a>
 <h2>REWORD<a class="headerlink" href="#reword" title="Link to this heading">¶</a></h2>
<p>Make a string or binary based on a template and substitution values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">reword <span class="rebarg">source</span> <span class="rebarg">values</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  source      [<span class="types">any-string! binary!</span>] Template series with escape sequences
  values      [<span class="types">map! object! block!</span>] Keyword literals and value expressions
<span class="tit">REFINEMENTS:</span>
  /case       Characters are case-sensitive
  /only       Use values as-is, do not reduce the block, insert block values
  /escape     Choose your own escape char(s) or [begin end] delimiters
   char       [<span class="types">char! any-string! binary! block! none!</span>] Default "$"
  /into       Insert into a buffer instead (returns position after insert)
   output     [<span class="types">any-string! binary!</span>] The buffer series (modified)
</pre>

<h6>Description:</h6>
<p>
This is a general substitution function useful for building web pages, form letters, and other documents.
</p>

<h6>Work In Process</h6><p>
The block substitution abilities are still pending but string substitution works well now.
</p>

<div class="see-also">See also: <a href="#compose">compose</a>, <a href="#replace">replace</a></div>
</section>

<hr>
<section id="rgb-to-hsv">
 <a name="rgb-to-hsv"></a>
 <h2>RGB-TO-HSV<a class="headerlink" href="#rgb-to-hsv" title="Link to this heading">¶</a></h2>
<p>Converts RGB value to HSV (hue, saturation, value)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">rgb-to-hsv <span class="rebarg">rgb</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  rgb         [<span class="types">tuple!</span>] 
</pre>
</section>

<hr>
<section id="rm">
 <a name="rm"></a>
 <h2>RM<a class="headerlink" href="#rm" title="Link to this heading">¶</a></h2>
<p>Send port a delete request.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">rm <span class="rebarg">port</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  port        [<span class="types">port! file! url! block!</span>] 
</pre>

<h6>Description:</h6>
<p>
Note: Shell shortcut for <a href="#delete">delete</a>.
</p>

<div class="see-also">See also: <a href="#cd">cd</a>, <a href="#change-dir">change-dir</a>, <a href="#delete">delete</a>, <a href="#list-dir">list-dir</a>, <a href="#ls">ls</a>, <a href="#make-dir">make-dir</a>, <a href="#mkdir">mkdir</a>, <a href="#pwd">pwd</a>, <a href="#what-dir">what-dir</a></div>
</section>

<hr>
<section id="round">
 <a name="round"></a>
 <h2>ROUND<a class="headerlink" href="#round" title="Link to this heading">¶</a></h2>
<p>Rounds a numeric value; halves round up (away from zero) by default.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">round <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number! pair! money! time!</span>] The value to round
<span class="tit">REFINEMENTS:</span>
  /to         Return the nearest multiple of the scale parameter
   scale      [<span class="types">number! money! time!</span>] Must be a non-zero value (result will be of this type)
  /even       Halves round toward even results
  /down       Round toward zero, ignoring discarded digits. (truncate)
  /half-down  Halves round toward zero
  /floor      Round in negative direction
  /ceiling    Round in positive direction
  /half-ceiling Halves round in positive direction
</pre>

<h6>Description:</h6>
<p>
"Rounding is meant to loose precision in a controlled way." -- Volker Nitsch
</p>
<p>
The <a href="#round">round</a> function is quite flexible. With the various refinements
and the scale option, you can easily round in various ways. Most of the
refinements are mutually exclusive--that is, you should use only one of
them--the /to refinement is an obvious exception; it can be combined 
with any other refinement.
</p>
<p>
By default, <a href="#round">round</a> returns the nearest integer, with halves rounded up (away 
from zero).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe round 1.4999
1

probe round 1.5
2

probe round -1.5
-2</code></pre></div><p>
If the result of the rounding operation is a number! with no decimal component, 
and the SCALE value is not time! or money!, an integer will be returned. This 
makes it easy to use the result of ROUND directly with iterator functions such
as LOOP and REPEAT.
</p>
<p>
The /TO refinment controls the "precision" of the rounding. That is, the result
will be a multiple of the SCALE parameter. In order to round to a given number
of decimal places, you don't pass in the number of decimal places, but rather 
the "level of precision" they represent. For example, to round to two decimal
places, often used for money values, you would do this:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe round/to $1.333 .01
$0.5558830792256812207833088</code></pre></div><p>
To round to the nearest 1/8, often used for interest rates, you would do this:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe round/to 1.333 .125
1.375</code></pre></div><p>
To round to the nearst 1K increment (e.g. 1024 bytes):
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe round/to 123'456 1024
123904</code></pre></div><p>
If the /TO refinement is used, and SCALE is a time! or money! value, the result 
will be coerced to that type. If SCALE is not used, or is not a time! or money! 
value, the datatype of the result will be the same as the valued being rounded.
</p>
<p>
The /EVEN refinement is designed to reduce bias when rounding large groups of
values. It is sometimes called Banker's rounding, or statistical rounding. For 
cases where the final digit of a number is 5 (e.g. 1.5 or 15), the previous 
digit will be rounded to an even result (2, 4, etc.).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">repeat i 10 [val: i + .5 print [val round/even val]]
10.5 10

repeat i 10 [val: i * 10 + 5 print [val round/even/to val 10]]
105 100</code></pre></div><p>
The /DOWN refinement rounds toward zero, ignoring discarded digits. It is often
called "truncate".
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe round/down 1.999
1

probe round/down -1.999
-1

probe round/down/to 1999 1000
1000

probe round/down/to 1999 500
1500</code></pre></div><p>
The /HALF-DOWN refinement causes halves to round toward zero; by default they are
rounded up.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe round/half-down 1.5
1

probe round/half-down -1.5
-1

probe round/half-down 1.50000000001
2

probe round/half-down -1.50000000001
-2</code></pre></div><p>
The /HALF-CEILING refinement causes halves to round in a positive direction; by 
default they are rounded up (away from zero). This works like the default 
behavior for positive values, but is not the same for negative values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe round -1.5
-2

probe round/half-ceiling -1.5
-1</code></pre></div><p>
/FLOOR causes numbers with any decimal component to be rounded in a negative 
direction. It works like /DOWN for positive numbers, but not for negative numbers.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">round/floor 1.999

round/floor -1.01

round/floor -1.00000000001</code></pre></div><p>
/CEILING is the reverse of /FLOOR; numbers with any decimal component are rounded
in a positive direction.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">round/ceiling 1.01

round/ceiling 1.0000000001

round/ceiling -1.999</code></pre></div><p>
If you are rounding extremely large numbers (e.g. 562'949'953'421'314), or using
very high precision decimal values (e.g. 13 or more decimal places), you may run
up against REBOL's native limits for values and its internal rounding rules. The
ROUND function is a mezzanine and has no control over that behavior.
</p>
<p>
Sometimes, it might appear that ROUND is doing something strange, so before 
submitting a bug to RAMBO, think about what you're actually asking it to do. For 
example, look at the results from this piece of code:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">repeat i 10 [
    scale: .9 + (i * .01) 
    print [scale  round/down/to 10.55 scale]
]
1.0 10.0</code></pre></div><p>
The results approach 10.55 for values from 0.91 to 0.95, but then jump back when 
using values in the range 0.96 to 0.99. Those are the expected results, because 
you're truncating, that is, truncating to the nearest multiple of SCALE.
</p>
<p>
The design and development of the ROUND function involved many members 
of the REBOL community. There was much debate about the interface (one
function with refinement versus individual functions for each rounding
type, what words to use for parameter names, behavior with regards to
type coercion).
</p>

<div class="see-also">See also: <a href="#//">//</a>, <a href="#mod">mod</a>, <a href="#modulo">modulo</a>, <a href="#remainder">remainder</a></div>
</section>

<hr>
<section id="rsa">
 <a name="rsa"></a>
 <h2>RSA<a class="headerlink" href="#rsa" title="Link to this heading">¶</a></h2>
<p>Encrypt, decrypt, sign, or verify data using the RSA cryptosystem. Only one of the action refinements may be used per call.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">rsa <span class="rebarg">rsa-key</span> <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  rsa-key     [<span class="types">handle!</span>] RSA context created via rsa-init
  data        [<span class="types">binary! any-string!</span>] Input data or ciphertext
<span class="tit">REFINEMENTS:</span>
  /encrypt    Encrypt with public key (PKCS#1 v1.5 or RSAES-OAEP if /oaep)
  /decrypt    Decrypt with private key (PKCS#1 v1.5 or RSAES-OAEP if /oaep)
  /sign       Sign with private key
  /verify     Verify with public key (returns TRUE or FALSE)
   signature  [<span class="types">binary!</span>] Signature for /verify
  /hash       Specify digest algorithm (for sign/verify)
   algorithm  [<span class="types">word! none!</span>] Hash algorithm (e.g. SHA256) or NONE
  /oaep       Enable RSAES-OAEP for encrypt/decrypt
  /pss        Enable RSASSA-PSS for sign/verify
</pre>
</section>

<hr>
<section id="rsa-init">
 <a name="rsa-init"></a>
 <h2>RSA-INIT<a class="headerlink" href="#rsa-init" title="Link to this heading">¶</a></h2>
<p>Creates a context which is than used to encrypt or decrypt data using RSA</p>

<h6>Usage:</h6>
<pre class="usage fs-6">rsa-init <span class="rebarg">n</span> <span class="rebarg">e</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  n           [<span class="types">binary!</span>] Modulus
  e           [<span class="types">binary!</span>] Public exponent
<span class="tit">REFINEMENTS:</span>
  /private    Init also private values
   d          [<span class="types">binary!</span>] Private exponent
   p          [<span class="types">binary!</span>] Prime number 1
   q          [<span class="types">binary!</span>] Prime number 2
</pre>
</section>

<hr>
<section id="same?">
 <a name="same?"></a>
 <h2>SAME?<a class="headerlink" href="#same?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are identical.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">same? <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns TRUE if the values are identical objects, not
just in value. For example, a TRUE would be returned if
two strings are the same string (occupy the same
location in memory). Returns FALSE for all other
values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">a: "apple"
b: a
print same? a b
true

print same? a "apple"
false</code></pre></div>
<div class="see-also">See also: <a href="#=?">=?</a>, <a href="#equal?">equal?</a></div>
</section>

<hr>
<section id="save">
 <a name="save"></a>
 <h2>SAVE<a class="headerlink" href="#save" title="Link to this heading">¶</a></h2>
<p>Saves a value, block, or other data to a file, URL, binary, or string.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">save <span class="rebarg">where</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  where       [<span class="types">file! url! binary! string! none!</span>] Where to save (suffix determines encoding)
  value        Value(s) to save
<span class="tit">REFINEMENTS:</span>
  /header     Provide a REBOL header block (or output non-code datatypes)
   header-data [<span class="types">block! object! logic!</span>] Header block, object, or TRUE (header is in value)
  /all        Save in serialized format
  /length     Save the length of the script content in the header
  /compress   Save in a compressed format or not
   method     [<span class="types">logic! word!</span>] true = compressed, false = not, 'script = encoded string
</pre>

<h6>Description:</h6>
<p>
The <a href="#save">save</a> function is used to save REBOL code and data to a file, upload it to a URL, or store it into a local string.
</p>
<p>
When saving to a file or URL, the output of this function is always UTF-8 (an Unicode encoded format where ASCII is normal, but other characters are encoded.)
</p>
<p>
The format of the resulting output depends on what you need. The <a href="#save">save</a> function is designed to allow simple values to be easily saved to be loaded with <a href="#load">load</a> later:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">save %date.r now
load %date.r
26-Feb-2009/13:06:15-8:00</code></pre></div><p>
But, it also allows complex more complex data to be saved:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">save %data.r reduce ["Data" 1234 %filename now/time]
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
...</code></pre></div><p>
In general, <a href="#save">save</a> performs the appropriate conversion and formatting to preserve datatypes. For instance, if the value is a REBOL block, it will be saved as a REBOL script that, when loaded, will be identical.
</p>
<p>
Editor note: saving /all
</p>
<p>
Editor note: saving with headers
Note: Users must take care in how saved data is loaded. More on this below.
</p>

<div class="see-also">See also: <a href="#load">load</a>, <a href="#mold">mold</a>, <a href="#write">write</a></div>
</section>

<hr>
<section id="scalar?">
 <a name="scalar?"></a>
 <h2>SCALAR?<a class="headerlink" href="#scalar?" title="Link to this heading">¶</a></h2>
<p>Return TRUE if value is any type of scalar.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">scalar? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Description is needed.
</p>

</section>

<hr>
<section id="script?">
 <a name="script?"></a>
 <h2>SCRIPT?<a class="headerlink" href="#script?" title="Link to this heading">¶</a></h2>
<p>Checks file, url, or string for a valid script header.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">script? <span class="rebarg">source</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  source      [<span class="types">file! url! binary! string!</span>] 
</pre>

<h6>Description:</h6>
<p>
If the header is found, the script string will be returned
as of that point. If not found, then NONE is returned.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print either script? %file.txt ["found"]["not found"]</code></pre></div>
</section>

<hr>
<section id="second">
 <a name="second"></a>
 <h2>SECOND<a class="headerlink" href="#second" title="Link to this heading">¶</a></h2>
<p>Returns the second value of a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">second <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
An error will occur if no value is found. Use the PICK
function to avoid this error.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print second "REBOL"
E

print second [11 22 33 44 55 66]
22

print second 12-jun-1999
6

print second 199.4.80.1
4

print second 12:34:56.78
34</code></pre></div>
<div class="see-also">See also: <a href="#fifth">fifth</a>, <a href="#first">first</a>, <a href="#fourth">fourth</a>, <a href="#pick">pick</a>, <a href="#third">third</a></div>
</section>

<hr>
<section id="secure">
 <a name="secure"></a>
 <h2>SECURE<a class="headerlink" href="#secure" title="Link to this heading">¶</a></h2>
<p>Set security policies (use SECURE help for more information).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">secure <span class="rebarg">policy</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  policy      [<span class="types">word! lit-word! block! unset!</span>] Set single or multiple policies (or HELP)
</pre>

<h6>Description:</h6>
<p>
The <a href="#secure">secure</a> function controls file, network, evaluation, and all other external access and related policies.
</p>
<p>
The function uses a simple dialect to specify security sandboxes and other options that allow or deny access. You can set different security levels and multiple sandboxes for networking and specific files and directories.
</p>

<h6>What can be controlled</h6><p>
The <a href="#secure">secure</a> function gives you control over policies for:
</p>
<table class="doctable">
<tr><td valign="top" nowrap><b>file</b></td><td valign="top" width="95%">file read, write, and directory creation and listing
</td></tr>
<tr><td valign="top" nowrap><b>net</b></td><td valign="top" width="95%">read and write access to the network interfaces
</td></tr>
<tr><td valign="top" nowrap><b>eval</b></td><td valign="top" width="95%">limit the number of evaluation cycles allowed (always quits)
</td></tr>
<tr><td valign="top" nowrap><b>memory</b></td><td valign="top" width="95%">limit the amount of memory used (always quits)
</td></tr>
<tr><td valign="top" nowrap><b>secure</b></td><td valign="top" width="95%">control changes to security policies with <a href="#secure">secure</a>
</td></tr>
<tr><td valign="top" nowrap><b>protect</b></td><td valign="top" width="95%">protecting and hiding values with <a href="#protect">protect</a>
</td></tr>
<tr><td valign="top" nowrap><b>debug</b></td><td valign="top" width="95%">use of debug-related functions: <a href="#trace">trace</a> and <a href="#stack">stack</a>
</td></tr>
<tr><td valign="top" nowrap><b>envr</b></td><td valign="top" width="95%">getting OS/shell environment variables with <a href="#get-env">get-env</a>
</td></tr>
<tr><td valign="top" nowrap><b>call</b></td><td valign="top" width="95%">launching external programs with <a href="#call">call</a>
</td></tr>
<tr><td valign="top" nowrap><b>browse</b></td><td valign="top" width="95%">opening the web browser with <a href="#browse">browse</a>
</td></tr>
<tr><td valign="top" nowrap><b>extension</b></td><td valign="top" width="95%">importing <a href="https://www.rebol.com/r3/docs/concepts/extensions.html" class="con">extensions</a> (may contain native code)
</td></tr>
</table><p>
A list of these for your current release can always be obtained with the line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure query</code></pre></div><p>
(Which will also show their current policy settings.)
</p>

<h6>Usage</h6><fieldset class="fset"><legend>R3 ASK not available</legend>
<p>In current releases of R3, the ASK option is not available. Use either THROW or QUIT instead.</p>
</fieldset>
<h7>The main argument</h7><p>
The argument to the <a href="#secure">secure</a> function can be a word or a block.
</p>
<table class="doctable">
<tr><td valign="top" nowrap><b>word</b></td><td valign="top" width="95%">a general, top-level action such as setting global security levels to allow or deny all access. It can also be used to query the current security policies.
</td></tr>
<tr><td valign="top" nowrap><b>block</b></td><td valign="top" width="95%">specify separate security policies for files, directories, networking, extensions, debugging, and other features.
</td></tr>
</table>
<h7>Argument as a word</h7><p>
If the argument is a word, it can be:
</p>
<table class="doctable">
<tr><td valign="top" nowrap><b>help</b></td><td valign="top" width="95%">summarize what policies can be set
</td></tr>
<tr><td valign="top" nowrap><b>query</b></td><td valign="top" width="95%">show current policies
</td></tr>
<tr><td valign="top" nowrap><b>allow</b></td><td valign="top" width="95%">remove all policies (no security)
</td></tr>
<tr><td valign="top" nowrap><b>none</b></td><td valign="top" width="95%">the same as allow (no security)
</td></tr>
<tr><td valign="top" nowrap><b>ask</b></td><td valign="top" width="95%">require user permission on all policies
</td></tr>
<tr><td valign="top" nowrap><b>throw</b></td><td valign="top" width="95%">throw an error for all violations
</td></tr>
<tr><td valign="top" nowrap><b>quit</b></td><td valign="top" width="95%">exit the program for all violations
</td></tr>
</table><p>
For example, developers often type:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure none</code></pre></div><p>
to disable all security when developing new programs. <b>However, use this with care. Do not run (or <a href="#do">do</a>) any programs other than those that you trust.</b>
</p>
<p>
Another example is:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure quit</code></pre></div><p>
the program will quit immediately if any security violation occurs. Of course, this is a little extreme, and you won't get far. You'll want to specify a block for greater control. See the next section.
</p>

<h7>Argument as a block</h7><p>
To provide more detailed security, use a block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure [
    net quit
    file ask
    %./ allow
]</code></pre></div><p>
This block will:
</p>
<ul>
<li>disable networking (force a quit if attempted)</li>
<li>ask for user approval for all file access, except:</li>
<li>allow access to the local directory</li>
</ul><p>
As you can see, the security dialect consists of a block of paired values. The first value in the pair specifies what is being secured (file or net), and the second value specifies the level of security (allow, ask, throw, quit). The second value can also be a block to further specify read and write security.
</p>

<h6>Security policies</h6><p>
The security policies are:
</p>
<table class="doctable">
<tr><td valign="top" nowrap><b>allow</b></td><td valign="top" width="95%">removes all READ and/or WRITE restrictions.
</td></tr>
<tr><td valign="top" nowrap><b>ask</b></td><td valign="top" width="95%">restricts immediate READ and/or WRITE access and prompts the user for each access attempt, requiring approval before the operation may be completed.
</td></tr>
<tr><td valign="top" nowrap><b>throw</b></td><td valign="top" width="95%">denies READ and/or WRITE access, throwing an error when a restricted access attempt is made.
</td></tr>
<tr><td valign="top" nowrap><b>quit</b></td><td valign="top" width="95%">denies READ and/or WRITE access and quits the script when restricted access is attempted.
</td></tr>
</table><p>
For example, to allow all network access, but to quit on any file access:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure [
    net allow ;allows any net access
    file quit ;any file access will cause the program to quit
]</code></pre></div><p>
If a block is used instead of a security level word, it can contain pairs of security levels and access types. This lets you specify a greater level of detail about the security you require.
</p>

<h6>Access types</h6><p>
The access types allowed are:
</p>
<table class="doctable">
<tr><td valign="top" nowrap><b>read</b></td><td valign="top" width="95%">controls read access.
</td></tr>
<tr><td valign="top" nowrap><b>write</b></td><td valign="top" width="95%">controls write, delete, and rename access.
</td></tr>
<tr><td valign="top" nowrap><b>execute</b></td><td valign="top" width="95%">controls execute access.
</td></tr>
<tr><td valign="top" nowrap><b>all</b></td><td valign="top" width="95%">controls all access.
</td></tr>
</table><p>
The pairs are processed in the order they appear, with later pairs modifying the effect of earlier pairs. This permits setting one type of access without explicitly setting all others. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure [
    net allow
    file [
        ask all
        allow read
        quit execute
    ]
]</code></pre></div><p>
The above sets the security level to ask for all operations except for reading (which is allowed).
</p>
<p>
This technique can also be used for individual files and directories. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure [
    net allow
    file quit
    %source/ [ask read]
    %object/ [allow all]
]</code></pre></div><p>
will prompt the user if an attempt is made to read the %source directory, but it will allow all operations on the %object directory. Otherwise, it uses the default (quit).
</p>
<p>
If no security access level is specified for either network or file access, it defaults to ASK. The current settings will not be modified if an error occurs parsing the security block argument.
</p>

<h6>Querying security</h6><p>
The <a href="#secure">secure</a> function returns the prior security settings before the new settings were made. This is a block with the global network and file settings followed by file or directory settings. The word query can also be used to obtain the current security settings without modifying them:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe secure query
[file allow net allow ...]</code></pre></div><p>
Using query, you can modify the current security level by querying the current settings, modifying them, then using the secure function to set the new values.
</p>

<h6>Securing security</h6><p>
Once you have your security policies set, it's a good idea to secure the <a href="#secure">secure</a> function to prevent modifications. This is done in the same way as other policies.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure [secure quit]</code></pre></div><p>
will cause your program to immediately quit if any other code tries to modify the security policies.
</p>

<h6>User confirmation</h6><p>
Note that lowering the security level produces a change security settings requestor to the user. The exception is when the REBOL session is running in quiet mode which will, instead, terminate the REBOL session. No request is generated when security levels are raised. Note that the security request includes an option to allow all access for the remainder of the scripts processing.
</p>

<h6>Controlling security at startup</h6><p>
To disable all security on startup, you can start REBOL with:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">rebol -s args...</code></pre></div><p>
This policy allows open access for everything.
</p>
<p>
You can also use the --secure argument to specify any other default security level on startup.
</p>

<h6>Limiting evaluation (quota)</h6><p>
You can set <a href="#secure">secure</a> to limit interpreter evaluation. This feature allows you to restrict server scripts (such as CGI) to a specific evaluation length to prevent runaway programs.
</p>
<p>
This example sets the limit to 50000 cycles, after which the program will immediately quit (the default behavior):
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; secure [eval 50000]
&gt;&gt; loop 100000 [next "test"]
&lt;quit&gt;</code></pre></div><p>
Also, for debugging you can use the more detailed form of <w>secure:</p>
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; secure [eval [throw 50000]]
&gt;&gt; loop 100000 [next "test"]
** Access error: security violation: eval
** Where: loop
** Near: loop 100000 [next "test"]</code></pre></div><p>
You can continue your debugging at the console, but secure will trap again on the next evaluation sample. To disable that behavior:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; secure [eval allow]</code></pre></div><p>
When tuning your program, to determine how many cycles your code needs, you can use:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; stats/evals
== 50403</code></pre></div><p>
However, add to that number a good margin of error for special conditions within your code. In many cases you will want to make it ten or twenty times larger, just to be sure.
</p>
<p>
A few notes:
</p>
<ul>
<li>The maximum evaluation limit is 9e18.</li>
<li>The evaluation limit can be set only once and cannot be reset. However, for debugging after an eval THROW exception, you can use <w>secure to disable the trap (use: [eval allow]).</li>
<li>The limit is approximate. It is sampled at regular intervals (to avoid slowing down evaluation.) The sampling period is 10000 cycles, so that is the resolution of the limit. For example, if you set the limit to 1, it won't trap an error until 10000.</li>
<li>If the program quits, the exit code is set to 101, the same as any security termination; however, we may want to use special codes to indicate the reason for the quit.</li>
<li>Some types of loops are not yet checked, but we will add them. For example, PARSE cycles are not yet counted.</li>
<li>Time limits are not yet supported, but may be added in the future. However, the cycle limit is better for most cases, because it is CPU speed independent.</li>
</ul>
<h6>Limiting memory</h6><p>
You can set <a href="#secure">secure</a> to limit the amount of memory allocated by your program. This feature allows you to restrict server scripts (such as CGI) to a specific memory usage to prevent runaway programs.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; secure [memory 2'000'000]
&gt;&gt; strings: []
&gt;&gt; loop 100000 [append strings make string! 100'000]
&lt;quit&gt;</code></pre></div><p>
This feature works the same way as the evaluation limit described above. Read that section for more details.
</p>
<p>
To determine how much memory your program has currently used:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; stats
== 913616</code></pre></div><p>
The number is shown in bytes.
</p>
<p>
In addition, it should be noted that the memory limit applies to actual memory consumed. Due to automatic memory allocation (garbage collection) it is possible for a program to run a indefinite amount of time on a specific amount of memory.
</p>
<p>
The memory limit can be set only once and cannot be reset. However, for debugging after an eval THROW exception, you can use <w>secure to disable the trap:</p>
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">secure [memory allow]</code></pre></div>
<div class="see-also">See also: <a href="#import">import</a>, <a href="#load">load</a>, <a href="#protect">protect</a></div>
</section>

<hr>
<section id="select">
 <a name="select"></a>
 <h2>SELECT<a class="headerlink" href="#select" title="Link to this heading">¶</a></h2>
<p>Searches for a value; returns the value that follows, else none.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">select <span class="rebarg">series</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! port! map! object! module! none!</span>] 
  value       [<span class="types">any-type!</span>] 
<span class="tit">REFINEMENTS:</span>
  /part       Limits the search to a given length or position
   range      [<span class="types">number! series! pair!</span>] 
  /only       Treats a series value as only a single value
  /case       Characters are case-sensitive
  /same       Use "same?" as comparator
  /any        Enables the * and ? wildcards
  /with       Allows custom wildcards
   wild       [<span class="types">string!</span>] Specifies alternates for * and ?
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] 
  /last       Backwards from end of series
  /reverse    Backwards from the current position
</pre>

<h6>Description:</h6>
<p>
Similar to the <a href="#find">find</a> function, but returns the next value
in the series rather than the position of the match.
Returns NONE if search failed.
</p>
<p>
The /only refinement is evaluated for a block argument 
and is ignored if the argument is a string.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">blk: [red 123 green 456 blue 789]
print select blk 'red
123

weather: [
    "Ukiah"      [clear 78 wind west at 5 MPH]
    "Santa Rosa" [overcast 65 wind north at 10 MPH]
    "Eureka"     [rain 62 wind north at 15 MPH]
]
probe select weather "Eureka"
[rain 62 wind north at 15 MPH]</code></pre></div>
<div class="see-also">See also: <a href="#find">find</a>, <a href="#switch">switch</a></div>
</section>

<hr>
<section id="selfless?">
 <a name="selfless?"></a>
 <h2>SELFLESS?<a class="headerlink" href="#selfless?" title="Link to this heading">¶</a></h2>
<p>Returns true if the context doesn't bind 'self.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">selfless? <span class="rebarg">context</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  context     [<span class="types">any-word! any-object!</span>] A reference to the target context
</pre>
</section>

<hr>
<section id="series?">
 <a name="series?"></a>
 <h2>SERIES?<a class="headerlink" href="#series?" title="Link to this heading">¶</a></h2>
<p>Return TRUE if value is any type of series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">series? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print series? "string"
true

print series? [1 2 3]
true

print series? 1234
false</code></pre></div>
<div class="see-also">See also: <a href="#block?">block?</a>, <a href="#email?">email?</a>, <a href="#file?">file?</a>, <a href="#issue?">issue?</a>, <a href="#paren?">paren?</a>, <a href="#string?">string?</a>, <a href="#tuple?">tuple?</a>, <a href="#type?">type?</a>, <a href="#url?">url?</a></div>
</section>

<hr>
<section id="set">
 <a name="set"></a>
 <h2>SET<a class="headerlink" href="#set" title="Link to this heading">¶</a></h2>
<p>Sets a word, path, block of words, or object to specified value(s).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">set <span class="rebarg">word</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word! lit-word! any-path! block! object!</span>] Word, block of words, path, or object to be set (modified)
  value       [<span class="types">any-type!</span>] Value or block of values
<span class="tit">REFINEMENTS:</span>
  /any        Allows setting words to any value, including unset
  /only       Block or object value argument is set as a single value
  /some       None values in a block or object value argument, are not set
</pre>

<h6>Description:</h6>
<p>
If the first argument is a block of words and the value
is not a block, all of the words in the block will be
set to the specified value. If the value is a block,
then each of the words in the first block will be set to
the respective values in the second block. If there are
not enough values in the second block, the remaining
words will be set to NONE
</p>
<p>
The /ANY refinement allows words to be set any datatype
including those such as UNSET! that are not normally
allowed. This is useful in situations where all values
must be handled.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">set 'test 1234
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
2</code></pre></div><p>
You can also use <span class="datatype">set-word!</span> within the <a href="#set">set</a> function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">set [a: b:] [1 2]</code></pre></div><p>
This is useful if you use the <a href="#funct">funct</a> function, which auto-detects local variables that use the set-word notation.
</p>

<div class="see-also">See also: <a href="#get">get</a>, <a href="#in">in</a>, <a href="#protect">protect</a>, <a href="#unprotect">unprotect</a>, <a href="#unset">unset</a>, <a href="#value?">value?</a></div>
</section>

<hr>
<section id="set-cookies">
 <a name="set-cookies"></a>
 <h2>SET-COOKIES<a class="headerlink" href="#set-cookies" title="Link to this heading">¶</a></h2>
<p>Processes `Set-Cookie` headers and stores cookies according to RFC 6265. Cookies are stored in `system/state/cookies` map.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">set-cookies <span class="rebarg">host</span> <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  host        [<span class="types">string!</span>] Current host (used when the cookie doesn't set its domain)
  data        [<span class="types">string! block!</span>] Either a string or block containing `Set-Cookie` lines.
</pre>
</section>

<hr>
<section id="set-env">
 <a name="set-env"></a>
 <h2>SET-ENV<a class="headerlink" href="#set-env" title="Link to this heading">¶</a></h2>
<p>Sets the value of an OS environment variable (for current process).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">set-env <span class="rebarg">var</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  var         [<span class="types">any-string! any-word!</span>] Variable to set
  value       [<span class="types">string! none!</span>] Value to set, or NONE to unset it
</pre>
</section>

<hr>
<section id="set-path?">
 <a name="set-path?"></a>
 <h2>SET-PATH?<a class="headerlink" href="#set-path?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">set-path? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if set-path? first [a/b/c: 10] [print "Path found"]
Path found</code></pre></div>
<div class="see-also">See also: <a href="#make">make</a></div>
</section>

<hr>
<section id="set-scheme">
 <a name="set-scheme"></a>
 <h2>SET-SCHEME<a class="headerlink" href="#set-scheme" title="Link to this heading">¶</a></h2>
<p>Low-level port scheme actor initialization.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">set-scheme <span class="rebarg">scheme</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  scheme      [<span class="types">object!</span>] 
</pre>
</section>

<hr>
<section id="set-user">
 <a name="set-user"></a>
 <h2>SET-USER<a class="headerlink" href="#set-user" title="Link to this heading">¶</a></h2>
<p>Initialize user's persistent data under system/user</p>

<h6>Usage:</h6>
<pre class="usage fs-6">set-user <span class="rebarg">name</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  name        [<span class="types">word! ref! string! email! unset! none!</span>] User's name
<span class="tit">REFINEMENTS:</span>
  /p          Password used to encrypt the data
   password   [<span class="types">string! binary!</span>] 
  /f          Use custom persistent data file location
   file       [<span class="types">file!</span>] 
  /n          Setup a user if does not exists
</pre>
</section>

<hr>
<section id="set-word?">
 <a name="set-word?"></a>
 <h2>SET-WORD?<a class="headerlink" href="#set-word?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">set-word? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if set-word? first [word: 10] [print "it will be set"]
it will be set</code></pre></div>
</section>

<hr>
<section id="seventh">
 <a name="seventh"></a>
 <h2>SEVENTH<a class="headerlink" href="#seventh" title="Link to this heading">¶</a></h2>
<p>Returns the seventh value of a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">seventh <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
See the FIRST function for examples.
</p>
<p>
An error will occur if no value is found. Use the PICK function to avoid this error.
</p>

<div class="see-also">See also: <a href="#first">first</a>, <a href="#pick">pick</a>, <a href="#second">second</a>, <a href="#third">third</a></div>
</section>

<hr>
<section id="shift">
 <a name="shift"></a>
 <h2>SHIFT<a class="headerlink" href="#shift" title="Link to this heading">¶</a></h2>
<p>Shifts an integer left or right by a number of bits.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">shift <span class="rebarg">value</span> <span class="rebarg">bits</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">integer!</span>] 
  bits        [<span class="types">integer!</span>] Positive for left shift, negative for right shift
<span class="tit">REFINEMENTS:</span>
  /logical    Logical shift (sign bit ignored)
</pre>

<h6>Description:</h6>
<p>
Supports right or left bits shifts on integers.
</p>

</section>

<hr>
<section id="shift-left">
 <a name="shift-left"></a>
 <h2>SHIFT-LEFT<a class="headerlink" href="#shift-left" title="Link to this heading">¶</a></h2>
<p>Shift bits to the left (unsigned).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">shift-left <span class="rebarg">data</span> <span class="rebarg">bits</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">integer!</span>] 
  bits        [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="shift-right">
 <a name="shift-right"></a>
 <h2>SHIFT-RIGHT<a class="headerlink" href="#shift-right" title="Link to this heading">¶</a></h2>
<p>Shift bits to the right (unsigned).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">shift-right <span class="rebarg">data</span> <span class="rebarg">bits</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">integer!</span>] 
  bits        [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="show">
 <a name="show"></a>
 <h2>SHOW<a class="headerlink" href="#show" title="Link to this heading">¶</a></h2>
<p>Display or update a graphical object or block of them.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">show <span class="rebarg">gob</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  gob         [<span class="types">gob! none! block!</span>] 
</pre>

<h6>Description:</h6>
<p>
This is a low-level View function that is used to display or
update a face. The face being displayed must be part of a
pane that is part of a window display.
</p>
<p>
The SHOW function is called frequently to update the display of
a face after changes have been made.  If the face contains a
pane of sub-faces, all of those faces will be redisplayed.
</p>
<p>
If you attempt to show a face and nothing happens, make sure
that the face is part of the display hierarchy.  That is, the
face must be present in the pane list of another face that is
being displayed.
</p>
<p>
For example, if you modify any of the attributes of a face,
you call the SHOW function to display the change.  The code
below shows this:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">view layout [
    bx: box 100x24 black
    button "Red" [bx/color: red  show bx]
    button "Green" [bx/color: green  show bx]
]</code></pre></div><p>
The example below creates a layout face and then removes faces
from its pane.  The SHOW function is called each time to refresh
the face and display what has happened.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">out: layout [
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
</section>

<hr>
<section id="show-soft-keyboard">
 <a name="show-soft-keyboard"></a>
 <h2>SHOW-SOFT-KEYBOARD<a class="headerlink" href="#show-soft-keyboard" title="Link to this heading">¶</a></h2>
<p>Display on-screen keyboard for user input.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">show-soft-keyboard</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /attach     
   gob        [<span class="types">gob!</span>] GOB which should be visible during the input operation
</pre>
</section>

<hr>
<section id="sign?">
 <a name="sign?"></a>
 <h2>SIGN?<a class="headerlink" href="#sign?" title="Link to this heading">¶</a></h2>
<p>Returns sign of number as 1, 0, or -1 (to use as multiplier).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">sign? <span class="rebarg">number</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  number      [<span class="types">number! money! time!</span>] 
</pre>

<h6>Description:</h6>
<p>
The SIGN? function returns a positive, zero, or negative integer
based on the sign of its argument.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print sign? 1000
1

print sign? 0
0

print sign? -1000
-1</code></pre></div><p>
The sign is returned as an integer to allow it to be used
as a multiplication term within an expression:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">val: -5
new: 2000 * sign? val
print new
-2000

size: 20
num: -30
if size &gt; 10 [xy: 10x20 * sign? num]
print xy
-10x-20</code></pre></div>
<div class="see-also">See also: <a href="#abs">abs</a>, <a href="#negate">negate</a></div>
</section>

<hr>
<section id="sin">
 <a name="sin"></a>
 <h2>SIN<a class="headerlink" href="#sin" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric sine.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">sin <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">decimal!</span>] In radians
</pre>
</section>

<hr>
<section id="sine">
 <a name="sine"></a>
 <h2>SINE<a class="headerlink" href="#sine" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric sine.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">sine <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number!</span>] In degrees by default
<span class="tit">REFINEMENTS:</span>
  /radians    Value is specified in radians
</pre>

<h6>Description:</h6>
<p>
Ratio between the length of the opposite side to the
length of the hypotenuse of a right triangle.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print sine 90
1.0

print (sine 45) = (cosine 45)
true

print sine/radians pi
0.0</code></pre></div>
<div class="see-also">See also: <a href="#arccosine">arccosine</a>, <a href="#arcsine">arcsine</a>, <a href="#arctangent">arctangent</a>, <a href="#cosine">cosine</a>, <a href="#tangent">tangent</a></div>
</section>

<hr>
<section id="single?">
 <a name="single?"></a>
 <h2>SINGLE?<a class="headerlink" href="#single?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the series length is 1.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">single? <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! port! map! tuple! bitset! object! gob! any-word!</span>] 
</pre>
</section>

<hr>
<section id="sixth">
 <a name="sixth"></a>
 <h2>SIXTH<a class="headerlink" href="#sixth" title="Link to this heading">¶</a></h2>
<p>Returns the sixth value of a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">sixth <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
See the FIRST function for examples.
</p>
<p>
An error will occur if no value is found. Use the PICK function to avoid this error.
</p>

<div class="see-also">See also: <a href="#first">first</a>, <a href="#pick">pick</a>, <a href="#second">second</a>, <a href="#third">third</a></div>
</section>

<hr>
<section id="size?">
 <a name="size?"></a>
 <h2>SIZE?<a class="headerlink" href="#size?" title="Link to this heading">¶</a></h2>
<p>Returns the size of a file or vector (bits per value).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">size? <span class="rebarg">target</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  target      [<span class="types">file! url! port! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
If the file or URL is a directory, it returns the number
of entries in the directory.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print size? %file.txt
none</code></pre></div>
<div class="see-also">See also: <a href="#exists?">exists?</a>, <a href="#modified?">modified?</a></div>
</section>

<hr>
<section id="skip">
 <a name="skip"></a>
 <h2>SKIP<a class="headerlink" href="#skip" title="Link to this heading">¶</a></h2>
<p>Returns the series forward or backward from the current position.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">skip <span class="rebarg">series</span> <span class="rebarg">offset</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port!</span>] 
  offset      [<span class="types">number! logic! pair!</span>] 
</pre>

<h6>Description:</h6>
<p>
For example, SKIP series 1 is the same as NEXT. If skip
attempts to move beyond the head or tail it will be
stopped at the head or tail.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "REBOL"
print skip str 3
OL

blk: [11 22 33 44 55]
print skip blk 3
44 55</code></pre></div>
<div class="see-also">See also: <a href="#at">at</a>, <a href="#back">back</a>, <a href="#index?">index?</a>, <a href="#next">next</a></div>
</section>

<hr>
<section id="sort">
 <a name="sort"></a>
 <h2>SORT<a class="headerlink" href="#sort" title="Link to this heading">¶</a></h2>
<p>Sorts a series; default sort order is ascending.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">sort <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series!</span>] At position (modified)
<span class="tit">REFINEMENTS:</span>
  /case       Case sensitive sort
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] Size of each record
  /compare    Comparator offset or function
   comparator [<span class="types">integer! any-function!</span>] 
  /part       Limits the sorting to a given length or position
   range      [<span class="types">number! series!</span>] 
  /all        Compare all fields
  /reverse    Reverse sort order
</pre>

<h6>Description:</h6>
<p>
Sorting will modify any type of <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a> passed as the argument:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">blk: [799 34 12 934 -24 0]
sort blk
print blk
-24 0 12 34 799 934

print sort "dbeca"
"abcde"</code></pre></div><p>
Normally sorting is not sensitive to character cases:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">sort ["Fred" "fred" "FRED"]
["fred" "FRED" "Fred"]</code></pre></div><p>
But you can make it sensitive with the /CASE refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">sort/case ["Fred" "fred" "FRED"]
["FRED" "Fred" "fred"]</code></pre></div><p>
Editor note: Sort bug here causes camel-case strings to be sorted incorrectly.
When using the /SKIP refinement, you can treat the series as a set of records of a fixed size. Here we sort by a "name" column, while "age" is skipped:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">name-ages: [
    "Larry" 45
    "Curly" 50
    "Mo" 42
]
print sort/skip name-ages 2
Curly 50 Larry 45 Mo 42</code></pre></div><p>
A /COMPARE function can be specified to perform the comparison. This allows you to change the ordering of the SORT:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">names: [
    "Larry"
    "Curly"
    "Mo"
]
print sort/compare names func [a b] [a &lt; b]
Curly Larry Mo</code></pre></div><p>
The /ALL refinement will force the entire record to be passed as a series to the compare function. This is useful if you need to compare one or more fields of a record while also doing a skip operation.
</p>
<p>
Editor note: Need a good working example. This may not be possible until remaining SORT bugs are fixed.
When sorting <span class="datatype">pair!</span> data (points and area sizes), the y coordinate is dominant. This is preferred to support the y sorting used by various graphics algorithms.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe sort [1x2 2x1 0x0 1x0 0x1 1x1]
[0x0 1x0 0x1 1x1 2x1 1x2]</code></pre></div>
<div class="see-also">See also: <a href="#append">append</a>, <a href="#change">change</a>, <a href="#clear">clear</a>, <a href="#insert">insert</a>, <a href="#remove">remove</a></div>
</section>

<hr>
<section id="source">
 <a name="source"></a>
 <h2>SOURCE<a class="headerlink" href="#source" title="Link to this heading">¶</a></h2>
<p>Prints the source code for a word</p>

<h6>Usage:</h6>
<pre class="usage fs-6">source <span class="rebarg">word</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word! path!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#source">source</a> function displays the source code for REBOL defined functions.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">>> source join</code></pre></div>
<div class="example-code"><pre class="text-block"><code>join: make function! [[
    "Concatenates values."
    value "Base value"
    rest "Value or block of values"
][
    append either series? :value [copy value] [form :value] reduce :rest
]]
</code></pre></div><p>
REBOL defined functions include the mezzanine functions (built-in interpreted functions) and user defined functions. Native functions have no source to display.
</p>

<div class="see-also">See also: <a href="#?">?</a>, <a href="#??">??</a>, <a href="#help">help</a>, <a href="#trace">trace</a>, <a href="#what">what</a></div>
</section>

<hr>
<section id="spec-of">
 <a name="spec-of"></a>
 <h2>SPEC-OF<a class="headerlink" href="#spec-of" title="Link to this heading">¶</a></h2>
<p>Returns a copy of the spec of any function, any object, vector, datatype or struct</p>

<h6>Usage:</h6>
<pre class="usage fs-6">spec-of <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-function! any-object! vector! datatype! struct!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; spec-of :join
== [
    "Concatenates values."
    value "Base value"
    rest "Value or block of values"
]</code></pre></div>
<div class="see-also">See also: <a href="#body-of">body-of</a>, <a href="#reflect">reflect</a>, <a href="#title-of">title-of</a>, <a href="#types-of">types-of</a>, <a href="#values-of">values-of</a>, <a href="#words-of">words-of</a></div>
</section>

<hr>
<section id="speed?">
 <a name="speed?"></a>
 <h2>SPEED?<a class="headerlink" href="#speed?" title="Link to this heading">¶</a></h2>
<p>Returns approximate speed benchmarks [eval cpu memory file-io].</p>

<h6>Usage:</h6>
<pre class="usage fs-6">speed?</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /no-io      Skip the I/O test
  /times      Show time for each test
</pre>
</section>

<hr>
<section id="split">
 <a name="split"></a>
 <h2>SPLIT<a class="headerlink" href="#split" title="Link to this heading">¶</a></h2>
<p>Split a series into pieces; fixed or variable size, fixed number, or at delimiters</p>

<h6>Usage:</h6>
<pre class="usage fs-6">split <span class="rebarg">series</span> <span class="rebarg">dlm</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series!</span>] The series to split
  dlm          
<span class="tit">REFINEMENTS:</span>
  /parts      If dlm is an integer, split into n pieces, rather than pieces of length n.
  /at         Split into 2, at the index position if an integer or the first occurrence of the dlm
</pre>

<h6>Description:</h6>
<p>
The <a href="#split">split</a> function is used to divide a <a href="https://www.rebol.com/r3/docs/concepts/series.html">series</a> into subcomponents.
It provides several ways to specify how you want the split done.
</p>

<h7>Split into equal segments:</h7><p>
Given an integer as the dlm parameter, <a href="#split">split</a> will break the series
up into pieces of that size.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; split "1234567812345678" 4
== ["1234" "5678" "1234" "5678"]</code></pre></div><p>
If the series can't be evenly split, the last value will be shorter.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; split "1234567812345678" 3
== ["123" "456" "781" "234" "567" "8"]

&gt;&gt; split "1234567812345678" 5
== ["12345" "67812" "34567" "8"]</code></pre></div>
<h7>Split into N segments:</h7><p>
Given an integer as dlm, and using the /parts refinement, it breaks
the series into n pieces, rather than pieces of length n.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; split/parts [1 2 3 4 5 6] 2
== [[1 2 3] [4 5 6]]

&gt;&gt; split/parts "1234567812345678" 2
== ["12345678" "12345678"]</code></pre></div><p>
If the series can't be evenly split, the last value will be longer.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; split/parts "1234567812345678" 3
== ["12345" "67812" "345678"]

&gt;&gt; split/parts "1234567812345678" 5
== ["123" "456" "781" "234" "5678"]</code></pre></div>
<h7>Split into uneven segments:</h7><p>
If dlm is a block containing only integer values, those values 
determine the size of each piece returned. That is, each piece
can be a different size.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; split [1 2 3 4 5 6] [2 1 3]
== [[1 2] [3] [4 5 6]]

&gt;&gt; split "1234567812345678" [4 4 2 2 1 1 1 1]
== ["1234" "5678" "12" "34" "5" "6" "7" "8"]

&gt;&gt; split first [(1 2 3 4 5 6 7 8 9)] 3
== [(1 2 3) (4 5 6) (7 8 9)]

&gt;&gt; split #{0102030405060708090A} [4 3 1 2]
== [#{01020304} #{050607} #{08} #{090A}]</code></pre></div><p>
If the total of the dlm sizes is less than the length of the series,
the extra data will be ignored.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; split [1 2 3 4 5 6] [2 1]
== [[1 2] [3]]</code></pre></div><p>
If you have extra dlm sizes after the series data is exhausted, you
will get empty values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; split [1 2 3 4 5 6] [2 1 3 5]
== [[1 2] [3] [4 5 6] []]</code></pre></div><p>
If the last dlm size would return more data than the series contains,
it returns all the remaining series data, and no more.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; split [1 2 3 4 5 6] [2 1 6]
== [[1 2] [3] [4 5 6]]</code></pre></div><p>
Negative values can be used to skip in the series without returning
that part:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt;  split [1 2 3 4 5 6] [2 -2 2]
== [[1 2] [5 6]]</code></pre></div>
<h7>Simple delimiter splitting:</h7><p>
Char or any-string values can be used for simple splitting, much as
you would with "parse", but with different behavior for strings
that have embedded quotes.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; split "abc,de,fghi,jk" #","
== ["abc" "de" "fghi" "jk"]

&gt;&gt; split "abc&lt;br&gt;de&lt;br&gt;fghi&lt;br&gt;jk" &lt;br&gt;
== ["abc" "de" "fghi" "jk"]</code></pre></div><p>
If you want to split at more than one character value, you can use
a charset.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; split "abc|de/fghi:jk" charset "|/:"
== ["abc" "de" "fghi" "jk"]</code></pre></div><p>
Note that for greater control, you can use simple <a href="#parse">parse</a> rules:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; split "abc     de fghi  jk" [some #" "]
== ["abc" "de" "fghi" "jk"]</code></pre></div>
<div class="see-also">See also: <a href="#extract">extract</a>, <a href="#parse">parse</a></div>
</section>

<hr>
<section id="split-lines">
 <a name="split-lines"></a>
 <h2>SPLIT-LINES<a class="headerlink" href="#split-lines" title="Link to this heading">¶</a></h2>
<p>Given a string series, split lines on CR-LF.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">split-lines <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">string!</span>] 
</pre>
</section>

<hr>
<section id="split-path">
 <a name="split-path"></a>
 <h2>SPLIT-PATH<a class="headerlink" href="#split-path" title="Link to this heading">¶</a></h2>
<p>Splits and returns directory path and file as a block.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">split-path <span class="rebarg">target</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  target      [<span class="types">file! url! string!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns a block consisting of two elements, the path and the file.
Can be used on URLs and files alike.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe split-path %tests/math/add.r
[%tests/math/ %add.r]

set [path file] split-path http://www.rebol.com/graphics/logo.gif
print path
http://www.rebol.com/graphics/

print file
logo.gif</code></pre></div>
<div class="see-also">See also: <a href="#clean-path">clean-path</a>, <a href="#suffix?">suffix?</a></div>
</section>

<hr>
<section id="sqrt">
 <a name="sqrt"></a>
 <h2>SQRT<a class="headerlink" href="#sqrt" title="Link to this heading">¶</a></h2>
<p>Returns the square root of a number.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">sqrt <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">decimal!</span>] 
</pre>
</section>

<hr>
<section id="square-root">
 <a name="square-root"></a>
 <h2>SQUARE-ROOT<a class="headerlink" href="#square-root" title="Link to this heading">¶</a></h2>
<p>Returns the square root of a number.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">square-root <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns the square-root of the number provided. If the
number is negative, an error will occur (which you can
trap with the TRY function).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print square-root 4
2.0

print square-root 2
1.414213562373095</code></pre></div>
<div class="see-also">See also: <a href="#exp">exp</a>, <a href="#log-10">log-10</a>, <a href="#log-2">log-2</a>, <a href="#log-e">log-e</a>, <a href="#power">power</a></div>
</section>

<hr>
<section id="stack">
 <a name="stack"></a>
 <h2>STACK<a class="headerlink" href="#stack" title="Link to this heading">¶</a></h2>
<p>Returns stack backtrace or other values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">stack <span class="rebarg">offset</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  offset      [<span class="types">integer!</span>] Relative backward offset
<span class="tit">REFINEMENTS:</span>
  /block      Block evaluation position
  /word       Function or object name, if known
  /func       Function value
  /args       Block of args (may be modified)
  /size       Current stack size (in value units)
  /depth      Stack depth (frames)
  /limit      Stack bounds (auto expanding)
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="stats">
 <a name="stats"></a>
 <h2>STATS<a class="headerlink" href="#stats" title="Link to this heading">¶</a></h2>
<p>Provides status and statistics information about the interpreter.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">stats</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /show       Print formatted results to console
  /profile    Returns profiler object
  /timer      High resolution time difference from start
  /evals      Number of values evaluated by interpreter
  /dump-series 
   pool-id    [<span class="types">integer!</span>] Dump all series in pool pool-id, -1 for all pools
</pre>

<h6>Description:</h6>
<p>
The STATS function returns a wide range of useful REBOL system
statistics, including information about memory usage, interpreter
cycles, and more.
</p>
<p>
If no refinement is provide, STATS returns the amount of memory
that it is using. This value must be computed from tables.
</p>
<p>
The /pools refinement returns information about the memory pools
that REBOL uses for managing its memory.
</p>
<p>
The /types refinement provides a summary of the number of each
datatype currently allocated by the system.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">foreach [type num] stats/types [
    print [type num]
]</code></pre></div><p>
The /series shows the number of series values, both string and
block oriented, as free space, etc.
</p>
<p>
The /frames provides the number of context frames used for objects
and functions.
</p>
<p>
The /recycle option summarizes garbage collection information.
</p>
<p>
The /evals provides counters for the number of interpreter cycles,
functions invoked, and blocks evaluated.
</p>
<p>
The /clear refinement can be used with the /evals refinement to clear
its counters.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">stats/evals/clear
loop 100 [print "hello"]
print stats/evals</code></pre></div>
<div class="see-also">See also: <a href="#help">help</a>, <a href="#trace">trace</a></div>
</section>

<hr>
<section id="strict-equal?">
 <a name="strict-equal?"></a>
 <h2>STRICT-EQUAL?<a class="headerlink" href="#strict-equal?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are strictly equal.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">strict-equal? <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Strict equality requires the values to not differ by
datatype (so 1 would not be equal to 1.0) nor by
character casing (so "abc" would not be equal to "ABC").
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print strict-equal? 123 123
true

print strict-equal? "abc" "ABC"
false</code></pre></div>
<div class="see-also">See also: <a href="#<>">&lt;&gt;</a>, <a href="#=">=</a>, <a href="#==">==</a>, <a href="#strict-not-equal?">strict-not-equal?</a></div>
</section>

<hr>
<section id="strict-not-equal?">
 <a name="strict-not-equal?"></a>
 <h2>STRICT-NOT-EQUAL?<a class="headerlink" href="#strict-not-equal?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are not strictly equal.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">strict-not-equal? <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE if the values neither differ by datatype
(so 1 would not be equal to 1.0) nor by character casing
(so "abc" would not be equal to "ABC").
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print strict-not-equal? 124 123
true

print strict-not-equal? 12-sep-98 10:30
true</code></pre></div>
<div class="see-also">See also: <a href="#!==">!==</a>, <a href="#<>">&lt;&gt;</a>, <a href="#=">=</a>, <a href="#==">==</a></div>
</section>

<hr>
<section id="string?">
 <a name="string?"></a>
 <h2>STRING?<a class="headerlink" href="#string?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">string? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print string? "with all things considered"
true

print string? 123
false</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="struct?">
 <a name="struct?"></a>
 <h2>STRUCT?<a class="headerlink" href="#struct?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">struct? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns TRUE if the value is a STRUCT datatype.
</p>

</section>

<hr>
<section id="su">
 <a name="su"></a>
 <h2>SU<a class="headerlink" href="#su" title="Link to this heading">¶</a></h2>
<p>Initialize user's persistent data under system/user</p>

<h6>Usage:</h6>
<pre class="usage fs-6">su <span class="rebarg">name</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  name        [<span class="types">word! ref! string! email! unset! none!</span>] User's name
<span class="tit">REFINEMENTS:</span>
  /p          Password used to encrypt the data
   password   [<span class="types">string! binary!</span>] 
  /f          Use custom persistent data file location
   file       [<span class="types">file!</span>] 
  /n          Setup a user if does not exists
</pre>
</section>

<hr>
<section id="subtract">
 <a name="subtract"></a>
 <h2>SUBTRACT<a class="headerlink" href="#subtract" title="Link to this heading">¶</a></h2>
<p>Returns the second value subtracted from the first.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">subtract <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! date! vector!</span>] 
  value2      [<span class="types">scalar! date! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
Note: The <a href="#+">+</a> operator is a special infix form for this function.
</p>
<p>
Many different datatypes support subtraction. Here are just a few:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print subtract 123 1
122

print subtract 1.2.3.4 1.0.3.0
0.2.0.4

print subtract 12:00 11:00
1:00

print subtract 1-Jan-2000 1
31-Dec-1999</code></pre></div><p>
When subtracting values of different datatypes, the values must be compatible. Auto conversion of the values will occur into the datatype that has the most expansive representation. For example an integer subtracted from a decimal will produce a decimal.
</p>

<div class="see-also">See also: <a href="#+">+</a>, <a href="#-">-</a>, <a href="#absolute">absolute</a>, <a href="#add">add</a></div>
</section>

<hr>
<section id="suffix?">
 <a name="suffix?"></a>
 <h2>SUFFIX?<a class="headerlink" href="#suffix?" title="Link to this heading">¶</a></h2>
<p>Return the file suffix of a filename or url. Else, NONE.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">suffix? <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file! url! string!</span>] 
</pre>

<h6>Description:</h6>
<p>
The SUFFIX? function can be used to obtain the file extention
(e.g. .exe, .txt, .jpg, etc.) that is part of a filename.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print suffix? %document.txt
.txt

print suffix? %program.exe
.exe

print suffix? %dir/path/doc.txt
.txt

print suffix? %file.type.r
.r

print suffix? http://www.rebol.com/doc.txt
.txt</code></pre></div><p>
If there is no suffix, a NONE is returned:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print suffix? %filename
none</code></pre></div><p>
The suffix function can be used with any string datatype, but always
returns a FILE! datatype if the suffix was found.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print type? suffix? %file.txt
file!

print type? suffix? "file.txt"
file!

print type? suffix? http://www.rebol.com/file.txt
file!</code></pre></div><p>
This was done to allow code such as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">url: http://www.rebol.com/docs.html
if find [%.txt %.html %.htm %.doc] suffix? url [
    print [url "is a document file."]
]
http://www.rebol.com/docs.html is a document file.</code></pre></div>
<div class="see-also">See also: <a href="#find">find</a>, <a href="#split-path">split-path</a></div>
</section>

<hr>
<section id="sum">
 <a name="sum"></a>
 <h2>SUM<a class="headerlink" href="#sum" title="Link to this heading">¶</a></h2>
<p>Returns the sum of all values in a block</p>

<h6>Usage:</h6>
<pre class="usage fs-6">sum <span class="rebarg">values</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  values      [<span class="types">block! vector! paren!</span>] 
</pre>
</section>

<hr>
<section id="supplement">
 <a name="supplement"></a>
 <h2>SUPPLEMENT<a class="headerlink" href="#supplement" title="Link to this heading">¶</a></h2>
<p>Append value if not found; returns series at same position.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">supplement <span class="rebarg">series</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">block!</span>] (modified)
  value        
<span class="tit">REFINEMENTS:</span>
  /case       Case-sensitive comparison
</pre>
</section>

<hr>
<section id="swap">
 <a name="swap"></a>
 <h2>SWAP<a class="headerlink" href="#swap" title="Link to this heading">¶</a></h2>
<p>Swaps elements between two series or the same series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">swap <span class="rebarg">series1</span> <span class="rebarg">series2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series1     [<span class="types">series! gob!</span>] At position (modified)
  series2     [<span class="types">series! gob!</span>] At position (modified)
</pre>

<h6>Description:</h6>
<p>
Description is needed.
</p>

</section>

<hr>
<section id="swap-endian">
 <a name="swap-endian"></a>
 <h2>SWAP-ENDIAN<a class="headerlink" href="#swap-endian" title="Link to this heading">¶</a></h2>
<p>Swaps byte order (endianness)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">swap-endian <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">binary!</span>] At position (modified)
<span class="tit">REFINEMENTS:</span>
  /width      
   bytes      [<span class="types">integer!</span>] 2, 4 or 8 (default is 2)
  /part       Limits to a given length or position
   range      [<span class="types">number! series!</span>] 
</pre>
</section>

<hr>
<section id="switch">
 <a name="switch"></a>
 <h2>SWITCH<a class="headerlink" href="#switch" title="Link to this heading">¶</a></h2>
<p>Selects a choice and evaluates the block that follows it.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">switch <span class="rebarg">value</span> <span class="rebarg">cases</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        Target value
  cases       [<span class="types">block!</span>] Block of cases to check
<span class="tit">REFINEMENTS:</span>
  /default    
   def         Default case if no others found
  /all        Evaluate all matches (not just first one)
  /case       Perform a case-sensitive comparison
</pre>

<h6>Description:</h6>
<p>
The <a href="#switch">switch</a> function selects the block for a given choice and evaluates it.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">switch 22 [
    11 [print "here"]
    22 [print "there"]
]
there</code></pre></div><p>
This function is equivalent to writing a <a href="#select">select</a> like this:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">do select [
    11 [print "here"]
    22 [print "there"]
] 22</code></pre></div>
<h6>Variety of Datatypes</h6><p>
The selection choices can be of any datatype. Here are some examples:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">file: %user.r
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

tag: &lt;title&gt;
print switch html [
    &lt;pre&gt;   ["preformatted text"]
    &lt;title&gt; ["page title"]
    &lt;li&gt;    ["bulleted list item"]
]
page title</code></pre></div>
<h6>Cases Not Evaluated</h6><p>
It's very important to note that the choices are not evaluated (think of them as constants.) This allows the choices to be words, as shown below. If you need evaluation of the case values, use the <a href="#case">case</a> function instead.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">person: 'mom
switch person [
    dad [print "here"]
    mom [print "there"]
    kid [print "everywhere"]
]
there</code></pre></div><p>
This most often becomes important when you want to <a href="#switch">switch</a> based on a datatype value. You must be sure to use <a href="#type?">type?</a> with a /word refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">val: 123
switch type?/word [
    integer! [print "it's integer"]
    decimal! [print "it's decimal"]
    date! [print "it's a date"]
]
it's integer</code></pre></div><p>
Here the <a href="#type?">type?</a> function returns the word (name) of the <span class="datatype">datatype!</span>, not the datatype's type value.
</p>
<p>
Another possible approach is to evaluate the block of cases. For the example above:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">switch type? reduce [
    integer! [print "it's integer"]
    decimal! [print "it's decimal"]
    date! [print "it's a date"]
]
it's integer</code></pre></div><p>
This works because words like integer! are set to their actual datatype values.
</p>

<h6>Default Case</h6><p>
You can use the /default refinement to specify a default case.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">time: 14:00
switch/default time [
     8:00 [send wendy@domain.dom "Hey, get up"]
    12:30 [send cindy@dom.dom "Join me for lunch."]
    16:00 [send group@every.dom "Dinner anyone?"]
][
    print ["Nothing done at" time]
]
Nothing done at 14:00</code></pre></div>
<h6>Return Value</h6><p>
The <a href="#switch">switch</a> function returns the value of the case block that it evaluated, or none otherwise.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">car: pick [Ford Chevy Dodge] random 3
print switch car [
    Ford [351 * 1.4]
    Chevy [454 * 5.3]
    Dodge [154 * 3.5]
]
491.4</code></pre></div>
<h6>Common Problems</h6><p>
The most common problem is to assume that <a href="#switch">switch</a> evaluates your case values. It does not. This kind of code does not work:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">item1: 100
item2: 200
n: 100
switch n [
    item1 [...]
    item2 [...]
]</code></pre></div><p>
However, you can <a href="#reduce">reduce</a> the case block to its actual values:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">switch n reduce [
    item1 [...]
    item2 [...]
]</code></pre></div>
<div class="see-also">See also: <a href="#case">case</a>, <a href="#find">find</a>, <a href="#select">select</a></div>
</section>

<hr>
<section id="tag?">
 <a name="tag?"></a>
 <h2>TAG?<a class="headerlink" href="#tag?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">tag? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print tag? &lt;title&gt;
true

print tag? "title"
false</code></pre></div>
</section>

<hr>
<section id="tail">
 <a name="tail"></a>
 <h2>TAIL<a class="headerlink" href="#tail" title="Link to this heading">¶</a></h2>
<p>Returns the series just past its end.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">tail <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port!</span>] 
</pre>

<h6>Description:</h6>
<p>
Access to the tail allows insertion at the end of a
series (because insertion always occurs before the
specified element).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">blk: copy [11 22 33]
insert tail blk [44 55 66]
print blk
11 22 33 44 55 66</code></pre></div>
<div class="see-also">See also: <a href="#head">head</a>, <a href="#head?">head?</a>, <a href="#tail?">tail?</a></div>
</section>

<hr>
<section id="tail?">
 <a name="tail?"></a>
 <h2>TAIL?<a class="headerlink" href="#tail?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if series is at or past its end; or empty for other types.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">tail? <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! gob! port! bitset! typeset! map!</span>] 
</pre>

<h6>Description:</h6>
<p>
This function is the best way to detect the end of a
series while moving through it.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print tail? "string"
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
true</code></pre></div>
<div class="see-also">See also: <a href="#empty?">empty?</a>, <a href="#head">head</a>, <a href="#head?">head?</a>, <a href="#tail">tail</a></div>
</section>

<hr>
<section id="take">
 <a name="take"></a>
 <h2>TAKE<a class="headerlink" href="#take" title="Link to this heading">¶</a></h2>
<p>Removes and returns one or more elements.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">take <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! port! gob! none!</span>] At the current position (modified)
<span class="tit">REFINEMENTS:</span>
  /part       Specifies a length or end position
   range      [<span class="types">number! series! pair!</span>] 
  /deep       Also copies series values within the block
  /last       Takes from the tail end
  /all        Copies the complete content of the series and then clears it
</pre>

<h6>Description:</h6>
<p>
The <a href="#take">take</a> function removes a value from a series and returns it as the result. It's a useful combination of <a href="#pick">pick</a> with <a href="#remove">remove</a>.
</p>
<p>
For example, used on blocks:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: [a b c d]
take data
a

probe data
[b c d]</code></pre></div><p>
Used on strings:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "abcd"
take str
#"a"

probe str
"bcd"</code></pre></div>
<h6>For Queues and Stacks</h6><p>
The <a href="#take">take</a> function is quite useful for making queues and stacks.
</p>
<p>
An example queue is implemented as first in first out (FIFO) block. New values are added with <a href="#append">append</a> and removed with <a href="#take">take</a>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: make block! 10
append data 1
append data 2
append data 3
take data
1

take data
2</code></pre></div><p>
An example stack is implemented as last in first out (LIFO). The difference is to use the /last refinement with <a href="#take">take</a>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: make block! 10
append data 1
append data 2
append data 3
take/last data
3

take/last data
2</code></pre></div><p>
The data queued and stacked above can be any REBOL values, including string, functions, objects or whatever.
</p>

</section>

<hr>
<section id="tan">
 <a name="tan"></a>
 <h2>TAN<a class="headerlink" href="#tan" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric tangent.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">tan <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">decimal!</span>] In radians
</pre>
</section>

<hr>
<section id="tangent">
 <a name="tangent"></a>
 <h2>TANGENT<a class="headerlink" href="#tangent" title="Link to this heading">¶</a></h2>
<p>Returns the trigonometric tangent.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">tangent <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number!</span>] In degrees by default
<span class="tit">REFINEMENTS:</span>
  /radians    Value is specified in radians
</pre>

<h6>Description:</h6>
<p>
Ratio between the length of the opposite side to
the length of the adjacent side of a right triangle.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print tangent 30
0.5773502691896257

print tangent/radians 2 * pi
0.0</code></pre></div>
<div class="see-also">See also: <a href="#arccosine">arccosine</a>, <a href="#arcsine">arcsine</a>, <a href="#arctangent">arctangent</a>, <a href="#cosine">cosine</a>, <a href="#tangent">tangent</a></div>
</section>

<hr>
<section id="task">
 <a name="task"></a>
 <h2>TASK<a class="headerlink" href="#task" title="Link to this heading">¶</a></h2>
<p>Creates a task.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">task <span class="rebarg">spec</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  spec        [<span class="types">block!</span>] Name or spec block
  body        [<span class="types">block!</span>] The body block of the task
</pre>

<h6>Description:</h6>
<p>
Description is needed.
</p>

</section>

<hr>
<section id="task?">
 <a name="task?"></a>
 <h2>TASK?<a class="headerlink" href="#task?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">task? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="tenth">
 <a name="tenth"></a>
 <h2>TENTH<a class="headerlink" href="#tenth" title="Link to this heading">¶</a></h2>
<p>Returns the tenth value of a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">tenth <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
See the FIRST function for examples.
</p>
<p>
An error will occur if no value is found. Use the PICK function to avoid this error.
</p>

<div class="see-also">See also: <a href="#first">first</a>, <a href="#pick">pick</a>, <a href="#second">second</a>, <a href="#third">third</a></div>
</section>

<hr>
<section id="third">
 <a name="third"></a>
 <h2>THIRD<a class="headerlink" href="#third" title="Link to this heading">¶</a></h2>
<p>Returns the third value of a series.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">third <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
An error will occur if no value is found. Use the PICK
function to avoid this error.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print third "REBOL"
B

print third [11 22 33 44 55 66]
33

print third 12-jun-1999
12

print third 199.4.80.1
80

print third 12:34:56.78
56.78</code></pre></div>
<div class="see-also">See also: <a href="#fifth">fifth</a>, <a href="#first">first</a>, <a href="#fourth">fourth</a>, <a href="#pick">pick</a>, <a href="#second">second</a></div>
</section>

<hr>
<section id="throw">
 <a name="throw"></a>
 <h2>THROW<a class="headerlink" href="#throw" title="Link to this heading">¶</a></h2>
<p>Throws control back to a previous catch.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">throw <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] Value returned from catch
<span class="tit">REFINEMENTS:</span>
  /name       Throws to a named catch
   word       [<span class="types">word!</span>] 
</pre>

<h6>Description:</h6>
<p>
CATCH and THROW go together. They provide a method of
exiting from a block without evaluating the rest of the
block. To use it, provide CATCH with a block to
evaluate. If within that block a THROW is evaluated,
the script will return from the CATCH at that point. The
result of the CATCH will be the value that was passed as
the argument to the THROW. When using multiple CATCH
functions, provide them with a name to identify which
one will CATCH which THROW.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print catch [
    if exists? %file.txt [throw "Doc file!"]
]
none</code></pre></div>
<div class="see-also">See also: <a href="#catch">catch</a>, <a href="#exit">exit</a>, <a href="#return">return</a></div>
</section>

<hr>
<section id="time?">
 <a name="time?"></a>
 <h2>TIME?<a class="headerlink" href="#time?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">time? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print time? 12:00
true

print time? 123
false</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="tint">
 <a name="tint"></a>
 <h2>TINT<a class="headerlink" href="#tint" title="Link to this heading">¶</a></h2>
<p>Mixing colors (tint and or brightness)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">tint <span class="rebarg">target</span> <span class="rebarg">rgb</span> <span class="rebarg">amount</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  target      [<span class="types">tuple! image!</span>] Target RGB color or image (modifed)
  rgb         [<span class="types">tuple!</span>] Color to use for mixture
  amount      [<span class="types">number!</span>] Effect amount
</pre>
</section>

<hr>
<section id="title-of">
 <a name="title-of"></a>
 <h2>TITLE-OF<a class="headerlink" href="#title-of" title="Link to this heading">¶</a></h2>
<p>Returns a copy of the title of any function, datatype or module</p>

<h6>Usage:</h6>
<pre class="usage fs-6">title-of <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-function! datatype! module!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; title-of :print
== "Outputs a value followed by a line break."</code></pre></div>
<div class="see-also">See also: <a href="#body-of">body-of</a>, <a href="#reflect">reflect</a>, <a href="#spec-of">spec-of</a>, <a href="#types-of">types-of</a>, <a href="#values-of">values-of</a>, <a href="#words-of">words-of</a></div>
</section>

<hr>
<section id="to">
 <a name="to"></a>
 <h2>TO<a class="headerlink" href="#to" title="Link to this heading">¶</a></h2>
<p>Converts to a specified datatype.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to <span class="rebarg">type</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  type        [<span class="types">any-type!</span>] The datatype or example value
  value       [<span class="types">any-type!</span>] The attributes of the new value
</pre>

<h6>Description:</h6>
<p>
Every datatype provides a TO method to allow conversions from
other datatypes. The to-binary, to-block, and all other to-
functions are mezzanine functions that are based on this TO
function.
</p>
<p>
Here are a few examples:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe to file! "test.r"
%test.r

probe to path! [a b c]
a/b/c</code></pre></div><p>
The TO function lets the target datatype be specified as an
argument, allowing you to write code such as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">flag: true
value: to either flag [integer!][decimal!] "123"
print value
123</code></pre></div><p>
The conversions that are allowed depend on the specific
datatype. Some datatypes allow special conversions, such as:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print to integer! false
0

print to integer! true
1

print to logic! 1
true

print to time! 600  ; # of seconds
0:10</code></pre></div>
<div class="see-also">See also: <a href="#make">make</a></div>
</section>

<hr>
<section id="to-binary">
 <a name="to-binary"></a>
 <h2>TO-BINARY<a class="headerlink" href="#to-binary" title="Link to this heading">¶</a></h2>
<p>Converts to binary! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-binary <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a binary! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe to-binary "123456"
#{313233343536}</code></pre></div><p>
Notice, that the binary returned is not how the "actual storage" in computer memory looks. Instead, the bits are in "network order", which is, by convention, big endian:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">to-binary 1
#{0000000000000001}</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-bitset">
 <a name="to-bitset"></a>
 <h2>TO-BITSET<a class="headerlink" href="#to-bitset" title="Link to this heading">¶</a></h2>
<p>Converts to bitset! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-bitset <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a bitset! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe to-bitset [#"a" - #"z" #"A" - #"Z"]
make bitset! #{00000000000000007FFFFFE07FFFFFE0}</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-block">
 <a name="to-block"></a>
 <h2>TO-BLOCK<a class="headerlink" href="#to-block" title="Link to this heading">¶</a></h2>
<p>Converts to block! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-block <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a block! value made from the given value.
</p>
<p>
NOTE: The behavior of this function differs from Rebol2 and Red!
Conversions using <a href="#to">to</a> from non-blocks only wrap the value in a block of the specified type. Use <a href="#make">make</a> if you expect tokenization!
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-block "123 10:00"
== ["123 10:00"] ;; no tokenization!

&gt;&gt; make block! "123 10:00"
== [123 10:00]</code></pre></div><p>
For conversions from another block-like type, one can use the <a href="#as">as</a> function, which coerces the original value to another type without creating a new one.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; path: 'hello/world
== hello/world

&gt;&gt; blk: as block! path
== [hello world] ;; this value has coerced type

&gt;&gt; insert next blk 'cruel
== [world]

&gt;&gt; path
== hello/cruel/world ;; original value was modified too

&gt;&gt; append to-block path 42
== [hello cruel world 42] ;; this is new series value!

&gt;&gt; path
== hello/cruel/world ;; original value was not modified</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a>, <a href="#to-paren">to-paren</a>, <a href="#to-path">to-path</a></div>
</section>

<hr>
<section id="to-char">
 <a name="to-char"></a>
 <h2>TO-CHAR<a class="headerlink" href="#to-char" title="Link to this heading">¶</a></h2>
<p>Converts to char! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-char <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a char! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-char "a"
== #"a"

&gt;&gt; to-char 65
== #"A"</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-closure">
 <a name="to-closure"></a>
 <h2>TO-CLOSURE<a class="headerlink" href="#to-closure" title="Link to this heading">¶</a></h2>
<p>Converts to closure! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-closure <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="to-command">
 <a name="to-command"></a>
 <h2>TO-COMMAND<a class="headerlink" href="#to-command" title="Link to this heading">¶</a></h2>
<p>Converts to command! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-command <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>
</section>

<hr>
<section id="to-datatype">
 <a name="to-datatype"></a>
 <h2>TO-DATATYPE<a class="headerlink" href="#to-datatype" title="Link to this heading">¶</a></h2>
<p>Converts to datatype! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-datatype <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Can be used to convert a <span class="datatype">word!</span> containing a valid datatype name into a <span class="datatype">datatype!</span>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-datatype 'integer!
== #(integer!)

&gt;&gt; type? to-datatype 'integer!
== #(datatype!)

&gt;&gt; to-datatype "foo"

** Script error: cannot MAKE #(datatype!) from: "foo"</code></pre></div>
<div class="see-also">See also: <a href="#make">make</a>, <a href="#to">to</a></div>
</section>

<hr>
<section id="to-date">
 <a name="to-date"></a>
 <h2>TO-DATE<a class="headerlink" href="#to-date" title="Link to this heading">¶</a></h2>
<p>Converts to date! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-date <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] May be also a standard Internet date string/binary
<span class="tit">REFINEMENTS:</span>
  /utc        Returns the date with UTC zone
</pre>

<h6>Description:</h6>
<p>
Returns a date! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-date "12-April-1999"
== 12-Apr-1999</code></pre></div><p>
Also accepts a string in the Internet Message Date format (RFC2822).
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-date "Mon, 1 Apr 2019 21:50:04 GMT"
== 1-Apr-2019/21:50:04

&gt;&gt; to-date "Thu, 28 Mar 2019 20:00:59 +0100"
== 28-Mar-2019/20:00:59+1:00</code></pre></div><p>
When the input is of type <span class="datatype">integer!</span> or <span class="datatype">decimal!</span>, it is treated as a Unix timestamp.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-date 123456789
== 29-Nov-1973/21:33:09

&gt;&gt; encode 'unixtime 29-Nov-1973/21:33:09
== 123456789

&gt;&gt; to-date 1741600660.239
== 10-Mar-2025/9:57:40.239</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-decimal">
 <a name="to-decimal"></a>
 <h2>TO-DECIMAL<a class="headerlink" href="#to-decimal" title="Link to this heading">¶</a></h2>
<p>Converts to decimal! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-decimal <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a decimal! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-decimal 1
== 1.0

&gt;&gt; to-decimal 10-Mar-2025/9:57:40.239
== 1741600660.239 ;; Unix timestamp with a precision</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-degrees">
 <a name="to-degrees"></a>
 <h2>TO-DEGREES<a class="headerlink" href="#to-degrees" title="Link to this heading">¶</a></h2>
<p>Converts radians to degrees</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-degrees <span class="rebarg">radians</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  radians     [<span class="types">integer! decimal!</span>] Radians to convert
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-degrees pi
== 180.0</code></pre></div>
<div class="see-also">See also: <a href="#to-radians">to-radians</a></div>
</section>

<hr>
<section id="to-email">
 <a name="to-email"></a>
 <h2>TO-EMAIL<a class="headerlink" href="#to-email" title="Link to this heading">¶</a></h2>
<p>Converts to email! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-email <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns an email! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print to-email [luke rebol.com]
lukerebol.com</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-error">
 <a name="to-error"></a>
 <h2>TO-ERROR<a class="headerlink" href="#to-error" title="Link to this heading">¶</a></h2>
<p>Converts to error! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-error <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns an error! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe disarm try [to-error "Oops! My error."]
make object! [

code: 308
type: 'Script
id: 'cannot-use
arg1: 'to
arg2: unset!
arg3: none
near: [to error! :value]
where: [to to-error try do attempt if emit parse foreach catch if either if do begin do]</code></pre></div><p>
</p>
<p>
Note that this differs from TO and MAKE in that you
have to wrap the call in a TRY block to catch the
error it makes.
</p>

<div class="see-also">See also: <a href="#make">make</a>, <a href="#to">to</a></div>
</section>

<hr>
<section id="to-event">
 <a name="to-event"></a>
 <h2>TO-EVENT<a class="headerlink" href="#to-event" title="Link to this heading">¶</a></h2>
<p>Converts to event! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-event <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="to-file">
 <a name="to-file"></a>
 <h2>TO-FILE<a class="headerlink" href="#to-file" title="Link to this heading">¶</a></h2>
<p>Converts to file! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-file <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a file! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-file "test.txt"
== %test.txt</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a>, <a href="#to-local-file">to-local-file</a>, <a href="#to-rebol-file">to-rebol-file</a></div>
</section>

<hr>
<section id="to-function">
 <a name="to-function"></a>
 <h2>TO-FUNCTION<a class="headerlink" href="#to-function" title="Link to this heading">¶</a></h2>
<p>Converts to function! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-function <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; fun: to-function [[a][a * 10]]
&gt;&gt; fun 1
== 10</code></pre></div>
</section>

<hr>
<section id="to-get-path">
 <a name="to-get-path"></a>
 <h2>TO-GET-PATH<a class="headerlink" href="#to-get-path" title="Link to this heading">¶</a></h2>
<p>Converts to get-path! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-get-path <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">get-path!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-get-path [path to word]
== :path/to/word</code></pre></div>
</section>

<hr>
<section id="to-get-word">
 <a name="to-get-word"></a>
 <h2>TO-GET-WORD<a class="headerlink" href="#to-get-word" title="Link to this heading">¶</a></h2>
<p>Converts to get-word! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-get-word <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">get-word!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe to-get-word "test"
:test</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-gob">
 <a name="to-gob"></a>
 <h2>TO-GOB<a class="headerlink" href="#to-gob" title="Link to this heading">¶</a></h2>
<p>Converts to gob! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-gob <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="to-hash">
 <a name="to-hash"></a>
 <h2>TO-HASH<a class="headerlink" href="#to-hash" title="Link to this heading">¶</a></h2>
<p>Converts to hash! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-hash <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>
</section>

<hr>
<section id="to-hex">
 <a name="to-hex"></a>
 <h2>TO-HEX<a class="headerlink" href="#to-hex" title="Link to this heading">¶</a></h2>
<p>Converts numeric value to a hex issue! datatype (with leading # and 0's).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-hex <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">integer! char! tuple!</span>] Value to be converted
<span class="tit">REFINEMENTS:</span>
  /size       Specify number of hex digits in result
   len        [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
The TO-HEX function provides an easy way to convert an integer to
a hexidecimal value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-hex 123
== #000000000000007B</code></pre></div><p>
The value returned is a string of the ISSUE datatype (not the BINARY
datatype). This allows you to convert hex values back to integers:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-integer #7B
== 123</code></pre></div><p>
Note: To convert HTML hex color values (like #80FF80) to REBOL
color values, it is easier to do the conversion to binary and
then use a base 16 encoding:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">to-html-color: func [color [tuple!]] [
    to-issue enbase to-binary color 16
]
print to-html-color 255.155.50
FF9B32</code></pre></div><p>
The TO-ISSUE function is just used to add the # to it.
</p>
<p>
To convert from an HTML color back to a REBOL color tuple, you
can use this:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">to-rebol-color: func [color [issue!]] [
    to-tuple debase color 16
]
to-rebol-color #FF9B32</code></pre></div><p>
If the HTML color value is a string, convert it to an issue first.
The function below will work for strings and issues:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">to-rebol-color2: func [color [string! issue!]] [
    if string? color [
        if find/match color "#" [color: next color]
        color: to-issue color
    ]
    to-tuple debase color 16
]
to-rebol-color2 "#FF9B32"</code></pre></div>
<div class="see-also">See also: <a href="#to-integer">to-integer</a></div>
</section>

<hr>
<section id="to-idate">
 <a name="to-idate"></a>
 <h2>TO-IDATE<a class="headerlink" href="#to-idate" title="Link to this heading">¶</a></h2>
<p>Returns a standard Internet date string.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-idate <span class="rebarg">date</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  date        [<span class="types">date!</span>] 
<span class="tit">REFINEMENTS:</span>
  /gmt        Converts local time to GMT (Greenwich Mean Time)
</pre>
</section>

<hr>
<section id="to-image">
 <a name="to-image"></a>
 <h2>TO-IMAGE<a class="headerlink" href="#to-image" title="Link to this heading">¶</a></h2>
<p>Converts to image! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-image <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
This is a special conversion function that is used for
converting a FACE object (such as those created by the layout
function) into an image bitmap in memory.
</p>
<p>
For example, the code below converts the OUT layout to a bitmap
image, then writes it out as a PNG file:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">out: layout [
    h2 "Title"
    field
    button "Done"
]
image: to-image out
save/png %test-image.png image</code></pre></div><p>
This function provides a useful way to save REBOL generated
images for use in other programs or web pages (which also allows
you to print the images). For example, you can display the image
above in a web browser with this code:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">write %test-page.html trim/auto {
    &lt;html&gt;&lt;body&gt;
    &lt;h2&gt;Image:&lt;/h2&gt;
    &lt;img src="test-image.png"&gt;
    &lt;/body&gt;&lt;/html&gt;
}
browse %test-page.html
write</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-integer">
 <a name="to-integer"></a>
 <h2>TO-INTEGER<a class="headerlink" href="#to-integer" title="Link to this heading">¶</a></h2>
<p>Converts to integer! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-integer <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns an integer! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print to-integer "123"
123

print to-integer 123.9
123

print to-integer #"A" ; convert to the character value
65

print to-integer #102030 ; convert hex value (see to-hex for info)
1056816</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a>, <a href="#to-hex">to-hex</a></div>
</section>

<hr>
<section id="to-issue">
 <a name="to-issue"></a>
 <h2>TO-ISSUE<a class="headerlink" href="#to-issue" title="Link to this heading">¶</a></h2>
<p>Converts to issue! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-issue <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns an issue! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print to-issue "1234-56-7890"
1234-56-7890</code></pre></div><p>
To convert HTML RGB color values (that look like #000000), see
the to-hex function.
</p>

<div class="see-also">See also: <a href="#to">to</a>, <a href="#to-hex">to-hex</a></div>
</section>

<hr>
<section id="to-itime">
 <a name="to-itime"></a>
 <h2>TO-ITIME<a class="headerlink" href="#to-itime" title="Link to this heading">¶</a></h2>
<p>Returns a standard internet time string (two digits for each segment)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-itime <span class="rebarg">time</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  time        [<span class="types">time! number! block! none!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-itime now/time
== "09:46:03"</code></pre></div>
</section>

<hr>
<section id="to-json">
 <a name="to-json"></a>
 <h2>TO-JSON<a class="headerlink" href="#to-json" title="Link to this heading">¶</a></h2>
<p>Convert Rebol data to a JSON string</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-json <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data         
<span class="tit">REFINEMENTS:</span>
  /pretty     
   indent     [<span class="types">string!</span>] Pretty format the output, using given indentation
  /ascii      Force ASCII output (instead of UTF-8)
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-json #[a: 1 b: ["hello"]]
== {{"a":1,"b":["hello"]}}</code></pre></div><p>
<a href="#to-json">to-json</a> is basically the same as using <a href="#encode">encode</a>
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; encode 'json #[a: 1 b: ["hello"]]
== {{"a":1,"b":["hello"]}}</code></pre></div><p>
But it provides easy option for producing nicely formatted output.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-json/pretty #[a: 1 b: ["hello"]] "  "
== {{
  "a": 1,
  "b": [
    "hello"
  ]
}}</code></pre></div>
<div class="see-also">See also: <a href="#load-json">load-json</a></div>
</section>

<hr>
<section id="to-lit-path">
 <a name="to-lit-path"></a>
 <h2>TO-LIT-PATH<a class="headerlink" href="#to-lit-path" title="Link to this heading">¶</a></h2>
<p>Converts to lit-path! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-lit-path <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a lit-path! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-lit-path [a b c]
== 'a/b/c</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-lit-word">
 <a name="to-lit-word"></a>
 <h2>TO-LIT-WORD<a class="headerlink" href="#to-lit-word" title="Link to this heading">¶</a></h2>
<p>Converts to lit-word! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-lit-word <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a ilt-word! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-lit-word "test"
== 'test</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-local-file">
 <a name="to-local-file"></a>
 <h2>TO-LOCAL-FILE<a class="headerlink" href="#to-local-file" title="Link to this heading">¶</a></h2>
<p>Converts a REBOL file path to the local system file path.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-local-file <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file! string!</span>] 
<span class="tit">REFINEMENTS:</span>
  /full       Prepends current dir for full path (for relative paths only)
</pre>

<h6>Description:</h6>
<p>
This function provides a way to convert standard, system
independent REBOL file formats into the file format used by
the local operating system.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe to-local-file %/c/temp
"c:\temp"

probe to-local-file what-dir
"C:\REBOL\3.0\docs\scripts\"</code></pre></div><p>
Note that the format of the file path depends on your local
system. Be careful how you use this function across systems.
</p>

<div class="see-also">See also: <a href="#to-file">to-file</a>, <a href="#to-rebol-file">to-rebol-file</a></div>
</section>

<hr>
<section id="to-logic">
 <a name="to-logic"></a>
 <h2>TO-LOGIC<a class="headerlink" href="#to-logic" title="Link to this heading">¶</a></h2>
<p>Converts to logic! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-logic <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a logic! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print to-logic 1
print to-logic 0
false</code></pre></div>
<div class="see-also">See also: <a href="#make">make</a>, <a href="#to">to</a></div>
</section>

<hr>
<section id="to-map">
 <a name="to-map"></a>
 <h2>TO-MAP<a class="headerlink" href="#to-map" title="Link to this heading">¶</a></h2>
<p>Converts to map! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-map <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-map [a: 1 b: 2]
== #[
    a: 1
    b: 2
]</code></pre></div>
<div class="see-also">See also: <a href="#make">make</a>, <a href="#to">to</a></div>
</section>

<hr>
<section id="to-module">
 <a name="to-module"></a>
 <h2>TO-MODULE<a class="headerlink" href="#to-module" title="Link to this heading">¶</a></h2>
<p>Converts to module! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-module <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>

<div class="see-also">See also: <a href="#make">make</a>, <a href="#to">to</a></div>
</section>

<hr>
<section id="to-money">
 <a name="to-money"></a>
 <h2>TO-MONEY<a class="headerlink" href="#to-money" title="Link to this heading">¶</a></h2>
<p>Converts to money! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-money <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a money! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-money 123.4
== $123.4</code></pre></div><p>
NOTE: Currency types are not supported yet!
</p>

<div class="see-also">See also: <a href="#make">make</a>, <a href="#to">to</a></div>
</section>

<hr>
<section id="to-object">
 <a name="to-object"></a>
 <h2>TO-OBJECT<a class="headerlink" href="#to-object" title="Link to this heading">¶</a></h2>
<p>Converts to object! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-object <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
This function currently works only for conversions from an <span class="datatype">error!</span> value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-object try [1 / 0]
== make object! [
    code: 400
    type: 'Math
    id: 'zero-divide
    arg1: #(none)
    arg2: #(none)
    arg3: #(none)
    near: [/ 0]
    where: [/ try]
]</code></pre></div>
<div class="see-also">See also: <a href="#make">make</a>, <a href="#to">to</a></div>
</section>

<hr>
<section id="to-pair">
 <a name="to-pair"></a>
 <h2>TO-PAIR<a class="headerlink" href="#to-pair" title="Link to this heading">¶</a></h2>
<p>Converts to pair! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-pair <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a pair! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-pair [120 50]
== 120x50

&gt;&gt; x: 100 y: 50
&gt;&gt; to-pair reduce [x y]
== 100x50</code></pre></div><p>
This last line is done so often that the <a href="#as-pair">as-pair</a> function was created.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; as-pair x y
== 100x50</code></pre></div>
<div class="see-also">See also: <a href="#as-pair">as-pair</a>, <a href="#pair?">pair?</a>, <a href="#to">to</a></div>
</section>

<hr>
<section id="to-paren">
 <a name="to-paren"></a>
 <h2>TO-PAREN<a class="headerlink" href="#to-paren" title="Link to this heading">¶</a></h2>
<p>Converts to paren! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-paren <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a paren! value made from the given value.
</p>
<p>
NOTE: The behavior of this function differs from Rebol2 and Red!
Conversions using <a href="#to">to</a> from non-blocks only wrap the value in a block of the specified type. Use <a href="#make">make</a> if you expect tokenization!
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-paren "123 456"
== ("123 456")

&gt;&gt; make paren! "123 456"
== (123 456)</code></pre></div><p>
For conversions from another block-like type, one can use the <a href="#as">as</a> function, which coerces the original value to another type without creating a new one.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; blk: ["hello" "world"]
== ["hello" "world"]

&gt;&gt; par: as paren! blk
== ("hello" "world")

&gt;&gt; uppercase par/2
== "WORLD"

&gt;&gt; blk
== ["hello" "WORLD"]</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a>, <a href="#to-block">to-block</a>, <a href="#to-path">to-path</a></div>
</section>

<hr>
<section id="to-path">
 <a name="to-path"></a>
 <h2>TO-PATH<a class="headerlink" href="#to-path" title="Link to this heading">¶</a></h2>
<p>Converts to path! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-path <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a path! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">colors: make object! [reds: ["maroon" "brick" "sunset"]]
p-reds: to-path [colors reds]
print form :p-reds
colors/reds

print p-reds
colors/reds

insert tail p-reds "bright"
print colors/reds
maroon brick sunset

print p-reds
colors/reds/"bright"</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a>, <a href="#to-block">to-block</a>, <a href="#to-paren">to-paren</a></div>
</section>

<hr>
<section id="to-percent">
 <a name="to-percent"></a>
 <h2>TO-PERCENT<a class="headerlink" href="#to-percent" title="Link to this heading">¶</a></h2>
<p>Converts to percent! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-percent <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="to-port">
 <a name="to-port"></a>
 <h2>TO-PORT<a class="headerlink" href="#to-port" title="Link to this heading">¶</a></h2>
<p>Converts to port! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-port <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a port! value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe to-port [scheme: 'checksum]</code></pre></div>
<div class="see-also">See also: <a href="#make">make</a>, <a href="#to">to</a></div>
</section>

<hr>
<section id="to-radians">
 <a name="to-radians"></a>
 <h2>TO-RADIANS<a class="headerlink" href="#to-radians" title="Link to this heading">¶</a></h2>
<p>Converts degrees to radians</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-radians <span class="rebarg">degrees</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  degrees     [<span class="types">integer! decimal!</span>] Degrees to convert
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-radians 180.0
== 3.14159265358979</code></pre></div>
<div class="see-also">See also: <a href="#to-degrees">to-degrees</a></div>
</section>

<hr>
<section id="to-real-file">
 <a name="to-real-file"></a>
 <h2>TO-REAL-FILE<a class="headerlink" href="#to-real-file" title="Link to this heading">¶</a></h2>
<p>Returns canonicalized absolute pathname. On Posix resolves symbolic links and returns NONE if file does not exists!</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-real-file <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file! string!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-real-file %../Rebol
== %/C/Users/oldes/Rebol/

&gt;&gt; to-real-file ".."
== %/C/Users/oldes/</code></pre></div>
<div class="see-also">See also: <a href="#to-local-file">to-local-file</a>, <a href="#to-rebol-file">to-rebol-file</a>, <a href="#what-dir">what-dir</a></div>
</section>

<hr>
<section id="to-rebol-file">
 <a name="to-rebol-file"></a>
 <h2>TO-REBOL-FILE<a class="headerlink" href="#to-rebol-file" title="Link to this heading">¶</a></h2>
<p>Converts a local system file path to a REBOL file path.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-rebol-file <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file! string!</span>] 
</pre>

<h6>Description:</h6>
<p>
This function provides a standard way to convert local operating
system files into REBOL's standard machine independent format.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-rebol-file %../Rebol
== %../Rebol

&gt;&gt; to-rebol-file "../Rebol"
== %../Rebol

&gt;&gt; to-rebol-file "C:\Program Files\"
== %/C/Program%20Files/</code></pre></div><p>
Note that the format of the file path depends on your local
system. Be careful how you use this function across systems.
</p>

<div class="see-also">See also: <a href="#to-local-file">to-local-file</a>, <a href="#to-real-file">to-real-file</a></div>
</section>

<hr>
<section id="to-ref">
 <a name="to-ref"></a>
 <h2>TO-REF<a class="headerlink" href="#to-ref" title="Link to this heading">¶</a></h2>
<p>Converts to ref! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-ref <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">ref!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-ref "Oldes"
== @Oldes</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-refinement">
 <a name="to-refinement"></a>
 <h2>TO-REFINEMENT<a class="headerlink" href="#to-refinement" title="Link to this heading">¶</a></h2>
<p>Converts to refinement! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-refinement <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">refinement!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-refinement 'REBOL
== /REBOL</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-relative-file">
 <a name="to-relative-file"></a>
 <h2>TO-RELATIVE-FILE<a class="headerlink" href="#to-relative-file" title="Link to this heading">¶</a></h2>
<p>Returns the relative portion of a file if in a subdirectory, or the original if not.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-relative-file <span class="rebarg">file</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  file        [<span class="types">file! string!</span>] File to check (local if string!)
<span class="tit">REFINEMENTS:</span>
  /no-copy    Don't copy, just reference
  /as-rebol   Convert to REBOL-style filename if not
  /as-local   Convert to local-style filename if not
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="-block"><code class="">&gt;&gt; what-dir
== %/C/Users/oldes/Rebol/

&gt;&gt; to-relative-file %/C/Users/Oldes/Rebol/temp
== %temp</code></pre></div>
<div class="see-also">See also: <a href="#to-real-file">to-real-file</a>, <a href="#what-dir">what-dir</a></div>
</section>

<hr>
<section id="to-set-path">
 <a name="to-set-path"></a>
 <h2>TO-SET-PATH<a class="headerlink" href="#to-set-path" title="Link to this heading">¶</a></h2>
<p>Converts to set-path! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-set-path <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">set-path!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-set-path [some path]
== some/path:</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a>, <a href="#to-get-path">to-get-path</a>, <a href="#to-lit-path">to-lit-path</a>, <a href="#to-path">to-path</a></div>
</section>

<hr>
<section id="to-set-word">
 <a name="to-set-word"></a>
 <h2>TO-SET-WORD<a class="headerlink" href="#to-set-word" title="Link to this heading">¶</a></h2>
<p>Converts to set-word! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-set-word <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">set-word!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-set-word "test"
== test:</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a>, <a href="#to-get-word">to-get-word</a>, <a href="#to-lit-word">to-lit-word</a>, <a href="#to-word">to-word</a></div>
</section>

<hr>
<section id="to-string">
 <a name="to-string"></a>
 <h2>TO-STRING<a class="headerlink" href="#to-string" title="Link to this heading">¶</a></h2>
<p>Converts to string! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-string <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">string!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-string [123 456]
== "123456"</code></pre></div>
<div class="see-also">See also: <a href="#form">form</a>, <a href="#mold">mold</a>, <a href="#to">to</a></div>
</section>

<hr>
<section id="to-tag">
 <a name="to-tag"></a>
 <h2>TO-TAG<a class="headerlink" href="#to-tag" title="Link to this heading">¶</a></h2>
<p>Converts to tag! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-tag <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">tag!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-tag ";comment:"
== &lt;;comment:&gt;</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-time">
 <a name="to-time"></a>
 <h2>TO-TIME<a class="headerlink" href="#to-time" title="Link to this heading">¶</a></h2>
<p>Converts to time! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-time <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">time!</span> value made from the given value.
</p>
<p>
Integer and decimal values are interpreted as a number of seconds.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-time 75
== 0:01:15

&gt;&gt; to-time 75.5
== 0:01:15.5</code></pre></div><p>
A block may contain up to three values. The first two must be 
integers, and correspond to the hour and minute values. The
third value can be an integer or decimal value, and corresponds
to the number of seconds.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-time [0 1 15.5]
== 0:01:15.5</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a>, <a href="#to-date">to-date</a>, <a href="#to-itime">to-itime</a></div>
</section>

<hr>
<section id="to-tuple">
 <a name="to-tuple"></a>
 <h2>TO-TUPLE<a class="headerlink" href="#to-tuple" title="Link to this heading">¶</a></h2>
<p>Converts to tuple! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-tuple <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">tuple!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-tuple [12 34 56]
== 12.34.56</code></pre></div><p>
To convert REBOL RGB color tuples to HTML hex color values, see
the <a href="#to-hex">to-hex</a> function.
</p>
<p>
Tuples can have up to 12 segments.
</p>

<div class="see-also">See also: <a href="#to">to</a>, <a href="#to-hex">to-hex</a></div>
</section>

<hr>
<section id="to-typeset">
 <a name="to-typeset"></a>
 <h2>TO-TYPESET<a class="headerlink" href="#to-typeset" title="Link to this heading">¶</a></h2>
<p>Converts to typeset! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-typeset <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">typeset!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; types: to-typeset [string! file! url!]
== make typeset! [string! file! url!]

&gt;&gt; find types #(url!)
== #(true)</code></pre></div>
</section>

<hr>
<section id="to-url">
 <a name="to-url"></a>
 <h2>TO-URL<a class="headerlink" href="#to-url" title="Link to this heading">¶</a></h2>
<p>Converts to url! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-url <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">url!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-url "http://www.rebol.com"
== http://www.rebol.com</code></pre></div>
<div class="see-also">See also: <a href="#as">as</a>, <a href="#to">to</a></div>
</section>

<hr>
<section id="to-value">
 <a name="to-value"></a>
 <h2>TO-VALUE<a class="headerlink" href="#to-value" title="Link to this heading">¶</a></h2>
<p>Returns the value if it is a value, NONE if unset.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-value <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-value ()
== #(none)

&gt;&gt; to-value 1
== 1

&gt;&gt; to-value #(unset)
== #(none)</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a></div>
</section>

<hr>
<section id="to-vector">
 <a name="to-vector"></a>
 <h2>TO-VECTOR<a class="headerlink" href="#to-vector" title="Link to this heading">¶</a></h2>
<p>Converts to vector! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-vector <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Currently, <a href="#to-vector">to-vector</a> can only be used with a valid vector specification.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-vector [uint8! 3]
== make vector! [unsigned integer! 8 3 [0 0 0]]

&gt;&gt; to-vector [int16! [1 2 3]]
== make vector! [integer! 16 3 [1 2 3]]</code></pre></div><p>
Vectors can be created using construction syntax.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; #(uint8! 3)
== make vector! [unsigned integer! 8 3 [0 0 0]]

&gt;&gt; #(int16! [1 2 3])
== make vector! [integer! 16 3 [1 2 3]]</code></pre></div><p>
Currently there are these vector types:
* Signed integers: <span class="datatype">int8!</span>, <span class="datatype">int16!</span>, <span class="datatype">int32!</span>, <span class="datatype">int64!</span>
* Unsigned integers: <span class="datatype">uint8!</span>, <span class="datatype">uint16!</span>, <span class="datatype">uint32!</span>, <span class="datatype">uint64!</span>
* 32bit decimal: <span class="datatype">float!</span>
* 64bit decimal: <span class="datatype">double!</span>
</p>

</section>

<hr>
<section id="to-word">
 <a name="to-word"></a>
 <h2>TO-WORD<a class="headerlink" href="#to-word" title="Link to this heading">¶</a></h2>
<p>Converts to word! value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">to-word <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Returns a <span class="datatype">word!</span> value made from the given value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; to-word "test"
== test</code></pre></div>
<div class="see-also">See also: <a href="#to">to</a>, <a href="#to-get-word">to-get-word</a>, <a href="#to-lit-word">to-lit-word</a>, <a href="#to-set-word">to-set-word</a></div>
</section>

<hr>
<section id="trace">
 <a name="trace"></a>
 <h2>TRACE<a class="headerlink" href="#trace" title="Link to this heading">¶</a></h2>
<p>Enables and disables evaluation tracing and backtrace.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">trace <span class="rebarg">mode</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  mode        [<span class="types">integer! logic!</span>] 
<span class="tit">REFINEMENTS:</span>
  /back       Set mode ON to enable or integer for lines to display
  /function   Traces functions only (less output)
</pre>

<h6>Description:</h6>
<p>
The <a href="#trace">trace</a> lets you watch the evaluation of your script, expression by expression.
</p>
<p>
The three most common arguments to <a href="#trace">trace</a> are shown here:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">trace on   ; turn on trace
trace off  ; turn off trace
trace 5    ; turn on, but trace only 5 levels deep</code></pre></div><p>
Once enabled, when you evaluate an expression, you will see each step as a single line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; print 123
 1: print : native! [value]
 2: 123
--&gt; print
123
&lt;-- print == unset!</code></pre></div>
<h6>Understanding the format</h6><p>
The <a href="#trace">trace</a> format uses these formatting notations to indicate what your code is doing:
</p>
<table class="doctable">
<tr><th align="top">
Notation
</th><th valign="top">
Meaning
</th>
<tr>
<td valign="top">
(indent)
</td><td valign="top">
The indentation for each line indicates the depth of the code.
</td>
<tr>
<td valign="top">
<div class="codeline">N:</div>
</td><td valign="top">
The index number of the value in the code block (that is to be evaluated.)
</td>
<tr>
<td valign="top">
<div class="codeline">--&gt;</div>
</td><td valign="top">
Entry into a function, followed by its formal argument list.
</td>
<tr>
<td valign="top">
<div class="codeline">&lt;--</div>
</td><td valign="top">
Return from a function, followed by the value it returned (==).
</td></tr></table>
<h7>Simple example</h7><p>
To help understand the format, here's a description for each line in the earlier example:
</p>
<table class="doctable">
<tr><th align="top">
Code
</th><th valign="top">
Meaning
</th>
<tr>
<td valign="top">
<div class="codeline">&gt;&gt; print 123</div>
</td><td valign="top">
Typed into the console to evaluate.
</td>
<tr>
<td valign="top">
<div class="codeline">1: print : native! [value]</div>
</td><td valign="top">
The value at block index 1 is the word <a href="#print">print</a>. It's value is looked up and found to be a <span class="datatype">native!</span> function that takes value as an argument.
</td>
<tr>
<td valign="top">
<div class="codeline">2: 123</div>
</td><td valign="top">
The value at block index 2 is the integer 123.
</td>
<tr>
<td valign="top">
<div class="codeline">--&gt; print</div>
</td><td valign="top">
The argument is valid and the <a href="#print">print</a> function is entered. The --&gt; means "enter into the function."
</td>
<tr>
<td valign="top">
<div class="codeline">123</div>
</td><td valign="top">
Output is printed.
</td>
<tr>
<td valign="top">
<div class="codeline">&lt;-- print == unset!</div>
</td><td valign="top">
The <a href="#print">print</a> function returns, but it has no return value (it is unset.) The &lt;-- means "return from the function."
</td></tr></table>
<h7>Larger example</h7><p>
Here is a user defined function to compute the average of a block of numbers.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">ave: func [nums [block!] /local val][
    val: 0
    foreach num nums [val: val + num]
    val / length? nums
]</code></pre></div><p>
Tracing the evaluation, you will see how each new level is indented and begins a new sequence of index numbers. Notice also the <a href="#foreach">foreach</a> loop.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; ave [1 2 3]
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
<h6>Minimizing the output</h6><p>
At times the trace output will be a lot more than you want. The trick becomes how to cut it down without losing the information you need.. There are three methods:
</p>
<p>
<ol>
<li>Specify a trace depth.</li>
<li>Locate the <a href="#trace">trace</a> on and off lines deeper within your code.</li>
<li>Trace only functions, not all values.</li>
<li>Use the backtrace option. (see more below)</li>
</ol>
</p>

<h7>Setting trace depth</h7><p>
Using the example above, set the trace depth to 2, and run it again. You will see:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; trace 2
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
== 2</code></pre></div><p>
The output has been reduced. You no longer see the foreach loop operate.
</p>

<h7>Locating trace within your code</h7><p>
Most of the time you don't need to trace your entire program, just part of it. So, it is useful just to put <a href="#trace">trace</a> in your code where you need it.
</p>
<p>
Using the same example as above:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">ave: func [nums [block!] /local val][
    val: 0
    trace on
    foreach num nums [val: val + num]
    trace off
    val / length? nums
]</code></pre></div><p>
You will now see:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; ave [1 2 3]
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
<h7>Tracing functions only</h7><p>
With the /function refinement you can trace just function calls and their returns. The evaluation of each code block value is not shown, saving a few lines.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; trace/function on
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
&lt;-- ave == 2</code></pre></div><p>
In this mode, the function call lines will show the arguments passed to the functions. (A dot is used to show NONE value slots, such as those for unused refinements or local variables.)
</p>

<h6>Backtrace</h6><p>
At times it is important to know what your code was doing immediately before a crash. In such cases, you don't want to see trace output until after the crash. That is the purpose of the /back refinement: to tell <a href="#trace">trace</a> to redirect its output to an internal buffer that you can examine later.
</p>
<p>
To enable backtrace:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; trace/back on</code></pre></div><p>
Then, run your code. When your crash occurs, type:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; trace/back 20</code></pre></div><p>
to see the last 20 lines (or however many lines you want to see.)
</p>
<p>
You can also modify your trace depth as you would normally. For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; trace/back on
&gt;&gt; trace 5</code></pre></div><p>
will only trace down five levels of code.
</p>
<p>
When you are done with the backtrace, you can disable it with:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; trace/back off</code></pre></div><p>
and that will also free memory used by the backtrace buffer.
</p>
<p>
To use backtrace with the /function refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; trace/back/function on</code></pre></div><p>
This will also speed-up trace evaluation.
</p>

<h7>Example backtrace</h7><p>
Here is an example session:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; trace/back on
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
--&gt; trace</code></pre></div><p>
So, it's not hard to see what was going on when the script crashed. Backtrace can be quite handy when you need it.
</p>

<h7>Important notes</h7><ul>
<li>Tracing is disabled automatically when you display the backtrace. (This prevents additional accumulation of trace information, allowing you to redisplay the buffer without interference from additional console lines.)</li>
<li>Backtrace will slow down your program by a factor of 20 (because for each value that is evaluated, it must store a log record).</li>
<li>The internal backtrace buffer is 100KB. On average, the most it will hold is 100 pages of backtrace.</li>
<li>Enabling normal trace will disable backtrace and delete the backtrace buffer.</li>
<li>Backtrace may interfere with some kinds of tracing, especially if the bug is related to a defect within the REBOL interpreter itself.</li>
</ul><p>
The <a href="#stack">stack</a> function can also be used to show stack related backtrace information.
</p>

<div class="see-also">See also: <a href="#echo">echo</a>, <a href="#probe">probe</a>, <a href="#stack">stack</a></div>
</section>

<hr>
<section id="transcode">
 <a name="transcode"></a>
 <h2>TRANSCODE<a class="headerlink" href="#transcode" title="Link to this heading">¶</a></h2>
<p>Translates UTF-8 binary source to values. Returns one or several values in a block.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">transcode <span class="rebarg">source</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  source      [<span class="types">binary! string!</span>] UTF-8 input buffer; string argument will be UTF-8 encoded
<span class="tit">REFINEMENTS:</span>
  /next       Translate next complete value (blocks as single value)
  /one        Translate next complete value (returns the value only)
  /only       Translate only a single value (blocks dissected)
  /error      Do not cause errors - return error object as value in place
  /line       Return also information about number of lines scaned
   count      [<span class="types">integer!</span>] Initial line number
  /part       Translates only part of the input buffer
   length     [<span class="types">integer!</span>] Length of source to decode
</pre>

<h6>Description:</h6>
<p>
The <a href="#transcode">transcode</a> function translates source code and data into the block value memory format that can be interpreted by REBOL.
</p>

<h6>Input</h6><p>
The source input to <a href="#transcode">transcode</a> must be Unicode UTF-8. This is a <span class="datatype">binary!</span> encoded format, and should not be confused with a <span class="datatype">string!</span>, which is a decoded in-memory indexable string.
</p>
<p>
If you need to <a href="#transcode">transcode</a> a string, you must convert it to a UTF-8 binary first. This can be done with <a href="#to-binary">to-binary</a>.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: transcode to-binary string</code></pre></div><fieldset class="fset"><legend>Reduced efficiency</legend>
<p>In general, conversions to and from UTF-8 require extra time to for the Unicode conversion process. Therefore, is not a good idea to write REBOL code like TCL or PERL where computations are done on strings.</p>
<p>Don't write code such as:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do append "1 +" n</code></pre></div>
<p>Because you can just as easily write:</p>
<div class="example-code"><pre class="code-block"><code class="rebol">do append [1 +] n</code></pre></div>
<p>in REBOL.</p>
</fieldset>
<h6>Refinements</h6><p>
Without refinements, <a href="#transcode">transcode</a> will convert the entire input string.
</p>
<p>
Refinements are provided for partial translation:
</p>
<table class="doctable">
<tr><td valign="top" nowrap><b>/next</b></td><td valign="top" width="95%">Translate the next full value. If it is a block, translate the entire block.
</td></tr>
<tr><td valign="top" nowrap><b>/only</b></td><td valign="top" width="95%">Translate the next singular value. If it is a block, translate only the first element of the block, and return it within a block.
</td></tr>
<tr><td valign="top" nowrap><b>/error</b></td><td valign="top" width="95%">Convert syntax errors to error objects and output them rather than throwing them as an error.
</td></tr>
</table><p>
These refinements can be used in various ways to parse REBOL source a value at a time.
</p>

<h6>Output</h6><p>
The output from <a href="#transcode">transcode</a> is a <span class="datatype">block!</span> containing two values:
</p>
<p>
<ol>
<li>The translated value, block of values, or <span class="datatype">error!</span> object.</li>
<li>The <span class="datatype">binary!</span> source at the point where the translation ended.</li>
</ol>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">a: to-binary "a b c"
#{6120622063}

transcode/only a
[a #{20622063}]</code></pre></div>
<div class="see-also">See also: <a href="#to-block">to-block</a></div>
</section>

<hr>
<section id="trim">
 <a name="trim"></a>
 <h2>TRIM<a class="headerlink" href="#trim" title="Link to this heading">¶</a></h2>
<p>Removes spaces from strings, nulls from binary, nones from blocks or objects.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">trim <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series! object! error! module!</span>] Series (modified) or object (made)
<span class="tit">REFINEMENTS:</span>
  /head       Removes only from the head
  /tail       Removes only from the tail
  /auto       Auto indents lines relative to first line
  /lines      Removes all line breaks and extra spaces
  /all        Removes all whitespace
  /with       
   str        [<span class="types">char! string! binary! integer!</span>] Same as /all, but removes characters in 'str'
</pre>

<h6>Description:</h6>
<p>
Trim removes unwanted values, normally it trims whitespace from a <span class="datatype">string!</span> or <span class="datatype">none!</span> values from a <span class="datatype">block!</span> or <span class="datatype">object!</span>.
</p>
<p>
Here is an example of a string:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "  string   "
probe trim str
"string"</code></pre></div><p>
Note that the str is modified. To avoid that, use copy:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">new-str: trim copy str</code></pre></div><p>
For a <span class="datatype">block!</span> :
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">trim reduce [none 'a none 'b none]
[a b]</code></pre></div><p>
It removes the <span class="datatype">none!</span> values from the block. (And it will also remove <span class="datatype">unset!</span> values as well.)
</p>
<p>
Note that the block is modified. But, in this example, <a href="#reduce">reduce</a> creates a unique copy, so the original is not effected.
</p>
<p>
And for an <span class="datatype">object!</span> :
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">trim system/options
make object! [
    home: %/C/Program%20Files/
    path: %/C/rebol/r3/
    boot: %/C/rebol/r3/view.exe
    binary-base: 16
    decimal-digits: 15
]</code></pre></div><p>
Because object fields cannot be removed (due to binding) the result of <a href="#trim">trim</a> of an object is always to return a new shallow object. (The values of the object are not deep-copied or rebound.)
</p>
<p>
The new object only shows fields that have actual value (not none or unset.)
</p>

<h6>Details on trimming strings</h6><p>
The default for TRIM is to remove whitespace characters (tabs
and spaces) from the heads and tails of every line of a string.
Empty leading and trailing lines are also trimmed.
</p>
<p>
When a string includes multiple lines, the head and tail
whitespace will be trimmed from each line (but not within the
line):
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: {
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
}</code></pre></div><p>
The line terminator of the final line is preserved.
</p>
<p>
As mentioned above, empty leading and trailing lines are also
trimmed:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe trim {

    Non-empty line.
    Non-empty line.
    Non-empty line.

}
{Non-empty line.
Non-empty line.
Non-empty line.
}</code></pre></div><p>
Note that TRIM modifies the string in the process.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "  string   "
trim str
probe str
"string"</code></pre></div><p>
TRIM does not copy the string. If that's what you want, then use
TRIM with COPY to copy the string before trimming it.
</p>
<p>
Several refinements to TRIM are available. To trim just the head
and/or tail of a string you can use the /HEAD or /TAIL refinements.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe trim/head "  string  "
"string  "

probe trim/tail "  string  "
"  string"

probe trim/head/tail "  string  "
"string"</code></pre></div><p>
When using /HEAD or /TAIL, multiple lines are not affected:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe trim/head {  line 1
    line 2
    line 3
}
{line 1
line 2
line 3
}</code></pre></div><p>
To trim just the head and tail of a multiline string, but none
of its internal spacing:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: {  line 1
    line 2
        line 3
            line 4
                line 5  }
probe trim/head/tail str
{line 1
line 2
    line 3
        line 4
            line 5}</code></pre></div><p>
If you use TRIM/LINES then all lines and extra spaces will be
removed from the text. This is useful for word wrapping and web
page kinds of applications.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: {
    Now   is
    the
    winter
}
probe trim/lines str
"Now is^/the^/winter"</code></pre></div><p>
You can also remove /ALL space:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe trim/all " Now is   the winter "
"Nowisthewinter"

str: {
    Now   is
    the
    winter
}
probe trim/all str
"Nowisthewinter"</code></pre></div><p>
One of the most useful TRIM refinements is /AUTO which will do a
"smart" trim of the indentation of text lines. This mode detects
the indentation from the first line and preserves indentation
for the lines to follow:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">probe trim/auto {
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
 }</code></pre></div><p>
This is useful for sections of text that are embedded within
code and indented to the level of the code.
</p>
<p>
To trim other characters, the /WITH refinement is provided.
It takes an additional string that specifies what characters
to be removed.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: {This- is- a- line.}
probe trim/with str "-"
"This is a line."

str: {This- is- a- line.}
probe trim/with str "- ."
"Thisisaline"</code></pre></div>
<h6>TRIM on blocks</h6><p>
When <a href="#trim">trim</a> is used on a <span class="datatype">block!</span>, it strips all <span class="datatype">none!</span> values from the block:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">trim reduce [1 2 none]
[1 2]</code></pre></div><p>
Note that <a href="#trim">trim</a> modifies the argument block.
</p>

<h6>TRIM on objects</h6><p>
When <a href="#trim">trim</a> is used on an <span class="datatype">object!</span>, it will return a new object that has all <span class="datatype">none!</span> values removed:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">obj: make object [arg1: 10 arg2: none]
trim obj
make object! [
    arg1: 10
]</code></pre></div>
<div class="see-also">See also: <a href="#clear">clear</a>, <a href="#parse">parse</a>, <a href="#remove">remove</a></div>
</section>

<hr>
<section id="true?">
 <a name="true?"></a>
 <h2>TRUE?<a class="headerlink" href="#true?" title="Link to this heading">¶</a></h2>
<p>Returns true if an expression can be used as true.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">true? <span class="rebarg">val</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  val         [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; true? 1
== #(true)

&gt;&gt; true? 2
== #(true)

&gt;&gt; true? none
== #(false)

&gt;&gt; true? off
== #(false)</code></pre></div><p>
Note that <span class="datatype">unset!</span> value is truthy!
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; true? #(unset)
== #(true)</code></pre></div>
<div class="see-also">See also: <a href="#false?">false?</a></div>
</section>

<hr>
<section id="truncate">
 <a name="truncate"></a>
 <h2>TRUNCATE<a class="headerlink" href="#truncate" title="Link to this heading">¶</a></h2>
<p>Removes all bytes/values from series' head to its current index position</p>

<h6>Usage:</h6>
<pre class="usage fs-6">truncate <span class="rebarg">series</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  series      [<span class="types">series!</span>] Series to be truncated
<span class="tit">REFINEMENTS:</span>
  /part       Also shorten resulted series to a length or end position
   range      [<span class="types">number! series!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; str: "12345"
== "12345"

&gt;&gt; truncate skip str 3
== "45"</code></pre></div><p>
This function is useful for removing processed data from an input buffer.
</p>

<div class="see-also">See also: <a href="#remove">remove</a>, <a href="#take">take</a></div>
</section>

<hr>
<section id="try">
 <a name="try"></a>
 <h2>TRY<a class="headerlink" href="#try" title="Link to this heading">¶</a></h2>
<p>Tries to DO a block and returns its value or an error!.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">try <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block! paren!</span>] 
<span class="tit">REFINEMENTS:</span>
  /all        Catch also BREAK, CONTINUE, RETURN, EXIT and THROW exceptions.
  /with       On error, evaluate the handler and return its result
   handler    [<span class="types">block! any-function!</span>] 
  /except     ** DEPRERCATED **
   code       [<span class="types">block! any-function!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#try">try</a> function evaluates a block and will capture any errors that occur during that evaluation.
</p>
<p>
The purpose of <a href="#try">try</a> is to give your own code the opportunity to handle errors, rather than causing your program to terminate with an error message.
</p>
<p>
For example, in this line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">try [delete %afile.txt]</code></pre></div><p>
if the file does not exist, then the error will not cause your program to terminate.
</p>

<h6>Return Value</h6><p>
The <a href="#try">try</a> function returns an error value if an error happened, otherwise it returns the normal result of the block.
</p>
<p>
Taking the above example, we can do something special if an error happened:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if error? try [delete %afile.txt] [print "delete failed"]</code></pre></div><p>
or, even use the error value itself:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if error? err: try [delete %afile.txt] [print ["delete failed:" mold err]]</code></pre></div><p>
Sometimes you'll want to use the value that was returned:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">either error? val: try [1 + "x"] [print "nope"] [print val]
nope

either error? val: try [1 + 2] [print "nope"] [print val]
3</code></pre></div>
<h6>Exception Handling</h6><p>
The <a href="#try">try</a> function is for error handling, but there are times when you may be returning error objects as values, and you cannot distinguish between an error occurring and the error value itself. This is case rare, but it does happen.
</p>
<p>
For this situation the <a href="#/with">/with</a> refinement is provided. If an error occurs, it will evaluate a exception handling function (or just a block). This indicates that an error exception happened (not just an error value being passed.)
</p>
<p>
The example below will catch the "zero-divide" error within a function. The error is passed as the argument to the exception function, and a value (zero in this case) is returned from the <a href="#try">try</a> function:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; try/with [1 / 0] :print

** Math error: attempt to divide by zero
** Where: / try
** Near: / 0</code></pre></div><p>
Or to provide a default value in case of the error:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; try/with [1 / 0] ['oh-no]
== oh-no</code></pre></div><p>
Last error is stored in the <a href="#system/state">system/state</a> object and may be used like:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; try [1 / 0]

** Math error: attempt to divide by zero
** Where: / try
** Near: / 0

&gt;&gt; system/state/last-error

** Math error: attempt to divide by zero
** Where: / try
** Near: / 0</code></pre></div>
<h6>Shortcut</h6><p>
The <a href="#attempt">attempt</a> function is shortcut for the common pattern where you don't care about the specific error, and mainly just want the non-error result.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">data: attempt [load %data.r]</code></pre></div><p>
The data will be either the data or none, if it failed to load.
</p>

<div class="see-also">See also: <a href="#attempt">attempt</a>, <a href="#do">do</a>, <a href="#error?">error?</a></div>
</section>

<hr>
<section id="tuple?">
 <a name="tuple?"></a>
 <h2>TUPLE?<a class="headerlink" href="#tuple?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">tuple? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; tuple? 1.2.3.4
== #(true)

&gt;&gt; tuple? "1.2.3.4"
== #(false)</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="type?">
 <a name="type?"></a>
 <h2>TYPE?<a class="headerlink" href="#type?" title="Link to this heading">¶</a></h2>
<p>Returns the datatype of a value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">type? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
<span class="tit">REFINEMENTS:</span>
  /word       Returns the datatype as a word
</pre>

<h6>Description:</h6>
<p>
To check for a single datatype, use its datatype test
function (e.g. string?, time?) The /WORD refinement
returns the type as a word so you can use if for FIND,
SELECT, SWITCH, and other functions.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; type? 10
== #(integer!)

&gt;&gt; type? :type?
== #(native!)</code></pre></div><div class="example-code"><pre class="rebol-block"><code class="rebol">value: 10:30
print switch type?/word value [
    integer! [value + 10]
    decimal! [to-integer value]
    time!    [value/hour]
    date!    [first value/time]
]
10</code></pre></div>
<div class="see-also">See also: <a href="#block?">block?</a>, <a href="#date?">date?</a>, <a href="#decimal?">decimal?</a>, <a href="#email?">email?</a>, <a href="#file?">file?</a>, <a href="#function?">function?</a>, <a href="#integer?">integer?</a>, <a href="#issue?">issue?</a>, <a href="#logic?">logic?</a>, <a href="#make">make</a>, <a href="#money?">money?</a>, <a href="#native?">native?</a>, <a href="#none?">none?</a>, <a href="#object?">object?</a>, <a href="#paren?">paren?</a>, <a href="#path?">path?</a>, <a href="#port?">port?</a>, <a href="#string?">string?</a>, <a href="#time?">time?</a>, <a href="#tuple?">tuple?</a>, <a href="#url?">url?</a>, <a href="#word?">word?</a></div>
</section>

<hr>
<section id="types-of">
 <a name="types-of"></a>
 <h2>TYPES-OF<a class="headerlink" href="#types-of" title="Link to this heading">¶</a></h2>
<p>Returns a copy of the types of any function</p>

<h6>Usage:</h6>
<pre class="usage fs-6">types-of <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-function!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; spec-of :to-radians
== [
    "Converts degrees to radians"
    degrees [integer! decimal!] "Degrees to convert"
]

&gt;&gt; types-of :to-radians
== [make typeset! [integer! decimal!]]</code></pre></div>
<div class="see-also">See also: <a href="#body-of">body-of</a>, <a href="#reflect">reflect</a>, <a href="#spec-of">spec-of</a>, <a href="#title-of">title-of</a>, <a href="#values-of">values-of</a>, <a href="#words-of">words-of</a></div>
</section>

<hr>
<section id="typeset?">
 <a name="typeset?"></a>
 <h2>TYPESET?<a class="headerlink" href="#typeset?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">typeset? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; typeset? any-string!
== #(true)

&gt;&gt; typeset? string!
== #(false)</code></pre></div>
</section>

<hr>
<section id="unbind">
 <a name="unbind"></a>
 <h2>UNBIND<a class="headerlink" href="#unbind" title="Link to this heading">¶</a></h2>
<p>Unbinds words from context.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">unbind <span class="rebarg">word</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">block! any-word!</span>] A word or block (modified) (returned)
<span class="tit">REFINEMENTS:</span>
  /deep       Process nested blocks
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; a: 1 b: [a a]
== [a a] ;; words inside the block are bound

&gt;&gt; not none? context? first b
== #(true)

&gt;&gt; reduce b
== [1 1] ;; and so have the value

&gt;&gt; unbind b
== [a a]

&gt;&gt; context? first b
== #(none)

&gt;&gt; reduce b

** Script error: a word is not bound to a context</code></pre></div>
<div class="see-also">See also: <a href="#bind">bind</a>, <a href="#context?">context?</a></div>
</section>

<hr>
<section id="undirize">
 <a name="undirize"></a>
 <h2>UNDIRIZE<a class="headerlink" href="#undirize" title="Link to this heading">¶</a></h2>
<p>Returns a copy of the path with any trailing "/" removed.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">undirize <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file! string! url!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; undirize %some/path/
== %some/path</code></pre></div>
<div class="see-also">See also: <a href="#dirize">dirize</a></div>
</section>

<hr>
<section id="unfilter">
 <a name="unfilter"></a>
 <h2>UNFILTER<a class="headerlink" href="#unfilter" title="Link to this heading">¶</a></h2>
<p>Reversed PNG delta filter</p>

<h6>Usage:</h6>
<pre class="usage fs-6">unfilter <span class="rebarg">data</span> <span class="rebarg">width</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">binary!</span>] Input
  width       [<span class="types">number!</span>] Scanline width (not counting the type byte)
<span class="tit">REFINEMENTS:</span>
  /as         Filter type. If not used, type is decoded from first byte on each line.
   type       [<span class="types">integer! word!</span>] 1..4 or one of: [sub up average paeth]
  /skip       
   bpp        [<span class="types">integer!</span>] Bytes per pixel
</pre>

<h6>Description:</h6>
<p>
Compression preprocessing, as used in PNG images.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; bin: #{01020304050102030405} ;; original data
== #{01020304050102030405}

&gt;&gt; filter bin 5 'sub
== #{01010101010101010101} ;; data filtered for good compression

&gt;&gt; unfilter/as #{01010101010101010101} 5 'sub
== #{01020304050102030405} ;; original data again</code></pre></div>
<div class="see-also">See also: <a href="#filter">filter</a></div>
</section>

<hr>
<section id="unhandle-events">
 <a name="unhandle-events"></a>
 <h2>UNHANDLE-EVENTS<a class="headerlink" href="#unhandle-events" title="Link to this heading">¶</a></h2>
<p>Removes a handler from the view event system.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">unhandle-events <span class="rebarg">handler</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  handler     [<span class="types">object!</span>] 
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="union">
 <a name="union"></a>
 <h2>UNION<a class="headerlink" href="#union" title="Link to this heading">¶</a></h2>
<p>Returns the union of two data sets.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">union <span class="rebarg">set1</span> <span class="rebarg">set2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  set1        [<span class="types">block! string! bitset! typeset! map!</span>] first set
  set2        [<span class="types">block! string! bitset! typeset! map!</span>] second set
<span class="tit">REFINEMENTS:</span>
  /case       Use case-sensitive comparison
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns all elements present within two blocks or strings 
ignoring the duplicates.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">lunch: [ham cheese bread carrot]
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
"abc"</code></pre></div><p>
To obtain a unique set (to remove duplicate values)
you can use UNIQUE.
</p>
<p>
Note that performing this function over very large
data sets can be CPU intensive.
</p>

<div class="see-also">See also: <a href="#difference">difference</a>, <a href="#exclude">exclude</a>, <a href="#intersect">intersect</a>, <a href="#unique">unique</a></div>
</section>

<hr>
<section id="unique">
 <a name="unique"></a>
 <h2>UNIQUE<a class="headerlink" href="#unique" title="Link to this heading">¶</a></h2>
<p>Returns the data set with duplicates removed.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">unique <span class="rebarg">set1</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  set1        [<span class="types">block! string! bitset! typeset! map!</span>] 
<span class="tit">REFINEMENTS:</span>
  /case       Use case-sensitive comparison (except bitsets)
  /skip       Treat the series as records of fixed size
   size       [<span class="types">integer!</span>] 
</pre>

<h6>Description:</h6>
<p>
Removes all duplicate values from a set or series:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">lunch: [ham cheese bread carrot ham ham carrot]
probe unique lunch
[ham cheese bread carrot]

probe unique [1 3 2 4 3 5 4 6]
[1 3 2 4 5 6]

string: "CBADEDCF"
probe unique string
"CBADEF"</code></pre></div><p>
Note that performing this function over very large
data sets can be CPU intensive.
</p>

<div class="see-also">See also: <a href="#difference">difference</a>, <a href="#exclude">exclude</a>, <a href="#intersect">intersect</a>, <a href="#union">union</a></div>
</section>

<hr>
<section id="unless">
 <a name="unless"></a>
 <h2>UNLESS<a class="headerlink" href="#unless" title="Link to this heading">¶</a></h2>
<p>If FALSE condition, return arg; evaluate blocks by default.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">unless <span class="rebarg">condition</span> <span class="rebarg">false-branch</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  condition   [<span class="types">any-type!</span>] 
  false-branch  
<span class="tit">REFINEMENTS:</span>
  /only       Return block arg instead of evaluating it.
</pre>

<h6>Description:</h6>
<p>
The <a href="#unless">unless</a> function is the equivalent of writing <a href="#if">if</a> <a href="#not">not</a> of a condition.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">unless now/time &gt; 12:00 [print "It's still morning"]</code></pre></div><p>
See the <a href="#if">if</a> function for a lot more information.
</p>

<h6>Why?</h6><p>
This function can take some getting used to. It has been provided to make PERL programmers happier, and it's marginally simpler and faster than writing an <a href="#if">if</a> <a href="#not">not</a> expression.
</p>

<div class="see-also">See also: <a href="#either">either</a>, <a href="#if">if</a>, <a href="#not">not</a></div>
</section>

<hr>
<section id="unprotect">
 <a name="unprotect"></a>
 <h2>UNPROTECT<a class="headerlink" href="#unprotect" title="Link to this heading">¶</a></h2>
<p>Unprotect a series or a variable (it can again be modified).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">unprotect <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">word! series! bitset! map! object! module!</span>] 
<span class="tit">REFINEMENTS:</span>
  /deep       Protect all sub-series as well
  /words      Block is a list of words
  /values     Process list of values (implied GET)
</pre>

<h6>Description:</h6>
<p>
Unprotects a series, variable, or object that was protected earlier with <a href="#protect">protect</a>.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">test: "text"
protect test
append test "a"
** Script error: protected value or series - cannot modify

unprotect test
append test "a"
probe texta
"texta"</code></pre></div><p>
To <a href="#unprotect">unprotect</a> all series found within a block, use the /deep refinement:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">test: [100 "example" 10:20]
protect/deep test
print append "example" "x"
** Script error: protected value or series - cannot modify

unprotect/deep test
print append "example" "x"
examplex</code></pre></div><p>
See <a href="#protect">protect</a> for other usage and information.
</p>

<div class="see-also">See also: <a href="#protect">protect</a></div>
</section>

<hr>
<section id="unset">
 <a name="unset"></a>
 <h2>UNSET<a class="headerlink" href="#unset" title="Link to this heading">¶</a></h2>
<p>Unsets the value of a word (in its current context.)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">unset <span class="rebarg">word</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word! block! none!</span>] Word or block of words
</pre>

<h6>Description:</h6>
<p>
Using UNSET, the word's current value will be lost. If
a block is specified, all the words within the block
will be unset.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">test: "a value"
unset 'test
print value? 'test
false</code></pre></div>
<div class="see-also">See also: <a href="#set">set</a></div>
</section>

<hr>
<section id="unset?">
 <a name="unset?"></a>
 <h2>UNSET?<a class="headerlink" href="#unset?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">unset? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns TRUE if a value is UNSET. Normally you should
use VALUE? to test if a word has a value.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">if unset? do [print "test"] [print "Nothing was returned"]
test</code></pre></div>
<div class="see-also">See also: <a href="#value?">value?</a></div>
</section>

<hr>
<section id="until">
 <a name="until"></a>
 <h2>UNTIL<a class="headerlink" href="#until" title="Link to this heading">¶</a></h2>
<p>Evaluates a block until it is TRUE. </p>

<h6>Usage:</h6>
<pre class="usage fs-6">until <span class="rebarg">block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  block       [<span class="types">block!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#until">until</a> function evaluates a block until the block returns true. It is different from <a href="#while">while</a> because it only requires a single block, which also serves as the condition. However, the block is always evaluated at least once.
</p>
<p>
The general form is:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">while [cond] [body]</code></pre></div><p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">num: 0
until[
    print num
    num: num + 1
    num &gt;= 2
]
0
1
2</code></pre></div><p>
Another example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "test"
until [
    print str
    tail? str: next str
]
test
est
st
t</code></pre></div>
<h6>Return Value</h6><p>
The last value of the block is returned from the <a href="#until">until</a> function. Because this is also the termination condition, it will always be non-none non-false, but that can be useful at times.
</p>

<h6>Other Notes</h6><ul>
<li>A <a href="#break">break</a> can be used to escape from the loop at any time.</li>
<li>A common mistake is to forget that block must return the test condition for the loop, which could result in an infinite loop.</li>
</ul>
<div class="see-also">See also: <a href="#for">for</a>, <a href="#foreach">foreach</a>, <a href="#loop">loop</a>, <a href="#repeat">repeat</a>, <a href="#while">while</a></div>
</section>

<hr>
<section id="unview">
 <a name="unview"></a>
 <h2>UNVIEW<a class="headerlink" href="#unview" title="Link to this heading">¶</a></h2>
<p>Closes a window view.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">unview <span class="rebarg">window</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  window      [<span class="types">object! gob! word! none!</span>] Window face or GOB. 'all for all. none for last
</pre>

<h6>Description:</h6>
<p>
The UNVIEW function is used to close a window previously opened
with the VIEW function. By default, the last window that has
been opened will be closed.  To close a specific window, use the
/only refinement and specify the window's face (that which was
returned from a layout, for example).  All windows can be closed
with the /all refinement.
</p>
<p>
The example below opens a window that displays a Close button.
Clicking on the button will evaluate the UNVIEW function and the
window will be closed.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">view layout [button "Close" [unview]]</code></pre></div><p>
Note that the VIEW function will not return until all windows
have been closed. (Use VIEW/new to return immediately after
the window is opened.)
</p>
<p>
The next example will open two windows, then use UNVIEW/only
to close each one separately.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">out1: layout [button "Close 2" [unview out2]]
out2: layout [button "Close 1" [unview out1]]
view/new out1
view/new out2
do-events</code></pre></div><p>
You could have closed both windows with the line:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">unview/all</code></pre></div>
</section>

<hr>
<section id="update">
 <a name="update"></a>
 <h2>UPDATE<a class="headerlink" href="#update" title="Link to this heading">¶</a></h2>
<p>Updates external and internal states (normally after read/write).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">update <span class="rebarg">port</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  port        [<span class="types">port!</span>] 
</pre>

<h6>Description:</h6>
<p>
Updates the input or output of a port. If input is
expected, the port is checked for more input. If output
is pending then that output is written.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">out: open/new %trash.me
insert out "this is a test"
update out
insert out "this is just a test"
close out</code></pre></div>
<div class="see-also">See also: <a href="#insert">insert</a>, <a href="#query">query</a>, <a href="#read">read</a>, <a href="#remove">remove</a>, <a href="#write">write</a></div>
</section>

<hr>
<section id="uppercase">
 <a name="uppercase"></a>
 <h2>UPPERCASE<a class="headerlink" href="#uppercase" title="Link to this heading">¶</a></h2>
<p>Converts string of characters to uppercase.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">uppercase <span class="rebarg">string</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  string      [<span class="types">any-string! char!</span>] (modified if series)
<span class="tit">REFINEMENTS:</span>
  /part       Limits to a given length or position
   length     [<span class="types">number! any-string!</span>] 
</pre>

<h6>Description:</h6>
<p>
The series passed to this function is modified as a
result.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print uppercase "abcdef"
ABCDEF

print uppercase/part "abcdef" 1
Abcdef</code></pre></div>
<div class="see-also">See also: <a href="#lowercase">lowercase</a>, <a href="#trim">trim</a></div>
</section>

<hr>
<section id="url?">
 <a name="url?"></a>
 <h2>URL?<a class="headerlink" href="#url?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">url? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print url? http://www.REBOL.com
true

print url? "test"
false</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="usage">
 <a name="usage"></a>
 <h2>USAGE<a class="headerlink" href="#usage" title="Link to this heading">¶</a></h2>
<p>Prints command-line arguments</p>

<h6>Usage:</h6>
<pre class="usage fs-6">usage</span></pre>

<h6>Description:</h6>
<p>
Displays REBOL command line arguments, including
options and examples.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">>> usage</code></pre></div>
<div class="example-code"><pre class="text-block"><code>
  <span class="ansi4 ansi1 ansi36">Command line usage</span>:
  
      <span class="ansi1 ansi32">REBOL |options| |script| |arguments|</span>
  
  <span class="ansi4 ansi1 ansi36">Standard options</span>:
  
      <span class="ansi1 ansi32">--args data</span>      Explicit arguments to script (quoted)
      <span class="ansi1 ansi32">--do expr</span>        Evaluate expression (quoted)
      <span class="ansi1 ansi32">--help (-?)</span>      Display this usage information (then quit)
      <span class="ansi1 ansi32">--script file</span>    Explicit script filename
      <span class="ansi1 ansi32">--version tuple</span>  Script must be this version or greater
  
  <span class="ansi4 ansi1 ansi36">Special options</span>:
  
      <span class="ansi1 ansi32">--boot level</span>     Valid levels: base sys mods
      <span class="ansi1 ansi32">--debug flags</span>    For user scripts (system/options/debug)
      <span class="ansi1 ansi32">--halt (-h)</span>      Leave console open when script is done
      <span class="ansi1 ansi32">--import file</span>    Import a module prior to script
      <span class="ansi1 ansi32">--quiet (-q)</span>     No startup banners or information
      <span class="ansi1 ansi32">--secure policy</span>  Can be: none allow ask throw quit
      <span class="ansi1 ansi32">--trace (-t)</span>     Enable trace mode during boot
      <span class="ansi1 ansi32">--verbose</span>        Show detailed startup information
      <span class="ansi1 ansi32">--cgi (-c)</span>       Starts in a CGI mode
      <span class="ansi1 ansi32">--no-color</span>       Reduce the use of ANSI color escape sequences

  <span class="ansi4 ansi1 ansi36">Other quick options</span>:
  
      <span class="ansi1 ansi32">-s</span>               No security
      <span class="ansi1 ansi32">+s</span>               Full security
      <span class="ansi1 ansi32">-v</span>               Display version only (then quit)
  
  <span class="ansi4 ansi1 ansi36">Examples</span>:
  
      REBOL script.r
      REBOL -s script.r
      REBOL script.r 10:30 test@example.com
      REBOL --do "watch: on" script.r
</code></pre></div><p>
SDK and special versions of REBOL may not include usage
information.
</p>

<div class="see-also">See also: <a href="#?">?</a>, <a href="#help">help</a></div>
</section>

<hr>
<section id="use">
 <a name="use"></a>
 <h2>USE<a class="headerlink" href="#use" title="Link to this heading">¶</a></h2>
<p>Defines words local to a block.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">use <span class="rebarg">vars</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  vars        [<span class="types">block! word!</span>] Local word(s) to the block
  body        [<span class="types">block!</span>] Block to evaluate
</pre>

<h6>Description:</h6>
<p>
The first block contains a list of words which will be
local to the second block. The second block will be
evaluated and its results returned from the USE.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">total: 1234
nums: [123 321 456]
use [total] [
    total: 0
    foreach n nums [total: total + n]
    print total
]
900

print total
1234</code></pre></div><p>
Note: The USE function modifies the context (bindings) of the code
block (as if BIND was used on it). This can lead to problems for
recursive functions. To use the USE function recusively, you will
need to COPY/deep the code block first:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">words: [a]
body: [print a * b]
use words copy/deep body</code></pre></div>
</section>

<hr>
<section id="user's">
 <a name="user's"></a>
 <h2>USER'S<a class="headerlink" href="#user's" title="Link to this heading">¶</a></h2>
<p>Resolves user's data value</p>

<h6>Usage:</h6>
<pre class="usage fs-6">user's <span class="rebarg">key</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  key          
</pre>

<h6>Description:</h6>
<p>
It can be used in the following scenario:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; set-user/n Test
 [REBOL] Initialize user: Test
 [REBOL] Creating a new persistent storage file: /C/Users/oldes/Rebol/.Test.safe
Enter password:

&gt;&gt; user's key
== #(none) ;; Because the key has not been stored yet.

&gt;&gt; put system/user/data 'key "secret"
== "secret"

&gt;&gt; user's key
== "secret"

&gt;&gt; set-user ;; Removes current user
&gt;&gt; user's key
== #(none) ;; Because there is no user now

&gt;&gt; set-user Test
 [REBOL] Initialize user: Test
Enter password:

&gt;&gt; user's key
== "secret"</code></pre></div>
<div class="see-also">See also: <a href="#set-user">set-user</a></div>
</section>

<hr>
<section id="utf?">
 <a name="utf?"></a>
 <h2>UTF?<a class="headerlink" href="#utf?" title="Link to this heading">¶</a></h2>
<p>Returns UTF BOM (byte order marker) encoding; + for BE, - for LE.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">utf? <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">binary!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; utf? #{FEFF005700720069007400650072}
== 16

&gt;&gt; utf? #{FFFE570072006900740065007200}
== -16

&gt;&gt; utf? #{fffe0000650000007300000063000000}
== -32

&gt;&gt; utf? #{EFBBBFC3A4C3B6C3BC}
== 8</code></pre></div>
<div class="see-also">See also: <a href="#invalid-utf?">invalid-utf?</a></div>
</section>

<hr>
<section id="utype?">
 <a name="utype?"></a>
 <h2>UTYPE?<a class="headerlink" href="#utype?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">utype? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="value?">
 <a name="value?"></a>
 <h2>VALUE?<a class="headerlink" href="#value?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the word has a value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">value? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">word!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#value?">value?</a> function returns true if the specified <span class="datatype">word!</span> has a value. It returns false if not.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; value? 'system
== #(true)

&gt;&gt; value? 'not-defined
== #(false)</code></pre></div><p>
The word can be passed as a literal or as the result of other operations.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; value? first [system not-defined]
== #(true)

&gt;&gt; value? second [system not-defined]
== #(false)</code></pre></div>
<div class="see-also">See also: <a href="#default">default</a>, <a href="#equal?">equal?</a>, <a href="#same?">same?</a>, <a href="#strict-equal?">strict-equal?</a>, <a href="#unset?">unset?</a></div>
</section>

<hr>
<section id="values-of">
 <a name="values-of"></a>
 <h2>VALUES-OF<a class="headerlink" href="#values-of" title="Link to this heading">¶</a></h2>
<p>Returns a copy of the values of any object, map or struct</p>

<h6>Usage:</h6>
<pre class="usage fs-6">values-of <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-object! map! struct!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; values-of #[a: 1 b: 2]
== [1 2]

&gt;&gt; values-of object [a: 1 b: 2]
== [1 2]</code></pre></div>
<div class="see-also">See also: <a href="#body-of">body-of</a>, <a href="#reflect">reflect</a>, <a href="#spec-of">spec-of</a>, <a href="#title-of">title-of</a>, <a href="#types-of">types-of</a>, <a href="#words-of">words-of</a></div>
</section>

<hr>
<section id="vector?">
 <a name="vector?"></a>
 <h2>VECTOR?<a class="headerlink" href="#vector?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">vector? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; vector? #(uint8! 3)
== #(true)

&gt;&gt; vector? [1 2 3]
== #(false)</code></pre></div>
</section>

<hr>
<section id="version">
 <a name="version"></a>
 <h2>VERSION<a class="headerlink" href="#version" title="Link to this heading">¶</a></h2>
<p>Return Rebol version string</p>

<h6>Usage:</h6>
<pre class="usage fs-6">version</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /data       loadable version
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; version
== {Rebol/Bulk 3.18.3 (9-Mar-2025/22:36 UTC)
Copyright (c) 2012 REBOL Technologies
Copyright (c) 2012-2025 Rebol Open Source Contributors
Source:       https://github.com/Oldes/Rebol3
}</code></pre></div>
<div class="see-also">See also: <a href="#about">about</a>, <a href="#license">license</a></div>
</section>

<hr>
<section id="view">
 <a name="view"></a>
 <h2>VIEW<a class="headerlink" href="#view" title="Link to this heading">¶</a></h2>
<p>Displays a window view.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">view <span class="rebarg">window</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  window      [<span class="types">gob! block! object! image!</span>] Window gob, VID face, or VID layout block
<span class="tit">REFINEMENTS:</span>
  /options    
   opts       [<span class="types">block!</span>] Window options spec block
  /no-wait    Return immediately. Do not wait and process events.
  /as-is      Leave window as is. Do not add a parent gob.
</pre>

<h6>Description:</h6>
<p>
NOTE: GUI system is only partially supported in this Rebol version!
</p>

</section>

<hr>
<section id="wait">
 <a name="wait"></a>
 <h2>WAIT<a class="headerlink" href="#wait" title="Link to this heading">¶</a></h2>
<p>Waits for a duration, port, or both.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">wait <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">number! time! port! block! none!</span>] 
<span class="tit">REFINEMENTS:</span>
  /all        Returns all in a block
  /only       only check for ports given in the block to this function
</pre>

<h6>Description:</h6>
<p>
If the value is a <span class="datatype">time!</span>, delay for that period. If the
value is an <span class="datatype">integer!</span> or <span class="datatype">decimal!</span>, wait that number of
seconds. If the value is a <span class="datatype">port!</span>, wait for an event from
that port. If a <span class="datatype">block!</span> is specified, wait for any of the
times or ports to occur. Return the port that caused
the wait to complete or return none if the timeout
occurred.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print now/time
17:48:19

wait 1
print now/time
17:48:22

wait 0:00:01
print now/time
17:48:23</code></pre></div>
</section>

<hr>
<section id="wait-for-key">
 <a name="wait-for-key"></a>
 <h2>WAIT-FOR-KEY<a class="headerlink" href="#wait-for-key" title="Link to this heading">¶</a></h2>
<p>Wait for single key press and return char (or word for control keys) as a result</p>

<h6>Usage:</h6>
<pre class="usage fs-6">wait-for-key</span></pre>

<pre class="help">
<span class="tit">REFINEMENTS:</span>
  /only       
   limit      [<span class="types">bitset! string! block! none! char!</span>] Limit input to specified chars or control words
</pre>
</section>

<hr>
<section id="wake-up">
 <a name="wake-up"></a>
 <h2>WAKE-UP<a class="headerlink" href="#wake-up" title="Link to this heading">¶</a></h2>
<p>Awake and update a port with event.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">wake-up <span class="rebarg">port</span> <span class="rebarg">event</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  port        [<span class="types">port!</span>] 
  event       [<span class="types">event!</span>] 
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

</section>

<hr>
<section id="what">
 <a name="what"></a>
 <h2>WHAT<a class="headerlink" href="#what" title="Link to this heading">¶</a></h2>
<p>Prints a list of known functions</p>

<h6>Usage:</h6>
<pre class="usage fs-6">what <span class="rebarg">name</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  name        [<span class="types">word! lit-word! unset!</span>] Optional module name
<span class="tit">REFINEMENTS:</span>
  /args       Show arguments not titles
</pre>

<h6>Description:</h6>
<p>
The <a href="#what">what</a> function lists globally exported functions and their titles or arguments.
</p>
<p>
For example:
</p>
<div class="example-code"><pre class="text-block"><code class="text">&gt;&gt; what
...
about               Information about REBOL
abs                 Returns the absolute value.
absolute            Returns the absolute value.
action              Creates datatype action (for internal usage only).
action?             Returns TRUE if it is this type.
add                 Returns the result of adding two values.
ajoin               Reduces and joins a block of values into a new string.
alias               Creates an alternate spelling for a word.
...</code></pre></div><p>
To see function arguments use:
</p>
<div class="example-code"><pre class="text-block"><code class="text">&gt;&gt; what/args
...
about                 []
abs                   [value]
absolute              [value]
action?               [value]
add                   [value1 value2]
ajoin                 [block]
...</code></pre></div><p>
Also see the <a href="#help">help</a> function which allows searching for functions.
</p>

<h6>Module Export Lists</h6><p>
To see a list of functions for a specific module, provide the module name:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">>> what/args help</code></pre></div>
<div class="example-code"><pre class="text-block"><code><span class="ansi1 ansi32">?              </span> ['word /doc /into string]
<span class="ansi1 ansi32">a-an           </span> [s]
<span class="ansi1 ansi32">about          </span> []
<span class="ansi1 ansi32">browse         </span> [url]
<span class="ansi1 ansi32">bugs           </span> []
<span class="ansi1 ansi32">changes        </span> []
<span class="ansi1 ansi32">dot            </span> [value]
<span class="ansi1 ansi32">dump-obj       </span> [obj /weak /match pattern /not-none]
<span class="ansi1 ansi32">form-pad       </span> [val size]
<span class="ansi1 ansi32">form-type      </span> [value]
<span class="ansi1 ansi32">form-val       </span> [val]
<span class="ansi1 ansi32">help           </span> ['word /doc /into string]
<span class="ansi1 ansi32">license        </span> []
<span class="ansi1 ansi32">list-codecs    </span> []
<span class="ansi1 ansi32">out-description</span> [des]
<span class="ansi1 ansi32">output         </span> [value]
<span class="ansi1 ansi32">pad            </span> [val size]
<span class="ansi1 ansi32">source         </span> ['word]
<span class="ansi1 ansi32">usage          </span> []
<span class="ansi1 ansi32">what           </span> ['name /args]
</code></pre></div>
<div class="see-also">See also: <a href="#?">?</a>, <a href="#help">help</a></div>
</section>

<hr>
<section id="what-dir">
 <a name="what-dir"></a>
 <h2>WHAT-DIR<a class="headerlink" href="#what-dir" title="Link to this heading">¶</a></h2>
<p>Returns the current directory path.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">what-dir</span></pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; what-dir
== %/C/Users/oldes/Rebol/</code></pre></div>
<div class="see-also">See also: <a href="#change-dir">change-dir</a>, <a href="#list-dir">list-dir</a>, <a href="#make-dir">make-dir</a></div>
</section>

<hr>
<section id="while">
 <a name="while"></a>
 <h2>WHILE<a class="headerlink" href="#while" title="Link to this heading">¶</a></h2>
<p>While a condition block is TRUE, evaluates another block.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">while <span class="rebarg">cond-block</span> <span class="rebarg">body-block</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  cond-block  [<span class="types">block!</span>] 
  body-block  [<span class="types">block!</span>] 
</pre>

<h6>Description:</h6>
<p>
The <a href="#while">while</a> function repeats the evaluation of its two block arguments while the first block returns true. The first block is the condition block, the second block is the evaluation block. When the condition block returns false or <span class="datatype">none!</span>, the expression block will no longer be evaluated and the loop terminates.
</p>
<p>
The general form is:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">while [cond] [body]</code></pre></div><p>
For example:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">num: 0
while [num &lt; 3] [
    print num
    num: num + 1
]
0
1
2</code></pre></div><p>
Another example, using <a href="#while">while</a> to traverse a series (like <a href="#foreach">foreach</a> ):
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">color: [red green blue]
while [not tail? color] [
    print first color
    color: next color
]
red
green
blue</code></pre></div><p>
Here is an example using a string series:
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">str: "abc"
while [not tail? str: next str] [
    print ["length of" str "is" length? str]
]
length of abc is 3
length of bc is 2
length of c is 1</code></pre></div>
<h6>Condition Block</h6><p>
The condition block can contain any number of expressions, so long as the last expression returns the condition. To illustrate this, the next example adds a print to the condition block. This will print the index value of the color. It will then check for the tail of the color block, which is the condition used for the loop.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">color: [red green blue]
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
<h6>Return Value</h6><p>
The last value of the block is returned from the <a href="#while">while</a> function.
</p>

<h6>Other Notes</h6><ul>
<li>A <a href="#break">break</a> can be used to escape from the loop at any time.</li>
<li>The most common mistake is to forget to provide a block for the
first argument (the condition).</li>
</ul>
<div class="see-also">See also: <a href="#for">for</a>, <a href="#loop">loop</a>, <a href="#repeat">repeat</a>, <a href="#until">until</a></div>
</section>

<hr>
<section id="wildcard">
 <a name="wildcard"></a>
 <h2>WILDCARD<a class="headerlink" href="#wildcard" title="Link to this heading">¶</a></h2>
<p>Return block of absolute path files filtered using wildcards.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">wildcard <span class="rebarg">path</span> <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file!</span>] Source directory
  value       [<span class="types">any-string!</span>] Search value with possible * and ? wildcards
</pre>
</section>

<hr>
<section id="wildcard?">
 <a name="wildcard?"></a>
 <h2>WILDCARD?<a class="headerlink" href="#wildcard?" title="Link to this heading">¶</a></h2>
<p>Return true if file contains wildcard chars (* or ?)</p>

<h6>Usage:</h6>
<pre class="usage fs-6">wildcard? <span class="rebarg">path</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  path        [<span class="types">file!</span>] 
</pre>
</section>

<hr>
<section id="with">
 <a name="with"></a>
 <h2>WITH<a class="headerlink" href="#with" title="Link to this heading">¶</a></h2>
<p>Evaluates a block binded to the specified context</p>

<h6>Usage:</h6>
<pre class="usage fs-6">with <span class="rebarg">context</span> <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  context     [<span class="types">object! module! port!</span>] A reference to the target context
  body        [<span class="types">block!</span>] A code to be evaluated
</pre>
</section>

<hr>
<section id="word?">
 <a name="word?"></a>
 <h2>WORD?<a class="headerlink" href="#word?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if it is this type.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">word? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] 
</pre>

<h6>Description:</h6>
<p>
Returns FALSE for all other values. To test for "word:",
":word", or "'word", use the SET?, GET?, and LITERAL?
functions.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print word? second [1 two "3"]
true</code></pre></div>
<div class="see-also">See also: <a href="#type?">type?</a></div>
</section>

<hr>
<section id="words-of">
 <a name="words-of"></a>
 <h2>WORDS-OF<a class="headerlink" href="#words-of" title="Link to this heading">¶</a></h2>
<p>Returns a copy of the words of any function, any object, map, date, handle or struct</p>

<h6>Usage:</h6>
<pre class="usage fs-6">words-of <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-function! any-object! map! date! handle! struct!</span>] 
</pre>

<h6>Description:</h6>
<p>
No description provided.
</p>

<div class="see-also">See also: <a href="#body-of">body-of</a>, <a href="#reflect">reflect</a>, <a href="#spec-of">spec-of</a>, <a href="#title-of">title-of</a>, <a href="#types-of">types-of</a>, <a href="#values-of">values-of</a></div>
</section>

<hr>
<section id="wrap">
 <a name="wrap"></a>
 <h2>WRAP<a class="headerlink" href="#wrap" title="Link to this heading">¶</a></h2>
<p>Evaluates a block, wrapping all set-words as locals.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">wrap <span class="rebarg">body</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  body        [<span class="types">block!</span>] Block to evaluate
</pre>

<h6>Description:</h6>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; a: 1 ;; Having some value....
== 1

&gt;&gt; wrap load "a: 2" ;; Evaluate some code which is
                    ;; using the same value name
== 2

&gt;&gt; a
== 1 ;; Original value was not changed</code></pre></div>
</section>

<hr>
<section id="write">
 <a name="write"></a>
 <h2>WRITE<a class="headerlink" href="#write" title="Link to this heading">¶</a></h2>
<p>Writes to a file, URL, or port - auto-converts text strings.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">write <span class="rebarg">destination</span> <span class="rebarg">data</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  destination [<span class="types">port! file! url! block! word!</span>] 
  data         Data to write (non-binary converts to UTF-8)
<span class="tit">REFINEMENTS:</span>
  /part       Partial write a given number of units
   length     [<span class="types">number!</span>] 
  /seek       Write at a specific position
   index      [<span class="types">number!</span>] 
  /append     Write data at end of file
  /allow      Specifies protection attributes
   access     [<span class="types">block!</span>] 
  /lines      Write each value in a block as a separate line
  /binary     Preserves contents exactly
  /all        Response may include additional information (source relative)
</pre>

<h6>Description:</h6>
<p>
WRITE is typically used to write a file to disk, but
many other operations, such as writing data to URLs and
ports, are possible.
</p>
<p>
Normally a string or binary value is provided to this
function, but other types of data such as a number or a
time can be written. They will be converted to text.
</p>
<p>
The /BINARY refinement will write out data as its exact
representation. This is good for writing image, sound
and other binary data.
</p>
<p>
The /STRING refinement translates line terminators to
the operating system's line terminator. This behavior
is default.
</p>
<p>
The /APPEND refinement is useful logging purposes, as
it won't overwrite existing data.
</p>
<p>
The /LINES refinement can take a block of values and 
will write each value to a line. By default, WRITE will
write the block of values as a concatonated string of
formed values.
</p>
<p>
The /PART refinement will read the specified number of
elements from the data being written.
The /WITH refinement converts characters, or strings,
specified into line terminators.
</p>
<p>
See the User's Guide for more detailed explanation of
using READ and its refinements.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">write %junkme.txt "This is a junk file."
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
print read %rebol-test-file.r</code></pre></div>
<div class="see-also">See also: <a href="#close">close</a>, <a href="#form">form</a>, <a href="#load">load</a>, <a href="#open">open</a>, <a href="#read">read</a>, <a href="#save">save</a></div>
</section>

<hr>
<section id="xor">
 <a name="xor"></a>
 <h2>XOR<a class="headerlink" href="#xor" title="Link to this heading">¶</a></h2>
<p>Returns the first value exclusive ORed with the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> xor <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
  value2      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
For integers, each bit
is exclusively-or'd. For logic values, this is the
same as the not-equal function.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">print 122 xor 1
123

print true xor false
true

print false xor false
false

print 1.2.3.4 xor 1.0.0.0
0.2.3.4</code></pre></div>
<div class="see-also">See also: <a href="#and">and</a>, <a href="#not">not</a>, <a href="#or">or</a></div>
</section>

<hr>
<section id="xor~">
 <a name="xor~"></a>
 <h2>XOR~<a class="headerlink" href="#xor~" title="Link to this heading">¶</a></h2>
<p>Returns the first value exclusive ORed with the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">xor~ <span class="rebarg">value1</span> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
  value2      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
</pre>

<h6>Description:</h6>
<p>
The trampoline action function for XOR operator.
</p>

<div class="see-also">See also: <a href="#and~">and~</a>, <a href="#or~">or~</a></div>
</section>

<hr>
<section id="xtest">
 <a name="xtest"></a>
 <h2>XTEST<a class="headerlink" href="#xtest" title="Link to this heading">¶</a></h2>
<p></p>

<h6>Usage:</h6>
<pre class="usage fs-6">xtest</span></pre>
</section>

<hr>
<section id="zero?">
 <a name="zero?"></a>
 <h2>ZERO?<a class="headerlink" href="#zero?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the value is zero (for its datatype).</p>

<h6>Usage:</h6>
<pre class="usage fs-6">zero? <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        
</pre>

<h6>Description:</h6>
<p>
Check the value of a word is zero.
</p>
<div class="example-code"><pre class="rebol-block"><code class="rebol">&gt;&gt; zero? 50
== #(false)

&gt;&gt; zero? 0
== #(true)</code></pre></div>
<div class="see-also">See also: <a href="#negative?">negative?</a>, <a href="#positive?">positive?</a></div>
</section>

<hr>
<section id="-">
 <a name="-"></a>
 <h2>-<a class="headerlink" href="#-" title="Link to this heading">¶</a></h2>
<p>Returns the second value subtracted from the first.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> - <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! date! vector!</span>] 
  value2      [<span class="types">scalar! date! vector!</span>] 
</pre>
</section>

<hr>
<section id="--">
 <a name="--"></a>
 <h2>--<a class="headerlink" href="#--" title="Link to this heading">¶</a></h2>
<p>Decrement an integer or series index. Return its prior value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">-- <span class="rebarg">word</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word!</span>] Integer or series variable
</pre>
</section>

<hr>
<section id="---">
 <a name="---"></a>
 <h2>---<a class="headerlink" href="#---" title="Link to this heading">¶</a></h2>
<p>Ignores the argument value and returns nothing.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">--- <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value        A string, block, file, etc.
</pre>
</section>

<hr>
<section id="&">
 <a name="&"></a>
 <h2>&<a class="headerlink" href="#&" title="Link to this heading">¶</a></h2>
<p>Returns the first value ANDed with the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> & <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
  value2      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
</pre>
</section>

<hr>
<section id="/">
 <a name="/"></a>
 <h2>/<a class="headerlink" href="#/" title="Link to this heading">¶</a></h2>
<p>Returns the first value divided by the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> / <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! vector!</span>] 
  value2      [<span class="types">scalar! vector!</span>] 
</pre>
</section>

<hr>
<section id="//">
 <a name="//"></a>
 <h2>//<a class="headerlink" href="#//" title="Link to this heading">¶</a></h2>
<p>Wrapper for MOD that handles errors like REMAINDER. Negligible values (compared to A and B) are rounded to zero.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">a</span> // <span class="rebarg">b</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  a           [<span class="types">number! money! char! time!</span>] 
  b           [<span class="types">number! money! char! time!</span>] Absolute value will be used.
</pre>
</section>

<hr>
<section id="=">
 <a name="="></a>
 <h2>=<a class="headerlink" href="#=" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are equal.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> = <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id="==">
 <a name="=="></a>
 <h2>==<a class="headerlink" href="#==" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are strictly equal.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> == <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id="=?">
 <a name="=?"></a>
 <h2>=?<a class="headerlink" href="#=?" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are identical.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> =? <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id=">">
 <a name=">"></a>
 <h2>><a class="headerlink" href="#>" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the first value is greater than the second value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> > <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1       
  value2       
</pre>
</section>

<hr>
<section id=">=">
 <a name=">="></a>
 <h2>>=<a class="headerlink" href="#>=" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the first value is greater than or equal to the second value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> >= <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1       
  value2       
</pre>
</section>

<hr>
<section id=">>">
 <a name=">>"></a>
 <h2>>><a class="headerlink" href="#>>" title="Link to this heading">¶</a></h2>
<p>Shift bits to the right (unsigned).</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">data</span> >> <span class="rebarg">bits</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">integer!</span>] 
  bits        [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="*">
 <a name="*"></a>
 <h2>*<a class="headerlink" href="#*" title="Link to this heading">¶</a></h2>
<p>Returns the first value multiplied by the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> * <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! vector!</span>] 
  value2      [<span class="types">scalar! vector!</span>] 
</pre>
</section>

<hr>
<section id="**">
 <a name="**"></a>
 <h2>**<a class="headerlink" href="#**" title="Link to this heading">¶</a></h2>
<p>Returns the first number raised to the second number.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">number</span> ** <span class="rebarg">exponent</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  number      [<span class="types">number!</span>] 
  exponent    [<span class="types">number!</span>] 
</pre>
</section>

<hr>
<section id="%">
 <a name="%"></a>
 <h2>%<a class="headerlink" href="#%" title="Link to this heading">¶</a></h2>
<p>Returns the remainder of first value divided by second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> % <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! vector!</span>] 
  value2      [<span class="types">scalar! vector!</span>] 
</pre>
</section>

<hr>
<section id="|">
 <a name="|"></a>
 <h2>|<a class="headerlink" href="#|" title="Link to this heading">¶</a></h2>
<p>Returns the first value ORed with the second.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> | <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
  value2      [<span class="types">logic! integer! char! tuple! binary! bitset! typeset! datatype! pair! vector!</span>] 
</pre>
</section>

<hr>
<section id="+">
 <a name="+"></a>
 <h2>+<a class="headerlink" href="#+" title="Link to this heading">¶</a></h2>
<p>Returns the addition of two values.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> + <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">scalar! date! vector!</span>] 
  value2      [<span class="types">scalar! date! vector!</span>] 
</pre>
</section>

<hr>
<section id="++">
 <a name="++"></a>
 <h2>++<a class="headerlink" href="#++" title="Link to this heading">¶</a></h2>
<p>Increment an integer or series index. Return its prior value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">++ <span class="rebarg">word</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  word        [<span class="types">word!</span>] Integer or series variable
</pre>
</section>

<hr>
<section id="?">
 <a name="?"></a>
 <h2>?<a class="headerlink" href="#?" title="Link to this heading">¶</a></h2>
<p>Note: Shell shortcut for <a href="#help">help</a>.</p>
</section>

<hr>
<section id="??">
 <a name="??"></a>
 <h2>??<a class="headerlink" href="#??" title="Link to this heading">¶</a></h2>
<p>Debug print a word, path, or block of such, followed by its molded value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">?? <span class="rebarg">name</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  name         Word, path or block to obtain values.
</pre>
</section>

<hr>
<section id="<">
 <a name="<"></a>
 <h2><<a class="headerlink" href="#<" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the first value is less than the second value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> < <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1       
  value2       
</pre>
</section>

<hr>
<section id="<=">
 <a name="<="></a>
 <h2><=<a class="headerlink" href="#<=" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the first value is less than or equal to the second value.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> <= <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1       
  value2       
</pre>
</section>

<hr>
<section id="<>">
 <a name="<>"></a>
 <h2><><a class="headerlink" href="#<>" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are not equal.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> <> <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id="<<">
 <a name="<<"></a>
 <h2><<<a class="headerlink" href="#<<" title="Link to this heading">¶</a></h2>
<p>Shift bits to the left (unsigned).</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">data</span> << <span class="rebarg">bits</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  data        [<span class="types">integer!</span>] 
  bits        [<span class="types">integer!</span>] 
</pre>
</section>

<hr>
<section id="!">
 <a name="!"></a>
 <h2>!<a class="headerlink" href="#!" title="Link to this heading">¶</a></h2>
<p>Returns the logic complement.</p>

<h6>Usage:</h6>
<pre class="usage fs-6">! <span class="rebarg">value</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value       [<span class="types">any-type!</span>] (Only FALSE and NONE return TRUE)
</pre>
</section>

<hr>
<section id="!=">
 <a name="!="></a>
 <h2>!=<a class="headerlink" href="#!=" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are not equal.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> != <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>
</section>

<hr>
<section id="!==">
 <a name="!=="></a>
 <h2>!==<a class="headerlink" href="#!==" title="Link to this heading">¶</a></h2>
<p>Returns TRUE if the values are not strictly equal.</p>

<h6>Usage:</h6>
<pre class="usage fs-6"><span class="rebarg">value1</span> !== <span class="rebarg">value2</span></span></pre>

<pre class="help">
<span class="tit">ARGUMENTS:</span>
  value1      [<span class="types">any-type!</span>] 
  value2      [<span class="types">any-type!</span>] 
</pre>
</section>
