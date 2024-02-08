#include <stdio.h>
#include <windows.h>

#define standardPressure 1013
#define standardTemperature 15

int QNH;
int QNHDiff;
int aerodromeElevation;
int pressureAltitude;
int densityAltitude;

void mainMenu(void);
void calcPressureAltitude(void);
void calcDensityAltitude(void);
void showHelp(void);

void showOptions(void)
{
    printf("Density Altitude Calculator\n\n1) Main Menu\n2) Calculate\n3) Help\n4) Quit\n");

    // Show options
    int option;
    scanf("%i", &option);

    switch(option)
    {
        case 1: mainMenu();
        case 2: calcPressureAltitude(); break;
        case 3: showHelp(); break;
        case 4: exit(0); break;
    }
}

// Main Menu
void densityAltitudeMenu(void)
{
    system("cls");
    showOptions();
}

void showHelp(void)
{
    system("cls");

    printf("HELP\n\n");
    printf("This program calculates the pressure altitude of an aerodrome,\n");
    printf("as well as the density altitude at the aerodrome's elevation\n\n");
    printf("Pressure altitude formula: Aerodrome Elevation - Difference in QNH * 30\n\n");
    printf("Density altitude formula:\n");
    printf("Aerodrome Pressure = 15 - (2 * Aerodrome Elevation / 1000)\n");
    printf("Temperature Deviation = Surface Temperature - Aerodrome Temperature\n");
    printf("Density Altitude = Pressure Altitude + Temperature Deviation * 120");

    showOptions();
}

int absoluteValue(int value)
{
    if (value < 0) value = -value;
    return value;
}

void calcPressureAltitude(void)
{
    system("cls");

    printf("PRESSURE ALTITUDE\n\n");

    // Calculate the difference in QNH
    printf("Enter the QNH (hPa): ");
    scanf("%i", &QNH);

    QNHDiff = QNH - standardPressure;

    printf("The difference is %i hPa", absoluteValue(QNHDiff));

    // Get the aerodrome elevation
    printf("\nEnter the aerodrome elevation (feet AMSL): ");
    scanf("%i", &aerodromeElevation);

    // Calculate the pressure altitude
    printf("\nPressure Altitude %i ft", pressureAltitude = aerodromeElevation - QNHDiff * 30);

    calcDensityAltitude();
}

void calcDensityAltitude(void)
{
    int surfaceTemp;
    int tempDifference;
    int tempDeviation;
    int aerodromeISA;

    printf("\n\nDENSITY ALTITUDE\n");

    // Get the surface temperature
    printf("\nEnter surface temperature (Celcius): ");
    scanf("%i", &surfaceTemp);

    // Calculate temperature variation
    tempDifference = surfaceTemp - standardTemperature;

    // Calculate temperature deviation
    aerodromeISA = standardTemperature - (2 * aerodromeElevation / 1000);
    tempDeviation = surfaceTemp - aerodromeISA;

    // Calculate the density altitude
    densityAltitude = pressureAltitude + (tempDeviation * 120);

    printf("\nDensity Altitude: %i ft\n\n", densityAltitude);

    showOptions();
}