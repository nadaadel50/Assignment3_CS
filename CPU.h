class CPU {
protected:
    int counter = 0;

public:
    int registers[16];
    int ProgramCounter; //keeps track of our instruction cycle
    int InstructionRegister; //loads our instructions from memory
    int Accumulator;

};



