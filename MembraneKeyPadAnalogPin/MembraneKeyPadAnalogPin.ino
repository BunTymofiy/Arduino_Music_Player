int keyIn = 0;
int keyVals [16] = 
{
  101, 175, 347, 107, 
  180, 350, 116, 188, 
  355, 194, 515, 518,
  520, 523, 124, 359
};
const char keys [16] = 
{
  '1', '2', '3', '4', 
  '5', '6', '7', '8',
  '9', '0', 'A', 'B', 
  'C', 'D', '*', '#'
};
int range = 1;

void setup() 
{
  Serial.begin(9600);

}

void loop() 
{
  keyIn = analogRead(A1);
  String temp = "";
  for(int i=0; i<=15; i++)
  {
    if(keyIn >= keyVals[i]-range && keyIn <= keyVals[i]+range)
    {
      temp = keys[i]; 
      Serial.println(temp); 
    }  
  }
  
  delay(300);
}
