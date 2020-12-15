
#include <stdio.h>

#include "list.h"

int main() {
    printf ("this is amazing!\n");

    int arr[] = {1,3,5,2,4,6};
    NODE *list = list_gen(arr, sizeof(arr)/sizeof(arr[0]));
    list_print (list);

    return 0;
}