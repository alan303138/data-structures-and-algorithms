本篇紀錄自 trekhleb/javascript-algorithms/Stack
from https://medium.com/@nicehorse06/js-%E8%B3%87%E6%96%99%E7%B5%90%E6%A7%8B-stack-3208e13f5ad5

### Stack 為一個元素集合的抽象資料結構，遵守後進先出的原則，我們可以很方便地查看最上層的元素，但如果要取用較深層的元素則須先移除數個上層元素．

主要實作了以下的方法：

* push：增加一個元素到集合裡
* pop：移除最近一個增加還沒有被移除的元素
* peek：可以查看最上層的元素，而不會移除
* isEmpty：確認最上層的元素是否為空來判斷整個stack的狀態

```
import LinkedList from '../linked-list/LinkedList';
export default class Stack {
  constructor() {
    // 以LinkedList來實作方法
    this.linkedList = new LinkedList();
  }
   /**
   * @return {boolean}
   */
  isEmpty() {
    return !this.linkedList.tail;
  }
   /**
   * @return {*}
   */
  peek() {
    if (this.isEmpty()) {
      return null;
    }
    return this.linkedList.tail.value;
  }
   /**
   * @param {*} value
   */
  push(value) {
    this.linkedList.append(value);
  }
   /**
   * @return {*}
   */
  pop() {
    const removedTail = this.linkedList.deleteTail();
    return removedTail ? removedTail.value : null;
  }
   /**
   * @return {*[]}
   */
  toArray() {
    return this.linkedList
      .toArray()
      .map(linkedListNode => linkedListNode.value)
      .reverse();
  }
}
```
