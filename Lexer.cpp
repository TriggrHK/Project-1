#include "Lexer.h"
#include <iostream>
#include <cctype>

Lexer::Lexer() {
    tokens = std::vector<Token*>();
    automata = std::vector<Automaton*>();
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens` del all parts in array
    while ((int)automata.size() >= 0){
       // delete automata[automata.size()];
        automata.pop_back();
    }
    while ((int)tokens.size() >= 0){
       // delete tokens[tokens.size()];
        tokens.pop_back();
    }
}

void Lexer::CreateAutomata() {
    automata.push_back(new UndefinedAuto());
    automata.push_back(new ColonAuto());
    automata.push_back(new ColonDashAuto());
    automata.push_back(new IdAuto());
    automata.push_back(new CommaAuto());
    automata.push_back(new CommentAuto());
    automata.push_back(new EOF_CPAuto());
    automata.push_back(new LP_Auto());
    automata.push_back(new RP_Auto());
    automata.push_back(new MultAuto());
    automata.push_back(new AddAuto());
    automata.push_back(new FactsAuto());
    automata.push_back(new PeriodAuto());
    automata.push_back(new Q_MarkAuto());
    automata.push_back(new QueriesAuto());
    automata.push_back(new SchemesAuto());
    automata.push_back(new RP_Auto());
    automata.push_back(new RulesAuto());
    automata.push_back(new StringAuto());
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code

    int lineNumber = 1;
    // While there are more characters to tokenize
    do {
        int maxRead = 0;
        Automaton *maxAutomaton = automata[0];

        // TODO: you need to handle whitespace in between tokens
        while (isspace(input[0]) || input[0] == '\n') {
            if (input[0] == '\n') {
                lineNumber++;
            }
            input = input.substr(1);
        }
        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        for (int i = 0; i < (int) automata.size(); i++) {
            int inputRead = automata[i]->Start(input);
            if (inputRead >= maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata[i];
            }
        }
        if (maxRead > 0) {
            Token *newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        if (!input.empty()) {
            input = input.substr(maxRead);
        }
        if (input.empty() && tokens[(int)tokens.size()-1]->codeToString() != "EOF") {
            maxRead = 0;
            for (int i = 0; i < (int) automata.size(); i++) {
                int inputRead = automata[i]->Start("");
                if (inputRead >= maxRead) {
                    maxRead = inputRead;
                    maxAutomaton = automata[i];
                }
            }
            Token *eofToken = maxAutomaton->CreateToken("", lineNumber);
            tokens.push_back(eofToken);
        }
    } while (!input.empty());

       //add end of file token to all tokens*/
    for(int i = 0; i < (int)tokens.size(); i++) {
        std::cout << "(" << tokens[i]->codeToString() << ",\"" << tokens[i]->getDesc() << "\","
                  << tokens[i]->getLineNum() << ")" << "\n";
    }
    std::cout << "Total Tokens = " << tokens.size();
}