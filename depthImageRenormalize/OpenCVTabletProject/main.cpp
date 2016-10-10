#include "include\opencv\cv.h"
#include "include\opencv\highgui.h"


cv::Mat adjustDepth(const cv::Mat& inImage)
{
	// from https://orbbec3d.com/product-astra/
	// Astra S has a depth in the range 0.35m to 2.5m
	int maxDepth = 2500; 
	int minDepth = 350; // in mm

	cv::Mat retImage = inImage;

	for(int j = 0; j < retImage.rows; j++)
		for(int i = 0; i < retImage.cols; i++)
		{
			if(retImage.at<ushort>(j, i))
				retImage.at<ushort>(j, i) = maxDepth - (retImage.at<ushort>(j, i) - minDepth);
		}

		return retImage;
}


int main ()
{
	cv::Mat inImage;
	inImage = cv::imread("testImage.png", CV_LOAD_IMAGE_UNCHANGED);

	cv::Mat adjustedDepth = adjustDepth(inImage);
	cv::Mat dispImage;
	adjustedDepth.convertTo(dispImage, CV_8UC1, 255.0f/2500.0f);
	cv::imshow(" ", dispImage);

	//cv::imwrite("testImageAdjusted.png", adjustedDepth);
	//cv::imwrite("savedImage.png", dispImage);

	cv::waitKey(0);
	return 0;
}
