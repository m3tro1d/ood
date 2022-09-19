#pragma once

#include "IObservable.h"
#include <map>

template <typename T>
class CObservable : public IObservable<T>
{
public:
	using ObserverType = IObserver<T>;

	void RegisterObserver(ObserverType& observer, unsigned priority) override
	{
		// NOTE: observers with the same priority will be called in order of registering
		// https://en.cppreference.com/w/cpp/container/multimap
		m_observers.emplace(priority, &observer);
	}

	void NotifyObservers() override
	{
		auto data = GetChangedData();
		auto observersCopy = m_observers;

		for (auto& observer : observersCopy)
		{
			observer.second->Update(data);
		}
	}

	void RemoveObserver(ObserverType& observer) override
	{
		for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
		{
			if (it->second == &observer)
			{
				m_observers.erase(it);
				break;
			}
		}
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	std::multimap<unsigned, ObserverType*> m_observers;
};
