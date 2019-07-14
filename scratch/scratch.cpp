#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void reverse_string(string &str);

class Node
{
   public:
   Node()=default;
   Node(int _v) : val(_v){}

   int val = 0;
};

int main()
{
   string str="123456789123456789123456789123456789123456789212324342435534643645632452363456457457";
   cout << "Reverse a string input : " << str << endl;
   reverse_string(str);
   cout << "Reverse a string output : " << str << endl;


   unordered_map<int,Node> mymap;
   mymap[0] = Node(1);
   cout << "Node val at key=0" << mymap[0].val;
}

void swap(string &str,size_t i,size_t j)
{
   char c = str[j];
   str[j] = str[i];
   str[i] = c;
}

void reverse_string(string &str)
{
   size_t nlen = str.length();
   for(size_t i =0 ;i < nlen/2  ;i++)
   {
       swap(str,i,nlen-i-1);  
   }
}


