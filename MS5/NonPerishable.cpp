// Final Project Milestone 5
// Version 1.0
// NonPerishable	
// Author	Sebastian Djurovic
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include "NonPerishable.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <istream>

using namespace std;

void sict::NonPerishable::name(const char * n)
{
	if (n != '\0' || n != nullptr) {
		strncpy(m_name, n, max_name_length);
		m_name[max_name_length] = '\0';
	}
	else
		m_name[0] = '\0';
}

const char * sict::NonPerishable::name() const
{
	if (m_name[0] != '\0' || m_name != nullptr)
		return m_name;
	else
		return nullptr;
}

double sict::NonPerishable::cost() const
{
	if (taxable)
		return m_price * (Tax_Rate) + m_price;
	else
		return m_price;
}

void sict::NonPerishable::message(const char *msg)
{
	//sets error message;
	m_error.ErrorMessage::message(msg);
}

bool sict::NonPerishable::isClear() const
{
	return m_error.ErrorMessage::isClear();
}

sict::NonPerishable::NonPerishable(char type)
{
	m_type = type;
	m_sku[0] = '\0';
	m_name[0] = '\0';
	m_qty = 0;
	m_price = 0;
	taxable = true;
	m_error.clear();
}

sict::NonPerishable::NonPerishable(const char * sku, const char * name, const char *u, int qty, bool tax, double price, int qtyn) //: NonPerishable('N')
{
	strncpy(m_sku, sku, max_sku_length);
	m_sku[max_sku_length] = '\0';
	NonPerishable::name(name); 
	strncpy(m_units, u, max_unit_length);
	m_units[max_unit_length] = '\0';
	m_qty = qty;
	m_price = price;
	taxable = tax;
	if (qtyn < 0){
		m_qtyn = 0;
	}
	else{
		m_qtyn = qtyn;
	}
	m_error.clear();
}

sict::NonPerishable::NonPerishable(const NonPerishable &cp)
{
	m_type = cp.m_type;
	strncpy(m_sku, cp.m_sku, max_sku_length);
	NonPerishable::name(cp.m_name); 
	strncpy(m_units, cp.m_units, max_unit_length);
	m_qty = cp.m_qty;
	m_price = cp.m_price;
	taxable = cp.taxable;
	if (cp.m_qtyn < 0){
		m_qtyn = 0;
	}
	else{
		m_qtyn = cp.m_qtyn;
	}
	m_error.clear();

}

sict::NonPerishable& sict::NonPerishable::operator=(const NonPerishable & p)
{	strncpy(m_sku, p.m_sku, max_sku_length);
	m_type = p.m_type;
	name(p.m_name);
	m_qty = p.m_qty;
	m_price = p.m_price;
	taxable = p.taxable;
	m_qtyn = p.m_qtyn;
	m_error.clear();
	return *this;
}


sict::NonPerishable::~NonPerishable()
{

}

std::fstream & sict::NonPerishable::store(std::fstream & file, bool newLine) const
{
	file << m_type << "," << m_sku << "," << name() << "," << m_price << ","  << taxable << "," << m_qty << ","  << m_units << "," << m_qtyn ;
	
	if (newLine) {
		file << endl;
	}
	 return file;
}

std::fstream & sict::NonPerishable::load(std::fstream & file)
{

	char sku[max_sku_length];
	char name[max_name_length];
	char unit[max_unit_length];
	double price;
	bool tax;
	int qty;
	int qtyn;

	file.getline(sku, max_sku_length, ',');
	file.getline(name, max_name_length, ',');
	file >> price;
	file.ignore();
	file >> tax;
	file.ignore();
	file >> qty;
	file.ignore();
	file.get(unit, 10, ',');
	file.ignore();
	file >> qtyn;

	*this = NonPerishable(sku, name, unit, qty, tax, price, qtyn);
	strncpy(m_units, unit, max_unit_length);
	m_units[max_unit_length] = '\0';
	return file;
	
}

std::ostream & sict::NonPerishable::write(std::ostream & os, bool linear) const
{
	//This function inserts a record with comma separated fields containing the data for the current object
	if (!isClear()){
		os << m_error;
	}
	else if (isClear()){
		if (linear) {
			os << setfill(' ') << left << setw(7) << m_sku << '|'
				<< left << setw(20) << name() << '|'
				<< right << setw(7) << fixed << setprecision(2) << cost() << '|'
				<< right << setw(4) << quantity() << '|'
				<< left << setw(10) << m_units << '|'
				<< right << setw(4) << m_qtyn << '|';
		}
		else {
			os << "Sku: " << m_sku << endl
				<< "Name: " << name() << endl
				<< "Price: " << m_price << endl;
			if (taxable) {
				os << "Price after tax: " << cost() << endl;
			}
			else {
				os << "Price after tax: N/A" << endl;
			}
			os << "Quantity On Hand: " << quantity() << " " << m_units << endl
				<< "Quantity Needed: " << qtyNeeded();
		}
	}
	return os;
}

std::istream & sict::NonPerishable::read(std::istream & is)
{
	char sku[max_sku_length + 1];
	char name[20];
	char unit[max_unit_length + 1];
	double price;
	char taxed;
	int qty;
	int qtyn;
	m_error.clear();
	//m_type = 'N';
	if (m_type != 'P') {
		m_type = 'N';
	}
	if (!is.fail()) {
		cout << " Sku: ";
		is >> sku;
		if (!is.fail()) {
			strncpy(m_sku, sku, max_sku_length);
			m_sku[max_sku_length] = '\0';
		}

		cout << " Name: ";
		is >> name;
		if (!is.fail()) {
			strncpy(m_name, name, 20);
		}
		cout << " Unit: ";
		is >> unit;
		if (!is.fail()) {
			strncpy(m_units, unit, max_unit_length);
			m_units[max_unit_length] = '\0';
		}
	//	message(nullptr);
		if (isClear()) {
			cout << " Taxed? (y/n): ";
			is >> taxed;
			if (!is.fail()) {
				//cerr << taxed << endl;
				if (taxed == 'Y' || taxed == 'y') {
					taxable = true;
					m_error.clear();
				}
				else if (taxed == 'N' || taxed == 'n') {
					taxable = false;
					m_error.clear();
				} 
				else{
					message("Only (Y)es or (N)o are acceptable");
					is.setstate(ios::failbit);
				}
			}
		}

		if (isClear()) {
				cout << " Price: ";
				is >> price;
				if (is.fail()){
				message("Invalid Price Entry");
				is.setstate(ios::failbit);
						
				}
				else {
					m_price = price;
					m_error.clear();
			}
		}
				

		if (isClear()) {
			cout << "Quantity On hand: ";
			is >> qty;
			if (is.fail()) {
				message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
			}
			else {
				quantity(qty);
				}
		}
		if (isClear()) {
			cout << "Quantity Needed: ";
			is >> qtyn;
			if (is.fail()) {
				message("Invalid Quantity Needed Entry");
				is.setstate(ios::failbit);
			}
			else {
				m_qtyn = qtyn;
				m_error.clear();
			}
		}	
		
	}
		return is;
}


bool sict::NonPerishable::operator==(const char *sku) const
{
	//compares a char to the current sku of the object
	if(strcmp(sku, m_sku) == 0){ 
		return true;
	}
	return false;
}

double sict::NonPerishable::total_cost() const
{
	return quantity()*cost();
}

void sict::NonPerishable::quantity(int qty)
{
	m_qty = qty;
}

bool sict::NonPerishable::isEmpty() const
{
	//check if has type if not it's an empty obj
	if(m_type == '\0'){
		return true;
	}
	return false;
}

int sict::NonPerishable::qtyNeeded() const
{
	return m_qtyn;
}

int sict::NonPerishable::quantity() const
{
	return m_qty;
}

void sict::NonPerishable::setType(char t)
{
	m_type = t;
}

bool sict::NonPerishable::operator>(const char *sku) const
{
	// If the sku is greater than the m_sku
	return (strcmp(sku, m_sku) > 0); 
}

int sict::NonPerishable::operator+=(int num)
{
	if (num > 0){
		int temp = num + quantity();
		quantity(temp);
	}
	return quantity();
}

bool sict::NonPerishable::operator>(const Product & obj) const
{
	//returns true if current name is the same as obj else false otherwise 
	return strcmp(obj.name(), name());
}

std::ostream & sict::operator<<(std::ostream & os, const Product & p)
{
	return p.write(os, true);
}

std::istream & sict::operator>>(std::istream &is, Product &p)
{
	return p.read(is);
}

double sict::operator+=(double & d, const Product &p)
{
	d += p.total_cost();
	return d;
}

sict::Product* sict::CreateProduct()
{
	Product* d = new NonPerishable();
	return d;
}




