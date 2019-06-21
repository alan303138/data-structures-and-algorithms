## Array vs hash-table
### Array
* 讀取儲存的資料時間複雜度都在O(1)
* 把Key當作array的index，value儲存到array，為Direct Access Table
* 如果key範圍很大，但數量很少，無法讓key連續而浪費記憶體空間

### hash-table
* 解決了浪費記憶體空間的問題，能把放資料的table大小壓縮至接近真正需要放進table資料的數量
* 引入了hash function，公式為 index=h(Key)，可以把原本雜散的key對應到 hash table的 緊湊有順序的index
* 但Hash function不是完美的，有時候會發生不同key 對應到相同index的情形，稱為collision．

## hash function
* 為一個把輸入的key轉成位置的函數，`h(Key)=index`
* 如果兩個雜湊值不相同，他們的key也不會一樣
* 兩雜湊值若相同，兩個key很大的機會一樣，若不一樣則稱為`雜湊碰撞（collision）`


## 參考資料
* [雜湊表](https://zh.wikipedia.org/wiki/%E5%93%88%E5%B8%8C%E8%A1%A8)
* [雜湊函式](https://zh.wikipedia.org/wiki/%E6%95%A3%E5%88%97%E5%87%BD%E6%95%B8)