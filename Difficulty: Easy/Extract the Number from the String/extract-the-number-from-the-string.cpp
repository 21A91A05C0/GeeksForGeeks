//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        string ans="";
        long long  a=0;
        for(long long i=0;i<sentence.size();i++)
        {
            if((sentence[i])>='0' && (sentence[i])<='8')
            {
                ans+=sentence[i];
            }
            else
            {
               if(ans.size()>0) a=max(a,stoll(ans));
                ans="";
            }
        }
        if(a==0) return -1;
        return a;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends