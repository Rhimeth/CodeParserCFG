#include "CFG.h"
#include "ASTConsumer.h"
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <clang/Frontend/FrontendActions.h>
#include <iostream>

using namespace clang::tooling;

class CFGAction : public clang::ASTFrontendAction {
public:
    CFGAction(CFG &cfg) : cfg(cfg) {}
    std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &, llvm::StringRef) override {
        return std::make_unique<ASTConsumer>(cfg);
    }

private:
    CFG &cfg;
};

int main(int argc, const char **argv) {
    CFG cfg;

    CommonOptionsParser optionsParser(argc, argv, cl::GeneralCategory);
    ClangTool tool(optionsParser.getCompilations(), optionsParser.getSourcePathList());
    tool.run(newFrontendActionFactory<CFGAction>(&cfg).get());

    cfg.exportToDot("cfg_output.dot");

    return 0;
}
