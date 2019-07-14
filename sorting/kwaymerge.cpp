#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int key;
    int data;
    node(int k,int d):key(k),data(d){};
};

/*
 * Complete the function below.
 */
vector <int> mergeArrays(vector < vector<int> > arr) {
    vector<int> merged;
    auto comp = [](node first,node second){return first.key >= second.key;};
    std::priority_queue<node,vector<node>,decltype(comp)> pq(comp);
    int k = arr.size();
    int n = arr[0].size();
    cout << "k : " << k << "n :" << n << endl;
    if(n==0) return vector<int>();
    int *indexes = new int[k];
    for(int i=0;i<k;i++)
    {
        indexes[i] = 0;
        pq.push(node(arr[i][0],i));
        cout << "push" << arr[i][0] << endl;
    }
    
    while(!pq.empty())
    {
        node sel = pq.top();
        pq.pop();
        merged.push_back(sel.key);
        //check if array not ended
        {
            int selected_array_index = sel.data;
            // advanced selecetd array index
            indexes[selected_array_index]++;
            cout << "value " << sel.key << "i " << selected_array_index << "j " <<  indexes[selected_array_index] << endl;
            if(indexes[selected_array_index] < n)
            {
               int key = arr[selected_array_index][indexes[selected_array_index]];
               pq.push(node(key,selected_array_index));  
            }
        }
    }
    delete []indexes;
    return merged;
}


int main()
{
  vector  <vector<int>>  myarr;
  vector<int> a = {1,5,9};
  vector<int> b = {3,4,6};
  vector<int> c = {2,7,10};
  myarr.push_back(a);
  myarr.push_back(b);
  myarr.push_back(c);
   cout << "kway merge" << endl;
  vector<int > result = mergeArrays(myarr);
  cout << "result";
  for(int i=0;i<result.size();i++)
  {
     cout << result[i] << " " ;    
  }
   return 0;
};
