#include <thread>

void buble_sort(int* array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        bool tr = true;
        for (size_t j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                tr = false;
            }
        }
        if (tr) return;
    }
}

void sheiker_sort(int* array, size_t size)
{
    for (size_t i = 0; i < size / 2; i++)
    {
        bool tr = true;
        for (size_t j = i; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                tr = false;
            }
        }
        for (size_t j = size - 1 - i; j > i; j--)
        {
            if (array[j] < array[j - 1])
            {
                std::swap(array[j], array[j - 1]);
                tr = false;
            }
        }
        if (tr) return;
    }
}

void choose_sort(int* array, size_t size)
{
    int min = array[0];
    size_t id;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 1; j < size; j++)
        {
            if (min > array[j])
            {
                min = array[j];
                id = j;
            }
        }
        std::swap(array[id], array[i]);
    }
}

void insert_sort(int* array, size_t size)
{
    int buff = 0;
    int j;
    for (int i = 1; i < size; i++)
    {
        buff = array[i];
        for (j = i - 1; j >= 0 && array[j] > buff; j--)
            array[j + 1] = array[j];
        array[j + 1] = buff;
    }
}

void In_quick_sort(int* array, int first, int last)
{
    {
        if (first < last)
        {
            int middle = array[(first + last) / 2];
            int left = first;
            int right = last;
            while (left <= right)
            {
                while (array[left] < middle)
                    left++;
                while (array[right] > middle)
                    right--;
                if (left <= right)
                {
                    std::swap(array[left], array[right]);
                    left++;
                    right--;
                }
            }
            In_quick_sort(array, first, right);
            In_quick_sort(array, left, last);
        }
    }
}

void In_thread_quick_sort(int* array, int first, int last)
{
    if (first < last)
    {
        int middle = array[(first + last) / 2];
        int left = first;
        int right = last;
        while (left <= right)
        {
            while (array[left] < middle)
                left++;
            while (array[right] > middle)
                right--;
            if (left <= right)
            {
                std::swap(array[left], array[right]);
                left++;
                right--;
            }
        }
        std::thread th1([&]() {
            In_quick_sort(array, first, right);
            });
        In_quick_sort(array, left, last);
        th1.join();
    }
}

void quick_sort(int* array, size_t size) { In_quick_sort(array, 0, size - 1); }
void thread_quick_sort(int* array, size_t size) { In_thread_quick_sort(array, 0, size - 1); }
