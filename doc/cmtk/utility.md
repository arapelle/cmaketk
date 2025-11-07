
# Utility

## Include
`find_package(cmaketk COMPONENTS utility)`

## Macros & Functions
### Macro `cmtk_fatal_ifdef(msg ...)`

&ensp;&ensp;&ensp;&ensp;Raise a fatal error if one of the given names is a defined variable. (e.g. `fatal_ifdef("FATAL ERROR!" PROBLEM BOMB)`)

- *msg* :  The error message to display if needed.

### Macro `cmtk_fatal_ifndef(msg ...)`

&ensp;&ensp;&ensp;&ensp;Raise a fatal error if one of the given names is NOT a defined variable. (e.g. `fatal_ifndef("FATAL ERROR!" ID_VAR BUILD_TYPE)`)

- *msg* :  The error message to display if needed.

### Function `cmtk_fatal_if_none_is_def(msg ...)`

&ensp;&ensp;&ensp;&ensp;Raise a fatal error if none of the given names is a defined variable. (e.g. `fatal_if_none_is_def("FATAL ERROR!" PUBLIC PRIVATE)`)

### Function `cmtk_fatal_if_none_is_true(msg ...)`

&ensp;&ensp;&ensp;&ensp;Raise a fatal error if none of the given names is a defined variable with TRUE as value. (e.g. `fatal_if_none_is_true("FATAL ERROR!" OPT_A OPT_B)`)

- *msg* :  The error message to display if needed.

### Function `cmtk_fatal_if_none_of(var_name ...)`

&ensp;&ensp;&ensp;&ensp;Raise a fatal error if var_name is undefined or if its value is none of the given ones. (e.g. `fatal_ifndef("FATAL ERROR!" EXPECTED)`)

- *var_name* :  The name of the variable to test.

### Macro `cmtk_set_ifndef(var_name value)`

&ensp;&ensp;&ensp;&ensp;Set a variable if it is not defined yet.

- *var_name* :  The named of the variable.
- *value* :  The value to give to the variable if it is not defined.

### Macro `cmtk_set_iftest(var_name)`

&ensp;&ensp;&ensp;&ensp;Set a variable according to a test. It the test is `true` a value is set, else another one.

- *var_name* :  The named of the variable.
- IF *test* : The test to evaluate.
- THEN *value* : The value to assign if the test is `true`.
- [ELSE *value*] : The value to assign if the test is `false`.

### Function `cmtk_list_nth_or_default(list_var_name list_var index default_value out_var_name)`

&ensp;&ensp;&ensp;&ensp;Get the nth element of a list or the default value if the list is not long enough.

- *list_var_name* :  The name of the list to treat.
- *index* :  The index of the element we want to get.
- *default_value* :  The default value set to the output variable if the list is not long enough.
- *out_var_name* :  The name of the output variable.

### Macro `cmtk_make_lower_c_identifier(str return_var)`

&ensp;&ensp;&ensp;&ensp;Convert a string to a C identifier in lower case.

- *str*: The string to convert.
- *return_var* :  Variable in the calling scope containing the generated string.

### Macro `cmtk_make_upper_c_identifier(str return_var)`

&ensp;&ensp;&ensp;&ensp;Convert a string to a C identifier in upper case.

- *str*: The string to convert.
- *return_var* :  Variable in the calling scope containing the generated string.

### Macro `cmtk_assert(...)`

&ensp;&ensp;&ensp;&ensp;Test an assertion passed as arguments, and raise a fatal error if the test failed. (e.g. `cmtk_assert(IVAR EQUAL 42)`)
