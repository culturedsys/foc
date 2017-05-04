#include <iostream>
#include <iterator>
#include <vector>

// A two-sided partition that modifies the array and returns an index p such
// that every element in the array at index < p is <= the value at p, and
// every value at index > p is >= the value at p. 
int partition(std::vector<int>& array, int start, int end)
{
    int partition = array[start];

    int from_start = start + 1;
    int from_end = end - 1;

    do 
    {
        while (from_start < end && array[from_start] <= partition)
            from_start++;
        while (from_end > start && array[from_end] >= partition)
            from_end--;
        if (from_start > from_end)
            break;
        std::swap(array[from_start], array[from_end]);
    } while (true);

    std::swap(array[from_end], array[start]);
    return from_end;
}

void quicksort(std::vector<int>& array, int start, int end)
{
    if (start >= end)
        return;
    int p = partition(array, start, end);
    quicksort(array, start, p);
    quicksort(array, p + 1, end);
}

int main()
{
    std::vector<int> array = {1, 3, 2, 4, 0};

    std::cout << "Unsorted: ";
    std::copy(array.begin(), array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    quicksort(array, 0, array.size());
    std::cout << "Sorted: ";
    std::copy(array.begin(), array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "Sorted again: ";
    quicksort(array, 0, array.size());
    std::copy(array.begin(), array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> worst = {1, 1, 1, 1, 1};

    std::cout << "Sorted worst: ";
    quicksort(worst, 0, worst.size());    
    std::copy(worst.begin(), worst.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}