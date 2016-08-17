import processing.serial.*;
Serial myPort;
import processing.sound.*;
SoundFile sound;

//boolean firstContact = false;

void setup () {
  size(800, 600, P3D);
//=====================Serial====================//
  String portName = "/dev/cu.usbmodem1421";
  printArray(Serial.list());
  myPort = new Serial(this, portName, 9600);
  myPort.clear();
  myPort.bufferUntil('\n'); 
//=====================Serial End=================//
  
  sound = new SoundFile(this, "bell.wav");
  //sound.play();
}

void draw()
{
  background(0);
  stroke(255);
  
  if ( myPort.available() > 0) {
    int val = myPort.read(); 
    println(val);
    if (val == 1)
      sound.play();
  }
}

void serialEvent( Serial myPort) {
  // read a byte from the serial port:
     //myPort.write('A');
     String input = myPort.readString();
    //println(input); 
     String[] numbers = split(input, ',');
   
     myPort.write('A');
}