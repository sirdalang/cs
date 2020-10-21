
#include <vector>
#include <iostream>
#include <string>

template <typename T>
void PRINT_ELEMENTES(const T& container, const std::string & optstr = "") { 
    if (optstr != "") {
        std::cout << optstr << std::endl;
    }
    std::cout << "size=" << container.size() << std::endl;
    for (const auto& r : container) {
        std::cout << r << " ";
    }
    std::cout << std::endl;
}

/**
 * 1.
 * 删除最小的元素，并用最后的元素填充空缺
 * 返回删除的元素
 */
int del_min(std::vector<int> &v) {
    if (v.size() == 0) {
        return -1;
    }

    int index_min = 0;
    int i = 0;
    for (i = 0; i < v.size(); ++i) {
        if (v[i] < v[index_min]) {
            index_min = i;
        }
    }

    int value_back = v[v.size() - 1];
    v[index_min] = v[v.size() - 1];
    v.pop_back();
    return value_back;
}

/**
 * 2.
 * 逆置所有元素，要求空间复杂度为O(1)
 */
void reverse(std::vector<int> &v) {
    /* 算法思路：前后两两交换 */
    for (int ib = 0, ie = v.size() - 1; ib < ie; ++ib, --ie) {
        /* 交换两个值 */
        int value = v[ib];
        v[ib] = v[ie];
        v[ie] = value;
    }
}

void reverse(std::vector<int> &v, int ibegin, int iend) {
    if (iend > v.size()) {
        iend = v.size();
    }
    for (int ib = ibegin, ie = iend - 1; ib < ie; ++ib, --ie) {
        /* 交换两个值 */
        int value = v[ib];
        v[ib] = v[ie];
        v[ie] = value;
    }
}

/**
 * 3.
 * 删除所有值为x的元素
 * 要求时间复杂度为O(n)，空间复杂度为O(1)
 */
void del_ele(std::vector<int> &v, int ele) {
    int iok_end = 0; /* 指向未删除的元素的后一个位置 */
    int i = 0; /* 指向当前检查的元素 */
    for (i = 0; i < v.size(); ++i) {
        if (v[i] != ele) {
            /* 交换不相同的元素至靠前 */
            v[iok_end] = v[i];
            ++iok_end;
        }
    }
    v.resize(iok_end);
}

/**
 * 10.
 * 将所有元素左移p个位置
 * 例如：1 2 3 4 5 左移2个位置，为 3 4 5 1 2。
 * 要求时间和空间都尽可能高效
 * 时间复杂度：O(step*v.size())
 * 空间复杂度：O(1)
 */
int move_left_v1(std::vector<int> &v, int step) {
    /* 思路：每次移动一步，多次进行 */
    for (int s = 0; s < step; ++s) {
        int value_head = v[0];
        for (int i = 0; i < v.size() - 1; ++i) {
            /* 交换i和i+1 */
            int value_temp = v[i];
            v[i] = v[i+1];
            v[i+1] = value_temp;
        }
        v[v.size() - 1] = value_head;
        PRINT_ELEMENTES(v);
    }
}

/**
 * 10.
 * 题目：省略
 * 思路二：
 * 可以转换为数组 ab --> ba 的问题。
 * 记对数组a求逆向为 R(a)
 * 则 ba = R(R(a)R(b))
 * 可以使用已有的逆置算法
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
void move_left_v2(std::vector<int> &v, int step) {
    reverse(v,0,step);
    reverse(v,step,v.size());
    reverse(v);
}

/**
 * 11.
 * 找出两个升序数组合并成一个升序数组后的中位数，对于
 * n个元素的数组，其中位数是指第n/2（向上取整）个数。
 */
int find_mid(const std::vector<int> &v1, const std::vector<int> &v2) {
    int ret = 0;
    /* begin指向左侧未处理的元素，end指向右侧未处理的元素 */
    int v1_begin = 0;
    int v1_end = v1.size() - 1;
    int v2_begin = 0;
    int v2_end = v2.size() - 1;
    while (true) {
        /* 每一次循环从两个数组中处理一个
         * 最小值和最大值
         */

        /* v1和v2都未处理完成 */
        if (v1_begin <= v1_end && v2_begin <= v2_end) {
            /* 同时只剩一个元素，则退出 */
            if (v1_end - v1_begin == 0 && v2_end - v2_begin == 0) {
                ret = std::min(v1[v1_begin], v2[v2_begin]);
                break;
            }

            /* 处理一个最小值 */
            if (v1[v1_begin] < v2[v2_begin]) {
                ++v1_begin;
            }
            else {
                ++v2_begin;
            }
            /* 处理一个最大值 */
            if (v1[v1_end] > v2[v2_end]) {
                --v1_end;
            }
            else {
                --v2_end;
            }
        }
        /* v1未处理完成，v2处理完成 */
        else if (v1_begin <= v1_end) {
            if (v1_begin == v1_end) {
                ret = v1[v1_begin];
                break;
            }

            ++v1_begin;
            --v1_end;
        }
        /* v1处理完成，v2未处理完成 */
        else if (v2_begin <= v2_end) {
            if (v2_begin == v2_end) {
                ret = v2[v2_begin];
                break;
            }
            ++v2_begin;
            --v2_end;
        }
        else {
            break;
        }
    }
    return ret;
}

int f1(int c) {
    switch (c) {
        case 1: {
            std::vector<int> v = {1,3,5,2,4,8};
            int ret = del_min(v);
            PRINT_ELEMENTES(v);
            break;
        }
        case 2: {
            std::vector<int> v = {1,3,5,2,4,8,9};
            reverse(v);
            PRINT_ELEMENTES(v);
            break;
        }
        case 3: {
            std::vector<int> v = {1,1,2,2,3,3,5,5,4,4,1,1};
            del_ele(v, 1);
            PRINT_ELEMENTES(v);
            break;
        }
        case 4: {
            std::vector<int> v = {1,2,3,4,5};
            move_left_v1 (v, 2);
            PRINT_ELEMENTES (v);
            break;
        }
        case 5: {
            std::vector<int> v = {1,2,3,4,5};
            move_left_v2 (v, 2);
            PRINT_ELEMENTES (v);
            break;
        }
        case 6: {
            std::vector<int> v1 = {1,2,3};
            std::vector<int> v2 = {4,5,6};
            int ret = find_mid (v1, v2);
            std::cout << "ret=" << ret << std::endl;
        }
    }
}

int main() {
    f1(6);
}