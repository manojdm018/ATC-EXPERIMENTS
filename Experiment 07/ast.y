%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[20];
    struct node *left, *right;
};

struct node* make_node(char *name, struct node *left, struct node *right);
void print_ast(struct node *t, int indent);
void yyerror(char *s);
int yylex();
%}

%union {
    struct node *n;
    char s[20];
}

%token <s> ID NUM
%type <n> E

%left '+' '-'
%left '*' '/'

%%
S: E { 
    printf("\nAbstract Syntax Tree Structure:\n");
    print_ast($1, 0); 
    exit(0); 
   }
 ;

E: E '+' E { $$ = make_node("+", $1, $3); }
 | E '-' E { $$ = make_node("-", $1, $3); }
 | E '*' E { $$ = make_node("*", $1, $3); }
 | E '/' E { $$ = make_node("/", $1, $3); }
 | NUM      { $$ = make_node($1, NULL, NULL); }
 | ID       { $$ = make_node($1, NULL, NULL); }
 ;

%%

struct node* make_node(char *name, struct node *left, struct node *right) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    newnode->left = left;
    newnode->right = right;
    return newnode;
}

void print_ast(struct node *t, int indent) {
    if(t == NULL) return;
    for(int i=0; i<indent; i++) printf("  ");
    printf("%s\n", t->name);
    print_ast(t->left, indent + 2);
    print_ast(t->right, indent + 2);
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter expression to build AST:\n");
    yyparse();
    return 0;
}
