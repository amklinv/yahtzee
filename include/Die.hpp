#pragma once // Ensures this header is only included once per translation unit

struct Die {
  int value;
  bool locked;

  // Sets value to 0 and locked to false
  void reset();

  // Returns true if value < d.value, false otherwise
  bool operator<(const Die& d);
};