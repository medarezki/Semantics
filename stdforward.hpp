#include <iostream>
#include <utility>

std::string  check(const int&){ return {"lvalue"}; }
std::string check(int&& ){ return {"rvalue"}; }


template<class T> void check_value(T&& argument){

    if(check(std::forward<T>(argument)) == "lvalue"  && check(argument) == "lvalue" ){
        std::cout<<"Managing lvalue"<<std::endl;
    }else{
        std::cout<<"Managing rvalue"<<std::endl;
    }
}

int main()
{
    int a = 9;

    check_value(a);
    check_value(9);

    return 0;
}
