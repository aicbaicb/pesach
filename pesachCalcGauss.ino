//Gauss's Pesach calculator variables
int year = 2021;
long A = year + 3760; //hebrew year
int a;
int b;
long M;
float m;
int c;
int month = 3;


void setup() {
  Serial.begin(57600);
gauss();
}

void loop() {
  
}

void gauss() {
  for (year = 2020; year < 2100; year = year + 1)
  { A = year + 3760;
    a = ((12 * A) + 17L ) % 19;
    b = A % 4;
    M = 32.0440931611 + (1.55424179662 * a) + b / 4.0 - (.00317779402 * A);
    m = 32.0440931611 + (1.55424179662 * a) + b / 4.0 - (.00317779402 * A);
//    m = (32L + (4343 / 98496)) + (1 + (272953 / 492480) * a) + b / 4 - ((313 / 98496) * A);
    c = (3 * A + 5 * b + M + 5) % 7;
   // M = int(m);
      m = m - M;
      if (c == 2 || c == 4 || c == 6) {
        M = M + 14;
      }
      else if (c == 1 && a > 6 && m >= 0.63287037037) {
        M = M + 15;
      }
      else if (c == 0 && a > 11 && m >= .89772376543) {
        M = M + 14;
      }
      else {
        M = M + 13;
      }
      if (M <= 31) {
        month = 3;
      }
      else {
        month = 4;
                M = M - 31;
      }
    
   
    Serial.print(A);
    Serial.print(" - ");
//    Serial.print("     a: ");
//    Serial.print(a);
//    Serial.print(" b: ");
//    Serial.print(b);
//    Serial.print(" c: ");
//    Serial.print(c);
//    Serial.print(" m: ");
//    Serial.print(m);
Serial.print(M);
if (month==3) {
  Serial.print(" March ");
}
else {
  Serial.print(" April ");
}
Serial.println(year);
   
    
    delay(50);
  }
}
