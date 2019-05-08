class LinkedListNode {
	constructor(value, next = null) {
		this.value = value;
		this.next = next;
	}
	toString(callback) {
		return callback ? callback(this.value) : `${this.value}`;
	}
}

class LinkedList {

	constructor(comparatorFunction) {
		this.head = null;
		this.tail = null;
		// 此項目前有問題
		this.compare = new Comparator(comparatorFunction);
	}

	/*
   * @param {*} value
   * @return {LinkedList}
   */
	prepend(value) {
		// 新增一個 node 到 head，並把舊 head 存到新 node 的 next值
		this.head = new LinkedListNode(value, this.head);
		return this;
	}

	/*
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

	/*
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

	/*
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
			if (value !== undefined && this.compare.equal(currentNode.value, value)) {
				return currentNode;
			}
			// currentNode 不斷的找下一項，直到null
			currentNode = currentNode.next;
		}
		return null;
	}

	/*
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

	/*
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

	/*
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
}