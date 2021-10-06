#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Student {
    string name;
    float mark;
    Student& operator=(Student& st2) {
        this->mark = st2.mark;
        this->name = st2.name;
        return *this;
    }
};

struct ArrayStudent {
    int n;
    Student arrSt[10000];
};

void InputArrStuFile(ArrayStudent &arr, ifstream &ifs) {
    ifs >> arr.n;
    int n = arr.n;
    for (int i = 0; i < n; ++i) {
        ifs >> arr.arrSt[i].name;
        ifs.ignore();
        ifs >> arr.arrSt[i].mark;
    }
}

void OutputArrStu(ArrayStudent &arr) {
    int n = arr.n;
    for (int i = 0; i < n; ++i) {
        cout << arr.arrSt[i].name << " " << arr.arrSt[i].mark << endl;
    }
}

void DeleteStuUnder5(ArrayStudent &arr) {
    int n = arr.n;
    int nod = 0;
    for (int i = 0; ; ++i) {
        while (arr.arrSt[i].mark < 5 && i < n) {
            ++nod;
            ++i;
        }
        if (i == n)
            break;
        arr.arrSt[i - nod] = arr.arrSt[i];
    }
    arr.n -= nod;
}

float MaxMark(ArrayStudent &arr) {
    int n = arr.n;
    float max = 0;
    for (int i = 0; i < n; ++i) {
        if (arr.arrSt[i].mark > max)
            max = arr.arrSt[i].mark;
    }
    return max;
}

float MinMark(ArrayStudent &arr) {
    int n = arr.n;
    float min = 10;
    for (int i = 0; i < n; ++i) {
        if (arr.arrSt[i].mark < min)
            min = arr.arrSt[i].mark;
    }
    return min;
}

void MaxFirstStu(ArrayStudent &arr) {
    float max = MaxMark(arr);
    Student stuTop[1000];
    int numMax = 0;
    for (int i = arr.n - 1; ; --i) {
        while (arr.arrSt[i].mark == max && i >= 0) {
            stuTop[numMax] = arr.arrSt[i];
            ++numMax;
            --i;
        }
        if (i < 0)
            break;
        arr.arrSt[i + numMax] = arr.arrSt[i];
    }
    for (int i = numMax - 1; i >= 0; --i) {
        arr.arrSt[numMax - 1 - i] = stuTop[i];
    }
}

void MinLastStu(ArrayStudent &arr) {
    float min = MinMark(arr);
    Student stuTop[1000];
    int numMin = 0;
    int n = arr.n;
    for (int i = 0; ; ++i) {
        while (arr.arrSt[i].mark == min && i < n) {
            stuTop[numMin] = arr.arrSt[i];
            ++numMin;
            ++i;
        }
        if (i == n)
            break;
        arr.arrSt[i - numMin] = arr.arrSt[i];
    }
    int k = 0;
    for (int i = numMin - 1; i >= 0; --i) {
        arr.arrSt[n - 1 - k] = stuTop[i];
        ++k;
    }
}

int main() {
    cout << "\n1======================\n";
    ifstream ifs1("DataStudent_1.txt", ios::in);
    if (!ifs1.good()) {
        cout << "error";
        return 0;
    }
    ArrayStudent arr1;
    InputArrStuFile(arr1, ifs1);
    ifs1.close();
    DeleteStuUnder5(arr1);
    OutputArrStu(arr1);

    cout << "\n2======================\n";
    
    ifstream ifs2("DataStudent_2.txt", ios::in);
    if (!ifs2.good()) {
        cout << "error";
        return 0;
    }
    ArrayStudent arr2;
    InputArrStuFile(arr2, ifs2);
    ifs2.close();
    MaxFirstStu(arr2);
    OutputArrStu(arr2);

    cout << "\n3======================\n";

    ifstream ifs3("DataStudent_3.txt", ios::in);
    if (!ifs3.good()) {
        cout << "error";
        return 0;
    }
    ArrayStudent arr3;
    InputArrStuFile(arr3, ifs3);
    ifs3.close();
    MinLastStu(arr3);
    OutputArrStu(arr3);

    cout << "\n1+2+3======================\n";
    MaxFirstStu(arr1);
    MinLastStu(arr1);
    OutputArrStu(arr1);

    getchar();
    return 0;
}