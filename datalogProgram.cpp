#include "datalogProgram.h"

/*datalogProgram::datalogProgram() {
}*/

void datalogProgram::copy_rule(std::vector<Rule> newRules){
    rules = newRules;
}
void datalogProgram::copy_scheme(std::vector<Predicate> newSchemes){
    schemes = newSchemes;
}
void datalogProgram::copy_fact(std::vector<Predicate> newFacts){
    facts = newFacts;
}
void datalogProgram::copy_query(std::vector<Predicate> newQueries){
    queries = newQueries;
}
std::vector<Rule> datalogProgram::getRules(){
    return rules;
}
std::vector<Predicate> datalogProgram::getSchemes(){
    return schemes;
}
std::vector<Predicate> datalogProgram::getFacts(){
    return facts;
}
std::vector<Predicate> datalogProgram::getQueries(){
    return queries;
}

/*void datalogProgram::to_String() {
    for(int i = 0; i < predics.size(); i++){
        predics[i].to_String();
    }
}*/
