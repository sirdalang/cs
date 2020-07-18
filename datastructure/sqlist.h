
/**
 * 顺序表
 * 线性表 动态分配 顺序存储的一个实现
 */

#ifndef SQLIST_H__
#define SQLIST_H__

#include "global.h"

class SqList
{
private:
    /* 线性表数据结构 */
    typedef struct 
    {
        ElemType *data;
        int nMaxSize;
        int nLength;
    } DSqList;
    DSqList d;

public:

    /* 基础接口 */
    SqList ();
    ~SqList ();
    void PrintList();

    int Length();
    int LocateElem(ElemTypeCR e);
    ElemType GetElem(int i);
    int ListInsert(int i, ElemTypeCR e);
    int ListDelete(int i, ElemTypeR e);

    /* 补充接口 */

    /**
     * @brief 逆转所有元素
     * @note 
     * 空间复杂度为 O(1)
     */
    void Reverse();

    /**
     * @brief 删除所有制定元素
     * @note 
     * 空间复杂度为 O(1)
     * 时间复杂度为 O(n)
     */
    int DeleteItem(ElemTypeCR e);
};

#endif // SQLIST_H__