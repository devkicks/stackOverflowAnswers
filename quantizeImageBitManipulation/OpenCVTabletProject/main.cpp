#include "include\opencv\cv.h"
#include "include\opencv\highgui.h"

// quantize the image to numBits 
cv::Mat quantizeImage(const cv::Mat& inImage, int numBits)
{
	cv::Mat retImage = inImage.clone();

	uchar maskBit = 0xFF;

	// keep numBits as 1 and (8 - numBits) would be all 0 towards the right
	maskBit = maskBit << (8 - numBits);

	for(int j = 0; j < retImage.rows; j++)
		for(int i = 0; i < retImage.cols; i++)
		{
			cv::Vec3b valVec = retImage.at<cv::Vec3b>(j, i);
			valVec[0] = valVec[0] & maskBit;
			valVec[1] = valVec[1] & maskBit;
			valVec[2] = valVec[2] & maskBit;
			retImage.at<cv::Vec3b>(j, i) = valVec;
		}

		return retImage;
}


int main ()
{
	cv::Mat inImage;
	inImage = cv::imread("testImage.jpg");
	char buffer[30];
	for(int i = 1; i <= 8; i++)
	{
		cv::Mat quantizedImage = quantizeImage(inImage, i);
		sprintf(buffer, "%d Bit Image", i);
		cv::imshow(buffer, quantizedImage);

		sprintf(buffer, "%d Bit Image.png", i);
		cv::imwrite(buffer, quantizedImage);
	}

	cv::waitKey(0);
	return 0;
}
