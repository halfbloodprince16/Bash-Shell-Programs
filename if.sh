echo "Enter two numbers"
read num1 num2
sum=`expr $num1 + $num2`

if [ $sum -gt 0 ] 
	then 
		echo "Positive"
elif [ $sum -lt 0 ]
	then 
		echo "Negative"
else
	echo "zero"
fi




