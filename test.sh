n="$1"
gcc randomize.c -o r
rrr=$(./r $n)
echo $rrr
./push_swap $rrr  | ./checker $rrr; echo; ./push_swap $rrr| wc -l 
rm r
unset rrr