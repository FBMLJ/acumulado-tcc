int valor = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, INPUT);
}

void loop() {
  delay(500);
  valor = 5;
  valor = analogRead(4);
  Serial.println(valor);
  // put your main code here, to run repeatedly:

}
