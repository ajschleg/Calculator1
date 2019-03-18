
#ifndef CS36300_SPRING2018_CALCULATOR1_EXPR_COMMAND_FACTORY_H
#define CS36300_SPRING2018_CALCULATOR1_EXPR_COMMAND_FACTORY_H

/*Abstract Factory Class*/
#include <iostream>
#include "Binary_Op_Command.h"
#include "Parentheses_Command.h"
#include "Num_Command.h"
#include "Modulus_Command.h"

class Expr_Command_Factory {
protected:
    Expr_Command_Factory() = default;

public:
    /*Interface, subclasses must override each method*/
    virtual ~Expr_Command_Factory() = 0;
    virtual Num_Command * create_number_command (int num) = 0;
    virtual Add_Command * create_add_command () = 0;
    virtual Subtract_Command * create_subtract_command () = 0;
    virtual Multiply_Command * create_multiply_command () = 0;
    virtual Divide_Command * create_divide_command () = 0;

    virtual Left_Parentheses_Command * create_lp_command() = 0;
    virtual Modulus_Command * create_modulus_command() = 0;

private:
    //Subclasses cannot access these methods, because you should never be able to instantiate an abstract class
    Expr_Command_Factory (const Expr_Command_Factory &);
    const Expr_Command_Factory &operator = (const Expr_Command_Factory &);
};

//Expr_Command_Factory::~Expr_Command_Factory() = default;

#endif //CS36300_SPRING2018_CALCULATOR1_EXPR_COMMAND_FACTORY_H
