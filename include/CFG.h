#ifndef CFG_H
#define CFG_H

#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>

class CFGNode {
public:
    std::string label;
    std::vector<CFGNode *> successors;

    CFGNode(const std::string &label) : label(label) {}
};

class CFG {
public:
    std::unordered_map<std::string, CFGNode*> nodes;

    CFGNode* addNode(const std::string &label);
    void addEdge(CFGNode *from, CFGNode *to);
    void exportToDot(const std::string &filename) const;
    ~CFG();
};

#endif // CFG_H
