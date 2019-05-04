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
 // 1 2 3 4 5
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
  		ListNode *right=head,**left=&head;
  		while(n--){
  			right=right->next;
		}
  		while(right)
  		{
  			right=right->next;
			left=&((*left)->next);	
		}
		*left=(*left)->next;
		return head;
    }
};
int main(){
	
}
