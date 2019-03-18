/*Auto pointer for array class
 * this is a proxy pattern
 * the pointer is made to look and act like a pointer except it deletes memory on its own.
 * */
#ifndef CS36300_SPRING2018_CALCULATOR1_ARRAY_AUTO_PTR_H
#define CS36300_SPRING2018_CALCULATOR1_ARRAY_AUTO_PTR_H

#include <iostream>
template <typename T>
class array_auto_ptr {
public:
    array_auto_ptr() : ptr_(0) {}

    array_auto_ptr(T *ptr) : ptr_(ptr) {}

    ~array_auto_ptr() {
        if (0 != this->ptr_)
            delete[] this->ptr_;
    }

    T *operator->() { return this->ptr_; }

    T &operator*() { return *this->ptr_; }

    operator T *() { return this->ptr_; }

private:
    T *ptr_;
};
#endif //CS36300_SPRING2018_CALCULATOR1_ARRAY_AUTO_PTR_H
