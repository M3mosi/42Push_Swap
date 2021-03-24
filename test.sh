n="$1"
gcc randomize.c -o r
rrr=$(./r $n)
echo $rrr
./push_swap $rrr  > ciao.txt
cat ciao.txt |./checker $rrr; echo; cat ciao.txt| wc -l 
rm r
rm ciao.txt
unset rrr