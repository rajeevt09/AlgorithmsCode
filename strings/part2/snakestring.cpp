#include <vector>
#include <string>
#include <iostream>
using namespace std;

void print_s(int k,char c,bool newLine = false)
{
    string s;
    if(newLine) cout << endl;
   s.push_back(c);
    for(int i =0;i<k;i++)
      s.push_back(' ');
 
    cout << s;
}

void print(string s)
{
    int i = 0;
    int n = s.length();
    int k = 2;
    print_s(1,' ',true);
    while(k<=n-1)
    {  
       print_s(3,s[k]);
       //cout << s[k];
       k = k + 4;
    }
    k = 1;
    print_s(0,' ',true);
    while(k<=n-1)
    {  
       print_s(1,s[k]);
       //cout << s[k];
       k = k + 2;
    }
    k = 0;
    print_s(0,0,true);
    while(k<=n-1)
    {  
       print_s(3,s[k]);
       //cout << s[k];
       k = k + 4;
    }


}


int main()
{
   string str = "Google~Worked";
   print(str);
}
