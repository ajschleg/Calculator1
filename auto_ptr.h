

#ifndef CS36300_SPRING2018_CALCULATOR1_AUTO_PTR_H
#define CS36300_SPRING2018_CALCULATOR1_AUTO_PTR_H

template <typename T>
class auto_ptr
{
public:
    auto_ptr() : ptr_(0) {}
    auto_ptr(T * ptr) : ptr_(ptr) {}

    ~auto_ptr()
    {
        if (0 != this->ptr_)
            delete this->ptr_;
    }

    T * operator -> () { return this->ptr_;}
    T & operator * () { return  *this->ptr_;}
    operator T * () { return this->ptr_;}

private:
    T * ptr_;

};

#endif //CS36300_SPRING2018_CALCULATOR1_AUTO_PTR_H
