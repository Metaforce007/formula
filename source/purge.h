// Task list
//      Try to pass the element/s by reference for reduced memory usage
//      Try to add a purge count feature
//      Add to multiple containers purge, an function equal(==) support
//      Rewrite instructions (at the bottom of this page)
//      Implement purge(std::string, std::string...)

# ifndef    FORMULA_PURGE_G
# define    FORMULA_PURGE_G

# include   "pop.h"

namespace fml {

    namespace mnl {

        ////////////////
        // CLASSIFIED //
        ////////////////

        template<typename __I, typename __T1, typename __T2>
        void trade(__I BI, __I EI, const __T1 &T1, const __T2 &T2);

        template<typename __I, typename __T>
        int purge(__I BI, __I EI, const __T T);

        template<typename __I, typename __F, typename __T1, typename __T2>
        void trade(__I BI, __I EI, const __F &F, const __T1 &T1, const __T2 &T2);

        template<typename __I, typename __F, typename __T>
        int purge(__I BI, __I EI, const __F &F, const __T T);

        template<typename __C, typename __T>
        int purge(__C &C, const __T T) {
            return fml::mnl::purge(C.begin(), C.end(), T);
        };

        template<typename __C, typename __T, typename... ___T>
        int purge(__C &C, const __T T, const ___T... _T) {
            return fml::mnl::purge(C.begin(), C.end(), T) + fml::mnl::purge(C, _T...);
        };

        template<typename __C, typename __F, typename __T>
        int purge(__C &C, const __F &F, const __T T) {
            return fml::mnl::purge(C.begin(), C.end(), F, T);
        };

        template<typename __C, typename __F, typename __T, typename... ___T>
        int purge(__C &C, const __F &F, const __T T, const ___T... _T) {
            return fml::mnl::purge(C.begin(), C.end(), F, T) + fml::mnl::purge(C, F, _T...);
        };

        template<typename __C, typename __T>
        int purge(__C &C, const __T T1, const __T T2) {
            return fml::mnl::purge(C.begin(), C.end(), T1) + fml::mnl::purge(C.begin(), C.end(), T2);
        };

        template<typename __C, typename __T, typename... ___T>
        int purge(__C &C, const __T T1, const __T T2, const ___T... _T) {
            return fml::mnl::purge(C.begin(), C.end(), T1) + fml::mnl::purge(C.begin(), C.end(), T2) +
                   fml::mnl::purge(C, _T...);   //
        };

        template<typename __T, typename __C>
        int purge(const __T T, __C &C) {
            return fml::mnl::purge(C.begin(), C.end(), T);
        };

        template<typename __T, typename __C, typename... ___C>
        int purge(const __T T, __C &C, ___C &... _C) {
            return fml::mnl::purge(C.begin(), C.end(), T) + fml::mnl::purge<__T, __C>(T, _C...);
        };

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

    template<typename __C, typename __T>
    void purge(__C &C, const __T T) {
        fml::mnl::__pop__(C, fml::mnl::purge(C.begin(), C.end(), T));
    };

    template<typename __C, typename __T, typename... ___T>
    void purge(__C &C, const __T T, const ___T... _T) {
        fml::mnl::__pop__(C, fml::mnl::purge(C.begin(), C.end(), T) + fml::mnl::purge(C, _T...));
    };

    template<typename __C, typename __F, typename __T>
    void purge(__C &C, const __F &F, const __T T) {
        fml::mnl::__pop__(C, fml::mnl::purge(C.begin(), C.end(), F, T));
    };

    template<typename __C, typename __F, typename __T, typename... ___T>
    void purge(__C &C, const __F &F, const __T T, const ___T... _T) {
        fml::mnl::__pop__(C, fml::mnl::purge(C.begin(), C.end(), F, T) + fml::mnl::purge(C, F, _T...));
    };

    template<typename __C, typename __T>
    void purge(__C &C, const __T T1, const __T T2) {
        fml::mnl::__pop__(C, fml::mnl::purge(C.begin(), C.end(), T1) + fml::mnl::purge(C.begin(), C.end(), T2));
    };

    template<typename __C, typename __T, typename... ___T>
    void purge(__C &C, const __T T1, const __T T2, const ___T... _T) {
        fml::mnl::__pop__(C, fml::mnl::purge(C.begin(), C.end(), T1) + fml::mnl::purge(C.begin(), C.end(), T2) +
                             fml::mnl::purge<__C, __T>(C, _T...));
    };

    template<typename __T, typename __C>
    void purge(const __T T, __C &C) {
        fml::mnl::__pop__(C, fml::mnl::purge(C.begin(), C.end(), T));
    };

    template<typename __T, typename __C, typename... ___C>
    void purge(const __T T, __C &C, ___C &... _C) {
        fml::mnl::__pop__(C, fml::mnl::purge(C.begin(), C.end(), T));
        fml::purge<__T, __C>(T, _C...);
    };

    // template <typename __T, typename __F, typename __C> void purge(const __T T, const __F &F, __C &C);

    // template <typename __T, typename __F, typename __C, typename... ___C> void purge(const __T T, const __F &F, __C &C, ___C&... _C);

};

# endif  // FORMULA_PURGE_G

/*
 *  purpose: removing element(s) from any container,
 *  using default equal(==) operator or user defined equal(==) function
 *
 *  1# usage: using default equal(==) operator
 *  fml::purge( [MUST] container,
 *              [MUST] element,
 *              [OPTIONAL] more elements )
 *
 *  2# usage: using user defined equal(==) function
 *  fml::purge( [MUST] container,
 *              [MUST] equal(==) function,
 *              [MUST] element,
 *              [OPTIONAL] more elements )
 *
 *  of course, if the element type already have an equal(==) operator defined in its class,
 *  it'll work with both usages.
 *  please define your equal(==) operator const:    operator==(const object) const
 *
 *  examples:
 *
 *
 *  1# example: using default equal(==) operator
 *
 *  std::vector<int> nums = {1, 2, 3, 1, 2, 3};
 *
 *  fml::purge(nums, 1);    nums now looks like this     {2, 3, 2, 3}
 *  fml::purge(nums, 1, 3); nums now looks like this     {2, 2}
 *
 *
 *  2# example: using user defined equal(==) function
 *
 *  struct object { int id = 0; }
 *
 *  object obj1; obj1.id = 1;
 *  object obj2; obj2.id = 2;
 *  object obj3; obj3.id = 3;
 *
 *  std::vector<object> objects = {obj1, obj2, obj3};
 *
 *
 *  fml::purge( objects,
 *              [] (object obj_1, object obj_2) -> bool { return obj_1.id == obj_2.id;},
 *              obj1);
 *  objects now looks like this      {obj2, obj3}
 *
 *  fml::purge( objects,
 *              [] (object obj_1, object obj_2) -> bool { return obj_1.id == obj_2.id;},
 *              obj1, obj3);
 *  objects now looks like this      {obj2}
 *
 */
