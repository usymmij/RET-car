int b1 = 2;
int b2 = 6;
int b3 = 5;
int b4 = 4;
int x1 = A0;
int y1 = A1;
int x2 = A3;
int y2 = A4;
int butval1;
int butval2;
int tankL = -1;
int tankR = -1;

void setup() {
    Serial.begin(9600);
    pinMode(b1, INPUT);
    pinMode(b2, INPUT);
    pinMode(b3, INPUT);
    pinMode(b4, INPUT);
    digitalWrite(b1, HIGH);
    digitalWrite(b2, HIGH);
}

void loop() {
    butval1 = digitalRead(b3);
    butval2 = digitalRead(b4);
    if (butval1 == 1 || butval2 == 1) {
        delay(500)
        if (butval1 == 1) {
            tankL *= -1;
        }
        else {
            tankR *= -1;
        }
        if (tankR == tankL) {
            tankR = -1;
            tankL = -1;
        }
    }
    if (tankR > tankL) {
        String a = String((analogRead(y1) + analogRead(x1)) / 2, DEC);
        String b = String((analogRead(y1) - analogRead(x1)) / 2, DEC);
    }
    else if (tankR < tankL) {
        String a = String((analogRead(y2) + analogRead(x2)) / 2, DEC);
        String b = String((analogRead(y2) - analogRead(x2)) / 2, DEC);
    }
    else {
        String a = String(analogRead(y1), DEC);
        String b = String(analogRead(y2), DEC);
    }
    String c = String(digitalRead(b1), DEC);
    String d = String(digitalRead(b2), DEC);
    String output = String("20," + a + "," + b + "," + c + "," + d + "\n");
    Serial.print(output);
    delay(50);
}
