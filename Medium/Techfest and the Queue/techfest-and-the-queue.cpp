//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
void evaluateseive(vector<int>&seive,int b)
{
    seive[0]=0;
    seive[1]=1;
    for(int i=0;i<=b;i++) seive[i]=i;
    for(int i=2;i*i<=b+1;i++)
    {
        if(seive[i]==i)
        {
            for(int j=i*i;j<=b+1;j+=i)
            {
                if(seive[j]==j)
                seive[j]=i;
            }
        }
    }
}
	int sumOfPowers(int a, int b)
	{
	    // Code here
	    vector<int>seive(b+1,1);
	    evaluateseive(seive,b);
	    int ans=0;
	    for(int i=a;i<=b;i++)
	    {
	        int s=0;
	        int m=i;
	        while(m>1)
	        {
	            int p=seive[m];
	            //cout<<"hi";
	            s++;
	            m/=p;
	        }
	      //  cout<<s<<" ";
	        ans+=s;
	    }
	   // for(auto it:mpp)
	   // {
	   //     cout<<it.second<<" ";
	   // }
	    return ans;
	}
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends