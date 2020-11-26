//You are given a set of n segments on the axis Ox, each segment has integer endpoints between 0 and m inclusive.
//Segments may intersect, overlap or even coincide with each other.Each segment is characterized by two integers li and ri — coordinates of the left and of the right endpoints.
//
//Consider all integer points between 0 and m inclusive.Your task is to print all such points that don't belong to any segment. The point x belongs to the segment [l;r] if and only if l ≤ x ≤ r.
//
//Input:
//m — the upper bound for coordinates;
//array of coordinates liand ri 0 ≤ li ≤ ri ≤ m — the endpoints of the i - th segment.Segments may intersect, overlap or even coincide with each other.
//
//Output:
//All points from 0 to m that don't belong to any segment.
//
//Examples :
//
//	segments(5, { {2,2},{1,2},{5,5} }) = > {0, 3, 4}
//segments(7, { {0,7} }) = > {}

#include <vector>

std::vector<int> segments(int m, const std::vector<std::pair<int, int>>& arr)
{
    std::vector<bool> map;
    std::vector<int> out_int;
    for (int i = 0; i <= m; i++)
    {
        map.push_back(false);
    }
    for (auto n : arr)
    {
        for (int p = n.first; p <= n.second; p++)
        {
            map[p] = true;
        }
    }
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (*it == false) out_int.push_back(it - map.begin());
    }
    return out_int; // you code here
}