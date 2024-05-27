//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  int findthelongestsub(int n,vector<int>&arr,int prev,int i)
  {
      if(i>=n) return 0;
      int pick=0;
      int notpick=0;
      if(prev==-1 || abs(arr[i]-prev)==1)
      {
          pick=1+findthelongestsub(n,arr,arr[i],i+1);
      }
       notpick=findthelongestsub(n,arr,prev,i+1);
      return max(pick,notpick);
  }
    int longestSubseq(int n, vector<int> &a) 
    {
        // code here
        
        return findthelongestsub(n,a,-1,0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends