#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *pos;
char token[20];

void next_token() {
    while(isspace(*pos)) pos++;
    int i = 0;
    if(isalnum(*pos)) {
        while(isalnum(*pos)) token[i++] = *pos++;
    } else {
        token[i++] = *pos++;
    }
    token[i] = '\0';
}

void match(char *s) {
    if(strcmp(token, s) == 0) next_token();
    else printf("Syntax Error: expected %s, found %s\n", s, token);
}

void parse_stmt();
void parse_cond() {
    // simplified: id RELOP id
    next_token(); // id
    next_token(); // RELOP
    next_token(); // id
}

void parse_stmt() {
    if(strcmp(token, "if") == 0) {
        match("if"); match("("); parse_cond(); match(")");
        match("{"); parse_stmt(); match("}");
    } else if(strcmp(token, "while") == 0) {
        match("while"); match("("); parse_cond(); match(")");
        match("{"); parse_stmt(); match("}");
    } else {
        match(token); match("="); match(token); match(";");
    }
}

int main() {
    char input[200];
    printf("Enter control statement (e.g. if(a<b){x=y;}): ");
    scanf("%s", input);
    pos = input;
    next_token();
    parse_stmt();
    printf("Control statement parsed successfully.\n");
    return 0;
}
