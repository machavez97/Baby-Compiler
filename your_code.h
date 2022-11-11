#ifndef YOUR_CODE_H
#define YOUR_CODE_H

typedef enum{ASTNODE_ARITH_OP, ASTNODE_LOGIC_OP, ASTNODE_COMPARE, ASTNODE_ASSIGN, ASTNODE_IDENT, ASTNODE_NUM, ASTNODE_IF, ASTNODE_WHILE, ASTNODE_DECLARATION_LIST} ASTNodeType;

// Define all operation types (add, mult, etc) here.
typedef enum{ADD_OP, MULT_OP, SUB_OP, DIV_OP} ASTOp; 

typedef struct ASTNode ASTNode;
struct ASTNode{
	ASTNodeType type; 
    ASTOp op; // The actual operation (add, mult, etc)
	int num;  //Need to store the actual value for number nodes
	char *name; //Need to store the actual variable name for ident nodes
	ASTNode* left; // Left child
	ASTNode* right; // Right child
	ASTNode* cond; //condition for if/while nodes
	
	// The following pointer is just a suggestion; you don't have to use it if you have a better design.
	ASTNode* next; // a pointer used to link statement nodes together in a statement list

// Depending on your implementation, you may need to add other fields to this struct 

};

// Add functions to create the different kinds of ASTNodes 
// These functions are called by the code embedded in the grammar.
// Here are some samples:  
ASTNode* CreateNumNode(int num);
ASTNode* CreateIdentNode(char* name);
ASTNode* CreateStatementListNode(ASTNode* st, ASTNode* stList);
ASTNode* CreateAssignNode(ASTNode* lhs, ASTNode* expr);
ASTNode* CreateAddNode(ASTNode* expr, ASTNode* term);
ASTNode* CreateSubNode(ASTNode* expr, ASTNode* term);
ASTNode* CreateMultNode(ASTNode* term, ASTNode* factor);
ASTNode* CreateDivNode(ASTNode* term, ASTNode* factor);
ASTNode* CreateIfNode(ASTNode* cond, ASTNode* stList);
ASTNode* CreateIfElseNode(ASTNode* cond, ASTNode* stList, ASTNode* stList2);
ASTNode* CreateCompareListNode(ASTNode* compare, ASTNode* compareList);
ASTNode* CreateANDNode(ASTNode* compare, ASTNode* compareList);
ASTNode* CreateORNode(ASTNode* compare, ASTNode* condList);
ASTNode* CreateEqualNode(ASTNode* expr, ASTNode* expr2);
ASTNode* CreateNotEqualNode(ASTNode* expr, ASTNode* expr2);
ASTNode* CreateGreaterNode(ASTNode* expr, ASTNode* expr2);
ASTNode* CreateLessNode(ASTNode* expr, ASTNode* expr2);
ASTNode* CreateGreaterEqualNode(ASTNode* expr, ASTNode* expr2);
ASTNode* CreateLessEqualNode(ASTNode* expr, ASTNode* expr2);
ASTNode* CreateWhileNode(ASTNode* cond, ASTNode* stList);




// Need a function to add a declaration to your symbol table
void AddDeclaration(char* name);

// This is the function that generates ILOC code after the construction of the AST
//void GenerateILOC(ASTNode* node);
ASTNode* CreateDeclarationListNode(ASTNode* dc, ASTNode* dcList);

struct Symbol{
	char* name;
	char* offset;
};


struct Symbol* table[100];

void Insert(char *name);
struct Symbol *Search(char *name);
int Index(char * name);
char *NextOffset();
#endif
