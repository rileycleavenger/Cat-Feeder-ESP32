#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

const int switchPin = 23;  // pin connected to the switch
volatile int switchState = LOW;

// wifi info
const char* ssid = "";
const char* password = "";

// Initialize Telegram BOT
#define BOTtoken ""  // your Bot Token (Get from Botfather)

// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define RILEY_CHAT_ID ""
#define COLIN_CHAT_ID ""
#define TYLER_CHAT_ID ""
#define MIKE_CHAT_ID ""

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

void setup() {
  // baud rate
  Serial.begin(115200);
  pinMode(switchPin, INPUT_PULLUP);

  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  

  bot.sendMessage(RILEY_CHAT_ID, "Bot started up", "");
}

void loop() {

  int currentState = digitalRead(switchPin);
  // check if the state has changed
  if (currentState != switchState) {
    switchState = currentState;

    // print the message when the switch state changes
    Serial.println("Switch state changed");

    // send notification
    bot.sendMessage(RILEY_CHAT_ID, "Cici was just fed!");
    bot.sendMessage(COLIN_CHAT_ID, "Cici was just fed!");
    bot.sendMessage(MIKE_CHAT_ID, "Cici was just fed!");
    bot.sendMessage(TYLER_CHAT_ID, "Cici was just fed!");
  }

  delay(1500); // delay for debouncing
}

