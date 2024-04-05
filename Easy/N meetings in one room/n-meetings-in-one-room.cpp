//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    static bool comp(const pair<int,int>&a,const pair<int,int>&b)
    {
        return a.second<b.second;
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({end[i],start[i]});
        }
        sort(vp.begin(),vp.end());
        int cnt=1;
        int pre=vp[0].first;
        for(int i=0;i<n;i++){
            if(vp[i].second>pre){
                cnt++;
                pre=vp[i].first;
            }
        }
        return cnt;
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends