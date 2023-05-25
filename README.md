# **Compiler**
Quá trình biên dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ máy để máy tính có thể hiểu được. Quá trình này được chia làm 4 giai đoạn:
- **_Giai đoạn tiền xử lý (pre-processor):_** các file _.c/.h_ khi đi qua giai đoạn này sẽ biến thành file _.i_ (preprocessed source). Tại giai đoạn này, sẽ xóa bỏ các comment, xử lý các chỉ thị tiền xử lý, thay thế các đoạn chương trình mà macro định nghĩa.
	-  Cú pháp để thực hiện quá tình tiền xử lý là `gcc -E main.c -o main.i`
- **_Giai đoạn compiler:_** file _.i_ khi qua giai đoạn này sẽ thành _.s_ (Assembly code). Giai đoạn này sẽ chuyển đổi ngôn ngữ C sang ngôn ngữ Assembly.
	-  Cú pháp để thực hiện quá tình tiền xử lý là `gcc main.i -S -o main.s`
- **_Giai đoạn assembler:_** file _.s_ khi qua giai đoạn này sẽ thành _.o_ (object file).
	-  Cú pháp để thực hiện quá tình tiền xử lý là `gcc -c main.s -o main.o`
- **_Giai đoạn linker:_** file _.o_ khi qua giai đoạn này sẽ thành _.exe_ (executable). Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn sẽ được liên kết lại với nhau để tạo thành 1 chương trình có thể thực thi được.

# **Phân vùng nhớ**
-  **_Phân vùng text:_** chỉ đọc data, không chỉnh sửa được. Thường chứa khai báo hằng số. Ví dụ: 
	- Ví dụ: `const a = 10`;
		  `char *arr = "Hello"`;
-  **_Phân vùng data:_**
	-  Có thể đọc hoặc ghi
	-  Chứa biến toàn cục hoặc biến static với giá trị khởi tạo khác 0. Ví dụ: int a = 20; static int b = 12;
	-  Được giải phóng khi kết thúc chương trình
-  **_Phân vùng bss:_**
	-  Có thể đọc hoặc ghi
	-  Chứa biến toàn cục hoặc biến static với giá trị khởi tạo bằng 0 hoặc không khởi tạo. Ví dụ: int a; static int b = 0;
	-  Được giải phóng khi kết thúc chương trình
-  **_Phân vùng stack:_**
	-  Có thể đọc hoặc ghi
	-  Được sử dụng cấp phát cho biến cục bộ, input parameter của hàm, …
	-  Được giải phóng khi thoát ra khởi hàm.
-  **_Phân vùng heap:_**
	-  Có thể đọc hoặc ghi
	-  Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, … (Malloc dùng để khởi tạo 1 mảng bắt đầu, Realloc để thay đổi kích thước của mảng, Calloc khởi tạo 1 mảng bắt đầu với gán giá trị đều bằng 0)
	-  Được giải phóng khi gọi hàm free.
	-  Cấp phát động: ví dụ : `uint8_t *ptr = (uint8_t *)malloc(sizeof(uint8_t) * 5);``arr = (uint8_t *)realloc(arr, sizeof(uint8_t)*8);`

# **Macro - Fuction**
- Macro diễn ra ở quá trình tiền xử lý. thay thế đoạn code vào chỗ xuất hiện các macro đó. Ví dụ ` define MAX = 10`

# **Thao tác bit**
- **_Tìm hiểu về thao tác thường gặp với bit:_** AND, NOT, OR, XOR, dịch bit (gồm dịch trái << và dịch phải >>)
  - AND: giống phép nhân, AND với 0 bằng 0, AND với 1 bằng chính nó.
  - OR: giống phép cộng.
  - XOR: 2 số giống nhau XOR lại bằng 0, khác nhau XOR lại bằng 1.
  - NOT: đảo ngược bit, 1 thành 0, 0 thành 1.
  - Dịch trái <<: dịch các bit theo chiều từ phải sang trái, thêm bit 0 vào bên phải.
  - Dịch phải >>: dịch các bit theo chiều từ trái sang phải, thêm bit 0 vào bên trái.
- **_Áp dụng các thao tác bit làm bài tập:_** 
  -  Hàm Readbyte: Để đọc được 1 byte, ta sẽ kiểm tra từng bit bằng cách lấy từng bit đó AND với 1, sau đó hiển thị lần lượt các kết quả ta sẽ được byte ban đầu muốn đọc.
  -  Set pin lên mức low/high: Với 1 PORT gồm 8 pin, hàm pinHigh có tham số truyền vào là pin muốn set, được thực hiện bằng thao tác OR và dịch bit, dịch bit sẽ giúp ta tìm được chỗ pin muốn set, OR với 1 để set pin dó lên mức HIGH. Tương tự với hàm pinLow, ta sẽ set dùng XOR và dịch bit 128, dịch bit 128 giúp tìm được nơi muốn set, XOR giúp đảo trạng thái và OR lại với nhau
  -  hàm digitalWrite: sẽ giúp ta có thể set bất kì 1 bit nào mong muốn lên mức HIGH hoặc LOW với tham số truyền là Pin (chân pin muôn set)và trạng thái(HIGH/LOW)




