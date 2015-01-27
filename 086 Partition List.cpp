/**
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
    	if(head == NULL || head->next == NULL)	return head;
    	ListNode *ans = NULL, *tail = head, *next, *before = head;
    	while(head != NULL) {
    		next = head->next;
    		if(head->val < x) {
    			if(ans == NULL) {
    				ans = head;
    				if(head != tail) {
    					before->next = head->next;
    					head->next = tail;
    				}
    				tail = head;
    			} else {
    				before->next = head->next;
    				head->next = tail->next;
    				tail->next = head;
    				tail = head;
    				if(before->next == head)
    					before = head;
    			}
    		} else {
    			before = head;
    		}
    		head = next;
    	}
    	if(ans != NULL)
    		return ans;
    	else
    		return tail;
    }
};