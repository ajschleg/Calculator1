

#ifndef CS36300_SPRING2018_CALCULATOR1_EXPR_COMMAND_H
#define CS36300_SPRING2018_CALCULATOR1_EXPR_COMMAND_H

#include <iostream>
#include "Stack.h"

/*Interface for each command to inherit from*/
class Expr_Command {
public:
    virtual void execute(Stack<int> &stack) = 0;
    virtual int get_precedence() = 0;

};


#endif //CS36300_SPRING2018_CALCULATOR1_EXPR_COMMAND_H
