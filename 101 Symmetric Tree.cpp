/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * 
 * For example, this binary tree is symmetric:
 * 
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * 
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 * 
 * 
 * OJ's Binary Tree Serialization:
 * The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
 * 
 * Here's an example:
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
	bool isMirror(TreeNode * root1, TreeNode * root2) {
		if(root1 == NULL && root2 == NULL)	return true;
		if(root1 == NULL || root2 == NULL)	return false;
		if(root1->val != root2->val)	return false;
		if(isMirror(root1->left, root2->right))
			return isMirror(root1->right, root2->left);
		else
			return false;
	}
    bool isSymmetric(TreeNode *root) {
    	if(root == NULL)	return true;
    	return isMirror(root->left, root->right);
    }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
	bool check(vector<TreeNode *> &v) {
		int length = v.size();
		if(length == 1)	return true;
		if(length % 2 != 0)	return false;
		for(int i = 0,j = v.size() - 1;i < j;i ++, j --) {
			if(v[i] == NULL && v[j] == NULL)	continue;
			if(v[i] == NULL || v[j] == NULL)	return false;
			if(v[i]->val != v[j]->val) {
				return false;
			}
		}
		return true;
	}
    bool isSymmetric(TreeNode *root) {
    	if(root == NULL)	return true;
    	vector<TreeNode *> v[2];
    	int current = 0;
    	bool isAllNull;
    	v[current].push_back(root);
    	while(v[current].size() > 0) {
    		if(!check(v[current]))
    			return false;
    		isAllNull = true;
    		for(int i = 0;i < (int)v[current].size();i ++) {
    			if(v[current][i] != NULL) {
    				v[1-current].push_back(v[current][i]->left);
    				v[1-current].push_back(v[current][i]->right);
    				isAllNull = false;
    			}
    		}
    		if(isAllNull) {
    			break;
    		}
    		v[current].clear();
    		current = 1 - current;
    	}
    	return true;
    }
};