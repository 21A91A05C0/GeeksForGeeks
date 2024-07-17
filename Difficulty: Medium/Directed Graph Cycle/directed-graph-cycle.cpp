//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>indeg(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indeg[it]++;
            }
        }
        vector<int>ans;
        queue<int>qu;
        for(int i=0;i<indeg.size();i++)
        {
            if(indeg[i]==0)
            {
                qu.push(i);
                ans.push_back(i);
            }
        }
        
        while(!qu.empty())
        {
            int node=qu.front();
            qu.pop();
            for(auto it:adj[node])
            {
                indeg[it]--;
                if(indeg[it]==0)
                {
                    qu.push(it);
                    ans.push_back(it);
                }
            }
        }
        if(ans.size()==V) return 0;
        return 1;
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