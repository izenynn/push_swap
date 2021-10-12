#!/bin/bash

# Colors
NOCOL='\033[0m'
RED='\033[1;31m'
YEL='\033[1;33m'
ORG='\033[0;33m'
GRN='\033[1;32m'

# Display help
if [[ $1 == "--help" ]]; then
	echo "Usage: ./tester.sh [RANGE START] [RANGE END] [OPTIONAL ARGS]"
	echo "A tester por push_swap"
	echo "Example: ./tester.sh -10 10"
	echo ""
	echo "Optional arguments:"
	echo "  (number), quantity, default is all the range"
	echo "  -b,       also use checker_bonus"
	echo ""
	echo "When the the two optional arguments are provided"
	echo "they must be in the correct order."
	echo "Example: ./tester.sh -10 10 7 -b"
	echo ""
	echo "Tester by: izenynn"
	echo "github: https://github.com/izenynn"
	exit 0
fi

# Check args
if [ -z $1 ] || [ -z $2 ]; then
	echo -e "${RED}Invalid arguments${NOCOL}"
	echo "Usage: ./tester.sh [RANGE START] [RANGE END] [FLAGS]"
	echo "Try './tester.sh --help' for more information."
	exit 1
fi

# Make if push_swap do not exists
if [ ! -f "./push_swap" ]; then
	printf "WARNING: ./push_swap does not exists, running make...\n"
	make -s
	echo ""
fi
if [ ! -f "./checker_bonus" ] && [[ $4 == "bonus" ]]; then
	printf "WARNING: ./checker_bonus does not exists, running make bonus...\n"
	make bonus -s
	echo ""
fi

# Generate random arguments
if [[ -z $3 ]] || [[ $3 == "-b" ]]; then
	ARG=`seq $1 $2 | sort -R | tr '\n' ' '`
else
	ARG=`seq $1 $2 | sort -R | tail -n $3 | tr '\n' ' '`
fi
printf "ARG: %s\n\n" "$ARG"

# Checker Mac
CHK_MAC=`./push_swap $ARG | ./checkers/checker_mac $ARG 2> /dev/null`
COL_MAC="$GRN"
if [ -z $CHK_MAC ]; then
	CHK_MAC="n/a"
	COL_MAC="$YEL"
elif [[ $CHK_MAC == "KO" ]]; then
	COL_MAC="$RED"
fi

# Checker Linux
CHK_LINUX=`./push_swap $ARG | ./checkers/checker_linux $ARG 2> /dev/null`
COL_LINUX="$GRN"
if [ -z $CHK_LINUX ]; then
	CHK_LINUX="n/a"
	COL_LINUX="$YEL"
elif [[ $CHK_LINUX == "KO" ]]; then
	COL_LINUX="$RED"
fi

# Print Checkers
printf "checker_mac: ${COL_MAC}%s${NOCOL}\n" "$CHK_MAC"
printf "checker_linux: ${COL_LINUX}%s${NOCOL}\n" "$CHK_LINUX"

# Checker bonus
if [[ $3 == "-b" ]] || [[ $4 == "-b" ]]; then
	CHK_BONUS=`./push_swap $ARG | ./checker_bonus $ARG 2> /dev/null`
	COL_BONUS="$GRN"
	if [ -z $CHK_BONUS ]; then
		CHK_BONUS="ERROR"
		COL_BONUS="$ORG"
	elif [[ $CHK_BONUS == "KO" ]]; then
		COL_BONUS="$RED"
	fi
	printf "checker_bonus: ${COL_BONUS}%s${NOCOL}\n" "$CHK_BONUS"
fi

# Moves
printf "Moves: %s\n" "$(./push_swap $ARG | wc -l | xargs)"