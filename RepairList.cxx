#include <fstream>
#include <iterator>  // next()
#include <stdexcept>  // invalid_argument
#include <string>  // string

#include "RepairList.hpp"

using std::string;
using std::ifstream;

/**********************************************
 **  Public/private implementations, types, and objects
 ** for class RepairList
 **********************************************/

/*************************************
 **  Friend functions: read and write
 *************************************/
std::ostream& operator<<(std::ostream& stream, const RepairList& repairlist) {
  for (const auto& request : repairlist._dailyList) stream << '\n' << std::setw(5) << request;

  return stream;
}

std::istream& operator>>(std::istream& stream, RepairList& repairlist) {
  Repair request;

  while (stream) {
    stream >> request;
    repairlist.addToList(std::move(request));
  }
  return stream;
}

/***********************
 ** Constructor
 ***********************/
RepairList::RepairList() : _dailyList(), _nowServicing() {
}

/*********************
 ** Destructor
 *********************/
RepairList::~RepairList() {
  _dailyList.clear();
}

/************************
 ** Assignment operator
 ************************/
RepairList& RepairList::operator+=(const RepairList& rhs) {
  // Concatenate the right-hand side list of repair requests to this list by
  // repeatedly adding each repair at the end of the current repair list.
  for (const auto& requests : rhs._dailyList) {
    _dailyList.push_back(requests);
  }
  return *this;
}

/***********************
 ** Queries or getters
 ***********************/
std::size_t RepairList::size() const {
  // return the size of the list
  return _dailyList.size();
}

// return the current repair
Repair RepairList::currRepair() const {
  return *_nowServicing;
}

/***********************
 ** Mutators
 ***********************/
// read the list of advanced repair requests from the specified file
void RepairList::loadAdvanceList(const std::string& filename) {
  std::ifstream inFile(filename);
  Repair newRequest;

  if (inFile.is_open()) {
    // Read each line
    while (inFile >> newRequest) {
      addToList(newRequest);
    }
    inFile.close();  // file closes
    _nowServicing = _dailyList.begin();
  }
  else {
    throw std::invalid_argument("Could not open " + filename);
  }
}

// The current repair has been serviced, so
// move the iterator to the next request.
void RepairList::next() {
  ++_nowServicing;
}

// Add a repair request to the current list.
void RepairList::addToList(const Repair& newRequest) {
  _dailyList.push_back(newRequest);
}

// Insert a repair request coming from a loyal customer
// right after the current iterator, but do not make
// changes to the current iterator.
void RepairList::insertLoyal(const Repair& newRequest) {
  auto loyalRequest = _nowServicing;
  if (_nowServicing != _dailyList.end()) {
    ++loyalRequest;
  }
  _dailyList.insert(loyalRequest, newRequest);
}
