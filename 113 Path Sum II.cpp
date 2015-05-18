/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
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
	void pathSumRecur(TreeNode * root, int sum, int currentSum, vector<vector<int> > &ans, vector<int> &tmp) {
		if(root->left == NULL && root->right == NULL) {
			if(sum == currentSum + root->val) {
				tmp.push_back(root->val);
				ans.push_back(tmp);
				tmp.pop_back();
			}
		} else {
			tmp.push_back(root->val);
			if(root->left != NULL)
				pathSumRecur(root->left, sum, currentSum + root->val, ans, tmp);
			if(root->right != NULL)
				pathSumRecur(root->right, sum, currentSum + root->val, ans, tmp);
			tmp.pop_back();
		}
	}
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
    	vector<vector<int> > ans;
    	if(root == NULL)	return ans;
    	vector<int> tmp;
    	pathSumRecur(root, sum, 0, ans, tmp);
    	return ans;
    }
};