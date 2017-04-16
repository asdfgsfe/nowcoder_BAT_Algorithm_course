class InsertValue {
public:
	ListNode* creatCircList(vector<int> A, int lenA, vector<int> nxt, int lenNxt)
	{
		ListNode* pHead = NULL;
		ListNode* tmpHead = NULL;

		pHead = (ListNode *)malloc(sizeof(struct ListNode));
		if (pHead == NULL)
			printf("out of space\n");
		pHead->val = A[0];
		pHead->next = NULL;
		tmpHead = pHead;

		int i = 0;
		for (;i<lenNxt - 1;i++)
		{
			ListNode* tmpNode = NULL;
			tmpNode = (ListNode *)malloc(sizeof(struct ListNode));
			if (tmpNode == NULL)
				printf("out of space\n");
			tmpNode->val = A[nxt[i]];
			tmpNode->next = NULL;

			tmpHead->next = tmpNode;
			tmpHead = tmpHead->next;
		}
		tmpHead->next = pHead;

		return pHead;
	}

	ListNode* insertVal(ListNode* pHead, int val)
	{
		ListNode* valNode;
		valNode = (ListNode *)malloc(sizeof(struct ListNode));
		if (valNode == NULL)
			printf("out of space\n");
		valNode->val = val;
		valNode->next = NULL;

		if (pHead == NULL)
		{
			pHead = valNode;
			pHead->next = valNode;
			return pHead;
		}
		if (pHead->next == pHead)
		{
			if (pHead->val <= val)
			{
				pHead->next = valNode;
				valNode->next = pHead;
				return pHead;
			}
			else
			{
				valNode->next = pHead;
				pHead->next = valNode;
				return valNode;
			}
		}

		ListNode* prevNode = pHead;
		ListNode* behindNode = pHead->next;

			while (behindNode!=pHead)
			{
				if (prevNode->val <= val && behindNode->val>val)
				{
					prevNode->next = valNode;
					valNode->next = behindNode;
					break;
				}

				prevNode = behindNode;
				behindNode = behindNode->next;
			}
			//2和3两段代码差距很大
			if (behindNode == pHead){
			 			valNode->next=behindNode;
            prevNode->next = valNode;
            pHead = valNode->val > pHead->val?pHead:valNode;
        } 
      //
		return pHead;
	}

	ListNode* insert(vector<int> A, vector<int> nxt, int val) {
		// write code here
		ListNode* pHead = NULL;
		int lenA = A.size();
		int lenNxt = nxt.size();

		if (lenA != lenNxt || lenNxt == 0)
			return pHead;
		pHead = creatCircList(A, lenA, nxt, lenNxt);
		pHead = insertVal(pHead, val);

        ListNode* tmp=pHead;
        while(tmp->next!=pHead)
            tmp=tmp->next;
        tmp->next=NULL;
        
		return pHead;
	}
};