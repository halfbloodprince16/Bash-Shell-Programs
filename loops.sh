max=10
for((i=2;i<=$max;++i))
do
    echo "$i"
done

while [ $max -lt 15 ]
do
	echo "$max"
	((max = max + 1))
done
