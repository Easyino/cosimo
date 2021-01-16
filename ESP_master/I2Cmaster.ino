void sendSlave(String data, int type) {
  Wire.beginTransmission(I2C_SLAVE);
  Wire.write(type);
  for (a = 0; data[a] != '\0'; a++) {
    Wire.write(data[a]);
  }
  Wire.endTransmission();
}

bool checkReady() {
  int statement = 0;
  Wire.requestFrom(I2C_SLAVE, 1);
  while (Wire.available()) {
    statement = Wire.read();
  }
  return statement;
}