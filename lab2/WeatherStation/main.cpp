#include "Displays/CurrentConditionsDisplay/CCurrentConditionsDisplay.h"
#include "Displays/StatsDisplay/CStatsDisplay.h"
#include "WeatherData/CWeatherData.h"

int main()
{
	CWeatherData wd;

	CCurrentConditionsDisplay display;
	wd.RegisterObserver(display, 0);

	CStatsDisplay statsDisplay;
	wd.RegisterObserver(statsDisplay, 1);

	wd.SetMeasurements(3, 0.7, 760);
	wd.SetMeasurements(4, 0.8, 761);

	wd.RemoveObserver(statsDisplay);

	wd.SetMeasurements(10, 0.8, 761);
	wd.SetMeasurements(-10, 0.8, 761);

	return EXIT_SUCCESS;
}
