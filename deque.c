#include "deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SPACE '\x20'

deque_element *Deque_Elements = NULL; // Avoiding variable redefinition
int deque_size = 0;

void push_back(int value, deque *Deque, int size)
{
    if (Deque->end == -1)
    { // If deque is initially empty
        Deque->start = 0;
        Deque->end = 0;
    }
    else if (Deque->end == size - 1)
    {
        Deque->end = 0; // wrap around
    }
    else
    {
        (Deque->end)++;
    }

    Deque_Elements[Deque->end].data = value;

    if (Deque->end == size - 1)
        Deque_Elements[Deque->end].Next = 0;
    else
        Deque_Elements[Deque->end].Next = Deque->end + 1;

    if (Deque->end == 0)
        Deque_Elements[Deque->end].Prev = size - 1;
    else
        Deque_Elements[Deque->end].Prev = Deque->end;
}

void push_front(int value, deque *Deque, int size)
{
    if (Deque->start == -1)
    { // If deque is initially empty
        Deque->start = 0;
        Deque->end = 0;
    }
    else if (Deque->start == 0)
    {
        Deque->start = size - 1;
    }
    else
    {
        Deque->start = Deque->start - 1;
    }

    Deque_Elements[Deque->start].data = value;

    if (Deque->start == size - 1)
        Deque_Elements[Deque->start].Next = 0;
    else
        Deque_Elements[Deque->start].Next = Deque->start + 1;

    if (Deque->start == 0)
        Deque_Elements[Deque->start].Prev = size - 1;
    else
        Deque_Elements[Deque->start].Prev = Deque->start - 1;
}

int empty(deque Deque)
{
    return (Deque.start == -1);
}

void display(deque Deque, int size)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (empty(Deque))
    {
        printf("��� ������.\n");
        return;
    }
    if (size > 103)
    {
        printf("������� ����� ����������.\n");
        return;
    }

    printf("�������� ����: ");
    int i = Deque.start;
    while (1)
    {
        printf("%d ", Deque_Elements[i].data);
        if (i == Deque.end)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

deque_element *make_new_deque(int size)
{
    deque_element *NewDeque = malloc(size * sizeof(deque_element));
    for (int i = 0; i < size; i++)
    {
        NewDeque[i] = Deque_Elements[i];
    }
    return NewDeque;
}

void deque_elements_init()
{
    Deque_Elements = malloc(sizeof(deque_element)); // <- Creating a dynamic array
}

deque deque_init()
{
    deque NewDeque;
    NewDeque.start = -1;
    NewDeque.end = -1;

    return NewDeque;
}

void deque_elements_resize(int deque_size)
{
    Deque_Elements = realloc(Deque_Elements, sizeof(deque_element) * deque_size);
}

void deque_elements_input(deque *Deque, char *filename)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char char_holder;
    char buffer[12]; // length of the number
    FILE *sequence = fopen(filename, "r");

    if (sequence == NULL)
    {
        perror("�� �������� ������� ����");
        exit(1);
    }
    while (1)
    {
        char_holder = fgetc(sequence);
        if (char_holder == EOF)
            break;
        if (char_holder == SPACE)
        {
            deque_size++;
        }
    }
    deque_size++;
    // Since we know the amount of numbers => enlarge Array of DeqElems;
    deque_elements_resize(deque_size);

    fseek(sequence, 0, SEEK_SET); // reset the pointer to the start of the file

    while (1)
    {
        char_holder = fgetc(sequence);
        if (char_holder == EOF)
        {
            strncat(buffer, &char_holder, 1);
            push_back(atoi(buffer), Deque, deque_size);
            memset(buffer, 0, sizeof(buffer));
            break;
        }
        if (char_holder == SPACE)
        {
            push_front(atoi(buffer), Deque, deque_size);

            // or

            // push_front(atoi(buffer), Deque, deque_size);

            memset(buffer, 0, sizeof(buffer)); // clearing buffer
        }
        else
        {
            strncat(buffer, &char_holder, 1); // adding new char to buffer;
        }
    }
    fclose(sequence);
}

void write_deque(deque Deque, int size, char *filename)
{
    if (empty(Deque))
    {
        printf("��� ������.\n");
        return;
    }

    FILE *fout;

    fout = fopen("result/��������_���.txt", "w");

    if (fout == NULL)
    {
        perror("�� �������� ������� ���� ������");
        exit(1);
    }

    int i = Deque.start;
    while (1)
    {
        fprintf(fout, "%d ", Deque_Elements[i].data);
        if (i == Deque.end)
            break;
        i = (i + 1) % size;
    }
    fclose(fout);
};