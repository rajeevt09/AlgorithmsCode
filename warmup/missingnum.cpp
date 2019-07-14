#include <iostream>
#include <vector>
using namespace std;

int find_missing(vector<int> arr)
{
   bool bvalid = true;
   int size = arr.size();
   int min = arr[0],max = arr[0];
  
   //find min
   for(auto num:arr)
   {
     if(num < min ) min = num;
     if(num > max ) max = num;
   }

   int mapsize = max-min+1;
   bool *map = new bool[mapsize];
   for(int i=0;i<mapsize;i++)
   {
     map[i] = false;
   }
   for(auto num:arr)
   {
      if(num < 0 || num > (min + mapsize)) {bvalid = false;break;}
      int index = num - min;
      if(index >=0 && index <= mapsize)
      {
           map[index] = true;
      }       
   }
  
   if(!bvalid) return -1;
   for (int i=0;i<mapsize;i++)
   {  
      if(map[i] == false) return i+min;
   }
   return -1;
}


int main()
{
  cout << "Find The Missing Num!" << endl;
  vector<int> array = {4,3,9,5,2,6,8,10,11,17,70,19,12,18,13,15,20,14,21};
  cout << "Missing Num Is " << find_missing(array);
   return 0;
}
