/*
  Transmits data using a white LED and recieves it using a photoresistor
*/
int a=7; 
int b=6; 
int c=5; 
int d=11; 
int e=10; 
int f=8; 
int g=4; 
int dp=9; 
#define STX 0x70
#define ETX 0x71
int ledPin= 13;
int inPin = 12;
char txButton, txTilt, txPot, txA, txB, txC, txD;
char txBuffer[8] = {0,0,0,0,0,0,0,ETX};
char rxBuffer[7];
char rxButton, rxTilt, rxPot, rxA, rxB, rxC, rxD;
int  rx_index;

  




int ledState = LOW;             // ledState used to set the LED


char encrypt(char in_char)
{
  char out_char;
  
  out_char = in_char;
  
  return out_char;
}


char decrypt(char in_char)
{
  char out_char;
  
  out_char = in_char;
  
  return out_char;
}



// the setup routine runs once when you press reset:
void setup()
{
  // set the digital pin as output:
  pinMode(3, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void display1(void) 
{ 
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
} 
//display number2
void display2(void) 
{
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
} 
// display number3
void display3(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(g,HIGH);
} 
// display number4
void display4(void) 
{ 
    digitalWrite(f,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  
} 
// display number5
void display5(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
} 
// display number6
void display6(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
} 
// display number7
void display7(void) 
{   
   digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
} 
// display number8
void display8(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
  digitalWrite(f,HIGH);  
} 
void clearDisplay(void) 
{ 
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(g,LOW);
  digitalWrite(c,LOW);
    digitalWrite(d,LOW);  
    digitalWrite(e,LOW);  
  digitalWrite(f,LOW);  
} 
void display9(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
  digitalWrite(f,HIGH);  
} 
void display0(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
  digitalWrite(f,HIGH);  
} 
void displayAll(void)
{digitalWrite(a, HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);  
digitalWrite(e,HIGH);  
digitalWrite(f,HIGH);  
digitalWrite(g,HIGH);
 
  }
  
void readInputs()
{int txTilt_read = digitalRead(inPin);
  if(txTilt_read == HIGH){
    txTilt = 0x42;
    }
  else{
    txTilt = 0x43;
    }
  
  int txPot_int = analogRead(A1);
  if(txPot_int < 102.3){
    txPot = 0x44;
  }
  else if(102.3 < txPot_int && txPot_int < 204.6 ){
    txPot = 0x45;
    }
  else if(204.6 < txPot_int && txPot_int < 306.9){
    txPot= 0x46;
    }
    else if(306.9 < txPot_int && txPot_int < 409.2){
    txPot= 0x47;
    }
  else if(409.2 < txPot_int && txPot_int < 511.5){
    txPot= 0x48;
    }
  else if(511.5 < txPot_int && txPot_int < 613.8){
    txPot= 0x49;
    }
  else if(613.8 < txPot_int && txPot_int < 716.1){
    txPot= 0x50;
    }
  else if(716.1< txPot_int && txPot_int <  818.4){
    txPot= 0x51;
    }
  else if(818.4< txPot_int && txPot_int <  920.7){
    txPot= 0x52;
    }
  else if(920.7< txPot_int && txPot_int <  1023){
    txPot= 0x53;
    }
    
 
  // Reads the inputs in the mini-projects
  // Uses txButton, txTilt, txPot, txA, txB, txC, txD;
  
}

void writeOutputs()

{
  if(rxTilt == 66){
    digitalWrite(ledPin, HIGH);
}
 else if(rxTilt == 0x43)
 {
  digitalWrite(ledPin, LOW);
  }
    

switch(rxPot){
  case 0x44:
  clearDisplay();
  display0();
  delay(100); 
  break;

  case 0x45:
  clearDisplay();
  display1();
  delay(100);
  break;

  case 0x46:
  clearDisplay();
  display2();
  delay(100); 
  break;

  case 0x47:
  clearDisplay();
  display3();
  delay(100); 
  break;

  case 0x48:
  clearDisplay();
  display4();
  delay(100); 
  break;

  case 0x49:
  clearDisplay();
  display5();
  delay(100);
  break;

  case 0x50:
  clearDisplay();
  display6();
  delay(100);
  break;

  case 0x51:
  clearDisplay();
  display7();
  delay(100);
  break;

  case 0x52:
  clearDisplay();
  display8();
  delay(100); 
  break;

  case 0x53:
  clearDisplay();
  display9();
  delay(100);
  break;

  default:
  display0();
  }

  
  // Writes the outputs in the mini-projects
  // Uses rxButton, rxTilt, rxPot, rxA, rxB, rxC, rxD;
    
}
const long txInterval = 200;              // interval at which to tx bit (milliseconds)
int tx_state = 0;
char tx_char = 'H';
char chr;
unsigned long previousTxMillis = 0;        // will store last time LED was updated

char tx_string[] = "Hello World";
#define TX_START_OF_TEXT  -1
int tx_string_state = TX_START_OF_TEXT;



char getTxChar()
{
  char chr;
  
  switch (tx_string_state)
  {
    case TX_START_OF_TEXT:
    tx_string_state = 0;
    txBuffer[0] = txButton;
    txBuffer[1] = txTilt;
    txBuffer[2] = txPot;
    txBuffer[3] = txA;
    txBuffer[4] = txB;
    txBuffer[5] = txC;
    txBuffer[6] = txD;
    return STX;
    break;
    
    default:
    chr = txBuffer[tx_string_state];
    tx_string_state++;
    if (chr == ETX)  /* End of string? */
    {
      tx_string_state = TX_START_OF_TEXT;  /* Update the tx string state to start sending the string again */
      return ETX;  /* Send End of Text character */
    }
    else
    {
      return chr;  /* Send a character in the string */
    }
    break;
  }
}

void txChar()
{
  unsigned long currentTxMillis = millis();

  if (currentTxMillis - previousTxMillis >= txInterval)
  {
    // save the last time you blinked the LED (improved)
    previousTxMillis = previousTxMillis + txInterval;  // this version catches up with itself if a delay was introduced

    switch (tx_state)
    {
      case 0:
        chr = encrypt(getTxChar());
        digitalWrite(3, HIGH);  /* Transmit Start bit */
        tx_state++;
        break;

      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
        if ((chr & 0x40) != 0)   /* Transmit each bit in turn */
        {
          digitalWrite(3, HIGH);
        }
        else
        {
          digitalWrite(3, LOW);
        }
        chr = chr << 1;  /* Shift left to present the next bit */
        tx_state++;
        break;

      case 8:
        digitalWrite(3, HIGH);  /* Transmit Stop bit */
        tx_state++;
        break;

      default:
        digitalWrite(3, LOW);
        tx_state++;
        if (tx_state > 20) tx_state = 0;  /* Start resending the character */
        break;
    }
  }
}



const long rxInterval = 20;              // interval at which to read bit (milliseconds)
int rx_state = 0;
char rx_char;
unsigned long previousRxMillis = 0;        // will store last time LED was updated
int rx_bits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


void rxChar()
{
  unsigned long currentRxMillis = millis();
  int sensorValue;
  int i;

  if (currentRxMillis - previousRxMillis >= rxInterval)
  {
    // save the last time you read the analogue input (improved)
    previousRxMillis = previousRxMillis + rxInterval;  // this version catches up with itself if a delay was introduced

    sensorValue = analogRead(A0);
    //Serial.println(rx_state);

    switch (rx_state)
    {
      case 0:
        if (sensorValue >= 900)
        {
          rx_bits[0]++;
          rx_state++;
        }
        break;

      case 100:
        if ((rx_bits[0] >= 6) && (rx_bits[8] >= 6))  /* Valid start and stop bits */
        {
          rx_char = 0;

          for (i = 1; i < 8; i++)
          {
            rx_char = rx_char << 1;
            if (rx_bits[i] >= 6) rx_char = rx_char | 0x01;
          }
          rx_char = decrypt(rx_char);

          Serial.println(rx_char + 0);          
          switch (rx_char)
          {
            case STX:
            rx_index = 0;
            break;
            
            case ETX:
            rxButton = rxBuffer[0];
            rxTilt = rxBuffer[1];
            rxPot = rxBuffer[2];
            rxA = rxBuffer[3];
            rxB = rxBuffer[4];
            rxC = rxBuffer[5];
            rxD = rxBuffer[6];
            rx_index = 0;
            break;
            
            default:
            rxBuffer[rx_index] = rx_char;
            rx_index++;
            break;
          }
        }
        else
        {
          Serial.println("Rx error");
        }
//        for (i = 0; i < 10; i++)  /* Print the recieved bit on the monitor - debug purposes */
//        {
//          Serial.println(rx_bits[i]);
//        }
        for (i = 0; i < 10; i++)
        {
          rx_bits[i] = 0;
        }
        rx_state = 0;
        break;

      default:
        if (sensorValue >= 900)
        {
          rx_bits[rx_state / 10]++;
        }
        rx_state++;
        break;
    }
  }

}



// the loop routine runs over and over again forever:
void loop()
{
  readInputs();
  txChar();
  rxChar();
  writeOutputs();
}
