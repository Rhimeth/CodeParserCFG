#include "CFG.h"
#include "ASTConsumer.h"
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <clang/Frontend/FrontendActions.h>
#include <llvm/Support/CommandLine.h> // For cl::GeneralCategory
#include <iostream>
#include <memory> // For std::make_unique

using namespace clang::tooling;

class CFGAction : public clang::ASTFrontendAction {
public:
    explicit CFGAction(CFG &cfg) : cfg(cfg) {}

    std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &, llvm::StringRef) override {
        return std::make_unique<ASTConsumer>(cfg);
    }

private:
    CFG &cfg;
};

int main(int argc, const char **argv) {
    // Initialize CFG
    CFG cfg;

    // Initialize CommonOptionsParser
    llvm::cl::OptionCategory MyToolCategory("CFG Analysis Tool");
    CommonOptionsParser optionsParser(argc, argv, MyToolCategory);

    // Set up ClangTool with the parsed options
    ClangTool tool(optionsParser.getCompilations(), optionsParser.getSourcePathList());

    // Run the tool
    int result = tool.run(newFrontendActionFactory<CFGAction>().get());
    if (result != 0) {
        std::cerr << "Error: ClangTool execution failed with code " << result << ".\n";
        return result;
    }

    // Export CFG to a DOT file
    if (!cfg.exportToDot("cfg_output.dot")) {
        std::cerr << "Error: Failed to export CFG to DOT file.\n";
        return 1;
    }

    std::cout << "CFG successfully exported to cfg_output.dot.\n";
    return 0;
}
