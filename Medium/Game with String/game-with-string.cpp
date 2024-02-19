//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int ans=0;
        map<char,int>mpp;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }
        priority_queue<int>pq;
        for(auto it:mpp)
        {
            pq.push(it.second);
        }
        while(k--)
        {
            int h=pq.top();
            h--;
            pq.pop();
            pq.push(h);
        }
        while(!pq.empty())
        {
            //cout<<pq.top()<<" ";
            int l=pq.top();
            ans+=pow(l,2);
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends