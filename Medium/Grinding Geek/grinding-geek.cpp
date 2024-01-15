//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int themaxumumcourses(int n,int total,vector<int>&cost,int i,vector<vector<int>>&dp)
    {
        if(i>=n) return 0;
        if(dp[i][total]!=-1) return dp[i][total];
        int pick=0;
        int notpick=0;
        if(cost[i]<=total)
        {
            //total=((int)(90*cost[i])/100);
            
            pick+=1+themaxumumcourses(n,total-cost[i]+((int)(90*cost[i])/100),cost,i+1,dp);
        }
        notpick+=themaxumumcourses(n,total,cost,i+1,dp);
        return dp[i][total]=max(pick,notpick);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        // vector<int>dp(n+1,-1);
        //int s=accumulate(cost.begin(),cost.end(),0);
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        return themaxumumcourses(n,total,cost,0,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends