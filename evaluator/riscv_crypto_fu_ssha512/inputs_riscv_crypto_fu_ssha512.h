#define ADD_HEADER_TO_CSV() \
    outputFile << "rs1, rs2, hw(rs1), hw(rs2)" << std::endl;

#define SET_RAND_VALS() \
    top->valid = dis(gen); \
    top->rs1 = dis64(gen); \
    top->rs2 = dis64(gen); \
    top->op_ssha512_sum0r = dis(gen); \
    top->op_ssha512_sum1r = dis(gen); \
    top->op_ssha512_sig0l = dis(gen); \
    top->op_ssha512_sig0h = dis(gen); \
    top->op_ssha512_sig1l = dis(gen); \
    top->op_ssha512_sig1h = dis(gen); \
    top->op_ssha512_sig0 = dis(gen); \
    top->op_ssha512_sig1 = dis(gen); \
    top->op_ssha512_sum0 = dis(gen); \
    top->op_ssha512_sum1 = dis(gen);

#define ADD_ROW_TO_CSV() \
    outputFile << top->rs1 << "," << top->rs2 << "," << hammingWeight(top->rs1) << "," << hammingWeight(top->rs2) << std::endl;
