# ifndef    FORMULA_HOLD_G
# define    FORMULA_HOLD_G

# include   "match.h"

namespace fml {

    namespace mnl {

        template<typename __I, typename __T>
        bool hold(__I BG, __I EN, const __T &T) {
            do if (*BG == T) return 1;
            while (++BG != EN);
            return 0;
        };

        template<typename __I, typename __F, typename __T>
        bool hold(__I BG, __I EN, const __F &F, const __T &T) {
            do if (F(*BG, T)) return 1;
            while (++BG != EN);
            return 0;
        };

    };

    template<typename __C, typename __T>
    bool hold(const __C &C, const __T &T) {
        return fml::mnl::hold(C.begin(), C.end(), T);
    };

    template<typename __C, typename __T, typename... ___T>
    bool hold(const __C &C, const __T &T, const ___T &... _T) {
        return fml::mnl::hold(C.begin(), C.end(), T) && fml::hold(C, _T...);
    };

    template<typename __C, typename __F, typename __T>
    bool hold(const __C &C, const __F &F, const __T &T) {
        return fml::mnl::hold(C.begin(), C.end(), T);
    };

    template<typename __C, typename __F, typename __T, typename... ___T>
    bool hold(const __C &C, const __F &F, const __T &T, const ___T &... _T) {
        return fml::mnl::hold(C.begin(), C.end(), T) && fml::hold(C, _T...);
    };

    template<typename __C, typename __T>
    bool hold(const __C &C, const __T &T1, const __T &T2) {
        return fml::mnl::hold(C.begin(), C.end(), T1) && fml::mnl::hold(C.begin(), C.end(), T2);
    };

    template<typename __C, typename __T, typename... ___T>
    bool hold(const __C &C, const __T &T1, const __T &T2, const ___T &... _T) {
        return fml::mnl::hold(C.begin(), C.end(), T1) && fml::mnl::hold(C.begin(), C.end(), T2) && fml::hold(C, _T...);
    };

    bool hold(const std::string &data, const std::string &sub) {
        if (sub.size() == 1) return fml::mnl::hold(data.begin(), data.end(), sub[0]);
        for (int i = 0, len = data.size(); i < len; i++)
            if (fml::match(data, sub, i))
                return 1;
        return 0;
    };

};

# endif  // FORMULA_HOLD_G
