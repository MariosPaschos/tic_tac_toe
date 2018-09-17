#ifndef TIC_TAC_TOE_NODE_H
#define TIC_TAC_TOE_NODE_H


#include "Cell.h"

#include <vector>


class Node : public Cell {
private:
    const Node *parent;
    vector<Node> children;
    int value;
    bool visited;

public:
    Node();
    Node(Cell cell, Node *parent);
    ~Node();
    Node(const Node &node)= default;
    Node &operator=(const Node &node)= default;


    void setParent(const Node *parent);
    const Node *getParent() const;
    void addChild(const Node &child);
    const vector<Node> &getChildren() const;
    int getValue() const;
    void setValue(int value);
    bool isTerminal() const;
    void setVisited(bool visited);
    bool isVisited() const;
};


#endif //TIC_TAC_TOE_NODE_H
