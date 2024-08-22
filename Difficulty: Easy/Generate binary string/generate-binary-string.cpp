//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	void findallthestrings(string s,vector<string>&ans,int n,int i)
	{
	    if(i>=n) 
	    {
	        ans.push_back(s);
	        return ;
	    }
	    if(s[i]=='?')
	    {
	        s[i]='0';
	        findallthestrings(s,ans,n,i+1);
	        s[i]='1';
	        findallthestrings(s,ans,n,i+1);
	    }
	    else
	    {
	        findallthestrings(s,ans,n,i+1);
	    }
	}
		vector<string> generate_binary_string(string s)
		{
		    // Code here
		    vector<string>ans;
		    findallthestrings(s,ans,s.size(),0);
		    return ans;
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends