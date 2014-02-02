#pragma once

#include    <string>
#include    <stdexcept>

#define MEMORY_SIZE     (2000)
#define DATA_OFFSET     (0)
#define OPCODE_OFFSET   (MEMORY_SIZE / 2)

/********************************************************************/
/* PURPOSE: Can load a state into memory and execute instructions.  */
/* USING: Standard exceptions type and std::string.                 */
/* USED IN: main.cpp                                                */
/* ALGORITHM: Use an array of member function pointer for the       */
/*              instructions.                                       */
/* DATA STRUCTURES: An array of 2000 int representing the memory,   */
/*                  and two values, eax (accumulator) and eip, the  */
/*                  instruction pointer.                            */
/********************************************************************/
class Machine {
public:
/********************************************************************/
/* PURPOSE: Allow user to load the state of a machine from a file.  */
/* RATIONALE: A C++ constructor shouldn't do heavy-lifting. Thus,   */
/*              it's a bad practise to put I/O in a Ctor.           */
/* INPUT PARAMETERS: std::string path => Path to the memory file.   */
/* RETURN: Either returns an initialized Machine object which can   */
/*          be run()'ed after, or throw on error.                   */
/********************************************************************/
    static Machine&    loadFromFile(const std::string& path);

/****************************************************************/
/* PURPOSE: Starts the virtual machine.                         */
/* RATIONALE: The Run parts belongs to the VM. It's the "main"  */
/* RETURN: A return code, 0 on success and non-0 on failure.    */
/* ALGORITHM: Just iterates over the instruction, decode them   */
/*              and call the right instruction.                 */
/****************************************************************/
    int    Run();

/********************************************************/
/* PURPOSE: Report exceptions about invalid opcodes.    */
/* USING: Inherit from std::runtime_error.              */
/* USED IN: Catched in main.cpp                         */
/********************************************************/
    class InvalidOpcode : public std::runtime_error {
    public:
        InvalidOpcode(std::string msg) : std::runtime_error(msg) {}
    };


/********************************************************/
/* PURPOSE: Report errors about file loading failure.   */
/* USING: Inherit from std::runtime_error.              */
/* USED IN: Catched in main.cpp                         */
/********************************************************/
    class LoadError : public std::runtime_error {
    public:
        LoadError(std::string msg) : std::runtime_error(msg) {}
    };

    // This is a trivial destructor.
    ~Machine();

/********************************************************/
/* PURPOSE: Dump the memory on stderr.                  */
/* RATIONALE: Reports the memory status at the end of   */
/*              execution.                              */
/********************************************************/
    void    DumpDataMemory() const;    

private:
    // Default constructor, trivial.
    Machine();

/****************************************************************/
/* PURPOSE: Load accumulator with contents of value's operand.  */
/* RATIONALE: All the instructions have a specific function.    */
/* INPUT PARAMETERS: value : The instruction beeing executed.   */
/* RETURN: 0 on success, and error code on failure.             */
/****************************************************************/
    int     Load(int value);

/****************************************************************/
/* PURPOSE: Store accumulator into the location of value's      */
/*          operand.                                            */
/* RATIONALE: All the instructions have a specific function.    */
/* INPUT PARAMETERS: value : The instruction beeing executed.   */
/* RETURN: 0 on success, and error code on failure.             */
/****************************************************************/
    int     Store(int value);

/****************************************************************/
/* PURPOSE: Add contents of value's operand to accumulator.     */
/* RATIONALE: All the instructions have a specific function.    */
/* INPUT PARAMETERS: value : The instruction beeing executed.   */
/* RETURN: 0 on success, and error code on failure.             */
/****************************************************************/
    int     Add(int value);

/****************************************************************/
/* PURPOSE: Subtract contents of value's operand from           */
/*          the accumulator.                                    */
/* RATIONALE: All the instructions have a specific function.    */
/* INPUT PARAMETERS: value : The instruction beeing executed.   */
/* RETURN: 0 on success, and error code on failure.             */
/****************************************************************/
    int     Sub(int value);

/****************************************************************/
/* PURPOSE: Branch to instruction refered to by value's operand */
/*              if accumulator is positive.                     */
/* RATIONALE: All the instructions have a specific function.    */
/* INPUT PARAMETERS: value : The instruction beeing executed.   */
/* RETURN: 0 on success, and error code on failure.             */
/****************************************************************/
    int     Branch(int value);

/****************************************************************/
/* PURPOSE: Stop the execution.                                 */
/* RATIONALE: All the instructions have a specific function.    */
/* INPUT PARAMETERS: value : The instruction beeing executed.   */
/* RETURN: value.                                               */
/****************************************************************/
    int     Stop(int value);


/************************************************************/
/* PURPOSE: Call the instruction in an uniform way.         */
/* RATIONALE: It scales, whenever switch/case or if don't.  */
/************************************************************/
    int     (Machine::*Instruction[6])(int);

/************************************************************/
/* PURPOSE: Returns the opcode from an instruction.         */
/* RATIONALE: Better readability and maintenance.           */
/* INPUT PARAMETERS: value : The instruction to decode.     */
/* RETURN: The opcode, a value between 1 and 6 included.    */
/************************************************************/
    int     OpcodeOf(int value) const;

/************************************************************/
/* PURPOSE: Returns the operand from an instruction.        */
/* RATIONALE: Better readability and maintenance.           */
/* INPUT PARAMETERS: value : The instruction to decode.     */
/* RETURN: The operand, a value between 0 and 999 included. */
/************************************************************/
    int     OperandOf(int value) const;

/************************************************************/
/* PURPOSE: Returns a reference to a memory address.        */
/* RATIONALE: Better information hiding and readability.    */
/* INPUT PARAMETERS: addr : The address being accessed.     */
/* RETURN: An rvalue to the requested memory location       */
/************************************************************/
    int&    MemoryAt(int addr);
    // The same as above, only provided for const-correctness
    // (Covariant return value are forbidden in C++).
    int     ReadMemory(int addr) const;

/********************************************************/
/* PURPOSE: Holds the address of the next instruction   */
/*          to be executed.                             */
/********************************************************/    
    int eip;

/********************************************************/
/* PURPOSE: It's the accumulator (see pdf).             */
/********************************************************/
    int eax;

/********************************************************/
/* PURPOSE: This is the memory of the virtual machine.  */
/********************************************************/
    int memory[MEMORY_SIZE];
};
