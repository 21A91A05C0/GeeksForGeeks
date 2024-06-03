//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void dfs(int i,vector<int>&vis,stack<int>&st,vector<pair<int,int>>adj[])
  {
      vis[i]=1;
      for(auto it:adj[i])
      {
          if(!vis[it.first])
          {
              dfs(it.first,vis,st,adj);
          }
      }
      st.push(i);
  }
    vector<int> shortestPath(int n,int M, vector<vector<int>>& edges)
    {
        // code here
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            // adj[edges[i][1]].push_back(edges[i][0]);
        }
        stack<int>st;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,st,adj);
            }
        }
        vector<int>ans(n,1e9);
        ans[0]=0;
        while(!st.empty())
        {
            int k=st.top();
            st.pop();
            // int dist=adj[k].second;
            for(auto it:adj[k])
            {
                if(ans[k]+it.second<ans[it.first])
                {
                    ans[it.first]=ans[k]+it.second;
                }
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]==1e9)
            {
                ans[i]=-1;
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends