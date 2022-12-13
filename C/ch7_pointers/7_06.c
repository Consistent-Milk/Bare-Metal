#include <ctype.h>
#include <stdio.h>
#include <string.h>

// function prototype
void convertToUpperCase(char *sPtr);

int main(void)
{
    char string[] = "ChAraCtErS and $32.98";

    printf("The string before conversion is: %s\n", string);
    convertToUpperCase(string);
    printf("The string after conversion is: %s\n", string);
}

void convertToUpperCase(char *sPtr)
{
    while (*sPtr != NULL)
    {
        *sPtr = toupper(*sPtr);
        ++sPtr;
    }
}