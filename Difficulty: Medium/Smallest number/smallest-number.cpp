//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    string smallestNumber(int s, int d) {
        // code here
        if(s>9 && d==1) return "-1";
        if(d==1 && s<=9) return to_string(s);
        int g=s;
        vector<int>ans(d,0);
        for(int i=d-1;i>=0;i--)
        {
            if(s>9)
            {
                ans[i]=9;
                s=s-9;
            }
            else
            {
                ans[i]=s;
                s=0;
            }
        }
        if(ans[0]==0)
        {
            for(int i=0;i<d;i++)
            {
                if(ans[i]!=0)
                {
                    ans[i]--;
                    ans[0]=1;
                    break;
                }
            }
        }
        string a="";
        int k=0;
        for(int i=0;i<ans.size();i++)
        {
            // cout<<ans[i]<<" ";
            k+=ans[i];
            if(ans[i]==0)
            {
                a+='0';
            }
            else   a+=to_string(ans[i]);
        }
        // cout<<k<<" ";
        // while(a.size()!=d)
        // {
        //     s+='0';
        // }
        // cout<<a<<" ";
        if(k!=g) return "-1";
        return a;
        
        
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
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends