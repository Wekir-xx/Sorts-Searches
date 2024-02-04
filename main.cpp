#include <iostream>
#include <functional>

//////////////////////SORTS///////////////////////////
void buble_sort(int* array, size_t size);
void sheiker_sort(int* array, size_t size);
void choose_sort(int* array, size_t size);
void insert_sort(int* array, size_t size);
void quick_sort(int* array, size_t size);
void thread_quick_sort(int* array, size_t size);
///////////////////////////////////////////////////////
//////////////////////SEARCHES/////////////////////////
int linear_search(int* array, size_t size, int number);
int binary_search(int* array, size_t size, int number);
int interpolating_search(int* array, size_t size, int number);
///////////////////////////////////////////////////////

class Array
{
public:
    Array(size_t size = 10)
        :size{ size },
        array{ new int[size] }
    {
        for (size_t i = 0; i < size; i++)
            array[i] = rand() % 100;
    }
    ~Array()
    {
        delete[] array;
    }

    void print()
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << array[i] << ' ';
        }
        std::cout << std::endl;
    }

    void use_sort(const std::function<void(int*, size_t)>& function)
    {
        std::cout << "start sort" << std::endl;
        function(array, size);
        std::cout << "end sort" << std::endl;
    }

    int use_search(const std::function<int(int*, size_t, int )>& function, int number)
    {
        return function(array, size, number);
    }

private:
    size_t size;
    int* array;
};

int main()
{
    Array a{ 10000000 };
    a.use_sort(quick_sort);
    return 0;
}