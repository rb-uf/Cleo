#define ADD_HEADER_TO_CSV() \
    outputFile << "hw(rs1)+hw(rs2)" << std::endl;

#define SET_RAND_VALS()                                     \
    top->valid = 1;                                         \
    top->rs1 = distHw<uint32_t>(dis32(gen), generator);     \
    top->rs2 = distHw<uint32_t>(dis32(gen), generator);     \
    top->enc = dis(gen);                                    \
    top->rot = dis(gen);

#define ADD_ROW_TO_CSV() \
    outputFile << hammingWeight(top->rs1) + hammingWeight(top->rs2) << std::endl;
