//�������ʵ�����Ĳ������ݴ洢

��һ�ö������������һ���㷨�����ղ�δ�ӡ��ö�������
�����������ĸ����root���뷵�ش�ӡ������������ÿһ��һ��������д��棬
���������˳���ղ����������£���ÿһ���������Ԫ�ذ��մ����������С�
��֤�����С�ڵ���500��

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