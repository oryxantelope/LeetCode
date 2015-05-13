/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
	TreeNode *buildTreeRecur(vector<int> &inorder, int beginInorder, int endInorder, vector<int> &postorder, int beginPostorder, int endPostorder) {
		if(beginInorder > endInorder)	return NULL;
		if(beginInorder == endInorder)	return new TreeNode(inorder[beginInorder]);
		int index;
		for(index = beginInorder;index <= endInorder; index ++) {
			if(inorder[index] == postorder[endPostorder])
				break;
		}
		TreeNode * root = new TreeNode(postorder[endPostorder]);
		root->left = buildTreeRecur(inorder, beginInorder, index - 1, postorder, beginPostorder, index - 1 - beginInorder + beginPostorder);
		root->right = buildTreeRecur(inorder, index + 1, endInorder, postorder, index - beginInorder + beginPostorder, endPostorder - 1);
		return root;
	}
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    	if(inorder.size() != postorder.size() || inorder.size() == 0)	return NULL;
    	return buildTreeRecur(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};