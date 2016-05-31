#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

void get_device_info(void) {
  const char* ssid = "your_ssid";
  const char* password = "your_pass";

  const char* host = "toothfi.com";
  const int httpsPort = 443;

  // NOTE: api.github.com works  
  //const char* host = "api.github.com";  
  //const int httpsPort = 443;


  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure s_client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!s_client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  String url = "/device/device/abc/get_fake_device_info";
  // String url = "/repos/esp8266/Arduino/commits/master/status";

  Serial.print("requesting URL: ");
  Serial.println(url);

  s_client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + String(host) + "\r\n" +
               "User-Agent: test_https\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (s_client.connected()) {
    String line = s_client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = s_client.readStringUntil('\n');


  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");

}
