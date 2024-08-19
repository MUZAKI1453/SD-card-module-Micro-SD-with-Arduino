#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);

  if (!SD.begin(chipSelect)) {
    Serial.println("Initialization failed!");
    return;
  }
  Serial.println("Initialization done.");


  File dataFile = SD.open("example.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.println("This is a test");
    dataFile.println("Hello, SD card!");
    dataFile.println("ini percobaan membaca file.txt menggunakan module sd card");
    dataFile.close();
    Serial.println("Data written to file.");
  } else {
    Serial.println("Error opening example.txt");
  }

  dataFile = SD.open("example.txt");
  if (dataFile) {
    Serial.println("Reading from file:");
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  } else {
    Serial.println("Error opening example.txt");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
