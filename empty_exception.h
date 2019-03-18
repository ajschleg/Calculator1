//
// Created by flynn on 3/24/18.
//

#ifndef CS36300_SPRING2018_COMPOSITION_EMPTY_EXCEPTION_H
#define CS36300_SPRING2018_COMPOSITION_EMPTY_EXCEPTION_H

#include <exception>
// COMMENT You are to refactor this exception so that the Queue and
// Stack can use the same exception, thereby increasing the portablity
// of this exception.

/**
 * @class empty_exception
 *
 * Exception thrown to indicate the stack is empty.
 */
//empty exception is based on std::exception
//std::exception?
class empty_exception : public std::exception {
public:
    /// Default constructor.
    /*have empty exception aggregate from std exception
     * create .h file for empty exception so that it can be used with queue as well.*/
    empty_exception (void) : std::exception ()
    {std::cout<<"Empty Exception thrown\n"; }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg) : std::exception()
    { std::cout<<msg;}

private:
    std::exception exception1;
};


#endif //CS36300_SPRING2018_COMPOSITION_EMPTY_EXCEPTION_H
