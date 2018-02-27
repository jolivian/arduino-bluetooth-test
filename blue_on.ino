int LED_INPUT = 9; // Initializing pin number 

void setup() //The setup function will only run once, after each powerup.It initializes and sets the initial values
{
  Serial.begin(9600);   //Sets the baud for serial data transmission (Bits Per Second)
  pinMode(LED_INPUT,OUTPUT); //Specify behaviour of pin to work either as an input or an output
}

void loop() 
{
  byte data;  //Recived data will get stored in this variable
  if(Serial.available()> 0) //Here We're checking whether data is available or not
  {
    data=Serial.read(); //Data received
    if(data==1)//LED ON..
    {
      digitalWrite(LED_INPUT,HIGH);  // Write a HIGH or a LOW value to a digital pin
    }
    if(data== 0)//LED OFF
    {
      digitalWrite(LED_INPUT,LOW);
    }

    Serial.print("I received: ");
   Serial.println(data);
  }
 
}

/*
 * Notes:
 * connection set-up:  
 * VCC: 5V source
 * GND: GND next to 5V source
 * TX: RX->0
 * RX: TX->1 with 1k and 2k ohm. 1k to ground and 2k to TX port. 
 * STATE: not used
 * EN: NOT used. 
 * 
 * 
 * LED setup:
 * 9 as output so connect long end to pin 9 and short end to GND on same side as pin 9. 
*/
