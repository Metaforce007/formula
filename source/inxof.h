# ifndef    FORMULA_INXOF_G
# define    FORMULA_INXOF_G

# include   <string>
# include   "match.h"

namespace fml {

    namespace mnl {

        template<typename __I, typename __T>
        int inxof(__I BG, __I EN, const __T &T) {
            int inx = 0;
            do
                if (*BG == T) return inx;
                else ++inx;
            while (++BG != EN);
            return -1;
        };

        template<typename __I, typename __F, typename __T>
        int inxof(__I BG, __I EN, const __F &F, const __T &T) {
            int inx = 0;
            do
                if (F(*BG, T)) return inx;
                else ++inx;
            while (++BG != EN);
            return -1;
        };

    };

    template<typename __C, typename __T>
    int inxof(__C &C, const __T &T) {
        return fml::mnl::inxof(C.begin(), C.end(), T);
    };

    template<typename __C, typename __F, typename __T>
    int inxof(__C &C, const __F &F, const __T &T) {
        return fml::mnl::inxof(C.begin(), C.end(), F, T);
    };

    int inxof(const std::string &data, const std::string &S) {
        if (S.size() == 1) return fml::mnl::inxof(data.begin(), data.end(), S[0]);
        for (int i = 0, len = data.size(); i < len; i++)
            if (fml::match(data, S, i))
                return i;
        return -1;
    };

};

# endif  // FORMULA_INXOF_G
