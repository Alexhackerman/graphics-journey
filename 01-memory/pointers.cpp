// Day 3: pointers and references. No [i] indexing allowed.
#include <cassert>
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

void reset(int **p)
{
    *p = nullptr;
}

size_t my_strlen(const char *s)
{
    size_t count = 0;
    while (*s != '\0')
    {
        count++;
        s++;
    }
    return count;
}

void my_reverse(char *s) {
    if (my_strlen(s) == 0) {
        return;
    }
    char *p = s + my_strlen(s) - 1;
    char q;
    while (s < p) {
        q = *s;
        *s = *p;
        *p = q;

        s++;
        p--;
    }

}

template<typename T>
void my_swap(T *a, T *b) {
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {

    // PART 1

    // 1.
    // int a[5];
    // int *p = a;
    // cout << p << endl; // the address of a
    // cout << p + 1 << endl; // we increase with 1 byte
    // cout << *(p + 2) << endl; // the value at p + 2
    //
    // double b[10];
    // double *q = b;
    // cout << q << endl; //the address of b
    // cout << q + 1 << endl; // we increase with 2 bytes
    // cout << *(q + 2); // the value at q + 2

    //2.
    // int x = 5;
    // int *p = &x;
    // int **pp = &p;
    //
    // **pp =10;
    // assert(x == 10);
    // reset(&p);
    // assert(p == nullptr);
    // we can't write a reset with just *p because
    // then our changes wouldn't get to the actual
    // value we want to change and would just happen
    // to the copy we reference in the signature
    // of the function

    //3.
    // int x = 1, y = 2;
    // const int* a = &x;    *a = 1;   a = &y;
    // int* const b = &x;    *b = 1;   b = &y;
    // const int* const c = &x; *c = 1; c = &y;

    //****
    //PART 2

    //1.
    assert(my_strlen("Hello") == 5);
    assert(my_strlen("") == 0);
    assert(my_strlen("W") == 1);

    //2.
    char w1[] = "hello"; my_reverse(w1); assert(string(w1) == "olleh");
    char w2[] = "ab";    my_reverse(w2); assert(string(w2) == "ba");
    char w3[] = "a";     my_reverse(w3); assert(string(w3) == "a");
    char w4[] = "";      my_reverse(w4); assert(string(w4) == "");

    //3.
    int i1 = 1, i2 = 2;           my_swap(&i1, &i2); assert(i1 == 2 && i2 == 1);
    double d1 = 1.5, d2 = -3.0;   my_swap(&d1, &d2); assert(d1 == -3.0 && d2 == 1.5);
    string s1 = "foo", s2 = "bar"; my_swap(&s1, &s2); assert(s1 == "bar" && s2 == "foo");


    return 0;
}
