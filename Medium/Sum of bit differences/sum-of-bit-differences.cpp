//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
// long long findthebitdiff(long long  c,long long  v)
// {
//     long long  q=0;
//     for(int i=0;i<32;i++)
//     {
//         long long  k=c&(1<<i);
//         long long  o=v&(1<<i);
//         if(k!=o) q++;
//     }
//     return q;
// }
	long long sumBitDifferences(int arr[], int n)
	{
	    // code here
	    long long ans=0;
	    for(int i=31;i>=0;i--)
	    {
	        long long one=0;
	        long long zero=0;
	        for(int j=0;j<n;j++)
	        {
	            if((arr[j]&(1<<i))==0) zero++;
	            else one++;
	        }
	       // cout<<zero<<" "<<one<<endl;
	        ans+=(one*zero*2);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends