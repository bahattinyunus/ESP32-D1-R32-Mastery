#include <Arduino.h>

// ESP32 D1 R32 pin definitions
#define LED_PIN 2

void printProgressBar(int percent) {
  Serial.print("[");
  for (int i = 0; i < 20; i++) {
    if (i < (percent / 5)) Serial.print("=");
    else Serial.print(" ");
  }
  Serial.printf("] %d%%\r", percent);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  // Sci-Fi Boot Sequence
  delay(1000);
  Serial.println("\n\n");
  Serial.println("INITIALIZING SYSTEM KERNEL...");
  delay(500);
  
  for(int i=0; i<=100; i+=10) {
    printProgressBar(i);
    delay(100);
  }
  Serial.println("\n[OK] KERNEL LOADED.");
  delay(200);
  
  Serial.println("[INFO] LOADING DRIVERS...");
  delay(300);
  Serial.println("  > GPIO........[READY]");
  delay(100);
  Serial.println("  > UART........[READY]");
  delay(100);
  Serial.println("  > WIFI........[STANDBY]");
  delay(100);
  
  Serial.println("\n===============================================");
  Serial.println("   ESP32 D1 R32 MASTERY | COMMAND CENTER v1.0   ");
  Serial.println("   ARCHITECT: BAHATTIN YUNUS CETIN             ");
  Serial.println("===============================================");
  
  Serial.printf("SYSTEM: %s | REV: %d\n", ESP.getChipModel(), ESP.getChipRevision());
  Serial.printf("CORE: %d MHz | MEM: %d KB\n", ESP.getCpuFreqMHz(), ESP.getFlashChipSize() / 1024);
  Serial.println("===============================================\n");
}

void loop() {
  // Heartbeat Effect
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
  delay(100);
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
  delay(1000); // Wait for next beat

  static long lastLog = 0;
  if (millis() - lastLog > 5000) {
    lastLog = millis();
    Serial.printf("[LOG] SYSTEM UPTIME: %lu ms | STATUS: NOMINAL\n", millis());
  }
}
