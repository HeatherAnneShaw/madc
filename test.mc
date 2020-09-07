
''

https://www.youtube.com/watch?v=69edOm889V4

https://www.youtube.com/watch?v=86xWVb4XIyE

https://en.wikipedia.org/wiki/Tail_call

TODO Current:

function extends type
	fun extends str
	"some string".fun(x)

TODO SOON:

	> reorganize directory tree
	
	> tree printing and more advanced garbage collection in that order

> reimplement var++ and the other assignment operators

> there needs to be a function map<name,pointer> to register functions imported
	from external sources, that way builtins for example can be more modular

> for the love of god start using exceptions for errors instead of catching with logic
	try, catch, throw

> build regular expressions into the language

> live coding graphical text editor


FIXME
> Interactive mode sucks ass right now, I assume it will be fixed after above

> there may be a memory leak in lists, I just haven't checked yet...
	when you free a list type, it should call the destructor for its member values


CAUTION!!!

This is pre-alpha software. it is currently absolutely useless in production.

I haven't even decided whether or not functions will inherit global scope yet (they currently do)

''

import "testlib.mc"



macrolam int : 64 * 2;

print macrolam();

for i=5:i>0:i=i-1 {
	print macrolam();
}

print type true;

/*
// lists (you can put ANYTHING in there, including functions)
a = [1,2,3,"a","b"+"c"];
print a;

print a + ["add"] + ["more"] + ["stuff"];
print [1,2,3] == [1,2,3];
print [1,2,3] == [1,2,4];

print;

print ["a"] == ["a"];
print ["b"] == ["a"];

print ["a",42,"b",42,"c"] - 42;
//print a[3];  // "a"
//print a[-1]; // "bc"
*/

/*
// string arithmatic
print "stuff " + "things"; // "stuff things"
print "aaaa bbbb cccc" - "b"; // "aaaa  cccc"
print "a" * 2;	// "aa"
print "this is not complicated" / " "; // ["this", "is", "not", "complicated"]


// if else statement (basically follows the rules as C with less characters)
// blocked if else statement
if 1 is 0:
	print "we dont get here";
else {
	print "passed";
}

// turnary you may also use '?' interchangeably with 'if' in both cases
x = ? true : 1337 : 0;
print x;

//// while variables dont need to be typed, operands and return values must be
//// this allows us to have interface safety through type checking
// basic function with operands and return
fun1 int x : int {
	return x*2;
}

// basic function with return no operands
fun2 int {
	return 42;
}

// basic function with operands no return
fun3 str x {
	print "foo"+x;
}

// basic function without operands or return value
fun4 {
	print "test";
}

// lambda expressions
foo int x : int : x**2;
a = 64;
macrolam int : a * 2;

print "YAY!!!!!";
print macrolam();


// dictionary (keys must be the same type, but dont have to be strings)
print [
	"key1": 2,
	"key2": "something"
];

// classes infer virtual functions by type description and map them
// classes are Value types, members MUST be explicitly typed

$ABasicClass {
		function1 int x : int {...}
		function1 str x : int {...}
		int variable = 42;
}
ABasicClass::function1(12);

*/





