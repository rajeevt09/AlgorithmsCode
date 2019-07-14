#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int main()
{
  string s = "i am splitting this string based on colons";
  stringstream ss(s);

  string token;
  while(ss >> token)
  {
     cout << token << endl;
  }
  
  string s2 = "i;am;splitting;this;string,based;on,colons";
  stringstream ss1(s2);
  while(!ss1.eof())
  {
     string token;
     std::getline(ss1,token,';');
     if(ss1.fail()) break;;
     cout << token << endl; 
  }

   string s3= "1;23;4;5;67;33;9;0;3;4;";
   stringstream ss3(s3);
   int a;
   while(!ss3.eof())
   {
      string token;
      std::getline(ss3,token,';');
      if(ss3.fail()) 
      {
        cout << "Failed " << endl;
        break;
      }
      a = stoi(token); 
      cout  << a << endl;
   }


  return 0;
}

