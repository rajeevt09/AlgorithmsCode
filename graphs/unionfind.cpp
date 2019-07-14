#include <vector>
#include <iostream>
using namespace std;

class UF
{
    public:
    UF(int _n):n(_n)
    {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i] =i;
        }
        cc = n;
    }
    
    int getRoot(int a)
    {
        while(a != parent[a])
        {
            a = parent[a];
        }
        return a;
    }
    
    void connect(int a,int b)
    {
        cout << "connect";
        int roota = getRoot(a);
        int rootb = getRoot(b);
        if(roota == rootb) return ; //already connected
        if(size[roota] < size[rootb])
        {
           parent[roota] = rootb; 
           size[rootb] += size[roota];
        }
        else
        {
            parent[rootb] = roota; 
            size[roota] += size[rootb];
        }
        cc--;
        print();
    }

    void print()
    {
        cout << endl;
        for(auto i:parent)
        {
            cout << i << ",";
        }
            
    }
    
    
    int count()
    {
        return cc;
    }
    
    private:
    vector<int> parent;
    int n =0;
    int cc = 0;
    vector<int> size;
    
};

class Solution {
public:
    
    bool isOpen(int x,int y)
    {
        return ( x>=0 && x<m && y >=0 && y<n && grid[x][y] == 1);
    }
    
    int toNum(int x,int y)
    {
        return x*m +n;
    }
    
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        UF uf(m*n);
        m = m;
        n = n;
        vector<int> results;
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        grid.resize(m,vector<int>(n,0));
        for(auto pos : positions)
        {
            int v = toNum(pos.first,pos.second);
            //get all neighbours of pos and connect them if they are land
            for(auto dir:dirs)
            {
                vector<int> next(2);
                next[0] = pos.first + dir[0];
                next[1] = pos.second + dir[1];
                if(isOpen(next[0],next[1]))
                {
                    int neighbour = toNum(next[0],next[1]);
                    grid[next[0]][next[1]] = 1;
                    uf.connect(v,neighbour);
                }
            }
            results.push_back(uf.count());
            
        }
        return results;
    }
    
    vector<vector<int>> grid;
    int m;
    int n;
};


int main()
{
 UF uf(4);
 uf.connect(0,3);
 cout << "count " << uf.count();
 uf.connect(1,3);
 cout << "count " << uf.count();
   
 uf.connect(2,1);
 cout << "count " << uf.count();
  
}
