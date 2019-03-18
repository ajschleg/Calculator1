
#include "Base_Array.h"
#include "Array.h"
#include "Stack.h"
#include "auto_ptr.h"
#include "Array_Iterator.h"
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"
#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
#include <map>
#include "Calculator.h"

// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.

//Solution create calculator class




int main(void)
{
    std::string infix;
  /*  std::map<char, int> mymap;
    int num;
    char var;
    std::cin>>var;

    *//*for variable
     * Need to store var char and then ask user to input number*//*
    mymap[var];
    std::cin>>num;

    // show content:
    for (auto it=mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';*/


    while(1) {
        std::cout << "Please enter your expression: ";
        std::getline(std::cin, infix);
        if(infix == "Quit")
            return 0;

        Stack<int> result;
        Calculator calculator;

        //Declare concrete factory to create command objects
        Stack_Expr_Command_Factory factory(
                result); //NOTE having trouble initializing this. Somehow compiler is saying that this has pure virtual methods

        Array<Expr_Command *> postfix(1);
        calculator.infix_to_postfix(infix, factory, postfix);



        for (int i = 0; i < postfix.size(); ++i) {
            postfix[i]->execute(result);
        }
        //evaluate postfix


        int res = result.top();
        std::cout << "Answer: " << res << std::endl;
    }
    return 0;
}

