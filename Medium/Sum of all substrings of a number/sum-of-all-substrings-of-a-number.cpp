//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        long long mod=1e9+7;
        long long  n=s.size();
        vector<long long>dp(n+1,0);
        long long ans=0;
        dp[0]=s[0]-'0';
        ans+=dp[0];
        for(long long i=1;i<n;i++)
        {
            long long  a=s[i]-'0';
            long long  k=((i+1)*a+10*(dp[i-1]))%mod;
            ans+=k%mod;
            dp[i]=k;
        }
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends