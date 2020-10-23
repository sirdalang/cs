#include "linkedlist.h"

/**
 * @brief 获取第@i个节点的前一个节点
 * @return 
 * 若@i=0，则返回头节点
 * 若@i=1，则返回第一个节点
 * 若@i=len，则返回最后一个节点
 * 若@i<0 || @i>len，则返回NULL
 */
LinkedList::Node *LinkedList::GetPreNode__(int i) const
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

void LinkedList::PrintList() const
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

int LinkedList::Length() const
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

int LinkedList::LocateElem(ElemTypeCR e) const
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

ElemType* LinkedList::GetElem(int i) const
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

/**
 * @brief 获取中间节点
 * 算法描述：双指针法。
 * 第一个指针每次挪一个节点，第二个指针每次挪两个节点。
 * 待第二个节点无法挪动时终止。
 * 如，共5个元素，则返回第3个元素。共4个元素，则返回
 * 第2个元素。
 * 
 * 细节：从头节点开始算起，挪动后再检查。最终1指针指向
 * 的节点即为中间节点。
 */
ElemType LinkedList::MidEle() const
{
    Node *p1 = head__;
    Node *p2 = head__;
    while (p2->next != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
        if (p2->next != nullptr) { /* 尝试挪动两次 */
            p2 = p2->next;
        }
    }
    return p1->data;
}

/**
 * @brief 链表逆置
 * 算法描述：双指针指向本节点和下一个节点，
 * 将下一个节点改为指向本节点
 * 此算法归结为原地反转法。
 */
void LinkedList::Reverse()
{
    /* 少于2个元素，不执行 */
    if (head__->next == nullptr || 
        head__->next->next == nullptr) {
        return ;
    }

    Node* p1 = head__->next;
    Node* p2 = head__->next->next;
    p1->next = nullptr; /* 第一个节点作为末尾节点 */
    while (p2 != nullptr) {
        Node *p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    head__->next = p1;
}

/**
 * @brief 链表逆置版本2
 * 算法描述：将原链表依次头插到一个新的链表
 * 上。形成一个逆序的链表。
 * 此算法归结为头插法。
 * 
 * 这个算法相比原地反转法，更为直观，逻辑更为
 * 简单。
 */
void LinkedList::ReverseV2()
{
    Node pNewHead = {};
    Node *pIt = head__->next;
    while (pIt != nullptr) {
        Node *pTemp = pIt;
        pIt = pIt->next;
        pTemp->next = pNewHead.next;
        pNewHead.next = pTemp;
    }
    head__->next = pNewHead.next;
}

/**
 * @brief 找出单向链表的倒数第@k个元素
 * 算法思路：只需要对单向链表进行一次遍历，利用
 * 两个有最大长度@k的游标遍历。当遍历至末尾时，第二
 * 游标即指向倒数第@k个元素。
 * 
 * @ref 2009统考 408
 */
ElemType LinkedList::LocateLast(int k) const
{
    Node *p1 = head__->next;
    Node *p2 = head__->next;
    int nDistance = 1; /* 表示p2相对p1是倒数第几个元素 */
    while (p1 != NULL) 
    {
        if (nDistance <= k) 
        {
            p1 = p1->next;
            ++nDistance;
        }
        else 
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    if (nDistance <= k) 
    {
        return -1;
    }
    else 
    {
        return p2->data;
    }
}

/**
 * @brief 
 * 2012 统考 408
 * 找出两个单向链表的相同末端的第一个元素
 * 算法思路：用两个指针指向链表的头节点，根据两个链表
 * 的长度，向后移动较长的链表的指针，使得两个指针后续
 * 链表的长度一致，然后统一向后检查，直到得到相同的元素。
 * 
 * 原题中两个链表共享最后的一段（也即比较节点的指针是否
 * 相同），这里更改为找第一个值相同。
 */
ElemType LinkedList::FindSameTail(const LinkedList &l1, const LinkedList &l2)
{
    int len1 = l1.Length();
    int len2 = l2.Length();

    Node *p1 = l1.head__;
    Node *p2 = l2.head__;
    if (len1 < len2) 
    {
        int diff = len2 - len1;
        for (int k = 0; k < diff; ++k) 
        {
            p2 = p2->next;
        }
    }
    else 
    {
        int diff = len1 - len2;
        for (int k = 0; k < diff; ++k) {
            p1 = p1->next;
        }
    }

    /* 对齐后，跳过头节点 */
    p1 = p1->next;
    p2 = p2->next;

    ElemType ret_data = -1;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->data == p2->data) {
            ret_data = p1->data;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return ret_data;
}

/**
 * 2019 统考 408
 * 将一个链表按如下顺序重新排列：
 * 1 2 3 4 5 --> 1 5 2 4 3
 * 1 2 3 4 5 6 --> 1 6 2 5 3 4
 * 要求：空间复杂度为O(1)，时间复杂度尽可能优化
 * 
 * 算法思路：将左边的序列从中间节点拆分为
 * 两个子链表：
 * 如：1 2 3 4 5 --> 1 2 + 3 4 5
 *    1 2 3 4 5 6 --> 1 2 3 + 4 5 6
 * 然后将右侧的子链表逆置：
 * 如：1 2 + 5 4 3
 *    1 2 3 + 6 5 4
 * 
 * 最后将两个子链交替取第一个节点形成新的链表即可。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
void LinkedList::mixele()
{
    /* 步骤1：找中间节点 */

    /* 步骤2：将链表等分为两个子链 */

    /* 步骤3：将第二个子链逆置 */

    /* 步骤4：将两个子链合并为一个子链 */

    /* 相关功能已实现，不重复 */
}