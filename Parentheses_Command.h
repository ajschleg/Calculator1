//
// Created by flynn on 3/18/18.
//

#ifndef CS36300_SPRING2018_CALCULATOR1_UNARY_OP_COMMAND_H
#define CS36300_SPRING2018_CALCULATOR1_UNARY_OP_COMMAND_H


#include "Expr_Command.h"

class Parentheses_Command : public Expr_Command{
protected:
    Parentheses_Command(){}
    int precedence;

public:
    virtual void execute(Stack<int> &stack)
    {
        //dont need anything here because parentheses just pops from the stack
    }
    virtual void evaluate(){
        //dont need anything here because parentheses just pops from the stack

    }

};

class Left_Parentheses_Command : public Parentheses_Command{
public:
    explicit Left_Parentheses_Command() : precedence(3) {}
    virtual int get_precedence() {return precedence;}

private:
    int precedence;
};


#endif //CS36300_SPRING2018_CALCULATOR1_UNARY_OP_COMMAND_H
