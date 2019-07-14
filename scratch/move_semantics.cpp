#include <vector>
#include <iostream>
using namespace std;

int main()
{
     vector<string> vec1 = {"hello","how","are","you"};
     vector<string> vec2;

/*     for(int i=0;i<vec1.size();i++)
     {
          vec2.push_back(std::move(vec1[i]));
     }*/

     for(int i=0;i<vec1.size();i++)
     {
         cout << vec1[i] << endl;
     }
     return 0;
}
