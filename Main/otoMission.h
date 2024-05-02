

#define missionTime 30000

#ifdef otoMission
unsigned long StartTime = 0;  
/*

                               __
                             /    \
                           /        \
                          |          |           
                          |          |
                          |   ++++   |
                          |          |
                          |          |
                          |          |
                          |Trim_Pitch|
                          

  ___________________                        ___________________
 /                   |                      |                   \
/       ----         |                      |       ++++         \
\                    |                      |                    /
 \____Trim_Roll______|                      |____Trim_Roll______/
 

                           Trim_Pitch
                          |          |           
                          |          |
                          |          |
                          |   ----   |
                          |          |
                          |          |
                          |          |
                           \        /
                             \ __ /


                      
*/

unsigned long RecordedTime = 0;  

int StartCounting = 1;
int stopMission = 1;

int sadly = 0;

int sure[] = {  // milisaniye
  5000,
  5000,
  5000,
  5000,
  0,
};

int rollDegre[] = {  
  0,
  500,
  1000,
  500, 
  0,
};

int pitchDegre[] = {  
  0,
  500,
  0, 
  0,
  0,
};

int heightValue[] = {  
  750,
  750,
  750,
  750,
  750
};

void setup_(){

}

void loop_(){
  if(flyMode_2 == 1 && stopMission == 1){
  unsigned long currentTime = millis();

  if(StartCounting == 1){
  RecordedTime = currentTime; 
  StartTime = currentTime;
  StartCounting = 0;
  }


  if( sadly < 5){
    
  if (currentTime - RecordedTime >= sure[sadly] ) {
      RecordedTime = currentTime;
   targetOto = heightValue[sadly];
   targetGOTX =  rollDegere[sadly];
   targetGOTY = pitchDegre[sadly];
   
    sadly = sadly + 1 ;
    }
  }else{
    sadly=0;
  }

  if (currentTime - StartTime >= missionTime ) {
    
   // stopFlightControl = 0;
  //  stopMission = 0;
  }
  
}}
#endif  
