#include "clang/Tooling/Tooling.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "llvm/Support/CommandLine.h"

// Define a custom factory to pass arguments to CFGAction
class CFGActionFactory : public clang::tooling::FrontendActionFactory {
    CFG *cfg;

public:
    explicit CFGActionFactory(CFG *cfg) : cfg(cfg) {}

    std::unique_ptr<clang::FrontendAction> create() override {
        return std::make_unique<CFGAction>(cfg);
    }
};

// Main function
int main(int argc, const char **argv) {
    llvm::cl::OptionCategory MyToolCategory("CFG Tool Options");

    // Initialize the options parser
    clang::tooling::CommonOptionsParser optionsParser(argc, argv, MyToolCategory);

    // Create the Clang tool
    clang::tooling::ClangTool tool(optionsParser.getCompilations(), optionsParser.getSourcePathList());

    // Run the tool with the custom factory
    CFG cfg;
    tool.run(new CFGActionFactory(&cfg).get());

    return 0;
}
