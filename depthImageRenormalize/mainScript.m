close all
clear all
clc


inImage = imread('testImage.png');
maxVal = double(max(max(inImage)));
minVal = 400;
inImage = double(inImage);

hist(inImage, 2500)

inImageInvert = - inImage;

figure;
hist(inImageInvert, 2500);


inImageOut = inImage

% renormalize the image
for j = 1:size(inImage, 1)
    for i = 1:size(inImage, 2)
        if(inImageOut(j, i) ~= 0)
            inImageOut(j, i) = 3000 - inImage(j, i);
        end
    end
end

figure; 
hist(inImageOut, 2500);

figure;
imshow(uint8(inImageOut./(2500) * 255));