#sting reverse

echo "Enter a string"
read str
len=${#str}
echo $len

revr=$(echo $str | rev)
echo $revr

if [ "$str" == "$revr" ]
then
	echo "Palindrome"
else
	echo "Not a Palindrome"
fi
