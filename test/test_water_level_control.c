#include "unity.h"
#include "mock_levelSensor.h"
#include "mock_water_devices.h"
#include "water_level_control.h"


void setUp()
{
}

void tearDown() 
{

}


void test_full_level_wash() 
{
    waterLevel_ExpectAndReturn(182);
    evWashOn_ExpectAndReturn(1);
    evWashOff_ExpectAndReturn(1);
    bool confir = fillWaterWash();
    TEST_ASSERT_EQUAL_INT(1, confir);
}


void test_full_level_soft() 
{
    waterLevel_ExpectAndReturn(202);
    evSoftOn_ExpectAndReturn(1);
    evSoftOff_ExpectAndReturn(1);
    bool confir = fillWaterSoft();
    TEST_ASSERT_EQUAL_INT(1, confir);
}


void test_drain_level() 
{
    waterLevel_ExpectAndReturn(30);
    pumpOn_ExpectAndReturn(1);
    pumpOff_ExpectAndReturn(1);
    bool confir = drainWater();
    TEST_ASSERT_EQUAL_INT(1, confir);
}

void test_overflow_during_fill_wash()
{
    waterLevel_ExpectAndReturn(253);
    evWashOn_ExpectAndReturn(1);
    bool confir = fillWaterWash();
    TEST_ASSERT_EQUAL_INT(0, confir);
}


void test_overflow_during_fill_soft()
{
    waterLevel_ExpectAndReturn(253);
    evSoftOn_ExpectAndReturn(1);
    bool confir = fillWaterSoft();
    TEST_ASSERT_EQUAL_INT(0, confir);
}

void test_overflow_during_drain()
{
    waterLevel_ExpectAndReturn(253);
    pumpOn_ExpectAndReturn(1);
    bool confir = drainWater();
    TEST_ASSERT_EQUAL_INT(0, confir);
}



