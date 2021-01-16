#include "settings.h"
namespace TypeCast = experimental::TypeConversion;
using namespace experimental::crypto;

void setup() {
  pinMode(up, INPUT_PULLUP);
  pinMode(confirm, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  Serial.begin(250000);
  Serial.println("--------------------------------");


  Wire.begin(SDA_PIN, SCL_PIN, I2C_MASTER);
  display.init();
  display.flipScreenVertically();
  display.setContrast(255);


  EEPROM.begin(EEPROM_length);
  inputString.reserve(200);

  max_value_address = pow(2, usable_address_bits);

  if (digitalRead(up) == LOW && digitalRead(confirm) == LOW && digitalRead(down) == LOW) {
    eepromClear();
  }



  Serial.print("max address memory = ");
  Serial.println(max_value_address);
  loadCheckpoints();
  if (checkpoint_memory[0] != 17) {
    eepromClear();
    loadSector(0);
    getNonceGenerator()(hkdfSalt, sizeof hkdfSalt);
    String buffer;
    for (i = 0; i < 16; i++) {
      buffer += (char)hkdfSalt[i];
    }
    updateCommand(0, buffer, text);
    updateEEPROM();
  }
  else {
    loadSector(0);
    for (i = 0; i < 16; i++) {
      hkdfSalt[i] = memory_map[0][i];
    }
  }
  HKDF hkdfInstance(FPSTR(masterKey), (sizeof masterKey) - 1, hkdfSalt, sizeof hkdfSalt); // (sizeof masterKey) - 1 removes the terminating null value of the c-string
  hkdfInstance.produce(derivedKey, sizeof derivedKey);
  Serial.println("hdfsalt:");
  for (i = 0; i < 16; i++) {
    Serial.print(hkdfSalt[i]);
    Serial.print(", ");
  }
  Serial.println("");



  if (EEPROM.read(0)) {
    tryConnect();
  }
  else {
    createNetwork();
  }


  if (digitalRead(up) == LOW && digitalRead(down) == LOW && digitalRead(confirm) == HIGH) {
    OTAupdate();
  }

  n_section = 4;
  section[0].title = "nome-0";
  section[0].email = "email-0";
  section[0].password = "password-0";
  section[1].title = "nome-1";
  section[1].email = "email-1";
  section[1].password = "password-1";
  section[2].title = "nome-2";
  section[2].email = "email-2";
  section[2].password = "password-2";
  section[3].title = "nome-3";
  section[3].email = "email-3";
  section[3].password = "password-3";
  sendSlave("/*caboom schadow digispark*/", text);
}

void loop() {
  server.handleClient();


  if (ota_initialised) {
    ArduinoOTA.handle();
  }

  serialEvent();
  if (stringComplete) {
    stringComplete = false;
    loadSerialCommands(inputString);
    executeSerialCommands();
  }
}