/**
 * author:CliffLeopard
 * date:2021/6/27  
 * time:04:48
 * email:precipiceleopard@gmail.com
 * link:
 */
#include "iostream"
using namespace std;

static int changeTimes = 0;

class SortShell {
public:
    static void sort(int *array, int n) {
        changeTimes = 0;
//        insertSort(array, 0, 1, n);
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = 0; i < gap; i++) {
                insertSort(array, i, gap, n);
            }
        }
    }

    // 初始位置为i,间隔为gap的插入排序,此时待排序的数组为 array[i,i+gap,i+2*gap,i+k*gap]
    static void insertSort(int *array, int i, int gap, int n) {
        for (int j = i + gap; j < n; j += gap) {
            int key = array[j];
            int k = j - gap;
            while (k >= 0 && array[k] > key) {
                array[k + gap] = array[k];
                k -= gap;
                changeTimes++;
            }
            array[k + gap] = key;
        }
    }


    static void sort2(int *array, int n) {
        changeTimes = 0;
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                insertSort2(array, gap, i);
            }
        }
    }

    static void insertSort2(int *array, int gap, int i) {
        int key = array[i];
        int k = i - gap;
        while (k >= 0 && array[k] > key) {
            array[k + gap] = array[k];
            k -= gap;
            changeTimes++;
        }
        array[k + gap] = key;
    }
};

int main() {
    int array[] = {10, 7, 3, 5, 1, 2, 9, 8, 4, 6, 11, 15, 12, 14, 13, 16};
    int array2[] = {70, 32, 15, 18, 21, 54, 19, 28, 42, 1, 11, 35, 100, 44, 32, 78, 11, 52};

    int len1 = (sizeof array) / sizeof(int);
    int len2 = (sizeof array2) / sizeof(int);

    for (int i = 0; i < len1; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "lenArray1:" << len1 << "  lenArray2:" << len2 << endl;

    SortShell::sort(array, len1);
    cout << "array1 changeTimes:" << changeTimes << endl;
    SortShell::sort(array2, len2);
    cout << "array2 changeTimes:" << changeTimes << endl;

    for (int i = 0; i < len1; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < len2; i++) {
        cout << array2[i] << " ";
    }
    cout << endl;
    return 0;
}


