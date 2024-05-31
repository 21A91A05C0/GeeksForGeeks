//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int  s=0;
        
        for(int i=7;i>=4;i--)
        {
            if((1<<i)&n)
            {
                // cout<<i<<" ";
                s+=pow(2,i-4);
                // cout<<s<<" ";
            }
        }
        // cout<<s<<" ";
        for(int i=3;i>=0;i--)
        {
            // cout<<"hi";
            if((1<<i)&n)
            {
                s+=pow(2,4+i);
            }
            // cout<<s<<" ";
        }
        // cout<<s;
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends