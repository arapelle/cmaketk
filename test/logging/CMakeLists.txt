include(cmtk/logging)

# cmtk_set_logging_level_ifndef() BUILD_TYPE "Debug"
cmtk_set_logging_level_ifndef(debug_logging_level BUILD_TYPE "Debug")
cmtk_assert(debug_logging_level STREQUAL "DEBUG")

# cmtk_set_logging_level_ifndef() BUILD_TYPE "Release"
cmtk_set_logging_level_ifndef(release_logging_level BUILD_TYPE "Release")
cmtk_assert(release_logging_level STREQUAL "INFO")

# cmtk_set_logging_level_ifndef() BUILD_TYPE "???"
cmtk_set_logging_level_ifndef(unknown_logging_level BUILD_TYPE "???")
cmtk_assert(unknown_logging_level STREQUAL "TRACE")
