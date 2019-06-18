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
 //超时，因为k可以给的非常大 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if(!head||!head->next) return head;
        ListNode* now=head;
        bool flag=false;
        ListNode** head2=NULL;
        for(int i=0;i<k;i++){
        	if(!now->next){
        		flag=true;
        		now->next=head;
        		head2=&now->next;
			}
			now=now->next;
		}
		if(!flag){
			ListNode* ls=now;
			while(ls->next){
				ls=ls->next;
			}
			ls->next=head;
			head2=&ls->next;
		}
		
		while(now!=head){
			now=now->next;
			head2=&(*head2)->next;
		}
		ListNode* ret=*head2;
		*head2=NULL;
		return ret;
    }
};

//正确的做法 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        //计算长度 
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

		//取余移动 
        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};


int main(){
	
}







