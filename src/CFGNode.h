#ifndef CFGNODE_H
#define CFGNODE_H

#include <string>
#include <vector>
#include <memory>

/**
 * @class CFGNode
 * @brief Represents a single node in a Control Flow Graph (CFG).
 */
class CFGNode {
public:
    int id;                              ///< Unique identifier for the node
    std::string label;                   ///< Label describing the node's content
    std::vector<std::shared_ptr<CFGNode>> successors; ///< Nodes that this node connects to
    std::vector<std::shared_ptr<CFGNode>> predecessors; ///< Nodes that connect to this node

public:
    /**
     * @brief Constructor for CFGNode.
     * @param id Unique identifier for the node.
     * @param label Description or label of the node.
     */
    CFGNode(int id, const std::string &label);

    /**
     * @brief Get the ID of the node.
     * @return The ID of the node.
     */
    int getId() const;

    /**
     * @brief Get the label of the node.
     * @return The label of the node.
     */
    std::string getLabel() const;

    /**
     * @brief Add a successor to this node.
     * @param node Shared pointer to the successor node.
     */
    void addSuccessor(const std::shared_ptr<CFGNode> &node);

    /**
     * @brief Add a predecessor to this node.
     * @param node Shared pointer to the predecessor node.
     */
    void addPredecessor(const std::shared_ptr<CFGNode> &node);

    /**
     * @brief Get all successor nodes.
     * @return A vector of shared pointers to successor nodes.
     */
    const std::vector<std::shared_ptr<CFGNode>> &getSuccessors() const;

    /**
     * @brief Get all predecessor nodes.
     * @return A vector of shared pointers to predecessor nodes.
     */
    const std::vector<std::shared_ptr<CFGNode>> &getPredecessors() const;

    /**
     * @brief Print a textual representation of the node.
     */
    void print() const;
};

#endif // CFGNODE_H
