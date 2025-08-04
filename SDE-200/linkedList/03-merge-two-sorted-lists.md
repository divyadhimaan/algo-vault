# Merge Two Sorted Lists

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the `head` of the merged linked list.

## Approach 1: Using dummy node
`Analogy`: Like zipping two sorted queues together by always taking the smallest front element.

```cpp
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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* newHead = new ListNode(-1);
        ListNode* tail = newHead;

    
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                tail->next = list1;
                list1=list1->next;
            }else{
                tail->next = list2;
                list2=list2->next;
            }
            tail = tail->next;
        }

        if(list1)
            tail->next = list1;
        if(list2)
            tail->next = list2;

        return newHead->next;
    }
};
```

> Time Complexity: O(m+n)
>
> Space Complexity: O(1)

## Approach2: Recursive Merge

`Analogy`: Merge the smallest head first and let recursion handle the rest.

```cpp
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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1)
            return list2;
        if(!list2)
            return list1;

        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
            
    }
};
```

> Time Complexity: O(m+n)
>
> Space Complexity: O(m+n)
