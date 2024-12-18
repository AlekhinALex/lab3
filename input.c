#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "deque.h"
#include <string.h>
#define SPACE '\x20'
void input()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char char_holder;
    char buffer[8];
    FILE *sequence = fopen("text files/test_squence.txt", "r");

    if (sequence == NULL)
    {
        perror("Не возможно открыть файл");
        exit(1);
    }

    while (1)
    {
        char_holder = fgetc(sequence);
        if (char_holder == EOF)
            break;
        if (char_holder == SPACE)
        {
            printf("%s\n", buffer);
            // Here has to be push_back();
            // push_back(ToInt(buffer), Deque.end); <- somthing's wrong
            memset(buffer, 0, sizeof(buffer)); // clearing buffer
        }
        else
        {
            strncat(buffer, &char_holder, 1); // adding new char to buffer;
        }
    }
    fclose(sequence);
}