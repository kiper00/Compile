B10515018 Compiler 作業2

編譯方式(linux)
	法一
	1.	到檔案根目錄下
	2.	下command
		a. bison -y -d parse.y
		b. flex main.l
		c. gcc y.tab.c lex.yy.c -ll -ly
		a.out製作完成(需無error)
	3.	下測試command
		./a.out < Test.modula
		文字檔檔名可做替換
		
	法二
	1.	到檔案根目錄下，執行make
		Makefile需存在於此目錄下

與HW1比較，main.l做了哪些改變：
	1.	token不在逐一印出保留字，減少配上 yacc 方便了解執行何行出錯
	2.	增加 return token 與 yacc 溝通
	3.	修正 Hw1 將 real 視為特殊保留字，轉為小數。
	
HINT
	1.	Debug模式下，將SymbolTable.h的debug設置為1。
		即可觀察執行到哪一行，做了甚麼動作。
	2.	註解寫在Trace(t)，可同1.開啟印出註解動作。
	3.	var宣告的變數，若沒有後面額外給值。
		計算時將以 integer = 0, real = 0, bool = false, string = null;
	4.	Array範圍可以為任意整數到任意整數
		只須滿足 [left,right] right >= left
	5.	Array可能因為3.，造成ID[expression] out of range。
		如果範圍並不包含0。