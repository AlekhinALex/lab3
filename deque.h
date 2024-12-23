#ifndef DEQUE_H_
#define DEQUE_H_

typedef struct deque_element
{
    int data;
    int Next;
    int Prev;
} deque_element;

typedef struct deque
{
    int start;
    int end;
} deque;

extern deque_element *Deque_Elements; // Array of elements; Making array external
extern int deque_size;

void push_front(int value, deque *Deque, int size);
void push_back(int value, deque *Deque, int size);
int empty(deque Deque);
void display(deque Deque, int size);
deque_element *make_new_deque(int size);
void deque_elements_init();
deque deque_init();
void deque_elements_resize(int deque_size);
void deque_elements_input(deque *Deque, char *filename);
void write_deque(deque Deque, int size, char *filename);
#endif
