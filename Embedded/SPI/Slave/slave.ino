#define SCK 13
#define MOSI 11
#define MISO 12
#define SS 10


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(SS, INPUT_PULLUP);
  pinMode(MISO, OUTPUT);
}

void loop() {
  uint8_t dataReceive = 0x00;
  while (SS == 0) {
    while (SCK == 0);
    for (int i = 0; i < 8; i++) {
      if (digitalRead(SCK) == 1) {
        dataReceive = dataReceive << 1;
        dataReceive = dataReceive | digitalRead(MOSI);
      }
    }
    Serial.println(dataReceive);
    dataReceive = 0x00;
  }

}
