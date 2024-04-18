#pragma once
#include <string>
class ComputerComponents
{

	public:
		enum class ComponentType
		{
			GPU,
			CPU,
			MOBO,
			RAM,
			COOLER,
			STORAGE,
			PSU
		};
		ComputerComponents()
		{
			price = 0;
			powerDraw = 0;
		}
		ComputerComponents(std::string pName,int pPrice,std::string pSocket,std::string pDescription,int pPowerDraw, ComputerComponents::ComponentType pType, bool pCritical)
		{
			name = pName;
			price = pPrice;
			socket = pSocket;
			description = pDescription;
			powerDraw = pPowerDraw;
			Type = pType;
			isCritical = pCritical;
		}
		~ComputerComponents(){}
		std::string GetName()
		{
			 return name;
		}
		void SetName(std::string pName)
		{
			name = pName;
		}
		int GetPrice()
		{
			return price;
		}
		int GetPowerDraw()
		{
			if (Type != ComponentType::PSU)
			{
				return powerDraw;
			}
			else
			{
				return 0;
			}
		}
	private:
		std::string name;
		int price;
		std::string socket;
		std::string description;
		int powerDraw;
		ComponentType Type;
		bool isCritical;
};

