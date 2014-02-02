/********************************************************************/
/* PURPOSE: A little virtual machine fulfilling the requirements    */
/*          of HW1 for CS351.                                       */
/* IMPLEMENTED BY: Mathias LANG                                     */
/* Course:  CS 351                                                  */
/* INSTRUCTOR: Shaun-Inn Wu                                         */
/* DATE: 30 January 2014                                            */
/* INPUT: The program expect a path to a correctly-formatted        */
/*        memory file. To see what the correct format is, please    */
/*        refer to the HW1 pdf.                                     */
/* OUTPUT: The program output its result to std::cout.              */
/* OVERVIEW OF SUBPARTS: All the algorithm is in the Machine class. */
/********************************************************************/
#include    <iostream>
#include    "Machine.hh"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "Usage: " << av[0]
                  << " path/to/memory/file"
                  << std::endl;
        return 1;
    }

    Machine&   vm = Machine::loadFromFile(av[1]);
    try {
        int retcode = vm.Run();
        std::cout << "--------------------" << std::endl;
        std::cout << "Dump of memory :" << std::endl;
        std::cout << "--------------------" << std::endl;
        vm.DumpDataMemory();
        return retcode;
    } catch (std::exception* e) {
        std::cerr << "Error: " << e->what() << std::endl;
    }
    return 1;
}
