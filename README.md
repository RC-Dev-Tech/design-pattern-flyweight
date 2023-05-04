# ![](https://drive.google.com/uc?id=10INx5_pkhMcYRdx_OO4rXNXxcsvPtBYq) Flyweight 享元模式 
> ##### 理論請自行找，網路上有很多相關的文章，這邊只關注於範例實作的部分.

---
<br>

<!--ts-->
## 目錄
* [目的](#目的)
* [使用時機](#使用時機)
* [URL結構圖](#url結構圖)
* [實作成員](#實作成員)
* [實作範例](#實作範例)
* [參考資料](#參考資料)
<!--te-->

---
<br>

## 目的
Flyweight設計模式旨在最小化對記憶體和計算資源的使用，通過共享盡可能多的數據來實現這一目標。

---
<br>

## 使用時機
當系統需要大量創建相似物件時，而這些相似物件有許多通用的屬性，可以使用Flyweight模式。<br>
透過共享相同的狀態，Flyweight模式可以大幅度減少內存使用量。

---
<br>

## URL結構圖
![](https://drive.google.com/uc?id=1HVv7QYYF31fs_DTPFjsEU1ExXDEidSsp)
> 圖片來源：[Refactoring.Guru - Flyweight](https://refactoring.guru/design-patterns/flyweight) 

---
<br>

## 實作成員
* Flyweight
 * 定義一個介面，用於共享具有相同狀態的物件。
* ConcreteFlyweight
 * 實現Flyweight介面，並保存其共享狀態。
* FlyweightFactory
 * 維護一個Flyweight池，用於存儲已創建的Flyweight對象。<br>
   當客戶端請求一個Flyweight時，如果池中已經存在相應的對象，則直接返回該對象，<br>
   否則創建一個新的對象並將其添加到池中。
* Client
 * 使用FlyweightFactory來創建和存取Flyweight物件。由於Client只操作Flyweight的共享狀態，所以可以與Flyweight的具體實現解耦。

---
<br>

## 實作範例:
- [待補...]() 

---
<br>

## 參考資料
* [Wiki - Flyweight Pattern](https://en.wikipedia.org/wiki/Flyweight_pattern) <br>
* [Refactoring.Guru - Flyweight](https://refactoring.guru/design-patterns/flyweight) <br>

---
<br>

---
<!--ts-->
#### [目錄 ↩](#目錄)
<!--te-->
---
