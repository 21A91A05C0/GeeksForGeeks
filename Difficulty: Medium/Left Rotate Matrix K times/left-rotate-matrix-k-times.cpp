//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void funtoreverse(vector<int>&arr,int k)
  {
      reverse(arr.begin(),arr.end());
       reverse(arr.begin(),arr.end()-k);
       reverse(arr.begin()+arr.size()-k,arr.end());
  }
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int n=mat[0].size();
        while(k>n)
        {
            k=k-n;
        }
        // cout<<k<<" ";
        vector<vector<int>>ans;
        for(int i=0;i<mat.size();i++)
        {
            vector<int>arr;
            for(int j=0;j<n;j++)
            {
                arr.push_back(mat[i][j]);
            }
            funtoreverse(arr,k);
            ans.push_back(arr);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends