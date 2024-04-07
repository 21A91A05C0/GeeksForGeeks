//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int themaxdotprodut(int a[],int b[],int n,int m,int i,int j,vector<vector<int>>&dp)
	{
	    if(i>=n && j<m) return -1e9;
	    if(i>=n ||j>=m) return 0;
	    if(dp[i][j]!=-1) return dp[i][j];
	    int pick=0;
	    int notpick=0;
	    pick=a[i]*b[j]+themaxdotprodut(a,b,n,m,i+1,j+1,dp);
	    notpick=themaxdotprodut(a,b,n,m,i+1,j,dp);
	    return dp[i][j]=max(pick,notpick);
	    
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		int zero=0;
		zero=n-m;
		vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
		return themaxdotprodut(a,b,n,m,0,0,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends