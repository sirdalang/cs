
/**
 * 用于测试手写代码的纯 C　链表样例。
 * date:2020.12.14
 */

#pragma once

typedef struct NODE {
    int data;
    struct NODE *next;
} NODE;

/************ BASE ***********/

/**
 * 使用提供的数组，生成一个带头结点的链表
 */
NODE *list_gen(int arr[], int size);

/**
 * 打印链表
 */
void list_print(const NODE *list);


/************ FUNN ***********/

/**
 *  1 2 3 4 5 -->
 *  1 5 2 4 3
 *  
 *  1 2 3 4 5 6 -->
 *  1 6 2 5 3 4
 */
NODE *list_eg1(NODE *list);