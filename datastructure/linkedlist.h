
/**
 * 线性表的链式表示
 * 
 * 关键：实现一个获取前一个节点的内部接口，
 * 这个接口可被用于获取节点、插入节点、删除节点等。
 */

#ifndef LINKEDLIST_H__
#define LINKEDLIST_H__

#include "global.h"

class LinkedList
{
private:
    typedef struct Node
    {
        ElemType data;
        struct Node *next;
    } Node;

    Node *head__;
private:
    Node *GetPreNode__(int i);
    
public:
    /* base interface */
    LinkedList();
    ~LinkedList();
    void PrintList();

    int Length();
    int LocateElem(ElemTypeCR e);
    ElemType *GetElem(int i);
    int ListInsert(int i, ElemTypeCR e);
    int ListDelete(int i, ElemTypeP pDel);
};

#endif // LINKEDLIST_H__