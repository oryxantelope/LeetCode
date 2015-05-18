/**
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example,
 * Given
 * 
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 * click to show hints.
 * 
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
	TreeNode * flattenNode(TreeNode *root) {
		if(root == NULL)	return NULL;
		TreeNode *node = flattenNode(root->left);
		TreeNode *tail = flattenNode(root->right);
		if(node != NULL) {
			node->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		return (tail != NULL) ? tail : ((node != NULL) ? node : root);
	}
    void flatten(TreeNode *root) {
    	flattenNode(root);
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
    void flatten(TreeNode *root) {
    	TreeNode * leftNode, * rightNode;
    	while(root != NULL) {
    		leftNode = root->left;
    		rightNode = root->right;
    		if(leftNode == NULL) {
    			root = rightNode;
    		} else {
    			root->right = leftNode;
    			root->left = NULL;
    			while(root->right != NULL)
    				root = root->right;
    			root->right = rightNode;
    			root = leftNode;
    		}
    	}
    }
};