class MinimumPath {
public:
    int min(int a, int b)
    {
        return (a<b)?a:b;
    }    
    
    
    int getMin(vector<vector<int> > map, int n, int m) {
        // write code here
        int dp[100][100]={0};
        dp[0][0]=map[0][0];
        int i, j;
        for(i=1; i<n; i++)
        {  
            dp[0][i] = map[0][i]+dp[0][i-1];
        //for(i=1; i<m; i++)
        	dp[i][0] = map[i][0]+dp[i-1][0];
        }
        for(i=1; i<n; i++)
        {
            for(j=1; j<m; j++)
            {
                dp[i][j]=map[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }    
        }    
        return dp[n-1][m-1];
    }
};