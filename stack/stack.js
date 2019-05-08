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