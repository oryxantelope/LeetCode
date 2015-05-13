/**
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
class Solution {
public:
	int balancedDepth(TreeNode *root) {
		if(root == NULL)	return 0;
		int left = balancedDepth(root->left);
		if(left == -1)	return -1;
		int right = balancedDepth(root->right);
		if(right == -1)	return -1;
		if(abs(left - right) > 1)
			return -1;
		else
			return max(left, right) + 1;
	}
    bool isBalanced(TreeNode *root) {
    	if(root == NULL)	return true;
    	int left = balancedDepth(root->left);
    	if(left == -1) return false;
    	int right = balancedDepth(root->right);
    	if(right == -1)	return false;
    	if(abs(left - right) > 1)
    		return false;
    	else
    		return true;
    }
};