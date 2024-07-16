//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int theminimumcoinsrequired(vector<int>&coins,int n,int target,int pres,int i,vector<vector<int>>&dp)
	{
	    if(i>=n)
	    {
	        if(pres==target)
	        {
	            return 0;
	        }
	        return 1e9;
	    }
	    if(dp[i][pres]!=-1) return dp[i][pres];
	    int pick=1e9,notpick=1e9;
	    if(pres+coins[i]<=target)
	    {
	        pick=1+theminimumcoinsrequired(coins,n,target,pres+coins[i],i,dp);
	    }
	    notpick=theminimumcoinsrequired(coins,n,target,pres,i+1,dp);
	    return dp[i][pres]=min(pick,notpick);
	}
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M,vector<int>(V+1,-1));
	    int k=theminimumcoinsrequired(coins,M,V,0,0,dp);
	    if(k==1e9) return -1;
	    return k;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends