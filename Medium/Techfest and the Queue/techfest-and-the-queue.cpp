//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
int findtheprimefactrossum(int n)
{
    
    int c=0;
    while(n%2==0)
    {
        c++;
        n=n/2;
    }
    int p=3;
    int k=(int)sqrt(n);
    while(n>1 && p<=k)
    {
        if(n%p==0 )
        {
            c++;
            n=n/p;
        }
        else 
        p+=2;
    }
    if(n>2) c++;
    return c;
    
}
	int sumOfPowers(int a, int b)
	{
	    // Code here
	    long long ans=0;
	    for(int i=a;i<=b;i++)
	    {
	        ans+=findtheprimefactrossum(i);
	    }
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