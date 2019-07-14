#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class test
{
    public:
    test(int _a) :a(_a){}
    private: 
    int a;
};

vector<test> gettestList()
{
    return vector<test>();
}

int main()
{
   vector<vector<unordered_set<int>>> list;  
   vector<test> testlist = gettestList();  
    
   cout << "<Topic> Homework <part -1/2> <Title> :" << endl;
   return 0;
}
