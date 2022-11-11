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
        struct Symbol *names = (struct Symbol*) malloc(sizeof(struct Symbol));
	names = Search(name);
	
	if(names == NULL) {
		 printf("Ident not declared");
		exit(1);
	}

        ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
        node->type = ASTNODE_IDENT; 
        node->name = name;
        if(names != NULL){
                node->name = names->name;
        }
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

ASTNode* CreateDeclarationListNode(ASTNode* dc, ASTNode* dcList) {
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = ASTNODE_DECLARATION_LIST;
	node->left = dc;
	node->right = dcList;
	return node;
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



// Commented out in this assignment 
/*void GenerateILOC(ASTNode* node);
{

}*/
int offset = 0;



void AddDeclaration(char* name) {
	struct Symbol *symbols = (struct Symbol*) malloc(sizeof(struct Symbol));
	symbols = Search(name);
	if(symbols != NULL) {
		char error[(strlen("Multiple declarations of ") + strlen(name) + 2)];
		strcpy(error, "Multiple declarations of ");
	} else {
		Insert(name);
	}
}

int Index(char *name) {
	int currPlace = 0;
	int key = 0;
	while(currPlace < strlen(name)) {
		key += (name[currPlace] - '0');
                currPlace++;
	}
	int index = key % 100;
	return index;
}

void Insert(char *name){
	struct Symbol *ident = (struct Symbol*) malloc(sizeof(struct Symbol));
	ident->name = name;
	ident->offset = NextOffset();
	int index = Index(name);
	while(table[index] != NULL) {
		++index;
		index %= 100;
	}
	table[index] = ident;
}



struct Symbol *Search(char* name) {
	int index;
        int i;
	for(index = Index(name); table[index] != NULL; index++) {
		if(strcmp(table[index]->name, name) == 0) 
                {
                        return table[index];
                        printf("found\n");

                }
		index %= 100;
	}
	return NULL;
}

char *SearchOffset(char* name) {
	int index;
	for(index = Index(name); table[index] != NULL; index++) {
		if(0 == strcmp(table[index]->name, name)) 
                        {return table[index]->offset;}
		index %= 100;
	}
	return NULL;
}

char *NextOffset(){
	char *nextOffset = malloc(sizeof(char) * 5);
	sprintf(nextOffset, "%d", offset);
	offset += 4;
	return nextOffset;
}