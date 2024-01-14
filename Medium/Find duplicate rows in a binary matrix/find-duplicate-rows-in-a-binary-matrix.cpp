//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    public:
    
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        map<int,int>mpp;
        vector<int>ans;
        for(int i=0;i<matrix.size();i++)
        {
            int a=0;
            int l=0;
            for(int j=matrix[0].size()-1;j>=0;j--)
            {
                if(matrix[i][j]==1) 
                {
                    a+=(2<<l);
                    
                }
                l++;
            }
            if(mpp.find(a)==mpp.end()) mpp[a]=i;
            else ans.push_back(i);
            

        }
        return ans;
      
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends