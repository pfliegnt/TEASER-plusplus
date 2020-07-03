/**
 * Copyright 2020, Massachusetts Institute of Technology,
 * Cambridge, MA 02139
 * All Rights Reserved
 * Authors: Jingnan Shi, et al. (see THANKS for the full author list)
 * See LICENSE for the license information
 */

#pragma once

#include "teaser/geometry.h"

namespace teaser {

/**
 * @brief A very simple TXT reader
 * it expects a text file with point coordinates line by line
 * 3 coordinates, separated by white space required, rest (rgb, intensity) is being ignored
 * Example:
 * 1.23 4.56 7.89
 * 9.87 6.54 3.21
 */
class TXTReader {
public:
  /**
   * @brief Default constructor
   */
  TXTReader() {}

  /**
   * @brief A wrapper function for reading txt files into PointCloud
   */
  int read(const std::string& file_name, PointCloud& cloud);
};

/**
 * @brief A very simple txt writer
 * writes the point cloud line by line.
 * Example output:
 * 1.23 4.56 7.89
 * 9.87 6.54 3.21
 */
class TXTWriter {
public:
  /**
   * @brief Default constructor
   */
  TXTWriter() {}

  /**
   * @brief Write point cloud to txt files
   * @param file_name
   * @param cloud
   * @return A status code
   */
  int write(const std::string& file_name, const PointCloud& cloud);
};

} // namespace teaser
