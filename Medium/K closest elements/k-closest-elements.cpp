//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector<int>ans;
        int l=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        int i=0;
        int j=0;
        // cout<<l<<" ";
        if(l==0)
        {
            i=-1;
            if(arr[l]==x)
            {
                j=l+1;
            }
            else j=l;
        }
        else if(l>=arr.size())
        {
            if(arr[arr.size()-1]==x)
            {
                i=arr.size()-2;
            }
            else i=arr.size()-1;
            j=arr.size()+2;
        }
        else
        {
            if(arr[l-1]==x)
            {
                i=l-2;
                j=l;
            }
            else
            {
                i=l-1;
                j=l;
            }
        }
        
        while(i>=0 && j<arr.size())
        {
            int diffj=abs(arr[j]-x);
            int diffi=abs(arr[i]-x);
            if(diffj<diffi)
            {
                ans.push_back(arr[j]);
                j++;
            }
            else if(diffi<diffj)
            {
                ans.push_back(arr[i]);
                i--;
            }
            else
            {
                if(arr[j]>arr[i])
                {
                    ans.push_back(arr[j]);
                    j++;
                }
                else
                {
                    ans.push_back(arr[i]);
                    i--;
                    
                }
            }
            if(ans.size()==k) return ans;
        }
        while(j<arr.size())
        {
            ans.push_back(arr[j]);
            j++;
            if(ans.size()==k) return ans;
        }
        while(i>=0)
        {
            ans.push_back(arr[i]);
            i--;
            if(ans.size()==k) return ans;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends