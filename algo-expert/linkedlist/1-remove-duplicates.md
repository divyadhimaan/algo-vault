# Remove Duplicates from Linked List

You're given the head of a Singly Linked List whose nodes are in sorted order with respect to their values. Write a function that returns a modified version of the Linked List that doesn't contain any nodes with duplicate values. The Linked List should be modified in place (i.e., you shouldn't create a brand new list), and the modified Linked List should still have its nodes sorted with respect to their values.
Each LinkedList node has an integer value as well as a next node pointing to the next node in the list or to None / null if it's the tail of the list.

> Sample Input
> linkedList = 1 - 1 - 3 - 4 - 4 - 4 - 5 - 6 - 6 

> Sample Output
> 1 - 3 - 4 - 5 - 6 

## Solution 1: Hash set

- Use Hash set to store the discovered nodes
- If a value appears again → remove that node.

```cpp
#include <unordered_set>
using namespace std;

LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList) {
    if (!linkedList) return nullptr;

    unordered_set<int> seen;

    LinkedList* curr = linkedList;
    LinkedList* prev = nullptr;

    while (curr) {
        // If value already exists, remove node
        if (seen.count(curr->value)) {
            prev->next = curr->next;
        }
        // If first time seen
        else {
            seen.insert(curr->value);
            prev = curr;
        }

        curr = curr->next;
    }

    return linkedList;
}

```

> Time Complexity: O(n)
>
> Space Complexity: O(n)

## Solution 2: Two Pointers

- We use two pointers:
  - front → moves ahead and checks every node.
  - node → always stays at the last unique value we have kept.

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


## Solution 3: Single Pointer

- If the current node and the next node have the same value,
- just skip the next node.

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

  LinkedList* node = linkedList;

  while(node->next){
    if(node->value == node->next->value){
      node->next = node->next->next;
      continue;
    }
    node = node->next;
  }

  return linkedList;
}

```

> Time Complexity: O(n)
>
> Space Complexity: O(1)