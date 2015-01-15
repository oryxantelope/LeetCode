/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * 
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * 
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * 
 * Only constant memory is allowed.
 * 
 * For example,
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k) {
    	if(head == NULL || head->next == NULL || k == 1)	return head;
    	ListNode *fakeHead = new ListNode(0), *pBefore = fakeHead, *pNode, *pEnd, *pTail = NULL;
    	int i;
    	fakeHead->next = head;
    	do {
    		for(i = 0, pEnd = pBefore;i < k && pEnd != NULL; pEnd = pEnd->next, i++);
    		if(pEnd != NULL) {
    			pTail = pBefore->next;
    			pEnd = pEnd->next;
    			for(pNode = pTail->next; pNode != pEnd; pNode = pTail->next) {
    				pTail->next = pNode->next;
    				pNode->next = pBefore->next;
    				pBefore->next = pNode;
    			}
    			pBefore = pTail;
    		} else {
    			pBefore = NULL;
    		}
    	} while(pBefore != NULL && pBefore->next != NULL);
    	head = fakeHead->next;
    	delete fakeHead;
    	return head;
    }
};