/*
тут всё просто 
нет никого в очреди -> время летит до самого ближайшего по времени челика 
есть хоть кто-то в очереди -> забираем человека и запускаем всех тех,
кто заходит, пока чел у врача не вышел

очередь с удалением долго - ловите 2 указателя (индекса) действительного куска 
массива данных
*/


#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a > b)?a:b)


int main(){
    int n, t;
    int now_time = 0;
    int left_point = 0, right_point = 0;
    int record = 0;
    scanf("%d %d", &n, &t);
    int my_queue[n];
    for (int ii = 0;ii < n;ii++){
        scanf("%d", &my_queue[ii]);
    }
    while(right_point < n){

        if (right_point - left_point == 0){
            now_time = my_queue[right_point];
        }

        if (my_queue[left_point] <= now_time){
            now_time += t;
            left_point++;
            while (my_queue[right_point] < now_time && right_point < n){
                right_point++;
            }
        }
        // printf("%d %d %d\n", left_point, right_point, now_time);
        // for (int i = left_point;i < right_point;i++){
        //     printf("%d ", my_queue[i]);
        // }
        // printf("\n---\n");
        record = max(record, (right_point - left_point));
    }



    printf("%d", record);


    return 0;
}
