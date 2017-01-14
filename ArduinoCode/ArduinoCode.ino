#include  <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
int backLight = 13;    // pin 13 will control the backlight

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int red = 9;
int blue = 7;
int green = 8;
 
void setup()
{
 // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);

  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  
  pinMode(backLight, OUTPUT);          //set pin 13 as output
  analogWrite(backLight, 150);        //controls the backlight intensity 0-254
  lcd.begin(16,2);                    // columns, rows. size of display
  lcd.clear();                        // clear the screen
}

void loop()
{
 

 if (stringComplete) {
    Serial.println(inputString);
    lcd.setCursor(0,0);
    lcd.print(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }




}




 void serialEvent() {
  while (Serial.available()) {
    lcd.clear();
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:


  if (inChar == 'a'){
    inChar =' ';
    lcd.clear();
      lcd.print("Blue Light ");
 digitalWrite(blue, HIGH); 
   digitalWrite(red, LOW); 
    digitalWrite(green, LOW);
     
   
}
if (inChar == 'b'){
  inChar =' ';
   lcd.clear();
     lcd.print("Red Light ");
 digitalWrite(red, HIGH); 
   digitalWrite(blue, LOW); 
   digitalWrite(green, LOW); 
}

if (inChar == 'c'){
  inChar =' ';
   lcd.clear();
      lcd.print("Green Light ");
 digitalWrite(green, HIGH); 
  digitalWrite(blue, LOW); 
   digitalWrite(red, LOW); 
  
}

if (inChar == 'd'){
  inChar =' ';
   lcd.clear();
 lcd.print("Light Disable");
 digitalWrite(blue, LOW); 
   digitalWrite(red, LOW); 
    digitalWrite(green, LOW); 
    

}

    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
   
      stringComplete = true;
    
  }
}



