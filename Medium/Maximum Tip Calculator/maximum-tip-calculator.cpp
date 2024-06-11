//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) 
    {
        // code here
       priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        {
            long long k=abs(arr[i]-brr[i]);
            pq.push({k,i});
        }
        long long ans=0;
        while(!pq.empty())
        {
            int l=pq.top().second;
            pq.pop();
            if(arr[l]>brr[l])
            {
                if(x>0)
                {
                    ans+=arr[l];
                    x--;
                }
                else if(y>0)
                {
                    ans+=brr[l];
                    y--;
                }
            }
            else
            {
                if(y>0)
                {
                    ans+=brr[l];
                    y--;
                }
                else if(x>0)
                {
                    ans+=arr[l];
                    x--;
                }
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends