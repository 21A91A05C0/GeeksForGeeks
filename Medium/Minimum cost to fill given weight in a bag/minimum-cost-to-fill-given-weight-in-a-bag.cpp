//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  int theminimumcost(int n,int tar,vector<int>&cost,int i,vector<vector<int>>&dp)
  {
      if(i>n)
      {
         
          if(tar==0)
          {
               
              return 0;
          }
          else
          {
              return 1e9;
          }
      }
      if(dp[i][tar]!=-1) return dp[i][tar];
      int pick=1e9;
      int notpick=1e9;
      if(tar-i>=0 && cost[i-1]!=-1)
      {
        //   cout<<"hi";
          pick=cost[i-1]+theminimumcost(n,tar-i,cost,i,dp);
      }
      notpick=theminimumcost(n,tar,cost,i+1,dp);
      
    //   cout<<pick<<" "<<notpick<<endl;
      return dp[i][tar]=min(pick,notpick);
  }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        int k=theminimumcost(n,w,cost,1,dp);
        if(k==1e9) return -1;
        return k;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends