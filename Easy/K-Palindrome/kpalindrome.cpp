//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
// abcdecba
// abcedcba
int  findthekpalin(string s,string r,int n,int k,int i,int j,vector<vector<int>>&dp)
{
   // cout<<"hi"<<" ";
   if(i>=n || j>=n) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
   int pick=0;
   int notpick=0;
   if(s[i]==r[j])
   {
       pick+=1+findthekpalin(s,r,n,k,i+1,j+1,dp);
   }
   notpick+=max(findthekpalin(s,r,n,k,i+1,j,dp),findthekpalin(s,r,n,k,i,j+1,dp));
   return dp[i][j]=max(pick,notpick);
    
}

    int kPalindrome(string str, int n, int k)
    {
        // code here
        string s=str;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        reverse(str.begin(),str.end());
        // dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==str[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else 
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        // cout<<dp[n][n]<<" ";
        int o=n-dp[n][n];
        if(o<=k) return 1;
        return 0;
        // return g;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends