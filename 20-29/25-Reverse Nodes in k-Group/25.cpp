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
// 1 2 3 4 5 6
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL||k==1) return head;
        int num=1;
        ListNode **pre = &head;
        ListNode *cur = *pre, *nex;
        while(cur = cur->next) 
            num++;
        while(num>=k) {
            cur = *pre;
            nex = cur->next;
            for(int i=1;i<k;++i) {
                cur->next=nex->next;
                nex->next=*pre;
                *pre=nex;
                nex=cur->next;  
            }
            pre = &(cur->next);
            num-=k;
        }
        return head;
    }
};

int main(){
	
}
