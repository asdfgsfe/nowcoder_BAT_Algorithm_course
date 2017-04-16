请用递归方式实现二叉树的先序、中序和后序的遍历打印。
给定一个二叉树的根结点root，请依次返回二叉树的先序，中序和后续遍历(二维数组的形式)。

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
//自己写的代码
class TreeToSequence {
public:
		//对于vector的应用地址定义用vector<int> &A;
    void prevPrintTree(TreeNode* root,vector<int> &prev)
    {
        TreeNode* tmp=root;
        //注意此处NULL的判断
        if(root!=NULL)
        {
            prev.push_back(tmp->val);
        	prevPrintTree(tmp->left,prev);
        	prevPrintTree(tmp->right,prev);
 
        }   
    }
    void midPrintTree(TreeNode* root,vector<int> &mid)
    {
        TreeNode* tmp=root;
        if(root!=NULL)
     	{   
            midPrintTree(tmp->left,mid);
        	mid.push_back(tmp->val);
        	midPrintTree(tmp->right,mid);
    
        }
    }
    void behindPrintTree(TreeNode* root,vector<int> &behind)
    {
        TreeNode* tmp=root;
        if(root!=NULL)
        {    
        	behindPrintTree(tmp->left,behind);
        	behindPrintTree(tmp->right,behind);
            behind.push_back(tmp->val);
        }    
    }
    
    vector<vector<int> > convert(TreeNode* root) {
        // write code here
        vector<int> prev,mid,behind;
        vector<vector<int>> res;
        
        prevPrintTree(root,prev);
        midPrintTree(root,mid);
        behindPrintTree(root,behind);
        
        res.push_back(prev);
        res.push_back(mid);
        res.push_back(behind);
        
        return res;
    }
};



//答案源码

class TreeToSequence {
public:
    void pre(TreeNode* rt,vector<int> &ret){
        ret.push_back(rt->val);
        if(rt->left) pre(rt->left,ret);
        if(rt->right) pre(rt->right,ret);
    }
    void mid(TreeNode* rt,vector<int> &ret){
        if(rt->left) mid(rt->left,ret);
        ret.push_back(rt->val);
        if(rt->right) mid(rt->right,ret);
    }
    void aft(TreeNode* rt,vector<int> &ret){
        if(rt->left) aft(rt->left,ret);
        if(rt->right) aft(rt->right,ret);
        ret.push_back(rt->val);
    }
    vector<vector<int> > convert(TreeNode* root) {
        vector<int> A,B,C;
        vector<vector<int> > ret;
        pre(root,A); mid(root,B); aft(root,C);
        ret.push_back(A); ret.push_back(B); ret.push_back(C);
        return ret;
    }
};