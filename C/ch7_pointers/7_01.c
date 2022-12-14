#include <stdio.h>

int main(void)
{
    // & -> The addres operator (ampersand)
    // * -> Indirection Operator or Dereferencing Operator (asterisk)
    puts("");
    int a[10] = {0};
    // Set *aPtr to point to the address of a

    // printf("Address of a is %p\n", &a);
    // printf("Value of a is %d\n", a);
    // printf("Address of aPtr is %p\n", aPtr);
    // printf("Values of *aPtr is %d\n\n", *aPtr);
    // printf("Showing that * and & are complements of each other\n");
    // printf("&*aPtr = %p\n*&aPtr = %p\n", &*aPtr, *&aPtr);

    for (size_t i = 0; i < 10; ++i)
    {
        printf("\nAddress of a[%zu] is %p\n", i, &a[i]);
    }
}