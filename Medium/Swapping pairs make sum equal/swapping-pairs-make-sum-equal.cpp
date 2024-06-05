//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int ans=0;
        int s1=0;
        map<int,int>mpp1;
        int s2=0;
        map<int,int>cpp;
        for(int i=0;i<n;i++)
        {
            mpp1[a[i]]++;
            s1+=a[i];
        }
        for(int i=0;i<m;i++)
        {
            cpp[b[i]]++;
            s2+=b[i];
        }
        for(auto it:mpp1)
        {
            
            for(auto tt:cpp)
            {
                int k=s1-it.first;
                int c=s2+it.first;
                k=k+tt.first;
                c-=tt.first;
                //  cout<<k<<" "<<c<<endl;
                if(k==c) return 1;
            }
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends