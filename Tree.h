

#ifndef TIC_TAC_TOE_TREE_H
#define TIC_TAC_TOE_TREE_H


#include "Node.h"

class Tree {
private:
    const Node root;
    vector<Node> children;
public:
    Tree();
    ~Tree();
    void addChild(const Node &child);
    const Node &getRoot() const;

};


#endif //TIC_TAC_TOE_TREE_H
