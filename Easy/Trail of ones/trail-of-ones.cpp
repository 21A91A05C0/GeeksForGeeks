//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  long long mod=1e9+7;
  long long power(long long base,long long exp)
  {
      long long  res=1;
      while(exp>0)
      {
          if(exp&1)
          {
              res=(res%mod*base%mod)%mod;
          }
          base=(base%mod*base%mod)%mod;
          exp/=2;
      }
      return res%mod;
  }
  long long findthenumberofnoncon(long long n,long long prev,long long i,vector<vector<long long>>&dp)
  {
      if(i>=n) return 1;
      long long pick=0;
      long long notpick=0;
      if(dp[i][prev]!=-1) return dp[i][prev];
      if(prev==0)
      {
          pick=findthenumberofnoncon(n,1,i+1,dp);
      }
      notpick=findthenumberofnoncon(n,0,i+1,dp);
      return dp[i][prev]=(pick%mod+notpick%mod)%mod;
      
      
  }
    int numberOfConsecutiveOnes(int n) {
        // code here
        string s="";
        vector<vector<long long>>dp(n+1,vector<long long>(3,-1));
        long long k=findthenumberofnoncon(n,0,0,dp);
        long long o=power(2,n)%mod;
        return (o-k+mod)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends