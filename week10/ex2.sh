echo 1 > ../week1/file.txt
link ../week1/file.txt _ex2.txt
ls -i _ex2.txt > ex2.txt
str_list=$(ls -i _ex2.txt)
str_array=($str_list)
find .. -inum ${str_array[0]} >> ex2.txt
find ../week10 -inum ${str_array[0]} -exec rm {} \; >> ex2.txt
