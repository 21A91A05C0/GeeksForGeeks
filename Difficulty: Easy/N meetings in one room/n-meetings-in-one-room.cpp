//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push_back({end[i],start[i]});
        }
        sort(pq.begin(),pq.end());
        int ans=1;
        int limit=-1;
        for(auto it:pq)
        {
            int s=it.second;
            int e=it.first;
            if(limit==-1)
            {
                limit=e;
            }
            else
            {
                if(s>limit)
                {
                    ans++;
                    limit=e;
                }
                
            }
        }
        return ans;
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