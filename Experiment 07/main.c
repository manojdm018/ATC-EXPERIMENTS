#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    char name[20];
    struct node *left, *right;
};

char *pos;

struct node* make_node(char *name, struct node *left, struct node *right) {
    struct node *n = malloc(sizeof(struct node));
    strcpy(n->name, name);
    n->left = left; n->right = right;
    return n;
}

struct node* parse_E();
struct node* parse_T();
struct node* parse_F();

struct node* parse_E() {
    struct node *res = parse_T();
    while(*pos == '+' || *pos == '-') {
        char op[2] = {*pos++, '\0'};
        res = make_node(op, res, parse_T());
    }
    return res;
}

struct node* parse_T() {
    struct node *res = parse_F();
    while(*pos == '*' || *pos == '/') {
        char op[2] = {*pos++, '\0'};
        res = make_node(op, res, parse_F());
    }
    return res;
}

struct node* parse_F() {
    if(isdigit(*pos)) {
        char buf[10] = {0}; int i=0;
        while(isdigit(*pos)) buf[i++] = *pos++;
        return make_node(buf, NULL, NULL);
    } else if(isalpha(*pos)) {
        char buf[10] = {0}; int i=0;
        while(isalnum(*pos)) buf[i++] = *pos++;
        return make_node(buf, NULL, NULL);
    }
    return NULL;
}

void print_ast(struct node *t, int indent) {
    if(!t) return;
    for(int i=0; i<indent; i++) printf("  ");
    printf("%s\n", t->name);
    print_ast(t->left, indent + 2);
    print_ast(t->right, indent + 2);
}

int main() {
    char input[100];
    printf("Enter expression for AST: ");
    scanf("%s", input);
    pos = input;
    struct node *root = parse_E();
    printf("\nAST Structure:\n");
    print_ast(root, 0);
    return 0;
}
