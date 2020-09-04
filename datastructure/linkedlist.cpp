#include "linkedlist.h"

/**
 * @brief 获取第@i个节点的前一个节点
 * @return 
 * 若@i=0，则返回头节点
 * 若@i=1，则返回第一个节点
 * 若@i=len，则返回最后一个节点
 * 若@i<0 || @i>len，则返回NULL
 */
LinkedList::Node *LinkedList::GetPreNode__(int i)
{
    int count = 0;
    Node* pit = head__;
    while (pit && count < i)
    {
        pit = pit->next;
        ++count;
    }
    return pit;
}

/**
 * 带头结点的链表
 */
LinkedList::LinkedList()
{
    head__ = (Node*)malloc (sizeof(Node));
    memset (head__, 0, sizeof(Node));
    return;
}

LinkedList::~LinkedList()
{
    Node *pit = head__;
    while (pit != NULL)
    {
        Node *pnext = pit->next;
        free (pit);
        pit = pnext;
    }
    return;
}

void LinkedList::PrintList()
{
    std::cout << "LinkedList::" << std::endl;
    std::cout << "head=" << head__ << std::endl;

    Node *pit = head__->next;
    while (pit)
    {
        std::cout << pit->data << " ";
        pit = pit->next;
    }

    std::cout << std::endl;
}

int LinkedList::Length()
{
    int count = 0;
    Node *pIt = head__->next;
    while (pIt)
    {
        pIt = pIt->next;
        ++count;
    }
    return count;
}

int LinkedList::LocateElem(ElemTypeCR e)
{
    int i = 0;
    bool bFound = false;

    Node *pit = head__->next;
    while (pit)
    {
        if (pit->data == e)
        {
            bFound = true;
            break;
        }

        pit = pit->next;
        ++i;
    }

    return bFound ? i : -1;
}

ElemType* LinkedList::GetElem(int i)
{
    Node *pPreNode = GetPreNode__(i);
    if (pPreNode && pPreNode->next)
    {
        return &(pPreNode->next->data);
    }
    else 
    {
        return NULL;
    }
}

/**
 * @brief 在节点i之前插入节点e
 * 若i=0，则插入节点为第一个节点
 * 若i=len，则插入节点为尾节点
 * @return 若范围不合法或失败，则返回-1
 * @ref 有两种节点插入方式，本例采用前插方式。
 * 后插方式：在节点后插入节点，然后交换节点和插入节点的值
 */
int LinkedList::ListInsert(int i, ElemTypeCR e)
{
    Node *pPreNode = GetPreNode__(i);
    if (! pPreNode)
    {
        return -1;
    }
    Node *pNewNode = (Node*)malloc(sizeof(Node));
    memset (pNewNode, 0, sizeof(Node));

    pNewNode->data = e;
    pNewNode->next = pPreNode->next;
    pPreNode->next = pNewNode;

    return 0;
}

/**
 * @brief 删除节点i
 * 若i=0，则删除第一个节点
 * 若i=len-1，则删除最后一个节点
 * @return 成功返回0，失败则返回-1
 * @ref 与插入节点一样，删除节点也可以采用
 * 删除后节点的方式进行。本例采用删除前节点的方式。
 */
int LinkedList::ListDelete(int i, ElemTypeP pDel)
{
    Node *pPreNode = GetPreNode__(i);

    /* 被删除的节点及其前驱节点都必须存在 */
    if (!pPreNode || !pPreNode->next)
    {
        return -1;
    }

    Node *pItem = pPreNode->next;
    pPreNode->next = pItem->next;
    if (pDel) {*pDel = pItem->data;}

    free (pItem);
    pItem = NULL;
    return 0;
}