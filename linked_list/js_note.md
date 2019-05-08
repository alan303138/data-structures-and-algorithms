from https://medium.com/@nicehorse06/javascript-algorithms-linked-list-b0f80e49a5c6
本篇紀錄自 trekhleb/javascript-algorithms/linked-list

linked list 為一線性元素的集合，排列的順序不是依照著記憶體位置的順序，而是藉由每一個元素指向下一個，linked list的新增和移除元素都非常的高效，但如果要檢視其中元素的時間為線性的，array 資料結構的檢視效能會比 linked list 好．

LinkedListNode
一開始先建立一個基本 node 的 class 資料結構 LinkedListNode，可設定該 node 的value和 next 去指定下一個 node，這裡next 設定了預設值 null 來檢視只有一個 node 而沒有 next的特殊狀況:
```
class LinkedListNode {
  constructor(value, next = null) {
    this.value = value;
    this.next = next;
  }
toString(callback) {
    return callback ? callback(this.value) : `${this.value}`;
  }
}
```
LinkedList
建立 class LinkedList，記錄了整個鏈結串列的頭尾 node 和所有操作的方法，在 constructor 中設定 head 和 tail 的 node，還有compare 目的是為了比較值的大小，this.compare(a, b) 如此可比較a b的大小．
```
export default class LinkedList {

  constructor(comparatorFunction) {
    /** @var LinkedListNode */
    this.head = null;
    /** @var LinkedListNode */
    this.tail = null;
    this.compare = new Comparator(comparatorFunction);
  }
```
LinkedList的所有方法
* prepend 從前新增node
* append 從後新增node
* delete 刪除對應到值的 node
* find 找到對應值的 node
* deleteTail 刪除 tail node
* deleteHead 刪除 head node
* toArray 輸出為 array

prepend
在 LinkedList 新增 prepend 方法加入一個 node，目的為在 head 前新增一個node 成為新的 head，結束後回傳新的 LinkedList．

```
/**
   * @param {*} value
   * @return {LinkedList}
   */
  prepend(value) {
    // 新增一個 node 到 head，並把舊 head 存到新 node 的 next值
    this.head = new LinkedListNode(value, this.head);
    return this;
  }
```

append
在LinkedList 新增 append 的方法加入一個node，目的為在tail後新增一個node成為新的 tail ，最後回傳新的 LinkedList，需判斷情況如下：


沒有 head 的情形
其他有 head 的情形
```
/**
   * @param {*} value
   * @return {LinkedList}
   */
  append(value) {
    const newNode = new LinkedListNode(value);
    // 判斷如果沒有 head 則把此 node 指定為 head 跟 tail
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
      return this;
    }
    // 先把新 node 放到舊 node 的 next，再把新 node 指定為新 node
    this.tail.next = newNode;
    this.tail = newNode;
    return this;
  }
```


delete
在LinkedList 新增 delete 的方法刪除第一個 node，其value 等同於 delete參數所帶入的 value的項，最後回傳被刪除的項，遇到的情況有以下可能:

沒有 head
head 即為被刪除項
被刪除的值非 head 則用迴圈一直往下一個找
tail 為被刪除的項時

```
  /**
   * @param {*} value
   * @return {LinkedListNode}
   */
  delete(value) {
    // 如果沒有 head 則不動作，返回 null
    if (!this.head) {
      return null;
    }
    // deletedNode 記錄著被刪除的 node，可在之後回傳
    let deletedNode = null;
    // 如果 head 被刪除，則令第二項為 新的 head
    if (this.compare.equal(this.head.value, value)) {
      deletedNode = this.head;
      this.head = this.head.next;
    }
    // 之後會做 while 迴圈去比對currentNode 的 value，currentNode 從   head 開始
    let currentNode = this.head;
    if (currentNode !== null) {
      // 如果下一個不是被刪除的項，則比對下下個，一但下一項比對到了，就把該項存 到deletedNode，並把下下項取代下一項．
      while (currentNode.next) {
        if (this.compare.equal(currentNode.next.value, value)) {
          deletedNode = currentNode.next;
          currentNode.next = currentNode.next.next;
        } else {
          currentNode = currentNode.next;
        }
      }
    }
   // 確認如果是 tail 項被刪除的情況.
    if (this.compare.equal(this.tail.value, value)) {
      this.tail = currentNode;
    }
    // 回傳被刪除的項
    return deletedNode;
  }
```


find
LinkedList 新增 find 方法，參數一個key有value或callback的物件，用迴圈往下找出等同於參數 value 或是符合 callback 所找的node 值，並回傳該 node，有以下可能：

有沒有 head
在 while 中判斷有無 callback ，並比對currentNode
在 while 中判斷有無 value，用 value 判斷是否等同於 currentNode

```
   /**
   * @param {Object} findParams
   * @param {*} findParams.value
   * @param {function} [findParams.callback]
   * @return {LinkedListNode}
   */
find({ value = undefined, callback = undefined }) {
    // 如果沒有 head 值，則直接回傳null
    if (!this.head) {
      return null;
    }
   let currentNode = this.head;
   //用 while 用 callback 和 value 對 currentNode 做比對，如果有比對到則回傳該值
   while (currentNode) {
      // 如果有 callback，且符合callback比對則回傳此node
      if (callback && callback(currentNode.value)) {
         return currentNode;
      }
     // 如果有給定 value，則尋找等同此 value 的 node
      if (value !== undefined &&          this.compare.equal(currentNode.value, value)) {
       return currentNode;
       }
      // currentNode 不斷的找下一項，直到null
      currentNode = currentNode.next;
   }
   return null;
}
```

deleteTail
LinkedList 的 deleteTail方法，為找出tail刪除之，並指定tail的上一個node為新的tail，由於此為單向LinkedList，只能由head開始用while往下找next來判斷tail．

刪除tail的方法為把tail的上項node的next設為null並設該node為tail，最後回傳被刪除的tail．

以下為需要判斷的可能：

確定head是否為tail
在while迴圈判斷currentNode的下下項是否為null來找tail

```
   /**
   * @return {LinkedListNode}
   */
deleteTail() {
    //如果head即為tail，則刪除兩者，令head和tail為null
    if (this.head === this.tail) {
      const deletedTail = this.tail;
      this.head = null;
      this.tail = null;
      return deletedTail;
    }
    // 把tail存到deletedTail回傳用，再用while從head開使找tail，找到該node的下下項為null時，即可知下一項為tail，把找到的node的next指定為null來刪除舊tail，並把該node指定為新的tail．
    const deletedTail = this.tail;    
    let currentNode = this.head;
    while (currentNode.next) {
      if (!currentNode.next.next) {
        currentNode.next = null;
      } else {
        currentNode = currentNode.next;
      }
    }
    this.tail = currentNode;
    return deletedTail;
}
```



deleteHead
LinkedList 的 deleteHead方法，刪除Head項，並指定第二項為新的 head．

刪除head的方法為直接把head.next 指定為新的head，最後回傳被刪除的head．

以下為需要判斷的可能：

確定head是否為null
確定head的下一項是否為 nul，判斷head是否同時為tail


```
  /**
   * @return {LinkedListNode}
   */
deleteHead() {
    //如果head為空代表整個linked為空，回傳null
    if (!this.head) {
      return null;
    }
    const deletedHead = this.head;
    // 如果 head.next(第二個node)有值，代表head不是tail，則把第二個node指定為新的head，
    //如果 head.next 為 null 表示 head同時為tail，需同時刪除，指定為null．
    if (this.head.next) {
      this.head = this.head.next;
    } else {
      this.head = null;
      this.tail = null;
    }
    return deletedHead;
}

```

```
toArray
LinkedList 的 toArray方法，把LinkedList輸出為 Array．建立一空array從head開始做迴圈到tail，把每一項push到該array，最後回傳array．

/**
   * @return {LinkedListNode[]}
   */
  toArray() {
    const nodes = [];
    let currentNode = this.head;
    while (currentNode) {
      nodes.push(currentNode);
      currentNode = currentNode.next;
    }
    return nodes;
  }
```