/*����ֲ���С�ĸ��arr����Ϊ1ʱ��arr[0]�Ǿֲ���С��arr�ĳ���ΪN(N>1)ʱ��
���arr[0]<arr[1]����ôarr[0]�Ǿֲ���С�����arr[N-1]<arr[N-2]��
��ôarr[N-1]�Ǿֲ���С�����0<i<N-1������arr[i]<arr[i-1]����arr[i]<arr[i+1]��
��ôarr[i]�Ǿֲ���С�� ������������arr����֪arr�������������ڵ���������ȣ�
дһ��������ֻ�践��arr������һ���ֲ���С���ֵ�λ�ü��ɡ�*/


class Solution {
public:
    int getLessIndex(vector<int> arr) {
        int n=arr.size();
        if(n==0)
            return -1;
        if(n==1||arr[0]<arr[1])
            return 0;    
        if(arr[n-1]<arr[n-2])
        	return n-1;
        
        int mid=0;
        //�˴�ע�� �����left=0��right=n-1�����
        int left=1,right=n-2;
        //�˴�left<rightҲ��
        while(left<=right)
        {
            mid = left+(right-left)/2;
            if(arr[mid]>arr[mid-1])
                right=mid-1;
            else 
            if(arr[mid]>arr[mid+1])
                left=mid+1;
            else   
				return mid;   
                
        }
        //�˴�����leftҲ��
        return mid;
    }
};