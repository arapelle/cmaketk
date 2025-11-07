set(EXAMPLE_CONFIGURED TRUE PARENT_SCOPE)

# cmtk_add_cpp_library_basic_examples()
cmtk_add_cpp_library_basic_examples(${PROJECT_NAME}
    SOURCES
        tools_example.cpp
)

# cmtk_add_cpp_library_example()
cmtk_add_cpp_library_example(other_tools_example ${PROJECT_NAME}
    SOURCES
        other_tools_example.cpp
)
