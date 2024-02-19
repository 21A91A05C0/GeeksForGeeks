//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void dfs(vector<vector<int>>&image,int i,int j,int color,int prev,vector<vector<int>>&vis)
{
    // vis[i][j]=1;
    int n=image.size();
    int m=image[0].size();
    if(i<0 || j<0 || i>=n || j>=m) return;
    if(!vis[i][j] && image[i][j]==prev)
    {
        image[i][j]=color;
        vis[i][j]=1;
    }
    else return ;
    dfs(image,i-1,j,color,prev,vis);
    dfs(image,i+1,j,color,prev,vis);
    dfs(image,i,j+1,color,prev,vis);
    dfs(image,i,j-1,color,prev,vis);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        // Code here
        int n=image.size();
        int m=image[0].size();
        int prev=image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        dfs(image,sr,sc,newColor,prev,vis);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends