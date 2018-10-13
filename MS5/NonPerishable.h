// Final Project Milestone 4
// Version 1.0
// Date	2017/12/15 
// Author	Sebastian Pavle Djurovic
//
//
// Revision History
// -----------------------------------------------------------
// Name     Error          Date                Reason

#ifndef __SICT_NONPERISHABLE_H
#define __SICT_NONPERISHABLE_H
#include "Product.h"
#include "ErrorMessage.h"

namespace sict {
	//constants in namespace
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 20;
	const double Tax_Rate = 0.13;

	class NonPerishable : public Product{
	private:
		char m_type;
		char m_sku[max_sku_length];
		char m_name[max_name_length];
		char m_units[max_unit_length];
		int m_qty;
		int m_qtyn;
		double m_price;
		bool taxable;
		ErrorMessage m_error;

	protected:
		void name(const char*);
		const char * name() const;
		double cost() const;
		void message(const char *);
		bool isClear() const;
		
	public:
		NonPerishable(char type = '\0');
		NonPerishable(const char* sku, const char *name, const char *u, int qty = 0, bool tax = false, double price = 0, int qtyn = 0);
		NonPerishable(const NonPerishable&);
		NonPerishable& operator=(const NonPerishable &p);
		~NonPerishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty()const;
		int qtyNeeded() const;
		int quantity() const;
		void setType(char);
		//sku and returns true if the string is greater than the sku of the current object
		bool operator>(const char*) const;
		int operator+=(int);
		bool operator>(const Product&) const;
	};
	//helper functions
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
	Product* CreateProduct();
}
#endif // !__SICT_NONPERISHABLE_H