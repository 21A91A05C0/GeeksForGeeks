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
void generateseive(vector<bool>&seive)
{
    seive[0]=0;
    seive[1]=0;
    for(int i=2;i*i<seive.size();i++)
    {
        if(seive[i]==1)
        {
            for(int j=i*i;j<seive.size();j+=i)
            {
                seive[j]=0;
            }
        }
    }
}
 
    vector<int> getPrimes(int n) {
        // code here
        vector<int>ans;
        vector<bool>primes(n+1,1);
        generateseive(primes);
        // for(int i=2;i<=n;i++)
        // {
        //     if(isprime(i)==1)
        //     {
        //         primes.push_back(i);
        //     }
        // }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<primes[i]<<" "<<i<<endl;
        // }
        for(int i=0;i<=(n/2);i++) 
        {
            if(primes[i]==1 && primes[n-i]==1 )
            {
                ans.push_back(i);
                ans.push_back(n-i);
                return ans;
            }
        }
        if(ans.size()==0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
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

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends