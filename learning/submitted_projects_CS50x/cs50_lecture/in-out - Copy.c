#include <stdio.h>

int main()
{
    // Two separate file pointers for different modes
    FILE* ptr1 = fopen("text.txt", "a"); // append mode
    FILE* ptr2 = fopen("text.txt", "r"); // read mode

    if (!ptr1 || !ptr2) // dont forget to do it to not get the null pointer
    {
        printf("Error opening file.\n");
        return 1;
    }

    int ch = fgetc(ptr2); // fgetc returns int

    while (ch != EOF) // EOF stands for End Of File
    {
        printf("%c\n", ch);
        ch = fgetc(ptr2); // only work in read mode // it is inside to be updated
    }

    fputc('a',ptr1) // fputc in a and w mode only

    //fread(buffer if a varible put the address , size at the time "int" , how many of them , file pointer in r mode)
    //fwrite is the same but in a and w modes

    //feof checks whether or not ur at the end

    fclose(ptr1); // close all the pointers
    fclose(ptr2);

    return 0;
}
