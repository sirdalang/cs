
#include "sqlist.h"

#include <stdlib.h>

#define INIT_SIZE 8

SqList::SqList()
{
    d.data = nullptr;
    d.nLength = 0;
    d.nMaxSize = 0;
}

SqList::~SqList()
{
    if (nullptr != d.data)
    {
        free (d.data);
    }
    d.data = nullptr;
    d.nLength = 0;
    d.nMaxSize = 0;
}

int SqList::Length()
{
    return d.nLength;
}

int SqList::LocateElem(ElemTypeCR e)
{
    int i = 0;
    for (i = 0; i < d.nLength; ++i)
    {
        if (d.data[i] == e)
        {
            break;
        }
    }
    return i < d.nLength ? i : -1;
}

ElemType SqList::GetElem (int i)
{
    if (i < d.nLength)
    {
        return d.data[i];
    }
    else 
    {
        return ElemType(0);
    }
}

int SqList::ListInsert(int i, ElemTypeCR e)
{
    if (d.nMaxSize < INIT_SIZE)
    {
        d.nMaxSize = INIT_SIZE;
        d.data = (ElemType*)malloc (d.nMaxSize);
    }

    if (d.nLength == d.nMaxSize)
    {
        d.nMaxSize *= 2;
        d.data = (ElemType*)realloc (d.data, d.nMaxSize);
    }

    for (int k = d.nLength; k > i; --k)
    {
        d.data[k] = d.data[k-1];
    }

    d.data[i] = e;
    ++d.nLength;

    return i;
}

int SqList::ListDelete (int i, ElemTypeR e)
{
    if (0 == d.nLength)
    {
        return -1;
    }
    
    e = d.data[i];

    for (int k = i; k < d.nLength - 1; ++k)
    {
        d.data[i] = d.data[i+1];
    }
    --d.nLength;

    return i;
}

void SqList::PrintList()
{
    std::cout << "p=" << d.data << std::endl;
    std::cout << "len=" << d.nLength << std::endl;
    std::cout << "max=" << d.nMaxSize << std::endl;
    for (int i = 0; i < d.nLength; ++i)
    {
        std::cout << d.data[i] << " ";
    }
    std::cout << std::endl;
}

void SqList::Reverse()
{
    for (int i = 0; i < d.nLength / 2; ++i)
    {
        int j = d.nLength - i - 1;
        ElemType eleTemp = d.data[i];
        d.data[i] = d.data[j];
        d.data[j] = eleTemp;
    }
}

int SqList::DeleteItem (ElemTypeCR e)
{
    /**
     * 算法思路：向右扫描，并记录相同项的数量。逐个置换
     */
    int i = 0, j = 0;
    while (i < d.nLength)
    {
        if (e == d.data[i])
        {
            ++i;
        }
        else 
        {
            ElemType eleTemp = d.data[i];
            d.data[i] = d.data[j];
            d.data[j] = eleTemp;
            ++i; 
            ++j;
        }
    }
    d.nLength = j;
    
    return i - j;
}