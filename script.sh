#!/bin/bash

if [ "$1" == "" ]; then
	echo "What's the arduino's serial port?"
	exit 126
fi

# rm temp-dir/chrome_debug.log


BUTTONS=$(cat temp-dir/chrome_debug.log | cut -d\" -f2 | cut -d= -f2)

while read -r RIGA; do
	echo "$RIGA" > "$1"
done <<< "$BUTTONS"
