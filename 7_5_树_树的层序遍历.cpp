//经典代码实现树的层序数据存储

有一棵二叉树，请设计一个算法，按照层次打印这棵二叉树。
给定二叉树的根结点root，请返回打印结果，结果按照每一层一个数组进行储存，
所有数组的顺序按照层数从上往下，且每一层的数组内元素按照从左往右排列。
保证结点数小于等于500。

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreePrinter {
public:
vector<vector<int> > printTree(TreeNode* root) 
{
	// write code here
    queue<TreeNode*> que;
		vector<vector<int>> result;
		vector<int> vec;
		if(!root)
			return result;
    que.push(root);
		while(!que.empty())
		{
			TreeNode* temp;
			int len = que.size();
			while(len--)
			{ 
				temp = que.front();
				que.pop();
				vec.push_back(temp->val);
				if(temp->left) 
					que.push(temp->left);
				if(temp->right)
					que.push(temp->right);   
			}
			result.push_back(vec);
			vec.clear();
		}
		return result;
}
    
};