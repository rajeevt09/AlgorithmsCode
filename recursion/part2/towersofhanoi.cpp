#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class rod
{
public:
    rod(string name):m_name(name){}
    string getName(){return m_name;}
    void push(int disk) {m_contents.push(disk);}
    int pop(){
         if(!m_contents.empty())
         {
             int disk = m_contents.top();
             m_contents.pop();
             return disk;
         }
         return -1;
      }
              
private:
    string m_name;
    stack<int> m_contents;

};

void move(rod &src,rod &dest)
{
     int disk = src.pop();
     dest.push(disk);
     cout << disk << " : " << src.getName() << " --> " << dest.getName() << endl;  
}

void towersOfHanoi(int numDisks,rod &src,rod &dest,rod &buffer)
{
    if(numDisks == 1)
    {
         move(src,dest);
         return;
    }
    towersOfHanoi(numDisks - 1, src, buffer, dest);
    move(src,dest);
    towersOfHanoi(numDisks - 1, buffer, dest, src); 
}


int main()
{
    rod s(string("source")),d(string("destination")),buffer(string("buffer"));
    int n = 4; //No Of Disks
    for(int i=n; i>=1; i--)
      s.push(i);
    towersOfHanoi(n,s,d,buffer);
    

}
