echo "Assignment 1 : File Implementation for read,write,display,delete,modify"

chk=1

while [ $chk -eq 1 ]
do
	echo -e "\nPress \n1:Write\n2:Read\n3:Display\n4:Modify\n5:Delete"
	read ch

	case $ch in
		1)echo "Enter Name:"
			read name
		    echo "Enter Roll no." 
		    read roll
		    echo "Enter Branch"
		    read branch
		    echo  $name $roll $branch >> data.txt
				;;
		2)  echo "Enter your roll to read"
			read x
			grep -i -n $x data.txt #command used search in the file
			;;

		3)echo -e "Name    Roll No.  Branch"
			cat data.txt;;
		4)echo "Enter roll no. to be modified"
			read x
			echo "Choose what to modify"
			grep -n $x data.txt 
			echo "Modify From :"
			read s1
			echo "Modify to :"
			read s2
			sed "s/$s1/$s2/gi" data.txt

			;;
		5)echo "Which roll no. data to be deleted"
			read x
			sed -i "/$x/d" data.txt #use of $x gives error
 			;;
		*)echo "invalid";;
	esac

	echo "Do you want to continue 1/0"
	read chk
done
