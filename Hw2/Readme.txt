B10515018 Compiler 作業
編譯方式
1.	到檔案根目錄下
2.	下command
	a. bison -y -d parse.y
	b. flex main.l
	c. gcc y.tab.c lex.yy.c -ll -ly
	a.out製作完成(需無error)
3.	下測試command
	./a.out < hello.txt
	文字檔檔名可做替換

HINT
1.	
