//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
void findthedivisors(int val,vector<int>&seive,int maxx)
{
    if(seive[val]<2)
    {
        for(int j=val;j<=maxx;j+=val)
        {
            seive[j]++;
            
        }
    }
    
}
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        int m=*max_element(arr.begin(),arr.end());
        vector<int>seive(m+1,0);
        for(int i=0;i<N;i++)
        {
            findthedivisors(arr[i],seive,m);
        }
        int ans=0;
        for(int i=0;i<N;i++)
        {
            if(seive[arr[i]]>1) 
            {
                //cout<<seive[arr[i]]<<" ";
                ans++;
            }
        }
        return ans;
      
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends