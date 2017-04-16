/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Common {
public:
    vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
        // write code here
        vector<int> array;
        //if(headA==NULL || headB==NULL)
        //	return ;
        while(headA!=NULL && headB!=NULL)
        {
                if(headA->val==headB->val)
                {
                    array.push_back(headA->val);
                    headA=headA->next;
                    headB=headB->next;
                }    
                else
               	if(headA->val<headB->val)
                    headA=headA->next;
                else
                    headB=headB->next;   
            
        }   
        return array;
        
    }
};