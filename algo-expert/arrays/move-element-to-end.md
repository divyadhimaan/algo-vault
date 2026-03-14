# Move Element to end

```cpp
#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  int size = array.size();
  int movingPointer=0, pointer=0;

  for(;movingPointer<size; movingPointer++){
    if(array[movingPointer] != toMove){
      array[pointer] = array[movingPointer];
      pointer++;
    }
  }

  for(int x = pointer;x<size;x++){
    array[x] = toMove;
  }
  
  return array;
}

```