// Note this solution fails one testCase
#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x_coord, y_coord;
};

int xComparator(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x_coord - p2->x_coord);
}

int yComparator(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y_coord - p2->y_coord);
}
float min(float x, float y)
{
    return x < y ? x : y;
}

float euclideanDistance(Point p1, Point p2)
{
    return sqrt((p1.x_coord - p2.x_coord) * (p1.x_coord - p2.x_coord) + (p1.y_coord - p2.y_coord) * (p1.y_coord - p2.y_coord));
}

float naiveClosest(Point P[], int N)
{
    float ans = FLT_MAX;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; j++)
        {
            ans = min(euclideanDistance(P[i], P[j]), ans);
        }
    }
    return ans;
}

float stripNearest(Point strip[], int size, float d)
{
    float minimum_distance = d;
    qsort(strip, size, sizeof(Point), yComparator);
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size && (strip[j].y_coord - strip[i].y_coord) < minimum_distance; ++j)
        {
            minimum_distance = min(euclideanDistance(strip[i], strip[j]), minimum_distance);
        }
    }
    return minimum_distance;
}

float findClosestUtil(Point P[], int n)
{
    if (n <= 4)
        return naiveClosest(P, n);
    int mid = n / 2;
    Point midPoint = P[mid];
    float delta_left = findClosestUtil(P, mid);
    float delta_right = findClosestUtil(P + mid, n - mid);
    float minimum_dldr = min(delta_left, delta_right);
    Point strip[n];
    int j(0);
    for (int i = 0; i < n; i++)
    {
        if (abs(P[i].x_coord - midPoint.x_coord) < minimum_dldr)
        {
            strip[j++] = P[i];
        }
    }
    return min(minimum_dldr, stripNearest(strip, j, minimum_dldr));
}

float findClosest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), xComparator);
    return findClosestUtil(P, n);
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    Point P[N];
    for (int i = 0; i < N; i++)
    {
        cin >> P[i].x_coord >> P[i].y_coord;
    }
    cout << findClosest(P, N);
    return 0;
}
