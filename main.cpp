#include "Lexer.h"
#include "fstream"
#include "iostream"

int main(int argc, char** argv) {
    std::string inputLines;
    std::string line;
    std::ifstream inFile(argv[1]);
    if (inFile.is_open()){
        while ( getline (inFile,line) ){
            inputLines += line + "\n";
            std::cout << line << '\n';
        }
        inFile.close();
        //std::cout << "whole file is" << "\n" << inputLines;
    }
    else std::cout << "Unable to open file";
    Lexer* lexer = new Lexer();

    // TODO
    lexer->Run(inputLines);

    // get the tokens from lexer and output in the right format
   // std::cout << "Did it!";
    delete lexer;

    return 0;
}