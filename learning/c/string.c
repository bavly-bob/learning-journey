#include <stdio.h>
#include <string.h>

int main()
{
    char *str1= "Hello, ", *str2;
    
    // Concatenate str2 to str1
    strcat(str2, str1);
    
    // Print the concatenated string
    printf("Concatenated String: %s\n", str1);
    
    return 0;
}