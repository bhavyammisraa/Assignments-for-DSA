#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int minIndex = i;
        int maxIndex = n - i - 1;

        // Ensure minIndex < maxIndex before comparisons
        if (arr[minIndex] > arr[maxIndex])
            swap(arr[minIndex], arr[maxIndex]);

        // Find actual min and max in current unsorted range
        for (int j = i + 1; j < n - i; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
            else if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }

        // Place the minimum at the start
        swap(arr[i], arr[minIndex]);

        // If the max element was at position i and got swapped, update its index
        if (maxIndex == i)
            maxIndex = minIndex;

        // Place the maximum at the end
        swap(arr[n - i - 1], arr[maxIndex]);
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 90, 3, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
