class ScaleSort {
public:
    vector<int> sortElement(vector<int> A, int n, int k) {
        // write code here
        //if(A.size()==0||n=0)
           // return ;
        
        int i,p;
        int tmp;
        for(p=1;p<n;p++)
        {
            tmp=A[p];
            for(i=p;i>=(p-k)&&A[i-1]>tmp;i--)
                A[i]=A[i-1];
            A[i]=tmp;
        }    
        return A;
    }
   
};