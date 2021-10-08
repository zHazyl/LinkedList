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

struct NodeSt {
    Student data;
    int next;
};

struct LinkedListSt {
    NodeSt list[1000];
    int head;
    int tail;
};

void CreateListSt(LinkedListSt &st) {
    st.head = -1;
    st.tail = -1;
}

bool IsEmptyListSt(LinkedListSt &st) {
    if (st.head == -1)
        return 1;
    return 0;
}

void InputListStuFile(LinkedListSt &st, ifstream &ifs) {
    if (!IsEmptyListSt(st))
        return;
    int n;
    ifs >> n;
    for (int i = 0; i < n; ++i) {
        ifs >> st.list[i].data.name;
        ifs >> st.list[i].data.mark;
        st.list[i].next = i + 1;
    }
    st.head = 0;
    st.tail = n - 1;
    st.list[st.tail].next = -1;
}

void OutputArrStu(LinkedListSt &st) {
    int p = st.head;
    while (p != -1) {
        cout << st.list[p].data.name << " " << st.list[p].data.mark << endl;
        p = st.list[p].next;
    }
}

void AddHeadListSt(LinkedListSt &st, int p) {
    if (IsEmptyListSt(st)) {
        st.list[p].next = -1;
        st.head = p;
        st.tail = p;
        return;
    }
    st.list[p].next = st.head;
    st.head = p;
}

void AddTailListSt(LinkedListSt &st, int p) {
    if (p == -1)
        return;
    if (IsEmptyListSt(st)) {
     st.list[p].next = -1;
        st.head = p;
        st.tail = p;
        return;
    }
    st.list[st.tail].next = p;
    st.list[p].next = -1;
    st.tail = p;
}

void DelHeadListSt(LinkedListSt &st) {
    if (IsEmptyListSt(st))
        return;
    if (st.list[st.head].next = -1) {
        st.head = -1;
        st.tail = -1;
        return;
    }
    int p = st.list[st.head].next;
    st.head = -1;
    st.head = p;
}

void DelTailListSt(LinkedListSt &st) {
    if (IsEmptyListSt(st))
        return;
    if (st.list[st.head].next = -1) {
        st.head = -1;
        st.tail = -1;
        return;
    }
    int p = st.head;
    while  (st.list[st.list[p].next].next != -1) {
        p = st.list[p].next;
    }
    st.list[p].next = -1;
    st.tail = p;
}

void DelList(LinkedListSt &st) {
    while (st.head != -1) {
        DelHeadListSt(st);
    }
}

void DelStUnder5(LinkedListSt &st) {
    if (IsEmptyListSt(st))
        return;
    while (st.list[st.head].data.mark < 5) {
        DelHeadListSt(st);
    }
    if (IsEmptyListSt(st))
        return;
    int p = st.head;
    int t;
    while  (st.list[p].next != -1) {
        if  (st.list[st.list[p].next].data.mark < 5) {
            t = st.list[p].next;
            st.list[p].next = st.list[t].next;
        } else {
            p = st.list[p].next;
        }
    }
    st.tail = p;
}

float MaxMark(LinkedListSt &st) {
    float max = 0;
    int p = st.head;
    while (p != -1) {
        if  (st.list[p].data.mark > max) {
            max = st.list[p].data.mark;
        }
        p = st.list[p].next;
    }
    return max;
}

float MinMark(LinkedListSt &st) {
    float min = 10;
    int p = st.head;
    while (p != -1) {
        if  (st.list[p].data.mark < min) {
            min = st.list[p].data.mark;
        }
        p = st.list[p].next;
    }
    return min;
}

void MaxFirstStu(LinkedListSt &st) {
    float max = MaxMark(st);
    int p = st.head;
    int t;
    while  (st.list[p].next != -1) {
        if  (st.list[st.list[p].next].data.mark == max) {
            t = st.list[p].next;
            st.list[p].next = st.list[st.list[p].next].next;
            AddHeadListSt(st, t);
        } else {
            p = st.list[p].next;
        }
    }
    st.tail = p;
}

void MinLastStu(LinkedListSt &st) {
    float min = MinMark(st);
    int p = st.head;
    int t = -1;
    while  (st.list[p].next != -1) {
        if  (st.list[st.list[p].next].data.mark == min) {
            t = st.list[p].next;
            st.list[p].next = st.list[st.list[p].next].next;
            st.list[t].next = -1;
            break;
        }
        p = st.list[p].next;
    }
    int k = t;
    while (st.list[st.list[p].next].next != -1) {
        if  (st.list[st.list[p].next].data.mark == min) {
            st.list[k].next = st.list[p].next;
            st.list[p].next = st.list[st.list[p].next].next;
            st.list[st.list[k].next].next = -1;
            k = st.list[k].next;
        } else {
            p = st.list[p].next;
        }
    }
    st.list[st.tail].next = t;
    st.tail = k;
}

// void DelNodeN(LinkedListSt &st, int n) {
//     if (n == 0) {
//         DelHeadListSt(st);
//         return;
//     }
//     int p = st.head;
//     int i = 0;
//     while (i < n - 1) {
//         ++i;
//         p = st.list[p].next;
//     }
//     if  st.list[st.head].data.next->next == -1) {
//         DelTailListSt(st);
//         return;
//     }
//     int t = st.list[p].next;
//     st.list[st.head].data.next = t->next;
//     delete t;
// }

// void Reverse(LinkedListSt &st) {
//     LinkedListSt r;
//     r.head = -1;
//     r.tail = -1;
//     int p = st.head;
//     int t;
//     while (p != -1) {
//         t = st.list[p].next;
//         AddHeadListSt(r, p);
//         p = t;
//     }
//     st.head = r.head;
//     st.tail = r.tail;
// }

int main() {
    cout << "\n1======================\n";
    ifstream ifs1("DataStudent_1.txt", ios::in);
    if (!ifs1.good()) {
        cout << "error";
        return 0;
    }
    LinkedListSt st1;
    CreateListSt(st1);
    InputListStuFile(st1, ifs1);
    // Reverse(st1);
    // OutputArrStu(st1);
    DelStUnder5(st1);
    OutputArrStu(st1);

    cout << "\n2======================\n";
    ifstream ifs2("DataStudent_2.txt", ios::in);
    if (!ifs2.good()) {
        cout << "error";
        return 0;
    }
    LinkedListSt st2;
    CreateListSt(st2);
    InputListStuFile(st2, ifs2);
    MaxFirstStu(st2);
    OutputArrStu(st2);

    cout << "\n3======================\n";
    ifstream ifs3("DataStudent_3.txt", ios::in);
    if (!ifs3.good()) {
        cout << "error";
        return 0;
    }
    LinkedListSt st3;
    CreateListSt(st3);
    InputListStuFile(st3, ifs3);
    MinLastStu(st3);
    OutputArrStu(st3);

    cout << "\n1+2+3======================\n";
    MaxFirstStu(st1);
    MinLastStu(st1);
    OutputArrStu(st1);

    getchar();
}