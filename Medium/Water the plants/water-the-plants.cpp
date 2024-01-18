//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        int ans=0;
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++)
        {
            int k=i+gallery[i];
            int r=min(n-1,k);
            int l=max(0,i-gallery[i]);
            for(int j=l;j<=r;j++)
            {
                vis[j]=max(vis[j],r);
                //cout<<vis[j]<<" ";
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<vis[i]<<" ";
        // }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1) return -1;
        }
        int i=0;
        while(i<n)
        {
            ans++;
            //if(vis[i]==-1) return -1;
            i=vis[i]+1;
            
            
        }
        return ans;
        
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
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends