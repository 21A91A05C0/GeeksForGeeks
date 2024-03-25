//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
void findthebinarystring(int size,string k,vector<string>&ans,int one,int zero)
{
    if(k.size()==size)
    {
        ans.push_back(k);
       // k="";
        return ;
    }
    if(one>=zero) 
    {
        k+='1';
        findthebinarystring(size,k,ans,one+1,zero);
        k.pop_back();
    }
    if(zero<one)
    {
        k+='0';
        findthebinarystring(size,k,ans,one,zero+1);
        k.pop_back();
    }
    
    
   //return ;
}
	vector<string> NBitBinary(int n)
	{
	    vector<string>ans;
	    string s="";
	    int one=0;
	    int zero=0;
	    findthebinarystring(n,s,ans,one,zero);
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends