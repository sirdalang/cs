
#include <iostream>

#include "gentree.h"
#include "traversetree.h"

int main() {
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

    return 0;
}