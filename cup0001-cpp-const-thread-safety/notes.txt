Herb Sutter says "const => thread-safe"
* http://channel9.msdn.com/posts/C-and-Beyond-2012-Herb-Sutter-You-dont-know-blank-and-blank 
* http://stackoverflow.com/questions/14127379/does-const-mean-thread-safe-in-c11
* people are confused now even more about const

To learn more about data-race-free code and C++ memory model:
* https://www.youtube.com/watch?v=gpsz8sc6mNU

Compilers do not guarantee that as of 2016
* unsychronized mutable, const_cast are legal
* non-transitivity with pointers is by design
  * http://dlang.org/const-faq.html#transitive-const
  * propagate_const in C++17 -- handy!
  * http://en.cppreference.com/w/cpp/experimental/propagate_const
  * http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4372.html
  * still without extra restrictions this won't make const thread-safe

Writing thread-safe (data-race-free) classes

* enforcement only via code review
* mark methods as "const", pass ref to const, whenever you can
* https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-const
* don't cast const away
* propagate_const for all pointer fields, if possible
* be extra careful with mutable fields
  * internally-syncronized classes are ok, like atomic and mutex
  * fields protected by the mutex are ok, but with extra careful review
* extra careful review for calls to non-member functions
  * thread-safe logging, caching, counters -- maybe have a whitelist

Can non-const methods be thread-safe?
* yes
* on internally synchronized classes all methods are thread-safe
* internally synchronized means ref to non-const can be shared
** mutexes, atomics, events
* currently no standard way to distinguish such classes
* on other classes you need prevent data race by limiting writers access

