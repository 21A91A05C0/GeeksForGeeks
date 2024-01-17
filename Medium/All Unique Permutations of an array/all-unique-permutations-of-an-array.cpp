//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void theuniquepermutations(vector<int>&arr,int n,set<vector<int>>&st,vector<int>&vis,vector<int>&present)
  {
      if(present.size()==arr.size()) 
      {
          st.insert(present);
         // present.clear();
          return ;
      }
      for(int i=0;i<arr.size();i++)
      {
          if(vis[i]==0)
          {
              vis[i]=1;
              present.push_back(arr[i]);
              theuniquepermutations(arr,n,st,vis,present);
              present.pop_back();
              vis[i]=0;
              //theuniquepermutations(arr,n,ans,vis,present);
          }
      }
      return;
  }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) 
    {
        // code here
        set<vector<int>>st;
        vector<vector<int>>ans;
        vector<int>vis(n,0);
        vector<int>present;
        theuniquepermutations(arr,n,st,vis,present);
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends