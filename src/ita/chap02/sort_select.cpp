/**
 * author:CliffLeopard
 * date:2021/6/27  
 * time:00:17
 * email:precipiceleopard@gmail.com
 * link:
 * 说明: 选择排序，由小到大
 * 算法很简单，每次从还没排序的部分找到最小的值，和带排序的位置交换。
 */

#include "iostream"

using namespace std;

class SortSelect {
public:
    static void sort(int *array, int n) {
        if (n <= 1)
            return;
        for (int i = 0; i < n - 1; i++) {
            int min = array[i];
            int index = i;
            for (int j = i + 1; j < n; j++) {
                if (array[j] < min) {
                    min = array[j];
                    index = j;
                }
            }
            array[index] = array[i];
            array[i] = min;
        }
    }
};

int main() {
    int *array = new int[10]{10, 7, 3, 5, 1, 2, 9, 8, 4, 6};
    int *array2 = new int[10]{70, 32, 15, 18, 21, 54, 19, 28, 42, 1};
    SortSelect::sort(array, 10);
    SortSelect::sort(array2, 10);

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