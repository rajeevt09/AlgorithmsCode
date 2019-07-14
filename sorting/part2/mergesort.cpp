void MergeSortHelper(vector<int> &array,int lo,int hi);
// Complete the MergeSort function below.
vector<int> MergeSort(vector<int> &intArr) {
       MergeSortHelper(intArr,0,intArr.size()-1);
       return intArr;
}

void merge(vector<int> &array,int lo,int mid,int hi)
{
   vector<int> mergedArr;
   int i = lo , j=mid+1;
   while(i <= mid && j <= hi)
   {
      if(array[i] <= array[j]) 
          mergedArr.push_back(array[i++]);
      else 
          mergedArr.push_back(array[j++]);        
   }

   //copy over remaining elements
   while(i <= mid)
       mergedArr.push_back(array[i++]);
   
   while(j <= hi)
        mergedArr.push_back(array[j++]);

   //copy back
   for(int val:mergedArr)
       array[lo++] = val;
}


void MergeSortHelper(vector<int> &array,int lo,int hi)
{
    if(lo >= hi) return;
    vector<int> tempArr;
    //sort elements in range[lo,hi]
    int mid = ((hi-lo)/2)+lo;
    
    //recursively sort left and right sub-arrays
    MergeSortHelper(array,lo,mid);
    MergeSortHelper(array,mid+1,hi);
   //merge the two sorted sub arrays into array
    merge(array,lo,mid,hi);
    
}


