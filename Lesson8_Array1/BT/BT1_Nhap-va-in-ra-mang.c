 /**
  *  Khởi tạo n biến, tự nhập vào bàn phím
  *  x1=1, x2=2, x3=3,...x100=100.
  */ 

#include <stdio.h>
#include <string.h>

void nhapSoPhanTu(int *n, unsigned char *s1)
{
    printf("Nhập số phần tử mảng: ");
    scanf("%d", n);

    int temp;
    for (int i = 0; i < *n; i++)
    {
        printf("mang[%d] = ",i);
        scanf("%d", &temp);

        s1[i] = (char)temp;
    }

  

    printf("----------------------------\n");
}

void inSoPhanTu(int *n, unsigned char *s1)
{
    for (int i = 0; i < *n; i++)
    {
        printf("mang[%d] = %d\n",i , s1[i]);
    }
}

int main(int argc, char const *argv[])
{
    unsigned char s1[100];
    int n;

    nhapSoPhanTu(&n, s1);
    inSoPhanTu(&n, s1);


    return 0;
}

