请编写一个函数，检查链表是否为回文。
给定一个链表ListNode* pHead，请返回一个bool，代表链表是否为回文。
测试样例：
{1,2,3,2,1}
返回：true
{1,2,3,2,3}
返回：false


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* tmp=NULL;
        while(cur!=NULL)
        {
            tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }    
         return prev;
    }
    
    bool isPalindrome(ListNode* pHead) {
        // write code here
        if(pHead==NULL || pHead->next==NULL)
            return true;
        
        ListNode* pSlow=pHead;
        ListNode* pQuick=pHead;
        
        //检查pQuick->next!=NULL特别重要 
        //如果pQuick->next==NULL,此时就没有pQiuck->next->next这个说法，所以报错；
        while(pQuick!=NULL&&pQuick->next!=NULL)
        {
            pSlow=pSlow->next;
            pQuick=pQuick->next->next;
        }    
        pQuick=reverseList(pSlow);
        pSlow=pHead;
        while(pQuick!=NULL)
        {
            if(pSlow->val!=pQuick->val)
                return false;
            pSlow=pSlow->next;
            pQuick=pQuick->next;
        }    
        reverseList(pSlow);
        
       return true; 
    }
};