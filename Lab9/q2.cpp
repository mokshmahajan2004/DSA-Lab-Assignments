#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <float.h>
using namespace std;
struct Point
{
    int x, y;
};
double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}
double bruteForce(vector<Point> &points, int left, int right, pair<Point, Point> &closest)
{
    double minDist = DBL_MAX;
    for (int i = left; i < right; ++i)
    {
        for (int j = i + 1; j < right; ++j)
        {
            double d = dist(points[i], points[j]);
            if (d < minDist)
            {
                minDist = d;
                closest = {points[i], points[j]};
            }
        }
    }
    return minDist;
}
bool compareX(Point a, Point b) { return a.x < b.x; }
bool compareY(Point a, Point b) { return a.y < b.y; }
double stripClosest(vector<Point> &strip, double d, pair<Point, Point> &closest)
{
    double minDist = d;
    sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); ++i)
    {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j)
        {
            double distance = dist(strip[i], strip[j]);
            if (distance < minDist)
            {
                minDist = distance;
                closest = {strip[i], strip[j]};
            }
        }
    }
    return minDist;
}
double closestUtil(vector<Point> &Px, vector<Point> &Py, int left, int right, pair<Point, Point> &closest)
{
    if (right - left <= 3)
        return bruteForce(Px, left, right, closest);
    int mid = (left + right) / 2;
    Point midPoint = Px[mid];
    vector<Point> Pyl, Pyr;
    for (auto &p : Py)
    {
        if (p.x <= midPoint.x)
            Pyl.push_back(p);
        else
            Pyr.push_back(p);
    }
    pair<Point, Point> cl, cr;
    double dl = closestUtil(Px, Pyl, left, mid, cl);
    double dr = closestUtil(Px, Pyr, mid, right, cr);
    double d = (dl < dr) ? dl : dr;
    closest = (dl < dr) ? cl : cr;
    vector<Point> strip;
    for (auto &p : Py)
        if (abs(p.x - midPoint.x) < d)
            strip.push_back(p);

    return min(d, stripClosest(strip, d, closest));
}
double closestPair(vector<Point> &points, pair<Point, Point> &closest)
{
    vector<Point> Px = points;
    vector<Point> Py = points;
    sort(Px.begin(), Px.end(), compareX);
    sort(Py.begin(), Py.end(), compareY);
    return closestUtil(Px, Py, 0, points.size(), closest);
}
int main()
{
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    pair<Point, Point> closest;
    double minDist = closestPair(points, closest);
    cout << "Closest pair: [(" << closest.first.x << "," << closest.first.y
         << "), (" << closest.second.x << "," << closest.second.y
         << ")] with distance ≈ " << minDist << endl;
    return 0;
}
