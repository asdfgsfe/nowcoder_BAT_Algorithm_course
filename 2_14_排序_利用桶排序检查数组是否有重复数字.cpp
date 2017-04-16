class Checker {
public:  
    bool checkDuplicate(vector<int> a, int n) {
        // write code here
		int min,max,i;
        min=max=a[0];
        for(i=1;i<n;i++)
        {
            if(a[i]<min)
                min=a[i];
            if(a[i]>max)
                max=a[i];
        }
        
        int *tmp;
        tmp=(int *)malloc(sizeof(int)*(max-min+1));
        for(i=0;i<=max-min;i++)
            tmp[i]=0;
        
        for(i=0;i<n;i++)
            tmp[a[i]-min]++;
 		for(i=0;i<=max-min;i++)
          	if(tmp[i]>1)  
        		return true;
            
        return false;
    }
};