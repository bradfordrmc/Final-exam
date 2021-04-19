from subprocess import call #import the call function needed for espeak from the subprocess library
import speech_recognition as sr #import the speech recognition library
import serial #import serial library for printing to terminal
import RPi.GPIO as GPIO      #import GPIO library to acces pi pins
import os, time # import time and os libraries
r= sr.Recognizer() #assigns the speech recognizer function to variable r
led=27 #setting up gpio pin 27 for the led 
text = {} #initalizing text variable
text1 = {} #initalizing text1 variable
GPIO.setwarnings(False) #disable GPIO warnings
GPIO.setmode(GPIO.BCM) # use GPIO numbers not board numbers
GPIO.setup(led, GPIO.OUT) #sets LED pin to output

#function to record the voice audio and store the value in variable audio. accounts for Ambient noise using speech recognition library
#and also prints directions to the user in the terminal below
def listen1():
    with sr.Microphone(device_index = 2) as source:
               r.adjust_for_ambient_noise(source)
               print("Say command");
               audio = r.listen(source)
               print("got it");
    return audio

#receives audio and google transfroms it into text, prints what you said to the screen, or gives error message
def voice(audio1):
       try: 
         text1 = r.recognize_google(audio1) 
         print ("you said: " + text1);
         return text1; 
       except sr.UnknownValueError: 
          call(["espeak", "-s140  -ven+18 -z" , "Raspberry could not understand"])
          print("Raspberry could not understand") 
          return 0

#assigns local vairables to the values received from the other functions and peforms a check to see if
# the light on or light off command is satisfied. activates led pin according to which command was said
def main(text):
       audio1 = listen1() 
       text = voice(audio1);
       if 'light on' in text:
          GPIO.output(led , 1)
          call(["espeak", "-s140  -ven+18 -z" , "Switching ON the Light now"])
          print ("Lights on");
       elif 'light off' in text:
          GPIO.output(led , 0)
          call(["espeak", "-s140  -ven+18 -z" , "Switching OFF the Light now"])
          print ("Lights Off");  
       text = {}

#main chunk of cod that assigns variables and uses espeak to greet user if starting command is said,
#also will repeat directions phrase if proper command is not said first.
if __name__ == '__main__':
 while(1):
     audio1 = listen1() 
     text = voice(audio1)
     if text == 'okay raspberry': 
         text = {}
         call(["espeak", "-s140  -ven+18 -z" ," Hello User, what do you want?"])
         main(text)
     else:
         call(["espeak", "-s140 -ven+18 -z" , " Please say. okay raspberry. to continue"])
