echo 1 > _ex3.txt
chmod -x _ex3.txt
ls -l _ex3.txt > ex3.txt
chmod 707 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "660 mean only read and write for user and group" >> ex3.txt
echo "775 mean read, write and execute for user and group; read and execute for others" >> ex3.txt
echo "777 mean read, write and execute for user, group and others" >> ex3.txt

