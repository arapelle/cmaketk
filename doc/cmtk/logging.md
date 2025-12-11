
# Logging

## Include
`find_package(cmaketk COMPONENTS logging)`

## Functions
### Function `cmtk_set_logging_level_ifndef(cache_var_name)`

&ensp;&ensp;&ensp;&ensp;Set a cache variable, if not defined yet, for managing logging level.
The value is automatically set accordingly with the build type.

- *cache_var_name* :  The name of the cache variable.
- [BUILD_TYPE *build_type*] :  The build type to take into account to deduce the default logging value. (Value of *CMAKE_BUILD_TYPE* used by default)
- [BUILD_TYPES *build_types*] :  The build types managed to deduce the default logging value. (*Debug;Release* used by default)
- [LEVELS *levels*] :  The logging level values managed to deduce the default logging value. (*Debug;Release* used by default)
- [VALUES *logging_values*] :  The possible values that the logging value can take. (*TRACE;DEBUG;INFO;WARN;ERROR;CRITICAL;OFF* used by default)

Example:
```CMake
cmtk_set_logging_level_ifndef(logging_level)
# logging_level is DEBUG if CMAKE_BUILD_TYPE is Debug.
# logging_level is  INFO if CMAKE_BUILD_TYPE is Release.
```
