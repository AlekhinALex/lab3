#include "sorting.h"
#include "deque.h"
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

void swap(deque_element *first_deque, deque_element *second_deque)
{
    int temp = first_deque->data;
    first_deque->data = second_deque->data;
    second_deque->data = temp;
}

void bubbleSort(deque_element *Deque_for_bubblesort, int size)
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (Deque_for_bubblesort[j].data > Deque_for_bubblesort[j + 1].data)
            {
                swap(&Deque_for_bubblesort[j], &Deque_for_bubblesort[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
    end = clock();
    cpu_time_used = ((float)(end - start)) / CLOCKS_PER_SEC;
    display_sorted(Deque_for_bubblesort, size, 1, cpu_time_used);
    write_sorted(Deque_for_bubblesort, size);
}

void heapSort(deque_element *Deque_for_heapsort, int size)
{
    int i, temp;
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    // making max heap
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(Deque_for_heapsort, size, i);
    }

    // max heaping without MAX elemnt
    for (i = size - 1; i > 0; i--)
    {
        temp = Deque_for_heapsort[0].data;
        Deque_for_heapsort[0].data = Deque_for_heapsort[i].data;
        Deque_for_heapsort[i].data = temp;
        heapify(Deque_for_heapsort, i, 0);
    }
    end = clock();
    cpu_time_used = ((float)(end - start)) / CLOCKS_PER_SEC;
    display_sorted(Deque_for_heapsort, size, 0, cpu_time_used);
}

void heapify(deque_element *Deque_for_heapSort, int size, int i)
{
    int temp, maximum, left_index, right_index;

    maximum = i;

    right_index = 2 * i + 2;

    left_index = 2 * i + 1;

    if (left_index < size && Deque_for_heapSort[left_index].data > Deque_for_heapSort[maximum].data)
        maximum = left_index;

    if (right_index < size && Deque_for_heapSort[right_index].data > Deque_for_heapSort[maximum].data)
        maximum = right_index;

    if (maximum != i)
    {
        temp = Deque_for_heapSort[i].data;
        Deque_for_heapSort[i].data = Deque_for_heapSort[maximum].data;
        Deque_for_heapSort[maximum].data = temp;
        heapify(Deque_for_heapSort, size, maximum);
    }
}

void display_sorted(deque_element *Displayed_deque, int size, int type, float time)
{
    setlocale(LC_ALL, "Russian");

    if (type)
        printf("BubbleSorted ");
    else
        printf("HeapSorted ");
    printf("deque: ");
    if (size > 103)
        printf(" ˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜; ");
    else
        for (int i = 0; i < size; ++i)
        {
            printf("%d ", Displayed_deque[i].data);
        }
    printf("˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ - %f ˜˜˜˜˜˜\n", time);
}

void write_sorted(deque_element *Displayed_deque, int size)
{
    FILE *fout;
    fout = fopen("result/˜˜˜˜˜˜˜˜_˜˜˜_˜˜˜˜˜˜˜˜˜˜˜˜˜˜˜_bubblesort.txt", "w");

    if (fout == NULL)
    {
        perror("˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜");
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(fout, "%d ", Displayed_deque[i].data);
    }

    fclose(fout);
}