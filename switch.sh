echo "calculator"
echo "Enter two nos"
read a b
ch=1
while [ $ch -ne 0 ]
do
	echo "Enter Choice 1:add 2:sub 3:mul 4:div"
	read choice

	case $choice in
		1) echo $((a+b));;
		2) echo $((a-b));;
		3) echo $((a*b));;
		4) echo $((a/b));;
		*) echo "invalid";;
	esac
	echo "Run Again 0/1"
	read ch
done


