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
    void zigZag(int n, vector<int> &arr) {
        // code here
        // 4 3 7 8 6 2 1
        //1 2 3 4 6 7 8 
        // 1< 8> 2< 7> 3< 6> 4
        // 3 7 4 8 2 6 1
        for(int i=0;i<n-1;i++){
            if((i%2==0 && arr[i]>arr[i+1]) || (i%2!=0 && arr[i]<arr[i+1])){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
};


//{ Driver Code Starts.

bool isZigzag(int n, vector<int> &arr) {
    int f = 1;

    for (int i = 1; i < n; i++) {
        if (f) {
            if (arr[i - 1] > arr[i])
                return 0;
        } else {
            if (arr[i - 1] < arr[i])
                return 0;
        }
        f = f ^ 1;
    }

    return 1;
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        //
        obj.zigZag(n, arr);
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == i % 2) {
                flag = 0;
            } else {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << "0\n";
        } else {
            bool check = 1;
            check = isZigzag(n, arr);
            if (check)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}

// } Driver Code Ends