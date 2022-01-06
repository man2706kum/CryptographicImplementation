int* convertC2I(char* A) {
    int binary[127], index = 0;
    for (int i = 0; i < 16; i++)
    {

        int temp = A[i];
        for (int j = 0; j < 8; j++)
        {
            binary[index] = A[i]&1;
            A[i] = A[i]>>1;
            index++;
        }
        
    }
    
}