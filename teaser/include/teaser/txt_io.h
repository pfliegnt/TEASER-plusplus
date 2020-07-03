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
 * @brief A class for reading TXT files.
 *
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
 * @brief A class for writing txt files.
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
   * @param binary_mode Set to true to write in binary mode
   * @return A status code
   */
  int write(const std::string& file_name, const PointCloud& cloud, bool binary_mode = false);
};

} // namespace teaser
