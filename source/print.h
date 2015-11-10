# ifndef    FORMULA_PRINT_G
# define    FORMULA_PRINT_G

# include <iostream>

namespace fml {

    namespace mnl {

        template <typename __I> void print(__I BG, __I EN, const char sep = '\n', std::ostream &OS = std::cout) {
            do OS << *BG << sep; while (++BG != EN);
        };

        template <typename __I, typename __F> void print(__I BG, __I EN, const __F &F, const char sep = '\n', std::ostream &OS = std::cout) {
            do OS << F(*BG) << sep; while (++BG != EN);
        };

    };

    template <typename __C> void print(__C &C, const char sep = '\n', std::ostream &OS = std::cout) {
        fml::mnl::print(C.begin(), C.end(), sep, OS);
    };

    template <typename __C, typename __F> void print(__C &C, const __F &F, const char sep = '\n', std::ostream &OS = std::cout) {
        fml::mnl::print(C.begin(), C.end(), F, sep, OS);
    };

};

# endif  // FORMULA_PRINT_G
