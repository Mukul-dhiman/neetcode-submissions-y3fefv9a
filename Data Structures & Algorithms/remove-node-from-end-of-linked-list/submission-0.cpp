/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    int sizeofLL(ListNode* head){
	if(!head)	return 0;
	return 1+ sizeofLL(head->next);
}

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = sizeofLL(head);
	ListNode *prev = head, *del;

	if(sz == n)	return head->next;
	int prev_idx = sz - n - 1;
	while(prev_idx){
		prev = prev->next;
        prev_idx--;
	}
	del = prev->next;
	prev->next = del->next;
	del->next = NULL;
	delete del;
	return head;

    }
};
