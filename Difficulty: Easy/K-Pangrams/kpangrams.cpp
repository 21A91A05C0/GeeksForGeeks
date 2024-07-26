//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    //   a     c  a
    bool kPangram(string str, int k) {
        // code here
        map<char,int>mpp;
        int space=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ') space++;
            mpp[str[i]]++;
        }
        if(str.size()-space<26) return 0;
        int l=0;
        for(char c='a';c<='z';c++)
        {
            if(mpp[c]==0)
            {
                k--;
                // mpp[c]++;
            }
        }
        if(k>=0) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends