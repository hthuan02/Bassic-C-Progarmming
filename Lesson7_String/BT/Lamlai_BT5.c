/**
 *  Nhập 1 chuỗi và đếm số lần xuất hiện của 1 ký tự đc nhập từ bàn phím.
 */

#include <stdio.h>
#include <string.h>

void nhapChuoi(char s1[], int size)
{
    printf("Nhập chuỗi:");
    fgets(s1,size,stdin);
    s1[strcspn(s1, "\n")] = '\0';
}

char timKyTu()
{
    char ch;
    printf("Tìm ký tự: ");
    scanf("%c",&ch);

    return ch;
}

int soLan_XuatHien(char s1[], char KyTu)
{
    int index = 0;
    for(int i = index;i < strlen(s1);i++)
    {
        if(s1[i] == KyTu)
            index++;
    }
    
    return index;
}

int main()
{   
    char s1[100];
    char KyTu, SoLan;

    nhapChuoi(s1,sizeof(s1));

    KyTu = timKyTu();
    SoLan = soLan_XuatHien(s1,KyTu);
    printf("Ký tự '%c', xuất hiện %d lần\n", KyTu, SoLan);

    return 0;
}