#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printCharacters(const char *sPtr);

int main(void)
{
    char string[] = "printing characters of life one by one";

    puts("");
    printCharacters(string);
    puts("");
}

void printCharacters(const char *sPtr)
{
    for (; *sPtr != NULL; ++sPtr)
    {
        printf("%c", *sPtr);
    }
}