#include <VirtualWire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

#define red 14
#define yellow 16
#define buzzer 17

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("   WelCome To ");
  lcd.setCursor(0, 1);
  lcd.print("  Our Project");
  delay(3000);
  lcd.clear();
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(buzzer, OUTPUT);

  vw_set_rx_pin(4);
  vw_setup(2000);
  vw_rx_start();
  Serial.begin(9600);
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen))
  {
    if (buf[0] == 'f')
    {
      Serial.println("Now You Safe..");
      lcd.setCursor(0, 0);
      lcd.print("Now You Safe...");
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(buzzer, LOW);

    }
    else if (buf[0] == 'b')
    {
      Serial.println("Where Hemalte");
      lcd.setCursor(0, 0);
      lcd.print(" Where Hemalte... ");
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
    }

  }
}
