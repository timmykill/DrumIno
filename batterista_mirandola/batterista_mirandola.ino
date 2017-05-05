// 4 magneti: pin analogici + 7 servo,  ON OFF pin 0, scelta ritmo pin 1 e 2, LED 
#include <Servo.h>

Servo timpanoA;
Servo timpanoB;  
Servo rullanteA;
Servo rullanteB;
Servo charlestonA;
Servo charlestonB;
Servo piattoA; 

//DICHIARAZIONI VARIABILI
boolean inter;    // interruttore ON OFF    pin 0
int ritmo;
boolean ritmo1;    // scelta ritmo  pin 1
boolean ritmo2;    // scelta ritmo  pin 2
int sedic;       // puntatore sedicesimo
int metronomo;   //battiti per minuto (bpm)
int sedicesimo; //durata di un sedicesimo in ms
boolean ti;   // flag timpano
boolean ch;   // flag charleston
boolean ru;   // flag rullante

boolean claveGR[16] ;     // clave grande
boolean clavePIC [16] ;   // clave piccola
boolean campGR [16] ;
boolean campPIC [16];

boolean timpano [16] ; 
boolean piatto [16] ; 
boolean rullante [16] ; 
boolean charleston [16];

//PROGRAMMAZIONE 2 RITMI E METRONOMI


int metronomo1= 100 ;    // RITMO 1

boolean claveGR1 [16] =   {0,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0};
boolean clavePIC1 [16] =  {1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0};
boolean campGR1 [16] =    {1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0};
boolean campPIC1 [16] =   {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0};

boolean timpano1 [16] =    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}; 
boolean piatto1 [16] =     {0,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0}; 
boolean rullante1 [16] =   {1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0}; 
boolean charleston1 [16] = {0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1}; 


int metronomo2= 120 ;   // RITMO 2 Every breath

boolean claveGR2 [16] =   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
boolean clavePIC2 [16] =  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
boolean campGR2 [16] =    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
boolean campPIC2 [16] =   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

boolean timpano2 [16] =    {1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0}; 
boolean piatto2 [16] =     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
boolean rullante2 [16] =   {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0}; 
boolean charleston2 [16] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0}; 


int metronomo3= 75 ;   // RITMO 3

boolean claveGR3 [16] =   {1,1,1,1,1,1,1,0,1,0,0,1,0,0,1,0};
boolean clavePIC3 [16] =  {1,0,1,0,1,0,0,1,1,1,1,0,0,0,0,0};
boolean campGR3 [16] =    {1,0,0,0,1,0,0,0,0,0,1,0,1,1,1,1};
boolean campPIC3 [16] =   {0,0,1,0,0,0,0,0,1,1,1,1,1,0,0,0};

boolean timpano3 [16] =    {1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0}; 
boolean piatto3 [16] =     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
boolean rullante3 [16] =   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
boolean charleston3 [16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 


int metronomo4= 50 ;   // RITMO 4

boolean claveGR4 [16] =   {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};
boolean clavePIC4 [16] =  {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0};
boolean campGR4 [16] =    {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0};
boolean campPIC4 [16] =   {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1};

boolean timpano4 [16] =    {1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0}; 
boolean piatto4 [16] =     {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0}; 
boolean rullante4 [16] =   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; 
boolean charleston4 [16] = {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0}; 


void setup() {
  
 //IMPIEGO PIN ARDUINO  (DECIDERE PIN)
 pinMode(18, OUTPUT); //claveGR
 pinMode(19, OUTPUT); //clavePIC
 pinMode(20, OUTPUT); //campGR
 pinMode(21, OUTPUT); //campPIC
 pinMode(22, OUTPUT); //LED metronomo
  
 pinMode(0, INPUT_PULLUP); // interruttore ON OFF    pin 0
 pinMode(1, INPUT_PULLUP); // ritmo
 pinMode(2, INPUT_PULLUP); // ritmo
 pinMode(7, INPUT_PULLUP); // pulsante rullata sul timpano 
 pinMode(8, INPUT_PULLUP); // pulsante colpo sul piatto 
 pinMode(4, INPUT_PULLUP); // pulsante rullata sul rullante 
 
 timpanoA.attach(10);
 timpanoB.attach(9);
 rullanteA.attach(6);
 rullanteB.attach(5);
 charlestonA.attach(3);
 charlestonB.attach(13);
 piattoA.attach(11);


 //INIZIALIZZAZIONI servo, magneti e flag 
     timpanoA.write(0); //servo timpanoA a riposo
     timpanoB.write(180); //servo timpanoB a riposo
     rullanteA.write(0); //servo rullanteA a riposo
     rullanteB.write(180); //servo rullanteB a riposo
     charlestonA.write(0); //servo charlestonA a riposo
     charlestonB.write(180); //servo charlestonB a riposo
     piattoA.write(180); //servo piattoA a riposo

     digitalWrite(18, 0); //claveGR a riposo
     digitalWrite(19, 0); //clavePIC a riposo
     digitalWrite(20, 0); //campGR a riposo
     digitalWrite(21, 0); //campPIC a riposo
     digitalWrite(22, 0); // metronomo spento

     ti=0; // inizializzazione FLAG 
     ch=0;
     ru=0;
  
     }



void loop() {

inter = digitalRead(0);  // leggi interruttore ON Off
 while(inter)   {

ritmo1 = digitalRead(1);  // leggi ritmo 1 o  2
ritmo2 = digitalRead(2);  // leggi ritmo 1 o  2

int ritmo = ritmo1 + ritmo2*2;
switch ( ritmo ) {
    case 0: {
        metronomo = metronomo1;
         memcpy(claveGR, claveGR1, 16);
         memcpy(clavePIC,clavePIC1,16);
         memcpy(campGR,campGR1,16);
         memcpy(campPIC,campPIC1,16);
         memcpy(timpano,timpano1,16);
         memcpy(piatto,piatto1,16);
         memcpy(rullante,rullante1,16);
         memcpy(charleston,charleston1,16); }
         break;

    case 1: {
        metronomo = metronomo2;
    
         memcpy(claveGR, claveGR2, 16);
         memcpy(clavePIC,clavePIC2,16);
         memcpy(campGR,campGR2,16);
         memcpy(campPIC,campPIC2,16);
         memcpy(timpano,timpano2,16);
         memcpy(piatto,piatto2,16);
         memcpy(rullante,rullante2,16);
         memcpy(charleston,charleston2,16); }      
         break;
         
     case 2: {
        metronomo = metronomo3;
    
         memcpy(claveGR, claveGR3, 16);
         memcpy(clavePIC,clavePIC3,16);
         memcpy(campGR,campGR3,16);
         memcpy(campPIC,campPIC3,16);
         memcpy(timpano,timpano3,16);
         memcpy(piatto,piatto3,16);
         memcpy(rullante,rullante3,16);
         memcpy(charleston,charleston3,16);  }
         break;

      case 3: {
        metronomo = metronomo4;
    
         memcpy(claveGR, claveGR4, 16);
         memcpy(clavePIC,clavePIC4,16);
         memcpy(campGR,campGR4,16);
         memcpy(campPIC,campPIC4,16);
         memcpy(timpano,timpano4,16);
         memcpy(piatto,piatto4,16);
         memcpy(rullante,rullante4,16);
         memcpy(charleston,charleston4,16); }
         break;
   }
   
  sedicesimo = 15000/metronomo; // calcolo durata di un sedicesimo in ms  
                                //(60 X 1000)/(4 X metronomo)  metronomo=n° di quarti al minuto
  
   for (sedic=0; sedic<16; sedic++) {          // ciclo FOR di esecuzione ritmo selezionato

      if (sedic == 0){ digitalWrite(22, 1);}   // accendi LED metronomo a inizio battuta
      else { digitalWrite(22, 0);}

bool rullataTimp = digitalRead(7);  // leggi pulsante rullata  TIMPANO
      
      if (timpano[sedic] == 1 || rullataTimp==0)   {     
         if (ti==1){               // suona timpanoA o timpanoB in base alla flag ti
           timpanoA.write(15);
         }
         else{
           timpanoB.write(145);
         }
         ti=!ti;   // nega la flag timpano       NEGARE x 2 bacchette
      }

    bool rullataRull = digitalRead(4);  // leggi pulsante rullata   Rullante
      
      if (rullante[sedic] == 1 || rullataRull==0)   {     
               if (ru==1){         // suona rullante1 o rullante2 in base alla flag ru
                 rullanteA.write(15);
               }
               else{
                 rullanteB.write(165);
               }
               ru=!ru;   // nega la flag rullante
      }
      
        if (charleston[sedic] == 1)   {     
               if (ch==1){           // suona charleston1 o charleston2 in base alla flag ch
                 charlestonA.write(15);
               }
               else{
                 charlestonB.write(165);
               }
               ch=!ch;   // nega la flag charleston
      }
     
     bool rullataPiatto = digitalRead(8);  // leggi pulsante rullata   Piatto
      if (piatto[sedic] == 1 || rullataPiatto==0)          
        piattoA.write(160);   // suona piatto

               
      if (claveGR[sedic] == 1)        
         digitalWrite(18, 1);       
      if (clavePIC[sedic] == 1)        
         digitalWrite(19, 1);
      if (campGR[sedic] == 1)        
         digitalWrite(20, 1);       
      if (campPIC[sedic] == 1)        
         digitalWrite(21, 1);
               
   delay(sedicesimo/2); //metà ritardo
   
//Riporta a zero
     timpanoA.write(0); //servo timpanoA a riposo
     timpanoB.write(180); //servo timpanoB a riposo
     rullanteA.write(0); //servo rullanteA a riposo
     rullanteB.write(180); //servo rullanteB a riposo
     charlestonA.write(0); //servo charlestonA a riposo
     charlestonB.write(180); //servo charlestonB a riposo
     piattoA.write(180); //servo piattoA a riposo
     
     digitalWrite(18, 0); //claveGR a riposo
     digitalWrite(19, 0); //clavePIC a riposo
     digitalWrite(20, 0); //campGR a riposo
     digitalWrite(21, 0); //campPIC a riposo 
    
    delay(sedicesimo/2); //metà ritardo
        }  // chiusura del for
    inter = digitalRead(0);  // leggi interruttore ON Off
  }   // chiusura del  while
}
