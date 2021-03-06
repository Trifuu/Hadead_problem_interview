#!/usr/bin/env bash

rm -f log.txt
touch log.txt
mkdir tests

number_of_total_symbols=(100 101)
number_of_unique_symbols=(1 5 16)

letters=({A..Z})

for total_symbols in ${number_of_total_symbols[@]}; do
	for number in  ${number_of_unique_symbols[@]}; do
		number=$((number - 1))
		symbol=${letters[${number}]}
		dd if=<(tr -dc A-${symbol} </dev/urandom) bs=1 count=${total_symbols} of=tests/total_symbols_${total_symbols}_unique_symbols_${number}.in

		./test.sh tests/total_symbols_${total_symbols}_unique_symbols_${number}.in > /dev/null
		diff out.txt tests/total_symbols_${total_symbols}_unique_symbols_${number}.in > diff.txt
		if [ -s diff.txt ]
		then
			echo "Failed: test with "${total_symbols}" total symbols and "$((number + 1))" unique symbols from A-"${symbol}"."
			echo "Failed: test with "${total_symbols}" total symbols and "$((number + 1))" unique symbols from A-"${symbol}"." >> log.txt
			echo -e "diff out.txt tests/total_symbols_${total_symbols}_unique_symbols_${number}.in > diff.txt\n" >> log.txt
			#cat diff.txt >> log.txt
			echo -e "-------------------------------------------------------\n\n" >> log.txt
		fi

		rm -f diff.txt
	done

done
rm -rf tests
rm out.txt out.bin