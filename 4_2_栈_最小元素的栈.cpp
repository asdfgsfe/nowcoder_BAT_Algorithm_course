定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

class Solution {
public:
    stack<int>s;
    stack<int>sMin;
    void push(int value) {
        s.push(value);
        //此处必须先判断SMin.empty()否则会死循环
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