//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        map<char,int>mpp;
        for(int i=0;i<str.size();i++) mpp[str[i]]++;
        string ans="";
        for(int i=0;i<str.size();i++)
        {
            if(mpp[str[i]]==-1) continue;
            else
            {
                ans+=str[i];
                mpp[str[i]]=-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends