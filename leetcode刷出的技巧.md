



## 链表修改当前节点
可以用指针的指针解决链表中无法修改当前指向的节点的问题。
一般的链表指针思路都是:
变量使用ListNode *:当访问当前节点的val时，该变量无法修改当前节点的被指向了，导致每次都要使用next判断提前处理。(如删除时)
当变量使用二级指针，可以方便的处理当前指针的全部内容，包括替换当前指针本身，(实际上是控制着上一个的next)，更加符合思路习惯。
如有序链表排序:
```
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
```

## 相和逼近
当找有序数组中俩项和等于/逼近某项时，可以使用如下方法。本质为贪心
```
        while (front < back) {
            int sum = num[front] + num[back];
            if (sum < target)
                front++;
            else if (sum > target)
                back--;
            else {
                //找到和=目标的了
```





