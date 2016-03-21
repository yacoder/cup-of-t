> For compactness of container objects and for simplicity, C++98 did not require containers to support allocators with state: Allocator objects need not be stored in container objects. This is still the default in C++11, but it is possible to use an allocator with state, say an allocator that holds a pointer to an arena from which to allocate.

Quote from: http://www.stroustrup.com/C++11FAQ.html#scoped-allocator

Further reading:

+ http://stackoverflow.com/questions/12556638/stl-container-constructors-allocator-parameter-and-scoped-allocators
+ http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2005/n1850.pdf
+ http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2013/n3525.pdf
+ https://erdani.com/publications/cuj-2005-12.pdf
+ http://en.cppreference.com/w/cpp/memory/scoped_allocator_adaptor
+ http://www.cppstdlib.com/cppstdlib_supplementary.pdf

Talks:

+ CppCon2014: Alisdair Meredith "Making Allocators Work, Part I" https://www.youtube.com/watch?v=YkiYOP3d64E
+ CppCon2014: Alisdair Meredith "Making Allocators Work, Part II" https://www.youtube.com/watch?v=Q5kyiFevMJQ
+ CppCon2015: Andrei Alexandrescu "std::allocator Is to Allocation what std::vector Is to Vexation" https://www.youtube.com/watch?v=LIb3L4vKZ7U

Slides:

+ http://accu.org/content/conf2012/JonathanWakely-CXX11_allocators.pdf
+ http://www.bloomberglabs.com/content/uploads/sites/2/2013/05/cpp11_allocators.pdf

