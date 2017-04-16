//特别注意c++中的string和c中的char a[]定义的字符串比较。
//尤其在赋值方面

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreeToString {
public:
    string interToStr(int a)
    {	
        string pStr;
        int i=0;
        while(a)
        {
            pStr+=a%10+'0';
            a/=10;
        }  
        reverse(pStr.begin(),pStr.end());
        return pStr;
    }
    void prevTree(TreeNode* pRoot,string &strTall)
    {
    	if(!pRoot)
        {    
            strTall+="#!";
            return; 
        }
        
        strTall+=interToStr(pRoot->val)+"!";
        prevTree(pRoot->left,strTall);
        prevTree(pRoot->right,strTall);
    }   
    
    string toString(TreeNode* root) {
        // write code here
 		string strTall;
         if(!root)    
            return strTall;
         
        prevTree(root,strTall);
      
    	return strTall;
    }
};