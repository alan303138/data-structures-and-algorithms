import LinkedList from '../linked-list/LinkedList';
const defaultHashTableSize = 32;
class HashTable {
	constructor(hashTableSize = defaultHashTableSize) {
		// 填充出等於hashTableSize大小的array，並在讓個欄位實作空LinkedList
		this.buckets = Array(hashTableSize).fill(null).map(() => new LinkedList());
	}
	hash(key) {
		// 藉由把 key 中的每一項轉換成 key code 加起來得到 hash值
		const hash = Array.from(key).reduce(
			(hashAccumulator, keySymbol) => (hashAccumulator + keySymbol.charCodeAt(0)),
			0,
		);
		// 減少 hash number的數量，得到符合 hash table的大小的index
		return hash % this.buckets.length;
	}
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

	get(key) {

		// 用hash(key)找出index，回傳linked list
		const bucketLinkedList = this.buckets[this.hash(key)];
		//帶入匿名函式找出該key有無存在於該index
		const node = bucketLinkedList.find({ callback: nodeValue => nodeValue.key === key });
		// 如果存在該node則回傳值
		return node ? node.value.value : null;
	}

}