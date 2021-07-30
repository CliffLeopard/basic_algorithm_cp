/**
 * author:CliffLeopard
 * date:2021/6/7
 * time:15:43
 * email:precipiceleopard@gmail.com
 * link:
 * 说明:
 */

#include "iostream"

using namespace std;

class SortInsert {

public:
    static void sort(int *array, int n) {
        if (n <= 1)
            return;
        for (int i = 1; i < n; i++) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
};

int main() {
    int *array = new int[10]{10, 7, 3, 5, 1, 2, 9, 8, 4, 6};
    int *array2 = new int[10]{70, 32, 15, 18, 21, 54, 19, 28, 42, 1};
    SortInsert::sort(array, 10);
    SortInsert::sort(array2, 10);

    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << array2[i] << " ";
    }
    cout << endl;
    return 0;
}