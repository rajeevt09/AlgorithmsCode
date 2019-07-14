#include <iostream>
#include <unordered_map>
using namespace std;
class node
{
public:
   node(){};
   ~node(){};
};
int main()
{
   std::unordered_map<string,node> map;
   node temp;
   map.insert(std::make_pair("1",node()));
}
