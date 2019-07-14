#include <vector>
#include <iostream>
#include <queue>
using namespace std;


class person
{
public:
    person(int age,string name):m_age(age),m_name(name){};
    int age(){return m_age;};
    string name(){return m_name;};
private:
   int m_age = 0;
   string m_name;
};

int main()
{
    int arr[10] = {10,5,91,21,4,6,71,1,13,81};
    string names[10] = {"Amy","baby","tina","rina","kim","tom","jack","arun","charan","aman"};
    auto cmp = [](int first , int second){return first >= second;};
    cout << "Priority Queue" << endl;
    std::priority_queue< int, std::vector<int>, decltype(cmp) > pq(cmp);
    for(int i = 0;i<10;i++)
      pq.push(arr[i]);
    while(!pq.empty())
    {
       cout << pq.top() << " ";
       pq.pop();
    }
    cout << endl;
    auto cmp2 = [](person p1,person p2){return p1.age() < p2.age();}; 
    std::priority_queue<person,std::vector<person>,decltype(cmp2)> pq2(cmp2);
    for(int i=0;i<10;i++)
    {
       pq2.push(person(arr[i],names[i]));
    }
    while(!pq2.empty())
    {
       person p  = pq2.top();
       cout << p.age() << " " << p.name() << " , ";
       pq2.pop();
    }
   

}


