# Middle Node

You're given a Linked List with at least one node. Write a function that returns the middle node of the Linked List. If there are two middle nodes (i.e. an even length list), your function should return the second of these nodes.
Each LinkedList node has an integer value as well as a next node pointing to the next node in the list or to None / null if it's the tail of the list.

> Sample Input
> linkedList = 2 → 7 -> 3 -> 5
> 
> Sample Output
> 3 → 5
> // The middle could be 7 or 3, we return the second middle node


## Solution 1: Find Length

- Find length
- Traverse till mid
- Needs 2 traversals

```cpp
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

int findLength(LinkedList* linkedList) {
  int counter=0;
  while(linkedList){
    counter++;
    linkedList=linkedList->next;
  }
  return counter;
}

LinkedList* middleNode(LinkedList* linkedList) {
  int len = findLength(linkedList);

  int mid = 0;
  if(len%2){
    mid = ceil(len/2);
  }else{
    mid = (len/2);
  }
  cout<<mid<<endl;

  LinkedList* node = linkedList;
  for(int i=0;i<mid;i++){
    node=node->next;
  }
  
  return node;
}

```

> Time Complexity: O(n)+O(n)=O(n)
>
> Space Complexity: O(1)

## Hare and Tortoise

- Make one pointer move slowly and another move twice as fast.
  - slow → moves 1 step
  - fast → moves 2 steps
- When fast reaches the end, slow will be at the middle.

```cpp

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* middleNode(LinkedList* linkedList) {
  LinkedList* fast = linkedList;
  LinkedList* slow = linkedList;

  while(fast->next && fast->next->next){
    slow = slow->next;
    fast = fast->next->next;
  }

  if(fast->next)
    slow=slow->next;
  return slow;
}
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)