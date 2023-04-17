#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Dynammic_Array.h"

void Example_CHAR(void);
void Example_INT(void);
void Example_FLOAT(void);
void Example_STRUCT(void);
void Example_STRING(void);

int main(void)
{
    Example_CHAR();
    Example_INT();
    Example_FLOAT();
    Example_STRUCT();
    Example_STRING();
    return 0;

}

// Example of how to use it for a char array
void Example_CHAR(void)
{
    // Example of how to add a char array.
    printf("EXAMPLE...OUTPUT FOR HOW TO ADD A CHAR ARRAY.\n");
    char msg[] = {'a', 'b', 'd', 'y', 't'};
    DynammicArray CHAR = allocate(10);
    printf("Allocated %dbyte/s of memory.\n", CHAR.size_in_bytes);
    for(int i= 0; i < strlen((char*)msg); i++)
    {
        add(&CHAR, msg + i);
    }
    // Print out array to check it worked.
    CHAR.size_in_bytes = CHAR.size * sizeof(char);
    printf("Capacity= %d, Length= %d, SizeWritten(Bytes)= %dbyte/s ", CHAR.capacity, CHAR.size, CHAR.size_in_bytes);
    printf("Contents= ");
    for(int i = 0; i < CHAR.size; i++)
    {
       printf("%c ", *((char *)CHAR.list[i])); 
    }
    printf("\n");
    printf("\n");
    // Example of how to add single character.
    printf("EXAMPLE...OUTPUT FOR HOW TO ADD A SINGLE CHARACTER TO END OF ARRAY.\n");
    char msg1[] = {'c'};
    add(&CHAR, msg1);
    CHAR.size_in_bytes = CHAR.size * sizeof(char);
    printf("Capacity= %d, Length= %d, SizeWritten(Bytes)= %dbyte/s ", CHAR.capacity, CHAR.size, CHAR.size_in_bytes);
    printf("Contents= ");
    for(int i = 0; i < CHAR.size; i++)
    {
       printf("%c ", *((char *)CHAR.list[i])); 
    }
    printf("\n");
    printf("\n");
    printf("EXAMPLE...OUTPUT FOR HOW TO INSERT A SINGLE CHARACTER TO AN IDX WITHIN THE SCOPE OF THE ARRAY.\n");
    int idx = 2;
    insert(&CHAR, msg1, idx);
    setCapacity(&CHAR);
    CHAR.size_in_bytes = CHAR.size * sizeof(char);
    printf("Capacity= %d, Length= %d, SizeWritten(Bytes)= %dbyte/s ", CHAR.capacity, CHAR.size, CHAR.size_in_bytes);
    printf("Contents= ");
    for(int i = 0; i < CHAR.size; i++)
    {
        printf("%c ", *((char*)CHAR.list[i]));
    }
    printf("\n");
    printf("\n");
    free_allocatedmemory(&CHAR);
}

void Example_INT(void)
{
    // Example of how to add int array.
    printf("EXAMPLE...OUTPUT FOR HOW TO ADD a INT ARRAY.\n");
    DynammicArray test = allocate(10);
    printf("Allocated %dbyte/s of memory.\n", test.size_in_bytes);
    int string[] = {1,2,3};
    for(int i = 0; i < 3; i++)
    {
        add(&test, &string[i]);
    }
    test.size_in_bytes = test.size * sizeof(int);
    printf("Capacity= %d, Length= %d, SizeWritten(Bytes)= %dbyte/s ", test.capacity, test.size, test.size_in_bytes);
    printf("Contents= ");
    for (int i = 0; i < test.size; i++)
    {
        printf("%d ", *((int*)test.list[i])); 
    }
    printf("\n" );
    printf("\n");
    // Example of how to add a single int.
    printf("EXAMPLE...OUTPUT FOR HOW TO ADD A SINGLE INT.\n");
    printf("Allocated %dbyte/s of memory.\n", test.size_in_bytes);
    int num = 6; 
    add(&test, &num);
    setCapacity(&test);
    test.size_in_bytes = test.size * sizeof(int);
    printf("Capacity= %d, Length= %d, SizeWritten(Bytes)= %dbyte/s,", test.capacity, test.size, test.size_in_bytes);
    printf("Contents= ");
    for (int i = 0; i < test.size; i++)
    {
        printf("%d ", *((int*)test.list[i])); 
    }
    printf("\n");
    printf("\n");
    free_allocatedmemory(&test);
}

void Example_FLOAT(void)
{
    //Example of how to add a float array.
    float number1[] = {1.1, 2.2, 3.3, 4.4};
    DynammicArray newtest = Default_allocate();
    printf("EXAMPLE...OUTPUT FOR HOW TO ADD A FLOAT ARRAY.\n");
    printf("Allocated %dbyte/s of memory.\n", newtest.size_in_bytes);
    for(int i = 0; i < 4; i++)
    {
        add(&newtest, &number1[i]);
    }
    newtest.size_in_bytes = newtest.size * sizeof(float);
    printf("Capacity= %d, Length= %d, SizeWritten(Bytes)= %dbyte/s ", newtest.capacity, newtest.size, newtest.size_in_bytes);
    printf("Contents= ");
    for (int i = 0; i < newtest.size; i++)
    {
        printf("%.1f ", *((float*)newtest.list[i])); 
    }
    printf("\n");
    printf("\n");

    //Example of how to add a single float value always gets added to end of array(.size).
    //newtest = allocate(4);
    float num2[] = {5.5};
    add(&newtest, &num2);
    printf("EXAMPLE...OUTPUT FOR HOW TO ADD, INSERT AND REMOVE A SINGLE FLOAT ENTRY.\n");
    newtest.size_in_bytes = newtest.size * sizeof(float);
    printf("Capacity= %d, Length= %d, SizeWritten(Bytes)= %dbyte/s ", newtest.capacity, newtest.size, newtest.size_in_bytes);
    for (int i = 0; i < newtest.size; i++)
    {
        printf("%.1f ", *((float*)newtest.list[i])); 
    }
    printf("\n");
    //Example of how to INSERT a single float value at an idx within the scope of the array excluding last slot use add() to do that.
    //Also demonstrates how to remove an entry.
    int idx = 0;
    float num5 = 2.6;
    insert(&newtest, &num5, idx);
    newtest.size_in_bytes = newtest.size * sizeof(float);
    printf("Capacity= %d, Length= %d, SizeWritten(Bytes)= %dbyte/s ", newtest.capacity, newtest.size, newtest.size_in_bytes);
    for (int i = 0; i < newtest.size; i++)
    {
        printf("%.1f ", *((float*)newtest.list[i])); 
    }
    printf("\n");
    removeEntry(&newtest, 0);
    setCapacity(&newtest);
    newtest.size_in_bytes = newtest.size * sizeof(float);
    printf("Capacity= %d, Length= %d, SizeWritten(Bytes)= %dbyte/s ", newtest.capacity, newtest.size, newtest.size_in_bytes);
    for (int i = 0; i < newtest.size; i++)
    {
        printf("%.1f ", *((float*)newtest.list[i])); 
    }
    printf("\n");
    printf("\n");
    free_allocatedmemory(&newtest);
}

void Example_STRUCT(void)
{
    struct person
    {
        char* name;
        int age;
    };
    struct person new = { .name = "Jane", .age = 25, };
    printf("EXAMPLE...OUTPUT FOR HOW TO ADD A STRUCT/S.\n");
    DynammicArray STRUCT = allocate(2);
    printf("Allocated %dbyte/s of memory.\n", STRUCT.size_in_bytes);
    add(&STRUCT, &new);
    struct person *p1 = STRUCT.list[0];
    setCapacity(&STRUCT);
    STRUCT.size_in_bytes = STRUCT.size * sizeof(struct person);
    printf("Capacity= %i, Size= %i\n", STRUCT.capacity, STRUCT.size);
    printf("Name= %s, Age= %d, SizeWritten(byte/s)= %d.\n", p1->name, p1->age, STRUCT.size_in_bytes);
    printf("\n");
}

void Example_STRING(void)
{
    printf("EXAMPLE...OUTPUT FOR HOW TO ADD A STRING.\n");
    char *string1 = "tester";
    char *string2 = "tester2";
    DynammicArray TEST = allocate(2);
    printf("Allocated %dbyte/s of memory.\n", TEST.size_in_bytes);
    add(&TEST, string1);
    add(&TEST, string2);
    setCapacity(&TEST);
    TEST.size_in_bytes = (sizeof(char) + strlen(string2) + strlen(string1));
    printf("Capacity= %d, Size= %d, SizeWritten(byte/s)= %d(byte/s), %s, %s.\n", TEST.capacity, TEST.size, TEST.size_in_bytes, (const char*)TEST.list[0], (const char*)TEST.list[0]);
    printf("\n");
}