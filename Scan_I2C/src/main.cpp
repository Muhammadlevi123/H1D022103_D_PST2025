#include <Arduino.h>
#include <wire.h>

int SDA_pin = D2;
int SCL_pin = D3;

void setup() {

    Wire.begin(SDA_pin,SCL_pin);
    Serial.begin(9600);

}

void loop() {

  byte error,address;
  int nDevices;
  Serial.print("Scanning...");
  nDevices = 0;
  for(address = 1; address<127;address++){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if(error==0){
      Serial.print("I2C terbaca pada alamat 0x");
      if(address < 16){
        Serial.print("0");
      }
      Serial.print(address,HEX);
      Serial.print("!");
      nDevices++;
    }else if(error==4){
      Serial.print("Ada error yang tidak diketahui alamat 0x");
      if(address<16){
        Serial.print("0");
        
      }
      Serial.print(address,HEX);
    }
  }
  if(nDevices==0){
    Serial.print("Tidak ada satupun alamat I@C yang ditemukan");
  }else {
    Serial.print("Selesai");
  }
  delay(5000);
}

