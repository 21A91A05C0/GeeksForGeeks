//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        string a="";
        string  b="";
        string c="";
        string d="";
        int flag=0;
        int e=0;
        int k=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==',') flag=1;
            
            else if(flag==0)
            {
                if(str[i]=='/')
                {
                    e=1;
                }
                else if(e==0)
                {
                    a+=str[i];
                }
                else b+=str[i];
            }
            else if(flag==1)
            {
                if(str[i]==' ') continue;
                else if(str[i]=='/')
                {
                    k=1;
                }
                else if(k==0)
                {
                    c+=str[i];
                }
                else d+=str[i];
            }
        }
        // cout<<stoi(a)<<" "<<stoi(b);
        double q=stoi(a)*1.0/stoi(b)*1.0;
        double w=stoi(c)*1.0/stoi(d)*1.0;
        if(q==w) return "equal";
        else if(q>w) return a+'/'+b;
         else return c+'/'+d;
        // cout<<a<<" "<<b<<" "<<c<<" "<<d;
        return "";
        
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends