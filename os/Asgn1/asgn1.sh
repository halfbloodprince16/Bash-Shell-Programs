		while true 
	do
echo -e "\a----------------------------ADDRESS BOOK--------------------"
echo -e "1.)Create Address Book"
echo "2.)View Address Book"
echo "3.)Insert A Record"
echo "4.)Modify A Record"
echo "5.)Delete A Record"
echo "6.)Exit"

read choice

case $choice in 
	1)echo "HOW MANY RECORDS YOU WANT - "
		read n
			
			for i in `seq 1 $n`
			
				do
					chmod u+w data.dat
					echo "ENTER Reg_NO"
						read r_no 
					echo "ENTER NAME"
						read name 
					echo "ENTER DOB"
						read dob 
					echo "ENTER ADDRESS"
						read add 
					echo "ENTER MOB NO"
						read mob
					echo "Done" 
				s=`cut -f 1 -d " " data.dat | grep -w $r_no | cut -f 1 -d " "` 
					if [ "x$s" = "x" ]
						then
							echo $r_no" "$name" "$dob" "$add" "$mob >> data.dat 
						else
							echo "ROLL NO EXISTS , RECORD NOT INSERTED"
						fi
				
				
			done 
				chmod u-w data.dat;;
	2) echo "DISPLAYING RECORDS"
		cat data.dat ;;
	3) echo "INSERTING RECORD"
			chmod u+w data.dat	
			flag=1
				echo "ENTER Reg_NO"
						read r_no 

					echo "ENTER NAME"
						read name 
					echo "ENTER DOB"
						read dob 
					echo "ENTER ADDRESS"
						read add 
					echo "ENTER MOB NO"
						read mob
					echo "Done" 

					s=`cut -f 1 -d " " data.dat | grep -w $r_no s | cut -f 1 -d " "` 
					if [ "x$s" = "x" ]
						then
							echo $r_no" "$name" "$dob" "$add" "$mob >> data.dat 
						else
							echo "ROLL NO EXISTS , RECORD NOT INSERTED"
						fi
				
				
			
			
			chmod u-w data.dat ;;
	4) echo "SEARCH"
		input="data.dat"
		echo "ENTER reg_no to change"
			read reg_no
		echo "ENTER NEW REG NO-"
			read nreg_no
		e=`cut -d " " -f 1 data.dat | grep -wn $reg_no | cut -f1 -d :`

		
		count=0
		while IFS= read  var
			do
				count=`expr $count + 1`
				if [ $count = $e ]
					then 
						
						echo $var > t.dat 
						s=`cut -d " " -f2,3,4,5 t.dat`
						echo $nreg_no $s > a.dat
						
						cat a.dat >> tt.dat
						rm -f a.dat 
						rm -f t.dat
						
						
				else
						
							echo $var >> tt.dat 
				fi

			done < "$input"	
			chmod u+w data.dat	
			cat tt.dat > data.dat
			rm -f tt.dat
			;;
		
	5) echo "Delete Record : Enter Reg_no to Delete"
		chmod u+w data.dat	
		touch temp3.dat
		read R_NO
		e=`cut -d " " -f 1 data.dat | grep -wn $R_NO | cut -f1 -d :`
		input='data.dat'
		count=0
		while IFS= read var 
			do
				count=`expr $count + 1`
				if [ $count = $e ]
					then	
						echo "ROW DELETING"
				else 
						echo $var >> temp3.dat 
				fi
			done < "$input"
			cat temp3.dat > data.dat 
			rm -f temp3.dat
		;;
	6) exit ;;
	*) echo "Wrong Choice";;
esac
done 