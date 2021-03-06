#include <iostream>

#define MAXIMUM_UNIQUE_SYMBOLS 16

void read_all_symbols(std::string &input) {

    while(true) {
        input.push_back(std::cin.get());
        
        if (std::cin.eof())
        {
            input.pop_back();
            break;
        }   
    }
}

void create_symbol_table(const std::string &input, std::string &symbol_table) {

    for (int i = 0; i < input.length(); i++) {
        int j;

        for (j = 0; j < symbol_table.length(); j++) {
            if (symbol_table[j] == input[i]) {
                break;
            }
        }

        if (j == symbol_table.length()) {
            //stop the search when it exceed the maximum of unique symbols
            if(symbol_table.length() == MAXIMUM_UNIQUE_SYMBOLS)
            {
                std:: cerr << "Error: The number of unique symbols is > 16." << std::endl;
                exit(1);
            }

            symbol_table.push_back(input[i]);
        }
    }
}

int search_symbol_index(const char &input, const std::string &symbol_table) {
    int index;
    for (index = 0; index < symbol_table.length(); index++) {
            if (symbol_table[index] == input) {
                return index;
            }
        }
    return index;
}

void encode(const std::string &input, const std::string &symbol_table,
            std::string &out) {

    char encoded_character;
    
    //create the output encoded array
    for (int j = 0; j < input.length() - 1; j += 2) {
        int k1, k2;
        k1 = search_symbol_index(input[j], symbol_table);
        k2 = search_symbol_index(input[j + 1], symbol_table);

        encoded_character = k1 & 0xf;
        encoded_character <<= 4;
        encoded_character |= k2 & 0xf;

        out.push_back(encoded_character);
    }

    //if the message have an odd length encode the last character separately
    if (input.length() % 2 == 1) {
        int k;
        k = search_symbol_index(input[input.length() - 1], symbol_table);
        encoded_character = k & 0xf;
        out.push_back(encoded_character);
    }
}

void write_to_stdout(const std::string &symbol_table, const std::string &out,
                     std::string input)
{
    //write to stdout the informations regarding the number and values for the symbol_table
    std::cout.put(symbol_table.length());
    std::cout.write(symbol_table.c_str(), symbol_table.length());

    //write to stdout the length of the input array of symbols
    int size = sizeof(size_t);
    size_t length = input.length();
    for( int i = 0; i< size; i++)
    {
        std::cout.put((char)(length >> 8*i) & 0xff);
    }
    
    //write encoded array of symbols to stdout
    std::cout.write(out.c_str(), (input.length() + 1) / 2);
}

int main() {

    std::string input, out, symbol_table;

    //read all the symbols from the input stdin
    read_all_symbols(input);

    //create the symbol_table array
    create_symbol_table(input, symbol_table);

    //calculate the output encoded array
    encode(input, symbol_table, out);

    //write to stdout all the encoded message informations
    write_to_stdout(symbol_table, out, input);

    return 0;
}