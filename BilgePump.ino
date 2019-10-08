int Waterheight = 0;   //Holds the value.
int Pinin = A5;        //Input pin used.
int Pump = 13;         //Output pin used.

bool IsPumpTurnedOn = false; //Checks if pump is turned on.

void setup()
{
  //Start the serial console.
  Serial.begin(9600);
  //Sets the digital pin 13 as output.
  pinMode(Pump, OUTPUT);
}

void loop()
{
  //Read data from analog pin and store it to resval variable.
  Waterheight = analogRead(Pinin);

  if (Waterheight>=700 && !IsPumpTurnedOn)
  {
    //Sets pump pin on.
    digitalWrite(Pump, HIGH);
    IsPumpTurnedOn = true;
  }
  else if(Waterheight<=100 && IsPumpTurnedOn)
  {
    //Sets pump pin off.
    digitalWrite(Pump, LOW);
    IsPumpTurnedOn = false;
  }
  delay(10000);
}
