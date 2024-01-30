//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // 15 11 17
//tsututssuususut ttuusuuttss sutsuutttususuttt
int findthelongestcommonsubse(string a,string b,string c,int n1,int n2,int n3,int i,int j,int k,vector<vector<vector<int>>>&dp)
{
    if(i>=n1 || j>=n2 || k>=n3) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    int pick=0;
    int notpick=0;
    if(a[i]==b[j] && b[j]==c[k])
    {
        pick+=1+findthelongestcommonsubse(a,b,c,n1,n2,n3,i+1,j+1,k+1,dp);
    }
    else
    {
        notpick+=max(findthelongestcommonsubse(a,b,c,n1,n2,n3,i+1,j,k,dp),max(findthelongestcommonsubse(a,b,c,n1,n2,n3,i,j+1,k,dp),
        findthelongestcommonsubse(a,b,c,n1,n2,n3,i,j,k+1,dp)));
    }
    return dp[i][j][k]=max(pick,notpick);
}
        
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            vector<vector<vector<int>>>dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
            return findthelongestcommonsubse(A,B,C,n1,n2,n3,0,0,0,dp);
            
        }
};



//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends