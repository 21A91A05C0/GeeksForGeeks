//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int i,int j,string  &s1,string &s2,vector<vector<int>> &dp)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        int x=0;
        if(s1[i]==s2[j])
        {
             x+=0+fun(i-1,j-1,s1,s2,dp);
        }
        else
        {
            x+=1+min(fun(i-1,j,s1,s2,dp),min(fun(i,j-1,s1,s2,dp),fun(i-1,j-1,s1,s2,dp)));
        }
        return dp[i][j]=x;
    }
    int editDistance(string s1, string s2) 
    {
        // Code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int>prev(m+1,0);
        vector<int>cur(m+1,0);
        
        for(int j=0;j<=m;j++)
        {
            prev[j]=j;
        }
        int x=0;
        for(int i=1;i<=n;i++)
        {
            cur[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                     x=0+prev[j-1];
                }
                else
                {
                    x=1+min(prev[j],min(cur[j-1],prev[j-1]));
                }
                cur[j]=x;
                
            }
            prev=cur;
        }
        return prev[m];
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends