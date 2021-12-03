#ifndef PROJECT_1_INTERPRETER_H
#define PROJECT_1_INTERPRETER_H
#include "datalogProgram.h"
#include "Database.h"

class Interpreter {
//connects datalog and database classes
//datalog should have a vector of schemes, facts, rules, adn queries
//stores a datalogprogram value
//makes a database using them and stores as data member
//look at slides video 10:30
private:
    datalogProgram parsedData;
    Database relations;
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Predicate> queries;
    std::vector<Rule> rules;
public:
    Interpreter(){}
    Interpreter(datalogProgram newParse, Database newRelations);
    void Run();
    Relation evaluatePredicate(Predicate p, Relation compareRel);
    Relation createPredicates(const Predicate& p);
    void evaluateRules();
    void evaluateQueries();
};


#endif //PROJECT_1_INTERPRETER_H
