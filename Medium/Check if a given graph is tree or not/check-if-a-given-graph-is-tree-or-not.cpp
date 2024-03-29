//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
  bool dfs(vector<int>lis[],int vis[],int node,int parent)
  {
      vis[node]=1;
      for(auto it:lis[node])
      {
          if(it!=parent)
          {
              if(vis[it]==1) return 1;
              bool y=dfs(lis,vis,it,node);
              if(y==1) return 1;
          }
      }
      return 0;
  }
    int isTree(int n, int m, vector<vector<int>> &adj) 
    {
        // code here
        vector<int>lis[n];
        for(int i=0;i<m;i++)
        {
            int u=adj[i][0];
            int v=adj[i][1];
            lis[u].push_back(v);
            lis[v].push_back(u);
            
        }
        int vis[n]={0};
        int c=0;
        int parent=-1;
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1)
            {
                int u=dfs(lis,vis,i,parent);
                if(u==1) return 0;
                c++;
            }
           
            
        }
        if(c<=1) return 1;
        return 0;
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends