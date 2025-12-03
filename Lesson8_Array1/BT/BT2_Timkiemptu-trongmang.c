#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_SoPhanTu 100

uint8_t s1[MAX_SoPhanTu] = {0}; // Tạo mảng với all giá trị = 0

int nhapPhanTu(int *n, uint8_t *s1)
{
    printf("Nhập số phần tử mảng: ");
    scanf("%d", n);

    if (*n > MAX_SoPhanTu || *n <= 0)
    {
        printf("Nhập lại đúng yêu cầu!");
        return -1;
    }

    for (int i = 0; i < *n; i++)
    {
        int temp; // biến tạm dùng để kiểm tra trước khi gán vào kiểu uint8_t
        do
        {
            printf("s1[%d] = ",i);
            scanf("%d", &temp);

            // if (temp < 0 || temp > 255)
            //      printf("Giá trị phải nằm trong phạm vi 0–255! Nhập lại.\n");
            if (temp < 0 || temp > 255)
                printf("Vượt ngưỡng giá trị (0-255), vui lòng nhập lại!\n");
        } while (temp < 0 || temp > 255); 
        // Nếu nhập vượt ngưỡng thì tiếp tục lặp lại vòng lặp -> nhập lại
        // Nhập đúng -> thực thi theo điều kiện for -> thoát 
        
        s1[i] = (uint8_t)temp;  // ép kiểu để đảm bảo kết quả in ra an toàn
    }
    printf("------------------------------\n");

    return 0; // Vì đây là hàm nhập, nên k có kết quả để trả 
}

void timPhanTu(int *n, int *var, uint8_t *s1)
{   
    printf("Tìm giá trị: ");
    scanf("%d", var);

    for (int i = 0; i < *n; i++)
    {
        if (s1[i] == *var)
        {
            printf("Tìm thấy giá trị: %d, vị trí %d của mảng", *var, i);
        }
        
    }

}

int main(int argc, char const *argv[])
{
    int n, var;

    if(nhapPhanTu(&n, s1) == -1)
        return 0;
    
    timPhanTu(&n, &var, s1);
    

    return 0;
}

