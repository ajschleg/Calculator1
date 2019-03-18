//
// Created by flynn on 3/29/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_CALCULATOR_H
#define CS36300_SPRING2018_CALCULATOR1_CALCULATOR_H

#include "Expr_Command_Factory.h"
#include "Array.h"
#include "Stack.h"
#include <iostream>
#include <sstream>
#include <stack>


class Calculator {
public:
    Calculator(void);

    ~Calculator();

    bool infix_to_postfix(const std::string &infix,
                          Expr_Command_Factory &factory,
                          Array<Expr_Command *> &postfix);
};

#endif //CS36300_SPRING2018_CALCULATOR1_CALCULATOR_H
