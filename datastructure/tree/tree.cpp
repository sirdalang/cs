#include "tree.h"

Node::Node(const ELETYPE &e, int iw) {
    data = e;
    l = nullptr;
    r = nullptr;
    ltag = false;
    rtag = false;
    w = iw;
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

int Node::weight() const {
    return w;
}