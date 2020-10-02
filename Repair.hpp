#pragma once    // include guard

#include <iostream>
#include <iomanip>
#include <cstddef>      // size_t
#include <string>

class Repair
{
  // Friend functions: read and write
  friend std::ostream & operator<<( std::ostream & stream, const Repair & request );
  friend std::istream & operator>>( std::istream & stream, Repair & request );

public:
  // Constructor (can be the default constructor)
  Repair(const std::string & name  = "", const std::string & vehicle = "", const std::string & date = "", const std::string & services = "", const double & cost  = 0.0 );

  // Queries or getters
  std::string name  () const;
  std::string vehicle () const;
  std::string date () const;
  std::string services () const;
  double      cost () const;

  // Mutators or setters
  void set_name    ( const std::string & newName   );
  void set_vehicle ( const std::string & newVehicle  );
  void set_date    ( const std::string & newDate );
  void set_services( const std::string & newServices );
  void set_cost    ( double newCost  );

  private:
  std::string _name;
  std::string _vehicle;
  std::string _date;
  std::string _services;
  double      _cost = 0.0;
};

// Ordinary functions: Relational Operators
bool operator==( const Repair & lhs, const Repair & rhs );
bool operator!=( const Repair & lhs, const Repair & rhs );

//#include "Repair.cxx"