
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

//variables and defines used by BLEServer.ino
String currentDataField;
#define SERVICE_UUID        "5ac9bc5e-f8ba-48d4-8908-98b80b566e49"
#define COMMAND_UUID        "bcca872f-1a3e-4491-b8ec-bfc93c5dd91a"
BLECharacteristic *commandCharacteristic;

//indicates connection state to the android device
boolean connected = false;

//indiciates whether or not a operation is currently in progress
boolean operationInProgress = false;

//function signitures
String sendBLE(String command);
void addData(String data);  //adds data to a current string, used within BLEServer.ino
void initBLE(); //initializes the BLE connection by starting advertising.




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

void setup() {
  Serial.begin(115200);
  initBLE();
}

void loop() {
  //available commands
  //  sendBLE("/notifications", &string); //gets current android notifications as a string format "appName,Title;ExtraText,ExtraInfoText,ExtraSubText,ExtraTitle;Description;"
  //  sendBLE("/calendar", &string); // returns a string of calender events for the next 24 hours in format "title;description;startDate;startTime;endTime;eventLocation;"
  //  sendBLE("/time", &string); // returns a string representing the time
  //  sendBLE("/isPlaying", &string); //returns "true" or "false" indicating whether spotify is playing on the android device
  //  sendBLE("/currentSong", &string); //returns the current song name and artist playing on spotify as one string
  //  sendBLE("/play"); //hits the media play button on the android device
  //  sendBLE("/pause"); //hits the media pause button on the android device
  //  sendBLE("/nextSong"); //hits the media next song button on the android device
  //  sendBLE("/lastSong"); //hits the media previous song button on the android device

  Serial.println("PITO");
  //Serial.println(sendBLE("/time"));

  String s= sendBLE("/time");
  
  if (s==""){ Serial.println("No signal received");}
  else{
    Serial.println(s);
    String datetime_hour=s.substring(0,s.indexOf(":"));
    String datetime_minute=s.substring(s.indexOf(":")+1,s.indexOf(":")+3);
    String datetime_second=s.substring(s.indexOf(":")+4,s.indexOf(":")+6);
    //Serial.println(s);
    //Serial.println(sendBLE("/time"));
    Serial.println(datetime_hour);
    Serial.println(datetime_minute);
    Serial.println(datetime_second);
    }


  
  
  
  delay(1000);
}
