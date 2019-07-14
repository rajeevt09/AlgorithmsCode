#include <iostream>
#include <array>
using namespace std;

#define SIZE 10

void swap(array<int,SIZE> &arr,int a, int b)
{
   int temp = arr[a];
   arr[a] = arr[b]; 
   arr[b] = temp;
}

int partition(array<int,SIZE> &arr,int lo,int hi,int pivot)
{
    int i = lo;
    int end = hi;
    int index = lo;
    while(i <= end)
    {
       //cout << arr[i] << ":" ;
       if(arr[i] > pivot)
       {
          swap(arr,i,end);      
          end--;
       }
       else if(arr[i] < pivot)
       {
          swap(arr,i,index);
          index++;  
          i++;
       }
       else //equal to case
       {
          i++; 
       }
    }
    return index;
}

void matchelem(array<int,SIZE> &A,array<int,SIZE> &B,int lo,int hi)
{
      if(lo>=hi) return;
      //choose last element as pivot
      int pivot = B[hi];
      int pivindex = partition(A,lo,hi,pivot);
      partition(B,lo,hi,A[pivindex]);
      matchelem(A,B,lo,pivindex-1);
      matchelem(A,B,pivindex+1,hi);
}

int main()
{
    cout << "Matchs Nuts and Bolts";
    array<int,SIZE> A={1,7,3,77,2,16,5,0,4,54};
    array<int,SIZE> B={54,5,7,0,2,77,1,4,16,3};

    

   
   matchelem(A,B,0,SIZE-1);
   cout << "A :" << endl;
   for(int i:A) cout << i << " ";
   cout << "B :" << endl;
   for(int i:B) cout << i << " ";
   
}
