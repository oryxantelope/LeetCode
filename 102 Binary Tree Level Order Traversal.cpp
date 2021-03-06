/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
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
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > ans;
    	if(root == NULL)	return ans;
    	vector<TreeNode *> v[2];
    	int current = 0;
    	v[current].push_back(root);
    	while(v[current].size() > 0) {
    		vector<int> tmp;
    		for(int i = 0;i < (int)v[current].size();i ++) {
    			tmp.push_back(v[current][i]->val);
    			if(v[current][i]->left != NULL)
    				v[1 - current].push_back(v[current][i]->left);
    			if(v[current][i]->right != NULL)
    				v[1 - current].push_back(v[current][i]->right);
    		}
    		ans.push_back(tmp);
    		v[current].clear();
    		current = 1 - current;
    	}
    	return ans;
    }
};