#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;


class Node
{
public:
   int val;
   std::deque<int>::iterator it;
   Node(int v,std::deque<int>::iterator i):val(v),it(i){};
};

class LRUCache
{

public:
   LRUCache(int c):capacity(c){};
   ~LRUCache(){};
   void put(int k,int v);
   int get(int k);
   int access(int k,int v);
private:
   std::deque<int> q;
   unordered_map<int,Node> map;
   int capacity = 0;
};

int LRUCache::get(int k)
{
    int v;
    v = access(k,-1); 
    return v; 
}

void LRUCache::put(int k,int v)
{
    //cout << "Map Size : " << map.size();
    if(map.size() >=  capacity)
    {
       //evacuate element to make space
       int kk = q.back();
       q.pop_back();
       //remove correseponding key from map
       map.erase(kk);   
       //cout << "erasing key : " << kk << endl;  
    }
    //now insert new element into map
    //cout << "Insert K " << k << "V " << v << endl;
    access(k,v);
}

int LRUCache::access(int k,int v)
{
    int val = v; //update or new insert case
    auto it = map.find(k);
    if(it != map.end()) 
    {
        Node node = it->second;
        q.erase(node.it);
        map.erase(k);
        if(v == -1) val = node.val; //GET case
    }
    else
    {
        if(v == -1) return -1; //GET case
    }
    //cout << "Reinsert K " << k << "V " << node.val << endl;
    q.push_front(k);
    Node newNode(val,q.begin());
    map.insert(std::make_pair(k,newNode));     
    return val;
}
int main()
{
    LRUCache cc(4);
    cc.put(1,11);
    cc.put(2,12);
    cc.put(3,13);
    cc.put(4,14);
    cc.put(5,15);
    cc.put(6,16);
    cc.put(7,17);
    cc.put(8,18);
    cout << cc.get(1) << endl;
    cout << cc.get(5) << endl;
    cc.put(9,19);    
    //cc.put(10,20);    
    cout << cc.get(5) << endl;
    cout << cc.get(6) << endl;
    cout << cc.get(9) << endl;
    //cout << cc.get(10) << endl;

}
