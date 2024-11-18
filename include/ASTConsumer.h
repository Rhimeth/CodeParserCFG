#ifndef AST_CONSUMER_H
#define AST_CONSUMER_H

#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include "CFG.h"
#include "CFGBuilder.h"

class ASTConsumer : public clang::ASTConsumer {
public:
    explicit ASTConsumer(CFG &cfg);
    void HandleTranslationUnit(clang::ASTContext &Context) override;

private:
    CFG &cfg;
    CFGBuilder cfgBuilder;
};

#endif // AST_CONSUMER_H
