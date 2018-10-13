// TODO: add file header comments here

// TODO: add header file guard here
#ifndef _PASSENGER_H
#define _PASSENGER_H
// TODO: declare your namespace here
namespace sict{
    // TODO: define the Passenger class here
	int const length = 33;
    class Passenger{
    private: 
    	char m_name[length];
    	char m_destination[length];
		int m_year;
		int m_month;
		int m_day;
    	
    public:
		Passenger();
    	Passenger(const char * name, const char * destination);
		Passenger(const char * name, const char * destination, int year, int month, int day);
		const char* name() const;
    	bool isEmpty() const;
    	void display() const; 
		bool canTravelWith(const Passenger& ) const;
	};
}

#endif //!_PASSENGER_H