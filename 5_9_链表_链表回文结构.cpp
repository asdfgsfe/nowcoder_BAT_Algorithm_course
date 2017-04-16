���дһ����������������Ƿ�Ϊ���ġ�
����һ������ListNode* pHead���뷵��һ��bool�����������Ƿ�Ϊ���ġ�
����������
{1,2,3,2,1}
���أ�true
{1,2,3,2,3}
���أ�false


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
        
        //���pQuick->next!=NULL�ر���Ҫ 
        //���pQuick->next==NULL,��ʱ��û��pQiuck->next->next���˵�������Ա���
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