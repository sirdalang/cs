#include "sqlist.h"

int main()
{
    int ret = 0;
    SqList l;

    l.ListInsert (0, 1);
    l.ListInsert (0, 2);
    l.ListInsert (2, 3);
    l.PrintList ();

    std::cout << "locate(2)=" << l.LocateElem (2) << std::endl;

    std::cout << "reverse" << std::endl;
    l.Reverse();
    l.PrintList ();

    l.ListInsert (0, 1);
    l.ListInsert (0, 2);
    l.ListInsert (0, 3);
    l.PrintList();

    ret = l.DeleteItem(1);
    std::cout << "l.delitem(1)=" << ret << std::endl;
    l.PrintList();

    return 0;
}