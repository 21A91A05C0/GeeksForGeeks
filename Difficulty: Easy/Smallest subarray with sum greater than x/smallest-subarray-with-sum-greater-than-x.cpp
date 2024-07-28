//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int ans=INT_MAX;
        int i=0,j=0;
        int s=0;
        while(j<arr.size())
        {
            s+=arr[j];
            // if(s==x)
            while(s>x)
            {
                ans=min(ans,j-i+1);
                s=s-arr[i];
                i++;
            }
            j++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        vector<int> arr;
        int x;

        cin >> x;
        cin.ignore(); // Ignore the newline character after x

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.smallestSubWithSum(x, arr) << endl;
    }

    return 0;
}
// } Driver Code Ends