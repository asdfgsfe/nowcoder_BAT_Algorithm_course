������һ��������������ÿ���ڵ㱣��һ���������ٸ���һ��ֵval�������е���val�Ľڵ�ɾ����
����һ���������ͷ���head��ͬʱ����һ��ֵval���뷵�������������ͷ��㣬��֤�������в����ڸ�ֵ������ֵ���뱣֤����Ԫ�ص����˳��
����������
{1,2,3,4,3,2,1},2
{1,3,4,3,1}

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ClearValue {
public:
    ListNode* clear(ListNode* head, int val) {
        // write code here
        if(!head)
        	return NULL;
        	//���׳��� �������ҵ���һ����val�Ľڵ���Ϊ����ͷ;
        while(head!=NULL)
        {
            if(head->val!=val)
                break;
            head=head->next;
        }    
        ListNode* prev=head;
        ListNode* cur=head;
        
        while(cur!=NULL)
        {
            if(cur->val==val)
            //���׳��� ��д��prev=cur->next;
                prev->next=cur->next;
            else
                prev=cur;
            cur=cur->next;
        }    
        return head;
    }
};