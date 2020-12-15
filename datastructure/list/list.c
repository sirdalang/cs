#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NODE *list_gen(int arr[], int size) {
    NODE *list = (NODE *)malloc(sizeof(NODE));
    memset (list, 0, sizeof(*list));
    NODE *tail = list;

    int i = 0;
    for (i = 0; i < size; ++i) {
        NODE *newnode = (NODE*)malloc(sizeof(NODE));
        memset (newnode, 0, sizeof(*newnode));
        newnode->data = arr[i];
        tail->next = newnode;
        tail = tail->next;
    }

    return list;
}

void list_print(const NODE *list) {
    printf ("list: %p\n", list);

    NODE *it = list->next;
    while (it != NULL) {
        printf ("%d ", it->data);
        it = it->next;
    }
    printf ("\n");
    return ;
}

NODE *list_eg1(NODE *list) {
    
}