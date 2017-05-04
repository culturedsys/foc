#include <iostream>
#include <iterator>
#include <vector>

void insertion_sort(std::vector<int>& array, int start, int end)
{
    int sorted_end = start + 1;

    while (sorted_end != end)
    {
        int swap_from = sorted_end;
        while (swap_from != start)
        {
            if (array[swap_from] > array[swap_from - 1])
                break;
            std::swap(array[swap_from], array[swap_from - 1]);
            swap_from--;
        }
        sorted_end++;
    }
}

int main()
{
    std::vector<int> array = {1, 3, 2, 4, 0};

    std::cout << "Unsorted: ";
    std::copy(array.begin(), array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    insertion_sort(array, 0, array.size());
    std::cout << "Sorted: ";
    std::copy(array.begin(), array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "Sorted again: ";
    insertion_sort(array, 0, array.size());
    std::copy(array.begin(), array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}