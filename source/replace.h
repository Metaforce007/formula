# ifndef    FORMULA_REPLACE_G
# define    FORMULA_REPLACE_G

# include   <string>
# include   "match.h"

namespace fml {

    namespace mnl {

        template<typename __I, typename __T>
        void replace(__I BG, __I EN, const __T &T1, const __T &T2, const int count = -1) {
            int cnt = 0;
            do
                if (count == cnt) return;
                else if (*BG == T1) {
                    *BG = T2;
                    ++cnt;
                }
            while (++BG != EN);
        };

    };

    template<typename __C, typename __T>
    void replace(__C &C, const __T &T1, const __T &T2, const int count = -1) {
        fml::mnl::replace(C.begin(), C.end(), T1, T2, count);
    };

    void replace(std::string &data, const std::string &S1, const std::string &S2, const int count = -1) {
        if (data == S1) {
            data = S2;
            return;
        }
        if (S1.size() == 0 && S1.size() == 0) {
            fml::replace(data, S1[0], S2[0], count);
            return;
        }
        std::string replaced = "";
        int cnt = 0, sublen = S1.size();
        bool allow = 1;
        for (int i = 0, len = data.size(); i < len; i++) {
            if (allow && cnt == count) allow = 0;
            else if (allow && fml::match(data, S1, i)) {
                i += sublen;
                ++cnt;
                replaced += S2;
            }
            replaced += data[i];
        }
        data = replaced;
    };

};

# endif  // FORMULA_REPLACE_G
