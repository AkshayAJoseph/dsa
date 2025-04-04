echo "Enter a number"
read n
rev=0
i=0
while [ $i -lt $n ]
do
    t=$((n%10))
    rev=$((t+rev*10))
    n=$((n/10))
done
echo $rev