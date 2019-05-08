本篇紀錄自:

from https://medium.com/@nicehorse06/js-%E8%B3%87%E6%96%99%E7%B5%90%E6%A7%8B-hash-table-9eed0e7b6f46

1. trekhleb/javascript-algorithms/hash-table

2. Second Round — Hash Table：Intro(簡介)

如果我們想要讀取儲存的資料時間複雜度都在O(1)，最適合的方式是用到Array，把Key當作array的index，value儲存到array，這樣稱為Direct Access Table，但這樣的實作有缺點，如果key範圍很大，但數量很少，無法讓key連續而浪費記憶體空間．

hash-table解決了浪費記憶體空間的問題，能把放資料的table大小壓縮至接近真正需要放進table資料的數量．為了達到這個目標引入了hash function，公式為 index=h(Key)，可以把原本雜散的key對應到 hash table的 緊湊有順序的index，但Hash function不是完美的，有時候會發生不同key 對應到相同index的情形，稱為collision．

Collision的解決方法有二：

1.Chaining：使用Linked list把「Hashing到同一個slot」的資料串起來。

2. Open Addressing：使用Probing Method來尋找Table中「空的slot」存放資料。

class HashTable 實作了以下方法：

* hash：把key經過一個演算法轉換成對應的hash table index
* insert：把key的值放入到 hash table中對應的index欄位(bucket)
* delete：刪除 hash table中經key所對應的index欄位
* get: 找出key所對應的index欄位值

```
import LinkedList from '../linked-list/LinkedList';
const defaultHashTableSize = 32;
class HashTable {
  constructor(hashTableSize = defaultHashTableSize) { 
    // 填充出等於hashTableSize大小的array，並在讓個欄位實作空LinkedList
    this.buckets = Array(hashTableSize).fill(null).map(() => new LinkedList());
   }

}
```
hash 方法，把 key 轉換成 hash table index．

```
hash(key) {
   // 藉由把 key 中的每一項轉換成 key code 加起來得到 hash值
   const hash = Array.from(key).reduce(
      (hashAccumulator, keySymbol) => (hashAccumulator + keySymbol.charCodeAt(0)),
      0,
    );
// 減少 hash number的數量，得到符合 hash table的大小的index
    return hash % this.buckets.length;
  }

```
insert 方法 ，先用hash(key) 去找出table中的index，再新增或是更改該位置的值

```
insert(key, value) { 
    // 把key對應到的table index裡的 linked list實例取出
    const bucketLinkedList = this.buckets[this.hash(key)];
    // 帶入匿名函式到 linked list的 find，尋找該 key有無儲存該index
    const node = bucketLinkedList.find({ callback: nodeValue => nodeValue.key === key });
    //如果沒有儲存則新增一項，如果有則更新該key的value值
   if (!node) {
      // Insert new node.
      bucketLinkedList.append({ key, value });
    } else {
      // Update value of existing node.
      node.value.value = value;
    }
 }

```

delete 方法，找出該key在table上的位置，如果存在則刪除並回傳，沒有則傳null．
```
delete(key) {
    
    // 用hash(key)找出index，回傳linked list
    const bucketLinkedList = this.buckets[this.hash(key)]; 
    //帶入匿名函式找出該key有無存在於該index
    const node = bucketLinkedList.find({ callback: nodeValue => nodeValue.key === key });
// 如果有則刪除，並回傳
if (node) {
      return bucketLinkedList.delete(node.value);
    }
return null;
  }
```
get 方法，找出該key在table上的位置，如果存在則回傳值，沒有則傳null．

```
get(key) {
    
    // 用hash(key)找出index，回傳linked list
    const bucketLinkedList = this.buckets[this.hash(key)]; 
    //帶入匿名函式找出該key有無存在於該index
    const node = bucketLinkedList.find({ callback: nodeValue => nodeValue.key === key });
  // 如果存在該node則回傳值
   return node ? node.value.value : null;
  }
}
```