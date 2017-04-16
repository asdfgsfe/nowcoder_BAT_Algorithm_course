//���Ž�
//dp[i][j] ��ʾstr1[o...i]��str2[0...j]�������������
class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        // write code here
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i - 1] == B[j - 1]) {//ֻ��������dp���±�1��ʼ
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};