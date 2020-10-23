
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
    Node *GetPreNode__(int i) const;
    
public:
    /* base interface */
    LinkedList();
    ~LinkedList();
    void PrintList() const;

    int Length() const;
    int LocateElem(ElemTypeCR e) const;
    ElemType *GetElem(int i) const;
    int ListInsert(int i, ElemTypeCR e);
    int ListDelete(int i, ElemTypeP pDel);
    ElemType MidEle() const;
    void Reverse();
    void ReverseV2();

    /* alg eg */
    ElemType LocateLast(int k) const;
    static ElemType FindSameTail(const LinkedList &l1, const LinkedList &l2);
    void mixele();
};

#endif // LINKEDLIST_H__