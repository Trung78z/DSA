#include <iostream>
#include <cassert>
template <typename T>
void heapify(T *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
template <typename T>
void heapSort(T *arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
template <typename T>
void display(T *arr, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = {-10, 78, -1, -6, 7, 4, 94, 5, 99, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    display(arr, n);
    heapSort(arr, n);
    display(arr, n);

    return 0;
}