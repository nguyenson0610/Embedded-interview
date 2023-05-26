#include <stdio.h>

#define MAX 10

#define TICH(a,b) a*b

#define FUNCTION1(ten_ham,noi_dung)              \
void ten_ham(){                                  \
    printf("In ra noi dung la %s\n", noi_dung);  \
}                                                \

FUNCTION1(test,"test marco");

// Inline
inline void ham1(){
    printf("test macro\n");
}

int main(int argc, char const *argv[])
{
    printf("In ra MAX la %d\n", MAX);
    printf("In ra TICH la %d\n", TICH(5,7));
    test();
    ham1();
    return 0;
}


