//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  void schedulethetask(queue<int>&qu,vector<int>&ans,vector<int>&indeg,vector<int>adj[])
  {
      while(!qu.empty())
      {
          int k=qu.front();
          qu.pop();
          ans.push_back(k);
          for(auto it:adj[k])
          {
              indeg[it]--;
              if(indeg[it]==0) qu.push(it);
          }
          
      }
  }
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        vector<int>adj[n];
        vector<int>ans;
        queue<int>qu;
        vector<int>indegree(n,0);
        for(int i=0;i<pre.size();i++)
        {
            int v=pre[i][0];
            int u=pre[i][1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) qu.push(i);
        }
        schedulethetask(qu,ans,indegree,adj);
        //for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        if(ans.size()!=n) return {};
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends