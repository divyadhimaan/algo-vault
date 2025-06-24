# Reverse Nodes in k-Group
Practice [Here](https://leetcode.com/problems/reverse-nodes-in-k-group/description/)

Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return the modified list.

`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.


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
    ListNode* reverse(ListNode* node){
        ListNode* p = node;
        ListNode* q = node;
        ListNode* r = NULL;

        while(p)
        {
            q = p;
            p=p->next;
            q->next = r;
            r = q;
        }
        return q;
    }

    ListNode* getKth(ListNode* curr, int k)
    {
        k--;
        while(curr && k>0)
        {
            curr=curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(k==1)
            return head;

        ListNode* currNode = head, *prevNode=NULL;
        while(currNode)
        {
            ListNode* kth = getKth(currNode, k);
            
            if(!kth){
                if(prevNode)
                    prevNode->next = currNode;
                break;
            }

            ListNode* nextNode = kth->next;
            kth->next = NULL;

            reverse(currNode);

            if(currNode==head)
                head=kth;
            else
                prevNode->next = kth;

            prevNode = currNode;
            currNode = nextNode;
        }
        return head;
    }
};
```

| Metric           | Value  | Notes                                           |
| ---------------- | ------ | ----------------------------------------------- |
| Time Complexity  | `O(n)` | Each node is visited a constant number of times |
| Space Complexity | `O(1)` | In-place reversal, no recursion                 |
