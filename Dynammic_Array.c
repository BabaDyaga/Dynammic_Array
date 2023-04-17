#include "Dynammic_Array.h"
// comment
DynammicArray Default_allocate(void)
{
    return allocate(4);
}
DynammicArray allocate(int capacity)
{

    DynammicArray ret;
    ret.list = malloc(capacity * sizeof(void *));
    ret.size = 0;
    ret.capacity = ret.list ? capacity : 0;
    ret.size_in_bytes = capacity * sizeof(void *);
    return ret;

}

void add(DynammicArray *list, void *element)
{
    if(list->size >= list->capacity)
    {
        resize_array(list);
    }    
    list->list[list->size] = element;
    list->list[list->size + 1] = '\0';
    list->size++;
}

void *removeEntry(DynammicArray *list, int idx)
{
    if(idx > list->size - 1)
    {
        return NULL;
    }
    for(int i = idx; i < list->size; i++)
    {
        list->list[i] = list->list[i + 1];
    }
    list->size--;
}

void resize_array(DynammicArray *list)
{
    void **NewArray = malloc(list->capacity * 2 * sizeof(void *));
    list->size_in_bytes = list->capacity * 2 * sizeof(void *);
    for(int i = 0; i < list->size; i++)
    {
        NewArray[i] = list->list[i];
    }
    free(list->list);
    list->list = NewArray;
    list->capacity = list->capacity * 2;
}

void *getEntryatidx(DynammicArray *list, int idx)
{
    return (idx > list->size) ? NULL : list->list[idx];
}

void *insert(DynammicArray *list, void *element, int idx)
{
    if(idx >= list->size)
    {
        printf("please use add function to add to end of array\n");
        return NULL;
    }
    for(int i = list->size; i >= idx; i--)
    {
        if(list->size >= list->capacity)
        {
            resize_array(list);
        }
        list->list[i + 1] = list->list[i]; 
    }
    list->list[idx] = element;
    list->size++;
}

void free_allocatedmemory(DynammicArray *list)
{
    free(list->list);
    list->size = 0;
    list->capacity = 0;
    list->size_in_bytes = 0;
    for(int i = 0; i < list->capacity; i++)
    {
        free(list->list[i]);
    }
}
