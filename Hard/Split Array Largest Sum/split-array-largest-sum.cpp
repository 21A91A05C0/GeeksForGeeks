//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int findtheminimumpossible(int arr[],int n,int maxsum,int k)
  {
      int presum=0;
      int ans=1;
      for(int i=0;i<n;i++)
      {
          if(arr[i]+presum<=maxsum)
          {
              presum+=arr[i];
          }
          else 
          {
              ans++;
              presum=arr[i];
          }
          
      }
      return ans;
  }
    int splitArray(int arr[] ,int N, int K) 
    {
        // code here
        int low=*max_element(arr,arr+N);
        int x=low;
        int high=accumulate(arr,arr+N,0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            int c=findtheminimumpossible(arr,N,mid,K);
            if(c==K)
            {
                high=mid-1;
                
            }
            else if(c>K)
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends