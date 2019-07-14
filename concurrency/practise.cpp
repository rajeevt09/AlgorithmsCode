#include <thread>
#include <queue>
#include <iostream>
#include <mutex>
using namespace std;


//passing rvalue ref to function
void rfun(int &&a)
{
   cout << "value inside rfun" << a << endl;
}

int main()
{
    int a = 9;
    rfun(move(a));
    cout << "value outside : " << a << endl;
  
   //Create 10 Threads
   vector<thread> vec;
   mutex m;
   for(int i=0;i<10;i++)
   {
        std::unique_lock<std::mutex> lock(m);
        cout << endl;
        thread p = thread([](int i){cout << "hello form thread : " << i; },i);
        vec.push_back(std::move(p));
   }
   for(thread &t:vec)
   {
        t.join();
   }
}

