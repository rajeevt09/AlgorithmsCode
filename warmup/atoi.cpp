#include <iostream>
using namespace std;
 bool isNumeral(char c)
    {
        if(c >= '0' && c <= '9') return true;
        return false;
    }
    bool overflows(int val,int digit,bool isNegative)
    {
        
        int overflow_val = isNegative ? (INT_MAX-digit)/10 : (INT_MAX-digit)/10;
        if(val > overflow_val) return true;
        return false;
    }
    int myAtoi(string str) {
        int num = 0;
        bool negative = 0;
        bool started = false;      
        
        for(char c:str)
        {
            if(started && !isNumeral(c))
            {
                //invalid char found stop parse;
                break;
            }
             //check acceptable characters
            
            //it is a numeral or we havent yet started
            if(c == ' ' ) continue; //ignore whitepsace
                
             //if its a '+' or '-' sign
             if(c == '-')
             {
                 started = true;
                negative = true;
                 continue;
             }
            
            if(c == '+' )
             {
                started = true;
                 continue;
             }
         // anything else not a number return
         if(!isNumeral(c))
            break;                          
          //is it in valid numerical range
          started = true;
          //will we overflow?
          if(overflows(num,std::atoi(&c),negative))
          {
              return negative? INT_MIN:INT_MAX; 
          }   
          num = num*10 + std::atoi(&c);                    
        }
        if(negative) num = -num;
        return num;
    }


int main()
{
   string s = "+11774694q241";
   cout << myAtoi(s);
}
