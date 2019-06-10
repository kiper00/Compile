B10515018 Compiler 作業3

編譯方式(linux)
	製作a.out
		法一
		1.	到檔案根目錄下
		2.	下command
			a. bison -y -d parse.y
			b. flex main.l
			c. gcc y.tab.c lex.yy.c -ll -ly
			a.out製作完成(需無error)
			
		法二
		1.	到檔案根目錄下，執行make
			Makefile需存在於此目錄下
	製作jasm
		下command
		./a.out < *.modula(根據檔名)
	
	製作java class
		下command
		./javaa *.jasm(根據檔名)
	
	測試class
		下command
		java *.class(根據檔名)

與HW2比較，做了哪些改變：
	1.	SymbolTable.h新增部分function方便查找、區分local與global差異
	2.	修改部分 BNF ，使其可以先執行部分動作
	
HINT
	1.	Debug模式下，將SymbolTable.h的debug設置為1。
		即可觀察執行到哪一行，做了甚麼動作。
	2.	註解寫在Trace(t)，可同1.開啟印出註解動作。
	3.	var宣告的變數，若沒有後面額外給值。
		計算時將以 integer = 0, real = 0, bool = false, string = null;