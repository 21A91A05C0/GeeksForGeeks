//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  //0011111100
    string binaryNextNumber(string s) {
        // code here.
        int i=s.size()-1;
        char k=s.back();
        if(k=='0')
        {
            s[i]='1';
            i--;
            
        }
        else
        {
            s[i]='0';
            i--;
            int c=0;
            while(s[i]=='1')
            {
                c=1;
                s[i]='0';
                i--;
            }
            if(i<0)
            {
                s='1'+s;
            }
            else
            {
                s[i]='1';
            }
        }
        //  return s;
        string ans="";
        int j=0;
        while(s[j]!='1')
        {
            j++;
        }
        // cout<<j<<" ";
        for(int o=j;o<s.size();o++)
        {
            ans=ans+s[o];
        }
        return ans;
            
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends