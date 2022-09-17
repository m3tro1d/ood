#include "CStatsDisplay.h"
#include <iostream>

void CStatsDisplay::Update(Observable& observable, const WeatherInfo& data)
{
	auto& observableData = m_observablesData[&observable];

	observableData.temperatureMonitor.Update(data.temperature);
	observableData.humidityMonitor.Update(data.humidity);
	observableData.pressureMonitor.Update(data.pressure);

	PrintHeader(observable);
	PrintStats("Temperature", observableData.temperatureMonitor.GetStats());
	PrintStats("Humidity", observableData.humidityMonitor.GetStats());
	PrintStats("Pressure", observableData.pressureMonitor.GetStats());
}

void CStatsDisplay::SetObservableName(Observable& observable, const std::string& name)
{
	m_observablesData[&observable].name = name;
}

void CStatsDisplay::RemoveObservable(Observable& observable)
{
	m_observablesData.erase(&observable);
}

void CStatsDisplay::PrintStats(std::string const& header, Stats const& stats) const
{
	std::cout << "[" << header << "]\n"
			  << "Max " << stats.max << "\n"
			  << "Min " << stats.min << "\n"
			  << "Average " << stats.average << "\n"
			  << "----------------" << std::endl;
}

void CStatsDisplay::PrintHeader(Observable& observable) const
{
	std::cout << "Stats from ";

	auto observableData = m_observablesData.find(&observable);
	if (observableData != m_observablesData.end())
	{
		std::cout << observableData->second.name;
	}
	else
	{
		std::cout << "unknown";
	}

	std::cout << " source\n";
}
