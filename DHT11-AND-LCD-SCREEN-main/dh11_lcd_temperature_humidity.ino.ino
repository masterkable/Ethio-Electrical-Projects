#include <LiquidCrystal_I2C.h>
#include <dht.h>
#include <Wire.h>


dht DHTSENSOR;
int DHT_Sensor_pin = 4;
LiquidCrystal_I2C lcd_screen(0x27, 16,2);


void setup() {
  Serial.begin(9600);  
  lcd_screen.begin(16,2);
  lcd_screen.backlight();
}

void loop() {
  DHTSENSOR.read11(DHT_Sensor_pin);
  String temp = "Temp : " + String(DHTSENSOR.temperature) + " C";
  String  humid = "humid : " + String(DHTSENSOR.humidity) + " %";
  lcd_screen.setCursor(0,0);
  lcd_screen.print(temp);
  lcd_screen.setCursor(0,1);
  lcd_screen.print(humid);
  delay(500);

}
// You can use the lcd_scroll function to add some spice to the display ;)
// usage : lcd_scroll(lcd_screen,temp,500,0);
// lcd_screen object
// temperature or Humdidty  String to be displayed
// 500 - delay
// 0/1 - Lcd screen Row
void lcd_scroll(LiquidCrystal_I2C& lcd,String string,int wait, int row){
  bool run = true;
  for(int i = 0;i<16;i++){
    static int j = 1;
    lcd.setCursor(i,row);
    lcd.print(string);
    delay(wait);
    lcd.clear();
    if(i == (16-string.length())){
        while(run == true){
          i++;
          lcd.setCursor(0,row);
          lcd.print(string.substring(string.length()-j));
          j++;
          lcd.setCursor(i,row);
          lcd.print(string);
          delay(wait);
          lcd.clear();
          //i++;
          if(string.length()==j){run = false;}
        }
      }
      if(string.length()==j){j = 1;break;}
    
  }
  }
