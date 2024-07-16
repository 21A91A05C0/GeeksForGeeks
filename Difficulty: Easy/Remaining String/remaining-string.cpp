//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        string g="";
        int c=0;
        int i=0;
        for(i=0;i<s.size();i++)
        {
            if(s[i]==ch)
            {
                c++;
            }
            if(c==count) break;
        }
        for(int j=i+1;j<s.size();j++)
        {
            g+=s[j];
        }
        return g;
        
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
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends