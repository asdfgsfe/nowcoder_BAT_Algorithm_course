//��������С���������Ժ������A��B������A��ĩ�����㹻�Ļ��������B��
���дһ����������B�ϲ���A������
������������int����A��B��A�еĻ������0��䣬ͬʱ����A��B����ʵ��Сint n��int m��
�뷵�غϲ�������顣

class Merge {
public:
    int* mergeAB(int* A, int* B, int n, int m) {
        // write code here
        int allSize=m+n-1;
        int i=n-1;
        int j=m-1;
        
        while(i>=0&&j>=0)
        {
            if(A[i]>B[j])
               A[allSize--]=A[i--]; 
            else
            	A[allSize--]=B[j--];
                     
        }  
        while(i>=0)
            A[allSize--]=A[i--];
        while(j>=0)
            A[allSize--]=B[j--];
        
        return A;
        
    }
};