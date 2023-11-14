#define ADD_HEADER_TO_CSV() \
    outputFile << "rs1, hw(rs1)" << std::endl;

#define SET_RAND_VALS() \
    top->valid = 1; \
    top->rs1 = dis64(gen); \
    top->op_ssha256_sig0 = dis(gen); \
    top->op_ssha256_sig1 = dis(gen); \
    top->op_ssha256_sum0 = dis(gen); \
    top->op_ssha256_sum1 = dis(gen);

#define ADD_ROW_TO_CSV() \
    outputFile << top->rs1 << "," << hammingWeight(top->rs1) << std::endl;
