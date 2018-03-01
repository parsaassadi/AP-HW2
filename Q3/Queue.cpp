//
// Created by Parsa Assadi on 2/26/18.
//

#include "Queue.h"
#include <fstream>
#include <cmath>


Queue::Queue(std::string filename)
{
    //error handling
    try
    {
        std::ifstream iff{filename};
        if (!iff.fail())
        {
            char temp{};
            int end{};
            read_p = 0;
            iff >> this->size;

            //case of Queue with size zero
            if(size == 0)
            {

                //My Rule: if size is zero reader and writer pointers assign to -2
                read_p = -2;
                write_p = -2;
                capacity = 0;
            }
            else
            {
                nums = new double[this->size];
                flags = new bool[size];
                for (int i{}; i < (this->size); i++)
                {
                    if (!iff.eof())
                    {
                        flags[i] = true;
                        iff >> this->nums[i];

                        //checks for end of file
                        if (!iff.eof())
                        {
                            iff >> temp;
                        }
                        else
                        {
                            end = i;
                            break;
                        }
                    }

                }

                //the value of Queue freespace is not important(I set it to PI)
                for (int j{end + 1}; j < this->size; j++)
                {
                    this->flags[j] = false;
                    this->nums[j] = std::acos(-1);
                }
                capacity = size - end - 1;
                if (!is_full())
                {
                    this->write_p = end + 1;
                }
                else
                {
                    this->write_p = -1;
                }

                iff.close();
            }
        }
        else
        {
            throw 1;
        }
    }
    catch (int a)
    {
        std::cerr << "Runtime error: File Did not opened succesfully "
                  << "\n";
    }

}


void Queue::displayQueue()
{

    //size zero
    if(read_p == -2)
    {
        std::cout << "Command displayQueue Denied: Nothing to display, Queue size is Zero!"
                  << "\n";
    }

    //empty Queue
    else if(read_p == -1)
    {
        std::cout << "Command displayQueue Denied: Nothing to display, Queue is Empty"
                  << "\n";
    }

    //normal Queue
    else
    {

        //elements at right handside of reader pointer by order
        for (int i = read_p; i < size; i++)
        {
            if (flags[i] == 1)
            {
                std::cout << nums[i] << " ,";
            }

        }

        //elements at left hanside of reader pointer by order
        for (int j = 0; j < read_p; j++)
        {
            if (flags[j] == 1)
            {
                std::cout << nums[j] << " ,";
            }

        }
        std::cout << "\n";
    }



}

void Queue::status()
{
    if(size == 0)
    {
        std::cout << "Status Denied: Queue size is Zero!" << "\n";
    }
    else
    {
        for (int i{}; i < (this->size); i++)
        {
            std::cout << this->flags[i] << ", ";
        }
        std::cout << "\n";
    }
}

int Queue::get_read()
{
    return this->read_p;
}

int Queue::get_write()
{
    return this->write_p;
}

void Queue::enQueue(double num)
{

    //size zero case
    if(read_p == -2)
    {
        std::cout << "Command enQueue Denied: You can not write into a Queue with zero size!"
                  << "\n";
    }
    else
    {
        //Empty Queue case
        if(read_p == -1)
        {
            read_p = write_p;
        }


        if (write_p != -1)
        {
            nums[write_p] = num;
            flags[write_p] = true;

            //if there is not freespace right hand side of writer pointer
            if ((write_p + 1) > (size - 1))
            {
                write_p = 0;
            }

            //if there is freespace right hand side of writer pointer
            else
            {
                write_p++;
            }
            (capacity) -= 1;

            //My rule: if Queue is full writer pointer assigned to -1
            if (capacity == 0)
            {
                write_p = -1;
            }
        }

        //error handling
        else
        {
            std::cout << "Command enQueue Denied: Element " << num
                      << " can not be added because Queue is full" << "\n";
        }
    }
}

int Queue::get_capacity()
{
    return this->capacity;
}

double Queue::deQueue()
{

    //zero size case
    if(write_p == -2)
    {
        std::cout<<"Command deQueue denied: You can not read from a Queue with zero size!"
                 <<"\n";
        return std::acos(-1);
    }
    else
    {
        //empty Queue case
        if (write_p == -1)
        {
            write_p = read_p;
        }
        double temp{};
        if (read_p != -1)
        {
            temp = nums[read_p];
            nums[read_p] = std::acos(-1);
            flags[read_p] = false;
            //std::cout<<"flag changed reader"<<"\n";

            //if there is not freespace right hand side of writer pointer
            if ((read_p + 1) > (size - 1))
            {
                read_p = 0;
            }
                //if there is freespace right hand side of writer pointer
            else
            {
                read_p++;
            }

            (capacity) += 1;

            //My rule: if Queue is Empty reader pointer assigned to -1
            if (capacity == size)
            {
                read_p = -1;
            }
        }
        else
        {
            std::cout << "Command deQueue Denied: you can not read from an empty Queue"
                      << "\n";
        }
        return temp;
    }
}

bool Queue::is_full()
{
    if(capacity == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Queue::~Queue()
{
    delete [] nums;
    delete [] flags;
    nums = nullptr;
    flags = nullptr;
}