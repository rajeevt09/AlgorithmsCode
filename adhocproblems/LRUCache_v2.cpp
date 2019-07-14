#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache
{
  using shared_ptr<Node> pNode;
  class Node
  {
    string key;
    string value;
    list<pNode>::iterator it;
  };
  public :
  LRUCache(size_t size):m_size(size){};
   
  void put(string key,string value)
  {
      // 
      if(m_capacity == 0) return;
      string oldVal;
      if(get(key,oldVal)) 
      {
         //key already exists just update
         m_map[key] = value;
         return;
      }
    
      //1 . check size
      if(m_map.size() == m_capacity)
      {
        //2. need to evacuate an element 
        // remove the tail elemnt which is LRU 
        pNode = m_order.tail;
        m_order.pop_tail();
        m_map.erase(key);        
      }
    
    //step 3 insert newly added elemnt into deque at head (Most Recent)
    pNewNode = make_shared<Node>(key,value);
    m_order.push_head(pNewNode);
    pNewNode->it  = m_order.begin();
    
    //step 4 insert new element in hash map
    m_map[key] = pNewNode;
    
  }
  
  
  /*return value*/
  bool get(string key,string &value)
  {
    bool bFound = false;
    if(m_capacity == 0) return bFound;
    if(m_map.find(key) != m_map.end())
    {
       pNode = m_map[key];
       value  = pNode->value;
       //move the element to front of queue
       m_order.erase(pNode->it);
       m_order.push_head(pNode); //Most Recently used
       bFound  = true;
    }
    return bFound;
  }
    
  
  
  private:
  unordered_map<string,pNode> m_map; //hash table
  list<pNode> m_order;   //order of Access
  size_t m_capacity=0;
    
};


int main() {
  using Key = std::string;
  using Value = std::string;

  // construct with a maximum size of 3
  //LRU<Key, Value> cache(3);
  LRUCache cache(3);

  cache.put("a", "foo");    // lru order: [a]
  cache.put("b", "bar");    // lru order: [a, b]
  cache.put("c", "foobar"); // lru order: [a, b, c] 
  // cahe.put("a" , "foornew");
  // cahcle.put("a","");

  // eject a, lru order: [b, c, d]
  cache.put("d", "baz");

  // update b, lru order: [c, d, b]
  assert(cache.get("b") == "bar");

  // eject c, lru order: [d, b, e]
  cache.put("e", "hello world");
}
