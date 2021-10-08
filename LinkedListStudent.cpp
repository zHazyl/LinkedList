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
    NodeSt *pNext;
};

struct LinkedListSt {
    NodeSt *pHead;
    NodeSt *pTail;
};

void CreateListSt(LinkedListSt &st) {
    st.pHead = NULL;
    st.pTail = NULL;
}

bool IsEmptyListSt(LinkedListSt &st) {
    if (st.pHead == NULL)
        return 1;
    return 0;
}

void InputListStuFile(LinkedListSt &st, ifstream &ifs) {
    if (!IsEmptyListSt(st))
        return;
    int n;
    ifs >> n;
    NodeSt *p = new NodeSt();
    st.pHead = new NodeSt();
    p->pNext = st.pHead;
    for (int i = 0; i < n; ++i) {
        ifs >> p->pNext->data.name;
        ifs.ignore();
        ifs >> p->pNext->data.mark;
        p = p->pNext;
        p->pNext = new NodeSt();
    }
    st.pTail = p;
    delete p->pNext;
    p->pNext = NULL;
}

void OutputArrStu(LinkedListSt &st) {
    NodeSt *p = st.pHead;
    while (p != NULL) {
        cout << p->data.name << " " << p->data.mark << endl;
        p = p->pNext;
    }
}

void AddHeadListSt(LinkedListSt &st, NodeSt *p) {
    if (p == NULL)
        return;
    if (IsEmptyListSt(st)) {
        p->pNext = NULL;
        st.pHead = p;
        st.pTail = p;
        return;
    }
    p->pNext = st.pHead;
    st.pHead = p;
}

void AddTailListSt(LinkedListSt &st, NodeSt *p) {
    if (p == NULL)
        return;
    if (IsEmptyListSt(st)) {
        p->pNext = NULL;
        st.pHead = p;
        st.pTail = p;
        return;
    }
    st.pTail->pNext = p;
    p->pNext = NULL;
    st.pTail = p;
}

void DelHeadListSt(LinkedListSt &st) {
    if (IsEmptyListSt(st))
        return;
    if (st.pHead->pNext = NULL) {
        st.pHead = NULL;
        st.pTail = NULL;
        return;
    }
    NodeSt *p = st.pHead->pNext;
    delete st.pHead;
    st.pHead = NULL;
    st.pHead = p;
}

void DelTailListSt(LinkedListSt &st) {
    if (IsEmptyListSt(st))
        return;
    if (st.pHead->pNext = NULL) {
	delete st.pHead;
        st.pHead = NULL;
        st.pTail = NULL;
        return;
    }
    NodeSt *p = st.pHead;
    while (p->pNext->pNext != NULL) {
        p = p->pNext;
    }
    delete p->pNext;
    p->pNext = NULL;
    st.pTail = p;
}

void DelList(LinkedListSt &st) {
    while (st.pHead != NULL) {
        DelHeadListSt(st);
    }
}

void DelStUnder5(LinkedListSt &st) {
    if (IsEmptyListSt(st))
        return;
    while (st.pHead->data.mark < 5) {
        DelHeadListSt(st);
    }
    if (IsEmptyListSt(st))
        return;
    NodeSt *p = st.pHead;
    NodeSt *t;
    while (p->pNext != NULL) {
        if (p->pNext->data.mark < 5) {
            t = p->pNext;
            p->pNext = t->pNext;
            delete t;
        } else {
            p = p->pNext;
        }
    }
    st.pTail = p;
}

float MaxMark(LinkedListSt &st) {
    float max = 0;
    NodeSt *p = st.pHead;
    while (p != NULL) {
        if (p->data.mark > max) {
            max = p->data.mark;
        }
        p = p->pNext;
    }
    return max;
}

float MinMark(LinkedListSt &st) {
    float min = 10;
    NodeSt *p = st.pHead;
    while (p != NULL) {
        if (p->data.mark < min) {
            min = p->data.mark;
        }
        p = p->pNext;
    }
    return min;
}

void MaxFirstStu(LinkedListSt &st) {
    float max = MaxMark(st);
    NodeSt *p = st.pHead;
    NodeSt *t;
    while (p->pNext != NULL) {
        if (p->pNext->data.mark == max) {
            t = p->pNext;
            p->pNext = p->pNext->pNext;
            AddHeadListSt(st, t);
        } else {
            p = p->pNext;
        }
    }
    st.pTail = p;
}

void MinLastStu(LinkedListSt &st) {
    float min = MinMark(st);
    NodeSt *p = st.pHead;
    NodeSt *t = NULL;
    while (p->pNext != NULL) {
        if (p->pNext->data.mark == min) {
            t = p->pNext;
            p->pNext = p->pNext->pNext;
            t->pNext = NULL;
            break;
        }
        p = p->pNext;
    }
    NodeSt *k = t;
    while(p->pNext->pNext != NULL) {
        if (p->pNext->data.mark == min) {
            k->pNext = p->pNext;
            p->pNext = p->pNext->pNext;
            k->pNext->pNext = NULL;
            k = k->pNext;
        } else {
            p = p->pNext;
        }
    }
    st.pTail->pNext = t;
    st.pTail = k;
}

void DelNodeN(LinkedListSt &st, int n) {
    if (n == 0) {
        DelHeadListSt(st);
        return;
    }
    NodeSt *p = st.pHead;
    int i = 0;
    while (i < n - 1) {
        ++i;
        p = p->pNext;
    }
    if (p->pNext->pNext == NULL) {
        DelTailListSt(st);
        return;
    }
    NodeSt *t = p->pNext;
    p->pNext = t->pNext;
    delete t;
}

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