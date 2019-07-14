#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int> &array,int lo,int mid,int hi);
void MergeSortHelper(vector<int> &array,int lo,int hi)
{
    if(lo >= hi) return;
    //sort elements in range[lo,hi]
    int mid = ((hi-lo)/2)+lo;
    
    //recursively sort left and right sub-arrays
    MergeSortHelper(array,lo,mid);
    MergeSortHelper(array,mid+1,hi);
   //merge the two sorted sub arrays into array
    merge(array,lo,mid,hi);
    
}


void merge(vector<int> &array,int lo,int mid,int hi)
{
   vector<int> mergedArr;
   int i = lo , j=mid+1;

   cout << "merge : " << lo << "," << mid << "," << hi << endl;
   while(i <= mid && j <= hi)
   {
      if(array[i] <= array[j])
      {
         mergedArr.push_back(array[i]);
         i++;
      }
      else
      {
        mergedArr.push_back(array[j]);
        j++;
      }
   }

   //copy over remaining elements
   while(i <= mid)
   {
     mergedArr.push_back(array[i]);
     i++;
   }
   while(j <= hi)
   {
     mergedArr.push_back(array[j]);
     j++;
   }

   //copy back
   i = lo;
   for(int i:mergedArr)
   {
      cout << i << " , ";
      array[lo++] = i;
   }
   cout << endl;
}

int main()
{
   /*vector<int> arr1 = {-1,0,-2,5};

   merge(arr1,0,1,arr1.size()-1);

   for(int i=0;i<arr1.size();i++)
   {
      cout << arr1[i] << " , ";      
   }*/

   vector<int> arr = {-1,0,-2,5,2,9,1};
   MergeSortHelper(arr,0,arr.size()-1);
   for(int i:arr)
    cout << i << " , " ;

}
