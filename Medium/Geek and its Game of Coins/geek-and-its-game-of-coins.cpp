//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int ans=0;
  int findthewiinner(int n,int x,int y,int geek,vector<vector<int>>&dp)
  {
      if(geek==1 && (n==1 || n==x || n==y))
      {
          return 1;
      }
      if(geek==0 && (n==1 || n==x || n==y)) return 0;
      
      if(dp[n][geek]!=-1) return dp[n][geek];
      int res=0;
      if(geek==1)
      {
          int r=0;
          if(n-1>=0)
          {
              r=findthewiinner(n-1,x,y,0,dp);
          }
          if(n-x>=0) 
          {
              r=r| findthewiinner(n-x,x,y,0,dp);
          }
          if(n-y>=0) r=r| findthewiinner(n-y,x,y,0,dp);
          
          return dp[n][geek]=r;
      }
      if(geek==0)
      {
          int r=0;
          if(n-1>=0)
          {
              r=findthewiinner(n-1,x,y,1,dp);
          }
          if(n-x>=0) 
          {
              r=r & findthewiinner(n-x,x,y,1,dp);
          }
          if(n-y>=0) r=r & findthewiinner(n-y,x,y,1,dp);
          
          return dp[n][geek]=r;
      }
      
      
      
      
  }
    int findWinner(int n, int x, int y) {
        // code here
         vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return findthewiinner(n,x,y,1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends