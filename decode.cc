#include <iostream>

void read_symbol_table(std::string &symbol_table) {
    char symbol_table_length = 0;
    std::cin.get(symbol_table_length);

    symbol_table = std::string(symbol_table_length, ' ');
    std::cin.read(&symbol_table[0], symbol_table_length);
}

void decode(const std::string &symbol_table, std::string &decode_message) {
    char character;
    
    int size = sizeof(size_t);
    size_t length = 0;
    for (int i = 0; i < size; i++) {
        std::cin.get(character);
        length = character << 8 * i & (0xff << 8 * i) | length;
    }

    decode_message = std::string(length, ' ');
    // decode the message
    for (int i = 0; i < decode_message.length() - 1; i += 2) {

        std::cin.get(character);
        decode_message[i] = symbol_table[(character >> 4) & 0xf];
        decode_message[i + 1] = symbol_table[character & 0xf];
    }
    // if the message have an odd length decode the last character separately
    if (decode_message.length() % 2 == 1) {
        std::cin.get(character);
        decode_message[decode_message.length() - 1] = symbol_table[character & 0xf];
    }
}

int main() {
    std::string symbol_table, decode_message;
    
    // read the unique symbol table
    read_symbol_table(symbol_table);
    
    // decode the message using the symbol table
    decode(symbol_table, decode_message);
    
    // print the decoded message to stdout
    std::cout.write(decode_message.c_str(), decode_message.length());
    
    return 0;
}