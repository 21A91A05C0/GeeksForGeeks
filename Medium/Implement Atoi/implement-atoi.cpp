//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int c=0;
        for(int i=0;i<s.size();i++)
        {
            //cout<<s[i]<<" ";
            if(s[i]=='-' && i!=0) return -1;
            if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]
            =='9' || s[i]=='0' || s[i]=='-') 
            {
                // 
                continue;
            }
            else return -1;
        }
       // return c;
        string b="";
        int minus=0;
        if(s[0]=='-')
        {
            minus=1;
            for(int i=1;i<s.size();i++)
            {
                b+=s[i];
            }
        }
        else
        {
            for(int i=0;i<s.size();i++)
            {
                b+=s[i];
            }
        }
        int n=stoi(b);
        if(minus==1) n*=-1;
        return n;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends