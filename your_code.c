#include "your_code.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


// Write the implementations of the functions that do the real work here

ASTNode* CreateNumNode(int num)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_NUM; 
        node->num = num;
        return node;
}


ASTNode* CreateIdentNode(char* name)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_IDENT; 
        node->name = name;
        return node;
}


// Take a statement node and a statement list node and connect them together
// to form a bigger statement list node (add the statement to the statement list).
// Return a pointer to the bigger list that resulted from this linking
ASTNode* CreateStatementListNode(ASTNode* st, ASTNode* stList)
{
        stList->next = st;
        return stList;

}

ASTNode* CreateAssignNode(ASTNode* lhs, ASTNode* expr)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_ASSIGN; 
        node->left = lhs;
        node->right = expr;
        return node;
}


ASTNode* CreateAddNode(ASTNode* expr, ASTNode* term)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_ARITH_OP; 
        node->op = ADD_OP;
        node->left = expr;
        node->right = term;
        return node;
}

ASTNode* CreateSubNode(ASTNode* expr, ASTNode* term)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_ARITH_OP; 
        node->op = SUB_OP;
        node->left = expr;
        node->right = term;
        return node;
}

ASTNode* CreateMultNode(ASTNode* term, ASTNode* factor)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_ARITH_OP; 
        node->op = MULT_OP;
        node->left = term;
        node->right = factor;
        return node;
}

ASTNode* CreateDivNode(ASTNode* term, ASTNode* factor)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_ARITH_OP; 
        node->op = DIV_OP;
        node->left = term;
        node->right = factor;
        return node;
}


ASTNode* CreateIfNode(ASTNode* cond, ASTNode* stList)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_IF; 
        node->cond = cond;
        node->left = stList;
        return node;
}

ASTNode* CreateIfElseNode(ASTNode* cond, ASTNode* stList, ASTNode* stList2)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_IF; 
        node->cond = cond;
        node->left = stList;
        node->right = stList2;
        return node;
}

ASTNode* CreateCompareListNode(ASTNode* compare, ASTNode* compareList)
{
        compareList->next = compare;
        return compareList;

}

ASTNode* CreateANDNode(ASTNode* compare, ASTNode* compareList)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_LOGIC_OP; 
        node->left = compare;
        node->right = compareList;
        return node;
}


ASTNode* CreateORNode(ASTNode* compare, ASTNode* compareList)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_LOGIC_OP; 
        node->left = compare;
        node->right = compareList;
        return node;
}

ASTNode* CreateEqualNode(ASTNode* expr, ASTNode* expr2)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_COMPARE; 
        node->left = expr;
        node->right = expr2;
        return node;
}

ASTNode* CreateNotEqualNode(ASTNode* expr, ASTNode* expr2)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_COMPARE; 
        node->left = expr;
        node->right = expr2;
        return node;
}

ASTNode* CreateGreaterNode(ASTNode* expr, ASTNode* expr2)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_COMPARE; 
        node->left = expr;
        node->right = expr2;
        return node;
}

ASTNode* CreateLessNode(ASTNode* expr, ASTNode* expr2)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_COMPARE; 
        node->left = expr;
        node->right = expr2;
        return node;
}


ASTNode* CreateGreaterEqualNode(ASTNode* expr, ASTNode* expr2)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_COMPARE; 
        node->left = expr;
        node->right = expr2;
        return node;
}

ASTNode* CreateLessEqualNode(ASTNode* expr, ASTNode* expr2)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_COMPARE; 
        node->left = expr;
        node->right = expr2;
        return node;
}

ASTNode* CreateWhileNode(ASTNode* cond, ASTNode* stList)
{
        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_WHILE; 
        node->cond = cond;
        node->right = stList;
        return node;
}
typedef struct hashTable
{
        char* ident;
        struct hashTable* next;
}
hashTable;
hashTable* symbolTable[50] = {NULL};
int hash(const char* ident)
{
        return tolower(ident[0] - 'a');
}






void insert (int key, const char* name)
{
        hashTable* newHash = malloc(sizeof(hashTable));
        if (newHash == NULL)
        {
                return;
        }
        strcpy(newHash->ident, name);
        newHash->next = NULL;

        if (symbolTable[key] == NULL)
        {
                symbolTable[key] = newHash;
        }
        else 
        {
                hashTable* predHash = symbolTable[key];
                while (1)
                {
                        if (predHash->next == NULL)
                        {
                                predHash->next = newHash;
                                break;
                        }
                        predHash = predHash->next;
                }
        }
        
}
void AddDeclaration(char* name)
{
        int value = hash(name);
        insert(value, name);

}


// Commented out in this assignment 
/*void GenerateILOC(ASTNode* node);
{

}*/

