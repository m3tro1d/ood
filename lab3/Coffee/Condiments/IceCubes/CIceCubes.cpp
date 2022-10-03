#include "CIceCubes.h"

CIceCubes::CIceCubes(IBeveragePtr&& beverage, unsigned quantity, IceCubeType type)
	: CCondimentDecorator(std::move(beverage))
	, m_quantity(quantity)
	, m_type(type)
{
}

std::string CIceCubes::GetCondimentDescription() const
{
	return std::string(m_type == IceCubeType::Dry ? "Dry" : "Water")
		+ " ice cubes x "
		+ std::to_string(m_quantity);
}

double CIceCubes::GetCondimentCost() const
{
	return (m_type == IceCubeType::Dry ? 10 : 5) * m_quantity;
}
