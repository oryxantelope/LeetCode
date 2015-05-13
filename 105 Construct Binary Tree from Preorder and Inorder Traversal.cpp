/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
	TreeNode *buildTreeRecur(vector<int> &inorder, int beginInorder, int endInorder, vector<int> &preorder, int beginPreorder, int endPreorder) {
		if(beginInorder > endInorder)	return NULL;
		if(beginInorder == endInorder)	return new TreeNode(inorder[beginInorder]);
		int index;
		for(index = beginInorder;index <= endInorder; index ++) {
			if(inorder[index] == preorder[beginPreorder])
				break;
		}
		TreeNode * root = new TreeNode(preorder[beginPreorder]);
		root->left = buildTreeRecur(inorder, beginInorder, index - 1, preorder, beginPreorder + 1, index - beginInorder + beginPreorder);
		root->right = buildTreeRecur(inorder, index + 1, endInorder, preorder, index - beginInorder + beginPreorder + 1, endPreorder);
		return root;
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	if(inorder.size() != preorder.size() || inorder.size() == 0)	return NULL;
    	return buildTreeRecur(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
    }
};