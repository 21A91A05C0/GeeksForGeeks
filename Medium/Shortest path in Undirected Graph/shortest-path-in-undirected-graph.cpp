//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        // code here
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        queue<pair<int,int>>pq;
        vector<int>ans(n,1e9);
        pq.push({src,0});
        while(!pq.empty())
        {
            int k=pq.front().first;
            int step=pq.front().second;
            vis[k]=1;
            pq.pop();
            ans[k]=min(ans[k],step);
            for(auto it:adj[k])
            {
                if(!vis[it])
                pq.push({it,step+1});
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends