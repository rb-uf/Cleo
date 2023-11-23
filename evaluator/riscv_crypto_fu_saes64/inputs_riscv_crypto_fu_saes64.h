#define ADD_HEADER_TO_CSV() \
    outputFile << "hw(rs1)+hw(rs2)" << std::endl;

#define SET_RAND_VALS() \
    /* the corresponding verilog file defines two additional inputs not present in the 32 bit version: g_clk and g_resetn */ \
    top->valid = 1; \
    top->rs1 = distHw<uint64_t>(dis64(gen), generator); \
    top->rs2 = distHw<uint64_t>(dis64(gen), generator); \
    top->enc_rcon = dis4(gen); \
    top->op_saes64_ks1 = dis(gen); \
    top->op_saes64_ks2 = dis(gen); \
    top->op_saes64_imix = dis(gen); \
    top->op_saes64_encs = dis(gen); \
    top->op_saes64_encsm = dis(gen); \
    top->op_saes64_decs = dis(gen); \
    top->op_saes64_decsm = dis(gen);

#define ADD_ROW_TO_CSV() \
    outputFile << hammingWeight(top->rs1) + hammingWeight(top->rs2) << std::endl;
    // outputFile << top->rs1 << "," << top->rs2 << "," << hammingWeight(top->rs1) << "," << hammingWeight(top->rs2) << std::endl;
