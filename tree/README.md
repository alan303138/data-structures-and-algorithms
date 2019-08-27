假設一棵k分之的樹,總共有n個節點,那麼它需要nk個LINK欄位
除了樹根外每一節點均被一LINK所指向,所以共用了n-1個LINK
共造成nk-(n-1) = nk-n-1個LINK被浪費

## 二元樹
### 與一般樹的不同點
* 二元樹節點可以為零，一般樹只少由一個節點組成
* 二元樹有排列順序關係，一般樹則沒有
* 二元樹每一節點分之最多為二，一般樹無此限制

### 特殊二元樹
* 左斜樹(left skewed tree)：每一節點右子樹為空集合，右斜樹定義亦同
* 滿枝二元樹(fully binary tree)：階度為k的樹，含有2**k-1個節點數
* 完整二元樹(complete binary tree)，排列順序同滿枝二元樹，節點數少於2**k-1

### 二元樹特性
* 在一棵樹的第i階度，最多節點數為2**(i-1)，i>=1
* 一棵k階度的樹，最多的節點樹為2**k-1，i>=1
* 一棵二元樹，若n0表示所有的樹葉節點(子節點為0)，n2表所有分支度為2的節點(子節點為2)，則n0=n2+1

### 二元樹編號順序
* 初步看下去，就是從上到下，從左到右
* 書上的嚴謹說法，todo

## 樹的定義
* 為一個或多個node的有線集合

### Tree的名詞
* 最上面的點稱為root
* Node/Edge (branch)
* Degree (of a node):
	* 該node的subtree數量
* Leaf/Terminal node
	* 表degree為零
* Parent/Children
* Siblings
	* 有同一個母節點
* Ancestors/Descendants
	* 祖先節點與後裔節點
* Level/depth (of a node)
	* 該node要到達root經過的數量
	* root level 為 0
* Height (of a tree):
	* tree的level數量
* Size (of a tree)
	* tree的node數量
* Weight (of a tree):
	* tree的leaves數量
* Degree (of a tree):
	* 該數的node最大的degree

## todo Representing a tree with array