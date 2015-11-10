// add -double- support

# ifndef    FORMULA_2STRING_G
# define    FORMULA_2STRING_G

# include   <string>

namespace fml {

    std::string to_string(long long data) {
        std::string res = data < 0 && (data *= -1) ? "-" : "";
        if (data < 10 && data > -10) return res += data + 48;
        long long hold, num2, num1 = data;
        do {
            hold = data, num2 = num1;
            while (num2 /= 10) hold /= 10;
            res += (hold % 10) + 48;
        } while (num1 /= 10);
        return res;
    };

};

# endif  // FORMULA_2STRING_G
