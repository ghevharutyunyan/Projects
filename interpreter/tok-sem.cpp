#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <memory>
#include <cctype>
#include<unordered_map>
#include <fstream>
#include <sstream>
enum class TokenType {
    KEYWORD, IDENTIFIER, OPERATOR, NUMBER_LITERAL, STRING_LITERAL, PUNCTUATOR, COMMENT, WHITESPACE, UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;

    Token(TokenType type, const std::string& value) : type(type), value(value) {}
};

bool isKeyword(const std::string& str) {
    static const std::unordered_set<std::string> keywords = {
        "Amboxj","Tox","Irakan","Zangvac","Logikakan",
        "for","while",
        "if","else","break",
        "True","False",
        "class", "continue", "else", "except", "finally", 
        "return"
    };
    return keywords.find(str) != keywords.end();
}


bool isOperator(char ch) {
    static const std::unordered_set<char> operators = {
        '+', '-', '*', '/', '%', '=', '!', '<', '>', '&', '|', '^', '~'
    };
    return operators.find(ch) != operators.end();
}

bool isPunctuator(char ch) {
    static const std::unordered_set<char> punctuators = {
        ':', ',', '(', ')', '[', ']', '{', '}', '.'
    };
    return punctuators.find(ch) != punctuators.end();
}

struct OperatorInfo {
    int precedence;
    bool rightAssociative;
};


std::unordered_map<std::string, OperatorInfo> operatorPrecedence = {
    {"=", {0, true}},     // Right associative
    {"+", {1, false}},
    {"-", {1, false}},
    {"*", {2, false}},
    {"/", {2, false}},
    {"%", {2, false}},
    {"==", {0, false}},
    {"!=", {0, false}},
    {"<", {0, false}},
    {"<=", {0, false}},
    {">", {0, false}},
    {">=", {0, false}},
    {"&&", {-1, false}},
    {"||", {-2, false}}
};


std::vector<Token> tokenize(const std::string& code) {
    std::vector<Token> tokens;
    size_t i = 0;
    while (i < code.size()) {
        if (std::isspace(code[i])) {
            ++i;
            continue;
        }
        if (std::isalpha(code[i]) || code[i] == '_') {
            size_t start = i;
            while (i < code.size() && (std::isalnum(code[i]) || code[i] == '_')) {
                ++i;
            }
            std::string word = code.substr(start, i - start);
            TokenType type = isKeyword(word) ? TokenType::KEYWORD : TokenType::IDENTIFIER;
            tokens.emplace_back(type, word);
        } else if (std::isdigit(code[i])) {
            size_t start = i;
            while (i < code.size() && std::isdigit(code[i])) {
                ++i;
            }
            if (i < code.size() && code[i] == '.') {
                ++i;
                while (i < code.size() && std::isdigit(code[i])) {
                    ++i;
                }
            }
            std::string number = code.substr(start, i - start);
            tokens.emplace_back(TokenType::NUMBER_LITERAL, number);
        } else if (code[i] == '"' || code[i] == '\'') {
            char quoteType = code[i];
            size_t start = i++;
            while (i < code.size() && code[i] != quoteType) {
                ++i;
            }
            if (i < code.size()) {
                ++i;
            }
            std::string strLiteral = code.substr(start, i - start);
            tokens.emplace_back(TokenType::STRING_LITERAL, strLiteral);
        } else if (code[i] == '#' || (code[i] == '/' && i + 1 < code.size() && code[i + 1] == '/')) {
            size_t start = i;
            while (i < code.size() && code[i] != '\n') {
                ++i;
            }
            std::string comment = code.substr(start, i - start);
            tokens.emplace_back(TokenType::COMMENT, comment);
        } else if (isOperator(code[i])) {
            std::string op(1, code[i]);
            if (i + 1 < code.size() && isOperator(code[i + 1])) {
                op += code[i + 1];
                ++i;
            }
            tokens.emplace_back(TokenType::OPERATOR, op);
            ++i;
        } else if (isPunctuator(code[i])) {
            std::string punct(1, code[i]);
            tokens.emplace_back(TokenType::PUNCTUATOR, punct);
            ++i;
        } else {
            std::string unknown(1, code[i]);
            tokens.emplace_back(TokenType::UNKNOWN, unknown);
            ++i;
        }
    }
    return tokens;
}



enum class NodeType {
    PROGRAM, VARIABLE_DECLARATION, FUNCTION_DECLARATION, FUNCTION_CALL,
    BINARY_OPERATION, IDENTIFIER, LITERAL, RETURN_STATEMENT, ASSIGNMENT,
    IF_STATEMENT,ELSE_STATEMENT,FOR_STATEMENT,WHILE_STATEMENT
};

struct ASTNode {
    NodeType type;
    std::vector<std::shared_ptr<ASTNode>> children;

    ASTNode(NodeType type) : type(type) {}
    virtual ~ASTNode() = default;
};

struct IdentifierNode : ASTNode {
    std::string name;

    IdentifierNode(const std::string& name) : ASTNode(NodeType::IDENTIFIER), name(name) {}
};

struct LiteralNode : ASTNode {
    std::string value;

    LiteralNode(const std::string& value) : ASTNode(NodeType::LITERAL), value(value) {}
};

struct BinaryOperationNode : ASTNode {
    std::shared_ptr<ASTNode> left;
    std::shared_ptr<ASTNode> right;
    std::string op;

    BinaryOperationNode(const std::shared_ptr<ASTNode>& left, const std::shared_ptr<ASTNode>& right, const std::string& op)
        : ASTNode(NodeType::BINARY_OPERATION), left(left), right(right), op(op) {}
};

struct AssignmentNode : ASTNode {
    std::shared_ptr<ASTNode> left;
    std::shared_ptr<ASTNode> right;

    AssignmentNode(const std::shared_ptr<ASTNode>& left, const std::shared_ptr<ASTNode>& right)
        : ASTNode(NodeType::ASSIGNMENT), left(left), right(right) {}
};

struct FunctionCallNode : ASTNode {
    std::string functionName;
    std::vector<std::shared_ptr<ASTNode>> arguments;

    FunctionCallNode(const std::string& functionName) : ASTNode(NodeType::FUNCTION_CALL), functionName(functionName) {}
};
struct IfStatementNode : ASTNode {
    std::shared_ptr<ASTNode> condition;
    std::shared_ptr<ASTNode> thenBranch;
    std::shared_ptr<ASTNode> elseBranch;

    IfStatementNode(const std::shared_ptr<ASTNode>& condition)
        : ASTNode(NodeType::IF_STATEMENT), condition(condition) {}
};

struct ForStatementNode : ASTNode {
    std::shared_ptr<ASTNode> init;
    std::shared_ptr<ASTNode> condition;
    std::shared_ptr<ASTNode> increment;
    std::shared_ptr<ASTNode> body;

    ForStatementNode(const std::shared_ptr<ASTNode>& init, const std::shared_ptr<ASTNode>& condition,
                     const std::shared_ptr<ASTNode>& increment, const std::shared_ptr<ASTNode>& body)
        : ASTNode(NodeType::FOR_STATEMENT), init(init), condition(condition), increment(increment), body(body) {}
};

struct WhileStatementNode : ASTNode {
    std::shared_ptr<ASTNode> condition;
    std::shared_ptr<ASTNode> body;

    WhileStatementNode(const std::shared_ptr<ASTNode>& condition, const std::shared_ptr<ASTNode>& body)
        : ASTNode(NodeType::WHILE_STATEMENT), condition(condition), body(body) {}
};

class Parser {
    std::vector<Token> tokens;
    size_t currentTokenIndex = 0;

    int getPrecedence(const std::string& op) {
        if (operatorPrecedence.find(op) != operatorPrecedence.end()) {
            return operatorPrecedence[op].precedence;
        }
        return -1;
    }

    bool isRightAssociative(const std::string& op) {
        if (operatorPrecedence.find(op) != operatorPrecedence.end()) {
            return operatorPrecedence[op].rightAssociative;
        }
        return false;
    }

    std::shared_ptr<ASTNode> parsePrimary() {
        if (currentTokenIndex >= tokens.size()) {
            return nullptr;
        }

        auto token = tokens[currentTokenIndex];

        if (token.type == TokenType::IDENTIFIER) {
            std::string identifier = token.value;
            ++currentTokenIndex;
            if (currentTokenIndex < tokens.size() && tokens[currentTokenIndex].value == "(") {
                ++currentTokenIndex;
                auto functionCallNode = std::make_shared<FunctionCallNode>(identifier);
                while (currentTokenIndex < tokens.size() && tokens[currentTokenIndex].value != ")") {
                    functionCallNode->arguments.push_back(parseExpression());
                    if (tokens[currentTokenIndex].value == ",") {
                        ++currentTokenIndex;
                    }
                }
                if (currentTokenIndex < tokens.size() && tokens[currentTokenIndex].value == ")") {
                    ++currentTokenIndex;
                }
                return functionCallNode;
            }
            return std::make_shared<IdentifierNode>(identifier);
        } else if (token.type == TokenType::NUMBER_LITERAL || token.type == TokenType::STRING_LITERAL) {
            ++currentTokenIndex;
            return std::make_shared<LiteralNode>(token.value);
        } else if (token.value == "(") {
            ++currentTokenIndex;
            auto expr = parseExpression();
            if (currentTokenIndex < tokens.size() && tokens[currentTokenIndex].value == ")") {
                ++currentTokenIndex;
            }
            return expr;
        } else if (token.value == "if") {
            ++currentTokenIndex;
            auto condition = parseExpression();
            auto ifNode = std::make_shared<IfStatementNode>(condition);
            ifNode->thenBranch = parseBlock();
            if (currentTokenIndex < tokens.size() && tokens[currentTokenIndex].value == "else") {
                ++currentTokenIndex;
                ifNode->elseBranch = parseBlock();
            }
            return ifNode;
        }
            else if (token.value == "for") {
            ++currentTokenIndex;
            auto init = parseExpression();
            if (currentTokenIndex < tokens.size() && tokens[currentTokenIndex].value == ";") {
                ++currentTokenIndex;
            }
            auto condition = parseExpression();
            if (currentTokenIndex < tokens.size() && tokens[currentTokenIndex].value == ";") {
                ++currentTokenIndex;
            }
            auto increment = parseExpression();
            auto forNode = std::make_shared<ForStatementNode>(init, condition, increment, parseBlock());
            return forNode;
        } else if (token.value == "while") {
            ++currentTokenIndex;
            auto condition = parseExpression();
            auto whileNode = std::make_shared<WhileStatementNode>(condition, parseBlock());
            return whileNode;
        }

        return nullptr;
    }
        



    

    std::shared_ptr<ASTNode> parseBinaryOpRHS(int exprPrec, std::shared_ptr<ASTNode> lhs) {
        while (true) {
            if (currentTokenIndex >= tokens.size()) {
                return lhs;
            }

            std::string op = tokens[currentTokenIndex].value;
            int tokPrec = getPrecedence(op);

            if (tokPrec < exprPrec) {
                return lhs;
            }

            ++currentTokenIndex;
            auto rhs = parsePrimary();
            if (!rhs) {
                return nullptr;
            }

            int nextPrec = getPrecedence(tokens[currentTokenIndex].value);
            if (tokPrec < nextPrec || (tokPrec == nextPrec && isRightAssociative(tokens[currentTokenIndex].value))) {
                rhs = parseBinaryOpRHS(tokPrec + 1, rhs);
                if (!rhs) {
                    return nullptr;
                }
            }

            lhs = std::make_shared<BinaryOperationNode>(lhs, rhs, op);
        }
    }

    std::shared_ptr<ASTNode> parseBlock() {
        auto blockNode = std::make_shared<ASTNode>(NodeType::PROGRAM);
        while (currentTokenIndex < tokens.size() && tokens[currentTokenIndex].value != "}") {
            auto stmt = parseAssignment();
            if (stmt) {
                blockNode->children.push_back(stmt);
            } else {
                ++currentTokenIndex;
            }
        }
        if (currentTokenIndex < tokens.size() && tokens[currentTokenIndex].value == "}") {
            ++currentTokenIndex;
        }
        return blockNode;
    }

public:
    Parser(const std::vector<Token>& tokens) : tokens(tokens) {}

    std::shared_ptr<ASTNode> parseExpression() {
        auto lhs = parsePrimary();
        if (!lhs) {
            return nullptr;
        }
        return parseBinaryOpRHS(0, lhs);
    }

    std::shared_ptr<ASTNode> parseAssignment() {
        auto lhs = parsePrimary();
        if (!lhs) {
            return nullptr;
        }
        if (currentTokenIndex < tokens.size() && tokens[currentTokenIndex].value == "=") {
            ++currentTokenIndex;
            auto rhs = parseExpression();
            if (!rhs) {
                return nullptr;
            }
            return std::make_shared<AssignmentNode>(lhs, rhs);
        }
        return lhs;
    }

    std::shared_ptr<ASTNode> parse() {
        auto root = std::make_shared<ASTNode>(NodeType::PROGRAM);
        while (currentTokenIndex < tokens.size()) {
            auto expr = parseAssignment();
            if (expr) {
                root->children.push_back(expr);
            } else {
                ++currentTokenIndex;  // Prevent infinite loop on error
            }
        }
        return root;
    }
};

// AST printing (for debugging purposes)
void printAST(const std::shared_ptr<ASTNode>& node, int indent = 0) {
    if (!node) return;
    std::string indentation(indent, ' ');

    switch (node->type) {
        case NodeType::PROGRAM:
            std::cout << indentation << "Program\n";
            break;
        case NodeType::VARIABLE_DECLARATION:
            std::cout << indentation << "VariableDeclaration\n";
            break;
        case NodeType::FUNCTION_DECLARATION:
            std::cout << indentation << "FunctionDeclaration\n";
            break;
        case NodeType::FUNCTION_CALL: {
            auto funcCallNode = std::dynamic_pointer_cast<FunctionCallNode>(node);
            std::cout << indentation << "FunctionCall: " << funcCallNode->functionName << "\n";
            for (const auto& arg : funcCallNode->arguments) {
                printAST(arg, indent + 2);
            }
            return;
        }
        case NodeType::BINARY_OPERATION: {
            auto binOpNode = std::dynamic_pointer_cast<BinaryOperationNode>(node);
            std::cout << indentation << "BinaryOperation: " << binOpNode->op << "\n";
            printAST(binOpNode->left, indent + 2);
            printAST(binOpNode->right, indent + 2);
            return;
        }
        case NodeType::ASSIGNMENT: {
            auto assignNode = std::dynamic_pointer_cast<AssignmentNode>(node);
            std::cout << indentation << "Assignment\n";
            printAST(assignNode->left, indent + 2);
            printAST(assignNode->right, indent + 2);
            return;
        }
        case NodeType::IDENTIFIER: {
            auto idNode = std::dynamic_pointer_cast<IdentifierNode>(node);
            std::cout << indentation << "Identifier: " << idNode->name << "\n";
            return;
        }
        case NodeType::LITERAL: {
            auto litNode = std::dynamic_pointer_cast<LiteralNode>(node);
            std::cout << indentation << "Literal: " << litNode->value << "\n";
            return;
        }
        case NodeType::RETURN_STATEMENT:
            std::cout << indentation << "ReturnStatement\n";
            break;
        case NodeType::IF_STATEMENT: {
            auto ifNode = std::dynamic_pointer_cast<IfStatementNode>(node);
            std::cout << indentation << "IfStatement\n";
            std::cout << indentation << "Condition:\n";
            printAST(ifNode->condition, indent + 2);
            std::cout << indentation << "Then:\n";
            printAST(ifNode->thenBranch, indent + 2);
            if (ifNode->elseBranch) {
                std::cout << indentation << "Else:\n";
                printAST(ifNode->elseBranch, indent + 2);
            }
            return;
        }
        case NodeType::ELSE_STATEMENT:
            std::cout << indentation << "ElseStatement\n";
            break;
        case NodeType::FOR_STATEMENT: {
            auto forNode = std::dynamic_pointer_cast<ForStatementNode>(node);
            std::cout << indentation << "ForStatement\n";
            std::cout << indentation << "Init:\n";
            printAST(forNode->init, indent + 2);
            std::cout << indentation << "Condition:\n";
            printAST(forNode->condition, indent + 2);
            std::cout << indentation << "Increment:\n";
            printAST(forNode->increment, indent + 2);
            std::cout << indentation << "Body:\n";
            printAST(forNode->body, indent + 2);
            return;
    }
    case NodeType::WHILE_STATEMENT:{
    auto whileNode = std::dynamic_pointer_cast<WhileStatementNode>(node);
    std::cout << indentation << "WhileStatement\n";
    std::cout << indentation << "Condition:\n";
     printAST(whileNode->condition, indent + 2);
    std::cout << indentation << "Body:\n";
    printAST(whileNode->body, indent + 2);
    return;
}
default:
std::cout << indentation << "UnknownNode\n";
break;
    }
 
    for (const auto& child : node->children) {
        printAST(child, indent + 2);
    }
}


std::string removeComments(const std::string& line) {
    size_t commentPos = line.find("//");
    if (commentPos != std::string::npos) {
        return line.substr(0, commentPos);
    }
    return line;
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    if (first == std::string::npos || last == std::string::npos) {
        return "";
    }
    return str.substr(first, last - first + 1);
}
// Function to process file content
std::pair<std::vector<std::string>, std::vector<std::string>> processFileContent(const std::string& content) {
    std::vector<std::string> statements;
    std::vector<std::string> blocks;
    
    std::istringstream inFile(content);
    std::string line;
    std::ostringstream currentBlock;
    std::ostringstream currentStatement;
    bool inBlock = false;
    int blockLevel = 0;

   

    while (std::getline(inFile, line)) {
        line = removeComments(line);
        std::string trimmedLine = trim(line);
        
        if (trimmedLine.empty()) {
            continue; // Skip empty lines
        }

        if (!inBlock) {
            if (trimmedLine.back() == ';') {
                // This is a statement ending with ';'
                statements.push_back(trimmedLine);
            } else if (trimmedLine.back() == '{') {
                // Start of a block
                currentBlock << trimmedLine << '\n';
                inBlock = true;
                blockLevel = 1;
            } else if (trimmedLine.find(';') != std::string::npos) {
                // Handle multi-line statements
                currentStatement << trimmedLine;
                if (trimmedLine.back() == ';') {
                    statements.push_back(currentStatement.str());
                    currentStatement.str("");
                    currentStatement.clear();
                }
            } else {
                // Handle lines that are part of a multi-line statement or block start
                currentStatement << trimmedLine << ' ';
            }
        } else {
            currentBlock << trimmedLine << '\n';
            for (char c : trimmedLine) {
                if (c == '{') {
                    blockLevel++;
                } else if (c == '}') {
                    blockLevel--;
                }
            }
            if (blockLevel == 0) {
                // End of a block
                blocks.push_back(currentBlock.str());
                currentBlock.str(""); // Clear the current block
                currentBlock.clear();
                inBlock = false;
            }
        }
    }

    return std::make_pair(statements, blocks);
}
int main() {
    // Create an input file stream (ifstream) object
    std::ifstream file("text.txt");

    // Check if the file was opened successfully
    if (!file) {
        std::cerr << "Error opening file for reading" << std::endl;
        return 1;
    }

    // Read the file content into a string
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    // Close the file
    file.close();

    // Process the file content
    auto result = processFileContent(content);

    // Output results
    std::cout << "Statements:" << std::endl;
    for (const auto& statement : result.first) {
        std::cout << statement << std::endl;
    }

    std::cout << "\nBlocks:" << std::endl;
    for (const auto& block : result.second) {
        std::cout << block << std::endl;
        std::cout << "------------------" << std::endl;
    }

    return 0;
}




