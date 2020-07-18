
#include <vector>
#include <iostream>

template <typename T>
int partition_v1(T &sqlist, int low, int high)
{
    auto mid = sqlist[low];
    while (low < high)
    {
        while (low < high && sqlist[high] >= mid) --high;
        std::swap(sqlist[low], sqlist[high]);
        while (low < high && sqlist[low] <= mid) ++low;
        std::swap(sqlist[low], sqlist[high]);
    }
    sqlist[low] = mid;
    return low;
}

template <typename T>
int partition_v2(T &sqlist, int low, int high)
{
    auto mid = sqlist[low];
    while (low < high)
    {
        while (low < high && sqlist[high] >= mid) --high;
        sqlist[low] = sqlist[high];
        while (low < high && sqlist[low] <= mid) ++low;
        sqlist[high] = sqlist[low];
    }
    sqlist[low] = mid;
    return low;
}

template <typename T>
void sort_quick (T &sqlist, int low, int high)
{
    if (low < high)
    {
        auto midindex = partition_v2 (sqlist, low, high);
        sort_quick (sqlist, low, midindex - 1);
        sort_quick (sqlist, midindex + 1, high);
    }
}

int main ()
{
    std::vector<int> v = {4,10,1,5,3,2,9,6,8,7};

    auto v1 = v;

    int ret = partition_v1(v1, 0, v1.size() - 1);
    std::cout << "ret=" << ret << std::endl;
    for (auto i : v1)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    v1 = v;

    ret = partition_v2(v1, 0, v1.size() - 1);
    std::cout << "ret=" << ret << std::endl;
    for (auto i : v1)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    v1 = v;
    sort_quick (v1, 0, v1.size() - 1);
    for (auto i : v1)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}