// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
:   Base_Array<T>(),
    cur_size_(0),
    max_size_(0)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
:   Base_Array<T>(length),
    cur_size_(length),
    max_size_(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
:   Base_Array<T>(length, fill),
    cur_size_(length),
    max_size_(length)
{

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
:   Base_Array<T>(array),
    max_size_(array.max_size_)
{

}


//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{

    if(this == &rhs)
        return *this;

    delete[] this->data_;
    this->cur_size_ = rhs.cur_size_;
    this->max_size_ = rhs.max_size_;
    this->size_ = rhs.size_;
    this->data_ = new T[this->size_];

    for (int i = 0; i < this->max_size_; ++i) {
        this->data_[i] = rhs.data_[i];
    }

    return *this;

}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{


    if(new_size < this->cur_size_)
    {
        //truncate array, max size should still save the original content
        this->cur_size_ = new_size;
        this->size_ = new_size;

    }
    if(new_size > this->cur_size_)
    {
        //allocate new space, new elements are not init to anything
        //Need to make max size greater than cur size when initializing somehow

        Array<T> * temp = 0;
        temp = new Array<T>(new_size);


        for (int i = 0; i < new_size; ++i) {
            if(i > this->cur_size_){
                temp->data_[i] = NULL;
            }

            else if(this->data_[i] == NULL){
                temp->data_[i] = NULL;
            }
            else {
                temp->data_[i] = this->data_[i];
            }
        }

        *this = *temp;

    }
    else
    {
        //cur_size_ == new_size... nothing happens
        return;
    }

}

