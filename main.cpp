#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");  

    int N;
    cout << "Введите размер массива N: ";
    cin >> N;

    if (N <= 0) {
        cout << "Ошибка: N должно быть больше 0" << endl;
        return 1;
    }

    int A[100];   

    cout << "Введите " << N << " элементов массива:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }

    
    int iMax = 0;
    int iMin = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] > A[iMax]) iMax = i;
        if (A[i] < A[iMin]) iMin = i;
    }

    cout << "\nМаксимальный элемент: A[" << iMax << "] = " << A[iMax] << endl;
    cout << "Минимальный элемент:  A[" << iMin << "] = " << A[iMin] << endl;

    
    int left, right;
    if (iMax < iMin) {
        left = iMax;
        right = iMin;
    }
    else {
        left = iMin;
        right = iMax;
    }

    
    int sum = 0;
    int count = 0;   
    for (int i = left + 1; i < right; i++) {
        if (A[i] < 0) {
            sum += A[i];
            count++;
        }
    }

    
    cout << "\nЭлементы между max и min (индексы " << left + 1 << ".." << right - 1 << "):" << endl;
    if (count == 0) {
        cout << "Отрицательных элементов между ними нет." << endl;
        cout << "Сумма = 0" << endl;
    }
    else {
        cout << "Найдено отрицательных: " << count << endl;
        cout << "Сумма отрицательных элементов = " << sum << endl;
    }

    return 0;
}
