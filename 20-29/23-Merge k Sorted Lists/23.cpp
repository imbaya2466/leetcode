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
	
	ListNode* mergeTwoList(ListNode *list1,ListNode *list2)
	{
		ListNode *ret=NULL;
		ListNode **pp_point=&ret;
		while(list1&&list2){
			if(list1->val>list2->val){
				*pp_point=list2;
				list2=list2->next;
			}else{
				*pp_point=list1;
				list1=list1->next;
			}
			pp_point=&((*pp_point)->next);
		}
		*pp_point=list1?list1:list2;
		return ret;
	}
		
	//how to partition is most important; no add&delete&move lists node will time
	//1 2 3 4 5 6 
    ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		int size=lists.size();
		for(int i=2;i<size*2;i+=i){
			for(int j=0;j<size;j+=i){
				lists[j]=mergeTwoList(lists[j],j+i/2>=size?NULL:lists[j+i/2]);
			}		
		}
		return lists.empty()?NULL:lists[0];
    }
};

int main()
{
	
}
