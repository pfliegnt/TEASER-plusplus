cmake_minimum_required(VERSION 3.10)
project(teaser_cpp_txt)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 REQUIRED)
find_package(teaserpp REQUIRED)

# Change this line to include your own executable file
add_executable(teaser_cpp_txt teaser_cpp_txt.cc)

# Link to teaserpp & Eigen3
target_link_libraries(teaser_cpp_txt Eigen3::Eigen teaserpp::teaser_registration teaserpp::teaser_io)

# Copy the data files to build directory
file(COPY ../example_data/
        DESTINATION ./example_data/
        FILES_MATCHING
        PATTERN *.txt)
