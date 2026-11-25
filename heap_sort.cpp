#include <iostream>
using namespace std;

// Heapify for ascending order (Max Heap)
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Heapify for descending order (Min Heap)
void minHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Heap Sort Ascending
void heapSortAscending(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// Heap Sort Descending
void heapSortDescending(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n], asc[n], desc[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        asc[i] = arr[i];
        desc[i] = arr[i];
    }

    heapSortAscending(asc, n);
    heapSortDescending(desc, n);

    cout << "Ascending Order: ";
    for (int i = 0; i < n; i++)
        cout << asc[i] << " ";

    cout << "\nDescending Order: ";
    for (int i = 0; i < n; i++)
        cout << desc[i] << " ";

    return 0;
}
