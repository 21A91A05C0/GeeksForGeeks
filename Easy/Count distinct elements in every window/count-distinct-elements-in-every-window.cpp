//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
//   14 5
// 78 16 94 36 87 93 50 22 63 28 91 60 64 27
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<k;i++)
        {
            mpp[A[i]]++;
        }
        ans.push_back(mpp.size());
        // for(auto it:mpp)
        //     {
        //         cout<<it.first<<" "<<it.second<<endl;
        //     }
        int j=0;
        int c=0;
        for(int i=k;i<n;i++)
        {
            mpp[A[j]]--;
            mpp[A[i]]++;
            // for(auto it:mpp)
            // {
            //     cout<<it.first<<" "<<it.second<<endl;
            // }
            
            if(mpp[A[j]]<=0) 
            {
               // cout<<"hi"<<" ";
                mpp.erase(A[j]);
            }
            ans.push_back(mpp.size());
            j++;
        }
        //cout<<endl;
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends