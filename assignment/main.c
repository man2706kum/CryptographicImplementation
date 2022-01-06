#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void add(int* a, int* b, int* C) {
    //C[5] = 0;
    for (int i = 0; i < 5; i++)
    {
        C[i] = a[i] + b[i];
        //printf("-----%d", C[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        if (C[i] >= pow(2, 26)) {
            C[i] = C[i] - pow(2, 26);
            C[i+1] = C[i+1] + 1;
        }
        //printf("%d ", C[i]);
    }

    //return C;
    
}
void convertC2I(unsigned char *A, int* a) {
    int binary[127], index = 0, loop = 8, count = 0;
    unsigned int a_i = 0;
    int result[5];

    for (int i = 0; i < 16; i++)
    {
        if(i==15){
            loop = 7;
        }
        unsigned char temp = (unsigned char)A[i];
        for (int j = 0; j < loop; j++)
        {
            binary[index] = 1 & A[i];
            //printf("%d", binary[index]);
            A[i] = A[i]>>1;
            index++;
        }
    }
    /*for (int i = 0; i < 127; i++){
        
            printf("%d", binary[i]);
        }*/
        
    printf("\n\n\n");
    loop = 26;
    index = 0;
    for (int i = 0; i < 5; i++){
        a_i = 0;
        if(i==4){
            loop = 23;
        }
        for (int j = 0; j < loop; j++)
        {
            a_i = a_i + pow(2,j)*binary[index];
            index++;
        }
            a[i] = a_i;
            //printf("%d ", a_i);
        }
        //a = result;
        //return result;
    }
    
void convertI2C(int* A){
    int binary[127], index = 0 , loop = 26, a_i;
    int result[16];
    for (int i = 0; i < 5; i++)
    {
        if (i==4)
        {
            loop = 23;
        }
        //printf("Binary");
        for (int j = 0; j < loop; j++)
        {
            binary[index] = 1&A[i];
            //printf("%d", binary[index]);
            A[i] = A[i]>>1;
            index++;
        }
    }
        index = 0;
        loop = 8;
        printf("\n");
        for (int i = 0; i < 16; i++)
        {   a_i = 0;

            if(i==15){
                loop = 7;
            }

            for (int j = 0; j < loop; j++)
            {
                a_i = a_i + pow(2, j)*binary[index];
                index++;
            }
            result[i] = a_i;

            printf("%d  ", result[i]);
            
            
        }
        
        
        
}
    


int main() {
    unsigned char A[16], B[16];
    int temp1, temp2, ans[5];
    int C[6], a[5], b[5];
    C[5] = 0;

    //Generating A and B as string of char
    for (int i = 0; i < 16; i++)
    {
        temp1 = rand()%256;
        temp2 = rand()%256;
        A[i] = temp1;
        B[i] = temp2;
    }
    A[15] = A[15]>>1;
    B[15] = B[15]>>1;
    //printf("%d\n", sizeof(A[15]));

    //Generating A
    for (int i = 0; i < 16; i++)
    {
        //temp = rand(256);
        printf("%d ", A[i]);
    }
    //printf("%d\n", sizeof(A));
    printf("\n");
    
    //Generating B
     for (int i = 0; i < 16; i++)
    {
        //temp = rand(256);
          printf("%d ", B[i]);
    }
    printf("\n");

    convertC2I(A, a);   //converting A to base 2^26
    printf("A in base 2^26\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    
    
    convertC2I(B, b);   //converting B to base 2^26
    printf("B in base 2^26\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n\n\n");
    printf("Addition in base 2^26\n");
    add(a, b, C);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", C[i]);
    }

    //convertI2C(a);//Converting a to base 2^8
    

}