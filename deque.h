typedef struct deque_element
{
    int data;
    int **pNext;
    int **pPrev;
} deque_element;

typedef struct deque
{
    deque_element *start;
    deque_element *end;
} deque;

int push_front(int value, deque *start); // Inserts the element at the beginning.
int push_back(int value, deque *end);    // Adds element at the end.
int pop_front(deque *start);             // Removes the first element from the deque.
int pop_back(deque *end);                // Removes the last element from the deque.
int front(deque *start);                 // Gets the front element from the deque.
int back(deque *end);                    // Gets the last element from the deque.
int empty(deque);                        // Checks whether the deque is empty or not.
int size(deque);                         // Determines the number of elements in the deque.
int clear();                             // Remove all the elements from the deque. It leaves the deque with a size of 0.
int erase();                             // Remove one element from the deque. It takes an iterator specifying the position of the first element to be removed,
                                         // and an optional second iterator specifying the position of the last element to be removed.
int swap();                              // Swap the contents of one deque with another deque.
int sort();                              // Sort the elements in the deque in ascending order. It uses the less-than operator to compare the elements.