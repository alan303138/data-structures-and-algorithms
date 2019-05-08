本篇紀錄自 trekhleb/javascript-algorithms/Queue
from https://medium.com/@nicehorse06/js-%E8%B3%87%E6%96%99%E7%B5%90%E6%A7%8B-queue-ca85bee7c0c3

## Queue 為一種先進先出(FIFO)的列隊資料結構，新增資料時會放在列隊的後方，移出資料時會從前方的舊資料開始移除．

用到的方法有：
* linkedList，使用linkedList 的方法來實作 Queue
* isEmpty，檢查 tail 是否為空
* peek，不移除任何項，回傳 queue 前端的第一項
* enqueue，增加一個node到queue的後方
* dequeue，移除一個node自queue的前方

```
import LinkedList from '../linked-list/LinkedList';
export default class Queue {
  constructor() {
    this.linkedList = new LinkedList();
  }
  isEmpty() {
    return !this.linkedList.tail;
  }
  peek() {
     if (!this.linkedList.head) {
        return null;
     }
     return this.linkedList.head.value;
  }
  enqueue(value) {
     this.linkedList.append(value);
  }
  dequeue() {
     const removedHead = this.linkedList.deleteHead();
     return removedHead ? removedHead.value : null;
  }
  toString(callback) {
    return this.linkedList.toString(callback);
  }
}
```