

#include "Tree.h"

Tree::Tree() : root(Node()), children(0) {}

Tree::~Tree() {
    children.clear();
}

void Tree::addChild(const Node &child) {
    this->children.push_back(child);
}

const Node &Tree::getRoot() const {
    return this->root;
}
