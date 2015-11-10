# ifndef    FORMULA_MATCH_G
# define    FORMULA_MATCH_G

namespace fml {

    namespace mnl {

        template <typename __I> bool match(__I BI1, __I EI1, __I BI2, __I EI2, const int inx) {
            int cnt = 0;
            while (cnt != inx) ++cnt, ++BI1;
            do if (*BI1 != *BI2) return 0;
            while (++BI1, ++BI2 != EI2);
            return 1;
        };

    };

    template <typename __C> bool match(const __C &C1, const __C &C2, const int inx) {
        return fml::mnl::match(C1.begin(), C1.end(), C2.begin(), C2.end(), inx);
    };

};

# endif  // FORMULA_MATCH_G
