# Generic Linked List

**To run the simple test placed in main.c just type on the terminal in the same directory:**
+ $ make
+ $ ./app

To use this library, just add the LinkedList.o and LinkedList.h to the directory of your project. Then, include the header file and link the .o file with main module, something like that: 
+ gcc -o my_app_executable main.c LinkedList.o

## Creating a list of integers
Node* listInt = newList(sizeof(int));

## Creating a list of floats
Node* listFloat = newList(sizeof(float));

## Creatint a list of user-defined types
Node* myList = newList(sizeof(MyNewType));

# Adding elements to the head
listInts = pushFront(listInts, 2);

# Adding elements to the tail
listInts = append(listInts, 505);

# OBS.: YOU MUST PROVIDE A POINTER FUNCTION WITH THE IMPLEMENTATION OF PRINTING AND SEARCHING PROCESS.

## For more information, read the **code contract** [here](https://github.com/ABuarque/generic-linked-list/blob/master/LinkedList.h)
