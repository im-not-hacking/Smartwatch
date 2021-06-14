void addData(String data) {
//  Serial.println("Adding:" + data);
  currentDataField += data;
}

class cb : public BLEServerCallbacks    {
    void onConnect(BLEServer* pServer) {
      connected = true;
    }
    void onDisconnect(BLEServer* pServer) {
      connected = false;
    }
};

class ccb : public BLECharacteristicCallbacks  {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();
      addData(String( pCharacteristic->getValue().c_str()));
    }
    void onRead(BLECharacteristic* pCharacteristic) {
      //      Serial.println("Characteristic Read");
      operationInProgress = false;
    }
};

void initBLE() {
  BLEDevice::init("ESP32 Smartwatch");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);

  //define the characteristics and how they can be used
  commandCharacteristic = pService->createCharacteristic(
                            COMMAND_UUID,
                            BLECharacteristic::PROPERTY_READ   |
                            BLECharacteristic::PROPERTY_WRITE  |
                            BLECharacteristic::PROPERTY_NOTIFY
                          );


  //set all the callbacks
  commandCharacteristic->setCallbacks(new ccb());
  commandCharacteristic->setValue("");

  //add server callback so we can detect when we're connected.
  pServer->setCallbacks(new cb());

  pService->start();


  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
}

String sendBLE(String command) {
  operationInProgress = true;
  commandCharacteristic->setValue(command.c_str());
  commandCharacteristic->notify();

  currentDataField = "";

  unsigned long startTime = millis();
  while (operationInProgress && (startTime + 2000 > millis()))
    delay(25);

  return currentDataField;

}
