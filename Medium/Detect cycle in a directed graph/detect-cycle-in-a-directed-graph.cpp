//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    int dfs(int i,vector<int>&vis,vector<int>adj[],vector<int>&pathvis)
    {
        vis[i]=1;
        pathvis[i]=1;
        for(auto it:adj[i])
        {
            if(vis[it]==0)
            {
                if(dfs(it,vis,adj,pathvis)==1) return 1;
            }
             else if(vis[it]==1 && pathvis[it]==1)
            {
                return 1;
            }
            
            
        }
        pathvis[i]=0;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>ans;
	    queue<int>pq;
	    vector<int>indeg(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indeg[it]++;
	        }
	    }
	    for(int i=0;i<indeg.size();i++) 
	    {
	        if(indeg[i]==0)
	        {
	            pq.push(i);
	            ans.push_back(i);
	        }
	    }
	    while(!pq.empty())
	    {
	        int t=pq.front();
	        pq.pop();
	        for(auto it:adj[t])
	        {
	            indeg[it]--;
	            if(indeg[it]==0)
	            {
	                pq.push(it);
	                ans.push_back(it);
	            }
	        }
	        
	    }
	    if(ans.size()!=V) return 1;
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