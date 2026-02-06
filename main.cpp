#include <iostream>
#include "my_unique_ptr.h"

int main(int argc,const char* argv[]){
    my_unique_ptr<int> ptr(new int(5));
    std::cout<<"Value of ptr is: "<<*ptr<<std::endl;

    return 0;
}