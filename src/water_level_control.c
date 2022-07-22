#include "water_level_control.h"
#include "levelSensor.h"
#include "water_devices.h"

#define EMPTY_LEVEL 50
#define FULL_LEVEL_WASH 180
#define FULL_LEVEL_SOFT 200
#define OVERFLOW_LEVEL 250
#define FILL_OK 1
#define FILL_NOK 0
#define DRAIN_OK 1
#define DRAIN_NOK 0


uint8_t level;

bool fillWaterWash(void)     //Carga agua en la etapa de lavado del programa de lavado//
{

  level = waterLevel();  
  if(evWashOn()&&(level<OVERFLOW_LEVEL))
  {	
	while(level<=FULL_LEVEL_WASH)
	{
	     level = waterLevel();
	}
	
	if(evWashOff())
	{
	     return FILL_OK;
	}
  }
  else
  {
      return FILL_NOK;
  }
  
}

bool fillWaterSoft(void)     //Carga agua en la etapa de suavizante del programa de lavado//
{
  
  level = waterLevel();
  if(evSoftOn()&&(level<OVERFLOW_LEVEL))
  {	
	while(level<=FULL_LEVEL_SOFT)
	{
	     level = waterLevel();
	}
	if(evSoftOff())
	{
	     return FILL_OK;
	}
  }
  else
  {
      return FILL_NOK;
  }
  
}



bool drainWater(void)
{
  level = waterLevel();
  if(pumpOn()&&(level<OVERFLOW_LEVEL))
  {	
	while(level>=EMPTY_LEVEL)
	{
	     level = waterLevel();
	}
	if(pumpOff())
	{
	     return DRAIN_OK;
	}
  }
  else
  {
      return DRAIN_NOK;
  }

}
