1.使用 g++ B11015059.cpp -o B11015059.out 將cpp檔轉成執行檔
2.將要執行的KISS file放入與執行檔同一個資料夾內
3.使用 ./B11015059.out input.kiss output.kiss output.dot 產生出input.dot、output.kiss、output.dot
4.接下來就可以用 cat 去看輸出的結果，或是用 dot -T png output.dot > output.png 產生出化簡前或化簡後的graph