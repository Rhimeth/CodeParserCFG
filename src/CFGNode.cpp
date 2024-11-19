#include "CFGNode.h"
#include <iostream>

CFGNode::CFGNode(int id, const std::string &label) : id(id), label(label) {}

int CFGNode::getId() const {
    return id;
}

std::string CFGNode::getLabel() const {
    return label;
}

void CFGNode::addSuccessor(const std::shared_ptr<CFGNode> &node) {
    successors.push_back(node);
}

void CFGNode::addPredecessor(const std::shared_ptr<CFGNode> &node) {
    predecessors.push_back(node);
}

const std::vector<std::shared_ptr<CFGNode>> &CFGNode::getSuccessors() const {
    return successors;
}

const std::vector<std::shared_ptr<CFGNode>> &CFGNode::getPredecessors() const {
    return predecessors;
}

void CFGNode::print() const {
    std::cout << "Node " << id << ": " << label << "\n";
    std::cout << "  Successors: ";
    for (const auto &succ : successors) {
        std::cout << succ->getId() << " ";
    }
    std::cout << "\n  Predecessors: ";
    for (const auto &pred : predecessors) {
        std::cout << pred->getId() << " ";
    }
    std::cout << "\n";
}
