/*This uses the Template method and Command Pattern to provide common functionality for Binary Operator subclasses*/

#ifndef CS36300_SPRING2018_CALCULATOR1_BINARY_OP_COMMAND_H
#define CS36300_SPRING2018_CALCULATOR1_BINARY_OP_COMMAND_H

#include <iostream>
#include "Expr_Command.h"


/*Command*/
class Binary_Op_Command : public Expr_Command {
protected:
    Binary_Op_Command(){}


public:
    virtual void execute(Stack<int> &stack)
    {
        int n2, n1;
        n1 = stack.top();
        stack.pop();
        n2 = stack.top();
        stack.pop();

        int result = this->evaluate(n1, n2);
        stack.push(result);
    }



    virtual int evaluate (int n1, int n2) const = 0;



};


/*Concrete Commands*/
class Add_Command : public Binary_Op_Command {
public:
    //Init constructor
    explicit Add_Command() : Binary_Op_Command(), precedence(1){}
    virtual int get_precedence() {return precedence;}

private:
    int evaluate (int n1, int n2) const {
        return n1 + n2;
    }
    int precedence;


};

class Subtract_Command : public Binary_Op_Command {
public:
    explicit Subtract_Command() : Binary_Op_Command(), precedence(1) {}
    virtual int get_precedence() {return precedence;}
private:
    int evaluate (int n1, int n2) const {
        return n2 - n1;
    }
    int precedence;

};

class Multiply_Command : public Binary_Op_Command {
public:
    explicit Multiply_Command() : Binary_Op_Command(), precedence(2) {}
    virtual int get_precedence() {return precedence;}
private:
    int evaluate (int n1, int n2) const {
        return n1 * n2;
    }
    int precedence;

};

class Divide_Command : public Binary_Op_Command {
public:
    explicit Divide_Command() : Binary_Op_Command(), precedence(2) {}
    virtual int get_precedence() {return precedence;}
private:
    int evaluate (int n1, int n2) const {
        return n2 / n1;
    }
    int precedence;

};


#endif //CS36300_SPRING2018_CALCULATOR1_BINARY_OP_COMMAND_H
