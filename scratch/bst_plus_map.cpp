#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <iostream>
using namespace std;
void test_multiset();
int main()
{
     map<int,string> bst;
     unordered_map<string,map<int,string>::iterator> hmap;
     auto it = bst.insert({2,"hello"});
     hmap["hello"] = it.first;
     it = bst.insert({1,"how"});
     it = bst.insert({4,"you"});
     hmap["how"] = it.first;
     cout << bst.rbegin()->second;
     test_multiset();
     return 0;

}


using myp = pair<string,int>;
void print(multiset<myp> &colors)
{
    for(auto c: colors)
    {
        cout << c.first << ":" << c.second << ",";
    }
    cout << endl;

}

void test_multiset()
{
    auto cmp = [](myp &p1,myp &p2){ p1.first == p2.first ? return p1.second > p2.second : p1.first > p2.first;};
    multimap<string,int,decltype(cmp)> colors(cmp);

    for (auto p : {{"red",10},{"green",20},{"blue",15}})
    {
        colors.insert(p);
    }

    colors.insert({"white",11});
    colors.insert({"orange",12});
    print(colors);
    colors.insert({"white",9});
    print(colors);
    auto it = colors.find("white");
    colors.erase(it);
    colors.erase("blue");
    print(colors);

}

