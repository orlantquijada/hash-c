#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int hash(HashTable hTable, int key)
{
    return key % hTable->size;
}

LinkedList newLinkedList()
{
    nodeptr temp;
    temp = (nodeptr)malloc(sizeof(struct node));
    temp->key = 0;
    temp->next = NULL;
    return temp;
}
void destroyLL(LinkedList *list)
{
    clearLL(*list);
    free(*list);
    *list = NULL;
}
void addLL(LinkedList list, int key)
{
    nodeptr p = list;

    nodeptr temp;
    temp = (nodeptr)malloc(sizeof(struct node));
    temp->key = key;
    temp->next = p->next;
    p->next = temp;
}
int containsLL(LinkedList list, int key)
{
    nodeptr p = list->next;
    while (p != NULL)
    {
        if (p->key == key)
            return 1;
        p = p->next;
    }
    return 0;
}
void removeLL(LinkedList list, int key)
{
    nodeptr prev, p;
    prev = list;
    p = list->next;

    while (p != NULL)
    {
        if (p->key == key)
        {
            if (p->next != NULL)
                prev->next = p->next;
            else
                prev->next = NULL;

            free(p);
            return;
        }
        prev = p;
        p = p->next;
    }
}

void clearLL(LinkedList list)
{
    nodeptr p, temp;
    p = list->next;

    while (p != NULL)
    {
        temp = p->next;
        removeLL(list, p->key);
        p = temp;
    }
}
void displayLL(LinkedList list)
{
    nodeptr p = list->next;

    printf("[ ");
    while (p != NULL)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("]");
}

HashTable newHashTable(int size)
{
    HashTable h = (HashTable)malloc(sizeof(struct hash));
    h->table = (LinkedList *)malloc(sizeof(struct node) * size);
    for (int i = 0; i < size; i++)
        h->table[i] = newLinkedList();
    h->size = size;
}
void destroy(HashTable *hTable)
{
    for (int i = 0; i < (*hTable)->size; i++)
        destroyLL((*hTable)->table + i);
    (*hTable)->table = NULL;
    free(*hTable);
    *hTable = NULL;
}
void add(HashTable hTable, int key) { addLL(hTable->table[hash(hTable, key)], key); }
void removeH(HashTable hTable, int key) { removeLL(hTable->table[hash(hTable, key)], key); }
int contains(HashTable hTable, int key) { return containsLL(hTable->table[hash(hTable, key)], key); }
void clear(HashTable hTable)
{
    for (int i = 0; i < hTable->size; i++)
        clearLL(hTable->table[i]);
}
void display(HashTable hTable)
{
    for (int i = 0; i < hTable->size; i++)
    {
        printf("[%d] = ", i);
        displayLL(hTable->table[i]);
        printf("\n");
    }
}