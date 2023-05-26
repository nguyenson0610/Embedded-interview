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
	- Ví dụ: `const int a = 10`;
		  `char *arr = "Hello"`;
-  **_Phân vùng data:_**
	-  Có thể đọc hoặc ghi
	-  Chứa biến toàn cục hoặc biến static với giá trị khởi tạo khác 0. Ví dụ: int a = 20; static int b = 12;
	-  Được giải phóng khi kết thúc chương trình
-  **_Phân vùng bss:_**
	-  Có thể đọc hoặc ghi
	-  Chứa biến toàn cục hoặc biến static với giá trị khởi tạo bằng 0 hoặc không khởi tạo. Ví dụ: `int a;` `static int b = 0;`
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
- **_Macro:_** diễn ra ở quá trình tiền xử lý. thay thế đoạn code vào chỗ xuất hiện các macro đó.
	-  Ví dụ `define MAX = 10`
- **_Inline:_** được xử lý bởi compiler. Khi chạy chương trình thấy inline function, nó sẽ thay thế function đó thành mã máy đã được compiler.
	- Ví dụ 
		```C
		inline void hello(){
   			 printf("hello");
		}
		```
- **_Function:_**: khi thấy hàm được gọi, compiler sẽ lưu địa chỉ tiếp theo của program counter đang đếm vào stack pointer, sau đó sẽ trở program counter đến địa chỉ hàm được gọi để thực hiện, khi thực hiện xong hàm đó và lấy kết quả trả về, program counter sẽ lấy địa chỉ lưu trong stack và tiếp tục thực hiện chương trình.
- **_So sánh Macro, Inline, Function:_**:
	- Macro: thay thế đoạn code marco vào chỗ được gọi trước khi compiler, marco khiến code dài hơn nhưng thời gian chạy nhanh hơn.
	- Inline: thay thế đoạn code inline đã được compiler vào chỗ được gọi, inline khiến code dài hơn, giảm thời gian chạy chương trình.
	- Function: tốn thời gian hơn inline, nhưng code ngắn gọn hơn.

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
# **Struct - Union**
- **_Struct:_** là kiểu dữ liệu do người dùng tự định nghĩa, dữ liệu của các member sẽ được lưu trữ ở các vùng nhớ khác nhau. Do đó, kích thước của 1 struct sẽ bằng tổng kích thước của các member và bộ nhớ đệm.
	- Ví dụ:
	```C
	static typeDate
	{
		int ngay;
		int thang;
		int nam;
	}
	```
- **_Union:_** là kiểu dữ liệu do người dùng tự dịnh nghĩa. Dữ liệu của các member sẽ dùng chung 1 bộ nhớ. Kích thước của union là kích thước của member lớn nhất.
	-Ví dụ:
	```C
	union typeData {
		int a;
		double b;
		float c;
	}
	```
# **Static** 
- **_Static toàn cục:_**  chỉ truy cập và sử dụng trong File khai báo nó, các File khác sẽ không thể truy cập được.
- **_Static cục bộ:_** chỉ khởi tạo 1 lần và tồn tại suốt thời thời gian chạy chương trình. Giá trị không mất đi khi kết thúc hàm, tuy nhiên biến static cục bộ chỉ có thể được gọi trong hàm khởi tạo nó, giá trị của biến chính bằng giá trị gần nhất mà nó được gọi.
- Ngoài ra, còn có `extern` để thông báo biến đã được khai báo ở file khác.
# **Pointer** 
-  **_Khái niệm:_** con trỏ (pointer) là những biến dùng để lưu trữ địa chỉ
-  Ví dụ khởi tạo biến con trỏ: `uint8_t *ptr;`
-  **_Con trỏ NULL:_** là con trỏ lưu trữ địa chỉ 0x00, tức là cho biết nó không trỏ vào đâu cả. Khi khởi tạo 1 con trỏ cần phải gắn cho nó 1 địa chỉ ngay, hoặc khi chưa cần dùng đến thì phải gắn nó là NULL, tại vì khi khởi tạo 1 con trỏ không gắn thì nó sẽ tự gắn cho nó 1 địa chỉ bất kì.
	- Ví dụ: ` uint8_t *ptr = NULL;`
- **_Con trỏ hàm:_** 
	- Khai báo con trỏ hàm: kiểu dữ liệu trả về + tên con trỏ hàm + input parameter
		Ví dụ : `void (*ptr)(int,int) = NULL;`
	- Thông qua con trỏ hàm có thể lấy 1 hàm làm input parameter của hàm khác.
		Ví dụ: 
		```C
		void hienthi(int a, int b, void (*tong)(int,int))
			{
				...
			}
		```
- **_Pointer to pointer:_** là 1 con trỏ có giá trị là 1 địa chỉ của 1 pointer	
	- Khai báo: `int **ptr;`

