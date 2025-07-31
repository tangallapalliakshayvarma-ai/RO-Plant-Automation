#include <LiquidCrystal.h>
#include <stdio.h>

// LCD RS, E, D4, D5, D6, D7
LiquidCrystal lcd(6, 7, 5, 4, 3, 2);

// Relay/Motor/Valve Pins
int con1 = 8;   // Motor 1
int con2 = 9;   // Motor 2
int valve = 10; // Solenoid Valve

// Water Level Sensors
int lvl1 = 11, lvl2 = 12, lvl3 = 13, lvl4 = A0; // OT tank
int lvl5 = A1, lvl6 = A2, lvl7 = A3, lvl8 = A4; // RT tank

int ti = 0;
int sts1 = 0, sts2 = 0, sts3 = 0, sts4 = 0;
int ot_level = 0;
int rt_level = 0;

void lcdbasic() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("OT:");
  lcd.setCursor(8, 0);
  lcd.print("RT:");
}

void setup() {
  Serial.begin(9600);

  // Set pins as OUTPUT or INPUT
  pinMode(con1, OUTPUT);
  pinMode(con2, OUTPUT);
  pinMode(valve, OUTPUT);

  pinMode(lvl1, INPUT);
  pinMode(lvl2, INPUT);
  pinMode(lvl3, INPUT);
  pinMode(lvl4, INPUT);
  pinMode(lvl5, INPUT);
  pinMode(lvl6, INPUT);
  pinMode(lvl7, INPUT);
  pinMode(lvl8, INPUT);

  // Turn off everything initially
  digitalWrite(con1, LOW);
  digitalWrite(con2, LOW);
  digitalWrite(valve, LOW);

  lcd.begin(16, 2);
  lcd.print(" Welcome ");
  delay(1500);

  lcdbasic();
}

void loop() {
  // Check OT level
  if (digitalRead(lvl1) == LOW && digitalRead(lvl2) == LOW && digitalRead(lvl3) == LOW && digitalRead(lvl4) == LOW) {
    lcd.setCursor(3, 0); lcd.print("Emp ");
    ot_level = 0;
  }
  else if (digitalRead(lvl1) == HIGH && digitalRead(lvl2) == LOW) {
    lcd.setCursor(3, 0); lcd.print("25% ");
    ot_level = 25;
  }
  else if (digitalRead(lvl1) == HIGH && digitalRead(lvl2) == HIGH && digitalRead(lvl3) == LOW) {
    lcd.setCursor(3, 0); lcd.print("50% ");
    ot_level = 50;
  }
  else if (digitalRead(lvl1) == HIGH && digitalRead(lvl2) == HIGH && digitalRead(lvl3) == HIGH && digitalRead(lvl4) == LOW) {
    lcd.setCursor(3, 0); lcd.print("75% ");
    ot_level = 75;
  }
  else if (digitalRead(lvl1) == HIGH && digitalRead(lvl2) == HIGH && digitalRead(lvl3) == HIGH && digitalRead(lvl4) == HIGH) {
    lcd.setCursor(3, 0); lcd.print("100%");
    ot_level = 100;
  }

  // Check RT level
  if (digitalRead(lvl5) == LOW && digitalRead(lvl6) == LOW && digitalRead(lvl7) == LOW && digitalRead(lvl8) == LOW) {
    lcd.setCursor(11, 0); lcd.print("Emp ");
    rt_level = 0;
  }
  else if (digitalRead(lvl5) == HIGH && digitalRead(lvl6) == LOW) {
    lcd.setCursor(11, 0); lcd.print("25% ");
    rt_level = 25;
  }
  else if (digitalRead(lvl5) == HIGH && digitalRead(lvl6) == HIGH && digitalRead(lvl7) == LOW) {
    lcd.setCursor(11, 0); lcd.print("50% ");
    rt_level = 50;
  }
  else if (digitalRead(lvl5) == HIGH && digitalRead(lvl6) == HIGH && digitalRead(lvl7) == HIGH && digitalRead(lvl8) == LOW) {
    lcd.setCursor(11, 0); lcd.print("75% ");
    rt_level = 75;
  }
  else if (digitalRead(lvl5) == HIGH && digitalRead(lvl6) == HIGH && digitalRead(lvl7) == HIGH && digitalRead(lvl8) == HIGH) {
    lcd.setCursor(11, 0); lcd.print("100%");
    rt_level = 100;
  }

  // Logic for automation
  if (ot_level >= 25) {
    sts2 = 0;
    if (rt_level <= 50) {
      sts3++; sts4 = 0;
      if (sts3 >= 2) sts3 = 2;
      if (sts3 == 1) {
        digitalWrite(valve, HIGH); delay(5000);
        digitalWrite(con1, HIGH); delay(5000);
        digitalWrite(con2, HIGH); delay(5000);
        lcdbasic();
      }
    }
    if (rt_level == 100) {
      sts4++; sts3 = 0;
      if (sts4 >= 2) sts4 = 2;
      if (sts4 == 1) {
        for (ti = 0; ti < 10; ti++) {
          lcd.setCursor(0, 1); lcd.print(ti); lcd.print(" ");
          delay(1000);
        }
        lcd.setCursor(0, 1); lcd.print(ti); lcd.print(" ");
        digitalWrite(con2, LOW); delay(5000);
        digitalWrite(con1, LOW); delay(5000);
        digitalWrite(valve, LOW); delay(5000);
        lcdbasic();
      }
    }
  }
  else {
    sts2++; sts3 = 0; sts4 = 0;
    if (sts2 >= 2) sts2 = 2;
    if (sts2 == 1) {
      digitalWrite(con2, LOW); delay(5000);
      digitalWrite(con1, LOW); delay(5000);
      digitalWrite(valve, LOW); delay(5000);
      lcdbasic();
    }
  }
}
