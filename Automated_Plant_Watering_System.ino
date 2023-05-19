// Automated Plant Watering System
// ID: 2330526
// Bidhi Maharjan
// Date: 2023-05-15

// include the library code for the lcd
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// initialize the water pump pin at digital pin 2
int waterPump = 2;

void setup() {
  // initialize serial communication at 9600 baud rates
  Serial.begin(9600);
  
  // set up the 16x2 LCD's number of columns and rows
  lcd.begin(16, 2);

  // set the water pump pin as the OUTPUT
  pinMode(waterPump, OUTPUT);
  digitalWrite(waterPump, HIGH);
  delay(1000); // wait for 1000 milliseconds

  // display the initial message rowwise on lcd for 3 seconds
  lcd.setCursor(0, 0);
  lcd.print("PLANT WATERING");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM IS ON ");
  delay(3000);
  lcd.clear();
}
 
void loop() {
  // read analog value of the moisture sensor from analog pin A0
  int moistureValue = analogRead(A0);
  Serial.print("Moisture value: ");
  Serial.println(moistureValue);

  // the sensor value is highest, when the moisture is lowest
  // and the sensor value decreases, as the moisture increases

  // condition to check the moisture value of the sensor
  // if the value is greater than 800, turn the pump on
  if (moistureValue > 800) {
    digitalWrite(waterPump, LOW);
    // display the pump status in the first row of lcd
    lcd.setCursor(0, 0);
    lcd.print("Water Pump : ON ");
  // else turn the pump off
  } else {
    digitalWrite(waterPump, HIGH);
    // display the pump status in the first row of lcd
    lcd.setCursor(0, 0);
    lcd.print("Water Pump : OFF");
  }

  // conditions to check and display the level of moisture present
  // on the second row of the lcd
  if (moistureValue < 400) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : HIGH");
  } else if (moistureValue > 400 && moistureValue < 800) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : MID ");
  } else if (moistureValue > 800) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : LOW ");
  }
}
