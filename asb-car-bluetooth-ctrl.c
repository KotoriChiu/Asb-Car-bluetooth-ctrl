#define SPEED 200
int rmoto = 12;
int rmoto_speed = 10;
int lmoto = 13;
int lmoto_speed = 11;

void setup(){
    for(int i=10;i<=13;i++) pinMode(i,OUTPUT);
    Serial.begin(9600);
}

void loop(){ 
    char bluetooth;
    if(Serial.available()){ //讀取藍芽是否有連上(boolean)
        bluetooth = Serial.read(); //Read bluetooth's data 
        Serial.println(bluetooth);
        switch(bluetooth){ //bluetooth moto ctrl
            case 'w': //前進
            bluetooth_data(1);
            break;
            case 's': //後退
            bluetooth_data(2);
            break;
            case 'a': //原地左轉
            bluetooth_data(3);
            break;
            case 'd': //原地右轉
            bluetooth_data(4);
            break;
            case 'q': //前左偏
            bluetooth_data(5);
            break;
            case 'e': //前右偏
            bluetooth_data(6);
            break;
            case 'z': //後左偏
            bluetooth_data(7);
            break;
            case 'c': //後又偏
            bluetooth_data(8);
            break;
            case 'p': //stop the car
            stay();
            break;
        }
    }
}

void bluetooth_data(int data){ //Moto Ctrl
    switch(data){
        case 1:
        digitalWrite(rmoto,HIGH);
        analogWrite(rmoto_speed,SPEED);
        digitalWrite(lmoto,HIGH);
        analogWrite(lmoto_speed,SPEED);
        break;
        case 2:
        digitalWrite(rmoto,LOW);
        analogWrite(rmoto_speed,SPEED);
        digitalWrite(lmoto,LOW);
        analogWrite(lmoto_speed,SPEED);
        break;
        case 3:
        digitalWrite(rmoto,HIGH);
        analogWrite(rmoto_speed,SPEED);
        digitalWrite(lmoto,LOW);
        analogWrite(lmoto_speed,SPEED);
        break;
        case 4:
        digitalWrite(rmoto,LOW);
        analogWrite(rmoto_speed,SPEED);
        digitalWrite(lmoto,HIGH);
        analogWrite(lmoto_speed,SPEED);
        break;
        case 5:
        digitalWrite(rmoto,HIGH);
        analogWrite(rmoto_speed,SPEED);
        digitalWrite(lmoto,HIGH);
        analogWrite(lmoto_speed,SPEED-150);
        break;
        case 6:
        digitalWrite(rmoto,HIGH);
        analogWrite(rmoto_speed,SPEED-150);
        digitalWrite(lmoto,HIGH);
        analogWrite(lmoto_speed,SPEED);
        break;
        case 7:
        digitalWrite(rmoto,LOW);
        analogWrite(rmoto_speed,SPEED);
        digitalWrite(lmoto,LOW);
        analogWrite(lmoto_speed,SPEED-150);
        break;
        case 8:
        digitalWrite(rmoto,LOW);
        analogWrite(rmoto_speed,SPEED-100);
        digitalWrite(lmoto,LOW);
        analogWrite(lmoto_speed,SPEED);
        break;
    }
}

void stay(){ //Stop Ctrl
    analogWrite(rmoto_speed,0);
    analogWrite(lmoto_speed,0);
}