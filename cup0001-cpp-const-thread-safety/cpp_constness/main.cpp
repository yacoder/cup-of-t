#include <memory>
#include <future>
using namespace std;

class A 
{
   unique_ptr<int> p;

public:
   A() : p(std::make_unique<int>(42)) {}
   void const_method() const { (*p)++; }
};

int main()
{
   const A a;

   // Data race in const method
   auto f1 = async(launch::async, [&a] { a.const_method(); });
   auto f2 = async(launch::async, [&a] { a.const_method(); });

   f1.get();
   f2.get();

   return 0;
}
