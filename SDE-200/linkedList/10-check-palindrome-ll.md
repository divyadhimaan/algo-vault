# Check if LL is palindrome or not
Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. Check whether the linked list values form a palindrome or not. Return true if it forms a palindrome, otherwise, return false.

A palindrome is a sequence that reads the same forward and backwards.


## Naive Approach

- Convert to string
- Check for palindrome
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

    bool isPalindromeStr(string str){
        int n = str.length();

        for(int i=0;i<n/2;i++){
            if(str[i]!=str[n-i-1])
                return false;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        string str = "";

        while(head){
            str += head->val;
            head=head->next;
        }

        if(isPalindromeStr(str))
            return true;
        return false;
    }
};
```

> Time Complexity:O(n) to traverse the linked list and build the string, and O(n/2) which simplifies to O(n) to check if the string is a palindrome, so the total time complexity is O(n) + O(n) = O(n).
>
> Space Complexity:O(n) to store the string representation of the linked list.

## Better Approach

- Find the middle node (slow-fast pointers)
- Reverse second half
- Compare halves

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

    ListNode* reverseList(ListNode* head) {
        ListNode* frontNode = head;
        ListNode* node = head;
        ListNode* tailNode = NULL;

        while(frontNode){
            node = frontNode;
            frontNode = frontNode->next;
            node->next = tailNode;
            tailNode = node;
        }
        return tailNode;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;

        while(fastPointer && fastPointer->next)
        {
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;
        }

        if (fastPointer != NULL) {
            slowPointer = slowPointer->next;
        }

        ListNode* secondHead = reverseList(slowPointer);

        while(secondHead){
            if(head->val != secondHead->val)
                return false;

            head=head->next;
            secondHead = secondHead->next;
        }
        return true;
    }
};
```
> Time Complexity:The time complexity is O(n) because the code iterates through the linked list multiple times: once to find the middle (O(n/2)), once to reverse the second half (O(n/2)), and once to compare the first and reversed second half (O(n/2)). Summing up all the terms gives O(n).
>
> Space Complexity:The space complexity is O(1) because the reversal is done in place with only a few extra pointer variables. The reverseList function uses O(1) space and the isPalindrome function uses O(1) space.
