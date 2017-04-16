class Exchange {
public:
    int countWays(vector<int> penny, int n, int aim) {
        // write code here
        if(n<=0 || aim<0)
            return 0;
        int dp[n][aim+1];
		memset(dp, 0, sizeof(dp));        
        
        int i, j;
        for(i=0; i<n; i++)
            dp[i][0]=1;
        for(i=0; i<aim+1; i++)
            if(i%penny[0]==0)
                dp[0][i]=1;
        
        int num=0;
        for(i=1; i<n; i++)
        {
            for(j=1; j<aim+1; j++)
            {
            		//优化后的程序
                /*
                if(penny[i]>j)
                    dp[i][j]=dp[i-1][j];
                else
                	dp[i][j] = dp[i-1][j] + dp[i][j-penny[i]];
                	*/
                num=0;
				int k;
                for(k=0; j-penny[i]*k>=0; k++)
                    num += dp[i-1][j-penny[i]*k];
                dp[i][j]=num;
            }
        }    
        return dp[n-1][aim];
    }
};