//
// Created by flynn on 3/17/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_NUM_COMMAND_H
#define CS36300_SPRING2018_CALCULATOR1_NUM_COMMAND_H


#include "Expr_Command.h"

/*Forward declaration of Stack*/
template <typename T>
class Stack;

class Num_Command : public Expr_Command {
public:
    explicit Num_Command(int n) : n_(n), precedence(0)
    {}

    virtual void execute (Stack<int> &s_){
        s_.push(this->n_);
    }

    int get_precedence() override {
        return this->precedence;
    }

    int get_number() {
        return this->n_;
    }


private:

    int n_;
    int precedence;
};


#endif //CS36300_SPRING2018_CALCULATOR1_NUM_COMMAND_H
