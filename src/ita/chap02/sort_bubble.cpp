/**
 * author:CliffLeopard
 * date:2021/6/27  
 * time:01:39
 * email:precipiceleopard@gmail.com
 * link:
 * 说明: 由小到大
 */
#include "iostream"

using namespace std;

class SortBubble {
public:
    static void sort(int *array, int n) {
        if (n <= 1)
            return;

        int sorted = 0;
        while (sorted < n) {
            int i = n - 1;
            while (i > sorted) {
                if (array[i] < array[i - 1]) {
                    int temp = array[i];
                    array[i] = array[i - 1];
                    array[i - 1] = temp;
                }
                i--;
            }
            sorted++;
        }
    }
};

int main() {
    int *array = new int[10]{10, 7, 3, 5, 1, 2, 9, 8, 4, 6};
    int *array2 = new int[10]{70, 32, 15, 18, 21, 54, 19, 28, 42, 1};
    SortBubble::sort(array, 10);
    SortBubble::sort(array2, 10);

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