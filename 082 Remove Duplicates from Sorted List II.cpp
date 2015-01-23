/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * 
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
    	if(head == NULL || head->next == NULL)	return head;
    	ListNode *fakeHead = new ListNode(head->val + 1), *lastVal = NULL;
    	fakeHead->next = head;
    	for(ListNode *pTail = fakeHead, *pTmp; pTail->next != NULL;) {
    		pTmp = pTail->next;
    		if((pTmp->next != NULL && pTmp->next->val == pTmp->val)
    				|| (lastVal != NULL && lastVal->val == pTmp->val)) {
    			pTail->next = pTmp->next;
    			if(lastVal != NULL)	delete lastVal;
    			lastVal = pTmp;
    		} else {
    			pTail = pTail->next;
    		}
    	}
    	if(lastVal != NULL)	delete lastVal;
    	head = fakeHead->next;
    	delete fakeHead;
    	return head;
    }
};