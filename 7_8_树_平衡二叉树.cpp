//��һ�ö������������һ���㷨�ж���ö������Ƿ�Ϊƽ���������
//�����������ĸ����root���뷵��һ��boolֵ������������Ƿ�Ϊƽ���������
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class CheckBalance {
public:
    int checkHeight(TreeNode* pRoot)
    {
        if(!pRoot) 
            return 0;
            
        int lh,rh;
        lh=checkHeight(pRoot->left);
        rh=checkHeight(pRoot->right);
        
        if(lh<0||rh<0) 
            return -1;
        if(abs(lh-rh)>1)
            return -1;
        
        return lh>rh?lh+1:rh+1;   
    }    
   
    bool check(TreeNode* root) {
        // write code here
        int res=checkHeight(root);
        if(res<0)
            return false;
        else
        	return true;
    }
};