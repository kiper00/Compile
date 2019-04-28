B10515018 Compiler 作業
編譯方式
1.	到檔案根目錄下
2.	下command
	a. flex main.l
	b. gcc lex.yy.c -ll
	a.out製作完成(需無error)
3.	下測試command
	./a.out < hello.txt
	文字檔檔名可做替換

HINT
1.	按照作業指示，若讀取'.'則會印出symbol table。
	並停止後程式離開。
2.	若沒有讀取到'.'則會在整個讀取完畢後自動dump	
	一次symbol table。
