#!/bin/bash

# Check args
if [ -z $1 ] || [ -z $2 ] || [ -z $3 ]; then
	printf "Invalid arguments\nPlease provide this arguments for the random generation:\n"
	printf "\t1. Min (range)\n\t2. Max (range)\n\t3. Random selection size\n"
	exit 1
fi

# Generato random arguments
ARG=`seq $1 $2 | sort -R | tail -n $3 | tr '\n' ' '`
printf "ARG: %s\n\n" "$ARG"

# Checkers
CHK_MAC=`./push_swap $ARG | ./checker_mac $ARG 2> /dev/null`
CHK_LINUX=`./push_swap $ARG | ./checker_linux $ARG 2> /dev/null`
if [ $CHK_MAC ]; then
	printf "checker_mac: %s\n" "$CHK_MAC"
elif [ $CHK_LINUX ]; then
	printf "checker_linux: %s\n" "$CHK_LINUX"
fi
if [[ $4 == "bonus" ]]; then
	CHK_BONUS=`./push_swap $ARG | ./checker_bonus $ARG 2> /dev/null`
	if [ -z $CHK_BONUS ]; then
		printf "checker_bonus: ERROR: make sure you compile the checker_bonus file (make bonus)\n"
	else
		printf "checker_bonus: %s\n" "$CHK_BONUS"
	fi
fi

# Moves
printf "Moves: %s\n" "$(./push_swap $ARG | wc -l | xargs)"