# ifndef    FORMULA_PURGE__GUARD
# define    FORMULA_PURGE__GUARD

# include   "pop.h"

namespace fml {

    namespace mnl {
    
    		// CLASSIFIED //
    
        };
        
    // CLASSIFIED //

};

# endif

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
