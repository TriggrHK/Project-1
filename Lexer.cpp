#include "Lexer.h"
#include "iostream"
#include "cctype"

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
    automata.push_back(new ColonAuto());
    automata.push_back(new ColonDashAuto());
    automata.push_back(new CommaAuto());
    automata.push_back(new CommentAuto());
    automata.push_back(new EOF_CPAuto());
    automata.push_back(new IdAuto());
    automata.push_back(new LP_Auto());
    automata.push_back(new RP_Auto());
    automata.push_back(new MultAuto());
    automata.push_back(new AddAuto());
    automata.push_back(new FactsAuto());
    automata.push_back(new PeriodAuto());
    automata.push_back(new Q_MarkAuto());
    automata.push_back(new QueriesAuto());
    automata.push_back(new RP_Auto());
    automata.push_back(new RulesAuto());
    automata.push_back(new StringAuto());
    automata.push_back(new SchemesAuto());
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code

    int lineNumber = 1;
    // While there are more characters to tokenize
    while (input.size() > 0) {

        int maxRead = 0;
        Automaton* maxAutomaton = automata[0];

        // TODO: you need to handle whitespace in between tokens
        if (isspace(input[0])) {
            if (input[0] == '\n') {
                lineNumber++;
            }
            input = input.substr(1);
        }
        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        for(int i = 0; i < ((int)automata.size())-1; i++) {
            int inputRead = automata[i]->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata[i];
                //new lines read = machine.newlinesread()
            }
        }
        // Here is the "Max" part of the algorithm
        if (maxRead > 0) {
            Token newToken = *maxAutomaton->CreateToken(input, lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(&newToken);
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            maxRead = 1;
            Token undefinedToken = *maxAutomaton->CreateToken("UNDEFINED", lineNumber);
            //(with first character of input)
            tokens.push_back(&undefinedToken);
        }
        // Update `input` by removing characters read to create Token
        if(!input.empty()) {
            input = input.substr(maxRead);
        }
    }
    //add end of file token to all tokens
    for(int i = 0; i < tokens.size(); i++) {
        std::cout << "(" << tokens[i]->codeToString() << ", \"" << tokens[i]->getDesc() << "\" ,"
                  << tokens[i]->getLineNum() << ")" << "\n";
    }
}