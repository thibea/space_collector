/*
#include <math.h>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
#include "main.h"
#include "cmsis_os.h"

// function rajouter
#include "Plane/Plane.h"
#include <string.h>

osThreadId_t defaultTaskHandle;

void StartDefaultTask(void *argument);

int main(void)
{
    hardware_init();

    osKernelInitialize();

    const osThreadAttr_t defaultTask_attributes = {
        .name = "defaultTask",
        .priority = (osPriority_t)osPriorityNormal,
        .stack_size = 128,
    };
    defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

    osKernelStart();

    while (1)
    {
        // movePlane(1, 60, 600);
    }
}

void StartDefaultTask(void *argument)
{
    while (1)
    {
        char DataServer[255];
        gets(DataServer);
        // puts(DataServer);

        /* copierTxt(&p1.cmd, "MOVE");
         p1.Id_Plane = 1;
         p1.angle = 40;
         p1.speed = 600;
         afficher(&p1);

        if ((strcmp(DataServer, "START")) == 0)
        {
            osDelay(10);
            copierTxt(&p1.cmd, "MOVE");
            p1.Id_Plane = 1;
            p1.angle = 40;
            p1.speed = 600;
            afficher(&p1);

            osDelay(20);
            p1.angle = 20;
            afficher(&p1);
        }

        osDelay(3000);
        gets(DataServer);
        puts(DataServer);

        if ((strcmp(DataServer, "OK")) == 0)
        {
            copierTxt(&p2.cmd, "MOVE");
            p1.Id_Plane = 2;
            p1.angle = 70;
            p1.speed = 700;
            afficher(&p1);
            osDelay(1);
        }

        osDelay(1);
    }
}
*/

#include <math.h>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
#include "main.h"
#include "cmsis_os.h"

//////
#include "Plane/Plane.h"
#include <string.h>

osThreadId_t defaultTaskHandle;
osThreadId_t thread_vaisseau1;

void StartDefaultTask(void *argument);
void vaiseau1(void *argument);

int main(void)
{
    hardware_init();

    osKernelInitialize();

    const osThreadAttr_t defaultTask_attributes = {
        .name = "defaultTask",
        .priority = (osPriority_t)osPriorityNormal + 2,
        .stack_size = 128,
    };
    defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

    const osThreadAttr_t thread1_attr = {
        .name = "thread1_attr",
        .priority = (osPriority_t)osPriorityNormal + 1,
        .stack_size = 128};

    thread_vaisseau1 = osThreadNew(vaiseau1, NULL, &thread1_attr);
    osKernelStart();

    while (1)
    {
    }
}

void StartDefaultTask(void *argument)
{
    int IsExit = 0;
    while (1)
    {
        // puts("Hello world\n");

        char DataServer[255];
        gets(DataServer);
        // puts(DataServer);

        // osDelay(1);
        if ((strcmp(DataServer, "START")) == 0)
        {
            copierTxt(&p1.cmd, "MOVE");
            p1.Id_Plane = 1;
            p1.angle = 60;
            p1.speed = 600;
            afficher(&p1);

            gets(DataServer);
            // osDelay(4);
            // puts(DataServer);

            if ((strcmp(DataServer, "OK")) == 0)
            {
                copierTxt(&p2.cmd, "MOVE");
                p2.Id_Plane = 2;
                p2.angle = 90;
                p2.speed = 600;
                afficher(&p2);
            }

            gets(DataServer);
            if ((strcmp(DataServer, "OK")) == 0)
            {
                copierTxt(&p6.cmd, "MOVE");
                p6.Id_Plane = 6;
                p6.angle = 190;
                p6.speed = 600;
                afficher(&p6);
            }

            gets(DataServer);
            if ((strcmp(DataServer, "OK")) == 0)
            {
                copierTxt(&p7.cmd, "MOVE");
                p7.Id_Plane = 7;
                p7.angle = 100;
                p7.speed = 600;
                afficher(&p7);

                IsExit = 1;
            }
        }
        break;
    }

    if (IsExit == 1)
    {
        osThreadExit();
    }
}

void vaiseau1(void *argument)
{
    while (1)
    {
        char DataServer[255];
        gets(DataServer);
        // puts(DataServer);

        if ((strcmp(DataServer, "OK")) == 0)
        {
            copierTxt(&p6.cmd, "RADAR");
            p6.Id_Plane = 6;
            afficher(&p6);

            if ((strcmp(DataServer, "OK")) == 0)
            {
            }
        }

        break;
    }

    /*static uint32_t lastTimeMqtt = 0;
    if (millis() - lastTimeMqtt >= 10000)
    {
        lastTimeMqtt = millis();
    }*/
    osThreadExit();
}
