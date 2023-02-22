// ConsoleApplication28.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
template<typename T>
void initArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

template<typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
}

template<typename T>
int insert(T*& arr, int& size, T value, int posInsert) {
    if (0 <= posInsert && posInsert <= size) {
        T* temp = new T[size + 1];
        int i = 0;
        for (; i < posInsert; i++) {
            temp[i] = arr[i];
        }
        temp[i] = value;
        for (int j = posInsert + 1; j < size + 1 && i < size; j++, i++) {
            temp[j] = arr[i];
        }
        delete[] arr;
        size++;
        arr = temp;
        return 0;
    }
    else {
        return -1;
    }
}

template<typename T>
int insert(T*& arr, int& size, T* insertArray, int insertSize, int posInsert) {
    if (0 <= posInsert && posInsert <= size) {
        T* temp = new T[size + insertSize];
        int i = 0;
        for (; i < posInsert; i++) {
            temp[i] = arr[i];
        }
        for (int j = 0; j < insertSize; j++, i++) {
            temp[i] = insertArray[j];
        }
        for (int j = i-insertSize ; j<size && i<size+insertSize ; j++, i++) {
            temp[i] = arr[j];
        }
        delete[] arr;
        size+= insertSize;
        arr = temp;
        return 0;
    }
    else {
        return -1;
    }
}

int main()
{
    int size = 10;
    int* arr = new int[size];
    initArray(arr, size);
    printArray(arr, size);
    int answer = insert(arr, size, -5, 100);
    if (!answer) {
        cout << endl;
        printArray(arr, size);
    }
    else {
        cout << endl;
        cout << "error!!!11!";
    }

    int a[] = { 5,5,5 };
    int answer1 = insert(arr, size, a, 3, 6);
    if (!answer1) {
        cout << endl;
        printArray(arr, size);
    }
    else {
        cout << endl;
        cout << "error!!!11!";
    }
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
