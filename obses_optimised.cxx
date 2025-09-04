
make_expression_observable("B_s->phill::M_1s(q2)@LHCb", R"(M_{1s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::H_1s(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::M_1s@LHCb", R"(M_{1s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::H_1s@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::M_1c(q2)@LHCb", R"(M_{1c}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::H_1c(q2)@LHCb>> / (<<B_s->phill::K_2c(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::M_1c@LHCb", R"(M_{1c}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::H_1c@LHCb>> / (<<B_s->phill::K_2c@LHCb>>) )"),


make_expression_observable("B_s->phill::M_2s(q2)@LHCb", R"(M_{2s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::H_2s(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::M_2s@LHCb", R"(M_{2s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::H_2s@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::M_2c(q2)@LHCb", R"(M_{2c}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::H_2c(q2)@LHCb>> / (<<B_s->phill::K_2c(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::M_2c@LHCb", R"(M_{2c}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::H_2c@LHCb>> / (<<B_s->phill::K_2c@LHCb>>) )"),


make_expression_observable("B_s->phill::M_3(q2)@LHCb", R"(M_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::H_3(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::M_3@LHCb", R"(M_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::H_3@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::M_4(q2)@LHCb", R"(M_{4}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::H_4(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * (2.0 * <<B_s->phill::K_2s(q2)@LHCb>> - <<B_s->phill::K_3(q2)@LHCb>>) ) ^ 0.5) )"),
make_expression_observable("B_s->phill::M_4@LHCb", R"(M_{4}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::H_4@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5) )"),


make_expression_observable("B_s->phill::M_5(q2)@LHCb", R"(M_{5}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::H_5(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * (2.0 * <<B_s->phill::K_2s(q2)@LHCb>> - <<B_s->phill::K_3(q2)@LHCb>>) ) ^ 0.5) )"),
make_expression_observable("B_s->phill::M_5@LHCb", R"(M_{5}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::H_5@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5) )"),


make_expression_observable("B_s->phill::M_6s(q2)@LHCb", R"(M_{6s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::H_6s(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::M_6s@LHCb", R"(M_{6s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::H_6s@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::M_7(q2)@LHCb", R"(M_{7}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::H_7(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * (2.0 * <<B_s->phill::K_2s(q2)@LHCb>> - <<B_s->phill::K_3(q2)@LHCb>>) ) ^ 0.5) )"),
make_expression_observable("B_s->phill::M_7@LHCb", R"(M_{7}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::H_7@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5) )"),


make_expression_observable("B_s->phill::M_8(q2)@LHCb", R"(M_{8}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(1.0/(2.0^(0.5)) * <<B_s->phill::H_8(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * (2.0 * <<B_s->phill::K_2s(q2)@LHCb>> - <<B_s->phill::K_3(q2)@LHCb>>) ) ^ 0.5) )"),
make_expression_observable("B_s->phill::M_8@LHCb", R"(M_{8}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(1.0/(2.0^(0.5)) * <<B_s->phill::H_8@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5) )"),


make_expression_observable("B_s->phill::M_9(q2)@LHCb", R"(M_{9}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::H_9(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::M_9@LHCb", R"(M_{9}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::H_9@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::Q_1s(q2)@LHCb", R"(Q_{1s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_1s(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::Q_1s@LHCb", R"(Q_{1s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_1s@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::Q_1c(q2)@LHCb", R"(Q_{1c}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::Z_1c(q2)@LHCb>> / (<<B_s->phill::K_2c(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::Q_1c@LHCb", R"(Q_{1c}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::Z_1c@LHCb>> / (<<B_s->phill::K_2c@LHCb>>) )"),


make_expression_observable("B_s->phill::Q_2s(q2)@LHCb", R"(Q_{2s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_2s(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::Q_2s@LHCb", R"(Q_{2s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_2s@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::Q_2c(q2)@LHCb", R"(Q_{2c}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::Z_2c(q2)@LHCb>> / (<<B_s->phill::K_2c(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::Q_2c@LHCb", R"(Q_{2c}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::Z_2c@LHCb>> / (<<B_s->phill::K_2c@LHCb>>) )"),


make_expression_observable("B_s->phill::Q_3(q2)@LHCb", R"(Q_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::Z_3(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::Q_3@LHCb", R"(Q_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::Z_3@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::Q_4(q2)@LHCb", R"(Q_{4}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::Z_4(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * (2.0 * <<B_s->phill::K_2s(q2)@LHCb>> - <<B_s->phill::K_3(q2)@LHCb>>) ) ^ 0.5) )"),
make_expression_observable("B_s->phill::Q_4@LHCb", R"(Q_{4}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::Z_4@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5) )"),


make_expression_observable("B_s->phill::Q_5(q2)@LHCb", R"(Q_{5}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_5(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * (2.0 * <<B_s->phill::K_2s(q2)@LHCb>> - <<B_s->phill::K_3(q2)@LHCb>>) ) ^ 0.5) )"),
make_expression_observable("B_s->phill::Q_5@LHCb", R"(Q_{5}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_5@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5) )"),


make_expression_observable("B_s->phill::Q_6s(q2)@LHCb", R"(Q_{6s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::Z_6s(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::Q_6s@LHCb", R"(Q_{6s}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::Z_6s@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::Q_7(q2)@LHCb", R"(Q_{7}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::Z_7(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * (2.0 * <<B_s->phill::K_2s(q2)@LHCb>> - <<B_s->phill::K_3(q2)@LHCb>>) ) ^ 0.5) )"),
make_expression_observable("B_s->phill::Q_7@LHCb", R"(Q_{7}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-1.0 * <<B_s->phill::Z_7@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5) )"),


make_expression_observable("B_s->phill::Q_8(q2)@LHCb", R"(Q_{8}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_8(q2)@LHCb>> / ((-2.0 * <<B_s->phill::K_2c(q2)@LHCb>> * (2.0 * <<B_s->phill::K_2s(q2)@LHCb>> - <<B_s->phill::K_3(q2)@LHCb>>) ) ^ 0.5) )"),
make_expression_observable("B_s->phill::Q_8@LHCb", R"(Q_{8}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_8@LHCb>> / ((-2.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5) )"),


make_expression_observable("B_s->phill::Q_9(q2)@LHCb", R"(Q_{9}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::Z_9(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::Q_9@LHCb", R"(Q_{9}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::Z_9@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::SP_1(q2)@LHCb", R"(SP_{1}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::S_3(q2)@LHCb>> / (<<B_s->phill::S_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::SP_1@LHCb", R"(SP_{1}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::S_3@LHCb>> / (<<B_s->phill::S_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::SP_2(q2)@LHCb", R"(SP_{2}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.125 * <<B_s->phill::S_6s(q2)@LHCb>> / (<<B_s->phill::S_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::SP_2@LHCb", R"(SP_{2}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.125 * <<B_s->phill::S_6s@LHCb>> / (<<B_s->phill::S_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::SP_3(q2)@LHCb", R"(SP_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.25 * <<B_s->phill::S_9(q2)@LHCb>> / (<<B_s->phill::S_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::SP_3@LHCb", R"(SP_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.25 * <<B_s->phill::S_9@LHCb>> / (<<B_s->phill::S_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::SP_4p(q2)@LHCb", R"(SP_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::S_4(q2)@LHCb>> / ((-1.0 * <<B_s->phill::S_2c(q2)@LHCb>> * <<B_s->phill::S_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::SP_4p@LHCb", R"(SP_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::S_4@LHCb>> / ((-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::SP_5p(q2)@LHCb", R"(SP_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::S_5(q2)@LHCb>> / ((-1.0 * <<B_s->phill::S_2c(q2)@LHCb>> * <<B_s->phill::S_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::SP_5p@LHCb", R"(SP_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::S_5@LHCb>> / ((-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::SP_6p(q2)@LHCb", R"(SP_{6p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::S_7(q2)@LHCb>> / ((-1.0 * <<B_s->phill::S_2c(q2)@LHCb>> * <<B_s->phill::S_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::SP_6p@LHCb", R"(SP_{6p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::S_7@LHCb>> / ((-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::SP_8p(q2)@LHCb", R"(SP_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::S_8(q2)@LHCb>> / ((-1.0 * <<B_s->phill::S_2c(q2)@LHCb>> * <<B_s->phill::S_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::SP_8p@LHCb", R"(SP_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::S_8@LHCb>> / ((-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::AP_1(q2)@LHCb", R"(AP_{1}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::A_3(q2)@LHCb>> / (<<B_s->phill::S_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::AP_1@LHCb", R"(AP_{1}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::A_3@LHCb>> / (<<B_s->phill::S_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::AP_2(q2)@LHCb", R"(AP_{2}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.125 * <<B_s->phill::A_6s(q2)@LHCb>> / (<<B_s->phill::S_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::AP_2@LHCb", R"(AP_{2}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.125 * <<B_s->phill::A_6s@LHCb>> / (<<B_s->phill::S_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::AP_3(q2)@LHCb", R"(AP_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.25 * <<B_s->phill::A_9(q2)@LHCb>> / (<<B_s->phill::S_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::AP_3@LHCb", R"(AP_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.25 * <<B_s->phill::A_9@LHCb>> / (<<B_s->phill::S_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::AP_4p(q2)@LHCb", R"(AP_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::A_4(q2)@LHCb>> / ((-1.0 * <<B_s->phill::S_2c(q2)@LHCb>> * <<B_s->phill::S_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::AP_4p@LHCb", R"(AP_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::A_4@LHCb>> / ((-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::AP_5p(q2)@LHCb", R"(AP_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::A_5(q2)@LHCb>> / ((-1.0 * <<B_s->phill::S_2c(q2)@LHCb>> * <<B_s->phill::S_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::AP_5p@LHCb", R"(AP_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::A_5@LHCb>> / ((-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::AP_6p(q2)@LHCb", R"(AP_{6p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::A_7(q2)@LHCb>> / ((-1.0 * <<B_s->phill::S_2c(q2)@LHCb>> * <<B_s->phill::S_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::AP_6p@LHCb", R"(AP_{6p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::A_7@LHCb>> / ((-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::AP_8p(q2)@LHCb", R"(AP_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::A_8(q2)@LHCb>> / ((-1.0 * <<B_s->phill::S_2c(q2)@LHCb>> * <<B_s->phill::S_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::AP_8p@LHCb", R"(AP_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::A_8@LHCb>> / ((-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::KP_1(q2)@LHCb", R"(KP_{1}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::K_3(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::KP_1@LHCb", R"(KP_{1}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::K_3@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::KP_2(q2)@LHCb", R"(KP_{2}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.125 * <<B_s->phill::K_6s(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::KP_2@LHCb", R"(KP_{2}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.125 * <<B_s->phill::K_6s@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::KP_3(q2)@LHCb", R"(KP_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.25 * <<B_s->phill::K_9(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::KP_3@LHCb", R"(KP_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.25 * <<B_s->phill::K_9@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::KP_4p(q2)@LHCb", R"(KP_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::K_4(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::KP_4p@LHCb", R"(KP_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::K_4@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::KP_5p(q2)@LHCb", R"(KP_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::K_5(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::KP_5p@LHCb", R"(KP_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::K_5@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::KP_6p(q2)@LHCb", R"(KP_{6p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::K_7(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::KP_6p@LHCb", R"(KP_{6p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::K_7@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::KP_8p(q2)@LHCb", R"(KP_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::K_8(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::KP_8p@LHCb", R"(KP_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::K_8@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::WP_1(q2)@LHCb", R"(WP_{1}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::W_3(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::WP_1@LHCb", R"(WP_{1}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::W_3@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::WP_2(q2)@LHCb", R"(WP_{2}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.125 * <<B_s->phill::W_6s(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::WP_2@LHCb", R"(WP_{2}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.125 * <<B_s->phill::W_6s@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::WP_3(q2)@LHCb", R"(WP_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.25 * <<B_s->phill::W_9(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::WP_3@LHCb", R"(WP_{3}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.25 * <<B_s->phill::W_9@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::WP_4p(q2)@LHCb", R"(WP_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::W_4(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::WP_4p@LHCb", R"(WP_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::W_4@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::WP_5p(q2)@LHCb", R"(WP_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::W_5(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::WP_5p@LHCb", R"(WP_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::W_5@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::WP_6p(q2)@LHCb", R"(WP_{6p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::W_7(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::WP_6p@LHCb", R"(WP_{6p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::W_7@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::WP_8p(q2)@LHCb", R"(WP_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::W_8(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::WP_8p@LHCb", R"(WP_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::W_8@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::M_4p(q2)@LHCb", R"(M_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::H_4(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::M_4p@LHCb", R"(M_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::H_4@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::M_5p(q2)@LHCb", R"(M_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::H_5(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::M_5p@LHCb", R"(M_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::H_5@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::M_7p(q2)@LHCb", R"(M_{7p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::H_7(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::M_7p@LHCb", R"(M_{7p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::H_7@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::M_8p(q2)@LHCb", R"(M_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::H_8(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::M_8p@LHCb", R"(M_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::H_8@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::Q_4p(q2)@LHCb", R"(Q_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_4(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::Q_4p@LHCb", R"(Q_{4p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_4@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::Q_5p(q2)@LHCb", R"(Q_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::Z_5(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::Q_5p@LHCb", R"(Q_{5p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(0.5 * <<B_s->phill::Z_5@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::Q_7p(q2)@LHCb", R"(Q_{7p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::Z_7(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::Q_7p@LHCb", R"(Q_{7p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(-0.5 * <<B_s->phill::Z_7@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::Q_8p(q2)@LHCb", R"(Q_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_8(q2)@LHCb>> / ((-1.0 * <<B_s->phill::K_2c(q2)@LHCb>> * <<B_s->phill::K_2s(q2)@LHCb>>) ^ 0.5) )"),
make_expression_observable("B_s->phill::Q_8p@LHCb", R"(Q_{8p}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::Z_8@LHCb>> / ((-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5) )"),


make_expression_observable("B_s->phill::SS(q2)@LHCb", R"(SS{}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::S_6c(q2)@LHCb>> / (<<B_s->phill::S_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::SS@LHCb", R"(SS{}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::S_6c@LHCb>> / (<<B_s->phill::S_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::KS(q2)@LHCb", R"(KS{}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::K_6c(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::KS@LHCb", R"(KS{}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::K_6c@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::WS(q2)@LHCb", R"(WS{}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::W_6c(q2)@LHCb>> / (<<B_s->phill::K_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::WS@LHCb", R"(WS{}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::W_6c@LHCb>> / (<<B_s->phill::K_2s@LHCb>>) )"),


make_expression_observable("B_s->phill::AS(q2)@LHCb", R"(AS{}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::A_6c(q2)@LHCb>> / (<<B_s->phill::S_2s(q2)@LHCb>>) )"),
make_expression_observable("B_s->phill::AS@LHCb", R"(AS{}(\bar{B}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "(<<B_s->phill::A_6c@LHCb>> / (<<B_s->phill::S_2s@LHCb>>) )"),

