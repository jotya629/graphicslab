#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    int points[n][3];

    cout << "Enter points (x y):\n";
    for(int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
        points[i][2] = 1;
    }

    float angle;
    cout << "Enter angle (in degree): ";
    cin >> angle;

    float rad = angle * 3.1416 / 180;

    float R[3][3] = {
        {cos(rad), -sin(rad), 0},
        {sin(rad), cos(rad), 0},
        {0, 0, 1}
    };

    float result[n][3];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < 3; k++)
            {
                result[i][j] += R[j][k] * points[i][k];
            }
        }
    }

    cout << "\nRotated Points:\n";
    for(int i = 0; i < n; i++)
    {
        cout << "(" << result[i][0] << ", " << result[i][1] << ")\n";
    }

    return 0;
}
