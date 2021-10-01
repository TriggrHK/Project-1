//
// Created by trevo on 9/28/2021.
//

#ifndef PROJECT_1_DATALOGPROGRAM_H
#define PROJECT_1_DATALOGPROGRAM_H
#include <vector>
#include "Rule.h"


class datalogProgram {
private:
    std::vector<Parameter> params;
    std::vector<Rule> rules;
    std::vector<Predicate> predics;
public:
    datalogProgram();
  //  void add_Vector(Parameter inParm);
   // void add_Vector(Rule inRule);
   // void add_Vector(Predicate inPred);
  //  void to_String();
};


#endif //PROJECT_1_DATALOGPROGRAM_H
