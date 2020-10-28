
#include "gentree.h"

/******

       1
    2     3
   4 5

******/

Node *gentree() {
    Node *root = new Node(1);

    Node *a2 = new Node(2);
    Node *a4 = new Node(4);
    Node *a5 = new Node(5);
    Node *a3 = new Node(3);

    a2->leftjoin(a4);
    a2->rightjoin(a5);
    root->leftjoin(a2);
    root->rightjoin(a3);

    return root;
}