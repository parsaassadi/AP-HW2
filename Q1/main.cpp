
#include <iostream>

int main()
{
    std::cout<<"addresses of 2D array that question defined:"<<"\n";
    int(*p5)[10]{new int[10][10]};
   for (int i = 0; i <10 ; i++) {
        for (int j = 0; j <10 ; j++) {
            std::cout<<&(p5[i][j])<<"\n";

        }
       std::cout<<"-------------------------------"<<"\n";

    }
    std::cout<<"addresses of a 2D array that normally defined:"<<"\n";
    int**p3=new int*[10];
    for (int k = 0; k <10 ; k++) {
        p3[k]=new int [10];
    }
    for (int i = 0; i <10 ; i++) {
        for (int j = 0; j <10 ; j++) {
            std::cout<<&(p5[i][j])<<"\n";

        }
        std::cout<<"-------------------------------"<<"\n";

    }
}