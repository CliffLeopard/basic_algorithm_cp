//
// Created by CliffLeopard on 2019-04-18.
//
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int times;
    scanf("%d", &times);
    for (int j = 0; j < times; j++) {
        char ox[81];
        cin.getline(ox,81);
        int n = strlen(ox);
        int sum = 0;
        int number = 0;
        for (int i = 0; i < n; i++) {
            if (ox[i] == 'O') {
                sum += ++number;
            } else {
                number = 0;
            }
        }
        cout << sum;
        if (j < times - 1)
            cout << endl;
    }
    return 0;
}