// TODO: add header guard
#ifndef CONTACT_H
#define CONTACT_H

// TODO: add namespace here
namespace sict {
	class Contact
	{
		char m_name[20];
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers;
	public:
		//char name[21];
		//long long phoneNumbers;
		//int noOfPhoneNumbers;
		// TODO: add the default constructor here
		Contact(); //default consturctor
		// TODO: add the constructor with parameters here
		Contact(char name[] , long long phoneNumbers[], int noOfPhoneNumbers);
		// TODO: add the destructor here
		~Contact();
		// TODO: add the display function here
		void display() const;
		// TODO: add the isEmpty function here
		bool isEmpty() const;
	public:
		Contact(const Contact& other) = delete;
		Contact& operator=(const Contact& other) = delete;
		Contact& operator+=(long long);
	};
};

#endif // !CONTACT_H