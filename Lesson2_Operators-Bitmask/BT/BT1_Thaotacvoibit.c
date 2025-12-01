#include<stdio.h>
#include<string.h>

int main()
{

    /* Set bit 4 lên 1 */
    unsigned char x = 0b11101110;
    x = x | (1<<4);                  //   OR với Bit 0 0b00000001
    
    //   Tạo bitmask (bit 0)
    //   (1<<4)      0b00010000 OR (|)
    //     x         0b11101110
    //   Kết quả     0b11111110 Bit 4 đã bật 
    printf("%d\n",x);

    /* Clear bit 3 về 0 */
    unsigned char y = 0b11101110;
    y = y & ~(1<<3);                 // AND NOT với bit0 0b00000001
    
    // Tạo bitmask (bit0)
    //    (1<<3)    0b00001000
    //   ~(bit 0)   0b11110111 AND (&)
    //      y       0b11101110
    //   Kết quả    0b11100110 Bit 3 đã tắt
    printf("%d\n",y);


    /* Toggle bit 4(Đảo trạng thái bit 4 )*/
    unsigned char z = 0b11101110;
    z = z ^ (1<<4);                 // XOR với bit0 0b00000001

    // Tạo bitmask (bit0)
    //   (1<<4)    0b00010000
    //      z      0b11101110 XOR (^)
    //      Kq     0b11111110 Bit 4 đã đảo trạng thái 0->1
    printf("%d\n",z);

    /* Check bit 4 */
    unsigned char i = 0b11101110;

    //  Tạo bitmask (bit0)- 0b00000001
    //    (1<<4)   0b00010000  
    //       i     0b11101110 AND (&)
    // -------------------------------
    //       KQ    0b11101110 -> (1<<4) & i, In ra giá trị thập phân 
    //       Để in ra giá trị logic 0|1 -> ((1<<4) & i) != 0

    printf("%d\n",(i & (1<<3)) !=0);
    
    return 0;
}