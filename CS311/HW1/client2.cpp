#include	<iostream>
#include	"queue.h"

int	main(void)
{
  queue	q2;

  std::string	tmp1, tmp2;
  std::string	cdata[3] = {
    "A", "B", "C"
  };

  q2.add("A");
  std::cout << "A" << std::endl;
  q2.add("B");
  std::cout << "B" << std::endl;
  q2.add("C");
  std::cout << "C" << std::endl;

  try {
    while (true) {
      q2.remove(tmp1);
      for (int i = 0; i < 3; ++i) {
	tmp2 = tmp1 + cdata[i];
	q2.add(tmp2);
	std::cout << tmp2 << std::endl;
      }
    }
  } catch (std::exception* e) {
    std::cerr << "Error: " << e->what() << std::endl;
    return -1;
  }
  return 0;
}
