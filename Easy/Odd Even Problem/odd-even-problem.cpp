//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) 
    {
        // code here
        map<char,int>odd;
        map<char,int>even;
        map<char,int>all;
        for(int i=0;i<s.size();i++)
        {
            if(((s[i]))%2==0)
            {
                even[s[i]]++;
            }
            else odd[s[i]]++;
            all[s[i]]++;
        }
        int o=0;
        int e=0;
        for(auto it:even)
        {
            if(it.second%2==0 ) e++;
        }
        for(auto it:odd)
        {
            if(it.second%2!=0 ) o++;
        }
        if((o+e)%2==0) return "EVEN";
        return "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends