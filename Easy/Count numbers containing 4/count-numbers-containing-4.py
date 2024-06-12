
class Solution:
    def countNumberswith4(self, n : int) -> int:
        # code here
        # k='1'
        ans=0
        for i in range(1,n+1):
            k=str(i)
            if '4' in k:
                ans+=1
        return ans
        
        



#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n = int(input())

        obj = Solution()
        res = obj.countNumberswith4(n)

        print(res)

# } Driver Code Ends