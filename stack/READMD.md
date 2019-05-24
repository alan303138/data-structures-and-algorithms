stack為後進先出,Last in first out

有以下四種方法，皆為O(1)，不會用到任何loop
* push()，Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
* pop ()，Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
* peek()，peekPeek or Top: Returns top element of stack.
* isEmpty()，isEmpty: Returns true if stack is empty, else false

array版本可先設定滿為10，滿也是一個邊界條件

array實作參考文章
* [C infinite loop when char input instead of int](https://stackoverflow.com/questions/53056369/c-infinite-loop-when-char-input-instead-of-int)

* [Implementation of Stack Using Array in C](https://www.programming9.com/programs/c-programs/302-implementation-of-stack-using-array-in-c)