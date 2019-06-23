
#include <FastLED.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

// here you need to put your own mac address
byte mac[] = {
  0x90, 0xA2, 0xDA, 0x0E, 0xF4, 0x91
};

// and here you need to put the IP address you want your arduino to have.
IPAddress ip(192, 168, 1, 11);
unsigned int localPort = 3456;

char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
EthernetUDP Udp;

// here we setup which data pin we want to send to and number of LEDs etc.
#define DATA_PIN    3
//#define CLK_PIN   4
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    500
CRGB leds[NUM_LEDS];
#define BRIGHTNESS          225
#define FRAMES_PER_SECOND  120
int i = 0;

void setup() {
  // handy to have a delay on startup so if FastLED crashes we don't lock ourselves out of the arduino.
  delay(3000);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  Ethernet.begin(mac, ip);

  // start UDP
  Udp.begin(localPort);

}

void loop() {

  // There is a limit of how many LEDs you can control with one UDP packet. I estimate it to be about 500 RGB LEDs.
  // If you want to control more than 500 you'll need to send 2 separate UDP packets.
  
  int packetSize = Udp.parsePacket();  

  if (packetSize) {
    Udp.read((char*)leds, NUM_LEDS * 3);
  }
  FastLED.show();

}

