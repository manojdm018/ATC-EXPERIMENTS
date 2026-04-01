#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char op[5];
    char left[10];
    char right[10];
    char name[10];
};

int main() {
    int n, i, j;
    struct node dag[10];
    char res[10][10], op[10][10], l[10][10], r[10][10];

    printf("Enter number of expressions: ");
    scanf("%d", &n);

    printf("Enter expressions (e.g., t1 = a + b):\n");
    for (i = 0; i < n; i++) {
        scanf("%s = %s %s %s", res[i], l[i], op[i], r[i]);
    }

    printf("\nOptimized Code (using DAG approach):\n");
    for (i = 0; i < n; i++) {
        int redundant = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(op[i], op[j]) == 0 && strcmp(l[i], l[j]) == 0 && strcmp(r[i], r[j]) == 0) {
                printf("%s = %s\n", res[i], res[j]);
                redundant = 1;
                break;
            }
        }
        if (!redundant) {
            printf("%s = %s %s %s\n", res[i], l[i], op[i], r[i]);
        }
    }

    return 0;
}
