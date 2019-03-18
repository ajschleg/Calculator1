// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//

template <typename T>
Stack <T>::Stack (void)
// COMMENT You have magic numbers below.
:   top_ofStack_(0),
    size_ofStack_(0),
    items(size_ofStack_)
    //new returns a pointer to the array, which *array will then be that pointer
    //so this will try to create an array of type T* and return a pointer to that array
    //T is an int so calling new will return an int* and then compiler will try and make array that pointer
    //but since array is an Array<int>* it will not be compatible.
    //hence the error cant convert T* to Array<T>*
    //array(new T[size_ofStack_])
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
:   top_ofStack_(stack.top_ofStack_),
    size_ofStack_(stack.size_ofStack_),
    items(stack.size_ofStack_)
{
    for (int i = 0; i < this->top_ofStack_; ++i) {
        this->items[i] = stack.items[i];
    }
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    //will go to base_array destructor
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    if(this->top_ofStack_ < this->size_ofStack_)
    {
        items[top_ofStack_++] = element;
    }
    else
    {

        items.resize(size_ofStack_+ 1);
        this->size_ofStack_++;
        items[top_ofStack_++] = element;
    }
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(this->top_ofStack_ > 0)
    {
        this->items[top_ofStack_--];
    }
    else
        throw empty_exception("Stack is empty\n");
}


//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    this->top_ofStack_ = rhs.top_ofStack_;
    this->size_ofStack_ = rhs.size_ofStack_;
    this->items = rhs.items;

/*    //check for self assignment
    if(this == &rhs)
        return *this;
    //free pointer
    this->items.~Array();

    this->top_ofStack_ = rhs.top_ofStack_;
    this->size_ofStack_ = rhs.size_ofStack_;
    *//*This is whats causing the error
     * new will return a pointer to an array
     * But want we really want is to just set this->items = Array<T> items(size)<---- no that declares on stack
     * instantiate on heap using new and return a pointer to the items
     * we want to just instantiate a new Array*//*
    //this->items = new T[this->size_ofStack_];

    Array<T> *items = 0;
    items = new Array<T>(size_ofStack_);
    for (int i = 0; i < this->top_ofStack_; ++i) {
        this->items[i] = rhs.items[i];
    }*/

    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    //"pop" off the stack until the top is 0
    while(this->top_ofStack_ != 0)
    {
        this->items[top_ofStack_--];
    }
}

template <typename T>
void Stack <T>::print() {
    for (int i = 0; i < top_ofStack_; ++i) {
        std::cout<<"["<<items[i]<<"]";
    }
    std::cout<<std::endl;
}

