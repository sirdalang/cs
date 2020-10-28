
#include "traversetree.h"

#include <iostream>
#include <stack>

void visit(const Node *node) {
    std::cout << node->data << " ";
}

/* 递归先序遍历 */
void recursive_traverse_preorder(Node *tree) {
    if (tree == nullptr) {
        return ;
    }

    visit(tree);
    recursive_traverse_preorder(tree->left());
    recursive_traverse_preorder(tree->right());
}

/* 递归中序遍历 */
void recursive_traverse_inorder(Node *tree) {
    if (tree == nullptr) {
        return ;
    }

    recursive_traverse_inorder(tree->left());
    visit(tree);
    recursive_traverse_inorder(tree->right());
}


/* 递归后序遍历 */
void recursive_traverse_postorder(Node *tree) {
    if (tree == nullptr) {
        return ;
    }

    recursive_traverse_postorder(tree->left());
    recursive_traverse_postorder(tree->right());
    visit(tree);
}

/** 
 * 非递归先序遍历 
 * 使用栈对树进行非递归遍历。
 * 先序遍历的顺序和非递归遍历访问元素的顺序相同。
 * 
 * 指针移动逻辑：
 * 使用一个遍历指针，指向根节点
 * 当指针非空时，向左子树移动。
 * 当指针为空时，
 *   有上一层路径，则退回到上一层路径并向右移动，抹去上一层路径。
 *   没有上一层路径，则停止。
 * 
 * 访问逻辑：
 * 第一次移动到一个节点时，即访问。
 */
void nonrecur_traverse_preorder(Node *tree) {
    std::stack<Node*> st;
    Node *it = tree;
    while (true) {
        if (it != nullptr) {
            visit(it);
            st.push(it);
            it = it->left();
        }
        else {
            if (st.empty()) {
                break;
            }
            else {
                it = st.top();
                st.pop();
                it = it->right();
            }
        }
    }
}

/**
 * 非递归中序遍历
 * 
 * 指针移动逻辑：
 * 和非递归前序遍历指针移动逻辑一致。
 * 
 * 访问逻辑：
 * 当左子树遍历完成，即将遍历右子树时，访问节点。
 */
void nonrecur_traverse_inorder(Node *tree) {
    std::stack<Node*> st;
    Node *it = tree;
    while (true) {
        if (it != nullptr) {
            st.push(it);
            it = it->left();
        }
        else {
            if (st.empty()) {
                break;
            }
            else {
                it = st.top();
                st.pop();
                visit(it);
                it = it->right();
            }
        }
    }
}


/**
 * 非递归后序遍历
 * 
 * 指针移动逻辑：
 * 当指针非空时，移向左节点。
 * 当指针为空时，
 *   若有上一层路径，则退回到上一层路径并向右移动（不抹去上一层路径）
 *   若没有上一层路径，则停止。
 * 
 * 访问逻辑：
 * 当左子树遍历完成，且右子树遍历完成，即将进入
 * 上一层节点时，访问节点。
 */
void nonrecur_traverse_postorder(Node *tree) {
    std::stack<Node*> st;
    Node *it = tree;
    Node *lastVisit = nullptr; /* 记录最后访问的节点 */
    while (true) {
        if (it != nullptr) {
            st.push(it);
            it = it->left();
        }
        else {
            if (st.empty()) {
                break;
            }
            else {
                it = st.top();

                if (it->right() == nullptr || 
                    it->right() == lastVisit) {
                    visit(it);
                    lastVisit = it;
                    st.pop();
                    it = nullptr;
                }
                else {
                    it = it->right();
                    st.push(it);
                    it = it->left();
                }
            }
        }
    }
}