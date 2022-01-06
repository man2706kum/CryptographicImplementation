#include<stdio.h>

//Finding k-th bit using left shift
int LeftShift (int n, int k) {
    if(n&(1<<(k-1)))
        return 1;
    else
        return 0;
}
// Finding k-th bit using light shift
int RightShift(int n, int k) {
    if((n>>(k-1))&1)
        return 1;
    else
        return 0;
}

//Finding decimal to binary using algorithm 1
void decimalToBinary1 (int n) {
    
    int result[10], i = 0;
    while (n!=0)
    {
        result[i] = n%2;
        n /= 2;
        i +=1;
    }
    
    while (i!=0)
    {
        printf("%d", result[i-1]);
        i -=1;
    }
    
    printf("\n");
}

//Finding decimal to binary using left shift 
void decimalToBinaryLeftShift (int n) {
    int i;
    for(i=10; i >0; i--) {
        printf("%d", LeftShift(n, i));
    }
    printf("\n");
}

//Finding decimal to binary using right shift
void decimalToBinaryRighttShift (int n) {
    int i;
    for(i=10; i >0; i--) {
        printf("%d", RightShift(n, i));
    }
    printf("\n");
}

int main () {

    int n, k;
    printf("Enter the value of n and k: ");

    scanf("%d %d", &n, &k);

    printf("\n------------------To Find The k-th Bit---------------------\n");
    printf("k-th bit using left shift: %d\n", LeftShift(n,k));
    printf("k-th bit using right shift: %d\n", RightShift(n,k));

    printf("\n------------------Decimal To Binary-----------------------\n");
    printf("decimal to binary using algorithm 1: ");
    decimalToBinary1(n);
    printf("decimal to binary using left shift: ");
    decimalToBinaryLeftShift(n);
    printf("decimal to binary using right shift: ");
    decimalToBinaryRighttShift(n);
   
}