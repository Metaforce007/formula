// add -double- support


# ifndef    FORMULA_2INTEGER_G
# define    FORMULA_2INTEGER_G

# include   <string>

namespace fml {

    long long to_integer(const std::string &data) {
        if (!data[1]) return data[0] - 48;
        bool neg = data[0] == '-';
        if (neg && !data[2]) return -(data[1] - 48);
        long long hold, res = 0;
        int index = 0;
        for (int i = neg, len = data.size(); i < len; i++) {
            index = i;
            hold = data[i] - 48;
            while (data[++index]) hold *= 10;
            res += hold;
        }
        return neg ? -res : res;
    };

};

# endif  // FORMULA_2INTEGER_G
