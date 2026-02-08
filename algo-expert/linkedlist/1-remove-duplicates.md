# Remove Duplicates from Linked List

You're given the head of a Singly Linked List whose nodes are in sorted order with respect to their values. Write a function that returns a modified version of the Linked List that doesn't contain any nodes with duplicate values. The Linked List should be modified in place (i.e., you shouldn't create a brand new list), and the modified Linked List should still have its nodes sorted with respect to their values.
Each LinkedList node has an integer value as well as a next node pointing to the next node in the list or to None / null if it's the tail of the list.

> Sample Input
> linkedList = 1 - 1 - 3 - 4 - 4 - 4 - 5 - 6 - 6 

> Sample Output
> 1 - 3 - 4 - 5 - 6 


## Solution 1: Two Pointers

```cpp
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList) {
  if(!linkedList)
    return nullptr;

  LinkedList* front = linkedList->next;
  LinkedList* node = linkedList;

  while(front){
    if(front->value != node->value){
      node->next = front;
      node = front;
    }
    front = front->next;
  }

  node->next = front;
  return linkedList;
}

```

> Time Complexity: O(n)
> 
> Space Complexity: O(1)