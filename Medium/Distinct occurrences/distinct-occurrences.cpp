//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod=1e9+7;
    int thenumberofsub(string s,string t,long long i,long long j,long long n,long long m,string &q,vector<vector<long long>>&dp)
    {
        if(i>=n || j>=m)
        {
            if(q.size()==t.size() && q==t) return 1;
            return 0;
        }
       if(dp[i][j]!=-1) return dp[i][j];
        long long pick=0;
        long long notpick=0;
        if(s[i]==t[j])
        {
            pick=thenumberofsub(s,t,i+1,j+1,n,m,q+=s[i],dp);
            q.pop_back();
        }
        
        ///q.pop_back();
        notpick=thenumberofsub(s,t,i+1,j,n,m,q,dp);
        return dp[i][j]=(pick+notpick)%mod;
    }
    int subsequenceCount(string s, string t)
    {
        //Your code here
        string q="";
        long long  n=s.size();
        long long m=t.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
        return thenumberofsub(s,t,0,0,n,m,q,dp);
      
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends