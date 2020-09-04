#include "linkedlist.h"

int main()
{
    LinkedList l;
    l.PrintList();

    /*  */
    l.ListInsert(0, 3);
    /* 3 */
    l.ListInsert(1, 5);
    /* 3 5 */
    l.ListInsert(0, 1);
    /* 1 3 5 */
    l.ListInsert(1, 2);
    /* 1 2 3 5 */
    l.ListInsert(3, 4);

    l.PrintList();

    assert (l.Length() == 5);

    assert (l.LocateElem(3) == 2);
    assert (* l.GetElem(3) == 4);

    ElemType elem = 0;
    l.ListDelete(2, &elem);
    assert (elem == 3);
    l.PrintList();

    return 0;
}