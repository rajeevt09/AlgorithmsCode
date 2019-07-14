#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void print(std::unordered_map<int,int> *dfa,int m)
{
    cout << "DFA STATE : " << endl;
    for(char c='a';c<='c';c++)
    {
       cout << c;
       for(int i=0;i<m;i++)
       {
           cout << " " << dfa[i][c];
       }
       cout << endl;
    }
}

std::unordered_map<int,int>* build_dfa(string strPattern)
{
    int m = strPattern.length();
    std::unordered_map<int,int> *dfa = new std::unordered_map<int,int>[m];
    int x = 0; // track state x
    //initialize dfa mismatch cases;
    for(int r=0;r<128;r++) 
    { 
        dfa[0][r] = 0;
    }
    dfa[0][strPattern[0]] = 1;
    cout << "DFA : " <<  strPattern << endl;
    for(int i=1;i<m;i++)
    {
        int val = strPattern[i];
        //fill in mismatch cases
        for(int r=0;r<128;r++) 
        { 
             dfa[i][r] = dfa[x][r];
        }
        
        //fill in the match case
        cout << "i " << i << "  " << val << " x " << x << endl;
        dfa[i][val] = i+1; 
        
        //update tracking state x
        x = dfa[x][val] ;
    }
    cout << "DFA : " << endl;
    print(dfa,m);
    return dfa;
}

bool KMP(string strText, string strPattern) {
     std::unordered_map<int,int> *dfa = nullptr;
     dfa = build_dfa(strPattern);
     int m = strPattern.length();
     int state = 0;
     for(char c:strText)
     {
         cout << c << " " << state << ", ";
         int val = c;
         state = dfa[state][val];
         if(state == m) 
         {  
             delete []dfa;
             return true;
         }
     }
     delete []dfa;
     return false;
}

int main()
{
   string strPattern = "ababc";
   string strText = "ababbbbababcaba";
   cout << "KMP " << endl;  
   bool b = KMP(strText,strPattern);
   cout << "matched : " << b << endl;
   return 0;
}
