
#ifndef CS36300_SPRING2018_CALCULATOR1_MODULUS_COMMAND_H
#define CS36300_SPRING2018_CALCULATOR1_MODULUS_COMMAND_H

#include <iostream>
#include "Expr_Command.h"

class Modulus_Command : public Expr_Command {
public:
    Modulus_Command() : precedence(2) {}

    void execute(Stack<int> &s_)
    {
        int n1, n2, i, j, k;
        n1 = s_.top();
        n2 = s_.top();
        i = n1 / n2;
        j = i * n1;
        k = n1 - j;

        s_.push( k );
    }

    int get_number()
    {
        return 0;
    }

    int get_precedence() override {return precedence;}

private:
    int precedence;
};


#endif //CS36300_SPRING2018_CALCULATOR1_MODULUS_COMMAND_H
