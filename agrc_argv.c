#include <stdio.h>

/**
 * @brief   Mô tả ngắn gọn về hàm, biến, lớp… (1-2 dòng)
 * 
 * @param   Tên_tham_số  Giải thích tham số của hàm
 *           (nếu hàm có nhiều tham số, lặp lại @param cho từng tham số)
 * 
 * @return  Giá trị trả về
 * 
 * @details Mô tả chi tiết hơn về chức năng, cơ chế, thuật toán hoặc cách hoạt động
 *          của hàm/biến/lớp. Có thể dài hơn, nhiều dòng.
 * 
 * @note    Thông tin quan trọng, cảnh báo, lưu ý khi sử dụng hàm/biến/lớp.
 */


/**
 * @brief Tham số dòng lệnh của hàm main.
 *
 * @param argc Số lượng tham số dòng lệnh truyền vào chương trình.
 *             Luôn >= 1, vì argv[0] chứa tên chương trình.
 * @param argv Mảng các chuỗi chứa từng tham số dòng lệnh.
 *             argv[0] là tên chương trình, argv[1] là tham số đầu tiên, ...
 * 
 * @return 0
 *
 * @details
 * Cơ chế này cho phép điều khiển chương trình từ bên ngoài thông Command Terminal, tương tự
 * trên cả Windows và Linux. Thường dùng nhiều trên Linux nhờ môi trường terminal mạnh.
 *
 * @note
 * - Luôn kiểm tra argc trước khi truy cập argv[i] để tránh truy xuất ngoài phạm vi.
 * - Ứng dụng phổ biến: truyền dữ liệu, chọn chế độ chạy, mở file, xử lý batch/script.
 */


int main(int argc, char *argv[])
{
    printf("argc = %d\n", argc);
    printf("argv[0] = %s\n", argv[0]);
    
    if (argc > 1)
        printf("argv[1] = %s\n", argv[1]);

    return 0;
}
