echo "you in bash world"
chk=1

while [ $chk -eq 1 ]
do
	echo -e "1-write\n2-read\n3-dipslay\n4-delete\n5-update"
	read x

	case $x in 
		1)echo "Enter Name :"
		  read name
		  echo "Enter roll :"
		  read roll
		  echo $name $roll >> at.txt;;
		2)echo "Enter roll to dipslay"
		  read roll
		  grep -i -n "$roll" at.txt
		  ;;
		3)cat at.txt;;
		4)echo "Enter roll to delete"
		  read roll
		  sed -i -n "/$roll/d" at.txt;;
		5)echo "Enter roll to update"
		  read roll
		  grep -i -n "$roll" at.txt
		  echo "Enter Line no"
		  read line
		  echo "Modify from"
		  read s1
		  echo "Modify to"
		  read s2
		  sed -i "${line}s/$s1/$s2/g" at.txt
 		  ;;
		*) ;;
	esac
	echo "continue 1/0"
	read chk
done