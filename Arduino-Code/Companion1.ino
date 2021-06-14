//// Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <Fonts/Orbitron_Medium_38.h>
#include <Fonts/Orbitron_Medium_34.h>
#include <Fonts/Orbitron_Medium_32.h>
#include <Fonts/Orbitron_Medium_30.h>
#include <Fonts/Orbitron_Medium_24.h>
#include <Fonts/Orbitron_Medium_20.h>
#include <Fonts/Lato_Regular_11.h>
#include <Fonts/Lato_Regular_34.h>
#include <Fonts/Lato_Regular_24.h>
#include <Fonts/Lato_Bold_24.h>
#include <Fonts/Lato_Regular_27.h>
#include <Fonts/Roboto_Bold_20.h>
#include <Fonts/Orbitron_Bold_14.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/Lato_Regular_20.h>
#include <Fonts/Lato_Regular_16.h>
#include <SPI.h>
#include <WiFi.h>
#include <time.h>
#include <ArduinoJson.h>
#include <RTClib.h>
#include <FastLED.h>
#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"
#include <RV3028C7.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include <EEPROM.h>

//PLACITECH
const unsigned char placitech [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0xe0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0xe0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0xc0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x82, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x83, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 
  0x07, 0xfe, 0x1e, 0x00, 0x7e, 0x00, 0xff, 0x87, 0x9f, 0xff, 0x3f, 0xf8, 0x7f, 0xc1, 0xe0, 0x78, 
  0x07, 0xff, 0x1e, 0x00, 0xff, 0x03, 0xff, 0xc7, 0x9f, 0xff, 0x3f, 0xf8, 0xff, 0xf1, 0xe0, 0x78, 
  0x07, 0xff, 0x9e, 0x00, 0xff, 0x03, 0xff, 0xe7, 0x9f, 0xff, 0x3f, 0xf9, 0xff, 0xf1, 0xe0, 0x78, 
  0x07, 0x87, 0x9e, 0x01, 0xef, 0x07, 0xc3, 0xe7, 0x81, 0xf0, 0x38, 0x01, 0xf0, 0xf9, 0xe0, 0x78, 
  0x07, 0x87, 0x9e, 0x01, 0xe7, 0x87, 0x81, 0xe7, 0x81, 0xf0, 0x38, 0x01, 0xe0, 0x79, 0xe0, 0x78, 
  0x07, 0x87, 0x9e, 0x01, 0xe7, 0x8f, 0x80, 0x07, 0x81, 0xf0, 0x3f, 0xf3, 0xe0, 0x01, 0xff, 0xf8, 
  0x07, 0x87, 0x9e, 0x03, 0xc7, 0x8f, 0x00, 0x07, 0x81, 0xf0, 0x3f, 0xf3, 0xc0, 0x01, 0xff, 0xf8, 
  0x07, 0xff, 0x9e, 0x03, 0xc3, 0xcf, 0x00, 0x07, 0x81, 0xf0, 0x3f, 0xf3, 0xc0, 0x01, 0xff, 0xf8, 
  0x07, 0xff, 0x1e, 0x03, 0xdf, 0xcf, 0x00, 0x07, 0x81, 0xf0, 0x3f, 0xf3, 0xc0, 0x01, 0xff, 0xf8, 
  0x07, 0xfe, 0x1e, 0x07, 0x9f, 0xc7, 0x81, 0xe7, 0x81, 0xf0, 0x38, 0x01, 0xe0, 0x79, 0xe0, 0x78, 
  0x07, 0xfc, 0x1e, 0x07, 0x9f, 0xe7, 0xc1, 0xe7, 0x81, 0xf0, 0x38, 0x01, 0xf0, 0x79, 0xe0, 0x78, 
  0x07, 0x80, 0x1f, 0xff, 0x81, 0xe7, 0xff, 0xe7, 0x81, 0xf0, 0x3f, 0xf9, 0xff, 0xf9, 0xe0, 0x78, 
  0x07, 0x80, 0x1f, 0xff, 0x01, 0xf3, 0xff, 0xc7, 0x81, 0xf0, 0x3f, 0xf8, 0xff, 0xf1, 0xe0, 0x78, 
  0x07, 0x80, 0x1f, 0xff, 0x00, 0xf1, 0xff, 0x87, 0x81, 0xf0, 0x3f, 0xf8, 0x7f, 0xe1, 0xe0, 0x78, 
  0x07, 0x80, 0x1f, 0xfe, 0x00, 0xf0, 0x7f, 0x07, 0x80, 0xe0, 0x3f, 0xf8, 0x1f, 0xc1, 0xe0, 0x78, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//BLE magnos
//variables and defines used by BLEServer.ino
String currentDataField;

//Rene UUIDS
#define SERVICE_UUID        "5ac9bc5e-f8ba-48d4-8908-98b80b566e49"
#define COMMAND_UUID        "bcca872f-1a3e-4491-b8ec-bfc93c5dd91a"

//Ale UUIDS
//#define SERVICE_UUID        "8fda68f1-be42-4ec9-9dfb-1f90308cc9ff"
//#define COMMAND_UUID        "43c63889-6268-4b07-af18-f5aeb367cb92"

BLECharacteristic *commandCharacteristic;

//indicates connection state to the android device
boolean connected = false;

//var to know if weather is displayed
boolean isWeatherDisplayed = false;

//var to know what app is opened
int selected = 0;

//indiciates whether or not a operation is currently in progress
boolean operationInProgress = false;

//function signitures
String sendBLE(String command);
void addData(String data);  //adds data to a current string, used within BLEServer.ino
void initBLE(); //initializes the BLE connection by starting advertising.

//menu app x and y position array
int posx[8]={20, 65, 110, 20, 110, 20, 65, 110};
int posy[8]={25, 25, 25, 65, 65, 105, 105, 105};

// Screen dimensions
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 128 // Change this to 96 for 1.27" OLED.

// You can use any (4 or) 5 pins 
#define MOSI_PIN 23
#define SCLK_PIN 18
#define CS_PIN   5
#define DC_PIN   17 // TX2
#define RST_PIN  4



//// Fixed values for OLED colors
#define WHITE           0xFFFF
#define YELLOW          0xFFE0
#define BLUE            0x001F
#define RED             0xF800  
#define ORANGE          0xFC40 
#define GREEN           0x07E0
#define CYAN            0x07FF
#define BLACK           0x0000

//globalvars
int colorColor[7]={WHITE,YELLOW, BLUE, RED, ORANGE, GREEN, CYAN};
int color = colorColor[EEPROM.read(2)];
boolean isVintage = EEPROM.read(0);
boolean makeSound = EEPROM.read(3);
boolean wakeRotation = EEPROM.read(1);   

//define colors
#define PRED  0xe55031 
#define PGREEN  0x61d761
#define PYELLOW  0x09cF
#define PBLUE   0x2363cc 
#define PBLUE2   0x23ccb5 
#define PORANGE   0xf19e27 
#define PGRAY   0xa6a0a7
#define PVIOLET    0x800F

int colorapp[8]={PRED,PGRAY,PYELLOW,GREEN,ORANGE,PVIOLET,PGREEN,PBLUE};



//// Variables stored in RTC memory
RTC_DATA_ATTR unsigned long time_elapsed = 0;
RTC_DATA_ATTR int hour_diff = 0;
RTC_DATA_ATTR int min_diff = 0;
RTC_DATA_ATTR int day_diff = 0;
RTC_DATA_ATTR byte weather_description;
RTC_DATA_ATTR int temperature_save;
RTC_DATA_ATTR byte color_save = 0;
RTC_DATA_ATTR byte red_f = 0;
RTC_DATA_ATTR byte green_f = 0;
RTC_DATA_ATTR byte blue_f = 0;
RTC_DATA_ATTR byte city_index = 0;
RTC_DATA_ATTR byte flash_status = 0;
RTC_DATA_ATTR byte boot = 0;
RTC_DATA_ATTR byte weather_stat = 0;



//// Declare the OLED Display
Adafruit_SSD1351 Oled = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, CS_PIN, DC_PIN, MOSI_PIN, SCLK_PIN, RST_PIN);  


//// Battery pin
const int batt = 34;
const int chg = 35;
int perc = 0;

const int acc = 26;
const int lgt = 19;
const int pwr = 16;


//// Define the server and the values used for time calculation
const char* ntpServer = "0.north-america.pool.ntp.org";
const long  gmtOffset_sec[7] = {-18000, -18000, -14400, -28800, 3600, 3600, -14400};
const int   daylightOffset_sec = 0;



//// Define the server, values and variables used for weather information 
String APIKEY = "877d83e4d31366ef2ece3325051b5c52";
String CityIDs[7] = {"5213681", "4164138", "5128581", "5368361", "6541136", "3169070", "3648522"};
bool id = false;
WiFiClient client;
char servername[] = "api.openweathermap.org";         



//// Define the weather variables
String w_main[15] = {"Thunder", "Drizzle", "Rain", "Snow", "Mist", "Smoke", "Haze",
  "Dust", "Fog", "Sand", "Ash", "Squall", "Tornado", "Clear", "Clouds"};
String weather_save;
String city_names[7] = {"State Col.", "Miami", "New York", "Los Angeles", "Fondi", "Rome", "Barquisimeto"};
String city_names_full[7] = {"State College", "Miami", "New York", "Los Angeles", "Fondi", "Rome", "Barquisimeto"};
byte x_coor[7] = {28, 54, 43, 33, 53, 55, 30};
byte prev_city_index;


  
//// Define wifi variables
byte net = 0;
int wait = 0;



//// Define time variables classic clock
char currentHour[3];
char currentH24[3];
char currentMinute[3];
char currentSecond[3];
int cH24;
int cH;
int cM;
int cS;
String prevHour = "-1";
String prevMinute = "-1";
String prevSecond = "-1";
String ampm = "0";
String cH_print;
String cM_print;
String cS_print;
byte changing;
byte wait_clock = 0;

//// Define time variables vintage clock
int v_hour;
int v_minute;
int v_second;
int v_hour_modified;

int v_prevhour = -1;
int v_prevminute = -1;
int v_prevsecond = -1;

byte v_changing;


//// Define date variables
char currentYear[5];
char currentDay[3];
char currentMonth[12];
int cY;
int cMo;
int cD;
String prevDay = "-1";
String months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
String daysOfTheWeek[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
String currentDayWeek;
String cMo_print;
String cD_print;


//// Define the clock
RV3028C7 rtc;


//// Define heart rate sensor
MAX30105 heartSensor;


//// Buzzer variables
const int Pin = 14; 
const int freq = 5000;
const int Channel = 0;
const int resolution = 8;


//// Buttons variables
const int b_button = 2;
const int m_button = 15;
const int t_button = 13;



//// Define the flashlight
#define LED_PIN 19 
#define NUM_LEDS 1 
CRGB led[NUM_LEDS];


//// Menu Variables
String menu_list[4] = {"Nav", "Heart Monitor", "Weather", "Spotify"};
int colors_list[7] = {WHITE, YELLOW, BLUE, RED, ORANGE, GREEN, CYAN};
String colors_list_str[7] = {"White", "Yellow", "Blue", "Red", "Orange", "Green", "Cyan"};
int Ra[7] = {255, 255, 0, 255, 255, 0, 0};
int Ga[7] = {255, 125, 0, 0, 30, 255, 255};
int Ba[7] = {255, 0, 255, 0, 0, 0, 255};
int goto_main = 0;

//Nav vars
String prev="";
String prevd="";

//for batt perc
int getVarPerc = 1;

TaskHandle_t Task1;

void codeForTask1(void * parameter){
  if(!isVintage){batt_bar(getVarPerc);}else{batt_num(getVarPerc);}
  for(;;){
    getClock(isVintage);
    //Serial.println("pase la primera");
    delay(250);
    //Serial.println("pase la segunda");
  }
}

void updateTime1(){
    String hourText = "";
    do{
      hourText = sendBLE("/time");
      rtc.setDateTimeFromISO8601(hourText);
      rtc.synchronize();
      rtc.setDateTimeComponent(DATETIME_DAY_OF_WEEK, 3);
      rtc.synchronize(); 
    Serial.print("HORANUEVA: "+ sendBLE("/time"));
    }while(hourText.length()<1);
}

 
void setup() {
  //// INITIALIZATION
  Serial.begin(115200);
  getVarPerc = getBattPerc();
  EEPROM.begin(4);
  isWeatherDisplayed = false;
  
  if (wakeRotation){
    delay(50);
    if (digitalRead(26) == LOW and boot != 0){
      esp_sleep_enable_ext0_wakeup(GPIO_NUM_26, 1);
      esp_deep_sleep_start();
    }
  }

  pinMode(acc, INPUT);
  pinMode(batt, INPUT);
  pinMode(chg, INPUT);
  pinMode(b_button, INPUT_PULLUP);
  pinMode(m_button, INPUT_PULLUP);
  pinMode(t_button, INPUT_PULLUP);

  pinMode(lgt, OUTPUT);
  pinMode(pwr, OUTPUT);
  digitalWrite(pwr, HIGH);
  
  FastLED.addLeds<NEOPIXEL, LED_PIN>(led, NUM_LEDS);
  ledcSetup(Channel, freq, resolution);
  ledcAttachPin(Pin, Channel);
  updateVars();
  //delay(500);

  Wire.begin();

  initBLE();
  rtc.begin();
  
  Oled.begin();
  Oled.setTextWrap(false);
  Oled.fillScreen(BLACK);
  Oled.setTextSize(1);

  if (boot == 0){
    delay(250);
    Oled.setFont(&Roboto_Bold_20);
    Oled.setTextColor(WHITE);
    Oled.drawBitmap(3, 15, placitech, 128, 70, WHITE); 
    drawCentreString("Companion", 66, 110);
    boot = 1;
    delay(3000);
    Oled.fillScreen(BLACK);
      
    eraseLoadText();
    startLoad();
    updateTime1();
    
  }
  
    //updateTime();

    Oled.fillScreen(BLACK);
    //if(!isVintage){batt_bar(getVarPerc);}else{batt_num(getVarPerc);}
    xTaskCreatePinnedToCore(codeForTask1, "TimeKeeping", 5000, NULL, 0, &Task1, 1);
    delay(50);
    goto waiting_main;
    
  //// END OF INITIALIZATION


  //// USER CONTROL
  
  waiting_main:
  Wait_SleepMode();
  
  
  //// BOTTOM BUTTON
  if (digitalRead(b_button) == LOW){
    wait = 0;
    while(digitalRead(b_button) == LOW){
      delay(10);
      wait += 10;
      if (wait >= 1000){
        if(makeSound){buzzer();}
        wait_clock_completion();
        vTaskDelete(Task1);
        delay(500);
        selected = 5;
        isWeatherDisplayed = false;
        stopwatch();
        Oled.fillScreen(BLACK);
        delay(250);
        if(!isVintage){batt_bar(getVarPerc);}else{batt_num(getVarPerc);}
        prevDay = "-1";
        prevMinute = -1;
        prevHour = -1;
        prevSecond = -1;
        v_prevhour = -1;
        v_prevminute = -1;
        v_prevsecond = -1;
        xTaskCreatePinnedToCore(codeForTask1, "TimeKeeping", 5000, NULL, 0, &Task1, 1);
        delay(500);
        wait_bottom();
        goto waiting_main;
        
      }
    }
    if(makeSound){buzzer();}
    goto waiting_main;
  }


  //// MIDDLE BUTTON
  else if (digitalRead(m_button) == LOW){
    wait_middle();
    if(makeSound){buzzer();}
    wait_clock_completion();
    vTaskDelete(Task1);
    delay(500);
    Oled.fillScreen(BLACK);
    delay(250);
    isWeatherDisplayed = false;
    menu_();
    if(!isVintage){batt_bar(getVarPerc);}else{batt_num(getVarPerc);}
    xTaskCreatePinnedToCore(codeForTask1, "TimeKeeping", 10000, NULL, 0, &Task1, 1);
    delay(500);
    wait_middle();
    goto waiting_main;
  }



  //// TOP BUTTON
  else if (digitalRead(t_button) == LOW){
    wait = 0;
    while(digitalRead(t_button) == LOW){
      delay(10);
      wait += 10;
      if (wait >= 1000){
        if(makeSound){buzzer();}
        wait_clock_completion();
        vTaskDelete(Task1);
        delay(500);
        selected = 2;
        isWeatherDisplayed = false;
        Oled.fillScreen(BLACK);
        delay(250);
        showWeather();
        Oled.fillScreen(BLACK);
        delay(250);
        if(!isVintage){batt_bar(getVarPerc);}else{batt_num(getVarPerc);}
        prevDay = "-1";
        xTaskCreatePinnedToCore(codeForTask1, "TimeKeeping", 5000, NULL, 0, &Task1, 1);
        delay(500);
        wait_bottom();
        goto waiting_main;
      }
    }
    if(makeSound){buzzer();}
    goto waiting_main;
  }
  
}



 
void loop() {
}