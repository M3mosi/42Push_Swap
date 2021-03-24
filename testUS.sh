#!/bin/bash
echo
printf "\033[0;90m \033[46m ------ USAVOIA ------ \033[0m \n"
echo

printf " \033[0;90m \033[46m --- Test sequenza di 3 --- \033[0m \n"
for i in {1..10}
do
	arg=`ruby -e "puts (10..12).to_a.shuffle.join(' ')"`
	check=`./push_swap $arg | wc -l`
	sort=`./push_swap $arg | ./checker $arg`
	if [[ $((check)) -lt 4 ]] && [[ $sort == "OK" ]]
	then
		printf "\033[0;90m \033[42m OK \033[0m "
	else
		printf "\033[0;90m \033[41m\n KO \033[0m --> Operations: $check \n"
		printf "          $arg\n"
	fi
done

printf "\n \033[0;90m \033[46m  --- Test sequenza di 5 --- \033[0m \n"
for i in {1..600}
do
	arg=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
	check=`./push_swap $arg | wc -l`
	sort=`./push_swap $arg | ./checker $arg`
	if [[ $((check)) -lt 12 ]] && [[ $sort == "OK" ]]
	then
		printf "\033[0;90m \033[42m OK \033[0m "
	else
		printf "\n\033[0;90m \033[41m KO \033[0m --> Operations: $check \n"
		printf "          $arg\n"
	fi
done

printf "\n \033[0;90m \033[46m --- Test sequenza di 100 --- \033[0m \n"
for i in {1..600}
do
	arg=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
	check=`./push_swap $arg | wc -l`
	sort=`./push_swap $arg | ./checker $arg`
	if [[ $((check)) -lt 700 ]] && [[ $sort == "OK" ]]
	then
		printf "\033[0;90m \033[42m OK \033[0m "
	else
		printf "\n\033[0;90m \033[41m KO \033[0m --> Operations: $check \n"
		printf "          $arg\n"
	fi
done

printf "\n \033[0;90m \033[46m --- Test sequenza di 500 --- \033[0m \n"
for i in {1..600}
do
	arg=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
	check=`./push_swap $arg | wc -l`
	sort=`./push_swap $arg | ./checker $arg`
	if [[ $((check)) -lt 5500 ]] && [[ $sort == "OK" ]]
	then
		printf "\033[0;90m \033[42m OK \033[0m "
	else
		printf "\n\033[0;90m \033[41m KO \033[0m --> Operations: $check \n"
		printf "          $arg\n"
	fi
done
echo
