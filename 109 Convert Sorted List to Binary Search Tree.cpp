/**
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
	TreeNode *sortedListToBST(ListNode * &head, int begin, int end) {
		if(begin > end)	return NULL;
		int mid = begin + (end - begin) / 2;
		TreeNode * left = sortedListToBST(head, begin, mid - 1);
		TreeNode * root = new TreeNode(head->val);
		head = head->next;
		root->left = left;
		root->right = sortedListToBST(head, mid + 1, end);
		return root;
	}
    TreeNode *sortedListToBST(ListNode *head) {
    	if(head == NULL)	return NULL;
    	int length = 0;
    	for(ListNode * p = head;p != NULL;p = p->next, length ++);
    	return sortedListToBST(head, 0, length - 1);
    }
};