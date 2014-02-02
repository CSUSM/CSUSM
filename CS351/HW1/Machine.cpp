#include    <iostream>
#include    <iomanip>
#include    <fstream>
#include    <sstream>
#include    "Machine.hh"

std::string IntToString(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

Machine::Machine()
{
    // We initialize the machine's state
    eax = 0;
    eip = OPCODE_OFFSET;
    for (int i = 0; i < MEMORY_SIZE; ++i)
        memory[i] = 0;

    // Then the operations
    Instruction[0] = &Machine::Load;
    Instruction[1] = &Machine::Store;
    Instruction[2] = &Machine::Add;
    Instruction[3] = &Machine::Sub;
    Instruction[4] = &Machine::Branch;
    Instruction[5] = &Machine::Stop;
}

// Trivial -- No extra heap allocation.
Machine::~Machine()   {}

// This function just read an int from a line and returns it.
static int  readInt(const std::string& line, int lineNum)
{
    int tmp;
    std::istringstream iss(line);
    // Store in the memory each line.
    if (!(iss >> tmp))
        throw new Machine::LoadError(
            std::string("Unexpected token at line ")
            + IntToString(lineNum));
    return tmp;
}

Machine&   Machine::loadFromFile(const std::string& path)
{
    Machine&            ret = *(new Machine());
    
    try {
        int             offset = DATA_OFFSET; // offset in memory
        int             lineNum = 0; // For better error reporting.
        std::ifstream   file(path.c_str());
        std::string     line; // Line readed.
        short           separators = 0; // How many separator we read.

        // We read line by line
        while (std::getline(file, line)) {
            ret.MemoryAt(offset++) = readInt(line, ++lineNum);

            // We check for separator, and remove it from memory.
            if (ret.MemoryAt(offset - 1) == 9999) {
                ret.MemoryAt(offset - 1) = 0;
                if (++separators == 2)
                    break;
                offset = OPCODE_OFFSET;
            }

            // Check for too many data
            if (offset >= OPCODE_OFFSET && separators == 0)
                throw new LoadError("Too many data in file (max is 1000)");
            // Check for too many opcode
            if (offset == MEMORY_SIZE)
                throw new LoadError("Too many opcode (max is 999)");
        }
        return ret;
    } catch (std::exception* e) {
        // We need to ensure the memory is correctly free'd
        delete &ret;
        throw;
    }
}

int     Machine::Run(void)
{
    int nextOpcode;
    while (true) {
        nextOpcode = MemoryAt(eip++);
        if (nextOpcode < 1000 || nextOpcode >= 7000)
            throw new InvalidOpcode("An opcode should be in the range "
                                    "1000 <= x < 7000");
        // First instruction is 1XXX, so we need the " - 1".
        nextOpcode = (this->*(Instruction[OpcodeOf(nextOpcode) - 1]))(nextOpcode);
        if (nextOpcode != 0)
            return OperandOf(nextOpcode);
        std::cout << "Next instruction (eip): " << eip << " -- Accumulator (eax): " << eax << std::endl;
    }
}

int     Machine::Load(int value)
{
    std::cout << "Load " << value << std::endl;
    eax = MemoryAt(OperandOf(value));
    return 0;
}

int     Machine::Store(int value)
{
    std::cout << "Store " << value << std::endl;
    MemoryAt(OperandOf(value)) = eax;
    return 0;
}

int     Machine::Add(int value)
{
    std::cout << "Add " << value << std::endl;
    eax += MemoryAt(OperandOf(value));
    return 0;
}

int     Machine::Sub(int value)
{
    std::cout << "Sub " << value << std::endl;
    eax -= MemoryAt(OperandOf(value));
    return 0;
}

int     Machine::Branch(int value)
{
    std::cout << "Branch " << value << std::endl;
    if (this->eax >= 0)
        eip = OPCODE_OFFSET + OperandOf(value);
    return 0;
}

int     Machine::Stop(int value)
{
    std::cout << "Stop " << value << std::endl;
    return value;
}

int     Machine::OpcodeOf(int value) const  { return (value / 1000); }
int     Machine::OperandOf(int value) const { return (value % 1000); }
int&    Machine::MemoryAt(int addr)         { return (this->memory[addr]); }
int     Machine::ReadMemory(int addr) const { return (this->memory[addr]); }

void    Machine::DumpDataMemory() const
{
    // show the 0x prefix, and fill it with '0'

    for (int i = 0; i < OPCODE_OFFSET; i += 8) {
        for (int j = 0; j < 8 && (i + j) < OPCODE_OFFSET; ++j)
            std::cout << std::showbase << std::internal
                      << std::setfill('0') << std::hex
                      << std::setw(6) << ReadMemory(i + j) << " ";
        std::cout << std::endl;
    }

    // Reset to default value
    std::cout << std::resetiosflags(std::ios_base::adjustfield
                                    | std::ios_base::basefield);
}
