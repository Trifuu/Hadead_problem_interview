#include <iostream>

char* symbol_table = nullptr;
char symbol_table_length = 0;

int main() {
    symbol_table = new char[1024];

    std::cin.get(symbol_table_length);
    std::cin.read(symbol_table, symbol_table_length);
    
    char in;
    int len,i;
    std::cin.get(in);
    len = (int) in;

    for (i = 0; i < len - 1; i += 2) {
        char in;
        std::cin.get(in);

        std::cout.put(symbol_table[(in >> 4) & 0xf]);
        std::cout.put(symbol_table[in & 0xf]);
    }
    if ( i == len - 1){
        std::cin.get(in);
        std::cout.put(symbol_table[in & 0xf]);
    }
    
    
    delete []symbol_table;
    return 0;
}