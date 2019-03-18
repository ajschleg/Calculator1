// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.


//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return this->size_ofStack_;
}

template <typename T>
inline
size_t Stack <T>::top_ofStk() const
{
    return this->top_ofStack_;
}




//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    if(this->top_ofStack_ > 0)
        //const correctness of stack prohibits change of stack vars.
        //so doing top of stack-- would modify t.o.s. value
        //where as t.o.s. would not but still return the top -1.
        return this->items[top_ofStack_ - 1];
    else
        throw empty_exception("Stack is empty!");
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    return this->top_ofStack_ <= 0;
}
