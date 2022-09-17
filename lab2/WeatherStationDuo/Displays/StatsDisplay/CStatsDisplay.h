#pragma once

#include "../../WeatherData/CWeatherData.h"
#include "StatsMonitor/CStatsMonitor.h"
#include <map>
#include <string>

class CStatsDisplay : public IObserver<WeatherInfo>
{
public:
	using Observable = IObservable<WeatherInfo>;

	void SetObservableName(Observable& observable, std::string const& name) override;
	void RemoveObservable(Observable & observable) override;

private:
	void Update(Observable& observable, WeatherInfo const& data) override;

	void PrintStats(std::string const& header, Stats const& stats) const;
	void PrintHeader(Observable& observable) const;

	struct ObservableInfo
	{
		std::string name;

		CStatsMonitor temperatureMonitor;
		CStatsMonitor humidityMonitor;
		CStatsMonitor pressureMonitor;
	};

	std::map<Observable*, ObservableInfo> m_observablesData;
};