#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;

class edge
{
public:
   edge(int from,int to,int weight):m_from(from),m_to(to),m_weight(weight){}
   int other(int i){
           if(i == m_from) return m_to;
           else return m_from;
    }
   int weight()
   {
        return m_weight;
   }  
private:
    int m_from;
    int m_to;
    int m_weight;
};

class graph
{
public:
    void addEdge(int from,int to,int weight)
    {
        vector<edge> empty;
        m_adj[to] = empty;
        m_adj[from].push_back(edge(from,to,weight));   
        m_distTo[from] = m_distTo[to] = INT_MAX;
    }

    void print()
    {
        cout << "Displaying Graph : ";
        for(auto it:m_adj)
        {
             cout << endl;
             int vertex = it.first;
             cout << vertex << " : ";
             for(edge e : m_adj[vertex])
             {
                  cout << e.other(vertex) << "," << e.weight() << ";" ;
             }
        }
    }

    void djikstra(int s)
    {
        auto cmp = [](const pair<int,int> &left,const pair<int,int> &right){ return left.first > right.first;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        pq.push(make_pair(0,s));
        m_distTo[s] = 0;
        cout << "djikstra"<< endl;  
        while(!pq.empty())
        {
            pair<int,int> pv = pq.top();
            pq.pop();
            int v = pv.second;
            //iterate all edges from v
            for(edge e:m_adj[v])
            {
                int other = e.other(v);
                cout << other << endl;
                if(m_distTo[other] > e.weight() + m_distTo[v])
                {
                     cout << "updating";
                     //update dist
                     m_distTo[other] = e.weight() + m_distTo[v];
                     m_edgeTo[other] = v; 
                     pq.push(make_pair(m_distTo[other],other));
                }
                
            }
        }
        cout << "Printing distTo" << endl;
        for(auto it:m_distTo)
        {
            cout << it.first << ":" << m_distTo[it.first] << endl;
        }
        cout << endl;
    }
    int getDist(int v)
    {
        return m_distTo[v];   
    }
private:
    unordered_map<int,vector<edge>> m_adj;
    unordered_map<int,int> m_distTo;
    unordered_map<int,int> m_edgeTo;
    
};


int main()
{
    int dag_nodes = 4;
    vector<int> dag_from = {1,1,1,3};
    vector<int> dag_to = {2,3,4,4};
    vector<int> dag_weight = {2,2,4,1};
    int from_node = 1;
    int to_node = 4;

    //creating graph
    graph myGraph;
    for(int i=0;i<dag_nodes;i++)
    {
        myGraph.addEdge(dag_from[i],dag_to[i],dag_weight[i]);
    }
    myGraph.print();
        
/*    auto cmp = [](const pair<int,int> &left,const pair<int,int> &right){ return left.first > right.first;};
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);

    pq.push(make_pair(20,5));
    pq.push(make_pair(40,1));
    pq.push(make_pair(30,3));
    pq.push(make_pair(10,2));
    pq.push(make_pair(50,4));


    while(!pq.empty())
    {
         pair<int,int> p = pq.top();
         pq.pop();
         cout << p.second << " , ";
    }*/

    cout << "Min Dist : " << endl;
    myGraph.djikstra(from_node);
    int minDist = myGraph.getDist(to_node);
    cout << minDist;
     

}
