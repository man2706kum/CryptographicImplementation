#include<stdio.h>
#include<math.h>

void Addition (int a[5], int b[5]) {
    //unsigned int a[5] = {135, 214, 18, 0};
    //unsigned int b[5] = {21, 205, 91, 7};
    unsigned int c[5] = {0};
    for (int i = 0; i < 5; i++) {

        c[i] += a[i] + b[i];
        if(c[i]>=256) {
            c[i+1] += c[i]/256;
            c[i] = c[i] % 256;
        }
        printf("%d, ", c[i]);

    }
    
}

void Subtraction (int a[5], int b[5]) {
    int c[5] = {0};
    
    for ( int i = 0; i < 5; i++){
            c[i] += a[i] - b[i];

        if (c[i]<0){

            c[i] = c[i] + 256;
            c[i+1] -= 1;
        }
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ", c[i]);
    }
    
            
    
}

void Multiplication (int a[], int b[]){

    int c[8] = {0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            c[i+j] += a[i] * b[j];
            if (c[i+j]>=256)
            {
                c[i+j+1] += c[i+j]/256;
                c[i+j] = c[i+j]%256;
            }
            
        }
        
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%d, ", c[i]);
    }
    
    
}
    
int main () {
    printf("Arithmetic in base R-----------------\n\n\n\n");
    int b[5];
    int a[5];
    printf("Enter a: a0 a1 a2 a3 a4\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &a[i]);
    
    printf("Enter b: b0 b1 b2 b3 b4\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &b[i]);
    
    printf("\n\nAddition:[c0, c1, c2, ...]\n");
    Addition(a,b);
    printf("\n\nSubtraction:[c0, c1, c2, ...]\n");
    Subtraction(a, b);
    printf("\n\nMultiplication:[c0, c1, c2, ...]\n");
    Multiplication(a,b);
    printf("\n");
}
