int input[3] = {2, 4, 7};
int output[3] = {3, 5, 9};
int numOfPlayers = 3;
int winnerId = -1;

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
  for (int i = 0;i < numOfPlayers; i++) {
    pinMode(input[i], INPUT_PULLUP);
    pinMode(output[i], OUTPUT);
  }
}

void loop()
{
  bool answer = false;
  for (int i = 0; i < numOfPlayers; i++) {
     int val = digitalRead(input[i]);
     if (val == HIGH) {
        answer = true;
        winnerId = i;
        break;
     }
  }
  
  if(answer) {
     digitalWrite(13, HIGH);
     Serial.write(1);
     ledUp(winnerId);
     delay(2000);
  }
  else {
    digitalWrite(13, LOW);
    ledUp(-1);
  }
}

void ledUp(int winnerId)
{
  for (int i = 0; i < numOfPlayers; i++) {
    if (i == winnerId)
      digitalWrite(output[winnerId], HIGH);
    else
      digitalWrite(output[i], LOW);
  }
}

