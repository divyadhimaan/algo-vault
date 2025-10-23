# Find the intersection point of Y LL


## With count nodes

```cpp
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

    int CountNodes(ListNode* head)
    {
        if(!head)
            return 0;
        return 1 + CountNodes(head->next);
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* p = headA;
        ListNode* q = headB;

        if(!p || !q)
            return NULL;

        int count1 = CountNodes(p);
        int count2 = CountNodes(q);

        int d= abs(count1-count2);

        if(count1>count2)
        {
            while(d--)
                p=p->next;
        }else{
            while(d--)
                q=q->next;
        }


        while(p && q && p!=q)
        {
            p=p->next;
            q=q->next;
        }
        if(p==q)
            return q;
        return NULL;
    }
};
```

> Time Complexity:O(m + n), where m and n are the lengths of the two linked lists because the CountNodes function traverses each list once, and the final while loop can iterate at most min(m, n) times.
>
> Space Complexity:O(m + n) due to the recursive calls of CountNodes function which can go upto the size of linked lists in worst case.

## With two pointers

```cpp
/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pointerOne = headA;
        ListNode* pointerTwo = headB;

        while(pointerOne != pointerTwo){
            pointerOne = pointerOne ? pointerOne->next : headB;
            pointerTwo = pointerTwo ? pointerTwo->next : headA;
        }

        return pointerTwo;

    }
};
```

> Time Complexity:O(m+n) where m and n are the lengths of the two linked lists.
> 
> Space Complexity:O(1) because it uses a constant amount of extra space.