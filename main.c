#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include "sorting.h"
#include <string.h>

int main(int argc, char *argv[])
{
    deque_elements_init();
    deque Deque = deque_init();

    if (argc > 2 && strcmp(argv[1], "--file") == 0)
    {
        deque_elements_input(&Deque, argv[2]);
        write_deque(Deque, deque_size, argv[2]);
        display(Deque, deque_size);
    }
    deque_element *Deque_for_Bubblesort = make_new_deque(deque_size);
    deque_element *Deque_for_Heapsort = make_new_deque(deque_size);

    bubbleSort(Deque_for_Bubblesort, deque_size);
    heapSort(Deque_for_Heapsort, deque_size);

    free(Deque_Elements);
    free(Deque_for_Bubblesort);
    free(Deque_for_Heapsort);
}
