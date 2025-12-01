#include <stdio.h>
#include <string.h>

void nhapChuoi(char s1[], int size)
{
    printf("Nhập chuỗi:\n");
    fgets(s1, size, stdin);       // sizeof không dùng được, truyên kích thước từ ngoài vào
    s1[strcspn(s1, "\n")] = '\0';
}

int main()
{   
    char s1[100];
    nhapChuoi(s1, sizeof(s1));

    return 0;
}
