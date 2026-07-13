#include <USB.h>
#include <USBHIDKeyboard.h>

USBHIDKeyboard Keyboard;

void setup() {
  // Bật tính năng USB gốc của ESP32-S3 và khai báo thiết bị là Bàn phím
  USB.begin();
  Keyboard.begin();
  
  // Đợi 3 giây để Windows kịp nhận diện phần cứng mới cắm vào
  delay(4000); 

  // Bước 1: Nhấn tổ hợp phím Windows + R để mở hộp thoại Run
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(500);             // Giữ phím 0.1 giây cho chắc ăn  
  Keyboard.releaseAll();  // Nhả phím ra
  
  delay(1000); // Đợi 0.5 giây cho bảng Run hiện lên hoàn toàn

  // Bước 2: Gõ chữ "notepad" và nhấn phím Enter
  Keyboard.print("notepad");
  Keyboard.write(KEY_RETURN);
  
  delay(2000); // Đợi 1 giây để phần mềm Notepad khởi động xong

  // Bước 3: Gõ thông điệp tự động
  Keyboard.println("hacked by J4P4N!");
  Keyboard.println("Haha :)");

  Keyboard.releaseAll();
  delay(3000); // đợi tiếp 3s

  Keyboard.press(KEY_LEFT_GUI); // ấn window
  delay(1000);
  Keyboard.releaseAll();

  delay(500);

  // gõ app zalo
  Keyboard.print("zalo");
  delay(500); // chờ 0.5s rồi mới nhấn enter
  Keyboard.write(KEY_RETURN);
  delay(1000);
}

void loop() {
  // LƯU Ý CỰC KỲ QUAN TRỌNG:
  // Luôn để trống hàm loop() khi làm BadUSB.
  // Code chỉ chạy 1 lần trong setup() khi vừa cắm điện. 
  // Nếu bạn bỏ lệnh gõ phím vào loop(), nó sẽ gõ vô hạn, 
  // làm liệt máy tính và bạn không thể nạp code mới để sửa được nữa!
  delay(1000);
}


// xong bước này máy sẽ coi board esp32 s3 là một bàn phím và không nạp code được nữa, để khắc phục nhấn giữ nút boot đồng thời nhấn 1 lần reset sau đó nhả ra và nạp lại code