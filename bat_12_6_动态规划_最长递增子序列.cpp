//最长自增子序列不一定连续问题

class LongestIncreasingSubsequence {
public:
    int dpMaxNUm(int *dp, int n)
    {
        int i;
        int ret=dp[0];
        for(i=0; i<n; i++)
            if(dp[i]>ret)
                ret=dp[i];
        return ret;
    }
    
    int max(int *dp, int i, vector<int> A)
    {
        int j;
        int maxNum=0;
        for(j=0; j<i; j++)
        	if(dp[j]>maxNum && A[j]<A[i])
                maxNum=dp[j];
        return maxNum;
    }
    
    int getLIS(vector<int> A, int n) {
        // write code here
        if(n<=0)
            return 0;
        int dp[500]={1};
        int i;
        for(i=0; i<n; i++)
            dp[i] = max(dp, i, A)+1;
        
        return dpMaxNUm(dp, n);
    }
};