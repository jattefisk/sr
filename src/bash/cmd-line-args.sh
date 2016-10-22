#!/bin/bash

LOC=$(dirname $0)
SLF=$(basename $0)
TMS=`date +"%Y-%m-%d %H:%M"`

# --- FUNCTIONS ---

function usage {
	echo "USAGE: $SLF"
	echo -e " -- show text [--verbose]"
	echo -e " -v"
	echo -e " -h|--help"
	echo -e " -\nARGUMENTS:"
	echo -e " -h|--help\tdisplay this help message"
	echo -e " --show text\tdisplay text to screen"
	echo -e " --verbose\tuse verbose output"
	echo -e " -v\t\tdisplay version information"
}

function version {
	echo "Version: 0.1"
}

ARGS=`getopt -o hv -a --long help,show:,verbose -n $0 -- "$@"`

eval set -- "$ARGS"

while true; do
	case "$1" in
		-h|--help)	usage ; exit 0 ;;
		--show)		SHOW=$2  ; shift 2 ;;
		--verbose)	V_FLG=1; shift ;;
		-v)		version ; exit 0 ;;
		--)		shift ; break ;;
		*)		usage ; exit 1 ;;
	esac
done

if [ $V_FLG ] ; then
	echo -e "running $SLF located in $LOC at $TMS"
fi

if [ "$SHOW" ] ; then
	echo "User input[${SHOW}]"
else
	echo "No user input"
fi

