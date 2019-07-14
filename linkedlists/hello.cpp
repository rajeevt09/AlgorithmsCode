#include <iostream>
#include <vector>
using namespace std;
class CUnitTest
{
public:
   static bool reg()
   { 
      cout << "hello";
      return true;
   }
};

bool b = CUnitTest::reg();


int main()
{
}
