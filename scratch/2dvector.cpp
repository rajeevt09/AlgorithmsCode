#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printvec(vector<vector<string>> res);
int main()
{
    vector<vector<string>> myvec;
    for(int i=0;i<10;i++)
    {
       vector<string> row;
       string istr = std::to_string(i);
       myvec.push_back(row);
       myvec[i].push_back("Hello");
       myvec[i].push_back("how");
       myvec[i].push_back("are");
       myvec[i].push_back("you");
       myvec[i].push_back(istr);
    }

    int size = myvec.size();
    cout << size;
    printvec(myvec);
    return 0;

}

void printvec(vector<vector<string>> res)
{
    for(int res_i = 0; res_i < res.size(); res_i++) {
        for(int res_j = 0; res_j < res[res_i].size(); res_j++) {
            cout << res[res_i][res_j] << " ";;
        }
        cout << endl;
      }
}
