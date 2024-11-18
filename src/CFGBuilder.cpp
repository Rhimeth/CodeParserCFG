#include "CFGBuilder.h"
#include <clang/AST/Stmt.h>

CFGBuilder::CFGBuilder(CFG &cfg) : cfg(cfg) {}

bool CFGBuilder::VisitFunctionDecl(clang::FunctionDecl *func) {
    if (func->hasBody()) {
        CFGNode *entryNode = cfg.addNode(func->getNameInfo().getName().getAsString() + "_entry");
        TraverseStmt(func->getBody());
    }
    return true;
}

bool CFGBuilder::VisitStmt(clang::Stmt *stmt) {
    if (clang::isa<clang::IfStmt>(stmt)) {
        cfg.addNode("IfStmt");
    }
    return true;
}
