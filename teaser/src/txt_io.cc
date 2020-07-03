/**
 * Copyright 2020, Massachusetts Institute of Technology,
 * Cambridge, MA 02139
 * All Rights Reserved
 * Authors: Jingnan Shi, et al. (see THANKS for the full author list)
 * See LICENSE for the license information
 */

#include <sstream>
#include <fstream>
#include <iostream>
#include <memory>
#include <cstring>
#include <string>

#include "teaser/txt_io.h"

// Internal datatypes for storing ply vertices
struct float3 {
  float x, y, z;
};
struct double3 {
  double x, y, z;
};

int teaser::TXTReader::read(const std::string& file_name, teaser::PointCloud& cloud) {
  auto file_stream = std::make_unique<std::ifstream>();
  file_stream->open(file_name);
  if(!file_stream->is_open())
  {
    std::cerr << "Failed to open " << file_name << std::endl;
    return -1;
  }

  try
  {
    // read the file line by line
    std::string line;
    while(std::getline(*file_stream, line))
    {
      std::istringstream linestream( line );
      std::array<std::string,3> token;
      
      // read  tokens
      linestream >> token[0] >> token[1] >> token[2];
      teaser::PointXYZ point = {
        std::stof(token[0]),
        std::stof(token[1]),
        std::stof(token[2])
      };

      // add the point
      cloud.push_back(point);

      // just ignore the rest
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << "Failed to read: ";
    std::cerr << e.what() << '\n';
    return -1;
  }
  
  return 0;
}

int teaser::TXTWriter::write(const std::string& file_name, const teaser::PointCloud& cloud) 
{
  auto fileStream = std::make_unique<std::ofstream>();
  fileStream->open(file_name);
  if(!fileStream->is_open())
  {
    std::cerr << "Failed to write to " << file_name << std::endl;
    return -1;
  }
  try
  {
    for(const auto& pt : cloud)
    {
      *fileStream << std::to_string(pt.x) << ' ';
      *fileStream << std::to_string(pt.y) << ' ';
      *fileStream << std::to_string(pt.z) << std::endl;
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << "Failed to write to file: ";
    std::cerr << e.what() << '\n';
    return -1;
  }
  
  return 0;
}
