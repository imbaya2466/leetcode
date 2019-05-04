#incldue <bits/stdc++.h>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode *ret=NULL;
    	ListNode **pplistnode=&ret;
    	while(l1&&l2){
    		if(l1->val>l2->val){
    			*pplistnode=l2;
    			l2=l2->next;
			}else{
				*pplistnode=l1;
				l1=l1->next;
			}
			pplistnode=&((*pplistnode)->next);
		}
		*pplistnode=l1?l1:l2;
		return ret;
    }
};
int main()
{
	
}
