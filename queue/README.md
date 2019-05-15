Queue為先進先出 類似排隊

可假想一陣列兩端為front端和rear端
* 每次加入都加在rear端
* 每次刪除就在front端 (書中做 終於排隊排到被服務了)

一開始佇列 front = -1, rear = -1
當有一元素加入須判斷 rear 是否超過陣列最大容量
當rear為 MAX-1十表示已達最大容量