# ifndef    FORMULA_VOLUME_G
# define    FORMULA_VOLUME_G

namespace fml {

    namespace mnl {

        template<typename __I>
        int volume(__I BG, __I EN) {
            int cnt = 0;
            do ++cnt; while (++BG != EN);
            return cnt;
        };

    };

    template<typename __C>
    int volume(__C &C) {
        return fml::mnl::volume(C.begin(), C.end());
    };

};

# endif  // FORMULA_VOLUME_G
