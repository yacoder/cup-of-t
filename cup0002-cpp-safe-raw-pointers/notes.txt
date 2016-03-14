+ What's the deal

Herb Sutter & Neil MacIntosh
CppCon 2015 keynote
"Writing Good C++14... By Default"
https://www.youtube.com/watch?v=hEx5DNLWGgA

+ safer language
  prevent crashes and mem leaks
+ faster: raw pointers used more often
+ competition for "safe system language"
some with GC, some without
Go, System C#
C++14 with GSL, Rust

http://joeduffyblog.com/2013/12/27/csharp-for-systems-programming/
http://joeduffyblog.com/2015/12/19/safe-native-code/

Docs: https://github.com/isocpp/CppCoreGuidelines/tree/master/docs
GSL: https://github.com/microsoft/gsl

19-pager
https://github.com/isocpp/CppCoreGuidelines/blob/master/docs/Introduction%20to%20type%20and%20resource%20safety.pdf

p. 6 -- rules of the game
template<typename T>
using owner = T;

p. 9 -- 1000 plain pointers for each "owner", because owners will be hidden inside primitives
p.16 -- why you'd still prefer unique_ptr or another RAII owner class to directly using "owner"

45-pager
https://github.com/isocpp/CppCoreGuidelines/blob/master/docs/Lifetimes%20I%20and%20II%20-%20v0.9.1.pdf
p.3  -- false positive rate kept at under 10%, "ensure leak-freedom and dangle-freedom"


Checker tool:
https://blogs.msdn.microsoft.com/vcblog/2015/12/03/c-core-guidelines-checkers-available-for-vs-2015-update-1/

Blogs:
https://atilanevesoncode.wordpress.com/2015/11/29/the-c-gsl-in-practice/

SO:
http://stackoverflow.com/questions/34832090/whats-the-difference-between-span-and-array-view-in-the-gsl-library
