#include <iostream>
using namespace std;

int main(){
int num1,num2;
cout<<"Enter number one ";
cin>>num1;
char opration ;
cout<<"Enter opretion";
cin>>opration;
cout<<"Enter num two ";
cin>>num2;

switch (opration){
    case '+': 
    cout<<num1<<'+'<<num2<<'='<<num1+num2;
    break;
    case '-': 
    cout<<num1<<'-'<<num2<<'='<<num1-num2;
    break;
    case '*': 
    cout<<num1<<'*'<<num2<<'='<<num1*num2;
    break;
    case '/': 
    cout<<num1<<'/'<<num2<<'='<<num1/num2;
    break;
    default : 
    cout<<"Enter a correct opration";
}
}