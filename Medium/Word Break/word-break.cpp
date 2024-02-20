//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
int find(string &k,vector<string>&dict)
{
    for(int i=0;i<dict.size();i++)
    {
        if(dict[i]==k)
        {
           // cout<<k<<" ";
            return 1;
        }
        
        
    }
    return 0;
}
int findifcanwebreak(string s,int n,vector<string>&dic,int i,string &k)
{
    if(i==n)
    {
      // cout<<k<<" ";
        if(find(k,dic)==1) 
        {
           // cout<<k<<" ";
            return 1;
        }
       // cout<<"hi"<<" ";
        return 0;
    }
    k+=s[i];
    //cout<<k<<" ";
    int notpick=0;
    int other=0;
    if(find(k,dic)==1)
    {
        string q="";
        notpick=findifcanwebreak(s,n,dic,i+1,q);
    }
    other=findifcanwebreak(s,n,dic,i+1,k);
    
    return other || notpick;
}
    int wordBreak(int n, string s, vector<string> &dictionary) 
    {
        //code here
        string k="";
        int m=s.size();
        return findifcanwebreak(s,m,dictionary,0,k);
        //return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends