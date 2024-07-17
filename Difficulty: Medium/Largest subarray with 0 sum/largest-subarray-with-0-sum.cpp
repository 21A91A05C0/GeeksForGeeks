//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        map<int,int>mpp;
        int ans=0;
        int s=0;
        // mpp[0]=0;
        for(int i=0;i<arr.size();i++)
        {
            s+=arr[i];
            // cout<<s<<" ";
            if(s==0) ans=max(ans,i+1);
            // if(s<0) s=0;
            if(mpp.find(s)!=mpp.end())
            {
                ans=max(ans,i-mpp[s]);
            }
            else
            mpp[s]=i;
        }
        if(s==0) return n;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends