// Tách chuỗi "Huynh Minh Thuan"

#include <stdio.h>
#include <string.h>

int main ()
{
    char s1[] = "Huynh Minh Thuan"; // mảng tự động được tính theo chuỗi khởi tạo
    char ho[6];
    char chulot[5];
    char ten[6];

    printf("Huynh -Minh &/Thuan\n");

    // Tách chuỗi s1[] thành chuỗi con, dùng ký tự " " để phân rẽ các chuỗi ->"Huynh" còn lại "Minh Thuan"
    // Tạo con trỏ để lưu địa chỉ chuỗi mình tách, token 

    char *token = strtok(s1," -&/");
    int dem = 0;
    // Tiếp tục tách "Minh Thuan"
    while(token != NULL) // Duyệt đến khi nào chuỗi = NULL thì thoát while
    {   
        if(dem == 0)
            strcpy(ho,token);

        else if (dem == 1)
            strcpy(chulot,token);

        else if (dem == 2)
            strcpy(ten,token);

        dem ++;
        token = strtok(NULL," -&/");
        
    }

    printf("Họ: %s\n",ho);
    printf("Chữ lót: %s\n",chulot);
    printf("Tên: %s\n",ten);

    return 0;
}