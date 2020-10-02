#include <list>     // doubly linked list
#include <string>

#include "Repair.hpp"


class RepairList {
	
	// Friend functions: read and write
	friend std::ostream & operator<<( std::ostream & stream, const RepairList & repairlist );
	friend std::istream & operator>>( std::istream & stream, RepairList & repairlist );
	
public:
  RepairList(); // TO DO // default constructor
	
	RepairList( const RepairList & other ) = default; // copy constructor
	RepairList( RepairList && other ) = default; // move constructor
	RepairList & operator=(const RepairList& rhs ) = default; // assignment operator
	RepairList & operator+=( const RepairList & rhs); 
	// TO DO // concatenates the rhs list to the end of this list

	~RepairList(); // TO DO // destructor

  // Queries or getters
  std::size_t size() const; // TO DO
  // returns the number of repair requests in the list
	Repair currRepair() const; // TO DO // return the current repair request

  // read from a file
  void loadAdvanceList(const std::string& filename);
  
	// Mutators
  void next(); // TO DO //go to the next repair request in the list, if any; return error if none
  void addToList(const Repair& newRequest); // TO DO // append a new repair request to the end of the list
	void insertLoyal(const Repair& newRequest); // TO DO // insert a new repair request in the current position of the list 
	
private:
	// Instance attributes, but you can select to use your
// own implementation of Doubly Linked List
// or use std::forward_list<Repair> instead
	std::list<Repair> _dailyList;
	std::list<Repair>::iterator _nowServicing = _dailyList.end();
}; 
