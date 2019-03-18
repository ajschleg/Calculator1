
#include "Stack_Expr_Command_Factory.h"


/*Create concrete commands and return a pointer to those commands
 * Concrete products of factory*/

/*SOLUTION TO COMMENTS
 * This is all wrong this allocates memory on the stack and not the heap.
 * This will cauuse the pointer to the object to be deleted once the function exits.
 * The stack will delete its contents when funciton exits.
 *
 * Use new
 *
 * Refactor using the heap. Be sure to delete allocated memory. AUTO POINTER*/
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack<int> &stack)
:   stack_(stack)
{

}


Num_Command* Stack_Expr_Command_Factory::create_number_command(int num) {
  // COMMENT: You will have a runtime error since you are returning a
  // local variable to the client. This variable will be destroyed, and
  // the client will be accessing garbage.
    Num_Command *num_command = 0;
    num_command = new Num_Command(num);
    return num_command;
}

Add_Command* Stack_Expr_Command_Factory::create_add_command() {
  // COMMENT: You will have a runtime error since you are returning a
  // local variable to the client. This variable will be destroyed, and
  // the client will be accessing garbage.
    Add_Command *add_command = 0;
    add_command = new Add_Command();
    return add_command;
}

Subtract_Command* Stack_Expr_Command_Factory::create_subtract_command() {
  // COMMENT: You will have a runtime error since you are returning a
  // local variable to the client. This variable will be destroyed, and
  // the client will be accessing garbage.
    Subtract_Command *subtract_command = 0;
    subtract_command = new Subtract_Command();
    return subtract_command;
}

Multiply_Command* Stack_Expr_Command_Factory::create_multiply_command() {
  // COMMENT: You will have a runtime error since you are returning a
  // local variable to the client. This variable will be destroyed, and
  // the client will be accessing garbage.
    Multiply_Command *multiply_command = 0;
    multiply_command = new Multiply_Command();
    return multiply_command;
}

Divide_Command* Stack_Expr_Command_Factory::create_divide_command() {
  // COMMENT: You will have a runtime error since you are returning a
  // local variable to the client. This variable will be destroyed, and
  // the client will be accessing garbage.
    Divide_Command *divide_command = 0;
    divide_command = new Divide_Command();
    return divide_command;
}

Left_Parentheses_Command* Stack_Expr_Command_Factory::create_lp_command() {
  // COMMENT: You will have a runtime error since you are returning a
  // local variable to the client. This variable will be destroyed, and
  // the client will be accessing garbage.
    Left_Parentheses_Command *left_parentheses_command = 0;
    left_parentheses_command = new Left_Parentheses_Command();
    return left_parentheses_command;

}


Modulus_Command* Stack_Expr_Command_Factory::create_modulus_command() {
  // COMMENT: You will have a runtime error since you are returning a
  // local variable to the client. This variable will be destroyed, and
  // the client will be accessing garbage.
    Modulus_Command *modulus_command = 0;
    modulus_command = new Modulus_Command();
    return modulus_command;

}