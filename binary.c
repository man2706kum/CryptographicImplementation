#include<stdio.h>

void decimalToBinary (int n) {
    int quotient, remainder;
    remainder = n%2;
    quotient = n/2;
    if(quotient>0)
        decimalToBinary(quotient);
    printf("%d", remainder);
    return;
}

int main(){
    decimalToBinary(12);
    printf("\n");
}