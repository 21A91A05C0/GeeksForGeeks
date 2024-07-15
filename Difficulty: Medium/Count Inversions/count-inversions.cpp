//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long arr[],long long  low,long long  mid,long long  high)
    {
        long long int p=0;
        vector<long long >brr;
        long long  i=low,j=mid+1;
        while(i<=mid && j<=high)
        {
            if(arr[i]<=arr[j])
            {
                brr.push_back(arr[i++]);
                
            }
            else
            {
                p+=(mid-i+1);
                brr.push_back(arr[j++]);
            }
        }
        while(i<=mid)
        {
            brr.push_back(arr[i++]);
           
        }
        while(j<=high)
        {
            brr.push_back(arr[j++]);
        }
        for(int u=0;u<brr.size();u++)
        {
            arr[low++]=brr[u];
        }
        return p;
    }
    long long int mergesort(long long arr[],int low,int high)
    {
        long long int c=0;
        if(low>=high) return 0;
        long long  mid=(low+high)/2;
        c+=mergesort(arr,low,mid);
        c+=mergesort(arr,mid+1,high);
        c+=merge(arr,low,mid,high);
        return c;
        
    }
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        return mergesort(arr,0,n-1);
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends