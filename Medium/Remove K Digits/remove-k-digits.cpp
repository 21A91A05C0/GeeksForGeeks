//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) 
    {
        stack<char>st;
        string ans="";
        int c=K;
        string res="";
        for(int i=0;i<S.size();i++)
        {
            if(st.empty())
            {
                st.push(S[i]);
            }
            else
            {
                while(!st.empty() && st.top()>S[i] && K>0)
                {
                    st.pop();
                    K--;
                }
                st.push(S[i]);
            }
            
        }
        while(K>0)
        {
            st.pop();
            K--;
        }
        while(!st.empty())
        {
            char q=st.top();
            ans+=q;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            if(res.size()==0 && ans[i]=='0') continue;
            else res+=ans[i];
        }
        if(res.size()==0) res+='0';
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends