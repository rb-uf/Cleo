#define ADD_HEADER_TO_CSV() \
    outputFile << "hw(rs1)+hw(rs2)" << std::endl;

#define SET_RAND_VALS() \
    top->valid = 1; \
    top->rs1 = distHw<uint32_t>(dis32(gen), generator); \
    top->rs2 = distHw<uint32_t>(dis32(gen), generator); \
    top->bs = dis2(gen); \
    top->op_saes32_encs = dis(gen); \
    top->op_saes32_encsm = dis(gen); \
    top->op_saes32_decs = dis(gen); \
    top->op_saes32_decsm = dis(gen);

#define ADD_ROW_TO_CSV() \
    outputFile << hammingWeight(top->rs1) + hammingWeight(top->rs2) << std::endl;
    //outputFile << top->rs1 << "," << top->rs2 << "," << hammingWeight(top->rs1) << "," << hammingWeight(top->rs2) << std::endl;
