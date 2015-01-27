/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
    	if(head == NULL || head->next == NULL) return head;
    	ListNode * p = head, * pNext = head, * tmp;
    	while(p != NULL){
    		pNext = p->next;
    		while(pNext != NULL && pNext->val == p->val) {
    			tmp = pNext;
    			pNext = pNext->next;
    			delete tmp;
    		}
    		p->next = pNext;
    		p = pNext;
    	}
    	return head;
    }
};