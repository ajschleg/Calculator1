// $Id: Base_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


template <typename T>
Base_Array<T>::Base_Array()
:   data_(0),
    size_(0)
{

}

template <typename T>
Base_Array<T>::Base_Array(size_t length)
:   data_(new T[length]),
    size_(length)

{

}

template <typename T>
Base_Array<T>::Base_Array(size_t length, T fill)
:   data_(new T[length]),
    size_(length)

{
    this->fill(fill);
}

template <typename T>
Base_Array<T>::Base_Array(const Base_Array &arr)
:   data_(new T[arr.size_]),
    size_(arr.size_)

{
    /*this is all wrong fix*/
    for (int i = 0; i < size_; ++i) {
        this->data_[i] = arr.data_[i];
    }
}

template <typename T>
Base_Array<T>::~Base_Array()
{
    delete []data_;
}

//
//fill
//
template <typename T>
void Base_Array<T>::fill(T fill)
{
    for (int i = 0; i < this->size_; ++i) {
        this->data_[i] = fill;
    }
}

//
//operator []
//
template <typename T>
T & Base_Array<T>::operator [] (size_t index)
{
    /*Get the value at index.
    For use with non-const array objects
        ex. Array example();
    data_[index] becomes data_.operator[4]
    Declaring the return type as char & allows you to assign values to a particular element.
        ex. array[5] = 'a';

    get() returns a char so we need to convert to pointer in order to return.
    */
    if(index > this->size_)
        throw std::out_of_range("Index out of range.");
    return this->data_[index];
}

//
// operator [] const
//
template <typename T>
const T & Base_Array<T>::operator [] (size_t index) const
{
    /*
    For use with const array objects
        ex. const Array example2();
    This is a const function so member vars are unchangeable
    */
    if(index > this->size_)
        throw std::out_of_range("Index out of range.");
    return this->data_[index];
}

//
//get
//
template <typename T>
T Base_Array<T>::get(size_t index) const
{
    if(index > this->size_)
        throw std::out_of_range("Index out of range.");
    return this->data_[index];
}

//
//set
//
template <typename T>
void Base_Array<T>::set(size_t index, T value)
{
    if(index > this->size_)
        throw std::out_of_range("Index out of range.");
    this->data_[index] = value;
}

//
// find (char)
//
template <typename T>
int Base_Array<T>::find(T item) const
{
    return this->find(item, 0);
}

//
//find (T size_t)
//
template <typename T>
int Base_Array<T>::find(T item, size_t start) const
{
    if(start > this->size_)
        throw std::out_of_range("Index out of range.");

    for (int i = start; i < size_; ++i) {
        if(this->data_[i] == item)
            return i;
    }
    return -1;
}


//
//reverse
//
template <typename T>
void Base_Array<T>::reverse()
{
    int i = this->size_ - 1;
    int j = 0;
    while(i > j)
    {
        T temp = this->data_[i];
        this->data_[i] = this->data_[j];
        this->data_[j] = temp;
        i--;
        j++;
    }
}

//
//print
//
template <typename T>
void Base_Array<T>::print()
{
    for (int i = 0; i <= size_; ++i) {
        std::cout<<"["<<&data_[i]<<"]";
    }
    std::cout<<std::endl;
}

//
//= operator
//
template <typename T>
const Base_Array<T> & Base_Array<T>::operator=(const Base_Array<T> &rhs)
{
    /*    ADDED IN REDO*/
    //check if same address
    if(this == &rhs)
        return *this;

    //if not then delete old data to reallocate memory
    delete [] this->data_;
    this->size_ = rhs.size_;
    data_ = new T[this->size_];

    //copy data
    for (int i = 0; i < this->size_; ++i) {
        this->data_[i] = rhs.data_[i];
    }

    return *this;

}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{

    if(this == &rhs)
        return true;

    //compare cur sizes
    if(this->size_ != rhs.size_)
        return false;

    //compare data elements
    for (int i = 0; i < this->size_; ++i)
    {
        if(this->data_[i] != rhs.data_[i])
            return false;
    }
    return true;

}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
    if (this == &rhs)
        return false;
    return true;
}
