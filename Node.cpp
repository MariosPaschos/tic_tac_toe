#include "Node.h"

Node::Node() : Cell(), parent(nullptr), children(0), value(0), visited(false) {}


Node::Node(Cell cell, Node *parent) : Cell(cell.getI(), cell.getJ()), parent(parent), children(0), value(0), visited(false) {}

Node::~Node() {
    children.clear();
}

const vector<Node> &Node::getChildren() const {
    return this->children;
}

void Node::addChild(const Node &child) {
    this->children.push_back(child);
}

bool Node::isTerminal() const {
    return children.empty();
}

int Node::getValue() const {
    return value;
}

void Node::setValue(int value) {
    this->value = value;
}

void Node::setVisited(bool visited) {
    this->visited = visited;
}

bool Node::isVisited() const {
    return visited;
}

const Node *Node::getParent() const {
    return this->parent;
}

void Node::setParent(const Node *parent) {
    Node::parent = parent;
}








