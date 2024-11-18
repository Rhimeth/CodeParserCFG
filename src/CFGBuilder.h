#ifndef CFG_BUILDER_H
#define CFG_BUILDER_H

#include "CFG.h"
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/AST/ASTContext.h>

class CFGBuilder : public clang::RecursiveASTVisitor<CFGBuilder> {
public:
    CFG &cfg;
    explicit CFGBuilder(CFG &cfg);

    bool VisitFunctionDecl(clang::FunctionDecl *func);
    bool VisitStmt(clang::Stmt *stmt);
};

#endif // CFG_BUILDER_H
