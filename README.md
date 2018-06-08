# -10598---Mid-term-practice-Stack-using-polymorphism-

Description

A stack is an abstract data type that serves as a collection of elements, where a node can be added to a stack and removed from a stack only at its top. Two principal operations can be used to manipulate a stack: push, which adds an element at the top, and pop, which removes the element at the top of the collection.

 

Let’s see how the stack data structure can be realized in C++.We have two different approaches to implement stack: array and linked list. Thus, we define three classes as follows:

 

class Stack{

    friend std::ostream &operator<<(std::ostream &, Stack &);

    public:

        virtual ~Stack() {};

        virtual void push(const int &) = 0;

        virtual int pop() = 0;

        virtual void print(std::ostream &output)=0;

};

class Array_stack : public Stack{

    public:

        Array_stack();

        virtual ~Array_stack();

        void push(const int &);

        int pop();

        void print(std::ostream &output);

    private:

        int number[100];

        int max_size;

};

 

class List_stack : public Stack{

    public:

        List_stack();

        virtual ~List_stack();

        void push(const int &);

        int pop();

        void print(std::ostream &output);

    private:

        ListNode *head;

        ListNode *tail;

};

 

where

    Class Stack serves as the abstract base class for realizing polymorphism
    Array_stack and List_stack provide the two different approaches to implement the stack data structure

 

Besides, we also overload the stream insertion operator (<<) to print the content of a stack object no matter if the stack object is an Array_stack object or a List_stack object (note that this is polymorphism).

 

REQUIREMENTS:

    Implement the push(), pop() and print() member functions of both the Array_stack and List_stack classes.
    Implement overloaded stream insertion operator (<<), which will call the correct member function print() polymorphically.

 

 

Note:

1.This problem involves three files.

    function.h: Class definitions.
    function.cpp: Member-function definitions.
    main.cpp: A driver program to test your class implementation.

You will be provided with main.cpp and function.h, and asked to implement function.cpp.

 

<code>function.h</code>

#ifndef FUNCTION_H

#define FUNCTION_H

#include <iostream>

class ListNode

{

    friend class List_stack; //make List_stack a friend

 

public:

    ListNode( const int &info ) //constructor

    : data( info ), nextPtr( NULL ), prevPtr( NULL )

    {

    } //end ListNode constructor

 

private:

    int data; //data

    ListNode *nextPtr; // next node in list

    ListNode *prevPtr;

}; //end class ListNode

 

class Stack{

    friend std::ostream &operator<<(std::ostream &, Stack &);

    public:

        virtual ~Stack() {};

        virtual void push(const int &) = 0;

        virtual int pop() = 0;

        virtual void print(std::ostream &output)=0;

};

class Array_stack : public Stack{

    public:

        Array_stack();

        virtual ~Array_stack();

        void push(const int &);

        int pop();

        void print(std::ostream &output);

    private:

        int number[100];

        int max_size;

};

class List_stack : public Stack{

    public:

        List_stack();

        virtual ~List_stack();

        void push(const int &);

        int pop();

        void print(std::ostream &output);

    private:

        ListNode *head;

        ListNode *tail;

};

#endif // FUNCTION_H

 

<code>main.cpp</code>

#include<iostream>

#include<string.h>

#include "function.h"

using namespace std;

int main(){

    Array_stack A_stack;

    List_stack L_stack;

    char command[10];

    int n;

    while(cin>>command){

 

        if(strcmp(command,"pop")==0){

            n=A_stack.pop();

            n=L_stack.pop();

        }else if(strcmp(command,"push")==0){

            cin >> n;

            A_stack.push(n);

            L_stack.push(n);

        }else if(strcmp(command, "print") == 0){

            cout << A_stack << endl;

            cout << L_stack << endl;

        }

    }

    return 0;

}

 

2.For OJ submission:

       Step 1. Submit only your function.cpp into the submission block.

       Step 2. Check the results and debug your program if necessary.
Input

There are three kinds of commands:

    “push integerA” represents adding an element with int value A at the top of the stack.
    “pop “ represents removing the element at the top of the stack.
    “print” represents showing the current content of the stack.

Each command is followed by a new line character.

Input terminated by EOF.
Output

The output should consist of the current state of the stack.

When the stack is empty, you don’t need to print anything except a new line character.
