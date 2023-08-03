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

# **Class** 
-  **_Khái niệm:_** class (lớp) là một mô tả trừu tượng của nhóm các đối tượng (object) có cùng bản chất, mỗi object là một thể  hiện cụ thể (instance) cho những mô tả trừu tượng đó.
- **_Một class sẽ bao gồm:_** 
	- Các dữ liệu (Property) và các phương thức (method).
   	- Class giống như struct cũng là kiểu dữ liệu do người dùng tự định nghĩa.
 - **_Method:_** giống như một hàm bình thường, có 2 cách định nghĩa:
   	+ Định nghĩa bên trong class:
   	```C
   	class LopHoc{
	public:
   	int siso;
   	int lop;
	void Hienthi(){
	cout<<"Lop "<<siso<<" siso la "<<siso<<endl;
	}
	}
	```
 	+ Định nghĩa bên ngoài class:
	```C
 	class SinhVien{
	public:
 	void hienthi();
  	private:
   	int tuoi;
    	int mssv;
 	}
  	void SinhVien::hienthi(){
		cout<<"tuoi "<<tuoi<<endl;
  		cout<<"mssv "<<mssv<<endl;
    	}
     	```
- **_Khai báo Class và Cách sử dụng Class:_** 
	- Khai báo Class: 
	Ví dụ :
	```C
	class SinhVien{
  	public:
      	void hienthi();
	private:
       	int tuoi;
		int MSSV;
	}
	```
	- Sử dụng Class:
		Ví dụ: 
		```C
		SinhVien sv;
  		sv.hienthi();
			
		```
# **Phạm vi truy cập của Class** 
- Có 3 phạm vi truy cập trong C++ là public, pivate và protected.
	+ Public: các property và method có thể được truy cập trực tiếp thông qua instance của class đó. Khai báo thuộc tính bằng public khi không có ràng buộc điều kiện trước khi gán hoặc không cần xử lý trước khi trả về giá trị thuộc tính.
 	+ Private: được sử dụng khi không muốn người khác có thể tùy ý gán giá trị hoặc muốn xử lý trước khi trả về giá trị.
  	+ Protected: các property và method chỉ có thể truy cập được thông qua class con. 
	Ví dụ:
	```C
 	class Doituong
	{
		public:
			int tuoi;
		private:
			int lop;
	};
# **Constructor** 
- Tên của constructor sẽ trùng với tên class, nằm ở public, có thể có tham số đầu vào hoặc không cần tham số đầu vào, nó sẽ được chạy đầu tiên khi khởi tạo 1 object.
	```C
 	class Doituong
	{
		public:
  			DoiTuong(int tuoi, int lop);
			int tuoi;
		private:
			int lop;
	};

# **Static trong class** 
- Static member sẽ là thuộc tính dùng chung cho tất cả các object của class đó. Tức là khi khai báo nhiều object, mỗi object sẽ có các thuộc tính khác nhau nhưng static chỉ có một và tồn tại trong suốt chương trình. hay ngắn gọn là các objcet sẽ dùng chung một biến static.

# **Các đặc tính của OOP**
 - Tính kế thừa: một class có thể kế thừa các thuộc tính từ một class khác đã tồn tại trước đó.
 - Tính đa hình: là một khả năng mà một method trong class sẽ trả về các kết quả khác nhau tùy vào các dữ liệu được xử lý.
 - Tính trừu tượng: là khả năng xử lý một đối tượng bằng cách gọi tên một method và thu về kết quả được xử lý mà không cần biết làm cách nào mà đối tượng có thể thao tác được.
 - Tính đóng gói: dữ liệu và thông tin sẽ được đóng gói lại, không cho người dùng có thể thay đổi đối tượng đó, nên sẽ đảm báo tính trọn vẹn của đối tượng.

# **Template trong C++**
  - Template là 1 từ khóa trong C++, là một kiểu dữ liệu trừu tượng tổng quát cho các kiểu dữ liệu cơ bản int, double, float,...
  - Template được sử dụng khi các hàm gần giống nhau, tương tự nhau, chỉ khác các kiểu dữ liệu input hay kiểu trả về.

# **Namespace trong C++**
  - Namespace được sử dụng để phân biệt các hàm, class, biến... có cùng tên trong các thư viện khác nhau.
    ```C
    namespace ConOngA{
    	int A = 10;
     }
    namespace ConOngB{
 		int A = 20
     }
    ```
# **Vector**
  - Giống với mảng, vector là một đối tượng để chứa các đối tượng khác, các đối tượng được chứa này được lưu trữ một cách liên tiếp.
  - Kích thước của vector có thể thay đổi được trong quá trình thực hiện chương trình.
  - Ví dụ khởi tạo 1 vector:
    	` vector<int> array;`
  - Một số method trong vector:
	+ push_back(): hàm đẩy một phần tử vào vị trí sau cùng của vector.
  	+ assign(): gán một giá trị mới cho các phần tử vector bằng cách thay thế các giá trị cũ.
   	+ pop.back(): xóa đi phần tử cuối cùng của một vector.
   	+ insert(): chèn các phần tử mới vào trước phần tử được trỏ bởi vòng lặp.
   	+ ersare(): xóa các phần tử tùy theo vị trí vùng chứa.
   	+ clear(): loại bỏ tất cả các phần tử của vùng chứa vector.

# **For cải tiến trong C++**
  ```C
  for(auto item : array){
	.....
  }
  ```
- Vị trí đầu tiên sẽ được gán vào item, sau đó sẽ vào vòng lặp, thực hiện xong thì array sẽ dịch sang phải, sẽ tiếp tục gán array vào item.
- Từ khóa auto được dùng khi chưa xác định được kiểu dữ liệu.

# **Linked List**
  - Sẽ bao gồm các Node, mỗi Node sẽ có địa chỉ node, và trong Node sẽ chưa giá trị và 1 con trỏ trỏ tới địa chỉ của một Node khác.
  - Lợi ích : giúp chèn hoặc xóa các phần tử cho mảng một cách dễ dàng và nhanh chóng
  - Thư viện sử dụng `#include <list>;` sẽ có các method giống với vector.
  - Thư viện <map> sẽ bao gồm 2 thông số Key và Value.`map<string,int> SinhVien;`

# **Embedded**
**_Giao thức SPI:_**
- Là 1 chuẩn giao tiếp nối tiếp tốc độ cao.
  + Các bit dữ liệu được truyền nối tiếp và có xung clock đồng bộ.
  + Giao tiếp song công, có thể truyền và nhận tại cùng một thời điểm.
  + Khoảng cách truyền ngắn, tốc độ truyền khoảng vài Mb/s.
  + Có thể chỉ gồm 1 master và 1 slave, hoặc 1 master và nhiều slave.
- SPI gồm có 4 đường tín hiệu:
  + SCK: xung clock
  + MOSI: Master Out, Slave In
  + MISO: Master In, Slave Out
  + SS: Slave select
- Cách truyền và nhận tín hiệu
  + Master và slave đều có 1 thanh ghi dữ liệu 8 bit chứa dữ liệu cần gửi đi hoặc dữ liệu nhận về.
  + Đối với có nhiều slave, master muốn giao tiếp với slave sẽ thông qua chân SS, để giao tiếp với slave nào thì master sẽ kéo chân SS nối với slave đó xuống thấp, các chân SS nối với các slave khác sẽ ở mức cao.
  + Cứ mỗi xung nhịp Clock, một bit trong thanh ghi dữ liệu của Master sẽ được truyền qua Slave thông qua chân MOSI, và 1 bit trong thanh ghi dữ liệu trong Slave sẽ được truyền qua Master thông qua chân MISO.
- Các chế độ hoạt đông: Có 4 chế độ hoạt động sẽ tùy thuộc vào CPOL và CPAL
  + CPOL:nói về hình dạng xung
    	* CPOL = 0: đầu tiên hình dạng xung ở mức 0 sau đó lên mức 1 và kéo lại xuống 0.
    	* SPOL = 1: khi không truyền data sẽ ở mức 1 sau đó kéo xuống 0 và kéo lại lên 1.
  + CPAL: nói về cách truyền data
    	* CPAL = 0: đưa bit vào chân truyền trước sau đó cần xung clock để đẩy bit data đi
    	* CPAL = 1: đưa xung clock trước sau đó mới đưa bit data vào và cần 1 xung clock tiếp theo để đẩy bit data đi.

**_Giao thức I2C:_**
- Chỉ sử dụng 2 dây: SDA (truyền và nhận data) và SCL (xung Clock)
- I2C là một giao thức truyền thông nối tiếp vì vậy dữ liệu sẽ được truyền từng bit dọc theo một đường duy nhất ( đường SDA).
- Khi Master không giao tiếp với Slave thì 2 chân SDA và SCL  sẽ ở mức cao
- Cách hoạt động của I2C: dữ liệu sẽ được truyền trong các tin nhắn. Tin nhắn sẽ được chia thành các khung dữ liệu. Mỗi tin nhắn sẽ bao gồm điều kiện khởi động, khung địa chỉ ( address frame), read/write bit, ACK/NACK bit, data frame, điều kiện dừng.
  + Start condition: SDA sẽ chuyển từ mức cao xuống mức thấp sau đó SCL sẽ chuyển tử mức cao xuống thấp
  + Address frame: gồm 7 hoặc 10 bit để xác định slave khi master muốn giao tiếp với slave đó
  + Read/Write bit: giúp xác định Master sẽ truyền dữ liệu ( tức là write khi bit này = 0) hay nhận dữ liệu ( tức là read khi bit này = 1)
  + ACK/NACK bit: khi master truyền 1 byte đến slave, lúc này dây SDA sẽ đổi trạng thái đầu vào ra (MASTER sẽ là đầu vào, SLAVE sẽ là đầu ra) sau đó salve sẽ truyền bit 0 đến master để xác nhận rằng slave đã nhận đủ 1 byte, hoặc truyền bit 1 để thông báo không nhận đủ 1 byte.
  + Data frame: sau khi nhận được bít ACK từ slave, data sẽ sẵn sàng được gửi đi. khung dữ liệu sẽ có độ dài 8 bit, các bit sẽ được truyền dọc theo dây SDA,  và mỗi khung dữ liệu như vậy sẽ có đi kèm theo bít ACK/NACK để xác nhận rằng có gửi thành công hay không
  + Stop condition: sau khi đã gửi hết các data, master sẽ gửi một stop bit để dừng quá trình truyền. SCL sẽ chuyển từ mức 0 lên mức 1 sau đó SDA sẽ chuyển tử mức 0 lên 1.
  
**_Giao thức UART:_**
- Gồm 2 chân: Tx và Rx, khi không truyền thì cả 2 chân đều kéo lên mức 1
- Chân Tx của 1 chip sẽ kết nối trức tiếp với chân Rx của chip kia và ngược lại. UART là giao thức một master và một slave.
- Khi gửi trên chân Tx, UART đầu tiên sẽ dịch thông tin song song này thành nối tiếp và truyền đến thiết bị nhận, UART thứ hai nhận dữ liệu này trên chân Rx của nó và biến đổi nó trở lại thành song song để giao tiếp với thiết bị điều khiển của nó.
- Có 3 chế độ truyền UART:
  + Full duplex: Giao tiếp đồng thời đến và đi từ mỗi master và slave
  + Half duplex: Dữ liệu đi theo một hướng tại một thời điểm
  + Simplex: Chỉ giao tiếp một chiều
- Dữ liệu truyền qua UART được tổ chức thành các gói. Mỗi gói chứa 1 bit bắt đầu, 5 đến 9 bit dữ liệu (tùy thuộc vào UART), một bit chẵn lẻ tùy chọn và 1 hoặc 2 bit dừng.
  + Start bit: 	UART thường ở mức cao khi không truyền tín hiệu. Để truyền tín hiệu, UART truyền sẽ kéo Tx từ cao xuống thấp trong 1 chu kì clock, khi UART nhận thấy được thay đổi đó nó sẽ bắt đầu đọc các bit trong khung dữ liệu
  + Khung dữ liệu: gồm 5 đến 8 bit nếu có bit chẵn lẻ, hoặc có thể lên đến 9 bit data khi không có bit chẵn lẻ.
  + Bit chẵn lẻ: để nhận biết có sự thay đổi dữ liệu trong quá trình truyền hay không. Sau khi nhận được khung data, nó sẽ đếm xem thử số bit 1 là bao nhiêu và kiểm tra xem nó là chẵn hay lẻ. Đối với quy tắc số chẵn, nếu tổng bit 1 trong khung data là số chẵn thì bit chẳn/lẻ = 0, và ngược lại. Đối với quy tắc lẻ, nếu tổng bit 1 trong khung data là số chẵn thì bit chẳn/lẻ = 1, và ngược lại
  + Stop bit: để báo hiệu kết thúc gói dữ liệu. Đối với 1 bit stop, Tx sẽ kéo từ 0 lên 1. Đối với 2 bit stop, Tx sẽ kéo từ 0 lên 1, kéo lại xuống mức 0 sau đó delay, rồi kéo lại lên mức 1.

**_Ngắt (Interrup):_**
- Ngắt là một sự kiện khẩn cấp, buộc vi điều khiển phải tạm dừng chương trình hiện tại, và phục vụ ngay lập tức nhiệm vụ  mà ngắt yêu cầu.
- Cần phải có trình phục vụ ngắt (ISR) để đưa ra nhiệm vụ cho vđk khi có ngắt xảy ra.
- Bảng vector ngắt chứa các ngắt mà ta muốn sử dụng ( bao gồm reset, ngắt ngoài, ngắt truyền thông, ngắt timer)
- Mỗi ngắt sẽ có 1 địa chỉ khác nhau và stt ngắt càng thấp thì độ ưu tiên càng cao. Khi có ngắt xảy ra, PC sẽ chạy tới địa chỉ ngắt đó và thực hiện.
- Ngắt ngoài:
  + LOW: kích hoạt trạng thái chân input mức thấp
  + HIGH: kích hoạt trạng thái chân input mức cao
  + RISING: chân input chuyển từ mức thấp lên cao ( xung cạnh lên)
  + FALLING: chân input chuyển từ mức cao lên thấp ( xung cạnh xuống)
- Ngắt truyền thông: thường dùng cho UART, SPI
