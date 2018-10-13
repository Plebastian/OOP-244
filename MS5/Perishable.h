#ifndef __SICT_PERISHABLE_H
#define __SICT_PERISHABLE_H
#include "NonPerishable.h"
#include "Date.h"

namespace sict {
	class Perishable : public NonPerishable {
		Date m_expiry;
	public:
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
};
	Product* CreatePerishable();
}
#endif // !__SICT_PERISHABLE_H
