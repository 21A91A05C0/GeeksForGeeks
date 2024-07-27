//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
//   int fun(string s1,string s2,int n,int i,int j,vector<vector<int>>&dp)
//   {
//       if(i>=n || j>=n) return 0;
//       int pick=0,notpick=0;
//       if(dp[i][j]!=-1) return dp[i][j];
//       if(s1[i]==s2[j])
//       {
//           pick=1+fun(s1,s2,n,i+1,j+1,dp);
//       }
//       notpick=max(fun(s1,s2,n,i+1,j,dp),fun(s1,s2,n,i,j+1,dp));
//       return dp[i][j]=max(pick,notpick);
//   }
    int countMin(string s){
        //complete the function here
        string k=s;
        reverse(k.begin(),k.end());
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==k[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int l=dp[n][n];
        // cout<<l;
        return n-l;
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends