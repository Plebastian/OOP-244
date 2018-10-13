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
    	
    public:
		Passenger();
    	Passenger(const char * name, const char * destination);
    	bool isEmpty() const;
    	void display() const; 
	};
}

#endif //!_PASSENGER_H