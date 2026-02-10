#ifndef MY_UNIQUE_PTR_H
#define MY_UNIQUE_PTR_H

template <typename T>
class my_unique_ptr{
private:
    T* ptr;
public:
    my_unique_ptr():ptr(nullptr){}
    my_unique_ptr(T* otherPtr):ptr(otherPtr){}

    my_unique_ptr(const my_unique_ptr& other)=delete;
    my_unique_ptr& operator=(const my_unique_ptr& other)=delete;
    
    my_unique_ptr(my_unique_ptr&& other): ptr(other.ptr){
            other.ptr=nullptr;
    }
    
    my_unique_ptr& operator=(my_unique_ptr&& other){
        if(this!=&other){
            delete ptr;
            ptr=other.ptr;
            other.ptr=nullptr;
        }
        return *this;
    }

    ~my_unique_ptr(){
        delete ptr;
    }
    T& operator*(){
        return *ptr;
    }
    T operator*() const{
        return *ptr;
    }
    T* operator->(){
        return ptr;
    }
    T const* operator->() const{
        return ptr;
    }
    operator bool() const{
        return ptr!=nullptr;
    }
};

#endif //MY_UNIQUE_PTR_H