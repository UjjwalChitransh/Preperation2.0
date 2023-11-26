class Solution {
    public:
            int integerBreak(int n)
            {
                vector<int> dp(100);
                dp[1]=1;
                dp[2]=1;
                dp[3]=2;
                for(int i=4;i <= n;i++)
                {
                    int num = i;
                    for(int j=1;j<=num;j++)
                    {
                        int x=j;
                        int y=num-x;
                        dp[i]=max({dp[i],x*y,dp[x]*y,x*dp[y],dp[x]*dp[y]});
                    }
                }
                return dp[n];
            }
}


//https://www.youtube.com/watch?v=TMfaNbjy1pI&ab_channel=codeExplainer

Time Complexity:
The outer loop runs for n - 3 iterations (from 4 to n). Within each iteration, you have an inner loop that runs j from 1 to i. In the worst case, the inner loop has a time complexity of O(n).

Therefore, the overall time complexity is approximately O(n^2).


Space Complexity:
The space complexity is determined by the size of the dp vector, which is n + 1. Hence, the space complexity is O(n).


Summary:
Time Complexity: O(n^2)
Space Complexity: O(n)


This implementation has polynomial time complexity, which should work efficiently for the given constraints (2 <= n <= 58). The space complexity is linear and depends on the size of the input.
