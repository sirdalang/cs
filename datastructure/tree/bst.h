/**
 * BST
 * 二叉排序树
 */


#pragma once

#include <tuple>

#include "tree.h"

class BST {
public:
    BST();
    ~BST() {if(root__!=nullptr) delete root__;}
    Node *insert(const ELETYPE &ele);
    Node *find(const ELETYPE &ele);
    void remove(const ELETYPE &ele);
    void print() const;
private:
    typedef std::tuple<Node*,Node*,Node*> POS;
    static POS locate(Node *tree, const ELETYPE &ele);
    Node *root__;
};
