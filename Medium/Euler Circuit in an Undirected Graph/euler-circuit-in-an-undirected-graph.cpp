//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool dfs(vector<int>&vis,vector<int>adj[],int v,int node,int par)
{
    vis[node]++;
    for(auto it:adj[node])
    {
        if(it!=par)
        {
            if(vis[it])
            {
                return 1;
            }
            dfs(vis,adj,v,it,node);
        }
    }
    return 0;
}
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
	    vector<int>vis(v,0);
	    int f=0;
	    for(int i=0;i<v;i++)
	    {
	        for(auto it:adj[i])
	        {
	            vis[it]++;
	        }
	    }
	    
	        for(auto it:vis)
    	    {
    	        if(it%2!=0) return 0;
    	    }
    	    return 1;
    	   
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends