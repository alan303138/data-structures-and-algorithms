# Sort

## 參考資料：
* [[演算法] 排序演算法(Sort Algorithm)](http://notepad.yehyeh.net/Content/Algorithm/Sort/Sort.php)
* [wiki 排序演算法](https://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95)
* [wiki qsort](https://en.wikipedia.org/wiki/Qsort)
* [geeksforgeeks Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)
* [義首大學排序網頁](http://spaces.isu.edu.tw/upload/18833/3/web/sorting.htm)

## 所有排序整理
* todo 
	* 合併排序
	* 快速排序
	* 謝耳排序
	* 基數排序
* finish
	* 選擇排序
	* 氣泡排序
* futrue，須先看完樹的單元
	* 堆積排序
	* 二元樹排序

## 定義
* 輸入input array[a1, a2, a3...,an]輸出排序後的output array[a1\`, a2\`, a3\`...,an\`]
* `a1`稱key
* 對應的實際資料為 `satellite data`
* 如果`satellite data`太大，實務上會移動pointer來排序

## 排序的應用
* 可以增快搜尋速度
	* 未排序的資料搜尋為`O(n)`
	* 排序過後的資料為`O(logn)`
	* 要考慮排序的時間
* 比對兩個長度為n跟m的array，是否一樣的速度
	* 未排序為`O(m * n)`
	* 排序後為`O(m + n)`
	* 要考慮排序的時間

## 排序的分類
* Internal Sort
	* 在memory中就可以解決的排序
* External Sort
	* 資料太大以至於需要額外的慢儲存來輔助，如硬碟
* 在大部分的情況先`Internal Sort`已足夠滿足需求

## 一些排序的相關名詞
* Stability
	* 當兩值(key)一樣在排序前後期順序不變則為stable sorting
	* 如排序前：3,5,19,1,3*,10，排序後：1,3,3*,5,10,19
		* 因為兩個3, 3*的相對位置在排序前與後皆相同，為stable sorting
* In-place
	* 在搜尋上不用到額外的記憶體空間
	* 空間複雜度為O(1)
* Adaptability
	* 如果一部分的序列已被搜尋，時間複雜度會降低的程度


## 用決策樹來分析次數
* 排序需要Compare和Swap
	* Compare:比較兩者大小
	* Swap:交換兩者順序
* 結論為n筆資料有n!種可能的排序
* 根據台大講義的推導，comparison-based的演算法最糟的複雜度為 `Ω(nlogn)`


##  Selection Sort
### 作法
* 選array中最小的數字移動到第一個位置
* 選array中第二小的數字移動到第二個位置
* 持續第n小移動到第n個位置
* 輪到最後一個數字時已自動排序完成
### 分析
* 每一次排序過程都會經過整個array
* 總共要做n次的Swap，且每一次Swap都要做n次的Compare
* 故`best-case`, `worst-case`, `average-case` 皆為O(n^2)
* Not adaptive
* In-place