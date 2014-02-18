// Author: Mathias LANG
// For HW2P1 in CS311, Spring 2014
//
// Instructions:
// Your main() will fill an array of 10 slots with
// integers 1 3 5 7 9 11 13 15 17 19.
// It will then ask the user to enter a number to look for.
// It will then call binarySearch and display the returned result.
// e.g. “The number was found in position 5”

#include	<iostream>
#include	<sstream>
#include	<stdexcept>
#include	<string>

namespace _Impl {
  // Algo:	Uses tail recursion, so space is not an issue.
  int	binarySearchImpl(int nbr, int* aggr, size_t aggrSize, size_t offset)
  {
    int	pivot = (aggrSize / 2);
    // We found it
    if (nbr == aggr[pivot])
      return offset + pivot;
    // We're not going to find it
    if (pivot == 0)
      return -1;
    size_t skip = (nbr > aggr[pivot]) ? (pivot) : (0);
    return (binarySearchImpl(nbr, aggr + skip, aggrSize - pivot, offset + skip));
  }
}

// Purpose:	Perform a binary search on an int array.
// Howto call:	Provide the number you are looking for, the array,
//			and the original size of the array.
// Returns:	-1 if not found, or the index.
int	binarySearch(int nbr, int* aggr, size_t aggrSize)
{
  return _Impl::binarySearchImpl(nbr, aggr, aggrSize, 0);
}

int	main(void)
{
  int		data[] = { 1,3, 5, 7, 9, 11, 13, 15, 17, 19 };
  std::string	readData;
  int		num;

  try {
    std::cout << "Enter a number to search: ";
    std::cin >> readData;
    std::istringstream(readData) >> num;

    if (-1 == (num = binarySearch(num, data, sizeof(data) / sizeof(int))))
      std::cout << "The number was not found." << std::endl;
    else
      std::cout << "The number was found in position " << 1 +num << std::endl;
  } catch (std::exception* e) {
    std::cout << "An error occured !" << std::endl;
    return -1;
  }
  return 0;
}
