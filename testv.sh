n="$1"
gcc randomize.c -o r
rrr=$(./r $n)
echo $rrr
./push_swap $rrr | ./checker $rrr -v
rm r
unset rrr