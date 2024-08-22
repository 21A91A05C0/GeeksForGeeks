//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool metaStrings (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << metaStrings (s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends



bool metaStrings (string S1, string S2)
{
    // your code here
    int firstindex=-1,secind=-1;
    for(int i=0;i<S1.size();i++)
    {
        if(S1[i]!=S2[i])
        {
           
            // cout<<"hi"<<" ";
            if(firstindex==-1)
            {
                firstindex=i;
            }
            else if(secind==-1)
            {
                secind=i;
            }
            else return 0;
        }
        
    }
        // cout<<firstindex<<" "<<secind<<endl;
        // cout<<S2[firstindex]<<" "<<S1[secind]<<endl;
        if(firstindex==-1 && secind==-1) return 0;
        if(S2[firstindex]==S1[secind] && S1[firstindex]==S2[secind]) return 1;
        return 0;
        // cout<<"HI";

}