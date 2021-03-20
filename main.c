/*На примере стоек регистрации в аэропорту смоделировать работу простейшей системы балансировки нагрузки,
 * функционирующей по принципу случайного выбора. Стойки регистрации для обслуживания новых пассажиров должны
 * выбираться случайным образом.

Вводится информация о количестве стоек регистрации (целое число) и прибывающих пассажирах. Формат записи,
 содержащей информацию о пассажире: id/ta/ts, где id – идентификатор пассажира (строка), ta – время прибытия
 пассажира (натуральное число), ts – время обслуживания пассажира (натуральное число).*/




#ifdef USE_VECTOR
#include "vector.h"
#else
#include "list.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main() {
    int number, time = 0;
    printf("Please, enter number of check-in counters:\n");
    input_int(&number);
    Massive mass = {0, NULL};
    #ifdef USE_VECTOR
    printf("Vector");
    mass.vect = calloc(number, sizeof (Vector));
    #else
    mass.list = calloc(number, sizeof (List));
    #endif
    mass.number = number;
    for (int i = 0; i < number; i++){
    #ifdef USE_VECTOR
        mass.vect[i] = {0, 0, NULL, 0};
        mass.vect[i].value = calloc(4, sizeof(queue))
    #else
        mass.list[i] = (List*) malloc(sizeof(Item));
        mass.list[i]->time_process = 0;
        mass.list[i]->head = NULL;
        mass.list[i]->tail = NULL;
    #endif
    }
    while (time < 20){//можно больше ставить
        int k = rand()%number;
        #ifdef USE_VECTOR
        Vector vect = mass.vect[k];
        vect = queue_vector_input_p(vect, time);
        if (strcmp(vect.value[vect.tail-1].id, "stop") || strcmp(vect.value[4].id, "stop")){
            break;
        }
        mass.vect[k] = vect;
        mass = queue_vector_output_p(mass, time);
        #else
        List *list = mass.list[k];
        list = queue_list_input_p(list, time);
        if (strcmp(list->tail->ptr.id, "stop") == 0){
            break;
        }
        mass.list[k] = list;
        mass = queue_list_output_p(mass, time);
        #endif
        time++;
    }
    #ifdef USE_VECTOR
    del_vect(mass);
    #else
    del_list(mass);
    #endif
    return 0;
}
