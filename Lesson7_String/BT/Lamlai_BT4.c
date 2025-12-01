
#include <stdio.h>
#include <string.h>

void xoaKhoangTrang(int index, char s1[])
{
    for(int i = index;i < strlen(s1);i++)
    {
        s1[i] = s1[i+1];
    }

}

int main()
{   
    char s1[] = "Huynh Minh Thuan lop DH20TD";

    char *str = strstr(s1, " ");

    printf("%s\n",s1);
    while(str != NULL)
    {
        int index = str - s1;
        xoaKhoangTrang(index,s1);

        printf("%s\n",s1);
        str = strstr(s1, " ");
        
    }

    return 0;
}