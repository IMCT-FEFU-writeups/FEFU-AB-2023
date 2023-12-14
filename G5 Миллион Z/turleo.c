/*
 * Эта задача заходит перебором: мы просто заводим массив на миллион символов и записываем изменения в этот массив.
 * А потом считаем количество символов через список 🙃
 */
#include <stdio.h>
#include <stdlib.h>

struct letter_list {
    char letter;
    struct letter_list* next;
};

int main() {
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w+");
    int n;
    fscanf(fin, "%d\n", &n);
    char letters[1000001];
    for (int i = 0; i < 1000001; ++i) {
        letters[i] = 'Z';
    }

    for (int i = 0; i < n; ++i) {
        char letter;
        int start, end;
        fscanf(fin, "%c %d %d\n", &letter, &start, &end);
        for (int j = start; j <= end; ++j) {
            letters[j] = letter;
        }
    }
    struct letter_list* head = malloc(sizeof(struct letter_list));
    head->letter = letters[1];
    head->next = 0;
    for (int i = 2; i < 1000001; ++i) {
        if (letters[i] != letters[i - 1]) {
            struct letter_list* cur = head;
            while (cur->next) {
                if (cur->letter == letters[i]) {
                    goto next;
                }
                cur = cur->next;
            }
            cur->next = malloc(sizeof(struct letter_list));
            cur = cur->next;
            cur->letter = letters[i];
            cur->next = 0;
next:
            asm("nop");
        }
    }
    int counter = 1;
    while (head->next != 0) {
        counter++;
        head = head->next;
    }
    fprintf(fout, "%d", counter);
}
