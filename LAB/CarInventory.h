/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
------------------------------------------------------
Workshop 4 part 1
Module: CarInventory
Filename : CarInventory.h
Version 1
Student	Noel Ibruli
Seneca ID : 117745216
Seneca Email : nibruli@myseneca.ca
Date : 2 / 10 / 22 (MM / DD / YY)
------------------------------------------------------
*/
#ifndef SDDS_CARINVENTORY_H
#define SDDS_CARINVENTORY_H

#define MIN_YEAR 1990
#define MIN_PRICE 0
#define MIN_DIGITS 100

namespace sdds{

	class CarInventory
	{
	private:
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;

	private:
		void resetInfo();

	public:
		// default constructor
		CarInventory();
		// parameterized constructor
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
		// destructor
		~CarInventory();
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;
	};
	bool find_similar(CarInventory car[], const int num_cars);
}

#endif