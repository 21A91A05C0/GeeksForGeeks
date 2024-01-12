//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:

         vector<int>primes;
    void precompute(){
        vector<int>seive(1e6+1,1);
        seive[0]=0;
        seive[1]=0;
        for(int i=2;i*i<=1e6+1;i++)
        {
            if(seive[i]==1)
            {
                
                for(int j=i*i;j<=1e6+1;j+=i)
                {
                    seive[j]=0;
                }
            }
        }
        for(int i=2;i<=1e6+1;i++)
        {
            if(seive[i]) primes.push_back(i);
        }
    }
    void  findthedfs(vector<int>adj[],int node,int vis[],int &count)
    {
        vis[node]=1;
        count++;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                findthedfs(adj,it,vis,count);
            }
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        int ans=0;
        vector<int>adj[n+1];
        for(auto it:g)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int vis[n+1]={0};
        for(int i=1;i<=n;i++)
        {   
            if(!vis[i])
            {
                int count=0;
                findthedfs(adj,i,vis,count);
                ans=max(ans,count);
            }
        }
       // cout<<ans<<" ";
        //cout<<primes[ans-1];
        if(ans==1) return -1;
        //int q=primes[ans-1];
        
        return primes[ans-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g;
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g.push_back({u, v});
// 			g[u].push_back(v);
// 			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends