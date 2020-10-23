#include "linkedlist.h"

int main()
{
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

        int ret = l.LocateLast(2);
        std::cout << "last2=" << ret << std::endl;
    }

    {
        LinkedList l1;
        l1.ListInsert(0,5);
        l1.ListInsert(0,4);
        l1.ListInsert(0,3);
        l1.ListInsert(0,2);
        l1.ListInsert(0,1);

        LinkedList l2;
        l2.ListInsert(0,5);
        l2.ListInsert(0,4);
        l2.ListInsert(0,3);
        l2.ListInsert(0,7);
        l2.ListInsert(0,8);

        l1.PrintList();
        l2.PrintList();

        int ret = LinkedList::FindSameTail(l1,l2);
        std::cout << "same=" << ret << std::endl;
    }

    {
        LinkedList l;
        l.ListInsert(0,1);
        l.ListInsert(0,2);
        l.ListInsert(0,3);
        l.PrintList();
        l.Reverse();
        l.PrintList();
    }
    {
        LinkedList l;
        l.ListInsert(0,1);
        l.ListInsert(0,2);
        l.ListInsert(0,3);
        l.PrintList();
        l.ReverseV2();
        l.PrintList();
    }
    {
        LinkedList l;
        l.ListInsert(0,1);
        l.ListInsert(0,2);
        l.ListInsert(0,3);
        l.ListInsert(0,4);
        l.PrintList();
        int ret = l.MidEle();
        std::cout << "midele=" << ret << std::endl;
    }

    return 0;
}