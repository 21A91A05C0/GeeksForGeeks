//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        // int ans=0;
        long long  i=0;
        long long  summ=0;
        long long  ans=0;
        while(i<n)
        {
            if(arr[i]<=k)
            {
                summ+=arr[i];
                
            }
            else
            {
                ans=max(summ,ans);
                summ=0;
            }
            i++;
            
        }
        ans=max(summ,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends