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

void InputArrStuFile(ArrayStudent &arr) {
    ifstream ifs("DataStudent.txt", ios::in);
    if (!ifs.good()) {
        cout << "error";
        return;
    }
    ifs >> arr.n;
    int n = arr.n;
    for (int i = 0; i < n; ++i) {
        ifs >> arr.arrSt[i].name;
        ifs.ignore();
        ifs >> arr.arrSt[i].mark;
    }
    ifs.close();
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
    for (int i = 0; i < n; ++i) {
        while (arr.arrSt[i].mark < 5 && i < n) {
            ++nod;
            ++i;
        }
        arr.arrSt[i - nod] = arr.arrSt[i];
    }
    arr.n -= nod;
}

int main() {
    ArrayStudent arr;
    InputArrStuFile(arr);
    DeleteStuUnder5(arr);
    OutputArrStu(arr);
    getchar();
    return 0;
}