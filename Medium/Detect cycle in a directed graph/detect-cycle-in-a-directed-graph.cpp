//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],int i,vector<int>&vis,vector<int>&pathvis)
    {
        vis[i]=1;
        pathvis[i]=1;
        for(auto it:adj[i])
        {
            //int k=adj[i][it];
            if(!vis[it])
            {
                if(dfs(adj,it,vis,pathvis)==1) return 1;
            }
            else if(pathvis[it]) return 1;
            
            
        }
        pathvis[i]=0;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[]) 
    {
        // code here
        vector<int>vis(V+1,0);
        vector<int>pathvis(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(adj,i,vis,pathvis)==1) return 1;
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends