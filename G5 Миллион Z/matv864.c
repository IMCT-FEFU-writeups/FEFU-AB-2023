#include <stdio.h>
#include <stdlib.h>


/*
чем дальше в гущу тем хуже
это много времени заняло, но оно готово 
---
я создаю промежуток (1, 1000000)Z
затем я беру новый промежуток из входных данных и
    перебираю промежутки 
    и накладываю промежуток из входных данных (A) на каждый перебираемый промежуток (B)
    в основном 4 ситуации 
    1) промежуток A покрывает полностью промежуток B
    2) промежуток A находится внутри B
    3,4) промежуток A покрывает левую или правую промежутка B

    и всё это реализовано под связанным списком
*/



const int MAX_END = 1000000;

struct item {
    struct item *next;
    int let;
    int l;
    int r;
};

void print_queue(struct item *mainNode) {
    int c = 0;
    struct item *nowNode = mainNode;
    while (1) {
        c++;
        printf("%d %d %d %d\n", c, nowNode->l, nowNode->r, nowNode->let);
        if (c > 50) {
            break;
        }

        if (nowNode->r == MAX_END) {
            break;
        }
        nowNode = nowNode->next;
    }
    printf("-----\n\n");
}

void put_interval(struct item *mainNode, struct item *addNode) {

    struct item *nowNode = mainNode;
    while (1) {
        // small interval above big interval
        if (addNode->l > nowNode->l && addNode->r < nowNode->r) {
            struct item *newNode = malloc(sizeof(struct item));
            struct item *insteadAddNode = malloc(sizeof(struct item));
            int old_r = nowNode->r, old_let = nowNode->let;
            struct item *oldPoint = nowNode->next;

            nowNode->r = addNode->l - 1;
            nowNode->next = insteadAddNode;

            insteadAddNode->let = addNode->let;
            insteadAddNode->l = addNode->l;
            insteadAddNode->r = addNode->r;
            insteadAddNode->next = newNode;

            newNode->l = addNode->r + 1;
            newNode->r = old_r;
            newNode->let = old_let;
            newNode->next = oldPoint;

            // printf("1\n");
            break;
        }

        // big interval above small interval
        if (addNode->l <= nowNode->l && addNode->r >= nowNode->r) {
            nowNode->let = addNode->let;

            // printf("2\n");
        }

        // interval above left part interval
        if (addNode->l <= nowNode->l && (addNode->r < nowNode->r && addNode->r >= nowNode->l)) {
            struct item *node2 = malloc(sizeof(struct item));
            struct item *point = nowNode->next;
            int old_r = nowNode->r, old_let = nowNode->let;

            nowNode->l = nowNode->l;
            nowNode->r = addNode->r;
            nowNode->let = addNode->let;
            nowNode->next = node2;

            node2->l = addNode->r + 1;
            node2->r = old_r;
            node2->let = old_let;
            node2->next = point;

            // printf("3\n");
            break;
        }

        // interval above right part interval
        if ((addNode->l > nowNode->l && addNode->l <= nowNode->r) && addNode->r >= nowNode->r) {
            struct item *newNode = malloc(sizeof(struct item));
            int old_r = nowNode->r;

            nowNode->r = addNode->l - 1;

            newNode->l = addNode->l;
            newNode->r = old_r;
            newNode->let = addNode->let;
            newNode->next = nowNode->next;

            nowNode->next = newNode;

            // printf("4\n");
        }

        if (nowNode->r == MAX_END) {
            break;
        }
        nowNode = nowNode->next;
    }
}

int main() {
    FILE *inp;
    FILE *out;
    inp = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    struct item tempNode;
    struct item *mainNode = malloc(sizeof(struct item));
    mainNode->let = 25;
    mainNode->l = 1;
    mainNode->r = MAX_END;
    char trash[100], char_let;
    int n, let, l, r;
    fscanf(inp, "%d", &n);

    while (n--) {
        fgets(trash, 100, inp);
        fscanf(inp, "%c %d %d", &char_let, &l, &r);
        let = char_let - 65;
        tempNode.let = let;
        tempNode.l = l;
        tempNode.r = r;
        put_interval(mainNode, &tempNode);
    }

    int result_data[30], res = 0;
    for (int i = 0; i < 30; i++) {
        result_data[i] = 0;
    }
    struct item *nowNode = mainNode;
    while (1) {
        result_data[nowNode->let] = 1;
        if (nowNode->r == MAX_END) {
            break;
        }
        nowNode = nowNode->next;
    }

    for (int i = 0; i < 30; i++) {
        res += result_data[i];
    }

    // // print_queue(mainNode);
    fprintf(out, "%d", res);
    // printf("-");

    return 0;
}