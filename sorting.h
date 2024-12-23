#include "deque.h"
#include "time.h"
void swap(deque_element *first_deque, deque_element *second_deque);
void bubbleSort(deque_element *Deque_for_bubblesort, int size);
void display_sorted(deque_element *Displayed_deque, int size, int type, float cpu_time_used);
void write_sorted(deque_element *Displayed_deque, int size);
void heapSort(deque_element *Deque_for_bubblesort, int size);
void heapify(deque_element *arr, int size, int i);