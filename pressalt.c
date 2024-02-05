#include <stdio.h>
#include <windows.h>

#define standardPressure 1013
#define standardTemperature 15

int QNH;
int QNHDiff;
int aerodromeElevation;
int pressureAltitude;
int densityAltitude;

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
    densityAltitude = pressureAltitude + (tempDifference * 120);

    printf("\nDensity Altitude: %i ft", densityAltitude);
}

int main(void)
{
    calcPressureAltitude();
    calcDensityAltitude();

    return 0;
}