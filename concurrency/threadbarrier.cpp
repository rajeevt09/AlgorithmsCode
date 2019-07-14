#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <unistd.h>
using namespace std;
class barrier
{
  public:
      barrier(int c):m_count(c)
      {
      };

      void lock()
      {
         unique_lock<mutex> lg(m);
         m_n++;
         //inside critical section
         if(m_n == m_count) cv.notify_all();
         while(m_n < m_count) cv.wait(lg);
      }

   private:
      size_t m_count = 0;
      mutex m;
      condition_variable cv;
      size_t m_n = 0;
};

int main()
{
   barrier bt(5); //create a barrier for 5 threads

   std::thread th[5];
   for(int i=0;i<4;i++)
   {
      usleep(20000);
      if(i ==4) usleep(10000);
      th[i] = thread([&bt](int i){
             cout << "hello from thread" << i << "," << endl;
             bt.lock();
             cout << "released" << i<< endl;
           },i);
   }

   bt.lock();
   
   for(int i=0;i<4;i++)
   {
      th[i].join();
   }
}
