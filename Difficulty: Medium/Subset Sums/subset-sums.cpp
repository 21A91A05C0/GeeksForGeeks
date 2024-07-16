//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void thearrayofsumsubsts(vector<int>&arr,int n,int i,vector<int>&ans,int summ)
  {
      if(i>=n)
      {
          ans.push_back(summ);
          return ;
      }
      thearrayofsumsubsts(arr,n,i+1,ans,summ+arr[i]);
      thearrayofsumsubsts(arr,n,i+1,ans,summ);
      
  }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int>ans;
        thearrayofsumsubsts(arr,n,0,ans,0);
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
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends