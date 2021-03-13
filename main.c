/*На примере стоек регистрации в аэропорту смоделировать работу простейшей системы балансировки нагрузки,
 * функционирующей по принципу случайного выбора. Стойки регистрации для обслуживания новых пассажиров должны
 * выбираться случайным образом.

Вводится информация о количестве стоек регистрации (целое число) и прибывающих пассажирах. Формат записи,
 содержащей информацию о пассажире: id/ta/ts, где id – идентификатор пассажира (строка), ta – время прибытия
 пассажира (натуральное число), ts – время обслуживания пассажира (натуральное число).*/





#include "vector.h"
#include <stdio.h>
#include "input.h"
#include <stdlib.h>


int main() {
    int number, time = 0;
    printf("Please, enter number of check-in counters:\n");
    input_int(&number);
    Massive mass = {0, NULL};
    mass.vect = calloc(number, sizeof (Vector));
    mass.number = number;
    for (int i = 0; i < number; i++){
        mass.vect[i] = queue_vector();
    }
    while (time < 10){//можно больше ставить
        int k = rand()%number;
        Vector vect = mass.vect[k];
        vect = queue_vector_input_p(vect, time);
        mass.vect[k] = vect;
        mass = queue_vector_output_p(mass, time);
        time++;
    }
    del(mass);
    return 0;
}
