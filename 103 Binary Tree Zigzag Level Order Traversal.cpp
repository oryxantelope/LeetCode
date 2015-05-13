/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    	vector<vector<int> > ans;
    	if(root == NULL)	return ans;
    	vector<int> v;
    	vector<TreeNode *> bfs[2];
    	int current = 0;
    	v.push_back(root->val);
    	ans.push_back(v);
    	bfs[current].push_back(root);
    	while(!bfs[current].empty()) {
    		vector<int> tmp;
    		for(int i = bfs[current].size() - 1;i >= 0;i --) {
    			if(current == 0) {
    				if(bfs[current][i]->right != NULL) {
    					bfs[1 - current].push_back(bfs[current][i]->right);
    					tmp.push_back(bfs[current][i]->right->val);
    				}
    				if(bfs[current][i]->left != NULL) {
    					bfs[1 - current].push_back(bfs[current][i]->left);
    					tmp.push_back(bfs[current][i]->left->val);
    				}
    			} else {
    				if(bfs[current][i]->left != NULL) {
						bfs[1 - current].push_back(bfs[current][i]->left);
						tmp.push_back(bfs[current][i]->left->val);
					}
    				if(bfs[current][i]->right != NULL) {
						bfs[1 - current].push_back(bfs[current][i]->right);
						tmp.push_back(bfs[current][i]->right->val);
					}
    			}
    		}
    		if(!tmp.empty())
    			ans.push_back(tmp);
    		bfs[current].clear();
    		current = 1 - current;
    	}
    	return ans;
    }
};