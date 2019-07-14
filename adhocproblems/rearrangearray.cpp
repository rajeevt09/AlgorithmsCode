#include <vector>
#include <iostream>
using namespace std;
/*
Given an array of sorted integers with duplicates, rearrange the array so that all unique integers 
move to the front of the array in a sorted fashion and the duplicates move to the back of the array.
*/

void swap(vector<int> &array,int rd,int wr)
{
     int temp = array[rd];
     array[rd] = array[wr];
     array[wr] = temp;
}

void rearrange_array(vector<int> &array)
{
   int length = array.size();
   if(length <= 1) return ;
   int rd = 1;
   int wr = 1;
   int elem  = array[0];
   while(rd <= length-1)
   {
       while(array[rd] == elem)
       {
           rd++;
       }
       if(rd > length-1) break;
       // swap new elem at rd at wr
      elem = array[rd];      
      swap(array,rd,wr);
      wr++;
      rd++;
   }
}

int main()
{
    //vector<int> array = {2,2,4,5,7,7,12,12,12};
    vector<int> array = {1,2,3,4,5,6,7,7,7,7,8};
    //vector<int> array = {2,4,5,7,12};
    cout << "Rearrange Elements in array" << endl;
    
    for(int elem:array)
     cout << elem << " , " ;
    cout << endl;
    rearrange_array(array);
    for(int elem:array)
     cout << elem << " , " ;
    cout << endl;
}
