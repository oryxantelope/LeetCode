/**
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
    	ListNode *slow = head, *fast = head;
    	int length;
    	if(k == 0 || head == NULL)	return head;
    	for(length = 0, fast = head;fast != NULL && length < k;length ++) {
    		fast = fast->next;
    	}
    	if(fast == NULL) {
    		k = k % length;
    		if(k == 0)	return head;
        	for(length = 0, fast = head;fast != NULL && length < k;length ++) {
        		fast = fast->next;
        	}
    	}
    	while(fast->next != NULL) {
    		fast = fast->next;
    		slow = slow->next;
    	}
    	fast->next = head;
    	head = slow->next;
    	slow->next = NULL;
    	return head;
    }
};