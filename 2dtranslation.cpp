
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    int points[n][3];

    cout << "Enter the coordinates (x y):" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
        points[i][2] = 1; // homogeneous coordinate
    }

    int tx, ty;
    cout << "Enter translation (tx ty): ";
    cin >> tx >> ty;

    // Translation matrix
    int T[3][3] = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}
    };

    int result[n][3];

    // Matrix multiplication
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < 3; k++)
            {
                result[i][j] += T[j][k] * points[i][k];
            }
        }
    }

    // Original points
    cout << "\nOriginal Points:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "(" << points[i][0] << ", " << points[i][1] << ")" << endl;
    }

    // Translated points
    cout << "\nTranslated Points:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "(" << result[i][0] << ", " << result[i][1] << ")" << endl;
    }

    return 0;
}
