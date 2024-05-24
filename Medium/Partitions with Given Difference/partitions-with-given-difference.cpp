//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
  int findthepartitions(vector<int>&arr,int i,int target,int n,int summ,vector<vector<int>>&dp)
  {
      if(i>=n)
      {
          if(summ==target) return 1;
          return 0;
      }
      if(dp[i][summ]!=-1) return dp[i][summ];
      int pick=0;
      int notpick=0;
      if((arr[i]+summ)<=target)
      {
          pick=findthepartitions(arr,i+1,target,n,summ+arr[i],dp);
      }
      notpick=findthepartitions(arr,i+1,target,n,summ,dp);
      return dp[i][summ]=(pick+notpick)%mod;
  }
    int countPartitions(int n, int d, vector<int>& arr) 
    {
        int total=accumulate(arr.begin(),arr.end(),0);
        double t=(double)(total-d)/2.0;
        // cout<<t;
        if(t!=(int)t) return 0;
        vector<vector<int>>dp(n+1,vector<int>(total+1,-1));
          return findthepartitions(arr,0,(int)t,arr.size(),0,dp);
        // return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends