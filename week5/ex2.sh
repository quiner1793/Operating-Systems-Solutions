file="./ASD.txt"

(
flock -e 200
for i in {1..10}
do
num=$(tail -n 1 $file)
((num++))
echo $num >> $file
done
)200>>$file
