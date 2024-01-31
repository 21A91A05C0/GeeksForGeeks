//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
   
    void findtheallpossibleways(vector<string>&ans,string &s,vector<vector<int>>&m,int n,int i,int j,vector<vector<int>>&vis)
    {
        if(i>=n || j>=n || i<0 || j<0 || m[i][j]!=1 || vis[i][j]!=0)
        {
            return ;
        }
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            return ;
        }
        
            s+="L";
            vis[i][j]=1;
            findtheallpossibleways(ans,s,m,n,i,j-1,vis);
            s.pop_back();
            vis[i][j]=0;
     
            s+="U";
            vis[i][j]=1;
            findtheallpossibleways(ans,s,m,n,i-1,j,vis);
            s.pop_back();
            vis[i][j]=0;
        
            s+="D";
            vis[i][j]=1;
            findtheallpossibleways(ans,s,m,n,i+1,j,vis);
             s.pop_back();
            vis[i][j]=0;
     
             s+="R";
            vis[i][j]=1;
            findtheallpossibleways(ans,s,m,n,i,j+1,vis);
            s.pop_back();
            vis[i][j]=0;
        //return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        // Your code goes here
        
        vector<vector<int>>vis(n+1,vector<int>(n+1,0));
        string s="";
        findtheallpossibleways(ans,s,m,n,0,0,vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends