
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/visualization/cloud_viewer.h>

#include <pcl/segmentation/segment_differences.h>


#include <iostream>

typedef pcl::PointXYZI PointT;


int
main (int argc, char** argv)
{
	pcl::PointCloud<PointT>::Ptr cloud (new pcl::PointCloud<PointT>);
	pcl::PointCloud<PointT>::Ptr seg (new pcl::PointCloud<PointT>);

	pcl::PointCloud<PointT>::Ptr out (new pcl::PointCloud<PointT>);

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

	seg->points[4].z = 10;


	pcl::SegmentDifferences<PointT> seg_diff;

	seg_diff.setTargetCloud(cloud);
	seg_diff.setInputCloud(seg);
	seg_diff.setDistanceThreshold(0.1);


	seg_diff.segment(*out);

	for(size_t i=0 ; i<out->size() ; i++) {
		std::cout << out->points[i].x << " "
			 	  << out->points[i].y << " "
			 	  << out->points[i].z << std::endl;
	}

	cout << "\n\n\n";

	/*
	pcl::SegmentDifferences<PointT> seg_diff2;
	
	seg_diff2.setTargetCloud(seg);
	seg_diff2.setInputCloud(cloud);
	seg_diff2.setDistanceThreshold(0.1);

	seg_diff2.segment(*out);

	for(size_t i=0 ; i<out->size() ; i++) {
		std::cout << out->points[i].x << " "
			 	  << out->points[i].y << " "
			 	  << out->points[i].z << std::endl;
	}
	*/


	return 0;
}
