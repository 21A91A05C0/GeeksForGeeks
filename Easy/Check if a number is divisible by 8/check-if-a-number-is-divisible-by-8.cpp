//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s)
    {
        //code here
        string k="";
       // int n=stoi(s);
        if(s.size()<3)
        {
            int n=stoi(s);
            if(n%8==0) return 1;
            else return -1;
        }
        else
        {
            string ans="";
            for(int i=s.size()-1;i>=s.size()-3;i--)
            {
                ans=ans+s[i];
            }
            //cout<<ans;
            reverse(ans.begin(),ans.end());
            int h=stoi(ans);
            if(h%8==0) return 1;
            return -1;
            return 0;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends