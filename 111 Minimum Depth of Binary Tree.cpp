/**
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
    	if(root == NULL)	return 0;
    	queue<TreeNode *> q[2];
    	int current = 0, depth = 1;
    	TreeNode *pNode;
    	q[current].push(root);
    	while(!q[current].empty()) {
    		pNode = q[current].front();
    		q[current].pop();
    		if(pNode->left == NULL && pNode->right == NULL) {
    			return depth;
    		}
    		if(pNode->left != NULL)
    			q[1 - current].push(pNode->left);
    		if(pNode->right != NULL)
    			q[1 - current].push(pNode->right);
    		if(q[current].empty()) {
    			current = 1 - current;
    			depth ++;
    		}
    	}
    	return depth;
    }
};