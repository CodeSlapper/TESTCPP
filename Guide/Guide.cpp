// Guide.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Guide.h"
#include "ComputerComponents.h"
#include <fstream>
#include <vector>

bool StringToBool(std::string param)
{
    if (param == "1")
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    #pragma region Variables
    std::vector<ComputerComponents> PC_Build;
    std::vector<std::string> data;
    std::vector<std::string> pcParts;
    std::ifstream componentsData("PcParts.txt");
    std::string temp;
    #pragma endregion

    //adds all parts
    if (componentsData.is_open())
    {
        while (std::getline(componentsData, temp))
        {
            data.push_back(temp);
        }
    }
    //foreach string item in list seperate it like a csv
    for(auto part : data)
    {
        int previousCut = 0;
        std::string placeHolder;
        for (char& spec : part) 
        {
            if (spec == ',')
            {
                pcParts.push_back(placeHolder);
                placeHolder = "";
            }
            else
            {
                placeHolder += spec;
            }
        }

        pcParts.push_back(placeHolder);
        ComputerComponents* test = new ComputerComponents
        (
            pcParts[0],
            std::stoi(pcParts[1]),
            pcParts[2],
            pcParts[3],
            std::stoi(pcParts[4]),
            static_cast<ComputerComponents::ComponentType>(std::stoi(pcParts[5])),
            StringToBool(pcParts[6])
        );
        //why does it need the pointer symbol again?
        PC_Build.push_back(*test);
        pcParts.clear();
        delete test;
    }
    
    // Close the file
    componentsData.close();
    //some user feedback
    int totalCost = 0;
    int totalDraw = 0;
    int PSUWatt = 0;
    for (auto item : PC_Build)
    {
         totalCost += item.GetPrice();
         totalDraw += item.GetPowerDraw();
    }
    std::cout << "Your PC build will cost: " << totalCost << std::endl;
    std::cout << "Your total Draw from the wall is+: " << totalDraw << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
