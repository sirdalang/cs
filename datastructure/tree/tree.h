
#pragma once

typedef int ELETYPE;

/**
 * 树节点
 */
class Node;
class Node {
public:
    Node(const ELETYPE &e);
    void leftjoin(Node *node);
    void rightjoin(Node *node);
    Node *left();
    Node *right();

    ELETYPE data;
    Node *l;
    Node *r;
    bool lTag;   /* 为真表示left指向前驱 */
    bool rTag;  /* 为真表示right指向后继 */
};

