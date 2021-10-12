#!/bin/bash

### INITIALISE VARIABLES
# Colors
NOCOL='\033[0m'
RED='\033[1;31m'
YEL='\033[1;33m'
ORG='\033[0;33m'
GRN='\033[1;32m'
DGRAY='\033[1;30m'
BLU='\033[1;34m'

# Others
OP_FILE="output.txt"
PS_PATH="$1"
DIGITS='^[0-9]+$'

### FUNCTIONS
# Invalid args
function invalid_args () {
	echo -e "${RED}ERROR:${NOCOL} Invalid arguments"
	echo "Usage: ./tester.sh [OPTION] [ARGS]"
	echo "Try './tester.sh --help' for more information."
	exit 1
}

# Checkers
function check () {
	# $1 == bonus ?
	# $1 or $2 == short ?
	# Checker Mac
	CHK_MAC=`cat $OP_FILE | ./checkers/checker_mac $ARG 2> /dev/null`
	COL_MAC="$GRN"
	if [ -z $CHK_MAC ]; then
		CHK_MAC="n/a"
		COL_MAC="$YEL"
	elif [[ $CHK_MAC == "KO" ]]; then
		COL_MAC="$RED"
	fi

	# Checker Linux
	CHK_LINUX=`cat $OP_FILE | ./checkers/checker_linux $ARG 2> /dev/null`
	COL_LINUX="$GRN"
	if [ -z $CHK_LINUX ]; then
		CHK_LINUX="n/a"
		COL_LINUX="$YEL"
	elif [[ $CHK_LINUX == "KO" ]]; then
		COL_LINUX="$RED"
	fi

	# Print Checkers
	if [[ $1 == "short" ]] || [[ $2 == "short" ]]; then
		printf " ${DGRAY}MAC: ${COL_MAC}%3s${NOCOL}" "$CHK_MAC"
		printf "  ${DGRAY}LNX: ${COL_LINUX}%3s${NOCOL}" "$CHK_LINUX"
	else
		printf "checker_mac: ${COL_MAC}%s${NOCOL}\n" "$CHK_MAC"
		printf "checker_linux: ${COL_LINUX}%s${NOCOL}\n" "$CHK_LINUX"
	fi

	# Checker bonus
	if [[ $1 == "bonus" ]]; then
		CHK_BONUS=`cat $OP_FILE | $PS_PATH/checker_bonus $ARG 2> /dev/null`
		COL_BONUS="$GRN"
		if [ -z $CHK_BONUS ]; then
			CHK_BONUS="ERROR"
			COL_BONUS="$ORG"
		elif [[ $CHK_BONUS == "KO" ]]; then
			COL_BONUS="$RED"
		fi
		if [[ $2 == "short" ]]; then
			printf "  ${DGRAY}BNS: ${COL_BONUS}%3s${NOCOL}" "$CHK_BONUS"
		else
			printf "checker_bonus: ${COL_BONUS}%s${NOCOL}\n" "$CHK_BONUS"
		fi
	fi
	
	# Moves
	if [[ $1 == "short" ]] || [[ $2 == "short" ]]; then
		printf "  ${DGRAY}MOVES:${NOCOL} %-6d\n"
	else
		printf "Moves: %s\n" "$(cat $OP_FILE | wc -l | xargs)"
	fi
}

# Check files
function check_ps () {
	# $1: push_swap path
	if [ ! -f "$1/push_swap" ]; then
		echo -e "${YEL}WARNING:${NOCOL} \"$PS_PATH/push_swap\" does not exists, running make..."
		make -sC "$1"
		echo ""
		if [ ! -f "$1/push_swap" ]; then
			echo -e "${RED}ERROR:${NOCOL} \"$PS_PATH/push_swap\" file does not exists after make."
			exit 1
		fi
	fi
}

function check_bonus () {
	# $1: push_swap path
	if [ ! -f "$1/checker_bonus" ]; then
		echo -e "${YEL}WARNING:${NOCOL} \"$PS_PATH/checker_bonus\" does not exists, running make bonus...\n"
		make bonus -sC "$1"
		echo ""
		if [ ! -f "$1/checker_bonus" ]; then
			echo -e "${RED}ERROR:${NOCOL} \"$PS_PATH/checker_bonus\" file does not exists after make bonus."
			exit 1
		fi
	fi
}

function get_args() {
	if [[ -z $3 ]]; then
		local res=`seq $1 $2 | sort -R | tr '\n' ' '`
	else
		local res=`seq $1 $2 | sort -R | tail -n $3 | tr '\n' ' '`
	fi
	echo "$res"
}

function exec_ps() {
	echo -n `$PS_PATH/push_swap $ARG` | tr ' ' '\n' > "$OP_FILE"
	if [ -s "$OP_FILE" ]; then
		echo "" >> "$OP_FILE"
	fi
}

### FLAGS FUNCTIONS
function flat_c {
	echo #
}

function flag_r () {
	if [ -z $1 ] || [ -z $2 ]; then
		invalid_args
	elif ! [[ $1 =~ $DIGITS ]] || ! [[ $2 =~ $DIGITS ]]; then
		invalid_args
	elif [ ! -z $3 ] && ! [[ $3 == "-b" ]] && ! [[ $3 =~ $DIGITS ]]; then
		invalid_args
	elif [ ! -z $4 ] && ! [[ $4 == "-b" ]]; then
		invalid_args
	fi
	ARG=$(get_args $1 $2 $3)
	printf "Args: %s\n\n" "$ARG"
	exec_ps
	if [[ $3 == "-b" ]] || [[ $4 == "-b" ]]; then
		check "bonus"
	else
		check
	fi
}

function flag_ro () {
	if [ -z $1 ] || [ -z $2 ]; then
		invalid_args
	elif ! [[ $1 =~ $DIGITS ]] || ! [[ $2 =~ $DIGITS ]]; then
		invalid_args
	elif [ ! -z $3 ] && ! [[ $3 == "-b" ]] && ! [[ $3 =~ $DIGITS ]]; then
		invalid_args
	elif [ ! -z $4 ] && ! [[ $4 == "-b" ]]; then
		invalid_args
	fi
	ARG=$(get_args $1 $2 $3)
	printf "Args: %s\n\n" "$ARG"
	echo "Output:"
	exec_ps
	cat "$OP_FILE"
	echo ""
	if [[ $3 == "-b" ]] || [[ $4 == "-b" ]]; then
		check "bonus"
	else
		check
	fi
}

function flag_rn () {
	if [ -z $1 ] || [ -z $2 ] || [ -z $3 ]; then
		invalid_args
	elif ! [[ $1 =~ $DIGITS ]] || ! [[ $2 =~ $DIGITS ]] || ! [[ $3 =~ $DIGITS ]]; then
		invalid_args
	elif [ ! -z $4 ] && ! [[ $4 == "-b" ]] && ! [[ $4 =~ $DIGITS ]]; then
		invalid_args
	elif [ ! -z $5 ] && ! [[ $5 == "-b" ]]; then
		invalid_args
	fi
	for (( i=1; i<=$1; i++ )); do
		printf "${BLU}TEST %4d:${NOCOL} " "$i"
		ARG=$(get_args $2 $3 $4)
		exec_ps
		if [[ $4 == "-b" ]] || [[ $5 == "-b" ]]; then
			check "bonus" "short"
		else
			check "short"
		fi
	done
	}

### SCRIPT
# Check args
if [ -z $1 ]; then
	invalid_args
fi

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

# Check push_swap path
if [ ! -d "$1" ]; then
	echo -e "${RED}ERROR:${NOCOL} \"$1\" directory does not exists."
	exit 1
fi
check_ps $1

# Check flags
if [[ -z $2 ]]; then
	invalid_args
elif [[ $2 == "-c" ]]; then
	echo "f" # custom combination
elif [[ $2 == "-co" ]]; then
	echo "f" # custom combination
elif [[ $2 == "-r" ]]; then # random
	flag_r $3 $4 $5 $6
elif [[ $2 == "-ro" ]]; then # random show output
	flag_ro $3 $4 $5 $6
elif [[ $2 == "-rn" ]]; then # n random
	flag_rn $3 $4 $5 $6 $7
else
	invalid_args
fi

# Delete garbage
if [ -f "$OP_FILE" ]; then
	rm -rf "$OP_FILE"
fi