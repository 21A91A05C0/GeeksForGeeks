//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        int dp[100006][2][2];
       int themaximumprofit(vector<int>&prices,int buy,int n,int i,int c)
       {
           if(i>=n) return 0;
           if(c==2)
            {
                return 0;
            }
           if(i==n-1)
           {
              if(buy==1) return prices[i];
              return 0;
           }
            
           if(dp[i][buy][c]!=-1) return dp[i][buy][c];
        //   long long mxx=0;
           int pick=0;
           int notpick=0;
           if(buy==0)
           {
               pick=-prices[i]+themaximumprofit(prices,1,n,i+1,c);
               //notpick=themaximumprofit(prices,0,n,i+1,c,dp);
           }
           else
           {
               pick=prices[i]+themaximumprofit(prices,0,n,i+1,c+1);
              
           }
           notpick=themaximumprofit(prices,buy,n,i+1,c);
           return dp[i][buy][c]=max(pick,notpick);
           
           
       }
        int maxProfit(vector<int>&price)
        {
            //Write your code here..
            int n=price.size();
            memset(dp,-1,sizeof(dp));
            // vector<vector<int>>dp(n+1,vector<int>(3,-1));
            // vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(3,vector<long long>(3,-1)));
            int  buy=0;
            int c=0;
            int last=0;
            return themaximumprofit(price,buy,n,0,c);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends