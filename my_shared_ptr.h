#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H

template <typename T>
class my_shared_ptr{
private:
    int* count;
    T* ptr;

    void release(){
        if(count){

            --(*count);

            if(*count==0){
                delete ptr;
                delete count;
            }
        }
    }

public:
    my_shared_ptr():ptr(nullptr),count(nullptr){}
    my_shared_ptr(T* ptr):ptr(ptr),count(new int(1)){}

    my_shared_ptr(const my_shared_ptr& other):ptr(other.ptr),count(other.count){
        if(count) (*count)++;
    }
    
    my_shared_ptr& operator=(const my_shared_ptr& other){
        if(this!=&other){
            release();

            ptr=other.ptr;
            count=other.count;
            if(count) (*count)++;


        }
        return *this;
    }

    my_shared_ptr(my_shared_ptr&& other):ptr(other.ptr),count(other.count){
        other.ptr=nullptr;
        other.count=nullptr;

    }

    my_shared_ptr& operator=(my_shared_ptr&& other){
        if(this!=&other){
            release();

            ptr=other.ptr;
            count=other.count;

            other.ptr=nullptr;
            other.count=nullptr;


        }
        return *this;
    }
    ~my_shared_ptr(){
        release();
    }

    T& operator*(){
        return *ptr;
    }

    const T& operator*() const{
        return *ptr;
    }

    T* operator->(){
        return ptr;
    }

    const T* operator->() const{
        return ptr;
    }

    int getCount() const{
        return (count? *count : 0);
    }

    operator bool() const{
        return ptr!=nullptr;
    }
};

#endif //MY_SHARED_PTR_H