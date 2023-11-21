#include <iostream>
using namespace std;

/*
почему на C++?
потому что С не умеет нормально работать со строками и много раз
принимал мусор за скобку
объясните пожалуйста как нормально в С вводить строки неопределённой длины

пока мы идём по строке мы засовываем в очередь открытые скобки
если увидели закрывающую, то проверяем была ли такой же последняя скобка
и если это так, удаляем из стека последнюю скобку

иначе пишем, что последовательность неправильная
*/


// ( - 1
// { - 2
// [ - 3
// ) - 4
// } - 5
// ] - 6

int take_type_skoba(char skoba) {
    if (skoba == '(') {
        return 1;
    }
    if (skoba == '{') {
        return 2;
    }
    if (skoba == '[') {
        return 3;
    }
    if (skoba == ')') {
        return 4;
    }
    if (skoba == '}') {
        return 5;
    }
    if (skoba == ']') {
        return 6;
    }
    return 0;
}

int main() {
    int history[100000];
    int last_dot = -1;
    int now_i = 0;
    int record = 0;
    int type_skoba;
    char inp_skoba;
    string input_str;
    cin >> input_str;
    while (1) {
        scanf("%c", &inp_skoba);
        type_skoba = take_type_skoba(input_str[now_i]);
        now_i++;
        if (type_skoba == 0) {
            break;
        }
        // printf("%c ", inp_skoba);
        // printf("\n")
        if (type_skoba <= 3) {
            last_dot++;
            history[last_dot] = type_skoba;
        } else {
            if (last_dot < 0) {
                printf("-1");
                return 0;
            }
            if ((history[last_dot]+3) == type_skoba) {
                if ((last_dot+1) > record) {
                    record = (last_dot+1);
                }
                last_dot--;
            } else {
                printf("-1");
                return 0;
            }
        }
    }
    if (last_dot != -1) {
        printf("-1");
        return 0;
    }
    printf("%d", record);
    return 0;
}
