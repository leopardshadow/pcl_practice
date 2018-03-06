
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <iostream>


int
main (int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr seg (new pcl::PointCloud<pcl::PointXYZ>);

	// Generate pointcloud data
	cloud->width = 10;
	cloud->height = 1;
	cloud->points.resize (cloud->width * cloud->height);

	for (size_t i = 0; i < cloud->points.size (); ++i)
	{
		cloud->points[i].x = i;
		cloud->points[i].y = i;
		cloud->points[i].z = i;
	}



	// Generate segment data
	seg->width = 5;
	seg->height = 1;
	seg->points.resize (seg->width * seg->height);

	for (size_t i = 0; i < seg->points.size (); ++i)
	{
		seg->points[i].x = i;
		seg->points[i].y = i;
		seg->points[i].z = i;
	}
}