#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;
bool bexit = false;
template<class T>
class pcq
{
public:
  pcq(size_t c):capacity(c)
  {
    buffer = make_shared<vector<T>>(c);
  }

  void insert(T val)
  {
    unique_lock<mutex> lck(m);
    while(elems == capacity)
    {
       nfull.wait(lck);
    }
    *buffer[wr++] = val;
    wr = wr%capacity;
    elems++;
    empty.notify_all();
  }

  T remove()
  {
     unique_lock<mutex> lck(m);
     while(elems == 0)
     {
       empty.wait(lck);
     }
     T val = *buffer[rd++];
     rd = rd%capacity;
     elems--;
     nfull.notify_all();
     return val;
  }
 
private:
  shared_ptr<vector<T>> buffer;  
  size_t rd = 0;
  size_t wr = 0;
  size_t elems = 0;
  size_t capacity = 0;
  mutex m;
  condition_variable nfull;
  condition_variable empty;
};

pcq<int> q(20);

void produce()
{ 
   static int i = 0;
   while(!bexit)
   {
       q.insert(i++);
   }
   cout << "Producer exiting" << endl;  
}

void consume()
{
   while(!bexit)
   {
      int val = q.remove();
      cout << "read:" << val << endl;      
      this_thread::sleep_for(chrono::seconds(1));
   }
   cout << "consumer exiting.." << endl;
}

int main()
{
    const int numThreads = 1;
    vector<thread> producers;
    vector<thread> consumers;
    for(int i=0;i<numThreads;i++)
    {
       producers.push_back(thread(produce));
       consumers.push_back(thread(consume));
    }

    this_thread::sleep_for(chrono::seconds(10));
    bexit = true;

    for(int i=0;i<numThreads;i++)
    {
       consumers[i].join();
       producers[i].join();
    }
}
