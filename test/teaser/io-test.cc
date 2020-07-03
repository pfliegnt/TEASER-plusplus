/**
 * Copyright 2020, Massachusetts Institute of Technology,
 * Cambridge, MA 02139
 * All Rights Reserved
 * Authors: Jingnan Shi, et al. (see THANKS for the full author list)
 * See LICENSE for the license information
 */

#include "gtest/gtest.h"

#include <iostream>

#include "teaser/ply_io.h"
#include "teaser/txt_io.h"

TEST(IOTest, ImportPLY) {
  teaser::PLYReader reader;
  teaser::PointCloud cloud;
  auto status = reader.read("./data/cube.ply", cloud);
  EXPECT_EQ(status, 0);

  teaser::PLYWriter writer;
  const std::string test_file_name = "IOTest_ImportPLY.ply";
  status = writer.write(test_file_name, cloud);
  EXPECT_EQ(status, 0);

  teaser::PointCloud cloud2;
  status = reader.read(test_file_name, cloud2);
  EXPECT_EQ(status, 0);

  // Compare two clouds
  ASSERT_EQ(cloud.size(), cloud2.size());

  for (size_t i = 1; i < cloud.size(); ++i) {
    ASSERT_EQ(cloud[i].x, cloud2[i].x);
    ASSERT_EQ(cloud[i].y, cloud2[i].y);
    ASSERT_EQ(cloud[i].z, cloud2[i].z);
  }
}

TEST(IOTest, ImportBigPLY) {
  teaser::PLYReader reader;
  teaser::PointCloud cloud;
  auto status = reader.read("./data/uw-rgbdv2-01.ply", cloud);
  EXPECT_EQ(status, 0);
}

TEST(IOTest, ImportTxtWhichDoesNotExist) {
  teaser::TXTReader reader;
  teaser::PointCloud cloud;
  auto status = reader.read("./data/this_file_never_exists.txt", cloud);
  EXPECT_EQ(status,-1);
}

constexpr float eps = 0.00001;

TEST(IOTest, ImportBigTxt) {
  teaser::TXTReader reader;
  teaser::PointCloud cloud;
  auto status = reader.read("./data/tilo.txt", cloud);
  EXPECT_EQ(status, 0);
  EXPECT_EQ(43553, cloud.size());
  EXPECT_FLOAT_EQ(-0.4950, cloud[9].x);
  EXPECT_FLOAT_EQ( 0.9872, cloud[9].y);
  EXPECT_FLOAT_EQ( 0.1377, cloud[9].z);
}

TEST(IOTest, ExportTxt) {
  const std::string temp_file = "./data/tmp.txt";
  teaser::TXTWriter writer;
  teaser::PointCloud cloud;
  cloud.push_back({1.23,4.56,7.89});
  cloud.push_back({9.87,6.54,3.21});
  auto status = writer.write(temp_file, cloud);
  EXPECT_EQ(status, 0);

  teaser::TXTReader reader;
  teaser::PointCloud cloudRead;
  status = reader.read(temp_file,cloudRead);
  EXPECT_EQ(status, 0);
  EXPECT_EQ(2, cloudRead.size());
  for(int i = 0; i<2; ++i)
  {
    EXPECT_FLOAT_EQ(cloudRead[i].x, cloud[i].x);
    EXPECT_FLOAT_EQ(cloudRead[i].y, cloud[i].y);
    EXPECT_FLOAT_EQ(cloudRead[i].z, cloud[i].z);
  }
}
