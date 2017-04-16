

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
       	//�쳣������Ҫ����ü�
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
        
        int tmpId=0;//���������ñ��� �ᵼ��for�����ѭ��
        for(i=0;i<=max;i++)
        {
            int j=dataSize[i];
            for(;j>0;j--)
            	A[tmpId++]=i;//ע���ŶA�����ֵΪ����dataSize��id
        }    
        free(dataSize);
        return A;
    }
};