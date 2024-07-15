//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int start[], int end[], int n)
    {
    	// Your code here
    	vector<int>pre(3000,0);
        for(int i=0;i<n;i++)
        {
            pre[start[i]]+=1;
            pre[end[i]+1]-=1;
        }
        int ans=0;
        int s=0;
        for(int  i=0;i<pre.size();i++)
        {
            s=s+pre[i];
            ans=max(ans,s);
        }
        return ans;
    	
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends