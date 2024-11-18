#include "ASTConsumer.h"

ASTConsumer::ASTConsumer(CFG &cfg) : cfg(cfg), cfgBuilder(cfg) {}

void ASTConsumer::HandleTranslationUnit(clang::ASTContext &Context) {
    cfgBuilder.TraverseDecl(Context.getTranslationUnitDecl());
}
