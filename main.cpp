#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include <iostream>
#include <fstream>


int main(int argc, char** argv) {
    std::string inputLines;
    std::string line;
    std::ifstream inFile(argv[1]);
    if (inFile.is_open()){
        while ( getline (inFile,line) ){
            inputLines += line + "\n";
           // std::cout << line << '\n';
        }
        inFile.close();
        // std::cout << "whole file is" << "\n" << inputLines;
    }
    else {
        std::cout << "Unable to open file";
    }

    auto* lexer = new Lexer();
    lexer->Run(inputLines);

    auto parser = new Parser(lexer->getTokenList());
    datalogProgram datalog = datalogProgram();
    parser->parse(datalog);

    auto relations = Database();
    auto interpreter = Interpreter(datalog, relations);
    interpreter.Run();
    std::cout << "Did it!";
    delete lexer;
    delete parser;
    return 0;
}