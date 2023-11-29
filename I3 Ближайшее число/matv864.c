/*
hint:
я представил это всё у себя в голове в виде графика,
который растёт и убывает


решение сделано на стеке (first in -> first out) FIFO
на каждой итерации цикла я добавлял нынешний элемент в стэк, после того
как нашёл для него ближайшее

как я ищу ближайшее?
смотрю верхнее значение стэка -> не подходит -> удаляю
и делаю так до тех пор пока:
* либо не найдётся элемент больше этого (и записываю это в результат)
* либо не опустошится список (а это означает, что сейчас - это максимальный элемент)
    (и записываю сам элемент как результат)
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Item Item;
struct Item{
    Item* next;
    int num;
};






void add_item(Item *head_stack, int *stack_size, int n) {
    Item *new_item = malloc(sizeof(Item));;
    new_item->next = head_stack->next;
    new_item->num = n;
    head_stack->next = new_item;
    *stack_size = *stack_size + 1;
}

void pop_item(Item *head_stack, int *stack_size) {
    Item *first_item = head_stack->next;
    int num = first_item->num;
    head_stack->next = first_item->next;
    *stack_size = *stack_size - 1;
}

int top_item(Item *head_stack, int stack_size) {
    return ((Item*)(head_stack->next))->num;
}



int main() {
    FILE *inp = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    Item *head = malloc(sizeof(Item));
    int stack_size = 0;
    int n;
    int done;
    fscanf(inp, "%d", &n);
    int arr[n];
    int res[n];
    for (int i = 0; i < n; i++) {
        fscanf(inp, "%d", &arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        done = 0;
        while (stack_size) {
            if (top_item(head, stack_size) > arr[i]) {
                res[i] = top_item(head, stack_size);
                done = 1;
                break;
            }
            else{
                pop_item(head, &stack_size);
            }
        }
        if (done == 0){
            res[i] = arr[i];
        }
        add_item(head, &stack_size, arr[i]);
    }
    // add_item(head, &stack_size, 5);
    // add_item(head, &stack_size, 8);
    // pop_item(head, stack_size);
    
    
    for (int i = 0; i < n; i++){
        fprintf(out, "%d ", res[i]);
    }
    
    return 0;
}