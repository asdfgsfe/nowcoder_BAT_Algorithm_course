

class CountingSort {
public:
    int findMax(int *A,int n)
    {
        int i=1;
        int max=A[0];
        for(;i<n;i++)
            if(A[i]>max)
            	max=A[i];
        return max;
    }    
    
    int* countingSort(int* A, int n) {
       	//异常检查很重要必须得加
	if(A==NULL||n==0)
        	return NULL;
        int max=findMax(A,n);
        int *dataSize;
        dataSize=(int *)malloc(sizeof(int)*(max+1));
        int i=0;
        for(;i<=max;i++)
            dataSize[i]=0;
            
        
        for(i=0;i<n;i++)
            dataSize[A[i]]++;
        
        int tmpId=0;//如果不定义该变量 会导致for语句死循环
        for(i=0;i<=max;i++)
        {
            int j=dataSize[i];
            for(;j>0;j--)
            	A[tmpId++]=i;//注意个哦A数组的值为数组dataSize的id
        }    
        free(dataSize);
        return A;
    }
};