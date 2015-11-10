# ifndef    FORMULA_COUNT_G
# define    FORMULA_COUNT_G

# include   <string>
# include   "match.h"

namespace fml {

    namespace mnl {

        template<typename __I, typename __T>
        int count(__I BG, __I EN, const __T &T) {
            int cnt = 0;
            do if (*BG == T) ++cnt;
            while (++BG != EN);
            return cnt;
        };

        template<typename __I, typename __F, typename __T>
        int count(__I BG, __I EN, const __F &F, const __T &T) {
            int cnt = 0;
            do if (F(*BG, T)) ++cnt;
            while (++BG != EN);
            return cnt;
        };

    };

    template<typename __C, typename __T>
    int count(const __C &C, const __T &T) {
        return fml::mnl::count(C.begin(), C.end(), T);
    };

    template<typename __C, typename __T, typename... ___T>
    int count(const __C &C, const __T &T, const ___T &... _T) {
        return fml::mnl::count(C.begin(), C.end(), T) + fml::count(C, _T...);
    };

    template<typename __C, typename __F, typename __T>
    int count(const __C &C, const __F &F, const __T &T) {
        return fml::mnl::count(C.begin(), C.end(), F, T);
    };

    template<typename __C, typename __F, typename __T, typename... ___T>
    int count(const __C &C, const __F &F, const __T &T, const ___T &... _T) {
        return fml::mnl::count(C.begin(), C.end(), F, T) + fml::count(C, F, _T...);
    };

    int count(const std::string &data, const std::string &sub) {
        if (sub.size() == 1) return fml::mnl::count(data.begin(), data.end(), sub[0]);
        int cnt = 0;
        for (int i = 0, len = data.size(); i < len; i++)
            if (fml::match(data, sub, i)) ++cnt;
        return cnt;
    };

};

# endif //  FORMULA_COUNT_G
