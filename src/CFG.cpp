#include "CFG.h"
#include <iostream>

CFGNode* CFG::addNode(const std::string &label) {
    if (nodes.find(label) == nodes.end()) {
        nodes[label] = new CFGNode(label);
    }
    return nodes[label];
}

void CFG::addEdge(CFGNode *from, CFGNode *to) {
    if (from && to) {
        from->successors.push_back(to);
    }
}

void CFG::exportToDot(const std::string &filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Failed to open output file " << filename << std::endl;
        return;
    }
    out << "digraph CFG {" << std::endl;
    for (const auto &pair : nodes) {
        const auto *node = pair.second;
        for (const auto *succ : node->successors) {
            out << "    \"" << node->label << "\" -> \"" << succ->label << "\";" << std::endl;
        }
    }
    out << "}" << std::endl;
    out.close();
    std::cout << "CFG exported to " << filename << std::endl;
}

CFG::~CFG() {
    for (auto &pair : nodes) delete pair.second;
}
