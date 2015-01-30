/**
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 * 
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
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
	vector<TreeNode *> generateTreesRecur(int begin, int end) {
		vector<TreeNode *> ans;
		if(begin == end) {
			ans.push_back(new TreeNode(begin));
		} else if (begin > end){
			ans.push_back(NULL);
		} else {
			for(int i = begin;i <= end;i ++) {
				TreeNode * root;
				vector<TreeNode *> left = generateTreesRecur(begin, i - 1);
				vector<TreeNode *> right = generateTreesRecur(i + 1, end);
				for(int m = 0; m < (int)left.size();m ++) {
					for(int n = 0;n < (int)right.size();n ++) {
						root = new TreeNode(i);
						root->left = left[m];
						root->right = right[n];
						ans.push_back(root);
					}
				}
			}
		}
		return ans;
	}
    vector<TreeNode *> generateTrees(int n) {
    	return generateTreesRecur(1, n);
    }
};