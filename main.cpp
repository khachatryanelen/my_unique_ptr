#include <iostream>
#include "my_unique_ptr.h"
#include "my_shared_ptr.h"


int main(int argc,const char* argv[]){
    my_unique_ptr<int> ptr(new int(5));
    std::cout<<"Value of ptr is: "<<*ptr<<std::endl;

    my_shared_ptr<double> ptr1(new double(1.5));
    my_shared_ptr<double> ptr2(new double(2.5));
    my_shared_ptr<double> ptr3;
    ptr3=std::move(ptr2);
    ptr1=ptr3;
    std::cout<<ptr1.getCount()<<std::endl;
    std::cout<<ptr2.getCount()<<std::endl;
    std::cout<<ptr3.getCount()<<std::endl;

    return 0;
}