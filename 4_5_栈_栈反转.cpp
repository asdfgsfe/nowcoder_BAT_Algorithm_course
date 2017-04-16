//反转一个数组中的数字 利用数组特性 前后交换
//或者利用栈结构
class StackReverse {
public:
    vector<int> reverseStack(vector<int> &A, int n) {
        // write code here
        if(A.empty()|| n==0)
            return A;
        int i=0;
        int j=n-1;
        int tmp;
        for(;i<=j;i++,j--)
        {
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
        return A;
    }
};