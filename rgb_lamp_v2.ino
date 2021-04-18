
#include <IRremote.h>
int IRpin=11;
IRrecv IR(IRpin);
decode_results cmd;

int redpin= 13;
int greenpin = 12;
int bluepin = 4;
int red2= 10;
int green2 = 9;
int blue2 = 8;
int red3= 7;
int green3 = 6;
int blue3 = 5;

void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(blue3, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue2, OUTPUT); 
}


void loop() {
  if(IR.decode(&cmd)){
    
    if (cmd.value==0xFFA25D){
      RGB_color(255, 255, 255, 255, 255, 255, 0, 0, 0); // White
    }
  
    if (cmd.value==0xFFE21D){
      RGB_color(0, 0, 0, 0, 0, 0, 255, 255, 255); // off
    }
    if(cmd.value==0xFF30CF){ //1
      RGB_color(255, 0, 0, 255, 0, 0, 0, 255, 255); // Red 
    }
    
    if (cmd.value==0xFF18E7){ //2
       RGB_color(0, 255, 0, 0, 255, 0, 255, 0, 255); // Green
    }
    
    if (cmd.value==0xFF7A85){ //3
       RGB_color(0, 0, 255, 0, 0, 255, 255, 255, 0); // Blue  
    }
    if (cmd.value==0xFF10EF){ //4
      RGB_color(255, 255, 125, 255, 255, 125, 125, 125, 255); // Raspberry
    }
    
    if(cmd.value==0xFF38C7){ //5
      RGB_color(0, 255, 255,0, 255, 255,255, 0, 0); // Cyan
    }
    
    if (cmd.value==0xFF5AA5){ //6
      RGB_color(255, 0, 255,255, 0, 255,0, 255, 0 ); // Magenta
    }
    
    if (cmd.value==0xFF42BD){ //7
      RGB_color(255, 255, 0, 255, 255, 0, 0, 0, 255); // Yellow
    }
    if(cmd.value==0xFF4AB5){ //8
      RGB_color(255, 255, 255, 255, 255, 255, 0, 0, 0); // White
    }
    
    if(cmd.value==0xFF52AD){ //9
      RGB_color(0, 0, 0, 0, 0, 0, 255, 255, 255); // off
    }
    IR.resume();
    Serial.println(cmd.value,HEX);
  }
}
void RGB_color(int red1val, int green1val, int blue1val, int red2val, int green2val, int blue2val, int red3val, int green3val, int blue3val)
 {
  analogWrite(redpin, red1val);
  analogWrite(red2,red2val);
  analogWrite(red3,red3val);
  analogWrite(greenpin, green1val);
  analogWrite(green2,green2val);
  analogWrite(green3,green3val);
  analogWrite(bluepin, blue1val);
  analogWrite(blue2,blue2val);
  analogWrite(blue3,blue3val);
}
