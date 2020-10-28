
#pragma once

typedef int ELETYPE;

/**
 * 树节点
 */
class Node {
public:
    Node(const ELETYPE &e, int iw = 1);
    void leftjoin(Node *node);
    void rightjoin(Node *node);
    Node *left();
    Node *right();
    int weight() const;

    ELETYPE data;
    Node *l;
    Node *r;
    bool ltag;   /* 为真表示left指向前驱 */
    bool rtag;  /* 为真表示right指向后继 */
    int w;      /* 权 */
};
