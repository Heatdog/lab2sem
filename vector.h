//
// Created by yura on 08.03.2021.
//

#ifndef LAB2_SEM2_VECTOR_H
#define LAB2_SEM2_VECTOR_H

#define VECT_SIZE 4

typedef struct {
    char id[10];
    int ta;
    int ts;
}queue;

typedef struct {
    int head;
    int tail;
    queue *value;
    int time_process;
}Vector;

typedef struct{
    int number;
    Vector *vect;
}Massive;


Vector queue_vector();
Vector queue_vector_input(Vector, int);
Massive queue_vector_output_p(Massive , int);
Vector queue_vector_input_p(Vector, int);
Vector queue_vector_output(Vector, int);
Vector queue_print_output(Vector, int, int);
void del(Massive);



#endif //LAB2_SEM2_VECTOR_H
