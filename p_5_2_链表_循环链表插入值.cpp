/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class InsertValue {
public:
    ListNode * creatCircleList(vector<int> &A, vector<int> &next){
        ListNode *pHead = NULL;        
        if (A.size()!=next.size() || next.size()==0){
            return pHead;
        }
        pHead = new ListNode(A[0]);        
        ListNode *pc = pHead;
        for (int i=0; i<next.size()-1; i++){
            pc->next = new ListNode(A[next[i]]);
            pc = pc->next;
        }
        pc->next = pHead;
        return pHead;                
    }
    
    ListNode* insertNode(ListNode *pHead, int val){
        if (pHead == NULL){
            return pHead;
        }
        
        ListNode *pp = pHead;
        ListNode *pc = pHead->next; 
        ListNode *pm = NULL;
        while (pc != pHead){
            if (pp->val <= val && val <= pc->val){
                pm = new ListNode(val);
                pm->next = pc;
                pp->next = pm;
                break;
            }else {
                pp = pc;
                pc = pc->next;
            }            
        }
              
    }
    //两段代码差距很大
    if (pc == pHead){
            pm = new ListNode(val);
            pm->next = pc;
            pp->next = pm;
            pHead = pm->val > pHead->val?pHead:pm;
        }  
    //          
        return pHead;  
    
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        // write code here
        ListNode *pHead = NULL;
        if (A.size()!=nxt.size() || nxt.size()==0){
            return pHead;
        }
        pHead = creatCircleList(A, nxt);
        pHead = insertNode(pHead, val);
       
        ListNode *pp = pHead;
        ListNode *pc = pHead->next;
        while (pc != pHead){
            pp = pc;
            pc = pc->next;            
        }
        pp->next = NULL;
            
        return pHead;                
    }
};