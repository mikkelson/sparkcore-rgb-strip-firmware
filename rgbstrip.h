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
 
#define FADESPEED 5    // Speed of pulse and flase effects
#define FLASHSPEED 1   // Default speed of flash effects


 
void setup() {
  Spark.function("pulse", pulse);
  Spark.function("flash", flash);
  pinMode(TESTPIN, OUTPUT);
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}
 
 
 
void loop() {

}

  int flash(String colour)
  {

      int n = 10;
    
      while (n>0) {

        analogWrite(REDPIN, 255);
        delay(FADESPEED);
        analogWrite(REDPIN, 0);
        --n;
        
      }

  }
  
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