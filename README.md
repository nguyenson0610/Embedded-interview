
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
