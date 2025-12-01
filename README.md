# Roadmap to Learning C Programming
---

<details>
  <summary><h3>Lesson 1: Basics of C Progamming  </h3></summary>

## 1. IDE, Text Editor, Complier ?

-> Quá trình Complier?

## 2. Byte & Bit

## 3. Kiểu dữ liệu

> Kiểu dữ liệu 1 biến xác định kích thước số byte của biến đó.
>
> Giúp xác định giá trị 1 biến có thể nhận hoặc giá trị 1 hàm có thể trả về.

### 3.1 Kiểu số nguyên 

| Type           | Kích thước (byte) | Phạm vi giá trị                                         |
|----------------|-------------------|----------------------------------------------------------|
| `char`         | 1                 | -128 tới 127                                             |
| `unsigned char`| 1                 | 0 tới 255                                                |
| `int`          | 2 or 4            | -32,768 tới 32,767 hoặc -2,147,483,648 tới 2,147,483,647 |
| `unsigned int` | 2 or 4            | 0 tới 65,535 hoặc 0 tới 4,294,967,295                    |
| `short`        | 2                 | -32,768 tới 32,767                                       |
| `long`         | 8 bytes           | -9223372036854775808 tới 9223372036854775807            |
| `unsigned long`| 8 bytes           | 0 tới 18,446,744,073,709,551,615                         |


### 3.2 Kiểu số thực

| Type    | Kích thước (byte) | Phạm vi giá trị                          |
|---------|-------------------|------------------------------------------|
| `float` | 4                 | Chính xác tới 6 chữ số thập phân         |
| `double`| 8                 | Chính xác tới 10 chữ số thập phân        |

### 3.3 Kiểu kí tự

| Type           | Kích thước (byte) | Phạm vi giá trị     |
|----------------|-------------------|----------------------|
| `char`         | 1                 | -128 to 127          |
| `unsigned char`| 1                 | 0 to 255             |

### 3.4 Kiểu void

> Là kiểu k có giá trị, kiểu k trả về.

> Không dùng kiểu `void` khai báo biến, mà dùng `void` khai báo hàm.

- Kiểu trả về
```c
    #include <stdio.h>

    int main()
    {
        const char x = 300;
        printf("%d", x);
        return 0;
    }
```

- Kiểu không trả về

```c
    #include <stdio.h>

    void main()
    {
        const char x = 300;
        printf("%d", x);
    }
```

## 4. Bảng mã ASCII

> Là bảng mã hóa trao đổi thông tin theo chuẩn Hoa Kỳ.
>
> Sử dụng 7 bit nhị phân (0 đến 127) dùng biểu diễn thông tin ký tự.

## 5. Định dạng trong C

`%c`  : Ký tự đơn

`%hhu`: Số nguyên không dấu, 1 byte (unsigned char)

`%hd` : Số nguyên có dâu, 2 byte  (short),

`%s`  : Chuỗi

`%d`  : Số nguyên có dấu, 4 byte (int)

`%f`  : Số thực, (VD: 6.33) float

`%lf` : Số thực dài, (VD: 6.3314141414) double

`%ld` : Sử dụng cho long

`%x`  : Số nguyên hex không dấu (VD: 0xAB)

```c
    #include <stdio.h>

    void main()
    {
        unsigned char a = 18;
        float b = 22.6;
        char c = 'B';
        int d = 3333;
        unsigned char e = 0xAB;
        char str[] = "deviot.vn";

        printf("%d\n", a);     // In số nguyên unsigned char
        printf("%.1f\n", b);   // In số thực với 1 chữ số thập phân
        printf("%c\n", c);     // In ký tự
        printf("%d\n", d);     // In số nguyên int
        printf("%x\n", e);     // In số hex không dấu
        printf("%s\n", str);   // In chuỗi
    }
```
## 6. Biến (cơ bản)

> Biến là thông tin được lưu trữ trên RAM.
>
> Trong quá trình chạy chương trình thì có thể thay đổi được -> gọi là biến số.
>
> Khai báo biến mà không khởi tạo, địa chỉ sẽ = 0 hoặc địa chỉ rác.

3 đặc trưng của biến:

- Kiểu dữ liệu

- Địa chỉ trên RAM

- Giá trị của biến

## 7. Hằng

> Là 1 biến không được thay đổi giá trị trong quá trình chạy.
>
> Khai báo bằng luôn luôn đi kèm khởi tạo giá trị.



```c
    #include<stdio.h>

    const int MAX = 100; // Hằng là biến toàn cục: .rodata (vùng nhớ chỉ đọc-vùng nhớ hằng) ->  trên PC
                                            //     Lưu ở ROM/Flash -> đối vs MCU
   
    void cong2so()
    {
        
        // Hằng là biến cục bộ -> Lưu ở thường là stack hoặc không nằm trong đâu hết
        //                     -> KHÔNG BAO GIỜ nằm trong .rodata, chỉ hằng toàn cục hoặc static const mới nằm .rodata.

        const float PI = 3.14; // Giá trị biết trước            // Không lưu ở stack hay .rodata -> Biên dịch ra mã máy luôn, vì đây là giá trị biết trước
        
        const float x = n +1;  // Giá trị biết khi chạy hàm     // Stack 100%
    }

    int main()
    {
        return 0;
    }
```

#### Thay đổi giá trị của biến hằng số bằng con trỏ được không?

`Con trỏ` lưu ở RAM, mà `biến hằng số` có 2 dạng: Toàn cục và cục bộ.

- Con trỏ -> Lưu vào địa chỉ trong vùng nhớ trên RAM.

- Hằng số là biến toàn cục  -> `.rodata` trên PC hoặc `Flash/ROM` trên MCU.

- Hằng số là biến cục bộ có 2 dạng

    - Giá trị biết trước(compile-time) `const float PI = 3.14;` -> Không lưu ở đâu hết -> Biên dịch ra mã máy luôn.

    - Giá trị biết khi chạy hàm(run-time) `const float x = n + 1;;` -> Stack trên RAM 100%.

=> Trên PC: Có thể thay đổi được nhưng in kết quả không đảm bảo, không an toàn (undefined behavior - hành vi không xác định).

=> Trên MCU: Crash chương trình, nguy hiểm.

## 8. Macro

> Macro những từ chỉ thông tin xử lý ở quá trình tiền xử lý do lập trình viên tự đặt ra, lấy khối lệnh ở phía sau thay thế văn bản được định nghĩa ở phía trước

```c
    #define PI 3.14
```

#### Interview1: Macro & Constant, Fuction khác nhau như thế nào?

`Macro`

- Không có biến thực sự, câu lệnh ở sau thay cho text ở trước, ở giai đoạn tiền xử lý.

- Tốc độ thực thi nhanh, trên PC macro không tốn bộ nhớ RAM. Nhưng trên MCU macro tốn bộ nhớ Flash vì thực thi chương trình nhiều lần -> copy code nhiều lần.

- Biến mất sau preprocessor, khó debug.

`Const`: 

- Là biến hằng số được khai báo, có kiểu dữ liệu.

- Có có tên biến cụ thể, dễ debug khi phát lỗi.

- Tiêu tốn bộ nhớ, tốc độ truy xuất: 
    
Hằng số là biến toàn cục: Nằm ở vùng nhớ hằng .rodata trên RAM(read-only)-> Tốc độ chậm hơn macro

Hằng số là biến cục bộ:

    - Có giá trị run-time hoặc biến cục bộ có giá trị compile-time có sử dụng `&` truy cập địa chỉ -> Lưu ở Stack trên RAM, tốc độ truy xuất chậm hơn macro.

    - Hằng số là biến cục bộ có giá trị complie-time không được sử dụng `&` truy cập địa chỉ -> Không lưu ở bộ nhớ nào hết,biên dịch thẳng ra mã máy và tốc độ truy xuất xấp xỉ macro.

`Function`

- Hàm được biên dịch thành mã máy và tồn tại trong phân vùng text/code segment -> Không ảnh hưởng bộ nhớ RAM, nhưng tốn nhớ Flash/ROM (đối với MCU).

- Biến được khai báo trong hàm là biến cục bộ lưu ở phân vùng Stack của bộ nhớ RAM - Stack Frame (Nếu có static thì lưu data segment).

- Tốc độ thực thi chương trình chậm hơn macro, vì hàm cần thực hiện tác vụ phụ khi gọi hàm (Overhead call) gồm: push (đẩy tham số lên), jump (nhảy đến địa chỉ hàm), tạo stack frame, return (trả về). 


data segment: khởi tạo giá trị

bss segment: chưa khởi tạo giá trị

#### inline???(Tìm hiểu inline, mảng vs chuỗi về phân  nha!)

## 9. PRINTF, SCANF, GETS

### 9.1 PRINTF

### 9.2 SCANF

### 9.3 GETS -> FGETS

> Là lệnh dùng để nhập vào 1 chuỗi, và **cho phép** nhập có khoảng trắng.

#### NHƯNG VẤN ĐỀ LÀ: tiêu chuẩn của VSCode hiện nay, hàm `gets` đã bị loại bỏ khỏi C11

-> Đổi hàm `gets()` -> `fgets()`

`scanf()` không coi `ENTER` là kí tự nhập vào. Nhưng ở `fgets()` thì ngược lại, vì vậy cần loại bỏ `ENTER` gây ra `\n`


```c
    #include <stdio.h>
    #include <string.h>  

    int main()
    {
        char ten[30];

        printf("Nhap ten: ");
        
        // strcspn(ten, "\n") tìm vị trí của ký tự \n.
        // fgets(<tên mảng>,<kích thước>, stdin)

        fgets(ten, sizeof(ten), stdin);  

        // <tên mảng>[strcspn(<tên mảng>, "\n")]
        // Xóa `\n`
        ten[strcspn(ten, "\n")] = '\0';  

        printf("Ten: %s\n", ten);

        return 0;
    }
```
</details>

<details>
  <summary><h3>Lesson 2: Operators & Bitmask  </h3></summary>

Các toán tử trong C:

`+`
`-`
`*`
`/`
`%`
## 1. Toán tử tăng giảm

Toán tử tăng:

- `x++`: Thực hiện lệnh trước, tăng giá trị sau.

- `++x`: Tăng giá trị trước, thực hiện lệnh sau.

Toán tử giảm:

- `y--`: Thực hiện lệnh trước, giảm giá trị sau.

- `--y`: Giảm giá trị trước, thực hiện lệnh sau.

## 2. Toán tử quan hệ

`==`

`!=`

`<`

`<=`

`>`

`>=`

## 3. Toán tử logic

`&&`: AND

`||`: OR

`!`: NOT

## 4. Toán tử thao tác với Bit

`|`: 

`&`: AND

`~`: NOT

`^`: X-OR (0 vs 1 = 1)

`<<`: Shift Left

`>>`: Shift Right

</details>

<details>
  <summary><h3>Lesson 3: Control Structures </h3></summary>

<details>
  <summary><h2>I. Conditional Statements </h2></summary>

## 1. Điều kiện if else

- `if`

- `if ... else`

- `if ... else if ... else`

## 2. Toán tử 3 ngôi

`bieuthuc_1 ? bieuthuc_2: bieuthuc_3;`

- Dạng viết tắt của if else

- Kiểm tra `bieuthuc_1` đúng hay sai? Nếu đúng thì gán giá trị cho `bieuthuc_2`. Nếu sai gán giá trị cho `bieuthuc_3`.

```c
    #include<stdio.h>

    int main ()
    {
        int a = 10, b = 1, max;
        max = (a>b)? a:b;

        // In ra số lớn nhất
        printf("Max = %d\n",max);

        return 0;
    }
```
## 3. Switch case 

> Cấu trúc rẽ nhánh dùng để chọn 1 trong nhiều trường hợp khác nhau.

- `expession`có thể là biểu thức bắt buộc kết quả hằng và được so sánh với các `case`.

- `case` nào có giá trị tương ứng thì sẽ thực thi case đó cho đến khi gặp `break` để thoát.

- Nếu không có `case` nào tương ứng, thì thực hiện case `default`.

```c
switch(expression)
{
    case const1;
        // Câu lệnh 1
        break;
    
    case const2;
        // Câu lệnh 2
        break;
    .
    .
    .
    default:
        // Câu lệnh default

}
```

</details>


<details>
  <summary><h2>II. Loops </></summary>

## 1. For 

> Sử dụng khi biết trước số lần lặp

```c
    for(khởi tạo giá trị; điều kiện; cập nhật biến)
    {
        // Các lệnh cần 
    }
```

`flowchart`: Khởi tạo -> Kiểm tra điều kiện -> Thực hiện nội dung lặp -> Cập nhật biến lặp.

## 2. While

> Sử dụng khi không  biết trước số lần lặp

```c
    while (Expression)
    {
        // Code
        // Tự thêm biến đếm tăng-giảm giá trị
    }
    // Nếu để biến đếm ở phía trước while, i = 0
    // Nếu để biến đếm ở phía sau while, i = 1

```
`flowchart`: Express đúng (!=0) tiếp tục lặp, Expression sai(==0) thoát vòng lặp.

### Từ khóa `continue`

> Nếu vòng lặp đang chạy mà gặp từ khóa `continue`, thì sẽ bỏ qua các lệnh dưới `continue` ở vòng lặp hiện tại. Và chương trình sẽ tiếp tục thực thi lại vòng lặp lần tiếp theo.

```c
    // In 1->10 trừ số 3,7,9

    #include <stdio.h>

    int main()
    {
        for(int i = 1; i<=10; i++)
        {
            if(i == 3){
                continue;
            }

            else if(i == 7){
                continue;
            }
            
            else if(i == 9){
                continue;
            }
            printf("%d\n",i);
        }
    }
```
### Từ khóa `break`

> Nếu chương trình trong vòng lặp đang chạy gặp `break` thì nó thoát ra khỏi vòng.

```c
    // in ra số chẵn 1-> 100, tới số 10 thì break
    #include<stdio.h>

    int main ()
    {
        int i =0;
        while (i <= 100)
        {   
            i++;
            if(i%2!=0){
                continue;
            }
            if(i>10){
                break;
            }

            printf("%d\n",i);
            
        }
    }
```

### Flag

> Flag là cờ được xem như biến tạm, để ghi nhớ trạng thái True/False (0 1). Thường áp dụng "biến tạm" để kiểm tra giá trị, kiểm tra điều kiện.

```c
#include<stdbool.h>
int main() 
{
    /*code*/
    bool laSNT = true;
}
```

</details>

</details>

<details>
  <summary><h3>Lesson 4: Local Variables, Global Variables, Static  </h3></summary>

## I. Local variables
(Biến cục bộ)

> Được khai báo trong 1 hàm.
>
> Cấp phát vào vùng nhớ `Stack` trên RAM. 
>
> Tồn tại và được sử dụng trong hàm, bị giải phóng khi thoát khỏi hàm.

```c
    #include<stdio.h>

    int main()
    {
        int x = 10;

        return 0;
    }
```

## II. Global variables
(Biến toàn cục)

> Được khai báo bên ngoài tất cả hàm.
>
> Cấp phát vào vùng nhớ `Data segment` trên RAM. 
>
> Tồn tại trong suốt quá trình chạy chương trình.

```c
    #include<stdio.h>

    int x = 10;

    int main()
    {
        return 0;
    }
```
## III. Static variables

### 1. Static với biến cục bộ (C-advance)

> Được khởi tạo 1 lần duy nhất trong cả chương trình.
>
> Phạm vi sử dụng bên trong 1 hàm khai .
>
> Giá trị/Vùng  được giữ lại sau khi thoát khỏi hàm (lưu vào `Data segment`), địa chỉ tồn tại xuyên suốt chương trình.

```c
    #include <stdio.h>

    int in_so_thu_tu(void)
    {
        static int x = 0;
        x = x + 1;
        printf("%d\r\n", x);
    }

    int main() {
        in_so_thu_tu(); // 0
        in_so_thu_tu(); // 1
        in_so_thu_tu(); // 2
        in_so_thu_tu(); // 3 
        in_so_thu_tu(); // 4
        return 0;
    }
```
- Ứng dụng: Lọc nhiễu, Blink 

### 2. Static với biến toàn cục (C-advance)

> Phạm vi sử dụng bên ngoài tất cả hàm.
>
> Khóa cái biến toàn cục đó lại chỉ được sử dụng trong File khai báo, các File khác không thể truy cập (Không thể dùng từ khóa `extern` gọi ra được, không thể liên kết File).

- Ứng dụng: Thiết kế thư viện, ẩn đi quá trình trung gian tính ra kết 

### 3. Static trong khai báo hàm

> Chỉ sử dụng trong File khai báo nó, các File khác không thể truy cập (giống static toàn cục)


</details>

<details>
  <summary><h3>Lesson 5: Fuction in C  </h3></summary>

## I. Hàm là gì?

> Nhóm những khối lệnh cùng thực hiện những chức năng vào 1 hàm riêng biệt, phân biệt hàm thông qua tên hàm. 

Hàm có 2 kiểu:

- Hàm tự định nghĩa.

- Hàm được định nghĩa sẳn trong library C.

```c
    <Kiểu dữ liệu trả về> <Tên hàm> ( <Tham số nếu có> )
    {
        // Code
        // ...

        <return Giá trị trả về nếu có>
    }
```

`Tên hàm thể hiện chức năng của hàm`

## 1. Hàm không có giá trị trả về (return void)

```c
    // Hàm không có tham số, không có giá trị trả về
    void hello(void)
    {
        printf("Hello world");
    }
```

```c
    // Hàm có tham số, không có giá trị trả về
    void add(int a, int b)
    {
        printf("%d + %d = %d", a, b, a + b);
    }
```

- void không truyền tham số & void truyền tham số (không có trả về)

## 2. Hàm có giá trị trả về (return <....>)

```c
    // Hàm không có tham số, có giá trị trả về
    int add(void)
    {
        int a;
        return a;
    }
```

```c
    // Hàm có tham số, có giá trị trả về
    int add(int a, int b)
    {
        return a+b;
    }
```
- int không truyền tham số & int truyền tham số (có trả về)
<details>
  <summary><h2>VD1: Hàm không trả về không truyền tham số, hàm có trả về không truyền tham số/h2></summary>

```c
    #include <stdio.h>

    void nhapten(void)
    {
        char ten[30];
        printf("Nhập tên: ");
        scanf("%s",ten);
        printf("Tên: %s\n",ten);
    }

    int nhaptuoi(void)
    {
        int tuoi;
        printf("Nhập tuổi: ");
        scanf("%d",&tuoi);
        return tuoi; // return về cái biến mình khởi tạo, giá trị trả về 1 số, thoát khỏi hàm là bị cấp thoát
    }

    int main ()
    {   
        int tuoithucte; // tạo biến tuoithucte, để gán giá trị return
        nhapten();
        tuoithucte = nhaptuoi(); 
        printf("Tuổi: %d\n",tuoithucte);
        
        return 0;
    }
```
</details>

<details>
  <summary><h2>VD2: Hàm không trả về, có truyền tham số</h2></summary>

Hàm có `return` thì ở `main()` phải tạo 1 biến trung gian gán giá trị `return`. Nếu gọi hàm trực tiếp mà không gán giá trị thì `return` sẽ bị bỏ đi -> return vô nghĩa.

```c
    // Hàm không trả về
    #include <stdio.h>

    void tong3soTN(int a, int b, int c)
    {
        int result;
        result = a + b + c;
        printf("Tổng 3 số: %d + %d + %d = %d\n",a,b,c,result);
    }

    int main ()
    {   
        tong3soTN(1,2,3); // 2 hàm này địa chỉ hoàn toàn khác 
        tong3soTN(4,5,6);
        return 0;
    }
```
</details>

<details>
  <summary><h2>VD3: Hàm có kiểu dữ liệu trả về, có truyền tham số</h2></summary>

```c
    // Hàm có trả về
    #include <stdio.h>

    int tong3soTN(int a, int b, int c)
    {
        int result;
        result = a + b + c;
        return result;
    }

    int main ()
    {   
        int res; // Khởi tạo biến gán giá trị return
        res = tong3soTN(1,2,3);
        
        printf("Tổng 3 số: %d + %d + %d = %d\n",1,2,3,res);
        return 0;
    }
```
</details>

</details>

<details>
  <summary><h3>Lesson 6: Pass by Value, Pass by Reference   </h3></summary>

## I. Pass by Value (Truyền tham trị)
(Truyền vào 1 giá trị)

- **Truyền giá trị** của biến vào hàm.

- Trong hàm, biến mới được tạo **có địa chỉ khác** với biến gốc.

- Nếu thay đổi giá trị biến mới trong hàm, **biến gốc ngoài hàm không bị ảnh hưởng**. 

```c
    #include<stdio.h>
    #include<stdlib.h>

    void giam1donvi(int var) // var = 100
    {
        var = var - 1;  // var = 99 // 0xe5 0xe6 0xe7 0xe8
    }// rời khỏi hàm, biến var bị cấp thoát địa chỉ, giá trị bị mất

    int main()
    {
        int x = 100; // 0x00 0x01 0x02 0x03
        printf("Trước: x = %d\n",x); // 100
        giam1donvi(x); 
        printf("Sau: x = %d\n",x); // 100

        return 0;
    }
```

- Để thay đổi được thì phải truyền địa chỉ của biến x -> Truyền tham chiếu 

## II. Pass by Reference (Truyền tham chiếu)
(Truyền vào 1 địa chỉ)

- **Truyền địa chỉ** ô nhớ của biến vào hàm.

- Nếu thay đổi giá trị của biến trong hàm, thì **biến gốc bên ngoài cũng thay đổi**.

```c
    #include<stdio.h>
    #include<stdlib.h>

    void giam1donvi(int *var) // var = 100
    {
        *var = *var - 1;  // var = 99 // 0x00 0x01 0x02 0x3
        // var: địa chỉ truyền vào
        // *var: giá trị tại vùng địa chỉ truyền vào
    }
    int main()
    {
        int x = 100; // 0x00 0x02 0x03 0x03
        printf("Trước: x = %d\n",x); // 100
        giam1donvi(&x); 
        // &x: truyền vùng địa chỉ của x  
        // x: truyền giá trị của x
        printf("Sau: x = %d\n",x); // 99

        return 0;
    }
```
</details>

<details>
  <summary><h3>Lesson 7: String </h3></summary>

# I. String(Chuỗi)

> Chuỗi là tập hợp các ký tự (char) được lưu trữ trên các ô nhớ liên tiếp, luôn có 1 ký tự `null`(`\0`) để báo hiệu kết thúc chuỗi.

Có 2 cách khai báo chuỗi: {V i e t N a m \0}

- C1: Dùng con trỏ kiểu char

`char *x = "VietNam";`

```c
#include <stdio.h>

int main ()
{
    char *x = "VietNam";

    /**
     *  Bời vì chuỗi "VietNam" lưu ở vùng nhớ hằng (.rodata) 
     *  -> Không thể thay đổi giá trị chuỗi trực tiếp, phải trung gian qua địa chỉ con trỏ
     * 
     *  - Chuỗi "VietNam"                // 0x08
     *  - Con trỏ `*x` sẽ trỏ đến lưu địa chỉ 0x08
     * 
     *  - Thay bằng chuỗi mới "ABC"      // 0x04
     *  - Con trỏ `*x`  0x08  -> 0x04 
     *  => "ABC"
     */ 

    x = "ABC";          
    printf("%s",x);     
    return 0;
}
```

- C2: Mảng ký tự
`char y[] = "VietNam";`

```c
#include <stdio.h>

int main ()
{
    char y[] = "VietNam"; 
    
    /**
     *  Vì cả chuỗi "VietNam" và mảng lưu ở stack nên thay vào trực tiếp luôn
     */
    y[0] = 'A';
    y[1] = 'B';
    y[2] = 'C';
    y[3] = 0; // hoặc '\0'
    printf("%s",x);
    return 0;
}
```

#### So sánh khai báo chuỗi bằng con trỏ char & khai báo chuỗi bằng mảng có gì khác nhau?

**Khai báo chuỗi bằng con trỏ kiểu char**

- Giá trị của chuỗi lưu ở vùng nhớ hằng(.rodata) không thể thay đổi giá trị được.

- Chỉ có thể dùng con trỏ để trỏ đến địa chỉ của chuỗi khác, hoàn toàn không thể thay đổi từng giá trị của chuỗi.
 -> Có thể lỗi nếu cố gắng ghi đè. 

**Khai báo chuỗi bằng mảng**

- Giá trị của chuỗi lưu ở stack(biến cục bộ), data(biến toàn cục) -> lưu trong RAM(ghi/đọc). Nên dễ dàng thay đổi từng phần tử của chuỗi.

## II. Thao tác với chuỗi

- Hàm `strlen`: tính độ dài 1 chuỗi(đếm từ phần tử đầu đến khi gặp phần tử kết thúc chuỗi `\0`).

```c
    int strlen(const char *str);
    // hoặc
    int strlen(char s[]);
```

```c
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char s[] = "Thuan";
        // char[]: kích thước tự động tính theo chuỗi khởi tạo

        int dodai = strlen(s);
        
        printf("Độ dài chuỗi là: %d",dodai);
        return 0;
    }
```

- Hàm `strcmp`: Dùng để so sánh **độ lớn/giá trị** 2 chuỗi str1 và str1

```c
    int strcmp(const char *str1, const char *str2);
```

```c
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char s1[] = "Thuan"; 
        char s2[] = "thuan";
        int sosanh = strcmp(s1,s2);
        
        if (sosanh > 0)
            printf("s1 > s2\n");
        
        else if (sosanh < 0)
            printf("s1 < s2\n");

        else 
            printf("s1 = s2\n");    


        return 0;
    }
```

**Ứng dụng:** Truyền dữ liệu trong IoT

- Hàm `strcpy`: Hàm dùng để **ghi đè** giá trị của chuỗi nguồn vào chuỗi đích. Chuỗi đích phải có kích thước đủ lớn để không bị tràn dữ liệu.


```c
    char *strcpy(char *dest,  const char *src);
```
`dest`: là con trỏ trỏ tới mảng chứa chuỗi vừa được sao chép

`src`: Chuỗi để được sao chép.

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "Thuan";
    char s2[] = "123456789"; // char[]: kích thước tự động tính theo chuỗi khởi tạo
    char s3[7] ="Huynh";
    char s4[] = ".vn";


    strcpy(s1,s2);
    strcpy(&s3[5],s4);
    
    printf("%s\n",s1); // 123456789
    printf("%s\n",s3); // Huynh.vn

    return 0;
}
```

#### Interview2: Copy chuỗi "abc" của mảng vào chuỗi "Thuan" của con trỏ được hay không?

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char *ten = "Thuan";
    char s2[] = "123";

    strcpy(s1,s2);
    
    printf("%s\n",s1);


    return 0;
}
```

-> Không được, vì chuỗi `"Thuan"` lưu ở vùng nhớ hằng(.rodata) RAM(chỉ đọc). Không thể lấy mảng `s2[] = "123"` ghi đè lên được.
    
    - Còn nếu `char ten[]` là mảng kí tự, thì thoải mái ghi đè, đảm bảo kích thước đủ lớn để không bị chuỗi nguồn ghi đè làm tràn dữ liệu.

- Hàm `strcat` dùng để **nối** chuỗi nguồn vào phần tử cuối(đuôi) của chuỗi đích.

```c
    char *strcat(char *dest, const char *scr);
```

```c
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char s1[] = "Thuan"; //char[]: kích thước tự động tính theo chuỗi khởi tạo
        char s2[] = "123";

        strcat(s1,s2);
        
        printf("%s\n",s1); //Thuan123


        return 0;
    }
```

- Hàm `strstr` là hàm tìm chuỗi s2 trong s1, và trả về địa chỉ của s2 trong s1.

```c
    char *strstr(const char *s1, const char *s2); 
```


```c
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char s1[] = "Huynh Minh Thuan hoc lop DH20TD ne!";
        char s2[] = "20TD"; //s1[], s2[] Kích thước của mảng tự động đc tính theo chuỗi được khai báo

        // Tìm vị trí của chuỗi"20TD" của s2 trong s1
        char *str = strstr(s1,s2); // trả về địa chỉ của chuỗi s2 trong s1

        printf("%c\n",s1[27]);

        if(str) // hoặc if(str != NULL)
        {
            printf("Đã tìm thấy chuỗi %s, địa chỉ %p\n",s2,str);
            // s2 là địa chỉ gốc (%s)
            // str là địa chị của s2 trong s1(%p)

            printf("Tại vị trí: %d\n",str-s1); 
            // str địa chỉ sau
            // s1 địa chỉ đầu tiên
        }
        else 
        {
            printf("Không tìm thấy!.");
        }

        return 0;
    }
```

- Hàm `strtok` là hàm **tách** chuỗi dài thành các chuỗi nhỏ, dựa vào các ký tự đặc biệt để phân rẽ chuỗi.












































































```c
#include <stdio.h>

int a;               // bss, biến toàn cục chưa khởi tạo

int b = 0;           // data, biến toàn cục đã khởi tạo

const int c = 1;     // .rodata(vùng nhớ hằng) RAM(read0-only)

char *hehe = "ABC";  // con trỏ data, chuỗi .rodata(vùng nhớ hằng)

char *data = x +1    // data (có khởi tạo = x+1)

char *bss;           // bss (chưa khởi tạo)

char *ten2 = NULL;   // con trỏ data(có khởi tạo null), NULL không nằm ở vùng nhớ nào khác

char ten3[] = {0};  // data segment(mảng có khởi giá trị = 0)

char ten4[] = "";   // data segment (chuỗi có 1 giá trị kết thúc `\0`)

char *ten5 =  ""; // con trỏ data, chuỗi .rodata

// hàm void -> text segment -> biên dịch ra mã máy
void hehe(int a, int b) 
{

    int x;               //stack, biến cục bộ

    static int y;                // bss, static với biến cục bộ-chưa khởi tạo

    static int c = 0;            // data, static với biến cục bộ-đã khởi tạo

    const int c = 1;         // khi được truy cập địa chỉ `&` -> stack
                             // khi không truy cập địa chỉ `&` là giá trị compile-time -> không lưu vào đâu hết.


    const int d = c + 1;     // stack (run-time)
}

int main()
{   
    char *ten = "ABC";      // con trỏ stack, chuỗi .rodata(vùng nhớ hằng)

    char ten1[] = "ABC";     // Stack
    return 0;
}

```




















</details>