class Solution:
    def fact(self, n, dp):
        if(n==0 or n==1):
            return 1
        if (dp[n] != -1):
            return dp[n]
        dp[n] = n * self.fact(n-1,dp)
        return dp[n]
    def uniquePaths(self, m: int, n: int) -> int:
        m -= 1
        n -= 1
        dp = (m+n+1)*[-1]
        return (int)(self.fact(m+n,dp)/(self.fact(m,dp)*self.fact(n,dp)))