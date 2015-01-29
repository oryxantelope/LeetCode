/**
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * 
 * return 1->4->3->2->5->NULL.
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    	if(head == NULL || head->next == NULL || m == n)	return head;
    	ListNode *pBegin = head, *pHead, *pTail, *pTmp;
    	for(int i = 2;i < m;i ++) {
    		pBegin = pBegin->next;
    	}
    	pHead = (m == 1) ? head : pBegin->next;
    	pTail = pHead->next;
    	for(int i = m + 2;i <= n;i ++) {
    		pTmp = pTail->next;
    		pTail->next = pTmp->next;
    		pTmp->next = pHead->next;
    		pHead->next = pTmp;
    	}
    	if(m == 1) {
    		pBegin = pHead->next;
    	} else {
    		pBegin->next = pHead->next;
    	}
    	pHead->next = pTail->next;
    	pTail->next = pHead;
    	return (m == 1) ? pBegin : head;
    }
};
