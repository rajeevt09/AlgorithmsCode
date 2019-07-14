#include <string>
#include <sstream>
using namespace std;
int main()
{
     char *buf;
     stringstream ss(buf);
     while(!ss.eof())
     {
	string line;
	ss >> line;
     }

     char ptr1[] = "Hello World"; 
     char *ptr2 = (char *)malloc( 5 ); 
     ptr2 = ptr1;
}
