#include <thread>

void buble_sort(int* array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        bool tr = true;
        for (size_t j = 0; j < size - 1; j++)
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

void In_merge_sort(int* array, size_t start, size_t end)
{
    if (end - start < 2) return;
    if (end - start == 2)
    {
        if (array[start] <= array[start + 1]) return;
        std::swap(array[start], array[start + 1]);        
    }
    In_merge_sort(array, start, start + (end - start) / 2);
    In_merge_sort(array, start + (end - start) / 2, end);

    int* array_2 = new int[end - start];
    size_t index = 0;
    size_t begin1 = start;
    size_t end1 = start + (end - start) / 2;
    size_t begin2 = end1;
    while (index < end - start)
    {
        if (begin1 >= end1 || (begin2 < end && array[begin2] <= array[begin1]))
            array_2[index++] = array[begin2++];
        else
            array_2[index++] = array[begin1++];
    }
    for (size_t i = start; i < end; ++i)
        array[i] = array_2[i - start];
    delete[] array_2;
}

void merge_sort(int* array, size_t size) { In_merge_sort(array, 0, size); }

void In_quick_sort(int* array, size_t first, size_t last)
{
    if (first < last)
    {
        size_t middle = array[(first + last) / 2];
        size_t left = first;
        size_t right = last;
        while (left <= right)
        {
            while (array[left] < middle)
                left++;

            while (array[right] > middle)
                right--;

            if (left >= right) break;

            std::swap(array[left++], array[right--]);
        }
        In_quick_sort(array, first, right);
        In_quick_sort(array, right + 1, last);
    }
}

void In_thread_quick_sort(int* array, size_t first, size_t last)
{
    if (first < last)
    {
        size_t middle = array[(first + last) / 2];
        size_t left = first;
        size_t right = last;
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
