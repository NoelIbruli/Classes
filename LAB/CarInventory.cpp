/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
------------------------------------------------------
Workshop 4 part 1
Module: CarInventory
Filename : CarInventory.cpp
Version 1
Student	Noel Ibruli
Seneca ID : 117745216
Seneca Email : nibruli@myseneca.ca
Date : 2 / 10 / 22 (MM / DD / YY)
------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "CarInventory.h"

namespace sdds {

	// sets member variables to a safe state
	void CarInventory::resetInfo()
	{
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	// calls reset info 
	// default constructor will be called at the start of the program and reset all the values of the member variables
	CarInventory::CarInventory()
	{
		resetInfo();
	}

	// validates the values
	bool CarInventory::isValid() const
	{
		return m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= MIN_YEAR && m_code >= MIN_DIGITS && m_price >= MIN_PRICE;
	}

	// dynamically keep the values of the C-string argument in their corresponding attributes and set the rest of the attributes the corresponding argument values if they pass validation
	// Otherwise it will reset the information (see void resetInfo())
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		if (type != nullptr || brand != nullptr || model != nullptr || year >= MIN_YEAR || code >= MIN_DIGITS || price > MIN_PRICE)
		{
			m_type = nullptr;
			m_brand = nullptr;
			m_model = nullptr;
			setInfo(type, brand, model, year, code, price);
		}
		else
			resetInfo();
	}

	// destructor will deallocate memory at the end of the program
	CarInventory::~CarInventory()
	{
		delete[] m_type;
		m_type = nullptr;
		delete[] m_brand;
		m_brand = nullptr;
		delete[] m_model;
		m_model = nullptr;
	}

	// function deletes previously allocated memory.
	// sets the pointers to nullptr
	// allocates new memory
	// copies the variables to member variables
	// returns the reference to that object
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		delete[] m_type;
		m_type = nullptr;
		delete[] m_brand;
		m_brand = nullptr;
		delete[] m_model;
		m_model = nullptr;
		if (type == nullptr || brand == nullptr || model == nullptr || year < 1990 || code < 100 || price < 0)
		{
			resetInfo();
		}
		else
		{
			m_type = new char[strlen(type) + 1];
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];
			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);

			m_year = year;
			m_code = code;
			m_price = price;
		}

		// returns the reference to that object
		return *this;
	}

	// prints the cars
	void CarInventory::printInfo() const
	{
		std::cout << "|" << " " << std::left << std::setw(11) << m_type << "|" << " " << std::left << std::setw(17) << m_brand << "|" << " " << std::left << std::setw(17) << m_model << "|" << " " << std::left << std::setw(5) << m_year << "|" << "  " << std::left << std::setw(4) << m_code << "|" << "  " << std::left << std::right << std::setw(8) << std::fixed << std::setprecision(2) << m_price << " " << "|" << std::endl;
	}

	// function check whether all the attributes of one object are the same as all the attributes of another object  
	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		return m_type == car.m_type && m_brand == car.m_brand && m_model == car.m_model && m_year == car.m_year;
	}

	// function returns true if it finds two objects that have similar information in the car array
	bool find_similar(CarInventory car[], const int num_cars)
	{
		for (int i = 0; i < num_cars; i++)
		{
			for (int j = i + 1; j < num_cars; j++)
			{
				if (car[i].isSimilarTo(car[j]))
				{
					return true;
				}
			}
		}
		return false;
	}
}