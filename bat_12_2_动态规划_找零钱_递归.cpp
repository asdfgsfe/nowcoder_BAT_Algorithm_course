class Exchange {
public:
    int countWaysCore(vector<int> penny, int index, int aim)
    {
        int res=0;
        if(res==penny.size())
            res = aim==0?1:0;
        else
        {
            int i;
            for(i=0; penny[index]*i<=aim; i++)
                res += countWaysCore(penny, index+1, aim-penny[index]*1);
        }   
        return res;
    }
    
    int countWays(vector<int> penny, int n, int aim) {
        // write code here
        if(n<=0 || aim<0)
            return 0;
        return countWaysCore(penny, 0, aim);
    }
};