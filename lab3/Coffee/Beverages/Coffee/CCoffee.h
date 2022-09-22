#pragma once

#include "../Beverage/CBeverage.h"

class CCoffee : public CBeverage
{
public:
	explicit CCoffee(std::string const& description = "Coffee")
		: CBeverage(description)
	{
	}

	double GetCost() const override;
};
