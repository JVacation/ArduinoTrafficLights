                                    // Declaring Variables
int red1 = 2;
int yellow1 = 3;
int green1 = 4;
int red2 = 5;
int yellow2 = 6;
int green2 = 7;
int pedRed = 8;
int pedGreen = 9;
String input = "";


void setup() {                     // The code that I want to run once. Making the variables outputs and launching the Serial Monitor. Also prints instructions into the monitor.
    pinMode(red1, OUTPUT);
    pinMode(yellow1, OUTPUT);
    pinMode(green1, OUTPUT);
    pinMode(red2, OUTPUT);
    pinMode(yellow2, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(pedRed, OUTPUT); 
    pinMode(pedGreen, OUTPUT);
    Serial.begin(9600);
    Serial.flush();
    Serial.println("Enter the word \"pedestrian\" to simulate a pedestrian wanting to cross! Give it a few seconds to start simulation...");

}

// The loop code that I want to repeat
void loop() {
  digitalWrite(pedRed, HIGH);     // Turns the pedestrian red light on whilst the loop happens.
  while (Serial.available() > 0)  // makes sure that the serial monitor is available 
  {
  input += (char) Serial.read();  // input reads the input from the user.
  delay(5);                       // delay gives it some time to read
  }

  if (input == "")                // IF statement to see if the input is pedestrian or not, if it is pedestrian it runs the trafficlight2 function.
  {
    trafficLights1();
  }else if ( input == "pedestrian"){
      Serial.println("Simulating pedestrian now!");
      trafficLights2();
      input = "";
  } 

}



void trafficLights1 (){           // Main traffic light loop just for cars, no pedestrian
  // green 1 and red2 on
    digitalWrite(green1, HIGH);
    digitalWrite(red2, HIGH);
    Serial.println("G1 = ON, R2 = ON");
    delay(3000);
 // green 1 off, yellow 1 on, yellow 2 on,
 
    digitalWrite(green1, LOW);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, HIGH);
    Serial.println("G1 = OFF, Y1 = ON, Y2 = ON , R2 = ON");
    delay(3000);

 // yellow 1 off, red 1 on, yellow 2 and red 2 off, green 2 on   

    digitalWrite(yellow1, LOW);
    digitalWrite(red1, HIGH);
    digitalWrite(red2, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green2, HIGH);
    Serial.println("Y1 = OFF, Y2 = OFF , R1 = ON, R2 = OFF, G2 = ON");
    delay(3000);
    
    // turn off red and yellow, then turn on green
    digitalWrite(yellow2, HIGH);
    digitalWrite(green2, LOW);
    digitalWrite(yellow1, HIGH);
    Serial.println("R1 = ON Y1 = ON, Y2 = ON, G2 = OFF");
    delay(3000);

    digitalWrite(red1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green2, LOW);
}

void trafficLights2(){      // trafficlight2 is the functiton for the pedestrian. This runs if pedestrian is entered into the serial monitor. 
    digitalWrite(yellow1, LOW);
    delay(5);
    digitalWrite(red1, HIGH);
    digitalWrite(green2, LOW);
    digitalWrite(yellow2, HIGH);
    Serial.println("R1 = ON Y1 = OFF, Y2 = ON, G2 = OFF");
    delay(3000);

    digitalWrite(yellow2, LOW);
    digitalWrite(red2, HIGH);
    digitalWrite(pedRed, LOW);
    digitalWrite(pedGreen, HIGH);
    Serial.println("R1 = ON R2 = ON, Y2 = OFF, PR = OFF, PG = ON");
    delay(5000);
    digitalWrite(pedGreen, LOW);
    Serial.println("PG = OFF");
    delay(500);
    digitalWrite(pedGreen, HIGH);
    Serial.println("PG = ON");
    delay(500);
    digitalWrite(pedGreen, LOW);
    Serial.println("PG = OFF");
    delay(500);
    digitalWrite(pedGreen, HIGH);
    Serial.println("PG = ON");
    delay(500);
    digitalWrite(pedGreen, LOW);
    Serial.println("PG = OFF");
    delay(500);
    digitalWrite(pedGreen, HIGH);
    Serial.println("PG = ON");
    delay(500);
    digitalWrite(pedGreen, LOW);
    Serial.println("PG = OFF");
    delay(500);
    digitalWrite(pedGreen, HIGH);
    Serial.println("PG = ON");
    delay(500);
    digitalWrite(pedRed, HIGH);
    digitalWrite(pedGreen, LOW);
    digitalWrite(yellow1, HIGH);
    Serial.println("PG = OFF, PR = ON, Y1 = ON");
    delay(3000);

    digitalWrite(yellow1, LOW);
    digitalWrite(red1, LOW);
    Serial.println("R1 = OFF, Y1 = OFF, G1 = ON, R2 = ON");
  
}

                                                              // Created by James Holliday 06/03/2017
                                                              // StudentID : 168230005
                                                              // email: James.Holliday1@uni.brighton.ac.uk

 

