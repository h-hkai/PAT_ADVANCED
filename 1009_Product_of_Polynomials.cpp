#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef struct PolyNode *Polynomial;

struct PolyNode
{
    double coef;
    int expon;
    Polynomial link;
};

void Attach(int expon, double coef, Polynomial* rear) {
    Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->expon = expon;
    P->coef = coef;
    P->link = NULL;
    (*rear)->link = P;
    (*rear) = P;
}

Polynomial ReadPoly() {
    Polynomial p, pRear, t;
    int e, N;
    double c;
    p = (Polynomial)malloc(sizeof(struct PolyNode));
    cin >> N;
    p->link = NULL;
    pRear = p;
    while(N--) {
        cin >> e >> c;
        Attach(e, c, &pRear);
    }
    t = p, p = p->link, free(t);
    return p;
}

Polynomial MultPoly(Polynomial P1, Polynomial P2) {
    Polynomial Rear, t, t1, t2, P;
    int e;
    double c;

    if (P1 == NULL || P2 == NULL) return NULL;

    t1 = P1, t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while(t2) {
        Attach(t1->expon + t2->expon, t1->coef * t2->coef, &Rear);
        t2 = t2->link;
    }
    t1 = t1->link;

    while (t1) {
        t2 = P2; Rear = P;
        while (t2) {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while (Rear->link && Rear->link->expon > e) Rear = Rear->link;
            if (Rear->link && Rear->link->expon == e) {
                if (Rear->link->coef + c) {
                    Rear->link->coef += c;
                } else {
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            } else {
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->expon = e;
                t->coef = c;
                t->link = Rear->link;
                Rear->link = t;
            }

            t2 = t2->link;
        }
        t1 = t1->link;
    }

    t = P; P = P->link; free(t);
    return P;
}

void PrintPoly(Polynomial p) {
    Polynomial t = p;
    int len = 0;
    while (t != NULL) {
        len++;
        t = t->link;
    }
    cout << len;
    while(p != NULL) {
        cout << " " << p->expon;
        cout << " " << fixed << setprecision(1) << p->coef;
        p = p->link;
    }
}

int main() {
    Polynomial p1, p2, pp;
    p1 = ReadPoly();
    p2 = ReadPoly();

    pp = MultPoly(p1, p2);
    PrintPoly(pp);

    return 0;
}