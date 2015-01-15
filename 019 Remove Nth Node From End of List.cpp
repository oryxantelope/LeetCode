/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 * 
 *    Given linked list: 1->2->3->4->5, and n = 2.
 * 
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	if(head == NULL)	return head;
    	if(head->next == NULL && n == 1) {
    		delete head;
    		head = NULL;
    		return head;
    	}
    	queue<ListNode *> q;
    	ListNode *pNode = head;
    	for(;pNode != NULL; pNode = pNode->next) {
    		q.push(pNode);
    		if((int)q.size() >  n + 1)
    			q.pop();
    	}
    	if((int)q.size() == n) {
    		pNode = head;
    		head = head->next;
    		delete pNode;
    		pNode = NULL;
    	} else {
    		pNode = q.front();
    		ListNode *tmp = pNode->next;
    		pNode->next = tmp->next;
    		delete tmp;
    		tmp = NULL;
    	}
    	return head;
    }
};