const byte led[]={14,13,12,11,10,9,8,7};

const int delaytime = 100;
int i;

void setup() 
{
  for(i=0;i<7;i++)
  {
    pinMode(led[i],OUTPUT);
  }
}

void loop()
{
//全暗亮
  for(i=0;i<8;i++) 
  {
    digitalWrite(led[i],HIGH);
  }
  delay(500);
  for(i=0;i<8;i++) 
  {
    digitalWrite(led[i],LOW);
  }
  delay(500);
  for(i=0;i<8;i++) 
  {
    digitalWrite(led[i],HIGH);
  }
  delay(500);
  for(i=0;i<8;i++) 
  {
    digitalWrite(led[i],LOW);
  }
  delay(500);
//跑
  for(i=0;i<8;i++) 
  {
    digitalWrite(led[i],HIGH);
    delay(delaytime);
    digitalWrite(led[i],LOW);
  }

  for(i=8;i>0;i--)
  {
    digitalWrite(led[i],HIGH);
    delay(delaytime);
    digitalWrite(led[i],LOW);
  }


  
  }
