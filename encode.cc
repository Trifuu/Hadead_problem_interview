#include <iostream>

#define MAXIMUM_TABLE_LENGTH 16


char* unique_symbol_table = nullptr;
char unique_symbol_table_length = 0;


void scan(char* input, int length) {

    
    for (int i = 0; i < length; i++) {
        int j;

        for (j = 0; j < unique_symbol_table_length; j++) {
            if (unique_symbol_table[j] == input[i]) {
                break;
            }
        }
        if (j == unique_symbol_table_length) {
            //stop the search when it reached the maximum of unique symbols
            if(unique_symbol_table_length == MAXIMUM_TABLE_LENGTH)
            {
                std:: cerr << "Error: The number of unique symbols is greater than 16.";
                exit(1);
            }

            unique_symbol_table[j] = input[i];
            unique_symbol_table_length++;
        }
    }
}

int search_symbol_index(char input)
{
    int k;
    for (k = 0; k < unique_symbol_table_length; k++) {
            if (unique_symbol_table[k] == input) {
                return k;
            }
        }
    return k;
}

int main() {
    char *out = nullptr;
    char *input = nullptr;
    int i,k1,k2,j,dim_out;

    input = new char[1024];

    //read all the symbols from the input stdin
    for (i = 0;; i++) {
        std::cin.get(input[i]);
        if (std::cin.eof())
            break;
    }

    unique_symbol_table = new char[16];

    //create the unique_symbol_table array
    scan(input, i);

    //write to stdout the informations regarding the number and values for the unique_symbol_table
    std::cout.put(unique_symbol_table_length);
    std::cout.write(unique_symbol_table, unique_symbol_table_length);

    //write to stdout the length of the input array of symbols
    std::cout.put(i);

    //calculate the output encoded array length
    dim_out = (i + 1) / 2;
    out = new char[dim_out];

    //create the output encoded array
    for (j = 0; j < i - 1; j += 2) {
        
        k1 = search_symbol_index(input[j]);
        k2 = search_symbol_index(input[j + 1]);

        out[j / 2] = k1 & 0xf;
        out[j / 2] <<= 4;
        out[j / 2] |= k2 & 0xf;
    }
    //if the length of the input array of symbols is odd, encode the last character
    if ( j == i - 1) {
        std:: cerr << "Intra aici"<< std::endl;
        k1 = search_symbol_index(input[j]);
        out[dim_out - 1] = k1 & 0xf;
    }

    //write encoded array of symbols to stdout
    std::cout.write(out, dim_out);

    //free all the allocated memory
    delete []out;
    delete []input;
    delete []unique_symbol_table;
    return 0;
}