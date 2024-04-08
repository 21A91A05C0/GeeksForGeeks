//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long findthemaximumsum(int arr[],int i,int j,int me,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        long long left=0;
        long long right=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(me==0)
        {
            left=arr[i]+findthemaximumsum(arr,i+1,j,1,dp);
            
        }
        else
        {
            left=min(findthemaximumsum(arr,i+1,j,0,dp),findthemaximumsum(arr,i,j-1,0,dp));
            
        }
        if(me==0)
        {
            right=arr[j]+findthemaximumsum(arr,i,j-1,1,dp);
        }
        else
        {
           
            left=min(findthemaximumsum(arr,i+1,j,0,dp),findthemaximumsum(arr,i,j-1,0,dp));
            
        }
        
        return dp[i][j]=max(left,right);
        
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        int me=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return findthemaximumsum(arr,0,n-1,me,dp);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends