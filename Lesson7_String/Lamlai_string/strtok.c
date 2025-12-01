#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "Thuan hoc lop DH20TD, truong Nong Lam Tp.HCM ne!"; // kích thước tự động được tính theo chuỗi được khai báo
    char ten[21];
    char truong[23];
    int dem = 0;
    
    char *token = strtok(s1, " ,");
    // printf("%s\n",token);

    while(token != NULL)
    {
        if(dem == 0)    
            strcpy(ten, token);

        else if(dem == 3)    
            strcpy(truong, token);

        
        dem++;
        token = strtok(NULL, " ,");
        // printf("%s\n",token);

    }

    printf("%s\n",ten);
    printf("%s\n",truong);

    return 0;
}