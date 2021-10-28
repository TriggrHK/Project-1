//
// Created by trevo on 9/28/2021.
//

#ifndef PROJECT_1_DATALOGPROGRAM_H
#define PROJECT_1_DATALOGPROGRAM_H
#include <vector>
#include "Rule.h"

class datalogProgram {
private:
    std::vector<Rule> rules;
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Predicate> queries;
public:
    datalogProgram(){}
    void copy_rule(std::vector<Rule> newRules);
    void copy_scheme(std::vector<Predicate> newSchemes);
    void copy_fact(std::vector<Predicate> newFacts);
    void copy_query(std::vector<Predicate> newQueries);
    std::vector<Rule> getRules();
    std::vector<Predicate> getSchemes();
    std::vector<Predicate> getFacts();
    std::vector<Predicate> getQueries();
};


#endif //PROJECT_1_DATALOGPROGRAM_H
