#include "sorting.h"
#include "deque.h"
#include <time.h>
#include <Windows.h>
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
    // performing heapify on the non leaf nodes so n/2 - 1
    // to 0 are the non leaf nodes
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(Deque_for_heapsort, size, i);
    }

    // the current array is changed to max heap

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

void heapify(deque_element *arr, int size, int i)
{
    int temp, maximum, left_index, right_index;

    // currently assuming i postion to
    // be holding the largest value
    maximum = i;

    // right child index
    right_index = 2 * i + 2;

    // left child index
    left_index = 2 * i + 1;

    // if left index value is grater than the current index
    // value
    if (left_index < size && arr[left_index].data > arr[maximum].data)
        maximum = left_index;

    // if right index value is grater than the current index
    // value
    if (right_index < size && arr[right_index].data > arr[maximum].data)
        maximum = right_index;

    // checking if we needed swaping the elements or not
    if (maximum != i)
    {
        temp = arr[i].data;
        arr[i].data = arr[maximum].data;
        arr[maximum].data = temp;
        heapify(arr, size, maximum);
    }
}

void display_sorted(deque_element *Displayed_deque, int size, int type, float time)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (type)
        printf("BubbleSorted ");
    else
        printf("HeapSorted ");
    printf("deque: ");
    if (size > 103)
        printf(" Слишком много переменных; ");
    else
        for (int i = 0; i < size; ++i)
        {
            printf("%d ", Displayed_deque[i].data);
        }
    printf("Время выполнения - %f секунд\n", time);
}

void write_sorted(deque_element *Displayed_deque, int size)
{
    FILE *fout;
    fout = fopen("result/исходный_ряд_отсортированный_bubblesort.txt", "w");

    if (fout == NULL)
    {
        perror("Невозможно открыть файл для записи");
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(fout, "%d ", Displayed_deque[i].data);
    }

    fclose(fout);
}