
#include <iostream>

#include "gentree.h"
#include "traversetree.h"
#include "wpl.h"
#include "bst.h"

void traverse() {
    Node *tree = gentree();

    std::cout << "recursive_traverse_preorder:" << std::endl;
    recursive_traverse_preorder (tree);
    std::cout << std::endl;

    std::cout << "recursive_traverse_inorder:" << std::endl;
    recursive_traverse_inorder (tree);
    std::cout << std::endl;

    std::cout << "recursive_traverse_postorder:" << std::endl;
    recursive_traverse_postorder (tree);
    std::cout << std::endl;

    std::cout << "nonrecur_traverse_preorder:" << std::endl;
    nonrecur_traverse_preorder (tree);
    std::cout << std::endl;

    std::cout << "nonrecur_traverse_inorder:" << std::endl;
    nonrecur_traverse_inorder (tree);
    std::cout << std::endl;

    std::cout << "nonrecur_traverse_postorder:" << std::endl;
    nonrecur_traverse_postorder (tree);
    std::cout << std::endl;

    std::cout << "level_traverse:" << std::endl;
    level_traverse (tree);
    std::cout << std::endl;
}

void wpl_eg() {
    Node *tree = gentree();
    int nWPL = calc_wpl(tree);
    std::cout << "WPL=" << nWPL << std::endl;
}

void bst_test() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.print();

    std::cout << "bst.find(3)=" << bst.find(3) << std::endl;
    std::cout << "bst.find(6)=" << bst.find(6) << std::endl;

    bst.remove(3);
    bst.print();
}

int main() {

    // traverse();
    // wpl_eg();
    bst_test();

    return 0;
}