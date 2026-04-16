#include<iostream>
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

    int sx, sy;
    cout << "Enter scaling factors (sx sy): ";
    cin >> sx >> sy;

    int S[3][3] = {
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0, 1}
    };

    int result[n][3];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < 3; k++)
            {
                result[i][j] += S[j][k] * points[i][k];
            }
        }
    }

    cout << "\nScaled Points:\n";
    for(int i = 0; i < n; i++)
    {
        cout << "(" << result[i][0] << ", " << result[i][1] << ")\n";
    }

    return 0;
}
