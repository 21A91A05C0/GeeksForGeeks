//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int thecountofsequences(int m,int n,int i,int prev)
{
    if(i==n && prev<=m) return 1;
    if(prev>m) return 0;
    if(i>n) return 0;
    int pick=0;
    int notpick=0;
    
    for(int j=prev*2;j<=m;j++)
    {
        pick+=thecountofsequences(m,n,i+1,j);
        //notpick+=thecountofsequences(m,n,i,j+1);
    }
    return pick+notpick;
}
    int numberSequence(int m, int n)
    {
        // code here
        int c=0;
        for(int i=1;i<=m;i++)
        {
            c+=thecountofsequences(m,n,1,i);
        }
        return c;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends