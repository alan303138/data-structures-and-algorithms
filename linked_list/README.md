# linked list

## 疑問
* ?? head == NULL 和 head -> next == NULL 是一樣意思嗎?
* 指標指向一個定值是實麼意思
```
int * num = 0;
num = 22
```

## linked list特性
* 可動態的產生node，每個node至少包含一個值和指標
* 如果指標為NULL表示在list中為最後一個node


## 需要的函示

* 初始定義
    * 定義節點struct
    * 定義必要指標（如header，可當作邊界條件）
* UI介面
    * 無窮while迴圈
    * 選擇功能的switch選單

* 基本的功能
    * 從第一筆、尾端生成新node
    * 印出所有資料和長度
    * 刪除所有node
		* 刪除第一筆資料
		* 刪除最後一筆資料

* 定義求長度的函示才能做以下功能
   * 從指定key插入node todo
   * 修改指定key的node的值 todo
   * 印出指定key的node的值 todo
   * 刪除指定key的的node todo

* 要做排序才有以下功能
    * 排序節點資料(依照裡面的數值) todo
    * 反轉list順序 todo



## 優點：
1. 可從中間新增或是移除 item
2. 不用定義初始大小

## 缺點:
1. There is no "random" access - it is impossible to reach the nth item in the array without first iterating over all items up until that item. This means we have to start from the beginning of the list and count how many times we advance in the list until we get to the desired item.
2. Dynamic memory allocation and pointers are required, which complicates the code and increases the risk of memory leaks and segment faults.
3. Linked lists have a much larger overhead over arrays, since linked list items are dynamically allocated (which is less efficient in memory usage) and each item in the list also must store an additional pointer.


### 參考資料
* [單向鏈結串列 Singly Linked List](https://hackersir.gitbooks.io/c/content/Ch11/02_Singly_Linked_List_forC.html)
* [JS 資料結構 linked-list](https://medium.com/@nicehorse06/javascript-algorithms-linked-list-b0f80e49a5c6)
* [C語言 鏈結串列(link list)的實作範例](https://lakesd6531.pixnet.net/blog/post/329288496-c%E8%AA%9E%E8%A8%80-%E9%8F%88%E7%B5%90%E4%B8%B2%E5%88%97(link-list)%E7%9A%84%E5%AF%A6%E4%BD%9C%E7%AF%84%E4%BE%8B)
* [[C 語言] 程式設計教學：如何使用結構 (Struct)]()