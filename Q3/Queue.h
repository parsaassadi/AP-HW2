

#include <string>
#include <iostream>

class Queue
{

public:
    //constructor
    Queue(std::string);

    //showing Queue in order of reading
    void displayQueue();

    //display Queue cells(0->empty , 1->full)
    void status();

    //output = current read_pointer index in Queue
    int get_read();

    //output = current write_pointer index in Queue
    int get_write();

    //add element to Queue
    void enQueue(double num);

    //output = freespace in Queue
    int get_capacity();

    //delete element
    double deQueue();

    //check if Queue is full
    bool is_full();

    //destructor
    ~Queue();

private:
    //Queue array
    double* nums;

    //for each of Queue cells status
    bool* flags;

    //size of nums array
    int size;

    //read pointer
    int read_p;

    //write pointer
    int write_p;

    //freespace in Queue
    int capacity;

};