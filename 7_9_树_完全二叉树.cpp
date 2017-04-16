//判断是否为完全二叉树 用层序遍历树的方法 采用c++队列自带队列实现。
//
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class CheckCompletion {
public:
    bool chk(TreeNode* root) {
        // write code here
        int tallLen=0;
        if(!root)
            return true;
        vector<TreeNode*> val;
        std::queue<TreeNode*> tQue;
        tQue.push(root);
		while(!tQue.empty())
		{
            TreeNode* nLast;
            int len=tQue.size();
            tallLen+=len;
            while(len--)
            {
            	nLast=tQue.front();
                tQue.pop();
                val.push_back(nLast);
                if(nLast->left)
                    tQue.push(nLast->left);
                if(nLast->right)
                    tQue.push(nLast->right);
            }  
        }
        int i;
        bool flag=false;
        for(i=0;i<=tallLen;i++)
        {
            if(val[i]->left==NULL||val[i]->right==NULL)
            {
                if(val[i]->left==NULL && val[i]->right) 
                    return false;
                if(!flag) flag=true;
                else if(val[i]->left||val[i]->right)
                    return false;
            }    
        }    

        return true;
    }
};


//判断完全二叉树 用数组实现

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class CheckCompletion {
public:
    bool chk(TreeNode* root) {
        // write code here
        if(!root)
            return true;
        TreeNode *node[500],*cur;
        int head=0,tail=0;
        node[tail++]=root;
        while(head!=tail)
        {
            cur=node[head++];
            
            if(cur->left)
            	node[tail++]=cur->left;
            if(cur->right)
                node[tail++]=cur->right;
        }    
        
        int i;
        bool flag=false;
        for(i=0;i<tail;i++)
        {
            if(node[i]->left==NULL || node[i]->right==NULL)
            {
                if(node[i]->left==NULL && node[i]->right)
                    return false;
                if(!flag) flag=true;
                else if(node[i]->left || node[i]->right)
                    return false;
            }    
        }    
        
        return true;
    }
};