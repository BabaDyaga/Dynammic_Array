#ifndef _DYNAMMIC_ARRAY_H_
#define _DYNAMMIC_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct DynammicArray
{

    int size;
    int capacity;
    int size_in_bytes;
    void **list;

}DynammicArray;



DynammicArray Default_allocate(void);
DynammicArray allocate(int capacity); 
void add(DynammicArray *list, void *element);
void resize_array(DynammicArray *list);
void *removeEntry(DynammicArray *list, int idx);
void *getEntryatidx(DynammicArray *list, int idx);
void *insert(DynammicArray *list, void *element, int idx);
void free_allocatedmemory(DynammicArray *list);
#endif