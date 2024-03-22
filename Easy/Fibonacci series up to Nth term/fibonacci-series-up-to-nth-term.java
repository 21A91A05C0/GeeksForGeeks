//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Main {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution obj = new Solution();
            int ans[] = obj.Series(n);
            for (int i : ans) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


class Solution {

    int[] Series(int n) {
        // code here
        int mod=1000000007;
        int[] arr=new int[n+1];
        int a=0;
        int b=1;
        arr[0]=a;
        arr[1]=b;
        // arr.add(b);
        // n-=2;
        int i=2;
        while(i<=n)
        {
            int c=(a%mod+b%mod)%mod;
            arr[i]=c%mod;
            i++;
            a=b%mod;
            b=c%mod;
        }
        return arr;
    }
}