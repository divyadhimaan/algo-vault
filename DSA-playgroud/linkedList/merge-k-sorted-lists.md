# Merge k Sorted Lists 

Practice [here](https://leetcode.com/problems/merge-k-sorted-lists/)
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.


## Brute Force

`Analogy`: Like stacking books one at a time: merge the first two piles into one, then merge the next pile onto it, and so on. Each merge grows heavier and slower as the pile grows.

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

    ListNode* merge2Lists(ListNode* head1, ListNode* head2)
    {
        if(!head1)
            return head2;
        if(!head2)
            return head1;
        ListNode* head = NULL;

        if(head1->val < head2->val){
            head = head1;
            head->next = merge2Lists(head1->next, head2);
        }
        else{
            head = head2;
            head->next = merge2Lists(head1, head2->next);
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;

        if(lists.size() == 1)
            return lists[0];

        ListNode* res = lists[0];
        for(int i=1;i<lists.size();i++)
        {
            res = merge2Lists(res, lists[i]);
        }
        return res;
    }
};
```


## Optimal Approach

`Analogy`: Like having K checkout lines: you always take the smallest item from the front of all lines using a priority queue.

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


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;

        if(lists.size() == 1)
            return lists[0];

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }

        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        while(!pq.empty())
        {
            ListNode* curr = pq.top().second;
            tail->next = curr;
            pq.pop();

            if(curr->next)
                pq.push({curr->next->val, curr->next});

            tail=tail->next;
        }
        return head->next;
    }
};
```


## Comparison

| Approach                 | Time Complexity | Space Complexity            | Analogy                                      |
| ------------------------ | --------------- | --------------------------- | -------------------------------------------- |
| Sequential Merge (Brute) | O(N·K)          | O(1) extra + O(N) recursion | Stack books one pile at a time               |
| Min-Heap (Optimal)       | O(N log K)      | O(K)                        | Take the smallest front item from all queues |
