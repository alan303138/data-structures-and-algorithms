# linked list

## 疑問
* ?? head == NULL 和 head -> next == NULL 是一樣意思嗎?
    * `head == NULL` 表head指標所指向的位置為空，`head -> next == NULL`表head指標所指向的位置有值，其struct的next指向的位址為空
* 指標指向一個定值是什麼意思
    * 該位置所指向的值為定值
```
int * num = 0; // 此時表把位置0放到位址變數num中
num = 22 //此時表把位置22放到num中，非數字
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

## 範例簡介
* singly_linked_list.c 為初始的練習範例，尚不熟其指標流程和struct用法
* easy_demo_6_24.c 為簡易的demo，宣告Node後，靜態的宣告三個Node並把三者串在一起
* easy_malloc_demo_6_24.c 為簡易的malloc demo，宣告Node後，依據輸入的長度，動態的產生該長度的linked list
* demo_6_26.c 有完成、清楚的 CRUD demo


### demo撰寫順序
* include 基本資料
* 定義 node
* 建立 main
* 建立 printList
    * 建立printList的測試
    * 可簡易的建立型態為Node的變數提供測試
* 建立 addLastNode，功能為新增一筆資料在最後一項
    * 需找出最後一項
* 建立 deleteLastNode，功能為刪除最後一筆資料
    * 記得處理如果只有處理只有一筆的情形
* 建立 addFirstNode
    * 可擴展為建立新增資料到第n筆
* 建立 deleteFirstNode
    * 可擴展為刪除第n筆資料
* 刪除所有list
* 反轉資料
    * 反轉資料比較難，需要三個變數處理

### 常見問題
* [What does “pointer being freed was not allocated” mean exactly?](https://stackoverflow.com/questions/13148119/what-does-pointer-being-freed-was-not-allocated-mean-exactly) 只有用malloc處理過的變數才能free()

* 指向struct的指標使用前必須被賦值，如給定一個值或用malloc配置位置

### 參考資料
* [單向鏈結串列 Singly Linked List](https://hackersir.gitbooks.io/c/content/Ch11/02_Singly_Linked_List_forC.html)
* [JS 資料結構 linked-list](https://medium.com/@nicehorse06/javascript-algorithms-linked-list-b0f80e49a5c6)
* [C語言 鏈結串列(link list)的實作範例](https://lakesd6531.pixnet.net/blog/post/329288496-c%E8%AA%9E%E8%A8%80-%E9%8F%88%E7%B5%90%E4%B8%B2%E5%88%97(link-list)%E7%9A%84%E5%AF%A6%E4%BD%9C%E7%AF%84%E4%BE%8B) 非常實用的範例

* [[C 語言] 程式設計教學：如何使用結構 (Struct)](https://michaelchen.tech/c-prog/struct/)
* [Linked List: Intro(簡介)](http://alrightchiu.github.io/SecondRound/linked-list-introjian-jie.html)
* [如何建構Linked List](https://mycollegenotebook.medium.com/%E5%A6%82%E4%BD%95%E5%BB%BA%E6%A7%8Blinked-list-4f49604e044a)
* [Linked List | Set 1 (Introduction) geeksforgeeks](https://www.geeksforgeeks.org/linked-list-set-1-introduction/)
    * 步驟清楚 有Python和C版本