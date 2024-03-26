#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
#10:56
# return 1 in case of True and 0 in case of False
class Solution:
    def isAdditiveSequence(self, n):
        #code here
        
        for i in range(0,len(n)):
            for j in range(i+1,len(n)):
                f=n[:i+1]
                s=n[i+1:j+1]
                nextt=int(f)+int(s)
                le=len(str(nextt))
                k=j+1
                while(n[k:k+le]==str(nextt)):
                    f=s
                    s=nextt
                    k+=le
                    nextt=int(f)+int(s)
                    le=len(str(nextt))
                    if(k==len(n)):
                        return 1
                    if(k>len(n)):
                        break
        return 0
                    
                    
                    
                    
        return 0
            

#{ 
 # Driver Code Starts.
        
if __name__ == "__main__":
    sol = Solution()
    t = int(input())
    for _ in range(t):
        s = input()
        print(sol.isAdditiveSequence(s))

# } Driver Code Ends