#include "Displays/CurrentConditionsDisplay/CCurrentConditionsDisplay.h"
#include "Displays/StatsDisplay/CStatsDisplay.h"
#include "WeatherData/CWeatherData.h"

int main()
{
	CWeatherData wdIn;
	CWeatherData wdOut;

	CCurrentConditionsDisplay display;

	wdIn.RegisterObserver(display, 0);
	display.SetObservableName(wdIn, "in");

	wdOut.RegisterObserver(display, 0);
	display.SetObservableName(wdOut, "out");

	CStatsDisplay statsDisplay;

	wdIn.RegisterObserver(statsDisplay, 1);
	statsDisplay.SetObservableName(wdIn, "in");

	wdOut.RegisterObserver(statsDisplay, 1);
	statsDisplay.SetObservableName(wdOut, "out");

	wdIn.SetMeasurements(22, 0.8, 760);
	wdOut.SetMeasurements(15, 0.7, 765);

	wdIn.SetMeasurements(20, 0.75, 761);
	wdOut.SetMeasurements(14, 0.8, 760);

	return EXIT_SUCCESS;
}
