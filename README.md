The program encode and decode an input file that contain symbols.

The encription works by replacing the symbols with an index 
from an unique symbols table that is created based on the input file.

The limitation are:
- no more then 16 unique symbols in the input file
- no input file with more total symbols than the maximum limit of size_t which is very very big

Don't load in the decode program a file that was not created with the encode one.

You can compile and test the program using the test.sh script or you can compile it on your own.

To compile:
g++ encode.cc -o encode
g++ decode.cc -o decode

To run:
./encode <example.dat >out.bin

./decode <out.bin >out.txt

To check if the encode -> decode works you can call the diff command:

diff out.txt example.dat

If the diff print something, there is a problem with the encription.

To check if the encription works with different files with bigger vales and different number of symbols,
you can use the script.sh file.

To run the script.sh you just need to call it:

./script.sh

The file will create it's own tests and at the end will delete all the files that were created and keeps only
log.txt if there were errors in one of the tests.

In the top of the file you can find 2 arrays: number_of_total_symbols and number_of_unique_symbols

You can change their values to customize your testing by following:
- number_of_total_symbols -> you can specify the size of the file(total number of symbols)
- number_of_unique_symbols -> you can specify the numbers of unique symbols

The script will run all the combinations between number_of_total_symbols and number_of_unique_symbols
