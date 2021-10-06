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
    NodeSt *p = st.pHead;
    while (p != NULL) {
        ifs >> p->data.name;
        ifs >> p->data.mark;
        p = p->pNext;
    }
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

int main() {

}