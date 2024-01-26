//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        //vector<double>fractions;
        vector<pair<double,int>>pr;
        double ans=0;
        for(int i=0;i<n;i++)
        {
            double a=(double)arr[i].value/(double)arr[i].weight;
            pr.push_back({a,i});
        }
        sort(pr.begin(),pr.end());
        reverse(pr.begin(),pr.end());
        // for(auto it:pr)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(auto it:pr)
        {
            if(W<=0) break;
            //cout<<arr[it.second].weight<<" ";
            if(arr[it.second].weight<=W)
            {
                W-=arr[it.second].weight;
                ans+=arr[it.second].value;
            }
            else
            {
                double req=W;
                ans+=((it.first)*req);
                W=0;
            }
        }
        return ans;
        
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends