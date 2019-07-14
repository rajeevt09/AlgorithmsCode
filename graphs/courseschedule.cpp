#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int topSort(string course,unordered_map<string,vector<string>> &adj,unordered_map<string,int> &depth)
{
      if(depth[course] != INT_MAX)
      {
          //this vertex is already visited , return the depth
          return depth[course];
      }
      //initialize the depth
      depth[course] = 0;
      //continue dfs for every adjacent node of course
      for(string &neighbour:adj[course])
      {
        int newDepth;
        newDepth = topSort(neighbour,adj,depth);
        depth[course] = max(depth[course],newDepth);
      }
      depth[course] = depth[course] + 1;
      return depth[course];
}

vector<vector<string>> getCourseSchedule(vector<string> &courses,vector<pair<string,string>> &dependencies)
{
      vector<vector<string>> results;
      unordered_map<string,vector<string>> adj;
      unordered_map<string,int> depth;
    
      //insert all nodes into graph
      for(string &s:courses)
      {
         adj.insert(make_pair(s,vector<string>()));
         depth[s] = INT_MAX;
      }
      //insert dependencies as edges into graph
      for(pair<string,string> &dep:dependencies)
      {
         adj[dep.first].push_back(dep.second);
      }

       //topSort the graph updating max depth for each course
      for(auto &it:adj)
      {
          //skip visited 
          if(depth[it.first] == INT_MAX)
          {
              topSort(it.first,adj,depth);
          }
      }

      //update results in depth order
      int maxDepth = 0;
      for_each(begin(depth),end(depth), [&maxDepth](pair<string,int> elem) 
      {
	 maxDepth = std::max(maxDepth,elem.second);
      });
      cout << "MaxDepth : " << maxDepth << endl;
      if(maxDepth == 0) return results;
      results.resize(maxDepth);
      for(auto &it:depth)
      {
            int depth = it.second;
            results[depth  - 1].push_back(it.first);
      }
      return results;
}

int main()
{
     vector<string> courses = {"Astronomy","Physics","English","Chemistry","Geometry","Engineering","Social","AstroPhysics","Maths"};
     vector<pair<string,string>> dependencies; //first depends on second
     dependencies.push_back(make_pair("AstroPhysics","Physics"));
     dependencies.push_back(make_pair("Physics","English"));
     dependencies.push_back(make_pair("Social","AstroPhysics"));
     dependencies.push_back(make_pair("Engineering","AstroPhysics"));
     dependencies.push_back(make_pair("Geometry","Maths"));
     dependencies.push_back(make_pair("Astronomy","Physics"));
     dependencies.push_back(make_pair("Chemistry","English"));
     dependencies.push_back(make_pair("Social","English"));
     dependencies.push_back(make_pair("Physics","Geometry"));
     dependencies.push_back(make_pair("Maths","English"));
     

     vector<vector<string>> order = getCourseSchedule(courses,dependencies);
     cout << "All Courses can be completed in " << order.size() << " semesters" << endl;
     cout << endl << "Course Order" << endl;
     for(int i = 0 ; i< order.size(); i++)
     {
        cout << endl << "Semester # " << i+1 << " : " << endl;
        for(string s:order[i])
        {
           cout << s << " , ";
        }    
     }

}
