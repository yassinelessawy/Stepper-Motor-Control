
 #include <BasicStepperDriver.h>             // stepper Driver library must be included https://github.com/laurb9/StepperDriver 
 #define Stepper1_STEPS 200.00               // number of the steps inside the motor *specifc for every motor but in most nema type motors its 200
 #define Stepper1_RPM 300.00                 // revlutions per minute   =>(for a lead screw =>(linear speed in cm/s *600)/lead in mm) , (for a belt and pulley system =>((linear speed in cm/s *600)/(pulley's tooth number*the belt pitch in mm))
 #define Stepper1_TURNS 62.00                // number of turns you want=>( for a lead screw => stroke(the travel distance)in mm/lead in mm ) , (for a belt and pulley system => stroke(the travel distance) in mm/(pulley's tooth number*the belt pitch in mm))           
 #define Stepper1_DIR 2                      // direction pin number
 #define Stepper1_STEP 3                     // step pin number
// #define Stepper1_ENABLE 4                 // enable pin number

 BasicStepperDriver stepper1(Stepper1_STEPS, Stepper1_DIR, Stepper1_STEP);
 //BasicStepperDriver stepper1(Stepper1_STEPS, Stepper1_DIR, Stepper1_STEP, Stepper1_ENABLE);

 void STEPPER_1_OPEN()
   {
    Serial.println("STEPPER_1 OPEN");
    //stepper1.move(Stepper1_STEPS*Stepper1_TURNS);                                      //Moving motor to original position using steps
    stepper1.rotate(360*Stepper1_TURNS);                                                 //Moving motor one full revolution using the degree notation
   }
   
 void STEPPER_1_CLOSE()
   {
    Serial.println("STEPPER_1 CLOSE");
    //stepper1.move(-Stepper1_STEPS*Stepper1_TURNS);                                    //Moving motor to original position using steps
    stepper1.rotate(-360*Stepper1_TURNS);                                               //Moving motor one full revolution using the degree notation
   }

 void setup()
   {
    Serial.begin(9600);
    stepper1.begin(Stepper1_RPM);
   }

 void loop()
   {
    // stepper1.enable();                                         //energize coils - the motor will hold position
    if(Serial.available()>0)
     {
      char letter = Serial.read();
      if(letter == '6')
       {
         STEPPER_1_OPEN();
       }
      else if(letter == '4')
       {
         STEPPER_1_CLOSE();
       }
     }
     // stepper1.disable();                                       //pause and allow the motor to be moved by hand
   }
