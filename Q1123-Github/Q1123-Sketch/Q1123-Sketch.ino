#include <Adafruit_MCP23X17.h>

Adafruit_MCP23X17 mcp;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste do MCP23017!");

  if (!mcp.begin_I2C(0x20)) {
    Serial.println("Erro MCP23017.");
    while (1)
      ;
  }

  for (int nL = 8; nL < 16; nL++) {
    mcp.pinMode(nL, OUTPUT);
    mcp.digitalWrite(nL, LOW);
  }

  for (int nL = 0; nL < 8; nL++) {
    mcp.pinMode(nL, INPUT_PULLUP);
  }

  Serial.println("Setup finalizado...");
}

void loop() {

  for (int nL = 0; nL < 8; nL++) {
    mcp.digitalWrite(nL + 8, !mcp.digitalRead(nL));
  }
}