#include "servo.h" //Driver library für PCA9685/Adafruit HAT
#include <iostream>
#include <stdio.h>
//#include <ncurses.h>
//#include <thread>
#include <unistd.h>

#include <stdio.h>
#include <string.h>
//#include <ncurses.h>
//#include <thread>
#include <unistd.h>
#include <wiringPi.h>   // für Pindefinition
#include <time.h>       // nanosleep()


#ifdef __cplusplus  //für I2C "C" Driver des 128x64 OledDisplays
extern "C" {
#endif
//#include "ssd1306_i2c.h"
#include "ssd1306_i2c.c"
#ifdef __cplusplus 
}
#endif

#define S2 4
#define S3 5
#define sensorOut 0

double Calred = 0;
double Calblue = 0;
double Calgreen = 0;

//frequency scalling to 2%, 20%, 100%
// S0 = Low + S1 = High -> 2%
// S0 = High + S1 = Low -> 20%
// S0 = High + S1 = High -> 100%

using namespace std;
// event counter Variable
volatile int eventCounter = 0;
int p = 0;
// myInterrupt:  Wir nach jedem Interrupt aufgerufen
void myInterrupt(void) {
    eventCounter++;
}


int main () {
    if (wiringPiSetup () < 0) {
        fprintf (stderr, "Unable to setup wiringPi: %s\n", strerror (errno));
        return 1;
    }
    
    
    //Motor und Hat Initiallizierung
    
    int c=0, p=0, f, i;
    printf ("Testing testing\n");
    //Address values.
    PCA9685 pwm;
    pwm.init(1,0x40);
    usleep(1000 * 100);
    printf ("Setting frequency..\n");
    pwm.setPWMFreq (60);
    usleep(1000 * 1000);
    
    int j=220;
   printf ("geben Sie 1 , 2, 3, 4, 5 ein\n");
    scanf ("%d",&c);
    
    /*Motor auf Ausgang Position
    pwm.setPWM(4,0,250);
    for(p=j; p<240;){
        p=p+10;
        pwm.setPWM(0,0,p);
        printf ("%d\n",p);
        usleep(1000 * 100);
        j=p;
    }
    for(p=j;p>240;)
    {
        p=p-10;
        pwm.setPWM(0,0,p);
        printf ("%d\n",p);
        usleep(1000 * 100);
        j=p;
    }*/
  /*Comentario sensor  
    printf ("Kalibrierung des Sensors\n");
    sleep(3);
    //Steuerpins S2/S3 als Output
    pinMode (S2, OUTPUT);
    pinMode (S3, OUTPUT);
    pinMode (sensorOut, INPUT);
    
    //Definition des nanosleeps
    struct timespec tim, tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 1000000;
    
    //Start der Interruptroutine
    if ( wiringPiISR (sensorOut, INT_EDGE_FALLING, &myInterrupt) < 0 )
    {
        
        return 1;
    }*/
    /*
    // Kalbierungswerte bestimmen
    //500ms Messung Rot
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    while ( i <= 500 )
    {
        // printf( "%d\n", eventCounter );
        nanosleep(&tim,&tim2);
        i++;
    }
    Calred = (eventCounter/500);
    printf ("Calred:%.9f\n",Calred);
    eventCounter = 0;
    i = 0;
    
    //500ms Messung Blau
    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
    while ( i <= 500 )
    {
        // printf( "%d\n", eventCounter );
        nanosleep(&tim,&tim2);
        i++;
    }
    Calblue = (eventCounter/500);
    printf ("Calblue:%.9f\n",Calblue);
    eventCounter = 0;
    i = 0;
    
    //500ms Messung Gr  n
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    while ( i <= 500 )
        
    {
        // printf( "%d\n", eventCounter );
        nanosleep(&tim,&tim2);
        i++;
    }
    Calgreen = (eventCounter/500);
    printf ("Calgreen:%.9f\n",Calgreen);
    eventCounter = 0;
    i = 0;
    */
    //Wei ^=er Stein in Box
    //
    
    /*pwm.setPWM(4,0,400);
    for(p=j; p<290;){
        p=p+10;
        pwm.setPWM(0,0,p);
        printf ("%d\n",p);
        usleep(1000 * 100);
        j=p;
    }
    
    pwm.setPWM(4,0,250);
    /* for(p=j;p>240;)
     {
     p=p-10;
     pwm.setPWM(0,0,p);
     printf ("%d\n",p);
     usleep(1000 * 100);
     j=p;
     }*/
  /*Comentarion sensor 2
    double rot, blau, gruen;
    bool x=true;
    bool red, blue, green,black,yellow,white;
    
    while(1){
        
        //Motor auf Ausgang Position
        //pwm.setPWM(12,0,250);
        for(p=j; p<240;){
            p=p+10;
            pwm.setPWM(12,0,p);
            printf ("%d\n",p);
            usleep(1000 * 100);
            j=p;
        }
        for(p=j;p>240;)
        {
            p=p-10;
            pwm.setPWM(12,0,p);
            printf ("%d\n",p);
            usleep(1000 * 100);
            j=p;
        }
        x = true;
        red= false;
        blue= false;
        green= false;
        black=false;
        yellow=false;
        white=false;
        
        
        //eventuell Start der Schleife durch einen Knopfdruck
     while (black==true)
       // {
        //Initialisierung
            
            //500ms Messung Rot
            digitalWrite(S2,LOW);
            digitalWrite(S3,LOW);
            while ( f <= 500 )
            {
                //printf( "%d\n", eventCounter );
                nanosleep(&tim,&tim2);
                f++;
            }
            rot = (eventCounter/500);
            printf ("Calred:%.9f\n",rot);
            eventCounter = 0;
            f = 0;
            
            //500ms Messung Blau
            digitalWrite(S2,LOW);
            digitalWrite(S3,HIGH);
            while ( f <= 500 )
            {
                // printf( "%d\n", eventCounter );
                nanosleep(&tim,&tim2);
                f++;
            }
            blau = (eventCounter/500);
            printf ("Calblue:%.9f\n",blau);
            eventCounter = 0;
            f = 0;
            
            //500ms Messung Gruen
            digitalWrite(S2,HIGH);
            digitalWrite(S3,HIGH);
            while ( f <= 500 )
            {
                // printf( "%d\n", eventCounter );
                nanosleep(&tim,&tim2);
                f++;
            }
            gruen = (eventCounter/500);
            printf ("Calgreen:%.9f\n",gruen);
            eventCounter = 0;
            f = 0;
            
              if (gruen < 15 && rot < 15 && blue < 15)
            {
                black = true;
            }  

            if (rot >= 45 && rot > blau && rot > gruen)
            {
                red = true;
            }
            
            
            
            if (gruen >= 25 && gruen > blau && gruen > rot)
            {
                green = true;
            }
          
            if (gruen >= 60 && rot >= 50 && blau >= 40)
            {
                yellow = true;
            }
             if (gruen >= 65 && rot >= 65 && blau >= 65)
            {
                white = true;
                yellow = false;
            }
            
       // }*/
        //Auswahl der Bewegungroutine für rot
      if (c==1){
      //  if(red==true && blue==false && green == false && black==false && yellow==false && white==false){
        int r=350, ir;
        int a=460, ia;

        char* text = (char*) "ROT";
//    ssd1306_drawString(text);
  //  ssd1306_display();
        ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
        ssd1306_drawString(text);
        ssd1306_display(); //Adafruit logo is visible
        ssd1306_clearDisplay();
//      delay(5000);    sleep(5);
//pwm.setPWM(0,0,510); 
for(ir=r; ir<500;){
        ir=ir+10;
    pwm.setPWM(0,0,ir);
 //   printf ("%d\n",ir);
    usleep(1000 * 100);
    r=ir;
}

        for(ia=a;ia>300;)
{
    ia=ia-10;
    pwm.setPWM(7,0,ia);
  //  printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}


//pwm.setPWM(12,0,200);    go to the RED Box
for(i=j; i<240;){
    i=i+10;
    pwm.setPWM(12,0,i);
    printf ("%d\n",i);
    usleep(1000 * 100);
    j=i;
}
//1
   for(ia=a; ia<460;){
        ia=ia+10;
    pwm.setPWM(7,0,ia);
 //   printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}




        for(ir=r;ir>350;)
{
    ir=ir-10;
    pwm.setPWM(0,0,ir);
 //   printf ("%d\n",ir);
    usleep(1000 * 100);
    r=ir;
}

 //2
     for(ia=a;ia>300;)
{
    ia=ia-10;
    pwm.setPWM(7,0,ia);
 //   printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}
      

        for(i=j;i>160;)
{
    i=i-10;
    pwm.setPWM(12,0,i);
    printf ("%d\n",i);
    usleep(1000 * 100);
    j=i;
}

    for(ia=a; ia<460;){
        ia=ia+10;
    pwm.setPWM(7,0,ia);
 // printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}

            
        }//endif Rot
        //Auswahl der Bewegungroutine für blau
    if (c==2){
    //    else if(red==false && blue==true && green == false && black==false && yellow==false && white==false){
           
                char* text = (char*) "Blau";
//    ssd1306_drawString(text);
  //  ssd1306_display();
        ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
        ssd1306_drawString(text);
        ssd1306_display(); //Adafruit logo is visible
        ssd1306_clearDisplay();
//      delay(5000);    sleep(5);
int r=350, ir;;
int a=460, ia;

//pwm.setPWM(0,0,510); 
for(ir=r; ir<500;){
        ir=ir+10;
    pwm.setPWM(0,0,ir);
 //   printf ("%d\n",ir);
    usleep(1000 * 100);
    r=ir;
}

        for(ia=a;ia>300;)
{
    ia=ia-10;
    pwm.setPWM(7,0,ia);
 //   printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}


//pwm.setPWM(12,0,200);    go to the Blue Box
           for(i=j; i<280;){
        i=i+10;
    pwm.setPWM(12,0,i);
    printf ("%d\n",i);
    usleep(1000 * 100);
    j=i;
}
   for(ia=a; ia<460;){ //Arm bewegt sich vorwarts 
        ia=ia+10;
    pwm.setPWM(7,0,ia);
   //printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}




        for(ir=r;ir>350;) //Greifer auf
{
    ir=ir-10;
    pwm.setPWM(0,0,ir);
  //printf ("%d\n",ir);
    usleep(1000 * 100);
    r=ir;
}

     for(ia=a;ia>300;)
{
    ia=ia-10;
    pwm.setPWM(7,0,ia);
 // printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}
      

        for(i=j;i>160;) //Null Pos.
{
    i=i-10;
    pwm.setPWM(12,0,i);
    printf ("%d\n",i);
    usleep(1000 * 100);
    j=i;
}

    for(ia=a; ia<460;){ //Arm bewegt sich vorwarts 
        ia=ia+10;
    pwm.setPWM(7,0,ia);
 // printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}

        } //endif Blau
        //Auswahl der Bewegungroutine für grün
      
        if (c==3){
      //  else if(red==false && blue==false && green == true && black==false && yellow==false && white==false){
           int r=350, ir;;
int a=460, ia;
           char* text = (char*) "GRUEN";
//    ssd1306_drawString(text);
  //  ssd1306_display();
        ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
        ssd1306_drawString(text);
        ssd1306_display(); //Adafruit logo is visible
        ssd1306_clearDisplay();
//      delay(5000);    sleep(5);



//pwm.setPWM(0,0,510); //Greifer zu 
for(ir=r; ir<500;){
        ir=ir+10;
    pwm.setPWM(0,0,ir);
  //  printf ("%d\n",ir);
    usleep(1000 * 100);
    r=ir;
}

        for(ia=a;ia>300;)
{
    ia=ia-10;
    pwm.setPWM(7,0,ia);
 // printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}


//pwm.setPWM(12,0,200);    go to the Green box
           for(i=j; i<340;){
        i=i+10;
    pwm.setPWM(12,0,i);
    printf ("%d\n",i);
    usleep(1000 * 100);
    j=i;
}
//1
   for(ia=a; ia<460;){ // Arm Bewegt sich
        ia=ia+10;
    pwm.setPWM(7,0,ia);
 // printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}




        for(ir=r;ir>400;) // Greifer Auf
{
    ir=ir-10;
    pwm.setPWM(0,0,ir);
  //  printf ("%d\n",ir);
    usleep(1000 * 100);
    r=ir;
}
 //2
     for(ia=a;ia>300;) // Arm bewegt sich Rueckwaerts
{
    ia=ia-10;
    pwm.setPWM(7,0,ia);
 //   printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}
      

        for(i=j;i>160;) // Null Pos
{
    i=i-10;
    pwm.setPWM(12,0,i);
    printf ("%d\n",i);
    usleep(1000 * 100);
    j=i;
}

    for(ia=a; ia<460;){ // Arm Vorwaerst 
        ia=ia+10;
    pwm.setPWM(7,0,ia);
//    printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}
//endif
    } //endif Grün
        /*Auswahl der Bewegungroutine für black
        elseif(red==false && blue==false && green == false && black==true && yellow==false && white==false){
        
        }*/
        //Auswahl der Bewegungroutine für yellow
       if (c==4){

     //   else if(red==false && blue==false && green == false && black==false && yellow==true && white==false){
         int r=350, ir;
int a=460, ia;

          char* text = (char*) "GELB";
//    ssd1306_drawString(text);
  //  ssd1306_display();
        ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
        ssd1306_drawString(text);
        ssd1306_display(); //Adafruit logo is visible
        ssd1306_clearDisplay();
//      delay(5000);    sleep(5);
        //pwm.setPWM(0,0,510); 
for(ir=r; ir<500;){ //Greifer zu
        ir=ir+10;
    pwm.setPWM(0,0,ir);
  //printf ("%d\n",ir);
    usleep(1000 * 100);
    r=ir;
}

        for(ia=a;ia>300;) //Arm Rueckwaerts
{
    ia=ia-10;
    pwm.setPWM(7,0,ia);
 //   printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}


//pwm.setPWM(12,0,200);   go all the way to the last box: Yellow
           for(i=j; i<400;){
        i=i+10;
    pwm.setPWM(12,0,i);
    printf ("%d\n",i);
    usleep(1000 * 100);
    j=i;
}
//1
   for(ia=a; ia<420;){ //Arm Vorwaerts
        ia=ia+10;
    pwm.setPWM(7,0,ia);
  //  printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}




        for(ir=r;ir>400;)
{
    ir=ir-10;
    pwm.setPWM(0,0,ir);
  //  printf ("%d\n",ir);
    usleep(1000 * 100);
    r=ir;
}
 //2
     for(ia=a;ia>300;)
{
    ia=ia-10;
    pwm.setPWM(7,0,ia);
 //   printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}
      

        for(i=j;i>160;) //Null Pos
{
    i=i-10;
    pwm.setPWM(12,0,i);
    printf ("%d\n",i);
    usleep(1000 * 100);
    j=i;
}

    for(ia=a; ia<460;){ //Arm Vorwaerts
        ia=ia+10;
    pwm.setPWM(7,0,ia);
  //  printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}
//endif





        }//endif Gelb
        //Auswahl der Bewegungroutine für white
         if (c==5){
       // else if(red==false && blue==false && green == false && black==false && yellow==false && white==true){
         int r=350, ir;
        int a=460, ia;

          char* text = (char*) "WEISS";
//    ssd1306_drawString(text);
  //  ssd1306_display();
        ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
        ssd1306_drawString(text);
        ssd1306_display(); //Adafruit logo is visible
        ssd1306_clearDisplay();
//      delay(5000);    sleep(5);


//pwm.setPWM(0,0,510); 
for(ir=r; ir<500;){ // Greifer zu
        ir=ir+10;
    pwm.setPWM(0,0,ir);
   // printf ("%d\n",ir);
    usleep(1000 * 100);
    r=ir;
}

        for(ia=a;ia>300;) //Arm Rueckwarst
{
    ia=ia-10;
    pwm.setPWM(7,0,ia);
 //   printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}


//pwm.setPWM(12,0,200);   go to the white Box
           for(i=j; i<460;){
        i=i+10;
    pwm.setPWM(12,0,i);
    printf ("%d\n",i);
    usleep(1000 * 100);
    j=i;
}
//1
   for(ia=a; ia<420;){ //Arm vorwaerst
        ia=ia+10;
    pwm.setPWM(7,0,ia);
    printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}




        for(ir=r;ir>400;) //Greifer Auf
{
    ir=ir-10;
    pwm.setPWM(0,0,ir);
//    printf ("%d\n",ir);
    usleep(1000 * 100);
    r=ir;
}
 //2
     for(ia=a;ia>300;) //Arm Rueckwaerts
{
    ia=ia-10;
    pwm.setPWM(7,0,ia);
  //  printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}
      

        for(i=j;i>160;) //Null Pos
{
    i=i-10;
    pwm.setPWM(12,0,i);
    printf ("%d\n",i);
    usleep(1000 * 100);
    j=i;
}

    for(ia=a; ia<460;){
        ia=ia+10;
    pwm.setPWM(7,0,ia);
 // printf ("%d\n",ia);
    usleep(1000 * 100);
    a=ia;
}
//endif






        }//endif White

        return 0;
    }

