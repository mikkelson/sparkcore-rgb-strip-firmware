/**
 * rgbstrip.cpp
 * Created by James Mikkelson on 2014-05-04.
 *
 * Licensed under The MIT License
 * Redistributions of files must retain the above copyright notice
 *
 * @copyright     James Mikkelson on 2014-05-04.
 * @link          http://www.madcapsule.com/blog/author/James
 * @license       MIT License (http://www.opensource.org/licenses/mit-license.php)
 */
 
#define REDPIN A5      // RED LED
#define GREENPIN D1    // GREEN LED
#define BLUEPIN A4     ///BLUE LED
#define TESTPIN D7     // Onboard LED - Used to debug
 
#define FADESPEED 10    // Speed of pulse and flase effects
#define FLASHSPEED 1   // Default speed of flash effects


 
void setup() {
  Spark.function("pulse", pulse);
  Spark.function("rgbPulse", rgbPulse);
  Spark.function("flash", flash);
  Spark.function("colour", colour);
  pinMode(TESTPIN, OUTPUT);
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}
 
 
 
void loop() {

}


/*
*   flash blinks one colour
*
*/
  int flash(String colour)
  {

      int n = 10;
    
      while (n>0) {

        analogWrite(REDPIN, 255);
        delay(FLASHSPEED);
        analogWrite(REDPIN, 0);
        --n;
        
      }

  }
  
  
/*
*   rpPulse pulses one colour
*
*/  
    int pulse(String colour)
  {

      int r;
      int n = 10;
    
      while (n>0) {

            for (r = 0; r < 256; r++) {
                analogWrite(REDPIN, r);
                delay(FADESPEED);
            }
        
            for (r = 0; r < 256; r++) {
                analogWrite(REDPIN, r);
                delay(FADESPEED);
            } 
            
        --n;
      }
      

  }
  
  
/*
*   rgbPulse pulses through Red Green Blue in order
*
*/
    int rgbPulse(String colour)
  {

      int r;
      int n = 10;
    
      while (n>0) {

            for (r = 0; r < 255; r++) {
                analogWrite(REDPIN, r);
                delay(FADESPEED);
            }
            
            analogWrite(REDPIN, 0);  
        
            for (r = 0; r < 255; r++) {
                analogWrite(GREENPIN, r);
                delay(FADESPEED);
            } 
            
            analogWrite(GREENPIN, 0);            

            for (r = 0; r < 255; r++) {
                analogWrite(BLUEPIN, r);
                delay(FADESPEED);
            }
            
            analogWrite(BLUEPIN, 0);            
            
        --n;
      }
      

  }  
  
/*
*   colour mixes one colour and leaves on
*   TODO: set colour from parameters
*
*/  
    int colour(String colour)
  {

        analogWrite(REDPIN, 249);
        analogWrite(GREENPIN, 50);
        analogWrite(BLUEPIN, 211);


  }
    