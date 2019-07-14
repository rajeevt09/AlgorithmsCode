#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;




string MinWindow(string strText, string strCharacters) {
      string sMinSoFar = "";
      std::unordered_map<char,int> pMap;
      std::unordered_map<char,int> tMap;
      for(char c:strCharacters)
      {
            pMap[c]++;
      }
      cout << "Printing map:" << endl;
      for(char c:strCharacters)
      {
         cout << c << ":"  << pMap[c] << endl;
      }
      
      std::unordered_map<char,int> tempMap = pMap;
      cout << "Printing map:" << endl;
       for(char c:strCharacters)
      {
         cout << c << ":"  << tempMap[c] << endl;
      }

      int lo = 0;
      int hi = 0;
//      cout << "pMap Size is " << pMap.size() << endl;
      while(hi < strText.length())
      {
           //keep expanding right index till solution satisfied or done
           while(hi < strText.length() && tempMap.size() )
           {
  //             cout << strText[hi];
               if(pMap.find(strText[hi]) != pMap.end())
               {
                    tMap[strText[hi]]++;
                    if(tempMap.find(strText[hi]) != tempMap.end())
                    { 
                        tempMap[strText[hi]]--;
                        if(tempMap[strText[hi]] == 0 ) tempMap.erase(strText[hi]);
                    }
               }
               hi++;           
           }
           cout << "tMap " << tMap.size() << "pMap " << pMap.size() << "tempMap " << tempMap.size() << endl;
            cout << endl <<  "PASS 1 lo : " << lo << " hi : " << hi  << "Min : " << sMinSoFar << "MapSize" << tMap.size() << endl; 
           if(tMap.size() < pMap.size())
            break;

           if(sMinSoFar.length() == 0) sMinSoFar = strText.substr(lo,hi-lo);
           //when solution done keep expanding left index till solution is undone
           while(lo < hi)
           {
               //keep track of minSoFar
               if(sMinSoFar.length() > (hi-lo))
               {
                   sMinSoFar = strText.substr(lo,hi-lo);
               }
 
               //remove element at index : lo from tMap
               if(tMap.find(strText[lo]) != tMap.end())
               {
                    tMap[strText[lo]]--;
                    if(tMap[strText[lo]] < pMap[strText[lo]])
                       break;
                     if(tMap[strText[lo]] == 0 ) tMap.erase(strText[lo]);
               
               }    
               lo++;
           }
           cout << "PASS 2 lo : " << lo << " hi : " << hi  << "Min : " << sMinSoFar << "MapSize" << tMap.size() << endl; 
      }

      return sMinSoFar;
}

int main()
{
   string s = "AYZABOBECODXBANC";
   string t =  "abbac";
   string answer = MinWindow(s,t); 
   cout << answer;
}
