# ifndef    FORMULA_CHOP_G
# define    FORMULA_CHOP_G

# include   "pop.h"

namespace fml {

    namespace mnl {

        ////////////////
        // CLASSIFIED //
        ////////////////

        template<typename __I, typename __T>
        void sub_chop(__I BI, __I EI, const __T &T, int &replaced);

        template<typename __I>
        int chop(__I BI, __I EI, int beg, int end);

        /*template <typename __C> void __pop__(__C &C, int N) {
            while (N--) C.pop_back();
        };*/

        /* C++ < 11
        # include <string>
        void __pop__(std::string &C, int N) {
            std::string nC = ""; int rt = C.size() - N;
            for (int i = 0; i < rt; i++) nC += C[i];
            C = nC;
        };*/

    };

    template<typename __C>
    void chop(__C &C, int beg, int end) {
        fml::mnl::__pop__(C, fml::mnl::chop(C.begin(), C.end(), beg, end));
    };

};

# endif  // FORMULA_CHOP_G
