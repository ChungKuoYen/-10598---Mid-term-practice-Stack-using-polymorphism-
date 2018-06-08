#include <iostream>
#include <algorithm>
#include "function.h"
//using namespace std;

     std::ostream &operator<<(std::ostream &out, Stack &tmp)
    {

        tmp.print(out);
        return out;
    }


        Array_stack::Array_stack()
        {
            std::fill_n(number,100,0);
            max_size=0;
        }

         Array_stack::~Array_stack()
        {

        }

        void Array_stack::push(const int &a)
        {
            number[max_size]=a;
            max_size++;
        }

        int Array_stack::pop()
        {
            if(max_size-1<0)
                return 0;

            number[max_size-1]=0;
            max_size--;
        }

        void Array_stack::print(std::ostream &output)
        {
            int i=max_size-1;
            if(max_size==0)
                return;
            output<<number[i];
            i--;

            while(i>=0)
            {
                output<<' '<<number[i];
                i--;

            }
        }





        List_stack::List_stack()
        {
            head=0;
            tail=0;
        }

         List_stack::~List_stack()
        {

        }

        void List_stack::push(const int &a)
        {
            ListNode *tmp;
            tmp = new ListNode(a);

            if(head==0&&tail==0)
            {
                head=tmp;
                tail=tmp;
            }
            else{
                tmp->nextPtr=0;
                tmp->prevPtr=tail;
                tail->nextPtr=tmp;
                tail=tmp;
            }
        }

        int List_stack::pop()
        {
            if(tail==0)
                return 0;
            ListNode *tmp;
            tmp=tail->prevPtr;
            delete tail;
            tail=tmp;
            if(tail!=0)
            tail->nextPtr=0;
            if(tail==0)
                head=0;
            return 1;
        }

        void List_stack::print(std::ostream &output)
        {
            ListNode *tmp;
            if(head==0&&tail==0)
                return;

            tmp=tail;
            output<<tmp->data;
            tmp=tmp->prevPtr;

            while(tmp!=0)
            {

                output<<' '<<tmp->data;
                tmp=tmp->prevPtr;

            }
        }
