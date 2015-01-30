/**
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
	void inOrderTravel(TreeNode *root, TreeNode **first, TreeNode **second, TreeNode **last) {
		if(root == NULL)	return ;
		inOrderTravel(root->left, first, second, last);
		// 当发现此元素比已序列化的最后一个元素还小的时候（非正常现象）
		if(*last != NULL && (*last)->val > root->val) {
			if(*first != NULL) {
				*second = root;
			} else {
				// 第一次发现非正常位置元素
				*first = *last;
				// 特判当仅有两个元素的时候
				*second = root;
			}
		}
		// last 指向中序遍历序列化过程中的最后一个已序列化元素，亦即之后所有元素理应都比此元素大
		*last = root;
		inOrderTravel(root->right, first, second, last);
	}
    void recoverTree(TreeNode *root) {
    	TreeNode *first = NULL, *second = NULL, *last = NULL;
    	// 中序遍历，在非递减有序序列中交换了两个数的位置，找出这两个数并恢复有序序列
    	inOrderTravel(root, &first, &second, &last);
    	swap(first->val, second->val);
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
	void inOrderTravel(TreeNode *root, TreeNode **first, TreeNode **second) {
		//Initialize current as root
		TreeNode * current = root, *pre = NULL, *tmp;
		//While current is not NULL
		while(current != NULL) {
			if(current->left == NULL) {
				//If current does not have left child
				//Go to the right, i.e., current = current->right
				pre = current;
				current = current->right;
			} else {
				for(tmp = current->left;tmp->right != NULL && tmp->right != current;tmp = tmp->right);
				if(tmp->right == NULL) {
					//Make current as right child of the rightmost node in current's left subtree
					tmp->right = current;
					//Go to this left child, i.e., current = current->left
					current = current->left;
				} else {
					tmp->right = NULL;
					pre = current;
					current = current->right;
				}
			}
			if(pre != NULL && current != NULL && pre->val > current->val) {
				if(*first != NULL) {
					*second = current;
				} else {
					*first = pre;
					*second = current;
				}
			}
		}
	}
    void recoverTree(TreeNode *root) {
    	TreeNode *first = NULL, *second = NULL;
    	inOrderTravel(root, &first, &second);
    	swap(first->val, second->val);
    }
};