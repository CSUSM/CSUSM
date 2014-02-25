#include	<vector>
#include	<stdexcept>
#include	<iostream>
#include	<sstream>

// PURPOSE: Combine and sort 2 vectors (A & B) into a third one (R)
// HOW TO CALL: A & B will be sorted into a third vector
void	combine(const std::vector<int>& A, const std::vector<int>& B, std::vector<int>& R)
{
  if (A.size() != B.size())
    throw new std::runtime_error("A & B must be the same size");

  int	IdxA = 0;
  int	IdxB = 0;

  // A and B are already sorted.

  while (R.size() < (A.size() + B.size())) {
    // Cases where one of the list is empty
    if (IdxA == A.size())
      R.push_back(B[IdxB++]);
    else if (IdxB == B.size())
      R.push_back(A[IdxA++]);
    else {
      // Cases where both of the list contains elements
      std::cout << "comparison: [" << A[IdxA] << "] and [" << B[IdxB] << "]" << std::endl;
      if (A[IdxA] < B[IdxB])
	R.push_back(A[IdxA++]);
      else
	R.push_back(B[IdxB++]);
    }
  }
}

// PURPOSE: Transform a string to a number
// HOW TO CALL:
//		- str is the inpu string containing space-separated numbers;
//		- buff is a buffer, previously allocated, to store the elements of str
//		- s is the size of buff, or under, and the number of element to retrieve.
static int*	strToNbr(const std::string& str, int* buff, size_t s)
{
  std::istringstream	iss(str);

  for (int i = 0; i < s; ++i)
    if (!(iss >> buff[i]))
      throw new std::runtime_error("No number was read from the input");
  return buff;
}

// PURPOSE : Entry point of the program
int	main(void)
{
  std::vector<int>	L1, L2, L3;
  int			buff[3];

 readL1:
  try {
    std::cout << "[L1] Type 3 integers in increasing order: ";
    std::string		input;
    getline(std::cin, input);
    strToNbr(input, buff, sizeof(buff) / sizeof(buff[0]));
    for (int i = 0; i < 3; ++i)
      L1.push_back(buff[i]);
  } catch (std::runtime_error* e) {
    std::cout << "[ERROR]: " << e->what() << std::endl;
    L1.clear();
    goto readL1;
  }

 readL2:
  try {
    std::cout << "[L2] Type 3 integers in increasing order: ";
    std::string		input;
    getline(std::cin, input);
    strToNbr(input, buff, sizeof(buff) / sizeof(buff[0]));
    for (int i = 0; i < 3; ++i)
      L2.push_back(buff[i]);
  } catch (std::runtime_error* e) {
    std::cout << "[ERROR]: " << e->what() << std::endl;
    L2.clear();
    goto readL2;
  }

  try {
    combine(L1, L2, L3);
    std::cout << "L3 : " << L3.size() << " item(s)" << std::endl;
    for (int i = 0; i < L3.size(); ++i)
      std::cout << "[" << i << "]: " << L3[i] << std::endl;
    if (0 == L3.size())
      std::cout << "Empty." << std::endl;
  } catch (std::runtime_error* e) {
    std::cout << "Fatal error: " << e->what() << std::endl;
    return 1;
  }
  return 0;
}
