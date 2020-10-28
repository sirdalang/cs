#include "tree.h"

Node::Node(const ELETYPE &e) {
    data = e;
    l = nullptr;
    r = nullptr;
    lTag = false;
    rTag = false;
}

void Node::leftjoin(Node *node) {
    l = node;
}

void Node::rightjoin(Node *node) {
    r = node;
}

Node *Node::left() {
    return l;
}

Node *Node::right() {
    return r;
}