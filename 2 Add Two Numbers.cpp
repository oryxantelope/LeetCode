/**
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	ListNode * sum = NULL;
    	ListNode * tail = NULL;
    	int nTakeOver = 0;
    	while(l1 != NULL || l2 != NULL) {
    		if(sum == NULL) {
    			sum = new ListNode(0);
    			tail = sum;
    		} else {
    			tail->next = new ListNode(0);
    			tail = tail->next;
    		}
    		if(l1 != NULL) {
    			tail->val += l1->val;
    			l1 = l1->next;
    		}
    		if(l2 != NULL) {
    			tail->val += l2->val;
    			l2 = l2->next;
    		}
    		tail->val += nTakeOver;
    		nTakeOver = tail->val / 10;
    		tail->val = tail->val % 10;
    	}
    	if(nTakeOver != 0) {
    		tail->next = new ListNode(0);
    		tail = tail->next;
    		tail->val = nTakeOver;
    	}
    	return sum;
    }
};