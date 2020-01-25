#include <mbed.h>
#include <stdbool.h>
#include <stdio.h>



DigitalOut greenLED(D11); //O0
DigitalOut blueLED(D10); //O1
DigitalOut redLED(D9); //O2
DigitalOut yellowLED(D6); //O3

Serial pc(USBTX, USBRX);
Serial device(D1, D0);

bool pc_activity;

int main() {

  unsigned char colorId;
  device.baud(9600);
    while(1) {

        if(pc.readable()) {
            colorId = pc.getc();
            device.putc(colorId);
            pc.printf("\n\nreceived : %x",colorId);
            pc_activity = !pc_activity;
        }

        if(device.readable()) {
            colorId =device.getc();
            pc.printf("\n Received %x \nSending : %x",colorId,colorId);
            switch (colorId) {
                case 48: //0
                    if (greenLED.read()){
                      greenLED.write(0);
                    }else{
                      greenLED.write(1);
                    }
                    break;
                case 49: //1
                    if (yellowLED.read()){
                      yellowLED.write(0);
                    }else{
                      yellowLED.write(1);
                    }
                    break;
                case 50: //2
                    if (blueLED.read()){
                      blueLED.write(0);
                    }else{
                      blueLED.write(1);
                    }
                    break;
                case 51: //3
                    if (redLED.read()){
                      redLED.write(0);
                    }else{
                      redLED.write(1);
                    }
                    break;
            }
        }
    }
} 