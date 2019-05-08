#include <bits/stdc++.h>
using namespace std;

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
    ListNode* swapPairs(ListNode* head) {
        ListNode **ppnode=&head;
        while(*ppnode&&(*ppnode)->next){
        	ListNode *pnow=*ppnode;
        	ListNode *pnext=(*ppnode)->next;
        	*ppnode=pnext;
        	pnow->next=pnext->next;
        	pnext->next=pnow;
        	ppnode=&(pnow->next);
		}
		return head;
    }
};
int main()
{
	
}
