/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416


Question - You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.
Link - https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1

Example 1:
Input: A = 10, B = 20
Output: 4
Explanation:
A  = 01010
B  = 10100
As we can see, the bits of A that need 
to be flipped are 01010. If we flip 
these bits, we get 10100, which is B.

Example 2:
Input: A = 20, B = 25
Output: 3
Explanation:
A  = 10100
B  = 11001
As we can see, the bits of A that need 
to be flipped are 10100. If we flip 
these bits, we get 11001, which is B.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned ll
#define PB push_back
#define MP make_pair
#define flash ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define vi vector<int>
#define vl vector<ll>
#define vll vector<ull>
#define mpi map<int, int>
#define mpl map<ll, ll>
#define mpll map<ull, ull>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define all(a) begin(a), end(a)
#define maxEl(a) *max_element(all(a))
#define minEl(a) *min_element(all(a))
#define uimap unordered_map<int, int>
#define ulmap unordered_map<ll, ll>
#define mppii map<pi, int>

int countFlip(int A, int B)
{
    int count(0);
    while (A || B)
    {
        int x(A & 1), y(B & 1);
        count += (x == y ? 0 : 1);
        A >>= 1;
        B >>= 1;
    }
    return count;
}

int32_t main()
{
    flash;
    int A, B;
    cin >> A >> B;
    cout << countFlip(A, B);
    return 0;
}