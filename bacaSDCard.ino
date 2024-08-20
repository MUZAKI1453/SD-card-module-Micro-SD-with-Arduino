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

  // Membuka file "example.txt" untuk membaca
  File dataFile = SD.open("ujicoba.txt");

  if (dataFile) {
    Serial.println("Reading from file:");
    // Membaca dan menampilkan isi file ke Serial Monitor
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  } else {
    Serial.println("Error opening ujicoba.txt");
  }
}

void loop() {
  // Kode utama Anda bisa ditambahkan di sini jika diperlukan
}
