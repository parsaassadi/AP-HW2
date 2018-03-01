
#include <iostream>
#include <string>
#include <vector>

//displaying a vector
void show(std::vector<double> n);

//output is the index of minimum element within the index range of [a,b]
int min_index(std::vector<double> n, int a, int b);

//replace two elements of the vector with index a and b
//input is reference for efficency
void replace(std::vector<double>& n, int a, int b);

//apply selection sort algorithm
std::vector<double> sort(std::vector<double> nums);

//main
int main()
{

    //prompting message
    std::cout << "Enter Numbers: (When finished enter zero)"<<"\n";
    double num{};
    std::vector<double> nums{};

    //gets input
    while(std::cin >> num)
    {
        if(num == 0)
        {
            break;
        }
        else
        {
            nums.push_back(num);
        }
    }
    std::cout << "Your input:" << "\n";
    show(nums);
    nums = sort(nums);
    std::cout << "selection sort algorithm applied:" << "\n";
    show(nums);
    return 0;
}

void show(std::vector<double> n)
{
    for (size_t i{}; i < n.size() - 1; i++)
    {
        std::cout << n[i] << " , ";
    }
    std::cout << n[n.size() - 1];
    std::cout << "\n";
}

int min_index(std::vector<double> n, int a, int b)
{
    bool flag{true};
    for (int i{a}; i < b; i++)
    {
        for (int j{a}; j < b ; j++)
        {
            if(n[i] > n[j])
            {
                flag = false;
                break;
            }
            else
            {
                flag = true;
            }

        }
        if(flag)
        {
            return i;
        }

    }
    return 1;
}


void replace(std::vector<double>& n, int a, int b)
{
    double temp;
    temp = n[b];
    n[b] = n[a];
    n[a] = temp;
}


std::vector<double> sort(std::vector<double> nums)
{
    for (size_t i{}; i < nums.size() - 1; i++)
    {
        replace(nums, i, min_index(nums, i, nums.size()));
    }
    return nums;
}
