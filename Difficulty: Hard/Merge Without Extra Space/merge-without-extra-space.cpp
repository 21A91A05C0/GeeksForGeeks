//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            vector<int>brr;
            int i=0,j=0;
            while(i<n && j<m)
            {
                if(arr1[i]<arr2[j])
                {
                    brr.push_back(arr1[i]);
                    i++;
                }
                else
                {
                    brr.push_back(arr2[j]);
                    j++;
                }
            }
            while(i<n)
            {
                brr.push_back(arr1[i]);
                    i++;
            }
            while(j<m)
            {
                brr.push_back(arr2[j]);
                    j++;
            }
            int k=0;
            for(int i=0;i<n;i++)
            {
                arr1[i]=brr[k++];
            }
            for(int i=0;i<m;i++)
            {
                arr2[i]=brr[k++];
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends