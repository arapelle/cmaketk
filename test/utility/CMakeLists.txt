
include(cmtk/utility)

# cmtk_fatal_ifdef():
cmtk_fatal_ifdef("error" undefined__)

# cmtk_fatal_ifndef():
set(alpha "")
set(beta "")
cmtk_fatal_ifndef("error" alpha beta)

# cmtk_fatal_if_none_is_def():
set(delta "")
cmtk_fatal_if_none_is_def("error" gamma delta)

# cmtk_fatal_if_none_of():
set(epsilon "ONE")
cmtk_fatal_if_none_of(epsilon "THREE" "TWO" "ONE")

# cmtk_set_ifndef():
cmtk_set_ifndef(zeta "1")
cmtk_assert(zeta EQUAL "1")
cmtk_set_ifndef(zeta "2")
cmtk_assert(zeta EQUAL "1")

# cmtk_set_iftest():
cmtk_set_iftest(theta IF ${epsilon} STREQUAL "ONE" THEN "TWO" ELSE "THREE")
cmtk_assert(theta STREQUAL "TWO")
cmtk_set_iftest(theta IF ${epsilon} STREQUAL "FOUR" THEN "TWO" ELSE "THREE")
cmtk_assert(theta STREQUAL "THREE")
set(theta "FIVE")
cmtk_set_iftest(theta IF ${epsilon} STREQUAL "FOUR" THEN "TWO")
cmtk_assert(theta STREQUAL "FIVE")
cmtk_set_iftest(theta IF ${epsilon} STREQUAL "ONE" THEN "TWO")
cmtk_assert(theta STREQUAL "TWO")

# cmtk_list_nth_or_default():
set(fruits "apple" "lemon" "banana")
cmtk_list_nth_or_default(fruits 1 "orange" iota)
cmtk_assert(iota STREQUAL "lemon")
cmtk_list_nth_or_default(fruits 4 "orange" iota)
cmtk_assert(iota STREQUAL "orange")

# cmtk_make_lower_c_identifier():
cmtk_make_lower_c_identifier("!My-str " kappa)
cmtk_assert(kappa STREQUAL "_my_str_")

# cmtk_make_upper_c_identifier():
cmtk_make_upper_c_identifier("!My-str " kappa)
cmtk_assert(kappa STREQUAL "_MY_STR_")
