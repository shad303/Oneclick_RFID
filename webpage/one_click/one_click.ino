//==============================================================
//                  LIBRARIES
//==============================================================
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
ESP8266WebServer server(80);
const char* ssid     = "Jio";     //Your Wi-Fi SSID and PASSWORD
const char* password = "12345678";
//--------------------------------------------------------------
#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <SPI.h>
//==============================================================
//                  DECLARATION
//==============================================================
constexpr uint8_t RST_PIN = D3;   // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = D4;    // Configurable, see typical pin layout above
MFRC522 rfid(SS_PIN, RST_PIN);    // Instance of the class
MFRC522::MIFARE_Key key;
String tag;
static String product;
static int value12;
static int value6s;
static int value;
int Counter12 = 0;
int Counter6s = 0;
//==============================================================
//                  HTML webpage
//==============================================================
#import "index.h" 
//==============================================================
//                  ROUTINES
//==============================================================
void handleRoot() {              
  server.send(200, "text/html", MAIN_page); 
}
void handlequant12() {   
  if(product == "iphone12"){
    Counter12 = Counter12 + 1;
    String quant12 = String(Counter12);
    server.send(200, "text/plain", quant12);
    }           
}
void handlequant6s() {   
  if(product == "iphone6s"){
    Counter6s = Counter6s + 1;
    String quant6s = String(Counter6s);
    server.send(200, "text/plain", quant6s);
    }           
}
void handlesubtotal12() {   
  value12 = (Counter12) * 84900 ;
    String subtotal12 = String(value12);
    server.send(200, "text/plain", subtotal12);        
}
void handlesubtotal6s() {   
   value6s = (Counter6s) * 18900 ;
    String subtotal6s = String(value6s);
    server.send(200, "text/plain", subtotal6s);        
}
void handletotal() {   
   value = (value6s) + (value12);
    String total = String(value);
    server.send(200, "text/plain", total);        
}
//==============================================================
//                  SETUP
//==============================================================
void setup() {
  WiFi.begin(ssid,password);
  Serial.begin(9600);  
  Serial.println("");  //Connect to your WiFi router
  SPI.begin();  // Init SPI bus
  rfid.PCD_Init();   // Init MFRC522
  Serial.println("Serial started at 9600");
  Serial.println("One-Click RFID Store");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP Address: ");   //If connection successful show IP address in serial monitor
  Serial.println(WiFi.localIP());
  //----------------------------------------------------------------
  server.on("/", handleRoot);  // This displays the main webpage
  server.on("/readquant12", handlequant12);  // To update Quantity of iPhone12 called by the function getquantof12()
  server.on("/readquant6s", handlequant6s);  // To update Quantity of iPhone6s called by the function getquantof6s()
  server.on("/readsubtotal12", handlesubtotal12);  // To update Sub total of iPhone12 called by the function getsubtotal12()
  server.on("/readsubtotal6s", handlesubtotal6s);  // To update Sub total of iPhone6s called by the function getsubtotal6s()
  server.on("/readtotal", handletotal);  // To update Total bill called by the function gettotal()
  //----------------------------------------------------------------
  server.begin();
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================  
void loop(void){
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
    Serial.println(tag);
    if(tag == "16219915128"){
      product = "iphone6s";
      Serial.println("Product: iphone 6s");
      Serial.println("Cost: 18,900");
      }
      else{
      product = "iphone12";
      Serial.println("Product: iphone 12");
      Serial.println("Cost: 84,900");
      }
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
  server.handleClient();          //Handle client requests
}
