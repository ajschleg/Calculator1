

#ifndef CS36300_SPRING2018_CALCULATOR1_STACK_EXPR_COMMAND_FACTORY_H
#define CS36300_SPRING2018_CALCULATOR1_STACK_EXPR_COMMAND_FACTORY_H

#include <iostream>
#include "Expr_Command_Factory.h"
#include "Stack.h"
#include "Expr_Command.h"
#include "Parentheses_Command.h"
#include "Modulus_Command.h"

/*Concrete Factory Class for creating commands*/
class Stack_Expr_Command_Factory : public Expr_Command_Factory {
public:
    //Constructor that takes an int stack
    explicit Stack_Expr_Command_Factory(Stack<int> & stack);

    //destructor
    ~Stack_Expr_Command_Factory(){}
    virtual Num_Command * create_number_command (int num); //should return (auto) pointer to class allocated on the stack.
    virtual Add_Command * create_add_command ();
    virtual Subtract_Command * create_subtract_command ();
    virtual Multiply_Command * create_multiply_command ();
    virtual Divide_Command * create_divide_command ();

    virtual Left_Parentheses_Command * create_lp_command();
    virtual Modulus_Command * create_modulus_command();

private:
    Stack<int> stack_; //int stack for numbers
};


#endif //CS36300_SPRING2018_CALCULATOR1_STACK_EXPR_COMMAND_FACTORY_H
