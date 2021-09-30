//
// Created by trevo on 9/29/2021.
//

#ifndef PROJECT_1_RULE_H
#define PROJECT_1_RULE_H
#include <vector>
#include "Predicate.h"

class Rule {
private:
    Predicate headPredicate;
    std::vector<Predicate> bodyPredicates;
public:
    Rule(Predicate inPred, std::vector<Predicate> inPredVector);
    void to_String();
};


#endif //PROJECT_1_RULE_H
