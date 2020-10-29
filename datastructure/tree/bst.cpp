
#include "bst.h"

#include <assert.h>
#include <iostream>
#include <exception>

#include "traversetree.h"

BST::BST() {
    root__ = nullptr;
}

Node* BST::insert(const ELETYPE &ele) {
    Node *node = new Node(ele);

    if (root__ == nullptr) {
        root__ = node;
    }
    else {
        POS pos = locate(root__,ele);
        Node *it = std::get<0>(pos);
        Node *pit = std::get<1>(pos);

        if (it != nullptr) {
            delete node;
            throw std::logic_error("");
        }
        else {
            if (ele < pit->data) {
                pit->leftjoin(node);
            }
            else if (ele > pit->data) {
                pit->rightjoin(node);
            }
        }
    }
    return node;
}

Node* BST::find(const ELETYPE &ele) {
    POS pos = locate(root__,ele);
    Node *it = std::get<0>(pos);
    return it;
}

void BST::remove(const ELETYPE &ele) {
    POS pos = locate(root__, ele);
    Node *it = std::get<0>(pos);
    Node *pit = std::get<1>(pos);

    if (it == nullptr) {
        throw std::logic_error("");
    }

    if (it->left() == nullptr) {
        if (pit != nullptr) {
            pit->replace(it, it->right());
        }
        it->destroy();
    }
    else if (it->right() == nullptr) {
        if (pit != nullptr) {
            pit->replace(it, it->left());
        }
        it->destroy();
    }
    else {
        it->destroy();
    }
}

void BST::print() const {
    std::cout << "recursive_traverse_preorder:" << std::endl;
    recursive_traverse_preorder(root__);
    std::cout << std::endl;

    std::cout << "recursive_traverse_inorder:" << std::endl;
    recursive_traverse_inorder(root__);
    std::cout << std::endl;

    std::cout << "recursive_traverse_postorder:" << std::endl;
    recursive_traverse_postorder(root__);
    std::cout << std::endl;

    std::cout << "level_traverse:" << std::endl;
    level_traverse(root__);
    std::cout << std::endl;

    std::cout << std::endl;
}


/**
 * 定位元素的位置
 * 若元素存在，(所在节点，上一层节点，上一层上一层节点)
 * 若元素不存在，(null,上一层节点，上一层上一层节点)
 */
BST::POS BST::locate(Node *tree, const ELETYPE &ele) {
    Node *ppre = nullptr;
    Node *pre = nullptr;
    Node *it = tree;
    while (it != nullptr) {
        if (ele < it->data) {
            ppre = pre;
            pre = it;
            it = it->left();
        }
        else if (ele > it->data) {
            ppre = pre;
            pre = it;
            it = it->right();
        }
        else {
            break;
        }
    }
    return std::make_tuple(it,pre,ppre);
}