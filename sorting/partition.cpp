#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

void print(vector<int> &arr)
{
   for(auto i:arr)
   cout << i << ",";
}
auto cmp = [](int &a,int &b){ return a>b;};

template<class C>
size_t partition(vector<int> &arr,int lo,int hi,C greater)
{
    srand(time(NULL));
    size_t piv = lo + (rand() %(hi-lo+1)); 
    cout << "chosen piv" << piv << endl;
    swap(arr[piv],arr[hi]);
    int pivval = arr[hi];
    int end = hi-1 , i =lo;
    while(i <= end)
    {
         if(greater(arr[i],pivval)) swap(arr[end--],arr[i]);
         else i++;
    }
    swap(arr[i],arr[hi]);
    return i;
}


int main()
{
    vector<int> arr ={1,6,2,8,6,3,2,0,9};
    cout << "before " << endl;
    print(arr);
    size_t piv =  partition(arr,0,arr.size()-1,cmp);   
    cout << "array is partitioned at index : " << piv << endl;
    print(arr);
}
