const int redPin = 8;//Sets digital pin as Red LED's control
const int bluePin = 10; //Sets digital pin as Blue LED's control
const int greenPin = 9;//Sets digital pin as Green LED's control 

int condVal; //this sets an integer called condVal which is used in later calculations in the code below
int val;
double dif;
int count=0;
double total = 0;





void setup() {
  Serial.begin(9600); //establishes a connection to the Arduino at a baud rate of 9600
  

  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

}

void loop() 
{ //everything between these curly braces will Loop
  
      condVal = analogRead(A1);
      //val = analogRead(A2);
       //this sets the integer condVal equal to the value read from analog @ on the Arduino
      double voltage = condVal*(5.0/1023.00000); 
      
    
                  
      //calculation of relative conductivity, essentially this is a measure of the voltage drop
      //across the mass sensor, the conductivity increases, the voltage drop across the divider increases
      //probe also increases
     total += voltage;
     count++;
     double Vavg = total/(double)count;

    double mass = 36.2*pow(2.718,voltage);
    
      // Setting restrictions for LED

    if(mass < 120 && mass > 20){
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, HIGH);
      digitalWrite(greenPin, LOW);
    }
    if(mass < 200 && mass >120){
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(greenPin, LOW);
    }
    if (mass < 310 && mass > 200){
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, LOW);
      digitalWrite(greenPin, HIGH);  
          
    }
    if (mass >= 310){
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, HIGH);
      digitalWrite(greenPin, LOW);

    }
      Serial.print("Voltage: ");
     //Serial.print(voltage,4);
     //.print("\t");
     
     Serial.print(voltage,4);
    //  Serial.print("\tResistance: ");
    //  Serial.print(rx);
     Serial.print("\t");

    Serial.print("Mass: ");

    Serial.print(mass,1);
    Serial.print("\n");

  delay(500); //delay before looping, numerical values are in milliseconds
}
