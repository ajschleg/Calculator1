
#include "Calculator.h"
#include <ctype.h>

Calculator::Calculator() = default;

Calculator::~Calculator() {

}

bool Calculator::infix_to_postfix(const std::string &infix, Expr_Command_Factory &factory,
                                  Array<Expr_Command *> &postfix) {
    // COMMENT: Improve the design of your commands to reduce the design
    // complexity of this method. Right now, there are too many if-else
    // statements, and a lot of duplicate code.

    // COMMENT: You should implement the precedence function on
    // the command object since it is better place there.

    /*Added temp input and temp token to count the number of expressions*/
    std::istringstream input(infix), temp_input(infix); // create a input stream parser
    std::string token, temp_token;               // current token in string/stream
    Expr_Command * cmd = nullptr;               // created command object
    Stack <Expr_Command *> temp;
    int i = 0, num_of_expr = 0;                      //position in the postfix array

    /*Count number of expressions to resize postfix array
     * that way it doesnt get resized more than once below.
     * The problem before was that postfix array was getting resized and deleting itself while it was still in the scope
     * of the loop, thus throwing seg fault when trying to access the array more then once*/
    while(!temp_input.eof()){
        temp_input >> temp_token;
        num_of_expr++;
    }
    /*resize postfix arrar with num of expr*/
    postfix.resize(num_of_expr);

    while (!input.eof ()) {
        /*extract formated input*/
        input >> token;
        if (token == "+")
            cmd = factory.create_add_command();

        else if (token == "-")
            cmd = factory.create_subtract_command ();

        else if (token == "*")
            cmd = factory.create_multiply_command();

        else if (token == "/")
            cmd = factory.create_divide_command();

        else if (token == "%")
            cmd = factory.create_modulus_command();

        else if (token == "("){
            // COMMENT: Create a design that does not require having parenthesis as
            // as command object since parenthesis are not executed.

            cmd = factory.create_lp_command();
        }

            //Pop off the stack until left parentheses is found. Also be sure to pop off the left parentheses when found.
        else if (token == ")"){
            // COMMENT: Create a design that does not require having parenthesis as
            // as command object since parenthesis are not executed.
            //SOLN dont create right parenthesis command, when right parenthesis is found pop off the stack until lp is found
            while(1) {
                std::cout<<"PrE: "<<temp.top()->get_precedence()<<std::endl;
                if(temp.top()->get_precedence() == 3) {
                    temp.pop();
                    break;
                }
                postfix[i] = temp.top();
                temp.pop();
                i++;
            }
            cmd = nullptr;
        }

            //need to check if string token is a char or number
        else if (isalpha(token[0])){
            std::cout<<"What is the value of "<<token<<"?";
            int alpha_num = 0;
            std::cin>> alpha_num;
            cmd = factory.create_number_command(alpha_num);
            postfix[i] = cmd;
            i++;
            continue;
        }

            //else its a number
        else {
            int num = std::stoi(token);
            cmd = factory.create_number_command(num);
            postfix[i] = cmd;
            i++;
            continue;
        }

        // ...
        // handle the command based on infix-to-postfix algorithm

        try {
            /*If lp or rp then cmd will be = nullptr and need to reduce the size by 2 to account for 2 parenthesis*/
            if (cmd == nullptr){
                postfix.resize(postfix.size() - 2);
                continue;
            }
            //If the precedence of the top of the stack is less than or equal to the cmd then pop
            if (cmd->get_precedence() <= temp.top()->get_precedence() && temp.top()->get_precedence() != 3) {
                postfix[i] = temp.top();
                temp.pop();
                temp.push(cmd);
                i++;
            }
                //else push cmd onto stack
            else {
                temp.push(cmd);
            }
        }
        catch (empty_exception){
            temp.push(cmd);
        }

    }


    /*pop whats left from the stack*/
    while(!temp.is_empty()) {
        /*I think the problem is here.
         * assignment operator is taking a shallow copy of the top of the stack
         * which means that the pointer is copied but the memory is not */
        postfix[i] = temp.top();

        cmd = temp.top();

        try {
            temp.pop();
        }
        catch (empty_exception)
        {}
        i++;
    }


    return true;
}