#!/usr/bin/env bash

rm -f log.txt
touch log.txt
mkdir tests

#number of symbols that will exist in the input file
number_of_total_symbols=(1000 10001)

#number of unique symbols that will exist in the input file that will have "number_of_total_symbols" symbols
number_of_unique_symbols=(1 5 16)

letters=({A..Z})

for total_symbols in ${number_of_total_symbols[@]}; do
	for number in  ${number_of_unique_symbols[@]}; do
		echo "Enter in test with "${total_symbols}" total symbols and "${number}" of unique symbols."
		number2=$((number - 1))
		symbol=${letters[${number2}]}
		dd if=<(tr -dc A-${symbol} </dev/urandom) bs=1 count=${total_symbols} of=tests/total_symbols_${total_symbols}_unique_symbols_${number}.in 2>/dev/null

		./test.sh tests/total_symbols_${total_symbols}_unique_symbols_${number}.in > /dev/null
		diff out.txt tests/total_symbols_${total_symbols}_unique_symbols_${number}.in > diff.txt
		if [ -s diff.txt ]
		then
			echo "Failed: test with "${total_symbols}" total symbols and "${number}" unique symbols from A-"${symbol}"."
			echo "Failed: test with "${total_symbols}" total symbols and "${number}" unique symbols from A-"${symbol}"." >> log.txt
			echo -e "diff out.txt tests/total_symbols_${total_symbols}_unique_symbols_${number}.in > diff.txt\n" >> log.txt

			echo -e "-------------------------------------------------------\n\n" >> log.txt
		else
			echo "Test passed. OK"
		fi
		echo ""
		rm -f diff.txt
	done

done

if [ ! -s log.txt ]; then
	echo "All tests passed. OK"
	rm log.txt
fi

#remove all the files that were created in this script
rm -rf tests
rm out.txt out.bin