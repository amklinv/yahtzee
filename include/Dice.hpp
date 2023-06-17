#pragma once // Ensures this header is only included once per translation unit

#include Die.hpp
#include <array>
#include <random>

class Dice {
public:
  // Calls reset and the distribution constructor
  Dice();

  // Calls reset on each die
  void reset();

  // Rolls all non-locked dice, then sorts so it's easier to check straights
  void roll();

  // Locks the specified die
  // Throws an exception if the die is already locked
  // Throws an exception if rolled_ is false
  void lock(int dieID);

  // Counts the number of dice equal to a target number
  // Throws an exception if target is not in [1,6]
  // Throws an exception if rolled_ is false
  int count(int target);

  // Determines whether the dice represent a three of a kind
  // Throws an exception if rolled_ is false
  bool is_three_of_kind();

  // Determines whether the dice represent a four of a kind
  // Throws an exception if rolled_ is false
  bool is_four_of_kind();

  // Determines whether the dice represent a five of a kind
  // Throws an exception if rolled_ is false
  bool is_yahtzee();

  // Determines whether the dice represent a full house
  // Throws an exception if rolled_ is false
  bool is_full_house();

  // Determines whether the dice represent a sequence of four
  // Throws an exception if rolled_ is false
  bool is_small_straight();

  // Determines whether the dice represent a sequence of five
  // Throws an exception if rolled_ is false
  bool is_large_straight();

  // Returns the sum of all dice
  // Throws an exception if rolled_ is false
  int sum();
private:
  // Returns false if any die is 0, true otherwise
  bool rolled_();

  // Calls sort on the dice
  void sort_();

  std::default_random_engine generator_;
  std::uniform_int_distribution<int> distribution_;
  std::array<int,5> dice_;
};