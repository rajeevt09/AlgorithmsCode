#include <iostream>
#include <vector>
using namespace std;

class LinkedListNode
{
public:
   int val;
   LinkedListNode *next;
   LinkedListNode(int v):val(v),next(nullptr){};
};
void print(LinkedListNode *p)
{
    while(p)
    {
        cout << p->val << "->" ;
        p = p->next;
    }
    cout << "nullptr" << endl;
}
void reverse_list(LinkedListNode *list,int k,LinkedListNode **curhead,LinkedListNode **nexthead)
{
    *curhead = list;
    LinkedListNode * prev = nullptr;
    LinkedListNode * next = nullptr;
    if(!list) return;
    while( k  && list)
    {
//        cout <<  list->val << "<-";
        next = list->next;
        list->next = prev;
        prev = list;
        list = next;
        k--;   
             
    }
//    cout << prev << next;
    *nexthead = next;
    *curhead = prev;
//    cout << endl;
}

LinkedListNode* reverse_linked_list_in_groups_of_k(LinkedListNode* head, int k) {
    LinkedListNode * prev= nullptr;
    LinkedListNode * cur = head;
    LinkedListNode * next = nullptr;
    LinkedListNode * listhead = nullptr;
    while(cur)
    {
        LinkedListNode *newhead = nullptr;
        reverse_list(cur,k,&newhead,&next);        
        //print(newhead);
        //print(next);
        if(prev) 
        {
            prev->next = newhead;
        }
        else
        {
            listhead = newhead;
        }
        prev = cur;
        cur = next;
    }
    return listhead;
}



int main()
{
   int cnt = 6;
   int i =0;
   LinkedListNode *head = nullptr;
   LinkedListNode *prev = nullptr;
   while(cnt)
   {
      LinkedListNode *cur;
      cur = new LinkedListNode(i);
      if(prev) prev->next = cur;
      else head = cur;
      prev = cur;   
      cnt--;
      i++;
   }
   print(head);
#if 0
   {
      //test reverse
      LinkedListNode *curhead = head;
      LinkedListNode *nexthead = nullptr;
      reverse_list(head,3,&curhead,&nexthead);      
      print(curhead);
      print(nexthead);
   }
#endif
   LinkedListNode *newhead = reverse_linked_list_in_groups_of_k(head,3);
   print(newhead);
 
}
