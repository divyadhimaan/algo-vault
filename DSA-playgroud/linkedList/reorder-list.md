# Reorder List

Practice [here](https://leetcode.com/problems/reorder-list/description/)

You are given the head of a singly linked-list. The list can be represented as:

```L0 → L1 → … → Ln - 1 → Ln```
Reorder the list to be on the following form:

```L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …```
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

## Intituion

1. Find the Middle of the List:
   - Use slow and fast pointers to find the middle node.
   - This divides the list into two halves.
2. Reverse the Second Half: Reverse the second half of the list (from middle to end).
   - Now you have two lists:
     - First half in original order.
     - Second half in reverse.
3. Merge Both Halves Alternately: Merge nodes from both halves:
   - Pick one node from the first half, then one from the second half, and continue alternately.

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


    ListNode* reverse(ListNode* head)
    {
        ListNode* frontNode = head;
        ListNode* node = head;
        ListNode* rearNode = NULL;

        while(frontNode){
            node = frontNode;
            frontNode = frontNode->next;
            node->next = rearNode;
            rearNode = node;
        }
        return node;
    }

    void mergeTwoListAlternatively(ListNode* first, ListNode* sec)
    {

        while(first && sec){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = sec->next;


            first->next = sec;
            if(!tmp1)
                break;
            sec->next = tmp1;

            first=tmp1;
            sec=tmp2;
        }
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = reverse(slow->next);
        slow->next = NULL;


        mergeTwoListAlternatively(head, second);
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)