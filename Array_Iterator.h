/*This Iterator is a friend of Base_Array
 * This is an Iterator Pattern*/


#ifndef CS36300_SPRING2018_CALCULATOR1_ARRAY_ITERATOR_H
#define CS36300_SPRING2018_CALCULATOR1_ARRAY_ITERATOR_H

#include <iostream>
#include "Base_Array.h"

/*forward declaration of Base array*/
template <typename T>
class Base_Array;

template <typename T>
class Array_Iterator {

public:
    Array_Iterator (Base_Array <T> & arr) : a_(arr), curr_(0) {}
    ~Array_Iterator(){}

    bool is_done() { return this->curr_ >= this->a_.size_;}
    bool advance() { ++ this->curr_;}
    T &operator *() { return this->a_.data_[this->curr_];}
    T *operator ->() { return &this->a_.data_[this->curr_];}

private:
    Base_Array<T> & a_;
    size_t curr_;
};


#endif //CS36300_SPRING2018_CALCULATOR1_ARRAY_ITERATOR_H
