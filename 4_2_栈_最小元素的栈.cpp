����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������

class Solution {
public:
    stack<int>s;
    stack<int>sMin;
    void push(int value) {
        s.push(value);
        //�˴��������ж�SMin.empty()�������ѭ��
        if(value<=sMin.top()||sMin.empty())
            sMin.push(value);
        else
            sMin.push(sMin.top());
    }
    void pop() {
        sMin.pop();
        s.pop();
    }
    int top() {
		return s.top();
    }
    int min() {
        return sMin.top();
    }
};