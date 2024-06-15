//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  long long thepossiblenumber(vector<vector<int>>&mat,int i,int j,int len,vector<vector<vector<long long>>>&dp)
  {
      if(len==0) return 1;
      int row[5]={-1,0,+1,0,0};
      int col[5]={0,+1,0,-1,0};
      long long pick=0;
      if(dp[i][j][len]!=-1) return dp[i][j][len];
      for(int r=0;r<5;r++)
      {
          int newrow=i+row[r];
          int newcol=j+col[r];
          if(newrow>=0 && newcol>=0 && newrow<mat.size() && newcol<mat[0].size() && mat[newrow][newcol]!=-1)
          {
              pick+=thepossiblenumber(mat,newrow,newcol,len-1,dp);
          }
        //   pick+=thepossiblenumber(mat,i,j,len-1);
      }
      return dp[i][j][len]=pick;
  }
    long long getCount(int n) {
        // Your code goes here
        if(n==1) 
        {
            return 10;
        }
        int k=1;
        vector<vector<int>>mat(4,vector<int>(3,0));
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                mat[i][j]=k;
                k++;
            }
        }
        mat[3][0]=-1;
        mat[3][1]=0;
        mat[3][2]=-1;
        long long ans=0;
        vector<vector<vector<long long>>>dp(15,vector<vector<long long>>(15,vector<long long>(n+1,-1)));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]!=-1)
                {
                    ans+=thepossiblenumber(mat,i,j,n-1,dp);
                }
                
            }
        }
        return ans;
        // return 0;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends