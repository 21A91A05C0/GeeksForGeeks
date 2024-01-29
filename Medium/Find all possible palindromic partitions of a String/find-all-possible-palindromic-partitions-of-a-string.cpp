//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool ispal(string k)
  {
      string p=k;
      reverse(k.begin(),k.end());
      if(p==k) return 1;
      return 0;
  }
  void findallthesubpalindromicstrings(string s,vector<vector<string>>&ans,int i,int n,vector<string>&brr)
  {
      if(i==n)
      {
          ans.push_back(brr);
         // brr.clear();
          return ;
      }
      for(int j=i;j<n;j++)
      {
          string k=s.substr(i,j-i+1);
          //string h=reverse(k.begin(),k.end());
          if(ispal(k)==1)
          {
              brr.push_back(k);
              findallthesubpalindromicstrings(s,ans,j+1,n,brr);
              brr.pop_back();
          }
          
          
      }
  }
    vector<vector<string>> allPalindromicPerms(string S) 
    {
        // code here
        vector<vector<string>>ans;
        int n=S.size();
        vector<string>brr;
        findallthesubpalindromicstrings(S,ans,0,n,brr);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends