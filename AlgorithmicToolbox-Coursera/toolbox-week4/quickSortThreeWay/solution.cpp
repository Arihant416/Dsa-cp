#include <bits/stdc++.h>
using namespace std;

pair<int, int> partition3Ways(vector<int> &A, int low, int high)
{
    int pivot = A[low];
    int left = low;
    int right = high;
    int index = low;
    int point1(0), point2(0);

    vector<int> res(2);
    while (index <= right)
    {
        if (A[index] < pivot)
        {
            swap(A[index], A[left]);
            left++;
            index++;
        }
        else if (A[index] == pivot)
        {
            index++;
        }
        else
        {
            swap(A[index], A[right]);
            right--;
        }
        point1 = left;
        point2 = right;
    }
    return {point1, point2};
}

void randomizedQuickSort(vector<int> &A, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int num = low + rand() % (high - low + 1);
    swap(A[low], A[num]);
    auto points = partition3Ways(A, low, high);
    randomizedQuickSort(A, low, points.first - 1);
    randomizedQuickSort(A, points.second + 1, high);
}

void print(vector<int> &A)
{
    for (int &i : A)
        cout << i << " ";
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &i : A)
        cin >> i;
    randomizedQuickSort(A, 0, N - 1);
    print(A);
    return 0;
}