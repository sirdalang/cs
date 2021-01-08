
#include <iostream>
#include <functional>
#include <algorithm>

#include "sort.h"

void print(const std::vector<int> &ref) {
    for (auto item : ref) {
        std::cout << item << " ";
    }
}

int main() {
    std::vector<std::function<void(std::vector<int> &)> > fs;
    fs.push_back(sort_insert);
    fs.push_back(sort_insert_half);
    fs.push_back(sort_shell);

    for (int m = 0; m < 100; ++m) {
        std::vector<int> ori = {0,1,2,3,4,5,6,7,8,9};
        std::vector<int> dst = ori;
        std::random_shuffle(dst.begin(), dst.end());

        for (auto it = fs.cbegin(); it != fs.cend(); ++it) {
            std::vector<int> temp = dst;
            (*it)(temp);
            if (temp != ori) {
                std::cout << std::endl;
                std::cout << "temp";
                print (temp);
                std::cout << std::endl;
                std::cout << "ori" ;
                print (ori);
                std::cout << std::endl;

                std::cout << "error!" << std::endl;
                break;
            }
        }
    }

    return 0;
}