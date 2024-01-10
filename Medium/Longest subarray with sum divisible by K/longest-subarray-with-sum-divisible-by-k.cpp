//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int>mpp;
	    int sum=0;
	    int maxx=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	        int rem=sum%k;
	        if(rem<0) rem+=k;
	        if(rem==0) maxx=max(i+1,maxx);
	        
	            if(mpp.find(rem)!=mpp.end())
	            {
	                maxx=max(maxx,i-mpp[rem]);
	            }
	            if(mpp.find(rem)==mpp.end())
	            {
	                mpp[rem]=i;
	            }
	        
	    }
	    return maxx;
	    
	   
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends