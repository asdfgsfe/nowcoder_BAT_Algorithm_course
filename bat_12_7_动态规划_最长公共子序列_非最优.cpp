//代码非最优解
class LCS {
public:
    int max(int a, int b)
	{
        a=a>b?a:b;
        //a=a>c?a:c;
        return a;
    }    
    int findLCS(string A, int n, string B, int m) {
        // write code here
        int dp[300][300]={0};
        int i, j;
        for(int i = 0;i<n;++i)
            dp[i][0] = 1;
        for(int j = 0;j<m;++j)
            dp[0][j] = 1;
        
        for(i=0; i<n; i++) 
        {    
            if(A[i] != B[0])
        		dp[i][0] = 0;
            else
                break;//为什么要break；
        }
        for(i=0; i<m; i++)  
        {    
         	if(A[0]!=B[i])
            	dp[0][i]=0;
            else
                break;
        }
        for(i=1; i<n; i++)
        {
            for(j=1; j<m; j++)
            {
                if(A[i]==B[j])
                	dp[i][j]=dp[i-1][j-1]+1;
                else
                	dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }    
        }    
        return dp[n-1][m-1];
    }
};