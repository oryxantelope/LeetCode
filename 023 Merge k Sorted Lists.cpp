/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
	static bool cmp(ListNode *e1, ListNode *e2) {
		return e1->val > e2->val;
	}
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	if(lists.size() == 0)	return NULL;
    	ListNode *dummyHead = new ListNode(-1), *tail = dummyHead;
    	vector<ListNode *> heap;
    	for(int i = 0;i < (int)lists.size();i ++) {
    		if(lists[i] != NULL)
    			heap.push_back(lists[i]);
    	}
    	if(heap.size() == 0) {
    		delete dummyHead;
    		return NULL;
    	}
    	make_heap(heap.begin(), heap.end(), cmp);
    	while(!heap.empty()) {
    		tail->next = heap.front();
    		tail = tail->next;
    		pop_heap(heap.begin(), heap.end(), cmp);
    		heap.pop_back();
    		if(tail->next != NULL) {
    			heap.push_back(tail->next);
    			push_heap(heap.begin(), heap.end(), cmp);
    		}
    	}
    	tail->next = NULL;
    	tail = dummyHead->next;
    	delete dummyHead;
    	return tail;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
	ListNode *mergeLists(ListNode *list1, ListNode *list2) {
		ListNode *dummyHead = new ListNode(0), *tail = dummyHead;
		while(list1 != NULL || list2 != NULL) {
			if(list1 == NULL) {
				tail->next = list2;
				tail = tail->next;
				break;
			}
			if(list2 == NULL) {
				tail->next = list1;
				tail = tail->next;
				break;
			}
			if(list1->val < list2->val) {
				tail->next = list1;
				list1 = list1->next;
			} else {
				tail->next = list2;
				list2 = list2->next;
			}
			tail = tail->next;
		}
		tail = dummyHead->next;
		delete dummyHead;
		return tail;
	}
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	if(lists.size() == 0)	return NULL;
    	if(lists.size() == 1)	return lists[0];
    	queue<ListNode *> q;
    	ListNode *list1, *list2;
    	for(int i = 0;i < (int)lists.size();i ++)
    		q.push(lists[i]);
    	while(q.size() > 1) {
    		list1 = q.front();
    		q.pop();
    		list2 = q.front();
    		q.pop();
    		q.push(mergeLists(list1, list2));
    	}
    	return q.front();
    }
};