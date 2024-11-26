#include <iostream>

class foo{
    public:

    int get_total_class_score(){
        int test = 0;
        for(int i = 0; i<10;i++){
            test += 5;
        }
        std::cout<<test;
        return test;
        }
};

int main(){
    foo wow;
    wow.get_total_class_score();
    return 0;
}