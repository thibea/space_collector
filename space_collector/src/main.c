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

         copierTxt(&p1.cmd, "MOVE");
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

//****Rajouter
#include <string.h>
#include "Plane/Plane.h"
#include "StructH/struct.h"

osThreadId_t defaultTaskHandle;
osThreadId_t thread_vaisseau1;

void StartDefaultTask(void *argument);
void vaiseau1(void *argument);
//************

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
            copierTxt(&TabPlaneV[0].cmd, "MOVE");
            TabPlaneV[0].Id_Plane = 1;
            TabPlaneV[0].angle = 60;
            TabPlaneV[0].speed = 600;
            afficher(&TabPlaneV[0]);

            gets(DataServer);
            // osDelay(4);
            // puts(DataServer);

            if ((strcmp(DataServer, "OK")) == 0)
            {
                copierTxt(&TabPlaneV[1].cmd, "MOVE");
                TabPlaneV[1].Id_Plane = 2;
                TabPlaneV[1].angle = 90;
                TabPlaneV[1].speed = 600;
                afficher(&TabPlaneV[1]);
            }

            gets(DataServer);
            if ((strcmp(DataServer, "OK")) == 0)
            {
                copierTxt(&TabPlaneV[5].cmd, "MOVE");
                TabPlaneV[5].Id_Plane = 6;
                TabPlaneV[5].angle = 190;
                TabPlaneV[5].speed = 600;
                afficher(&TabPlaneV[5]);
            }

            gets(DataServer);
            if ((strcmp(DataServer, "OK")) == 0)
            {
                copierTxt(&TabPlaneV[6].cmd, "MOVE");
                TabPlaneV[6].Id_Plane = 7;
                TabPlaneV[6].angle = 100;
                TabPlaneV[6].speed = 600;
                afficher(&TabPlaneV[6]);

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
            copierTxt(&TabPlaneV[5].cmd, "RADAR");
            TabPlaneV[5].Id_Plane = 6;
            afficher(&TabPlaneV[5]);

            /// osDelay(1);
            gets(DataServer);
            signed char *recPlanet[1000];
            decoupeDataRadarLigne(DataServer, &recPlanet);

            // osDelay(1);
            puts(*recPlanet);
        }

        break;
    }

    osThreadExit();
}
