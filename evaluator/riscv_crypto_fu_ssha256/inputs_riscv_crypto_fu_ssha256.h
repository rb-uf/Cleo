#define ADD_HEADER_TO_CSV() \
    outputFile << "hw(rs1)" << std::endl;

#define SET_RAND_VALS() \
    top->valid = 1; \
    top->rs1 = dist64hw(dis64(gen), generator); \
    top->op_ssha256_sig0 = dis(gen); \
    top->op_ssha256_sig1 = dis(gen); \
    top->op_ssha256_sum0 = dis(gen); \
    top->op_ssha256_sum1 = dis(gen);

#define ADD_ROW_TO_CSV() \
    outputFile << hammingWeight(top->rs1) << std::endl;
