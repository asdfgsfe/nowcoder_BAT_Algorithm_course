/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return NULL;  
        RandomListNode* oldHead=pHead;
        RandomListNode* newHead=NULL;
        while(oldHead!=NULL)
        {    
        	newHead=(RandomListNode *)malloc(sizeof(struct RandomListNode));
        	newHead->label=oldHead->label;
            newHead->next=oldHead->next;;
        	newHead->random=NULL;
            
            oldHead->next=newHead;
        	oldHead=newHead->next;
        }
        
        oldHead=pHead;
        newHead=pHead->next;
        while(oldHead!=NULL )
        {
            if(oldHead->random!=NULL)    
            	newHead->random=oldHead->random->next;
            oldHead->next=newHead->next;
            newHead->next=oldHead->next;
            
        }    
           
        oldHead=pHead;
        RandomListNode* pNode=pHead->next;
        newHead=pHead->next;
        while(oldHead!=NULL)
        {
            oldHead->next=pNode->next;
            oldHead=oldHead->next;
            pNode->next=oldHead->next;
            pNode=oldHead->next;
        }
        
        return newHead;    
    }
};